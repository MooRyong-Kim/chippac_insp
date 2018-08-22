//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.hpp>
#pragma hdrstop

#include "WorkSetup.h"
#include "DataClass.h"
#include "Msg.h"
#include "Jog.h"
#include "Maint.h"
#include "Main.h"
#include "MotionBase.h"
#include "MeasProcess.h"
#include "MotionBase.h"
#include "IOPort.h"
#include "Extern.h"
#include "Init.h"
#include "InitProcess.h"
#include "SecsGem.h"
#include "Password.h"
#include "WorkProcess.h"
#include "RunChk.h"
#include "ProtecDll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseEdit"
#pragma link "LMDControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomEdit"
#pragma link "LMDCustomExtSpinEdit"
#pragma link "LMDCustomMaskEdit"
#pragma link "LMDCustomPanel"
#pragma link "LMDSpinEdit"
#pragma link "RzButton"
#pragma link "RzTabs"
#pragma link "LMDCustomBrowseEdit"
#pragma link "LMDCustomFileEdit"
#pragma link "LMDFileOpenEdit"
#pragma link "LMDButtonControl"
#pragma link "LMDCheckBox"
#pragma link "LMDCustomCheckBox"
#pragma resource "*.dfm"
TWorkSetupForm *WorkSetupForm;
//---------------------------------------------------------------------------
__fastcall TWorkSetupForm::TWorkSetupForm(TComponent* Owner)
    : TForm(Owner)
{
    AnsiString sPath = SYS_FILE_PATH+"Loader";
    ForceDirectories(sPath);
    LdFileOpenEdit->InitialDir = sPath;
    LdFileOpenEdit->Filter = "Loader File|*.LD|";
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::FormCreate(TObject *Sender)
{
    OpenDlg->InitialDir = MODEL_FILE_PATH;
    SaveDlg->InitialDir = MODEL_FILE_PATH;
    this->DoubleBuffered = true;
    UnitDrawBasePanel->DoubleBuffered = true;

    WorkSetPanel->Width = 417;
    WorkSetupPageCtrl->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::FormShow(TObject *Sender)
{
    ToolPageCtrlChange(Sender);

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->WorkSetupBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->WorkSetupBtn->Width, pt.y+MainForm->WorkSetupBtn->Height};
    Ext.DrawWireRects(&rectTo, &rectFrom);

    MaintForm->Position = poDefault;
    MaintForm->ManualDock(ToolsPage, MaintForm, alClient);
    //MaintForm->Align = alClient;
    MaintForm->Show();
    //ToolPageCtrl->Pages[0]->TabVisible = false;
    ToolPageCtrl->ActivePageIndex = 0;


    SecsGemForm->SendEvent(C_EDIT_PROGRAM);
    TickTimer->Enabled = true;

    VarToComponent();
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if(m_bDataChange && !(AnsiString(run.chMdlFile).IsEmpty())) {
        if(MsgDlg->ShowBox("Data Save Close?",MMB_YESNO|MMI_INFO,0,STR_MSG) == MID_YES)
            ToolBarBtnClick(FileSaveBtn);
    }

    TickTimer->Enabled = false;

    if(MaintForm->Visible)
        MaintForm->Close();
    if(JogForm->Visible)
        JogForm->Close();
#ifdef PROTECDLL
    _pvAllWindowHide();
    _pvAllWindowHide();
#endif

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->WorkSetupBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->WorkSetupBtn->Width, pt.y+MainForm->WorkSetupBtn->Height};
    Ext.DrawWireRects(&rectFrom, &rectTo);

    MainForm->MainPanel->Visible = false;
    MainForm->ProductPanel->Visible = true;

    IO.SetTowerLamp(TWR_IDLE);
    MainForm->MainPageCtrlChange(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::ToolBarBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);

    if(ptr == FileNewBtn || ptr == FileOpenBtn || ptr == FileSaveBtn) {
        if(ptr == FileNewBtn) {
            SaveDlg->Title = "Work File New...";
            if(SaveDlg->Execute()) {
                ComponentToVar();
                Data.SaveModelData(SaveDlg->FileName);
                VarToComponent();
            }
        }
        else if(ptr == FileOpenBtn) {
            SaveDlg->Title = "Work File Open...";
            if(OpenDlg->Execute()) {
                Data.LoadModelData(OpenDlg->FileName, true, true);
                VarToComponent();
            }
        }
        else if(ptr == FileSaveBtn) {
            ComponentToVar();
            Data.SaveModelData(AnsiString(run.chMdlFile));
            VarToComponent();
        }
    }
    else if(ptr == CancelBtn) {
        if(MsgDlg->ShowBox("Is Cancel Edit Parameter?", MMB_YESNO|MMI_INFO) == MID_YES)
            VarToComponent();
    }
    else if(ptr == PrevBtn || ptr == NextBtn) {
        if(ptr == PrevBtn && WorkSetupPageCtrl->ActivePageIndex > 0)
            --WorkSetupPageCtrl->ActivePageIndex;
        else if(ptr == NextBtn && WorkSetupPageCtrl->ActivePageIndex < WorkSetupPageCtrl->PageCount-1)
            ++WorkSetupPageCtrl->ActivePageIndex;

        if(WorkSetupPageCtrl->ActivePageIndex <= 0) {
            PrevBtn->Enabled = false;
            NextBtn->Enabled = true;
        }
        else if(WorkSetupPageCtrl->ActivePageIndex >= WorkSetupPageCtrl->PageCount-1) {
            PrevBtn->Enabled = true;
            NextBtn->Enabled = false;
        } else {
            PrevBtn->Enabled = true;
            NextBtn->Enabled = true;
        }
    }
    else if(ptr == PkgLoadBtn) {
        Work.m_sManualCmd[RearCvySelChkBox->Checked] = "PCB_LOAD";
        Work.pNo.nInspCvy[RearCvySelChkBox->Checked] = 1;
        if(MsgDlg->ShowBox("Manual PCB Loading.", MMB_CANCEL|MMI_INFO) == MID_CANCEL)
            Work.m_sManualCmd[RearCvySelChkBox->Checked] = "";
    }
    else if(ptr == PkgUnloadBtn) {
        if(IO.In(RearCvySelChkBox->Checked?rcvyinspdct:fcvyinspdct)) {
            IO.Off(FINSPBLKVAC);
            Sleep(300);
            IO.Off(FINSPBLKUP);
        }
    }
    else if(ptr == CloseBtn) {
        this->Close();
    }

    //2016.10.10 17:36:38 chcho
    String logStr = "";
    logStr.sprintf( "Btn : %s, CurRecipe : %s",ptr->Name, mdl.chID );
    Ext.SysLogAdd(logStr);
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::ComponentToVar()
{
    //Pcb Information
    mdl.pcb.nUnitXCnt0                  = UnitXCntSpinEdit->Value;
    mdl.pcb.nUnitYCnt0                  = UnitYCntSpinEdit->Value;
    mdl.pcb.nBlockXCnt                  = BlockXCntSpinEdit->Value;
    mdl.pcb.nBlockYCnt                  = BlockYCntSpinEdit->Value;
    mdl.pcb.nUnitXCnt                   = mdl.pcb.nUnitXCnt0*mdl.pcb.nBlockXCnt;
    mdl.pcb.nUnitYCnt                   = mdl.pcb.nUnitYCnt0*mdl.pcb.nBlockYCnt;
    mdl.pcb.dUnitXPitch                 = StrToFloat(UnitXPitchEdit->Text);
    mdl.pcb.dUnitYPitch                 = StrToFloat(UnitYPitchEdit->Text);
    mdl.pcb.dBlockXPitch                = StrToFloat(BlockXPitchEdit->Text);
    mdl.pcb.dBlockYPitch                = StrToFloat(BlockYPitchEdit->Text);
    mdl.pcb.ofstEvenCol.x               = StrToFloat(EvenColOfstXEdit->Text);
    mdl.pcb.ofstEvenCol.y               = StrToFloat(EvenColOfstYEdit->Text);

    mdl.pcb.dCvyInPos                   = DistCvyInPosEdit->Text.ToDouble();
    mdl.pcb.dCvyOutPos[0]               = DistCvyFrntOutPosEdit->Text.ToDouble();
    mdl.pcb.dCvyOutPos[1]               = DistCvyRearOutPosEdit->Text.ToDouble();

    mdl.pcb.posFirstUnit[0].x           = StrToFloat(FrntFirstUnitXPosEdit->Text);
    mdl.pcb.posFirstUnit[0].y           = StrToFloat(FrntFirstUnitYPosEdit->Text);
    mdl.pcb.posFirstUnit[1].x           = StrToFloat(RearFirstUnitXPosEdit->Text);
    mdl.pcb.posFirstUnit[1].y           = StrToFloat(RearFirstUnitYPosEdit->Text);
    strcpy(mdl.pcb.chLoaderFile, LdFileOpenEdit->Filename.c_str());
    mdl.pcb.nUlSlotTerm                 = UlMgzSlotTermSpinEdit->Value;
    mdl.pcb.nCntDir                     = PcbCntDirRdoGrp->ItemIndex;
    mdl.pcb.bNoUseZigZag                = NoUseZigZagChkBox->Checked;
    mdl.pcb.bUseCure                    = UseCureChkBox->Checked;
    mdl.pcb.nCureSec                    = CureSecSpinEdit->Value;

    mdl.pcb.bUseBarcode                 = ChkUseBarcode->Checked;
    mdl.pcb.dBarcodeX                   = StrToFloat(EditBarcodeX->Text);
    mdl.pcb.dBarcodeY                   = StrToFloat(EditBarcodeY->Text);

    mdl.pcb.bUseAfterInspCure           = ChkInspAfterCure->Checked;

    UnitDraw();

    if(m_bDataChange) {
        SecsGemForm->SendEvent(C_EDIT_PROGRAM);
        SecsGemForm->m_nChangedFdc = FDC_INCONTENS;
    }

    m_bDataChange = false;
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::VarToComponent()
{
    //Pcb Information
    UnitXCntSpinEdit->Value             = mdl.pcb.nUnitXCnt0;
    UnitYCntSpinEdit->Value             = mdl.pcb.nUnitYCnt0;
    BlockXCntSpinEdit->Value            = mdl.pcb.nBlockXCnt;
    BlockYCntSpinEdit->Value            = mdl.pcb.nBlockYCnt;
    UnitXPitchEdit->Text                = Ext.FloatToStr(mdl.pcb.dUnitXPitch);
    UnitYPitchEdit->Text                = Ext.FloatToStr(mdl.pcb.dUnitYPitch);
    BlockXPitchEdit->Text               = Ext.FloatToStr(mdl.pcb.dBlockXPitch);
    BlockYPitchEdit->Text               = Ext.FloatToStr(mdl.pcb.dBlockYPitch);
    EvenColOfstXEdit->Text              = Ext.FloatToStr(mdl.pcb.ofstEvenCol.x);
    EvenColOfstYEdit->Text              = Ext.FloatToStr(mdl.pcb.ofstEvenCol.y);

    DistCvyInPosEdit->Text              = Ext.FloatToStr(mdl.pcb.dCvyInPos);
    DistCvyFrntOutPosEdit->Text         = Ext.FloatToStr(mdl.pcb.dCvyOutPos[0]);
    DistCvyRearOutPosEdit->Text         = Ext.FloatToStr(mdl.pcb.dCvyOutPos[1]);

    FrntFirstUnitXPosEdit->Text         = Ext.FloatToStr(mdl.pcb.posFirstUnit[0].x);
    FrntFirstUnitYPosEdit->Text         = Ext.FloatToStr(mdl.pcb.posFirstUnit[0].y);
    RearFirstUnitXPosEdit->Text         = Ext.FloatToStr(mdl.pcb.posFirstUnit[1].x);
    RearFirstUnitYPosEdit->Text         = Ext.FloatToStr(mdl.pcb.posFirstUnit[1].y);
    LdFileOpenEdit->Filename            = mdl.pcb.chLoaderFile;
    UlMgzSlotTermSpinEdit->Value        = mdl.pcb.nUlSlotTerm;
    PcbCntDirRdoGrp->ItemIndex          = mdl.pcb.nCntDir;
    NoUseZigZagChkBox->Checked          = mdl.pcb.bNoUseZigZag;
    UseCureChkBox->Checked              = mdl.pcb.bUseCure;
    CureSecSpinEdit->Value              = mdl.pcb.nCureSec;

    ChkUseBarcode->Checked              = mdl.pcb.bUseBarcode;
    EditBarcodeX->Text                  = Ext.FloatToStr(mdl.pcb.dBarcodeX);
    EditBarcodeY->Text                  = Ext.FloatToStr(mdl.pcb.dBarcodeY);

    ChkInspAfterCure->Checked           = mdl.pcb.bUseAfterInspCure;

    UnitDraw();

    m_bDataChange = false;
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::UnitDrawBoxPaint(TObject *Sender)
{
    UnitDraw();
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::GetPosBtnClick(TObject *Sender)
{
    TRzBitBtn *pBtn = dynamic_cast<TRzBitBtn*>(Sender);

    String posX = Ext.FloatToStr(MB.GetPos(IX));
    String posY = Ext.FloatToStr(MB.GetPos(IY));

    //Inspection Conveyor
    if(pBtn == DistCvyInPosGetBtn)
        DistCvyInPosEdit->Text = Ext.FloatToStr(MB.GetPos(DC));
    else if(pBtn == DistCvyFrntOutPosGetBtn)
        DistCvyFrntOutPosEdit->Text = Ext.FloatToStr(MB.GetPos(DC));
    else if(pBtn == DistCvyRearOutPosGetBtn)
        DistCvyRearOutPosEdit->Text = Ext.FloatToStr(MB.GetPos(DC));
    else if(pBtn == FrntFirstUnitPosGetBtn) {
        FrntFirstUnitXPosEdit->Text = Ext.FloatToStr(MB.GetPos(IX));
        FrntFirstUnitYPosEdit->Text = Ext.FloatToStr(MB.GetPos(IY));
    }
    else if(pBtn == RearFirstUnitPosGetBtn) {
        RearFirstUnitXPosEdit->Text = Ext.FloatToStr(MB.GetPos(IX));
        RearFirstUnitYPosEdit->Text = Ext.FloatToStr(MB.GetPos(IY));
    }
    else if(pBtn == EvenColOfstGetBtn) {
        EvenColOfstXEdit->Text = Ext.FloatToStr(MB.GetPosInc(IX));
        EvenColOfstYEdit->Text = Ext.FloatToStr(MB.GetPosInc(IY));
    }
    else if( Sender == BtnBarcodePosGet ) {
        EditBarcodeX->Text = posX;
        EditBarcodeY->Text = posY;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::GoBtnClick(TObject *Sender)
{
    TRzBitBtn *pBtn = dynamic_cast<TRzBitBtn*>(Sender);
    Coord pos;

    if(pBtn == DistCvyInPosGoBtn)
        MB.MoveTo(DC, DistCvyInPosEdit->Text.ToDouble());
    else if(pBtn == DistCvyFrntOutPosGoBtn)
        MB.MoveTo(DC, DistCvyFrntOutPosEdit->Text.ToDouble());
    else if(pBtn == DistCvyRearOutPosGoBtn)
        MB.MoveTo(DC, DistCvyRearOutPosEdit->Text.ToDouble());
    else if(pBtn == FrntFirstUnitPosGoBtn) {
        MB.MoveTo(DC, DistCvyInPosEdit->Text.ToDouble());
        pos.x = FrntFirstUnitXPosEdit->Text.ToDouble();
        pos.y = FrntFirstUnitYPosEdit->Text.ToDouble();
        MB.XYMoveTo(IX, pos);
    }
    else if(pBtn == RearFirstUnitPosGoBtn) {
        MB.MoveTo(DC, DistCvyInPosEdit->Text.ToDouble());
        pos.x = RearFirstUnitXPosEdit->Text.ToDouble();
        pos.y = RearFirstUnitYPosEdit->Text.ToDouble();
        MB.XYMoveTo(IX, pos);
    }
    else if( Sender == BtnBarcodePosGo ) {
        Coord pos;
        pos.x = StrToFloat( EditBarcodeX->Text );
        pos.y = StrToFloat( EditBarcodeY->Text );
        MB.XYMoveTo( IX, pos );
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::TickTimerTimer(TObject *Sender)
{
    if(AnsiString(run.chMdlFile).IsEmpty()) {
        FileSaveBtn->Enabled = false;
        CancelBtn->Enabled = false;
    } else {
        CancelBtn->Enabled = m_bDataChange;
        FileSaveBtn->Enabled = true;
    }

    static clock_t t300ms;
    if(Ext.CheckDelay(t300ms, 300)) {
        t300ms = clock();
        UnitDraw();
    }

    GroupBox1->Visible = (sys.fac.nEquipType==VTYPE_2RAIL&&!sys.fac.bNoUseRearRail);
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::FormKeyPress(TObject *Sender, char &Key)
{
    if((Key < '0' || Key > '9') && Key != '.' && Key != '-'  && Key != 22 && Key != 3)
        Key = 0x00;
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::DataChange(TObject *Sender)
{
    m_bDataChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::WorkSetupPageCtrlChange(TObject *Sender)
{
    VarToComponent();
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::WorkSetupPageCtrlChanging(TObject *Sender,
     bool &AllowChange)
{
    if(m_bDataChange)
        ComponentToVar();
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::UnitDraw(TPoint ptClick)
{
    TPanel *pPanel = UnitDrawBasePanel;
    TPaintBox *pPntBox = UnitDrawBox;
    int nX, nY, nBX, nBY;
    int nSpace ,nCnt, nBwX, nBwY;

    nX = mdl.pcb.nUnitXCnt;
    nY = mdl.pcb.nUnitYCnt;
    nBX = mdl.pcb.nUnitXCnt0;
    nBY = mdl.pcb.nUnitYCnt0;

    if(nX < 1 || nY < 1) {
        pPntBox->Visible = false;
        return;
    }
    pPntBox->Visible = true;

    nSpace = 2;
    for(int i=0; i<nX*nY; i++)
        nBwX = nBwY = nSpace*(i/(nBX*nY));

    TSize szUnit;
  	szUnit.cx = (pPanel->Width-nSpace-nBwX)/nX;
    szUnit.cy = (pPanel->Height-nSpace-nBwY)/nY;

    if(pPanel->Width-nSpace < szUnit.cy*nX) {
        pPntBox->Width = szUnit.cx*nX+nBwX;
        pPntBox->Height = szUnit.cx*nY+nBwY;
      	szUnit.cy = szUnit.cx;
    } else {
        pPntBox->Width = szUnit.cy*nX+nBwX;
        pPntBox->Height = szUnit.cy*nY+nBwY;
      	szUnit.cx = szUnit.cy;
    }

    TRect rtCanvas;
    rtCanvas = TRect(0, 0, szUnit.cx*nX+nBwX, szUnit.cy*nY+(nBwY/2.));
    pPntBox->Left = (pPanel->Width-pPntBox->Width)/2;
    pPntBox->Top = (pPanel->Height-pPntBox->Height)/2;

    Graphics::TBitmap *pBmpBox = new Graphics::TBitmap();
    pBmpBox->Width = pPntBox->Width;
    pBmpBox->Height = pPntBox->Height;
    pBmpBox->Canvas->Brush->Color = TColor(0x00004000);
    pBmpBox->Canvas->FillRect(rtCanvas);

    int nClickUnit = -1;
    nCnt = 0;
    int nCrntUnit = MB.GetCrntUnitNum(run.bRearRailWork);
//    for(int m=(mdl.pcb.nCntDir?nX-1:0); (mdl.pcb.nCntDir?m>=0:m<nY); (mdl.pcb.nCntDir?m--:m++)) {
//          for(int n=(mdl.pcb.nCntDir?0:nX-1); (mdl.pcb.nCntDir?n<nY:n>=0); (mdl.pcb.nCntDir?n++:n--)) {
    for(int m=(mdl.pcb.nCntDir?0:0); (mdl.pcb.nCntDir?m<nX:m<nY); (mdl.pcb.nCntDir?m++:m++)) {
        for(int n=(mdl.pcb.nCntDir?0:0); (mdl.pcb.nCntDir?n<nY:n<nX); (mdl.pcb.nCntDir?n++:n++)) {
            TRect rtUnit;
            if(mdl.pcb.nCntDir) {
                nBwX = nSpace*(m/nBX);
                nBwY = nSpace*(n/nBY);
                rtUnit = TRect((m*szUnit.cx)+nSpace/2+nBwX, (n*szUnit.cy)+nSpace/2+nBwY,
                            (m*szUnit.cx)+(szUnit.cx-nSpace/2)+nBwX, (n*szUnit.cy)+(szUnit.cy-nSpace/2)+nBwY);
            } else {
                nBwX = nSpace*(n/nBX);
                nBwY = nSpace*(m/nBY);
                rtUnit = TRect((n*szUnit.cx)+nSpace/2+nBwX, (m*szUnit.cy)+nSpace/2+nBwY,
                            (n*szUnit.cx)+(szUnit.cx-nSpace/2)+nBwX, (m*szUnit.cy)+(szUnit.cy-nSpace/2)+nBwY);
            }
            pBmpBox->Canvas->Brush->Color = clGreen;
            pBmpBox->Canvas->FillRect(rtUnit);

            int nWidth = abs(rtUnit.Right-rtUnit.Left);
            int nTerm = nWidth*0.09;
            rtUnit.Left = rtUnit.Left+nTerm;
            rtUnit.Top = rtUnit.Top+nTerm;
            rtUnit.Right = rtUnit.Left+nWidth-(nTerm*2);
            rtUnit.Bottom = rtUnit.Top+nWidth-(nTerm*2);
            pBmpBox->Canvas->Brush->Color = (nCrntUnit==nCnt?clLime:clSilver);
            pBmpBox->Canvas->FillRect(rtUnit);
            pBmpBox->Canvas->Font->Color = clBlack;
            //pBmpBox->Canvas->Font->Style = TFontStyles()<< fsBold;
            pBmpBox->Canvas->Font->Size = (nX*nY>9?6:7);
            pBmpBox->Canvas->Font->Name = "Tahoma";
            pBmpBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top, IntToStr(nCnt+1));

            if(PtInRect(&rtUnit, ptClick)) {
                nClickUnit = nCnt;
            }

            nCnt++;
        }
    }

    pPntBox->Canvas->Draw(0,0,pBmpBox);
    delete pBmpBox;

    if(nClickUnit > -1) {
        Coord posMove = MB.GetUnitPos(RearCvySelChkBox->Checked, nClickUnit);
        MB.XYMoveTo(IX, posMove);
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::UnitDrawBoxMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TPoint ptClick = TPoint(X, Y);
    UnitDraw(ptClick);
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::ToolPageCtrlChange(TObject *Sender)
{
#ifdef PROTECDLL
    if(ToolPageCtrl->ActivePageIndex == 1) {
        TPoint pt;
        pt.x = VsnPage->Left;
        pt.y = VsnPage->Top;

        pt = VsnPage->ClientToScreen(pt);
        pt.y-=25;
        _pvMoveDlg(pt.x, pt.y, pt.x+VsnPage->Width, pt.y+VsnPage->Height);
        _pvShowMode(SHOWMODE_SETUP);
    }
    else _pvAllWindowHide();
#endif
}
//---------------------------------------------------------------------------
void __fastcall TWorkSetupForm::LdFileOpenEditChange(TObject *Sender)
{
    m_bDataChange = true;
    Data.LoaderFileCtrl(mdl.pcb.chLoaderFile, false, false);
}
//---------------------------------------------------------------------------

void __fastcall TWorkSetupForm::ChkUseBarcodeClick(TObject *Sender)
{
    if( ChkUseBarcode->Checked ) {
        GroupBox7->Visible = true;
    }
    else {
        GroupBox7->Visible = false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TWorkSetupForm::BtnBarcodeTestClick(TObject *Sender)
{
    Coord pos;
    pos.x = mdl.pcb.dBarcodeX;
    pos.y = mdl.pcb.dBarcodeY;
    MB.XYMoveTo( IX, pos, true );

    Sleep( sys.opr.nVsnDly );

    _pvShowMode(SHOWMODE_RUN);

    _pvSignal_Reset(0);
    Sleep(sys.opr.nVsnDly);

    _pvInspChange(0, 0, BARCODE_INDEX);
    _pvSWTrigger(0);
    Sleep(500);
    _pvSignal_Reset(0);

    _pvShowMode(SHOWMODE_SETUP);

}
//---------------------------------------------------------------------------


