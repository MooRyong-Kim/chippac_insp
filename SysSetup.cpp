//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SysSetup.h"
#include "Password.h"
#include "Msg.h"
#include "Maint.h"
#include "Jog.h"
#include "Init.h"
#include "InitProcess.h"
#include "Main.h"
#include "MotionBase.h"
#include "Extern.h"
#include "IOPort.h"
#include "MeasProcess.h"
#include "SecsGem.h"
#include "WorkProcess.h"
#include "RunChk.h"
#include "DataClass.h"
#include "ProtecDll.h"
//---------------------------------------------------------------------------
#include <comctrls.hpp>
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
#pragma link "RzLine"
#pragma resource "*.dfm"
TSysSetupForm *SysSetupForm;
//---------------------------------------------------------------------------
__fastcall TSysSetupForm::TSysSetupForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::FormCreate(TObject *Sender)
{
    //2015.11.09 14:31:23 chcho
    for( int i = 0; i < PageControl1->PageCount; i++ ) {
        PageControl1->Pages[i]->TabVisible = false;
    }
    PageControl1->Align = alClient;

    for(int i=0; i<OprPageCtrl->PageCount; i++)
        OprPageCtrl->Pages[i]->TabVisible = false;
    for(int i=0; i<EngPageCtrl->PageCount; i++)
        EngPageCtrl->Pages[i]->TabVisible = false;
    for(int i=0; i<FacPageCtrl->PageCount; i++)
        FacPageCtrl->Pages[i]->TabVisible = false;

    OprPageCtrl->Align = alClient;
    EngPageCtrl->Align = alClient;
    FacPageCtrl->Align = alClient;

    EngPageCtrl->Visible = false;
    FacPageCtrl->Visible = false;
    OprPageCtrl->Visible = false;

    OprPageCtrl->ActivePageIndex = 1;
    EngPageCtrl->ActivePageIndex = 0;
    FacPageCtrl->ActivePageIndex = 0;

    LdUlSetupPageCtrl->ActivePageIndex = 0;

    TwrLmpComboBox->ItemIndex = 0;
    HTypeUlMgzPosPanel->Align = alClient;
    HTypeUlSetPanel->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::FormShow(TObject *Sender)
{
#ifdef PROTECDLL
    _pvAllWindowHide();
#endif

    SetupTreeView->FullCollapse();
    EngPageCtrl->Visible = false;
    FacPageCtrl->Visible = false;
    OprPageCtrl->Visible = true;
    OprPageCtrl->ActivePageIndex = 0;

    SetupTreeViewPanel->Width = 268;
    sysOld = sys;
    if(Data.LoaderFileCtrl(mdl.pcb.chLoaderFile, false, true))
        LdFileNamePnl->Caption = mdl.pcb.chLoaderFile;
    VarToComponent();
    m_bDataChange = false;
    PasswordForm->m_nResult = PSWD_MISS;

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->SysSetupBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->SysSetupBtn->Width, pt.y+MainForm->SysSetupBtn->Height};
    Ext.DrawWireRects(&rectTo, &rectFrom);

    TickTimer->Enabled = true;
}
//--------------------------------------------------------------------------
void __fastcall TSysSetupForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    TickTimer->Enabled = false;

    if(m_bDataChange) {
        if(MsgDlg->ShowBox("Data Save Exit?",MMB_YESNO|MMI_INFO,0,STR_MSG) == MID_YES)
            ToolBarBtnClick(FileSaveBtn);
    }

    if(MaintForm->Visible)
        MaintForm->Close();

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->SysSetupBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->SysSetupBtn->Width, pt.y+MainForm->SysSetupBtn->Height};
    Ext.DrawWireRects(&rectFrom, &rectTo);

    MainForm->MainPanel->Visible = false;
    MainForm->ProductPanel->Visible = true;

    IO.SetTowerLamp(TWR_IDLE);
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::ToolBarBtnClick(TObject *Sender)
{
    TSpeedButton *ptr = dynamic_cast<TSpeedButton *>(Sender);
    if(ptr == FileSaveBtn) {
        ComponentToVar();
        Data.SaveConfigData();
        Data.LoaderFileCtrl(LdFileNamePnl->Caption, true, true);
        VarToComponent();
    }
    else if(ptr == CancelBtn) {
        if(MsgDlg->ShowBox("Is Cancel Edit Parameter?", MMB_YESNO|MMI_INFO) == MID_YES) {
            sys = sysOld;
            VarToComponent();
        }
    }
    else if(ptr == CloseBtn) {
        SysSetupForm->Close();
    }
}
//---------------------------------------------------------------------------
//ÄÞÆ÷³ÍÆ®ÀÇ °ªÀ» º¯¼ö·Î...
void __fastcall TSysSetupForm::ComponentToVar()
{
    int nIdx, nPkr;
    TComponent *ptr;
    TTreeNode *Node = SetupTreeView->Selected;
//************** Factory ******************//
    //General
    sys.fac.bNoMachine                  = NoHWChkBox->Checked;
    sys.fac.bEnglishVersion             = EnglishVersionChkBox->Checked;
    sys.fac.bDebugMode                  = DebugModeChkBox->Checked;
    sys.fac.bUseSecsGem                 = UseSecsGemChkBox->Checked;
    sys.fac.bSetupBtnPswd               = SetupBtnPswdChkBox->Checked;
    sys.fac.bNoUseUnloader              = NoUseUnloaderChkBox->Checked;
    sys.fac.bUsePreBufCvy               = UsePreBufCvyChkBox->Checked;
    sys.fac.bUseSmema                   = EnaSmemaChkBox->Checked;
    sys.fac.bUseLineScan                = UseLineScanChkBox->Checked;
    sys.fac.bEngSafetySet               = EngSaftySetEnaChkBox->Checked;
    sys.fac.bDisSpdAdjust               = DisableSpdAdjustChkBox->Checked;
    sys.fac.bAlwaysSafetyOn             = AlwaysSafetyOnChkBox->Checked;
    sys.fac.bAutoDoorLock               = AutoDoorLockChkBox->Checked;
    strcpy(sys.fac.chUdpIp, UdpIpEdit->Text.c_str());
    sys.fac.nUdpPort                    = UdpPortEdit->Text.ToIntDef(0);
    sys.fac.bNoUseXYInterpolation       = NoUseXYCoordMoveChkBox->Checked;
    sys.fac.nEquipType                  = EquipTypeSelRdoGrp->ItemIndex;
    sys.fac.bNoUseRearRail              = NoUseRearRailChkBox->Checked;
    sys.fac.bNoUseFnIo                  = NoUseFnIoChkBox->Checked;
    for(int ax=0; ax<AXES; ax++) {
        ptr = FindComponent("Ax"+IntToStr(ax)+"PulsePermmEdit");
        sys.fac.mtr[ax].dPulsePermm = (ptr != NULL)?StrToFloat(((TEdit*)ptr)->Text):sys.fac.mtr[ax-1].dPulsePermm;
        ptr = FindComponent("Ax"+IntToStr(ax)+"MSftLmtPosEdit");
        sys.fac.mtr[ax].dMSftLmt = (ptr != NULL)?StrToFloat(((TEdit*)ptr)->Text):sys.fac.mtr[ax-1].dMSftLmt;
        ptr = FindComponent("Ax"+IntToStr(ax)+"PSftLmtPosEdit");
        sys.fac.mtr[ax].dPSftLmt = (ptr != NULL)?StrToFloat(((TEdit*)ptr)->Text):sys.fac.mtr[ax-1].dPSftLmt;
        ptr = FindComponent("Ax"+IntToStr(ax)+"HomeOfstEdit");
        sys.fac.mtr[ax].dHomeOfst = (ptr != NULL)?StrToFloat(((TEdit*)ptr)->Text):sys.fac.mtr[ax-1].dHomeOfst;
    }
//************** Operator ******************//
    //General
    sys.opr.bMsgBoxBuzz                 = MsgBoxBuzzChkBox->Checked;
    sys.opr.nMsgBoxBuzzTime             = MsgBoxBuzzTimeSpinEdit->Value;
    //Delay Time
    sys.opr.nBlkUpDly                   = BlkUpDlySpinEdit->Value;    
    sys.opr.nBlkVacOffDly               = BlkVacOffDlySpinEdit->Value;
    sys.opr.nCvyStopDly                 = TransferDlySpinEdit->Value;
    sys.opr.nUlCvyStopDly               = UnloadingDlySpinEdit->Value;
    sys.opr.nUlPushOnDly                = UlPusherOnDlySpinEdit->Value;
    sys.opr.nCvyStprUpDly               = StprUpDlySpinEdit->Value;
    sys.opr.nVsnAutoRtyCnt              = VsnAutoRtyCntSpinEdit->Value;
    sys.opr.nVsnDly                     = InspDlySpinEdit->Value;
    sys.opr.nVsnErrSet                  = UnitVsnErrSetRdoGrp->ItemIndex;
    sys.opr.bInspErrCollect             = InspErrCollectChkBox->Checked;
    //2016.02.11 19:53:21 chcho
    sys.eng.nDelayVacuum                = VacOnDelaySpinEdit->Value; 
//************** Engineer ******************//
    //System Log
    for(int i=0; i<SysLogItemChkListBox->Items->Count; i++)
        sys.eng.bLogItem[i] = SysLogItemChkListBox->Checked[i];
    //Password
    strcpy(sys.eng.chOprPswd, OprPswdChangeEdit->Text.c_str());
    strcpy(sys.eng.chEngPswd, EngPswdChangeEdit->Text.c_str());
    //Tower Lamp
    nIdx = TwrLmpComboBox->ItemIndex-1;
    if(nIdx >= 0) {
        sys.eng.twr[nIdx].nGrnLight         = GrnLmpRdoGrp->ItemIndex;
        sys.eng.twr[nIdx].nGrnFlashIntvl    = GrnLmpFlashTimeSpinEdit->Value;
        sys.eng.twr[nIdx].nYlwLight         = YlwLmpRdoGrp->ItemIndex;
        sys.eng.twr[nIdx].nYlwFlashIntvl    = YlwLmpFlashTimeSpinEdit->Value;
        sys.eng.twr[nIdx].nRedLight         = RedLmpRdoGrp->ItemIndex;
        sys.eng.twr[nIdx].nRedFlashIntvl    = RedLmpFlashTimeSpinEdit->Value;
        sys.eng.twr[nIdx].bUseBuzz          = BuzzChkBox->Checked;
        sys.eng.twr[nIdx].bBuzzAutoOff      = UseBuzzValidTimeChkBox->Checked;
        sys.eng.twr[nIdx].nBuzzOnTime       = BuzzValidTimeSpinEdit->Value;
    }
    //Log
    sys.eng.nFileValidDay               = FileValidDaySpinEdit->Value;
    //Safety
    sys.eng.bSafetySrvOff               = SafetySrvOffChkBox->Checked;
    sys.eng.bFrntDoorSafety             = FrntDoorSafetyChkBox->Checked;
    sys.eng.bUvDoorSafety               = UvDoorSafetyChkBox->Checked;
    sys.eng.bUlBarSafety                = UlBarSafetyChkBox->Checked;
    //Time Error
    sys.eng.nCylTimeErr                 = CylTimeErrSpinEdit->Value;
    sys.eng.nBlkVacTimeErr              = BlkVacTimeErrSpinEdit->Value;
    sys.eng.nCvyTimeErr                 = CvyTimeErrSpinEdit->Value;
    sys.eng.nComTimeErr                 = ComTimeErrSpinEdit->Value;
    //Conveyor
    sys.eng.bNoUseInspBlk               = NoUseInspBlkChkBox->Checked;
    sys.eng.bUseClamp                   = UseClampChkBox->Checked;
    sys.eng.bNoUseInspBlkVacErr         = NoUseInspBlkVacErrChkBox->Checked;
    sys.eng.bNoUseInspBlkVacOn          = NoUseInspBlkVacOnChkBox->Checked;
    sys.eng.nInspBlkVacRtyNum           = InspBlkVacRtyNumSpinEdit->Value;
    //Unloader Position
    sys.eng.bUseUlJamSens               = UseUlPushJamChkBox->Checked;
    sys.eng.bUseUlErrMcStop             = UlErrMcStopChkBox->Checked;

    sys.eng.BarcodeRetryCnt             = SpinBcrRetryCnt->Value;
    sys.eng.UseHeaterAlarm              = ChkHeaterAlarm->Checked;

    //2016.02.15 12:29:33 chcho
    sys.eng.UseNetworkFrontDisp         = ChkFrontDispComm->Checked;


    //Motor
    for(int ax=0; ax<AXES; ax++) {
        ptr = FindComponent("Ax"+IntToStr(ax)+"SpdSpinEdit");
        sys.eng.mtr[ax].nSpd = (ptr != NULL)?((TLMDSpinEdit*)ptr)->Value:sys.eng.mtr[ax-1].nSpd;
        ptr = FindComponent("Ax"+IntToStr(ax)+"AccSpinEdit");
        sys.eng.mtr[ax].nAcc = (ptr != NULL)?((TLMDSpinEdit*)ptr)->Value:sys.eng.mtr[ax-1].nAcc;
        ptr = FindComponent("Ax"+IntToStr(ax)+"JSpdSpinEdit");
        sys.eng.mtr[ax].nJogSpd = (ptr != NULL)?((TLMDSpinEdit*)ptr)->Value:sys.eng.mtr[ax-1].nJogSpd;
        ptr = FindComponent("Ax"+IntToStr(ax)+"JAccSpinEdit");
        sys.eng.mtr[ax].nJogAcc = (ptr != NULL)?((TLMDSpinEdit*)ptr)->Value:sys.eng.mtr[ax-1].nJogAcc;
        ptr = FindComponent("Ax"+IntToStr(ax)+"HSpdSpinEdit");
        sys.eng.mtr[ax].nHomeSpd = (ptr != NULL)?((TLMDSpinEdit*)ptr)->Value:sys.eng.mtr[ax-1].nHomeSpd;
    }
    //Warning Safety Unlock
    if(!FrntDoorSafetyChkBox->Checked || !UlBarSafetyChkBox->Checked) {
        if(EngPageCtrl->ActivePageIndex == 2)
            MsgDlg->ShowBox("Warning Safety Unlock", MMI_WARNING|MMB_OK, 0, STR_ERR);
        if(m_bDataChange)
            SecsGemForm->SendEvent(C_SAFETY_UNLOCK, false);
    } else {
        if(m_bDataChange)
            SecsGemForm->SendEvent(C_SAFETY_LOCK, false);
    }

    if(m_bDataChange)
        SecsGemForm->SendEvent(C_CHANGE_CFG);

    LoaderDataSet(true);

    m_bDataChange = false;
}
//---------------------------------------------------------------------------
//º¯¼ö °ªÀ» ÄÞÆ÷³ÍÆ®·Î...
void __fastcall TSysSetupForm::VarToComponent()
{
    int nIdx, nPkr;
    TComponent *ptr;
    TTreeNode *Node = SetupTreeView->Selected;
//************** Factory ******************//
    //General
    NoHWChkBox->Checked                             = sys.fac.bNoMachine;
    EnglishVersionChkBox->Checked                   = sys.fac.bEnglishVersion;
    DebugModeChkBox->Checked                        = sys.fac.bDebugMode;
    UseSecsGemChkBox->Checked                       = sys.fac.bUseSecsGem;
    SetupBtnPswdChkBox->Checked                     = sys.fac.bSetupBtnPswd;
    NoUseUnloaderChkBox->Checked                    = sys.fac.bNoUseUnloader;
    UsePreBufCvyChkBox->Checked                     = sys.fac.bUsePreBufCvy;
    EnaSmemaChkBox->Checked                         = sys.fac.bUseSmema;
    UseLineScanChkBox->Checked                      = sys.fac.bUseLineScan;
    EngSaftySetEnaChkBox->Checked                   = sys.fac.bEngSafetySet;
    DisableSpdAdjustChkBox->Checked                 = sys.fac.bDisSpdAdjust;
    AlwaysSafetyOnChkBox->Checked                   = sys.fac.bAlwaysSafetyOn;
    AutoDoorLockChkBox->Checked                     = sys.fac.bAutoDoorLock;
    UdpIpEdit->Text                                 = AnsiString(sys.fac.chUdpIp);
    UdpPortEdit->Text                               = IntToStr(sys.fac.nUdpPort);
    NoUseXYCoordMoveChkBox->Checked                 = sys.fac.bNoUseXYInterpolation;
    EquipTypeSelRdoGrp->ItemIndex                   = sys.fac.nEquipType;
    NoUseRearRailChkBox->Checked                    = sys.fac.bNoUseRearRail;
    NoUseFnIoChkBox->Checked                        = sys.fac.bNoUseFnIo;
    //Factory Motor
    for(int ax=0; ax<AXES; ax++) {
        ptr = FindComponent("Ax"+IntToStr(ax)+"MSftLmtPosEdit");
        if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.fac.mtr[ax].dMSftLmt,3);
        ptr = FindComponent("Ax"+IntToStr(ax)+"PSftLmtPosEdit");
        if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.fac.mtr[ax].dPSftLmt,3);
        ptr = FindComponent("Ax"+IntToStr(ax)+"PulsePermmEdit");
        if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.fac.mtr[ax].dPulsePermm,3);
        ptr = FindComponent("Ax"+IntToStr(ax)+"HomeOfstEdit");
        if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.fac.mtr[ax].dHomeOfst,3);
    }
    //The Others
    ModifyTimePanel->Caption = "  Modified: "+AnsiString(sys.chModifyTime);
//************** Operator ******************//
    //General
    MsgBoxBuzzChkBox->Checked                   = sys.opr.bMsgBoxBuzz;
    MsgBoxBuzzTimeSpinEdit->Value               = sys.opr.nMsgBoxBuzzTime;
    //Delay Time
    BlkUpDlySpinEdit->Value                     = sys.opr.nBlkUpDly;
    BlkVacOffDlySpinEdit->Value                 = sys.opr.nBlkVacOffDly;
    TransferDlySpinEdit->Value                  = sys.opr.nCvyStopDly;
    UnloadingDlySpinEdit->Value                 = sys.opr.nUlCvyStopDly;
    UlPusherOnDlySpinEdit->Value                = sys.opr.nUlPushOnDly;
    StprUpDlySpinEdit->Value                    = sys.opr.nCvyStprUpDly;
    VsnAutoRtyCntSpinEdit->Value                = sys.opr.nVsnAutoRtyCnt;
    InspDlySpinEdit->Value                      = sys.opr.nVsnDly;
    UnitVsnErrSetRdoGrp->ItemIndex              = sys.opr.nVsnErrSet;
    InspErrCollectChkBox->Checked               = sys.opr.bInspErrCollect;
    //2016.02.11 19:53:21 chcho
    VacOnDelaySpinEdit->Value                   = sys.eng.nDelayVacuum;
//************** Engineer ******************//
    //System Log
    for(int i=0; i<SysLogItemChkListBox->Items->Count; i++)
            SysLogItemChkListBox->Checked[i] = sys.eng.bLogItem[i];
    //Password
    OprPswdChangeEdit->Text             = AnsiString(sys.eng.chOprPswd);
    EngPswdChangeEdit->Text             = AnsiString(sys.eng.chEngPswd);
    //Tower Lamp
    nIdx = TwrLmpComboBox->ItemIndex-1;
    if(nIdx >= 0) {
        GrnLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nGrnLight;
        GrnLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nGrnFlashIntvl;
        YlwLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nYlwLight;
        YlwLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nYlwFlashIntvl;
        RedLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nRedLight;
        RedLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nRedFlashIntvl;
        BuzzChkBox->Checked                 = sys.eng.twr[nIdx].bUseBuzz;
        UseBuzzValidTimeChkBox->Checked     = sys.eng.twr[nIdx].bBuzzAutoOff;
        BuzzValidTimeSpinEdit->Value        = sys.eng.twr[nIdx].nBuzzOnTime;
    }
    //Log
    FileValidDaySpinEdit->Value             = sys.eng.nFileValidDay;
    //Safety
    SafetySrvOffChkBox->Checked             = sys.eng.bSafetySrvOff;
    FrntDoorSafetyChkBox->Checked           = sys.eng.bFrntDoorSafety;
    UlBarSafetyChkBox->Checked              = sys.eng.bUlBarSafety;
    //Time Error
    CylTimeErrSpinEdit->Value               = sys.eng.nCylTimeErr;
    BlkVacTimeErrSpinEdit->Value            = sys.eng.nBlkVacTimeErr;
    CvyTimeErrSpinEdit->Value               = sys.eng.nCvyTimeErr;
    ComTimeErrSpinEdit->Value               = sys.eng.nComTimeErr;
    //Conveyor
    NoUseInspBlkChkBox->Checked             = sys.eng.bNoUseInspBlk;
    UseClampChkBox->Checked                 = sys.eng.bUseClamp;
    NoUseInspBlkVacErrChkBox->Checked       = sys.eng.bNoUseInspBlkVacErr;
    NoUseInspBlkVacOnChkBox->Checked        = sys.eng.bNoUseInspBlkVacOn;
    InspBlkVacRtyNumSpinEdit->Value         = sys.eng.nInspBlkVacRtyNum;
    //Unloader Position
    UseUlPushJamChkBox->Checked             = sys.eng.bUseUlJamSens;
    UlErrMcStopChkBox->Checked              = sys.eng.bUseUlErrMcStop;

    SpinBcrRetryCnt->Value                  = sys.eng.BarcodeRetryCnt;
    ChkHeaterAlarm->Checked                 = sys.eng.UseHeaterAlarm;

    //2016.02.15 12:30:35 chcho
    ChkFrontDispComm->Checked               = sys.eng.UseNetworkFrontDisp;

    //Motor Speed
    for(int ax=0; ax<AXES; ax++) {
        ptr = FindComponent("Ax"+IntToStr(ax)+"SpdSpinEdit");
        if(ptr != NULL) ((TLMDSpinEdit*)ptr)->Value = sys.eng.mtr[ax].nSpd;
        ptr = FindComponent("Ax"+IntToStr(ax)+"AccSpinEdit");
        if(ptr != NULL) ((TLMDSpinEdit*)ptr)->Value = sys.eng.mtr[ax].nAcc;
        ptr = FindComponent("Ax"+IntToStr(ax)+"JSpdSpinEdit");
        if(ptr != NULL) ((TLMDSpinEdit*)ptr)->Value = sys.eng.mtr[ax].nJogSpd;
        ptr = FindComponent("Ax"+IntToStr(ax)+"JAccSpinEdit");
        if(ptr != NULL) ((TLMDSpinEdit*)ptr)->Value = sys.eng.mtr[ax].nJogAcc;
        ptr = FindComponent("Ax"+IntToStr(ax)+"HSpdSpinEdit");
        if(ptr != NULL) ((TLMDSpinEdit*)ptr)->Value = sys.eng.mtr[ax].nHomeSpd;
    }

    LoaderDataSet(false);

    m_bDataChange = false;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::GetPosBtnClick(TObject *Sender)
{
    TRzBitBtn *pBtn = dynamic_cast<TRzBitBtn*>(Sender);
    TTreeNode *Node = SetupTreeView->Selected;

//Vetical Magazine
    if(pBtn == UlMgz1StartPosGetBtn)
        UlMgz1StartPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
    else if(pBtn == UlMgz1EndPosGetBtn)
        UlMgz1EndPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
    else if(pBtn == UlMgz2StartPosGetBtn)
        UlMgz2StartPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
    else if(pBtn == UlMgz2EndPosGetBtn)
        UlMgz2EndPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
    else if(pBtn == UlMgz3StartPosGetBtn)
        UlMgz3StartPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
    else if(pBtn == UlMgz3EndPosGetBtn)
        UlMgz3EndPosEdit->Text = Ext.FloatToStr(MB.GetPos(UL));
//Horizontal Magazine
    else if(pBtn == UlMgzStartPosGetBtn) {
        UlMgzStartYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY));
        UlMgzStartZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ));
    }
    else if(pBtn == UlMgzEndZPosGetBtn)
        UlMgzEndZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ));
//Horizintal Unaloder
    else if(pBtn == UlMgzGripOnPrePosGetBtn) {
        UlMgzGripOnPreYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOnPreZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOnCvyPosGetBtn) {
        UlMgzGripOnCvyYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOnCvyZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOnUpPosGetBtn) {
        UlMgzGripOnUpYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOnUpZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOnOutPosGetBtn) {
        UlMgzGripOnOutYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOnOutZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOffPrePosGetBtn) {
        UlMgzGripOffPreYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOffPreZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOffCvyPosGetBtn) {
        UlMgzGripOffCvyYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOffCvyZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOffPosGetBtn) {
        UlMgzGripOffYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOffZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOffDnPosGetBtn) {
        UlMgzGripOffDnYPosEdit->Text = Ext.FloatToStr(MB.GetPos(UY),3);
        UlMgzGripOffDnZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    }
    else if(pBtn == UlMgzGripOffOutPosGetBtn) {
        UlMgzGripOffOutYPosEdit->Text = Ext.FloatToStr(0.);
        UlMgzGripOffOutZPosEdit->Text = Ext.FloatToStr(MB.GetPos(UZ),3);
    } else {
        for(int ax=0; ax<AXES; ax++) {
            if(pBtn->Name == "Ax"+IntToStr(ax)+"MSftLmtPosGetBtn") {
                TEdit *pEdit = (TEdit*)(FindComponent("Ax"+IntToStr(ax)+"MSftLmtPosEdit"));
                pEdit->Text = Ext.FloatToStr(MB.GetPos(ax),3);
            }
            else if(pBtn->Name == "Ax"+IntToStr(ax)+"PSftLmtPosGetBtn") {
                TEdit *pEdit = (TEdit*)(FindComponent("Ax"+IntToStr(ax)+"PSftLmtPosEdit"));
                pEdit->Text = Ext.FloatToStr(MB.GetPos(ax),3);
            }
            else if(pBtn->Name == "Ax"+IntToStr(ax)+"HomeOfstGetBtn") {
                TEdit *pEdit = (TEdit*)(FindComponent("Ax"+IntToStr(ax)+"HomeOfstEdit"));
                pEdit->Text = Ext.FloatToStr(MB.GetPos(ax),3);
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::GoBtnClick(TObject *Sender)
{
    TRzBitBtn *pBtn = dynamic_cast<TRzBitBtn*>(Sender);
    TTreeNode *Node = SetupTreeView->Selected;
    Coord pos;

//Vertical Magazine
    if(pBtn == UlMgz1StartPosGoBtn)
        MB.MoveTo(UL, UlMgz1StartPosEdit->Text.ToDouble());
    else if(pBtn == UlMgz1EndPosGoBtn)
        MB.MoveTo(UL, UlMgz1EndPosEdit->Text.ToDouble());

    else if(pBtn == UlMgz2StartPosGoBtn)
        MB.MoveTo(UL, UlMgz2StartPosEdit->Text.ToDouble());
    else if(pBtn == UlMgz2EndPosGoBtn)
        MB.MoveTo(UL, UlMgz2EndPosEdit->Text.ToDouble());

    else if(pBtn == UlMgz3StartPosGoBtn)
        MB.MoveTo(UL, UlMgz3StartPosEdit->Text.ToDouble());
    else if(pBtn == UlMgz3EndPosGoBtn)
        MB.MoveTo(UL, UlMgz3EndPosEdit->Text.ToDouble());
//Horizontal Magazine
    else if(pBtn == UlMgzStartPosGoBtn) {
        pos.y = UlMgzStartYPosEdit->Text.ToDouble();
        pos.z = UlMgzStartZPosEdit->Text.ToDouble();
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzEndZPosGoBtn) {
        pos.y = sys.ul.posMgzStart.y;
        pos.z = UlMgzEndZPosEdit->Text.ToDouble();
        MB.HTypeUlManMove(UL, pos);
    }
//Horizontal Unloader
    else if(pBtn == UlMgzGripOnPrePosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOnPreYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOnPreZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOnCvyPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOnCvyYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOnCvyZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOnUpPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOnUpYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOnUpZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOnOutPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOnOutYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOnOutZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOffPrePosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOffPreYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOffPreZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOffCvyPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOffCvyYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOffCvyZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOffPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOffYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOffZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOffDnPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOffDnYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOffDnZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    else if(pBtn == UlMgzGripOffOutPosGoBtn) {
        pos.y = StrToFloat(UlMgzGripOffOutYPosEdit->Text);
        pos.z = StrToFloat(UlMgzGripOffOutZPosEdit->Text);
        MB.HTypeUlManMove(UL, pos);
    }
    //Factory setup
    else {
        for(int ax=0; ax<AXES; ax++) {
            if(pBtn->Name == ("Ax"+IntToStr(ax)+"MSftLmtPosGoBtn")) {
                TEdit *pEdit = (TEdit*)(FindComponent("Ax"+IntToStr(ax)+"MSftLmtPosEdit"));
                MB.MoveTo(ax, StrToFloat(pEdit->Text));
            }
            else if(pBtn->Name == ("Ax"+IntToStr(ax)+"PSftLmtPosGoBtn")) {
                TEdit *pEdit = (TEdit*)(FindComponent("Ax"+IntToStr(ax)+"PSftLmtPosEdit"));
                MB.MoveTo(ax, StrToFloat(pEdit->Text));
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::BitBtnClick(TObject *Sender)
{
    TBitBtn *ptr = dynamic_cast<TBitBtn *>(Sender);

    AnsiString sPswd;
    TEdit *pChangeEdit, *pConfirmEdit;

    if(ptr == OprPswdSetBtn) {
        sPswd = OprPswdChangeEdit->Text;
        pChangeEdit = OprPswdChangeEdit;
        pConfirmEdit = OprPswdConfirmEdit;
    }
    else if(ptr == EngPswdSetBtn) {
        sPswd = EngPswdChangeEdit->Text;
        pChangeEdit = EngPswdChangeEdit;
        pConfirmEdit = EngPswdConfirmEdit;
    }
    else if(ptr == WorkPswdSetBtn) {
        sPswd = WorkPswdChangeEdit->Text;
        pChangeEdit = WorkPswdChangeEdit;
        pConfirmEdit = WorkPswdConfirmEdit;
    }
    else return;

    if(pChangeEdit->Text == "" || pChangeEdit->Text.AnsiPos(" ")) {
        MsgDlg->ShowBox("Do Not Use Empty Or Space.");
        pConfirmEdit->Text = "";
        return;
    }

    /*if(sys.fac.bCESafetyMode) {
        if(sPswd.Length() < 6) {
            MsgDlg->ShowBox("Please Enter At Least 6 Characters.");
            return;
        }
        bool bNumber = false;
        bool bAlpabet = false;
        char *chStr = sPswd.c_str();
        for(int i=0; i<sPswd.Length(); i++) {
            if(chStr[i] >= 'A' && chStr[i] <= 'Z') {
                MsgDlg->ShowBox("Please Enter Only Lowercase Letters.");
                break;
            }
        }
        for(int i=0; i<sPswd.Length(); i++) {
            if(chStr[i] >= '0' && chStr[i] <= '9') {
                bNumber = true;
                break;
            }
        }
        for(int i=0; i<sPswd.Length(); i++) {
            if(chStr[i] >= 'a' && chStr[i] <= 'z') {
                bAlpabet = true;
                break;
            }
        }
        if(!bNumber) {
            MsgDlg->ShowBox("It Must Contain At Least One Of The Numbers.");
            return;
        }
        if(!bAlpabet) {
            MsgDlg->ShowBox("It Must Contain At Least One Of The Characters.");
            return;
        }
    }*/
    if(pChangeEdit->Text.AnsiCompare(pConfirmEdit->Text) != 0) {
        strcpy(sys.eng.chOprPswd, pChangeEdit->Text.c_str());
        MsgDlg->ShowBox("Password Changed Complete.");
    } else {
        MsgDlg->ShowBox("Incorrect Confirm Password.");
        pChangeEdit->Text = AnsiString(sys.eng.chOprPswd);
    }
    pConfirmEdit->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::SetupTreeViewChanging(TObject *Sender,
      TTreeNode *Node, bool &AllowChange)
{
    if(m_bDataChange)
        ComponentToVar();
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::SetupTreeViewChange(TObject *Sender,
      TTreeNode *Node)
{
    if(!TickTimer->Enabled || Node->Text == "Disable") {
        OprPageCtrl->Visible = false;
        EngPageCtrl->Visible = false;
        FacPageCtrl->Visible = false;
        return;
    }

    this->Caption = Node->Text;
    int nIndex = Node->StateIndex;

    OprPageCtrl->Visible = false;
    EngPageCtrl->Visible = false;
    FacPageCtrl->Visible = false;

//    if(nIndex == 0) {
//        OprPageCtrl->Visible = true;
//        OprPageCtrl->ActivePageIndex = 0;
//    }
//    else if(nIndex == 10) {
//        EngPageCtrl->Visible = true;
//        EngPageCtrl->ActivePageIndex = 0;
//    }
//    else if(nIndex == 100) {
//        FacPageCtrl->Visible = true;
//        FacPageCtrl->ActivePageIndex = 0;
//    }
//    else if(nIndex > 0 && nIndex < 10) {
//        OprPageCtrl->Visible = true;
//        OprPageCtrl->ActivePageIndex = nIndex;
//    }
//    else if(nIndex > 10 && nIndex < 100) {
//        EngPageCtrl->Visible = true;
//        EngPageCtrl->ActivePageIndex = nIndex-10;
//    }
//    else if(nIndex > 100) {
//        FacPageCtrl->Visible = true;
//        FacPageCtrl->ActivePageIndex = nIndex-100;
//    }
    if(nIndex == 0) {
        PageControl1->ActivePageIndex = 0;
        OprPageCtrl->Visible = true;
        OprPageCtrl->ActivePageIndex = 0;
    }
    else if(nIndex == 10) {
        PageControl1->ActivePageIndex = 1;
        EngPageCtrl->Visible = true;
        EngPageCtrl->ActivePageIndex = 0;
    }
    else if(nIndex == 100) {
        PageControl1->ActivePageIndex = 2;
        FacPageCtrl->Visible = true;
        FacPageCtrl->ActivePageIndex = 0;
    }
    else if(nIndex > 0 && nIndex < 10) {
        PageControl1->ActivePageIndex = 0;
        OprPageCtrl->Visible = true;
        OprPageCtrl->ActivePageIndex = nIndex;
    }
    else if(nIndex > 10 && nIndex < 100) {
        PageControl1->ActivePageIndex = 1;
        EngPageCtrl->Visible = true;
        EngPageCtrl->ActivePageIndex = nIndex-10;
    }
    else if(nIndex > 100) {
        PageControl1->ActivePageIndex = 2;
        FacPageCtrl->Visible = true;
        FacPageCtrl->ActivePageIndex = nIndex-100;
    }
    VarToComponent();

    TickTimerTimer(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::SetupTreeViewExpanding(TObject *Sender,
      TTreeNode *Node, bool &AllowExpansion)
{
    if(Node->Text == "Disable") {
        AllowExpansion = false;
        return;
    }

    if(sys.fac.bNoMachine) {
        AllowExpansion = true;
        return;
    }

    if(Node->StateIndex == 0 && Node->ImageIndex == 0) {
         AllowExpansion = (PasswordForm->m_nResult == PSWD_OPR_MATCH ||
                            PasswordForm->m_nResult == PSWD_ENG_MATCH ||
                            PasswordForm->m_nResult == PSWD_FAC_MATCH);
         if(!AllowExpansion) {
            int nRtn = PasswordForm->PasswordCheck(Node->StateIndex);
            if(nRtn == PSWD_OPR_MATCH || nRtn == PSWD_ENG_MATCH || nRtn == PSWD_FAC_MATCH)
                AllowExpansion = true;
            else {
                if(nRtn == PSWD_MISS)
                    MsgDlg->ShowBox("Invalid Password.");
                AllowExpansion = false;
            }
        }
    }
    else if(Node->StateIndex == 10 && Node->ImageIndex == 1) {
         AllowExpansion = (PasswordForm->m_nResult == PSWD_ENG_MATCH ||
                            PasswordForm->m_nResult == PSWD_FAC_MATCH);
         if(!AllowExpansion) {
            int nRtn = PasswordForm->PasswordCheck(Node->StateIndex);
            if(nRtn == PSWD_ENG_MATCH || nRtn == PSWD_FAC_MATCH)
                AllowExpansion = true;
            else {
                if(nRtn == PSWD_MISS)
                    MsgDlg->ShowBox("Invalid Password.");
                AllowExpansion = false;
            }
        }
    }
    else if(Node->StateIndex == 100 && Node->ImageIndex == 2) {
         AllowExpansion = (PasswordForm->m_nResult == PSWD_FAC_MATCH);
         if(!AllowExpansion) {
            int nRtn = PasswordForm->PasswordCheck(Node->StateIndex);
            if(nRtn == PSWD_FAC_MATCH)
                AllowExpansion = true;
            else {
                if(nRtn == PSWD_MISS)
                    MsgDlg->ShowBox("Invalid Password.");
                AllowExpansion = false;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::TickTimerTimer(TObject *Sender)
{
    FileNamePanel->Caption = "  File Path: "+sys.sFileName;
    CancelBtn->Enabled = m_bDataChange;

    UlBarSafetyChkBox->Enabled = !AlwaysSafetyOnChkBox->Checked;
    GroupBox1->Visible = EngSaftySetEnaChkBox->Checked;
    EngPageCtrl->Pages[4]->Visible = !DisableSpdAdjustChkBox->Checked;

    HTypeUlSetPanel->Visible = (sys.fac.nEquipType==HTYPE_1RAIL);
    LdUlSetupPageCtrl->Pages[1]->TabVisible = (sys.fac.nEquipType==HTYPE_1RAIL);
    HTypeUlMgzPosPanel->Visible = (sys.fac.nEquipType==HTYPE_1RAIL);
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::TwrLmpComboBoxChange(TObject *Sender)
{
    int nIdx = TwrLmpComboBox->ItemIndex-1;
    if(nIdx >= 0) {
        GrnLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nGrnLight;
        GrnLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nGrnFlashIntvl;
        YlwLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nYlwLight;
        YlwLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nYlwFlashIntvl;
        RedLmpRdoGrp->ItemIndex             = sys.eng.twr[nIdx].nRedLight;
        RedLmpFlashTimeSpinEdit->Value      = sys.eng.twr[nIdx].nRedFlashIntvl;
        BuzzChkBox->Checked                 = sys.eng.twr[nIdx].bUseBuzz;
        m_bDataChange = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::TrackBarChange(TObject *Sender)
{
    TTrackBar *ptr = dynamic_cast<TTrackBar *>(Sender);

    AnsiString sLblName = ptr->Name;
    sLblName.Delete(sLblName.Pos("TrackBar"),8);
    sLblName+="Lbl";
    TLabel *pLbl = (TLabel*)(FindComponent(sLblName));
    if(pLbl != NULL)
        pLbl->Caption = IntToStr(ptr->Position)+" %";
    m_bDataChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::DataChange(TObject *Sender)
{
    m_bDataChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::DataClick(TObject *Sender)
{
    m_bDataChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::UnitDataChange(TObject *Sender)
{
    m_bDataChange = true;
}
//--------------------------------------------------------------------------
void __fastcall TSysSetupForm::PosDataChange(TObject *Sender)
{
    m_bDataChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::FormKeyPress(TObject *Sender, char &Key)
{
/*    if(EngPageCtrl->ActivePage != EngPage2) {
        if((Key < '0' || Key > '9') && Key != '.' && Key != '-'  && Key != 22 && Key != 3)
            Key = 0x00;
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::MotionBtnClick(TObject *Sender)
{
    TSpeedButton *pBtn = dynamic_cast<TSpeedButton *>(Sender);

    if(pBtn == UlMgzLdBtn) {
        if(MB.InitCheck()) {
            LDUL_DATA tmpUl;
            tmpUl = mdl.ul;
            mdl.ul = sys.ul;
            Work.pNo.nUl = 1;
            if(MsgDlg->ShowBox("Unloader Magazine Loading Start.",
                MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
                Work.pNo.nUl = 0;
            }
            mdl.ul = tmpUl;
        }
        return;
    }
    else if(pBtn == UlMgzUlBtn) {
        if(MB.InitCheck()) {
            LDUL_DATA tmpUl;
            tmpUl = mdl.ul;
            mdl.ul = sys.ul;
            Work.pNo.nUl = 105;
            if(MsgDlg->ShowBox("Unloader Magazine Unloading Start.",
                MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
                Work.pNo.nUl = 0;
            }
            mdl.ul = tmpUl;
        }
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::UlSelectCmbBoxChange(TObject *Sender)
{
    VarToComponent();
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::m_SaveSettingsClick(TObject *Sender)
{
    AnsiString sPath = SYS_FILE_PATH+"Loader";
    ForceDirectories(sPath);
    SaveDialog1->InitialDir = sPath;

    SaveDialog1->Filter = "Loader File|*.LD|";
    if(SaveDialog1->Execute()) {
        LoaderDataSet(true);

        AnsiString FileName=SaveDialog1->FileName;
        if (FileName.AnsiPos(".")==0) FileName+=".LD";
        if (FileExists(FileName)) // Old file makes to back up
             DeleteFile (FileName);

        int nFileHandle=FileCreate(FileName);
        if (nFileHandle==-1) {
            MsgDlg->ShowBox("Loader Data Save Error.");
            return ;
        }
        FileWrite(nFileHandle, &sys.ul,sizeof(sys.ul));
        FileClose(nFileHandle);
        LdFileNamePnl->Caption = FileName;

        LoaderDataSet(false);
        Data.LoaderFileCtrl(mdl.pcb.chLoaderFile, false, false);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::m_LoadSettingsClick(TObject *Sender)
{
    AnsiString sPath = SYS_FILE_PATH+"Loader";
    ForceDirectories(sPath);
    OpenDialog1->InitialDir = sPath;

    OpenDialog1->Filter = "Loader File|*.LD|";
    if(OpenDialog1->Execute()) {
        if(!Data.LoaderFileCtrl(OpenDialog1->FileName, false, true)) return;
        LdFileNamePnl->Caption = OpenDialog1->FileName;
        LoaderDataSet(false);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSysSetupForm::LoaderDataSet(bool bCompToVar)
{
    if(bCompToVar) {
    //Vertical type unloader
        sys.ul.nMgzSlotNum                      = UlMgzSlotNumSpinEdit->Value;
        sys.ul.bUseRejMgz                       = UseRejMgzChkBox->Checked;
        sys.ul.nRejMgzSel                       = RejMgzSelSpinEdit->Value;
        for(int i=0; i<MAX_MGZ; i++) {
            TComponent *ptr;
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"UseChkBox");
            if(ptr != NULL) sys.ul.bUseMgz[i]         = ((TCheckBox*)ptr)->Checked;
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"StartPosEdit");
            if(ptr != NULL) sys.ul.dMgzStartPos[i]    = StrToFloat(((TEdit*)ptr)->Text);
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"EndPosEdit");
            if(ptr != NULL) sys.ul.dMgzEndPos[i]      = StrToFloat(((TEdit*)ptr)->Text);
        }
    //Horizontal type unloader
        sys.ul.posMgzStart.y                    = UlMgzStartYPosEdit->Text.ToDouble();
        sys.ul.posMgzStart.z                    = UlMgzStartZPosEdit->Text.ToDouble();
        sys.ul.posMgzEnd.y                      = sys.ul.posMgzStart.y;
        sys.ul.posMgzEnd.z                      = UlMgzEndZPosEdit->Text.ToDouble();
        //Loading Position
        sys.ul.posGripOnPre.y                   = StrToFloat(UlMgzGripOnPreYPosEdit->Text);
        sys.ul.posGripOnPre.z                   = StrToFloat(UlMgzGripOnPreZPosEdit->Text);
        sys.ul.posGripOnCvy.y                   = StrToFloat(UlMgzGripOnCvyYPosEdit->Text);
        sys.ul.posGripOnCvy.z                   = StrToFloat(UlMgzGripOnCvyZPosEdit->Text);
        sys.ul.posGripOnUp.y                    = StrToFloat(UlMgzGripOnUpYPosEdit->Text);
        sys.ul.posGripOnUp.z                    = StrToFloat(UlMgzGripOnUpZPosEdit->Text);
        sys.ul.posGripOnOut.y                   = StrToFloat(UlMgzGripOnOutYPosEdit->Text);
        sys.ul.posGripOnOut.z                   = StrToFloat(UlMgzGripOnOutZPosEdit->Text);
        //Unloading Position
        sys.ul.posGripOffPre.y                  = StrToFloat(UlMgzGripOffPreYPosEdit->Text);
        sys.ul.posGripOffPre.z                  = StrToFloat(UlMgzGripOffPreZPosEdit->Text);
        sys.ul.posGripOffCvy.y                  = StrToFloat(UlMgzGripOffCvyYPosEdit->Text);
        sys.ul.posGripOffCvy.z                  = StrToFloat(UlMgzGripOffCvyZPosEdit->Text);
        sys.ul.posGripOff.y                     = StrToFloat(UlMgzGripOffYPosEdit->Text);
        sys.ul.posGripOff.z                     = StrToFloat(UlMgzGripOffZPosEdit->Text);
        sys.ul.posGripOffDn.y                   = StrToFloat(UlMgzGripOffDnYPosEdit->Text);
        sys.ul.posGripOffDn.z                   = StrToFloat(UlMgzGripOffDnZPosEdit->Text);
        sys.ul.posGripOffOut.y                  = StrToFloat(UlMgzGripOffOutYPosEdit->Text);
        sys.ul.posGripOffOut.z                  = StrToFloat(UlMgzGripOffOutZPosEdit->Text);
        sys.ul.posGripOnUp.y                    = sys.ul.posGripOnCvy.y;
        sys.ul.posGripOnCvy.z                   = sys.ul.posGripOnPre.z;
        sys.ul.posGripOnOut.y                   = sys.ul.posGripOnUp.y;
        sys.ul.posGripOffCvy.z                  = sys.ul.posGripOffPre.z;
        sys.ul.posGripOff.y                     = sys.ul.posGripOffCvy.y;
        sys.ul.posGripOffDn.y                   = sys.ul.posGripOff.y;
        sys.ul.posGripOffOut.y                  = 0.;
        sys.ul.posGripOffOut.z                  = sys.ul.posGripOffDn.z;
        sys.ul.nEmptyChkTime                    = UlMgzEmptyChkTimeSpinEdit->Value;
        sys.ul.nLdOutSensDly                    = UlMgzLdOutDlySpinEdit->Value;
    } else {
        //Vertical type unloder
        UlMgzSlotNumSpinEdit->Value             = sys.ul.nMgzSlotNum;
        UseRejMgzChkBox->Checked                = sys.ul.bUseRejMgz;
        RejMgzSelSpinEdit->Value                = sys.ul.nRejMgzSel;
        for(int i=0; i<MAX_MGZ; i++) {
            TComponent *ptr;
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"UseChkBox");
            if(ptr != NULL) ((TCheckBox*)ptr)->Checked = sys.ul.bUseMgz[i];
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"StartPosEdit");
            if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.ul.dMgzStartPos[i], 3);
            ptr = FindComponent("UlMgz"+IntToStr(i+1)+"EndPosEdit");
            if(ptr != NULL) ((TEdit*)ptr)->Text = Ext.FloatToStr(sys.ul.dMgzEndPos[i], 3);
        }
        //Horizontal type unloader
        sys.ul.posMgzEnd.y                      = sys.ul.posMgzStart.y;
        UlMgzStartYPosEdit->Text                = Ext.FloatToStr(sys.ul.posMgzStart.y);
        UlMgzStartZPosEdit->Text                = Ext.FloatToStr(sys.ul.posMgzStart.z);
        UlMgzEndZPosEdit->Text                  = Ext.FloatToStr(sys.ul.posMgzEnd.z);

        sys.ul.posGripOnUp.y                    = sys.ul.posGripOnCvy.y;
        sys.ul.posGripOnCvy.z                   = sys.ul.posGripOnPre.z;
        sys.ul.posGripOnOut.y                   = sys.ul.posGripOnUp.y;
        sys.ul.posGripOffCvy.z                  = sys.ul.posGripOffPre.z;
        sys.ul.posGripOff.y                     = sys.ul.posGripOffCvy.y;
        sys.ul.posGripOffDn.y                   = sys.ul.posGripOff.y;
        sys.ul.posGripOffOut.y                  = 0.;
        sys.ul.posGripOffOut.z                  = sys.ul.posGripOffDn.z;
        //Loading Position
        UlMgzGripOnPreYPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnPre.y);
        UlMgzGripOnPreZPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnPre.z);
        UlMgzGripOnCvyYPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnCvy.y);
        UlMgzGripOnCvyZPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnCvy.z);
        UlMgzGripOnUpYPosEdit->Text             = Ext.FloatToStr(sys.ul.posGripOnUp.y);
        UlMgzGripOnUpZPosEdit->Text             = Ext.FloatToStr(sys.ul.posGripOnUp.z);
        UlMgzGripOnOutYPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnOut.y);
        UlMgzGripOnOutZPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOnOut.z);
        //Unloading Position
        UlMgzGripOffPreYPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffPre.y);
        UlMgzGripOffPreZPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffPre.z);
        UlMgzGripOffCvyYPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffCvy.y);
        UlMgzGripOffCvyZPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffCvy.z);
        UlMgzGripOffYPosEdit->Text              = Ext.FloatToStr(sys.ul.posGripOff.y);
        UlMgzGripOffZPosEdit->Text              = Ext.FloatToStr(sys.ul.posGripOff.z);
        UlMgzGripOffDnYPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOffDn.y);
        UlMgzGripOffDnZPosEdit->Text            = Ext.FloatToStr(sys.ul.posGripOffDn.z);
        UlMgzGripOffOutYPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffOut.y);
        UlMgzGripOffOutZPosEdit->Text           = Ext.FloatToStr(sys.ul.posGripOffOut.z);
        UlMgzEmptyChkTimeSpinEdit->Value        = sys.ul.nEmptyChkTime;
        UlMgzLdOutDlySpinEdit->Value            = sys.ul.nLdOutSensDly;
    }
}






