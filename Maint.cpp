//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Maint.h"
#include "DataClass.h"
#include "Jog.h"
#include "MotionBase.h"
#include "Main.h"
#include "Extern.h"
#include "InitProcess.h"
#include "Init.h"
#include "IOPort.h"
#include "Msg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseControl"
#pragma link "LMDBaseEdit"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDBaseLabel"
#pragma link "LMDControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomEdit"
#pragma link "LMDCustomExtSpinEdit"
#pragma link "LMDCustomGlyphLabel"
#pragma link "LMDCustomImageList"
#pragma link "LMDCustomMaskEdit"
#pragma link "LMDCustomPanel"
#pragma link "LMDGlyphLabel"
#pragma link "LMDImageList"
#pragma link "LMDSpinEdit"
#pragma link "RzPanel"
#pragma link "RzRadGrp"
#pragma link "RzTabs"
#pragma link "LMDButtonControl"
#pragma link "LMDCheckBox"
#pragma link "LMDCustomCheckBox"
#pragma link "RzButton"
#pragma resource "*.dfm"
TMaintForm *MaintForm;
//---------------------------------------------------------------------------
__fastcall TMaintForm::TMaintForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::FormCreate(TObject *Sender)
{
    MaintPageCtrl->ActivePageIndex = 0;
    CvyPageCtrl->ActivePageIndex = 0;

    this->Width = 570;
    this->Height = 620;
    IOPanelCreate();

    m_sCylSensName[IO.EnumMap[IO_OUT][CLAMPON]][ON] = clampon;
    m_sCylSensName[IO.EnumMap[IO_OUT][CLAMPON]][OFF] = clampoff;

    m_sCylSensName[IO.EnumMap[IO_OUT][FINSPSTPRDN]][OFF] = finspstprup;
    m_sCylSensName[IO.EnumMap[IO_OUT][FINSPBLKUP]][ON] = finspblkdn;
    m_sCylSensName[IO.EnumMap[IO_OUT][FINSPBLKUP]][OFF] = finspblkup;
    m_sCylSensName[IO.EnumMap[IO_OUT][FULPUSHDN]][ON] = fulpushdn;
    m_sCylSensName[IO.EnumMap[IO_OUT][FULPUSHDN]][OFF] = fulpushup;
    m_sCylSensName[IO.EnumMap[IO_OUT][FULPUSHFWD]][ON] = fulpushfwd;
    m_sCylSensName[IO.EnumMap[IO_OUT][FULPUSHFWD]][OFF] = fulpushbwd;

    m_sCylSensName[IO.EnumMap[IO_OUT][RINSPSTPRDN]][ON] = rinspstprdn;
    m_sCylSensName[IO.EnumMap[IO_OUT][RINSPSTPRDN]][OFF] = rinspstprup;
    m_sCylSensName[IO.EnumMap[IO_OUT][RINSPBLKUP]][ON] = rinspblkdn;
    m_sCylSensName[IO.EnumMap[IO_OUT][RINSPBLKUP]][OFF] = rinspblkup;
    m_sCylSensName[IO.EnumMap[IO_OUT][RULPUSHDN]][ON] = rulpushdn;
    m_sCylSensName[IO.EnumMap[IO_OUT][RULPUSHDN]][OFF] = rulpushup;
    m_sCylSensName[IO.EnumMap[IO_OUT][RULPUSHFWD]][ON] = rulpushfwd;
    m_sCylSensName[IO.EnumMap[IO_OUT][RULPUSHFWD]][OFF] = rulpushbwd;

    m_sCylSensName[IO.EnumMap[IO_OUT][ULMGZGRIPOFF]][ON] = ulmgzgripoff;
    m_sCylSensName[IO.EnumMap[IO_OUT][ULMGZGRIPOFF]][OFF] = ulmgzgripon;

    for(int i=0; i<IO_MAX; i++) {
        if(!m_sCylSensName[i][ON].IsEmpty())
            CylChkErrMemo->Lines->Add(m_sCylSensName[i][ON]);
        if(!m_sCylSensName[i][OFF].IsEmpty())
            CylChkErrMemo->Lines->Add(m_sCylSensName[i][OFF]);

        m_lblIn[i] = NULL;
        m_btnOut[i] = NULL;
        m_chkCyl[i] = NULL;
    }

    for(int i=0; i<this->ComponentCount; i++) {
        if(Components[i]->ClassNameIs("TLMDGlyphLabel")) {
            AnsiString sIn = ((TLMDGlyphLabel*)Components[i])->Caption;
            int nIn = IO.NameMap[IO_IN][sIn];
            if(nIn >= IO_MAX) continue;
            if(nIn != 0) {
                m_lblIn[nIn] = ((TLMDGlyphLabel*)Components[i]);
            }
            //else CylChkErrMemo->Lines->Add(sIn);
        }
        else if(Components[i]->ClassNameIs("TSpeedButton")) {
            AnsiString sOut = ((TSpeedButton*)Components[i])->Caption;
            int nOut = IO.NameMap[IO_OUT][sOut];
            if(nOut >= IO_MAX) continue;
            if(nOut != 0) {
                m_btnOut[nOut] = ((TSpeedButton*)Components[i]);
                ((TSpeedButton*)Components[i])->GroupIndex = i+1;
            }
            //else CylChkErrMemo->Lines->Add(sOut+":"+((TSpeedButton*)Components[i])->Name);
        }
        else if(Components[i]->ClassNameIs("TCheckBox")) {
            AnsiString sOut = ((TCheckBox*)Components[i])->Caption;
            int nOut = IO.NameMap[IO_OUT][sOut];
            if(nOut >= IO_MAX) continue;
            if(nOut != 0) {
                m_chkCyl[nOut] = ((TCheckBox*)Components[i]);
            }
        }
    }
    m_lblIn[0] = InLED0;
    m_btnOut[0] = OutBtn4;

    UlMgzSlotUpBtn->GroupIndex = 0;
    UlMgzSlotDnBtn->GroupIndex = 0;
    UnitPosDecBtn->GroupIndex = 0;
    UnitPosIncBtn->GroupIndex = 0;

    m_rtForm.Left = (MainForm->Width-this->Width)/2;
    m_rtForm.Top = (MainForm->Height-this->Height)/2;
    m_rtForm.Right = m_rtForm.Left+this->Width;
    m_rtForm.Bottom = m_rtForm.Top+this->Height;
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::FormShow(TObject *Sender)
{
    for(int o=0 ; o<IO_MAX ; o++)
        m_bPreOut[o] = IO.GetOut(o);

    CvyPageCtrl->Pages[1]->TabVisible = (!sys.fac.bNoUseRearRail && sys.fac.nEquipType!=HTYPE_1RAIL);
    RzGroupBox5->Visible = (sys.fac.nEquipType==HTYPE_1RAIL);
    RzGroupBox9->Caption = (sys.fac.nEquipType==VTYPE_2RAIL?"Unloader":"Unloader Y");

    for(int i=0; i<this->ComponentCount; i++) {
        if(Components[i]->ClassNameIs("TLMDGlyphLabel")) {
            if(((TLMDGlyphLabel*)Components[i])->Caption.AnsiPos("REAR")) {
                ((TLMDGlyphLabel*)Components[i])->Visible =
                    (!sys.fac.bNoUseRearRail && sys.fac.nEquipType!= HTYPE_1RAIL);
            }
            if(((TLMDGlyphLabel*)Components[i])->Caption.AnsiPos("UNLOADER")) {
                if(!((TLMDGlyphLabel*)Components[i])->Caption.AnsiPos("RESET") &&
                    !((TLMDGlyphLabel*)Components[i])->Caption.AnsiPos("PUSHER")) {
                    ((TLMDGlyphLabel*)Components[i])->Visible = (sys.fac.nEquipType==HTYPE_1RAIL || (sys.fac.nEquipType == VTYPE_2RAIL && sys.fac.bNoUseRearRail == true));
                }
            }
        }
        else if(Components[i]->ClassNameIs("TSpeedButton")) {
            if(((TSpeedButton*)Components[i])->Caption.AnsiPos("REAR")) {
                ((TSpeedButton*)Components[i])->Visible =
                    (!sys.fac.bNoUseRearRail && sys.fac.nEquipType!= HTYPE_1RAIL);
            }
            if(((TSpeedButton*)Components[i])->Caption.AnsiPos("UNLOADER")) {
                if(!((TSpeedButton*)Components[i])->Caption.AnsiPos("RESET") &&
                    !((TLMDGlyphLabel*)Components[i])->Caption.AnsiPos("PUSHER")) {
                    ((TSpeedButton*)Components[i])->Visible = (sys.fac.nEquipType==HTYPE_1RAIL || (sys.fac.nEquipType == VTYPE_2RAIL && sys.fac.bNoUseRearRail == true));
                }
            }
        }
        else if(Components[i]->ClassNameIs("TCheckBox")) {
            if(((TCheckBox*)Components[i])->Caption.AnsiPos("REAR")) {
                ((TCheckBox*)Components[i])->Visible =
                    (!sys.fac.bNoUseRearRail && sys.fac.nEquipType!= HTYPE_1RAIL);
            }
            if(((TCheckBox*)Components[i])->Caption.AnsiPos("UNLOADER")) {
                if(!((TCheckBox*)Components[i])->Caption.AnsiPos("RESET")) {
                    ((TCheckBox*)Components[i])->Visible = (sys.fac.nEquipType==HTYPE_1RAIL);
                }
            }
        }
    }

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->ManualBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->ManualBtn->Width, pt.y+MainForm->ManualBtn->Height};
    Ext.DrawWireRects(&rectTo, &rectFrom);

    TickTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    for(int i=0; i<IO_MAX; i++) {
        if(m_chkCyl[i] != NULL) m_chkCyl[i]->Checked = false;
    }

    TickTimer->Enabled = false;
    //출력을 들어 오기 전 상태로?
    //for(int o=0 ; o<96 ; o++)
        //m_bPreOut[o]?SetBit(o):reSetBit(o);

    IO.SetTowerLamp(TWR_IDLE);

    MaintForm->Position = poOwnerFormCenter;

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->ManualBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->ManualBtn->Width, pt.y+MainForm->ManualBtn->Height};
    Ext.DrawWireRects(&rectFrom, &rectTo);
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::IOPanelCreate()
{
    int nCnt, nPnlW, nPnlH;

//In Panel Create
    TRzTabSheet *pTabSheet;
    for(int i=0; i<MaintPageCtrl->PageCount; i++) {
        if(MaintPageCtrl->Pages[i]->Caption == "Machine I/O")
            pTabSheet = MaintPageCtrl->Pages[i];
    }

    FullInGrpBox->Height = pTabSheet->Height/2;
    nPnlW = InBasePanel->Width/IO_COL;
    nPnlH = InBasePanel->Height/IO_ROW;
    nCnt = 0;
   	for(int i=0; i<IO_ROW; i++){
    	for(int j=0; j<IO_COL ; j++){
            m_pInPnl[nCnt] = new TPanel(this);
            m_pInPnl[nCnt]->Parent 	        = InBasePanel;
            m_pInPnl[nCnt]->Left 	        = nPnlW*j;
            m_pInPnl[nCnt]->Top 	        = nPnlH*i;
            m_pInPnl[nCnt]->Width 	        = nPnlW;
            m_pInPnl[nCnt]->Height 	        = nPnlH;
            m_pInPnl[nCnt]->Color           = TColor(0x00000057);
            m_pInPnl[nCnt]->Font->Name      = "Tahoma";
            m_pInPnl[nCnt]->Font->Size      = 8;
            m_pInPnl[nCnt]->Font->Color     = clYellow;
            m_pInPnl[nCnt]->Font->Style     = TFontStyles()<< fsBold;
            m_pInPnl[nCnt]->Caption         = IntToStr(nCnt);
            m_pInPnl[nCnt]->Tag	            = nCnt;
            m_pInPnl[nCnt]->Hint            = AnsiString(IO.io_Fmt[IO_IN][nCnt].chName);
            m_pInPnl[nCnt]->ShowHint        = true;

        	m_pOutPnl[nCnt] = new TPanel(this);
            m_pOutPnl[nCnt]->Parent         = OutBasePanel;
            m_pOutPnl[nCnt]->Left 	        = nPnlW*j;
            m_pOutPnl[nCnt]->Top 	        = nPnlH*i;
            m_pOutPnl[nCnt]->Width 	        = nPnlW;
            m_pOutPnl[nCnt]->Height         = nPnlH;
            m_pOutPnl[nCnt]->Color          = TColor(0x00005100);
            m_pOutPnl[nCnt]->Font->Name     = "Tahoma";
            m_pOutPnl[nCnt]->Font->Size     = 8;
            m_pOutPnl[nCnt]->Font->Color    = clYellow;
            m_pOutPnl[nCnt]->Font->Style    = TFontStyles()<< fsBold;
            m_pOutPnl[nCnt]->Caption        = IntToStr(nCnt);
            m_pOutPnl[nCnt]->Tag	        = nCnt;
            m_pOutPnl[nCnt]->OnClick        = OutPanelClick;
            m_pOutPnl[nCnt]->Hint           = AnsiString(IO.io_Fmt[IO_OUT][nCnt].chName);
            m_pOutPnl[nCnt]->ShowHint       = true;
            nCnt++;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::OutPanelClick(TObject *Sender)
{
    TPanel *ptr = dynamic_cast<TPanel *>(Sender);
    if(IO.GetOut(ptr->Tag))
        IO.ResetBit(ptr->Tag);
    else IO.SetBit(ptr->Tag);
    FullIOPortIndicate();
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::TickTimerTimer(TObject *Sender)
{
    if(MaintPageCtrl->ActivePageIndex == MaintPageCtrl->PageCount-1) {
        CylChkProcess();
        if(m_nCylChkPNo == 0) {
            CylTestStartBtn->Down = false;
            CylTestStopBtn->Down = true;
        } else {
            CylTestStartBtn->Down = true;
            CylTestStopBtn->Down = false;
        }
    }
    else if(MaintPageCtrl->ActivePageIndex  == MaintPageCtrl->PageCount-2)
        FullIOPortIndicate();
    else InputStatusIndicate();

    static clock_t t100 = clock();
    if(Ext.CheckDelay(t100, 100)) {
        t100 = clock();
        int nPosKind;
        CylinderAutoRepeat();
        UlSlotNumSpinEdit->MaxValue = mdl.ul.nMgzSlotNum;
    }

    if(sys.fac.nEquipType == HTYPE_1RAIL)
        RzGroupBox19->Caption = "Magazine Slot: "+IntToStr(MB.GetCrntSlotNum(UZ)+1);
    else {
        int nMgz, nSlot; nMgz = nSlot = -1;
        MB.GetMgzSlotNum(UL, nMgz, nSlot);
        RzGroupBox19->Caption = "Magazine: "+IntToStr(nMgz+1)+", Slot: "+IntToStr(nSlot+1);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::InputStatusIndicate()
{
    for(int i=0; i<IO_MAX; i++) {
        if(m_lblIn[i] != NULL)
            m_lblIn[i]->ImageIndex = IO.In(i);
        if(m_btnOut[i] != NULL)
            m_btnOut[i]->Down = IO.GetOut(i);
    }

    for(int ax=0; ax<AXES; ax++) {
        TLMDGlyphLabel *pLED;
        TSpeedButton *pBtn;

        Init.HomeProcess(ax);
        pBtn = (TSpeedButton*)(FindComponent("HomeBtn"+IntToStr(ax)));
        if(pBtn != NULL) pBtn->Enabled = (Init.m_nHomePNo[ax] == 0);

        if(MB.IsServoOn(ax)) {
            pBtn = (TSpeedButton*)(FindComponent("AmpOnBtn"+IntToStr(ax)));
            if(pBtn != NULL) pBtn->Down = true;
        } else {
            pBtn = (TSpeedButton*)(FindComponent("AmpOffBtn"+IntToStr(ax)));
            if(pBtn != NULL) pBtn->Down = true;
        }

        pLED = (TLMDGlyphLabel*)(FindComponent("PLmtLED"+IntToStr(ax)));
        if(pLED != NULL) pLED->ImageIndex = MB.PosLimit(ax);

        pLED = (TLMDGlyphLabel*)(FindComponent("HomeLED"+IntToStr(ax)));
        if(pLED != NULL) pLED->ImageIndex = MB.HomeSensor(ax);

        pLED = (TLMDGlyphLabel*)(FindComponent("MLmtLED"+IntToStr(ax)));
        if(pLED != NULL) pLED->ImageIndex = MB.NegLimit(ax);

        pLED = (TLMDGlyphLabel*)(FindComponent("AmpFltLED"+IntToStr(ax)));
        if(pLED != NULL) pLED->ImageIndex = MB.IsServoAlarm(ax);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::FullIOPortIndicate()
{
    int nNum = 0;
   	for(int i=0; i<IO_ROW; i++) {
    	for(int j=0; j<IO_COL ; j++){
            m_pInPnl[nNum]->Color = (IO.In(nNum))?clRed:TColor(0x00000057);
            m_pOutPnl[nNum]->Color = (IO.GetOut(nNum))?clLime:TColor(0x00005100);
            nNum++;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::OutBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton*>(Sender);

/*    if(ptr == UlGripFreeBtn) {
        IO.Off(ULMGZGRIPON);
        IO.Off(ULMGZGRIPOFF);
        return;
    }*/

    ptr->Down?IO.On(ptr->Caption, true):IO.Off(ptr->Caption, true);
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CylChkMsg(AnsiString sPort, bool bError)
{
    int nPort = IO.EnumMap[IO_IN][sPort];

    AnsiString sStr = IO.io_Fmt[IO_IN][nPort].chName;
    if(bError) {
        sStr = "IN("+IntToStr(nPort)+"): "+sStr+" Sensor Check Error.";
        CylChkErrMemo->Lines->Add(sStr);
    } else {
        sStr = "IN("+IntToStr(nPort)+"): "+sStr+" Sensor Checking.";
        CylChkMsgPanel->Caption = sStr;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CylChkProcess()
{
    static clock_t tCylChk;

    if(m_nCylChkPNo == 0) {
        CylChkTimePgsBar->Position = 0;
        tCylChk = clock();
        return;
    }

    static int nCnt;

    CylChkTimePgsBar->Position = (Ext.GetLapTime(tCylChk)/(double)CylChkTimeSpinEdit->Value)*100;

    switch(m_nCylChkPNo) {
    case 1:
        tCylChk = clock();
        nCnt = 0;
        m_nCylChkPNo = 5;
        break;
    case 2:
        tCylChk = clock();
        if(++nCnt < IO_MAX)
            m_nCylChkPNo = 5;
        else {
            CylChkMsgPanel->Caption = "Cylinder Sensor Checking End.";
            m_nCylChkPNo = 0;
        }
        break;
    case 5:
        tCylChk = clock();
        if(!m_sCylSensName[nCnt][ON].IsEmpty()) {
            CylChkMsg(m_sCylSensName[nCnt][ON]);
            IO.On(IO.m_pEnumList[IO_OUT]->Strings[nCnt]);
            tCylChk = clock();
            m_nCylChkPNo = 10;
        }
        else m_nCylChkPNo = 2;
        break;
    case 10:
        if(IO.In(m_sCylSensName[nCnt][ON])) {
            CylChkMsg(m_sCylSensName[nCnt][OFF]);
            IO.Off(IO.m_pEnumList[IO_OUT]->Strings[nCnt]);
            tCylChk = clock();
            m_nCylChkPNo = 15;
        }
        else if(Ext.CheckDelay(tCylChk, CylChkTimeSpinEdit->Value)) {
            CylChkMsg(m_sCylSensName[nCnt][ON], true);
            CylChkMsg(m_sCylSensName[nCnt][OFF]);
            IO.Off(IO.m_pEnumList[IO_OUT]->Strings[nCnt]);
            tCylChk = clock();
            m_nCylChkPNo = 15;
        }
        break;
    case 15:
        if(IO.In(m_sCylSensName[nCnt][OFF]))
            m_nCylChkPNo = 2;
        else if(Ext.CheckDelay(tCylChk, CylChkTimeSpinEdit->Value)) {
            CylChkMsg(m_sCylSensName[nCnt][OFF], true);
            m_nCylChkPNo = 2;
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::InitBtnClick(TObject *Sender)
{
    if(!InitForm->Visible) {
        Init.m_bAuto = false;
        InitForm->ShowModal();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::HomeBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);
    AnsiString sBtn = ptr->Name;
    int nAxis = StrToInt(sBtn.Delete(1, sBtn.AnsiPos("Btn")+2));
    if(Init.m_nHomePNo[nAxis] == 0) {
        Init.m_nHomePNo[nAxis] = 1;
        if(MsgDlg->ShowBox(IntToStr(nAxis)+"Homing Start.", MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL) {
            Init.m_nHomePNo[nAxis] = 0;
            MB.MoveStop(nAxis);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::AmpRstBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);
    AnsiString sBtn = ptr->Name;
    int nAxis = StrToInt(sBtn.Delete(1, sBtn.AnsiPos("Btn")+2));
    Init.m_nHomePNo[nAxis] = 0;
    MB.MoveStop(nAxis);
    MB.ServoReset(nAxis, ON);
    Ext.Sleep(300);
    MB.ServoReset(nAxis, OFF);
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::AmpPwrOnBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);
    AnsiString sBtn = ptr->Name;
    int nAxis = StrToInt(sBtn.Delete(1, sBtn.AnsiPos("Btn")+2));
    MB.ServoPower(nAxis, ON);
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::AmpPwrOffBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);
    AnsiString sBtn = ptr->Name;
    int nAxis = StrToInt(sBtn.Delete(1, sBtn.AnsiPos("Btn")+2));
    MB.ServoPower(nAxis, OFF);
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::OutAllBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);

    if(ptr == OutAllOnBtn) {
        for(int o=0; o<IO_MAX; o++)
            IO.SetBit(o);
    }
    else if(ptr == OutAllOffBtn) {
        for(int o=0; o<IO_MAX; o++)
            IO.ResetBit(o);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CylinderAutoRepeat()
{
    const int DLY_TIME = 1000;
    static bool bInFunc;
    static clock_t tOut[IO_MAX];
    
    if(bInFunc) return;
    bInFunc = true;
                                     
    for(int i=0; i<IO_MAX; i++) {
        if(m_chkCyl[i] != NULL) {
            if(m_chkCyl[i]->Checked) {
                if(IO.In(m_sCylSensName[i][OFF])) {
                    while(!Ext.CheckDelay(tOut[i], DLY_TIME)) {
                        if(!this->Visible || !m_chkCyl[i]->Checked) break;
                        Ext.DoEvents();
                    }
                    IO.On(IO.m_pEnumList[IO_OUT]->Strings[i]);
                    tOut[i] = clock();
                }
                else if(IO.In(m_sCylSensName[i][ON])) {
                    while(!Ext.CheckDelay(tOut[i], DLY_TIME)) {
                        if(!this->Visible || !m_chkCyl[i]->Checked) break;
                        Ext.DoEvents();
                    }
                    IO.Off(IO.m_pEnumList[IO_OUT]->Strings[i]);
                    tOut[i] = clock();
                }
            }
        }
    }

    bInFunc = false;
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::MaintPageCtrlChange(TObject *Sender)
{
    /*
    for(int i=0; i<110; i++) {
        TCheckBox *ptr = (TCheckBox*)(FindComponent("Out"+IntToStr(i)+"CylChkBox"));
        if(ptr != NULL) ptr->Checked = false;
    } */
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CvyMoveBtnMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*
    TLMDShapeButton *ptr = dynamic_cast<TLMDShapeButton *>(Sender);

    if(ptr == DispCvyBWDBtn)      IO.On(DISPCVYBWD);
    else if(ptr == DispCvyFWDBtn) IO.On(DISPCVYFWD);
    else if(ptr == AtchCvyBWDBtn) IO.On(ATCHCVYBWD);
    else if(ptr == AtchCvyFWDBtn) IO.On(ATCHCVYFWD);
    else if(ptr == CureCvyBWDBtn) IO.On(CURECVYBWD);
    else if(ptr == CureCvyFWDBtn) IO.On(CURECVYFWD);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CvyMoveBtnMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
/*
    TLMDShapeButton *ptr = dynamic_cast<TLMDShapeButton *>(Sender);

    if(ptr == DispCvyBWDBtn || ptr == DispCvyFWDBtn)
        IO.Off(DISPCVY);
    else if(ptr == AtchCvyBWDBtn || ptr == AtchCvyFWDBtn)
        IO.Off(ATCHCVY);
    else if(ptr == CureCvyBWDBtn || ptr == CureCvyFWDBtn)
        IO.Off(CURECVY);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    for(int ax=0; ax<AXES; ax++) {
        if(Init.m_nHomePNo[ax] != 0) {
            CanClose = false;
            return;
        }
    }
    CanClose = true;
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CvyBtnClick(TObject *Sender)
{
    /*
    TSpeedButton *p = dynamic_cast<TSpeedButton *>(Sender);

    if(p == Ax8FwdBtn) {
        if(MB.AxisDone(C1)) {
            MB.VelMove(C1, FWD);
            Ax8FwdBtn->Down = true;
            Ax8BwdBtn->Down = false;
        } else {
            MB.VelMove(C1, MSTOP);
            Ax8FwdBtn->Down = false;
            Ax8BwdBtn->Down = false;
        }
    }
    else if(p == Ax8BwdBtn) {
        if(MB.AxisDone(C1)) {
            MB.VelMove(C1, BWD);
            Ax8FwdBtn->Down = false;
            Ax8BwdBtn->Down = true;
        } else {
            MB.VelMove(C1, MSTOP);
            Ax8FwdBtn->Down = false;
            Ax8BwdBtn->Down = false;
        }
    }
    else if(p == Ax9FwdBtn) {
        if(MB.AxisDone(C2)) {
            MB.VelMove(C2, FWD);
            Ax9FwdBtn->Down = true;
            Ax9BwdBtn->Down = false;
        } else {
            MB.VelMove(C2, MSTOP);
            Ax9FwdBtn->Down = false;
            Ax9BwdBtn->Down = false;
        }
    }
    else if(p == Ax9BwdBtn) {
        if(MB.AxisDone(C2)) {
            MB.VelMove(C2, BWD);
            Ax9FwdBtn->Down = false;
            Ax9BwdBtn->Down = true;
        } else {
            MB.VelMove(C2, MSTOP);
            Ax9FwdBtn->Down = false;
            Ax9BwdBtn->Down = false;
        }
    }
    else if(p == Ax11FwdBtn) {
        if(MB.AxisDone(C3)) {
            MB.VelMove(C3, FWD);
            Ax11FwdBtn->Down = true;
            Ax11BwdBtn->Down = false;
        } else {
            MB.VelMove(C3, MSTOP);
            Ax11FwdBtn->Down = false;
            Ax11BwdBtn->Down = false;
        }
    }

    else if(p == Ax11BwdBtn) {
        if(MB.AxisDone(C3)) {
            MB.VelMove(C3, BWD);
            Ax11FwdBtn->Down = false;
            Ax11BwdBtn->Down = true;
        } else {
            MB.VelMove(C3, MSTOP);
            Ax11FwdBtn->Down = false;
            Ax11BwdBtn->Down = false;
        }
    }
    */
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::SpdBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);

    if(ptr == CylTestStartBtn && m_nCylChkPNo == 0) {
        CylChkTimeSpinEdit->Enabled = false;
        CylChkErrMemo->Clear();
        m_nCylChkPNo = 1;
    }
    else if(ptr == CylTestStopBtn) {
        CylChkTimeSpinEdit->Enabled = true;
        m_nCylChkPNo = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::CloseBtnClick(TObject *Sender)
{
    MaintForm->ManualFloat(m_rtForm);
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::MoveBtnClick(TObject *Sender)
{
    int nSlot;
    Coord posMove;

    if(!MB.AxisDone(UL) || !MB.AxisDone(UZ))
        return;

    if(Sender == UlMgzSlotUpBtn || Sender == UlMgzSlotDnBtn) {
        if(sys.fac.nEquipType == HTYPE_1RAIL) {
            //2015.11.06 15:01:20 chcho//
//            nSlot = MB.GetCrntSlotNum(UZ);
//            if(Sender == UlMgzSlotUpBtn) {
//                if(nSlot++ >= mdl.ul.nMgzSlotNum) nSlot = 0;
//            } else {
//                if(nSlot-- < 0) nSlot = mdl.ul.nMgzSlotNum-1;
//            }
//            MB.HTypeUlManMove(UL, MB.GetMgzSlotPos(UL, -1, nSlot));

            int targetSlot = UlSlotNumSpinEdit->Value-1;

            MB.MoveTo(UY, mdl.ul.posMgzStart.y);
            if(Sender == UlMgzSlotUpBtn) {
                if(targetSlot++ >= mdl.ul.nMgzSlotNum)
                    targetSlot = 0;
            }
            else {
                if(targetSlot-- < 0)
                    targetSlot = mdl.ul.nMgzSlotNum-1;
            }
            float targetZPos = MB.GetMgzSlotPos(UZ, 0, targetSlot).z;
            MB.MoveTo(UZ, targetZPos);

            UlSlotNumSpinEdit->Value = targetSlot+1;

        }
        else {
            nSlot = MB.GetCrntSlotNum(UL);
            if(Sender == UlMgzSlotUpBtn) {
                if(nSlot++ >= mdl.ul.nMgzSlotNum*MAX_MGZ) nSlot = 0;
            } else {
                if(nSlot-- < 0) nSlot = (mdl.ul.nMgzSlotNum*MAX_MGZ)-1;
            }
            int nMgz = nSlot/mdl.ul.nMgzSlotNum;
            int nStep = nSlot%mdl.ul.nMgzSlotNum;
            double dPos = MB.GetMgzSlotPos(UL, nMgz, nStep).z;
            MB.MoveTo(UL, dPos);
        }
    }
    else if(Sender == UlMgzSlotGoBtn) {
        if(sys.fac.nEquipType == HTYPE_1RAIL) {
        //2015.11.06 15:14:36 chcho//
//            MB.HTypeUlManMove(UZ, MB.GetMgzSlotPos(UL, -1, UlSlotNumSpinEdit->Value-1));

            int targetSlot = UlSlotNumSpinEdit->Value-1;
            MB.MoveTo(UY, mdl.ul.posMgzStart.y);
            float targetZPos = MB.GetMgzSlotPos(UZ, 0, targetSlot).z;
            MB.MoveTo(UZ, targetZPos); 
        }
        else {
            MB.MoveTo(UL, MB.GetMgzSlotPos(UL, UlMgzNumSpinEdit->Value-1, UlSlotNumSpinEdit->Value-1).z);
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::ReadIOBtnClick(TObject *Sender)
{
    IO.ReadAndDecodeFromIOFile();

    for(int i=0; i<IO_MAX; i++) {
        m_lblIn[i] = NULL;
        m_btnOut[i] = NULL;
    }

    for(int i=0; i<this->ComponentCount; i++) {
        if(Components[i]->ClassNameIs("TLMDGlyphLabel")) {
            AnsiString sIn = ((TLMDGlyphLabel*)Components[i])->Caption;
            int nIn = IO.NameMap[IO_IN][sIn];
            if(nIn >= IO_MAX) continue;
            if(nIn != 0) {
                m_lblIn[nIn] = ((TLMDGlyphLabel*)Components[i]);
            }
            //else CylChkErrMemo->Lines->Add(sIn);
        }
        if(Components[i]->ClassNameIs("TSpeedButton")) {
            AnsiString sOut = ((TSpeedButton*)Components[i])->Caption;
            int nOut = IO.NameMap[IO_OUT][sOut];
            if(nOut >= IO_MAX) continue;
            if(nOut != 0) {
                m_btnOut[nOut] = ((TSpeedButton*)Components[i]);
                ((TSpeedButton*)Components[i])->GroupIndex = i+1;
            }
            //else CylChkErrMemo->Lines->Add(sOut+":"+((TSpeedButton*)Components[i])->Name);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::ComTestBtnClick(TObject *Sender)
{
    static bool bInProcess = false;

    if(bInProcess) return;
    bInProcess = true;


    bInProcess = false;
}
//---------------------------------------------------------------------------
void __fastcall TMaintForm::UnitPosGoBtnClick(TObject *Sender)
{
    if(AnsiString(run.chMdlFile).IsEmpty())
        return;

    TSpeedButton *pBtn = dynamic_cast<TSpeedButton*>(Sender);

    if(pBtn == UnitPosIncBtn || pBtn == UnitPosDecBtn) {
        MB.XYMoveTo(IX, MB.GetNextUnitPos(UnitPosLaneSelChkBox->Checked, pBtn==UnitPosIncBtn?POS:NEG));
    }
}
//---------------------------------------------------------------------------
