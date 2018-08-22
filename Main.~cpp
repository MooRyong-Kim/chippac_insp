//---------------------------------------------------------------------------
#include <vcl.h>
//#include <algorithm.h>

#pragma hdrstop

#include "Main.h"
#include "WorkSetup.h"
#include "SysSetup.h"
#include "Init.h"
#include "Jog.h"
#include "Maint.h"
#include "Prepare.h"
#include "Splash.h"
#include "MotionBase.h"
#include "Msg.h"
#include "DataClass.h"
#include "InitProcess.h"
#include "WorkProcess.h"
#include "RunChk.h"
#include "MeasProcess.h"
#include "FileCtrl.hpp"
#include "Debug.h"
#include "Extern.h"
#include "IOPort.h"
#include "DataView.h"
#include "Password.h"
#include "SecsGem.h"
#include "ProtecDll.h"
#include <Math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzBorder"
#pragma link "RzTabs"
#pragma link "RzButton"
#pragma link "RzPanel"
#pragma link "LMDCustomScrollBox"
#pragma link "LMDListBox"
#pragma link "CPort"
#pragma link "ZipBuilder"
#pragma link "ZipBuilder"
#pragma resource "*.dfm"
TMainForm *MainForm;

AnsiString g_sInspResult;

// 0 : OK  1 : NG   9 : Chip_Undetected
int pResultCall(char* chInspResult, LPVOID pParam) {
    String mode = String(chInspResult).SubString(1,1);
    String result = "";
    if( mode == "B" ) {
        result = String(chInspResult).SubString(2, String(chInspResult).Length()-1);
    }
    else {
        result = mode;
    }
    g_sInspResult = result;
    return 1;
}
//    g_sInspResult = AnsiString(chInspResult).SubString(1,1);
//    return 1;
//}
void pMovingCall(double dXAxisValue, double dYAxisValue, LPVOID pParam)
{

}

bool TestRequestJobName1(LPVOID pParam)
{
    AnsiString str1 = Ext.GetFileName(run.chMdlFile);
#ifdef PROTECDLL
	_pvJobChange(0, str1.c_str());
#endif
	return true;
}
/*
EXPORT_API void _pvInitialize(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom); //비젼 창 초기화
EXPORT_API void _pvCloseVisionMainDlg(); //비젼 창 닫기
EXPORT_API void _pvMoveDlg(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom);//비젼 창 이동
EXPORT_API void	_pvShowMode(long nShowMode);
//#define SHOWMODE_SETUP		1
//#define SHOWMODE_RUN		2
//#define SHOWMODE_CALTEACH	3
EXPORT_API void	_pvAllWindowHide();//비젼 창 감춤
EXPORT_API void _pvSignal_Reset();//운영 도중 중단 했을 때 검사 리셋
EXPORT_API bool _pvJobChange(int nCamIndex, char *chJobName);//Job 체인지
EXPORT_API void _pvInspChange(int nCamIndex, int nInspIndex, int nInspMode);//Inspecion 모드 변경 - Dispenser Inspection에서는 의미 없음
EXPORT_API void _pvMachineState(bool bIsRun);//상태확인
EXPORT_API void _pvSetCalibration(int nCamIndex, double dRealDistanceX, double dRealDistanceY);//좌표 캘리브레이션
EXPORT_API void _pvSetCallResult(int nCamIndex, int(*pResultCall)(char *chInspResult, LPVOID pParam), LPVOID pWnd);//검사 결과 호출
EXPORT_API void _pvSetCallGrabEnd(int nCamIndex, int(*pGrabEndCall)(LPVOID pParam), LPVOID pWnd);//Grab End 호출
EXPORT_API void _pvSetCallMotionMoving(int nCamIndex, void(*pMotionMovingCall)(double dXAxisValue, double dYAxisValue, LPVOID pParam), LPVOID pWnd);//모션이동
EXPORT_API void _pvSetCallLightOn(int nCamIndex, void(*pLightOnCall)(int nLightChannel, int nOn, LPVOID pParam), LPVOID pWnd);//라이트 온,오프
EXPORT_API void _pvSetCallLightValue(int nCamIndex, void(*pLightValueCall)(int nLightChannel, int nValue, LPVOID pParam), LPVOID pWnd);//라이트 밸류셋팅
EXPORT_API void _pvSetCallRequestJobName(int nCamIndex, bool(*pRequestJobNameCall)(LPVOID pParam), LPVOID pWnd);//Job 이름 요청
EXPORT_API void _pvSWTrigger(int nCamIndex);//S/W트리거 사용
*/
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    m_pProcessThread = new TProcessThread(true);
    m_pProcessThread->Priority = tpIdle;
    m_pProcessThread->FreeOnTerminate = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    ForceDirectories(MAIN_PATH);
    ForceDirectories(SYS_FILE_PATH);
    ForceDirectories(MODEL_FILE_PATH);
    ForceDirectories(SYSLOG_FILE_PATH);
    ForceDirectories(BACKUP_PATH);

    this->DoubleBuffered = true;
    Application->OnHint = ShowHint;
    Application->OnMessage = AppMessage;

    MainPageCtrl->ActivePageIndex = 0;
    RunModeCmbBox->ItemIndex = 0;
    LogPageCtrl->ActivePageIndex = 0;
    LdUlSelCmbBox->ItemIndex = 0;

    MainPanel->Visible = false;
    MainPanel->Align = alClient;
    ProductPanel->Visible = true;
    ProductPanel->Align = alClient;

    LotStartTimeLbl->Caption = "";
    WorkStartTimeLbl->Caption = "";

    Data.LoadConfigData();

    if(sys.fac.bEnglishVersion)
        Ext.LoadLangFile(sys.fac.nEquipType == HTYPE_1RAIL?"ZeusInspS_Eng.txt":"ZeusInspD_Eng.txt");
    else Ext.LoadLangFile(sys.fac.nEquipType == HTYPE_1RAIL?"ZeusInspS_Msg.txt":"ZeusInspD_Msg.txt");

    if(FileExists(ExtractFilePath(Application->ExeName)+"Memo.txt"))
        CommonMemo->Lines->LoadFromFile(ExtractFilePath(Application->ExeName)+"Memo.txt");

    LdUlSelCmbBox->Clear();
    if(sys.fac.nEquipType == HTYPE_1RAIL) {
        LdUlSelCmbBox->Items->Add("UNLOADER");
        LdUlSelCmbBox->Items->Add("INSPECTION");
    } else {
        LdUlSelCmbBox->Items->Add("FRONT");
        LdUlSelCmbBox->Items->Add("REAR");
    }

    if(sys.fac.nEquipType == HTYPE_1RAIL)
        LMDPanelFill1->Caption = " SINGLE LANE U/F INSPECTION";
    else LMDPanelFill1->Caption = " DUAL LANE U/F INSPECTION";

    IO.ReadAndDecodeFromIOFile();
    IO.ReadAndDecodeFromIOFile();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    if(sys.fac.bNoMachine || true) {
        this->Align = alNone;
        this->Left = 0;
        this->Top = 0;
//        this->Width = 1024;
//        this->Height = 768;
        //if(sys.fac.bNoMachine)
        //    goto FUNCTION_END;
    } else {
        this->Align = alClient;
    }

    Ext.SysLogAdd("System Power On.");

    bool bIOBoardOK, bMotionBoardOk;

    INITIO:
    SplashForm->InitStatus("Initialize I/O Board.");
    if((bIOBoardOK = IO.InitIOBoard()) == false) {
        int nRtn = MsgDlg->ShowBox("I/O Board Init Error.",MMB_ABORTRETRYIGNORE|MMI_INFO,0,STR_MSG);
        if(nRtn == MID_ABORT) {
            Close();
            return;
        }
        else if(nRtn == MID_RETRY)
            goto INITIO;
    }

    //Motion Board Initialize...
    INITMB:
    SplashForm->InitStatus("Initialize Motion Board.");
    if((bMotionBoardOk = MB.InitMotionBoard()) == false) {
        int nRtn = MsgDlg->ShowBox("Motion Board Init Error.",MMB_ABORTRETRYIGNORE|MMI_INFO,0,STR_MSG);
        if(nRtn == MID_ABORT) {
            Close();
            return;
        }
        else if(nRtn == MID_RETRY)
            goto INITMB;
    } else {
        for(int ax=0; ax<AXES; ax++) {
            if(MB.IsServoOn(ax))
                MB.ServoPower(ax, OFF);
        }
    }
    if(!bIOBoardOK || !bMotionBoardOk)
        sys.fac.bNoMachine = true;
    if(sys.fac.bNoMachine && bMotionBoardOk)
        sys.fac.bDebugMode = true;

    if(sys.fac.bNoMachine) {
        Init.m_bDone = true;
        this->Align = alNone;
        goto FUNCTION_END;
    }
    // 조이스틱 연결여부 확인
    if(joyGetNumDevs())
        joySetCapture(Handle, JOYSTICKID1, 1, true);
    else MsgDlg->ShowBox("Joystick Not Exist.");
    //Picker1&2 Top Load Cell Com Port Open 하기

    FUNCTION_END:

    IO.SetTowerLamp(TWR_IDLE);

    Data.LoadRunData();
    Data.LoadModelData(run.chMdlFile, false);

    //2016.02.15 12:31:27 chcho
    if( sys.eng.UseNetworkFrontDisp ) {
        SockDispenser->Active = true;
    }
    else {
        SockDispenser->Active = false;
    }


    TickTimer->Enabled = true;
    ProcessTimer->Enabled = true;
    m_pProcessThread->Resume();

    Process1000msec();// for Form setting
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if(!sys.fac.bNoMachine) {
        for(int i=0; i<AXES; i++) {
            if(Init.m_bDone && (!MB.AxisDone(i) || Work.pNo.nStop != 0)) {
                Action = caNone;
                return;
            }
        }
    }

    if(TickTimer->Enabled) {
        if(MsgDlg->ShowBox("Do you quit the program?",MMB_YESNO|MMI_WARNING,0,STR_MSG) == MID_NO) {
            Action = caNone;
            return;
        }
    }

    MsgDlg->ShowBox("Doing Vision Release...",MMB_WAITTIME|MMI_TIMER,0,STR_MSG);
    #ifdef PROTECDLL
        try {
            //_pvCloseVisionMainDlg();
        } catch(...) {}
    #endif
    MsgDlg->Close();


    m_pProcessThread->Terminate();
    //m_pProcessThread->WaitFor();
    TickTimer->Enabled = false;
    ProcessTimer->Enabled = false;
    Data.SaveRunData();

    Ext.SysLogAdd("System Power Off.");

    Ext.ValidDayFileClean(SYSLOG_FILE_PATH, sys.eng.nFileValidDay);

    CommonMemo->Lines->SaveToFile(ExtractFilePath(Application->ExeName)+"Memo.txt");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
    if(m_bDebugFinish) {
        SourceMakeToZip();
        DWORD ProcessId = Ext.FindProcessPid("bcb.exe");
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
        clock_t tWait = clock();
        while(hProcess) {
            TerminateProcess(hProcess,0);//또는 ExitProcess 사용해서 죽임..
            if(Ext.CheckDelay(tWait, 1500))
                break;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ProcessTimerTimer(TObject *Sender)
{
    Chk.AutoRunSafety();
    Chk.MachineBtnProcess();
    //2016.10.14 chcho
//    Work.MainProcess(false);
    Meas.MainProcess();
    Init.MainProcess();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TickTimerTimer(TObject *Sender)
{
    static bool bInitVsn;
    if(!bInitVsn) {
        bInitVsn = true;
#ifdef PROTECDLL
        SplashForm->InitStatus("Initialize Vision Library.");
     try {
        _pvInitialize(0, 0, TabSheet2->Width, TabSheet2->Height);
        _pvSetCallRequestJobName(0, TestRequestJobName1, this);
        _pvMoveDlg(0, 100, 800, 600+100);
        _pvShowMode(SHOWMODE_RUN);
        m_bInitVision = true;
        _pvSetCallResult(0, pResultCall, this);
        _pvJobChange(0, Ext.GetFileName(run.chMdlFile).c_str());
        //_pvShowMode(SHOWMODE_RUN);
        //_pvInspChange(0,0,1);
        //_pvShowMode(SHOWMODE_RUN);
         _pvAllWindowHide();
         _pvSetCallMotionMoving(0, pMovingCall, this);
        // _pvSetCallResult(0, pResultCall, this);
        //_pvJobChange(0, Ext.GetFileName(run.chMdlFile).c_str());
        // _pvShowMode(SHOWMODE_RUN);
     } catch(...) {}
        SplashForm->InitStatus("Application Initialize End.");
        SplashForm->Release();
#endif
    }

    Process1msec();
    static clock_t t100 = clock();
    if(Ext.CheckDelay(t100, 100)) {
        Process100msec();
        t100 = clock();
    }
    static clock_t t1000 = clock();
    if(Ext.CheckDelay(t1000, 1000)) {
        Process1000msec();
        t1000 = clock();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Process1msec()
{
    if(sys.fac.bNoMachine) return;

    if(IO.In(srvpwr) && !IO.GetOut(SRVPWR)) {
        Sleep(1500);
        IO.On(SRVPWR);
    }

    if(!Chk.m_bMainErrEvent) {
        static bool bEmgLvl = true;
        if(IO.In(emgsw) && bEmgLvl) {
            Init.m_bDone = false;
            int nRet = MsgDlg->ShowBox("Main Emergency Switch Pressed.", MMB_RETRYCANCEL|MMI_WARNING);
            if(nRet == MID_CANCEL)
                bEmgLvl = false;
        }
        else if(!IO.In(emgsw)) bEmgLvl = true;

        static bool bUlEmgLvl = true;
        if(IO.In(ulemgsw) && bUlEmgLvl) {
            Init.m_bDone = false;
            int nRet = MsgDlg->ShowBox("Unloader Emergency Switch Pressed.", MMB_RETRYCANCEL|MMI_WARNING);
            if(nRet == MID_CANCEL)
                bUlEmgLvl = false;
        }
        else if(!IO.In(ulemgsw)) bUlEmgLvl = true;

        static bool bAirLvl = true;
        if(!IO.In(mainairgood) && bAirLvl) {
            int nRet = MsgDlg->ShowBox("Main Air Low.", MMB_RETRYCANCEL|MMI_WARNING);
            if(nRet == MID_CANCEL)
                bAirLvl = false;
        }
        else if(IO.In(mainairgood)) bAirLvl = true;

        LOOP:
        static bool bSrvPwrLvl = true;
        if(!IO.In(srvpwr) && bSrvPwrLvl) {
            bSrvPwrLvl = false;
            clock_t tSrvPwr = clock();
            while(true) {
                if(IO.In(srvpwr)) goto LOOP;
                if(Ext.CheckDelay(tSrvPwr, 30)) break;
            }
            Init.m_bDone = false;
            for(int ax=0; ax<AXES; ax++)
                MB.ServoPower(ax, OFF);
            int nRet = MsgDlg->ShowBox("Servo Power Switch Off.", MMB_RETRYCANCEL|MMI_WARNING);
            if(nRet == MID_RETRY)
                bSrvPwrLvl = true;
        }
        else if(IO.In(srvpwr)) bSrvPwrLvl = true;
    }

    if(MaintForm->Visible) return;

    IO.On(MAINAIR);
    IO.On(SRVPWR);

    if(Work.m_nStatus == RSTOP) {
        (IO.In(lightsw))?IO.On(LIGHTSWLAMP):IO.Off(LIGHTSWLAMP);
        (IO.In(htrsw))?IO.On(WRKBLKHTR):IO.Off(WRKBLKHTR);
    } else {
        IO.Off(LIGHTSWLAMP);
    }

    IO.TowerLampProcess();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Process100msec()
{
    PrepareBtn->Enabled = (Work.m_nStatus == RSTOP && Work.pNo.nStop == 0);
    WorkSetupBtn->Enabled = (Work.m_nStatus == RSTOP && Work.pNo.nStop == 0);
    SysSetupBtn->Enabled = (Work.m_nStatus == RSTOP && Work.pNo.nStop == 0);
    ManualBtn->Enabled = (Work.m_nStatus == RSTOP && Work.pNo.nStop == 0);
    InitBtn->Enabled = (Work.m_nStatus == RSTOP && Work.pNo.nStop == 0);
    JogBtn->Caption = (Work.m_nStatus==RSTOP?"JOG":"POS'");
    SysLogListBox->Enabled = (Work.m_nStatus == RSTOP);
    DispComLogListBox->Enabled = (Work.m_nStatus == RSTOP);
    CimLogListBox->Enabled = (Work.m_nStatus == RSTOP);
    SecsGemBtn->Enabled = sys.fac.bUseSecsGem;
    LoadingBtn->Enabled = (Work.m_nStatus == RSTOP);
    UnloadingBtn->Enabled = (Work.m_nStatus == RSTOP);
    InspLoadingBtn->Enabled = (Work.m_nStatus == RSTOP);
    InspUnloadingBtn->Enabled = (Work.m_nStatus == RSTOP);
    DebugPanel->Visible = sys.fac.bDebugMode;

    run.dUlZPos = MB.GetPos(UZ);

    if(AnsiString(run.chMdlFile).IsEmpty() || !FileExists(run.chMdlFile)) {
        strcpy(run.chMdlFile, "");
        ModelNamePanel->Caption = "";
    }
    else ModelNamePanel->Caption = Ext.GetFileName(run.chMdlFile);
    KeyBoardStatus();
    StatusBar->Panels->Items[3]->Text = DateTimeToStr(Now());
    StatusBar->Panels->Items[4]->Text = "Boat Flow: Left To Right";

    OperNameLbl->Caption = PrepareForm->OperNameEdit->Text;
    LotNumLbl->Caption = PrepareForm->LotNumEdit->Text;

    if(SecsGemForm->m_nHostConnected) {
        if(SecsGemForm->AllowRemoteBtn->Down)
            SecsGemBtn->Color = clLime;
        else SecsGemBtn->Color = clAqua;
    }
    else SecsGemBtn->Color = clBtnFace;

    Ext.RefreshSysRunData();

    if(!Chk.m_bMainErrEvent)
        ResetPanel->Color = clOlive;

    UnitStatusDraw();        
    MgzStatusDraw();

    if(Work.m_nStatus == RSTOP) {
        StartPanel->BevelOuter = Controls::bvRaised;
        StopPanel->BevelOuter = Controls::bvLowered;
        EmptyStopPanel->BevelOuter = Controls::bvRaised;

        StartPanel->Color = clGreen;
        EmptyStopPanel->Color = clNavy;
        StopPanel->Color = clRed;
        ExitBtn->Enabled = true;
    } else {
        StartPanel->BevelOuter = Controls::bvLowered;
        StopPanel->BevelOuter = Controls::bvRaised;
        if(Work.m_nStatus == RSTART) {
            EmptyStopPanel->Color = clNavy;
            EmptyStopPanel->BevelOuter = Controls::bvRaised;
            IO.Off(STOPLAMP);
        }
        else EmptyStopPanel->BevelOuter = Controls::bvLowered;
        StopPanel->Color = clMaroon;
        ExitBtn->Enabled = false;

        WorkPgsTimeLed->Caption = Ext.SecToStr(Ext.GetLapSec(Work.m_dtStartTime),4);

        if(!Work.m_bUPHStartTimeReset) {
            static clock_t tUPHRefresh;
            if(Ext.CheckDelay(tUPHRefresh, 45000)) {
                int nLapSec = Ext.GetLapSec(Work.m_dtUPHStartTime);
                if(nLapSec > 1 && Work.m_nUphUnitCnt > 1)
                    UphLed->Caption = UphLed->Caption.sprintf("%04d", Work.m_nUphUnitCnt*(3600./(nLapSec%3600)));
                tUPHRefresh = clock();
            }                                                                                   
        }
    }

    if(!LotStartTimeLbl->Caption.IsEmpty())
        LotPgsTimeLed->Caption = Ext.SecToStr(Ext.GetLapSec(StrToDateTime(LotStartTimeLbl->Caption)),4);

    RunModeCmbBox->Enabled = (Work.m_nStatus == RSTOP);
    Work.m_nRunMode = RunModeCmbBox->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Process1000msec()
{
    static clock_t t3000ms = clock();
    if(Ext.CheckDelay(t3000ms, 3000)) {
        Data.SaveRunData();
        t3000ms = clock();
    }

    if(Chk.m_bMainErrEvent) {
        if(ResetPanel->Color == clOlive)
            ResetPanel->Color = clYellow;
        else ResetPanel->Color = clOlive;
    }

    if(Work.m_nStatus == RSTART || Work.m_nStatus == CYC_STOP) {
        if(StartPanel->Color == clLime)
            StartPanel->Color = clGreen;
        else StartPanel->Color = clLime;

        if(Work.m_nStatus == CYC_STOP) {
            if(EmptyStopPanel->Color == clBlue)
                EmptyStopPanel->Color = clNavy;
            else EmptyStopPanel->Color = clBlue;
        }
    }

    DispComLogListBox->Font->Size = (DispComLogListBox->Height<200?8:10);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MgzStatusDraw(TPoint ptMouse)
{
    TPaintBox *pPntBox = MgzDrawBox;
    int nCrntSlot, nSelSlot = -1;
    TSize szMgz, szSlot;
    int nAxis = (sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL);

    Graphics::TBitmap *pBmpBox = new Graphics::TBitmap();
    pBmpBox->Width = pPntBox->Width;
    pBmpBox->Height = pPntBox->Height;

    TRect rtCanvas;
    rtCanvas = TRect(0, 0, pPntBox->Width, pPntBox->Height);
    pBmpBox->Canvas->Brush->Color = clBlack;
    pBmpBox->Canvas->FillRect(rtCanvas);

    nCrntSlot = MB.GetCrntSlotNum(nAxis);

    if(!MB.AxisDone(UY) || !MB.AxisDone(sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL) || nCrntSlot < 0 || mdl.ul.nMgzSlotNum < 1)
        goto DRAWBOX;

if(sys.fac.nEquipType == HTYPE_1RAIL) {
    szSlot.cx = pPntBox->Width;
    szSlot.cy = pPntBox->Height/double(mdl.ul.nMgzSlotNum);

    if(mdl.ul.posMgzStart.z > mdl.ul.posMgzEnd.z) {
        for(int s=mdl.ul.nMgzSlotNum-1; s>=0; s--) {
            TRect rtUnit = TRect(1, pPntBox->Height-((s+1)*szSlot.cy)+1, szSlot.cx-1, pPntBox->Height-((s+1)*szSlot.cy)+(szSlot.cy-1));
            pBmpBox->Canvas->Brush->Color = (Work.m_bUlEmptySlot[s]?clWhite:clLime);
            pBmpBox->Canvas->FillRect(rtUnit);
            pBmpBox->Canvas->Font->Color = clBlack;
            pBmpBox->Canvas->Font->Name = "Tahoma";
            pBmpBox->Canvas->Font->Size = 6;
            pBmpBox->Canvas->TextOut(rtUnit.Left+2, rtUnit.Top, IntToStr(s+1));
            if(ptMouse.x != -1 && ptMouse.y != -1 && PtInRect(&rtUnit, TPoint(ptMouse.x, ptMouse.y))) {
                nSelSlot = s;
            }
        }
    } else {
        for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
            TRect rtUnit = TRect(1, (s*szSlot.cy)+1, szSlot.cx-1, (s*szSlot.cy)+(szSlot.cy-1));
            pBmpBox->Canvas->Brush->Color = (Work.m_bUlEmptySlot[s]?clWhite:clLime);
            pBmpBox->Canvas->FillRect(rtUnit);
            pBmpBox->Canvas->Font->Color = clBlack;
            pBmpBox->Canvas->Font->Name = "Tahoma";
            pBmpBox->Canvas->Font->Size = 6;
            pBmpBox->Canvas->TextOut(rtUnit.Left+2, rtUnit.Top, IntToStr(s+1));
            if(ptMouse.x != -1 && ptMouse.y != -1 && PtInRect(&rtUnit, TPoint(ptMouse.x, ptMouse.y))) {
                nSelSlot = s;
            }
        }
    }
} else {
        int nMaxMgz = 0;
        for(int m=0; m<MAX_MGZ; m++) {
            if(mdl.ul.bUseMgz[m])
                nMaxMgz++;
        }
        szMgz.cx = pPntBox->Width/(nMaxMgz==0?3:nMaxMgz);
        szMgz.cy = pPntBox->Height/double(mdl.ul.nMgzSlotNum==0?1:mdl.ul.nMgzSlotNum);

        int nStep = 0;
        for(int m=0; m<nMaxMgz ; m++) {
            if(mdl.ul.dMgzStartPos[m]<mdl.ul.dMgzEndPos[m]) {
                for(int s=mdl.ul.nMgzSlotNum-1; s>=0; s--) {
                    TRect rtUnit = TRect((m*szMgz.cx)+1, pPntBox->Height-((s+1)*szMgz.cy)+1, (m*szMgz.cx)+(szMgz.cx-1), pPntBox->Height-((s+1)*szMgz.cy)+(szMgz.cy-1));
                    if(!mdl.ul.bUseMgz[m])
                        pBmpBox->Canvas->Brush->Color = clBlack;
                    else if(Work.m_bUlEmptySlot[(m*mdl.ul.nMgzSlotNum)+s])
                        pBmpBox->Canvas->Brush->Color = clWhite;
                    else {
                        pBmpBox->Canvas->Brush->Color = clLime;
                        for(int i=0; i<mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt; i++) {
                            if(Work.rltMem.bMgzRejUnit[m][s][i]) {
                                pBmpBox->Canvas->Brush->Color = clRed;
                                break;
                            }
                        }
                        if(ptMouse.x != -1 && ptMouse.y != -1 && PtInRect(&rtUnit, TPoint(ptMouse.x, ptMouse.y)))
                            m_nDataViewSelMgz = m, m_nDataViewSelStep = s;
                    }
                    pBmpBox->Canvas->FillRect(rtUnit);
                    pBmpBox->Canvas->Font->Color = clBlack;
                    pBmpBox->Canvas->Font->Name = "Tahoma";
                    pBmpBox->Canvas->Font->Size = 6;
                    nStep++;
                }
            } else {
                for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                    TRect rtUnit = TRect((m*szMgz.cx)+1, (s*szMgz.cy)+1, (m*szMgz.cx)+(szMgz.cx-1), (s*szMgz.cy)+(szMgz.cy-1));
                    if(!mdl.ul.bUseMgz[m])
                        pBmpBox->Canvas->Brush->Color = clBlack;
                    else if(Work.m_bUlEmptySlot[nStep])
                        pBmpBox->Canvas->Brush->Color = clWhite;
                    else {
                        pBmpBox->Canvas->Brush->Color = clLime;
                        for(int i=0; i<mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt; i++) {
                            if(Work.rltMem.bMgzRejUnit[m][s][i]) {
                                pBmpBox->Canvas->Brush->Color = clRed;
                                break;
                            }
                        }
                        if(ptMouse.x != -1 && ptMouse.y != -1 && PtInRect(&rtUnit, TPoint(ptMouse.x, ptMouse.y)))
                            m_nDataViewSelMgz = m, m_nDataViewSelStep = s;
                    }
                    pBmpBox->Canvas->FillRect(rtUnit);
                    pBmpBox->Canvas->Font->Color = clBlack;
                    pBmpBox->Canvas->Font->Name = "Tahoma";
                    pBmpBox->Canvas->Font->Size = 6;
                    nStep++;
                }
            }
        }

}

    if(nSelSlot != -1) {
        for(int s=0; s<=nSelSlot; s++) {
            Work.m_bUlEmptySlot[s] = !Work.m_bUlEmptySlot[s];
        }
    }

    DRAWBOX:

    pPntBox->Canvas->Draw(0,0,pBmpBox);
    delete pBmpBox;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RunModeCmbBoxChange(TObject *Sender)
{
    if(RunModeCmbBox->ItemIndex != RUN_REAL) {
        int nRtn = PasswordForm->PasswordCheck(10);
        if(nRtn == PSWD_MISS || nRtn == PSWD_CANCEL) {
            if(nRtn == PSWD_MISS)
                MsgDlg->ShowBox("Invalid Password.");
            RunModeCmbBox->ItemIndex = RUN_REAL;
            return;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MainBtnClick(TObject *Sender)
{
    TRzBitBtn *p = dynamic_cast<TRzBitBtn*>(Sender);

    if(p == PrepareBtn) {
        if(!PrepareForm->Visible)
            MB.InitCheck();

        bool bVisible = PrepareForm->Visible;

        RECT rectFrom;
	    ::GetWindowRect(PrepareForm->Handle, &rectFrom);
        TPoint pt = TPoint(0,0);
        pt = ScreenToClient(PrepareBtn->ClientToScreen(pt));
	    RECT rectTo = {pt.x, pt.y, pt.x+PrepareBtn->Width, pt.y+PrepareBtn->Height};
        if(bVisible) Ext.DrawWireRects(&rectFrom, &rectTo);
        else         Ext.DrawWireRects(&rectTo, &rectFrom);

        PrepareForm->Visible = !bVisible;
    }
    else if(p == WorkSetupBtn) {
        if(SysSetupForm->Visible)
            SysSetupForm->Close();

        if(!WorkSetupForm->Visible) {
            if(!Init.m_bDone) {
                if(InitForm->Visible) return;
                int nRtn = MsgDlg->ShowBox("System Init Start?", MMB_YESNOCANCEL|MMI_HELP, 0, STR_MSG);
                if(nRtn == MID_YES) {
                    Init.m_bAuto = true;
                    InitForm->ShowModal();
                    if(!Init.m_bDone) return;
                }
                else if(nRtn == MID_CANCEL)
                    return;
            }
            if(sys.fac.bSetupBtnPswd) {
                int nRtn = PasswordForm->PasswordCheck(10);
                if(sys.fac.bDebugMode || nRtn == PSWD_ENG_MATCH) {
                    ProductPanel->Visible = false;
                    MainPanel->Visible = true;
                    WorkSetupForm->ManualDock(MainPanel,NULL,alClient);
                    WorkSetupForm->Show();
                }
                else MsgDlg->ShowBox("Invalid Password.");
            } else {
                ProductPanel->Visible = false;
                MainPanel->Visible = true;
                WorkSetupForm->ManualDock(MainPanel,NULL,alClient);
                WorkSetupForm->Show();
            }
        } else {
            WorkSetupForm->Close();
            MainPanel->Visible = false;
            ProductPanel->Visible = true;
        }
    }
    else if(p == SysSetupBtn) {
        if(WorkSetupForm->Visible)
            WorkSetupForm->Close();

        if(!SysSetupForm->Visible) {
            if(!Init.m_bDone) {
                if(InitForm->Visible) return;
                int nRtn = MsgDlg->ShowBox("System Init Start?", MMB_YESNOCANCEL|MMI_HELP, 0, STR_MSG);
                if(nRtn == MID_YES) {
                    Init.m_bAuto = true;
                    InitForm->ShowModal();
                    if(!Init.m_bDone) return;
                }
                else if(nRtn == MID_CANCEL)
                    return;
            }
            ProductPanel->Visible = false;
            MainPanel->Visible = true;
            SysSetupForm->ManualDock(MainPanel,NULL,alClient);
            SysSetupForm->Show();
        } else {
            SysSetupForm->Close();
            MainPanel->Visible = false;
            ProductPanel->Visible = true;
        }
    }
    else if(p == ManualBtn) {
        if(WorkSetupForm->Visible && MaintForm->Visible)
            return;
        if(MaintForm->Visible) {
            MaintForm->Close();
        } else {
            MaintForm->ManualFloat(MaintForm->m_rtForm);
            MaintForm->Show();
        }
        return;
        if(MaintForm->Visible) {
            MaintForm->ManualFloat(MaintForm->m_rtForm);
            if(MaintForm->WindowState == wsMinimized)
                MaintForm->WindowState = wsNormal;
            //else MaintForm->Close();
        }
        else MaintForm->Show();
    }
    else if(p == InitBtn) {
        if(!InitForm->Visible)
            InitForm->ShowModal();

        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.Off(DOORLOCK);
            Sleep(100);
        }

    }
    else if(p == JogBtn) {
        if(!JogForm->Visible)
            JogForm->Show();
        else {
            JogForm->Focused();
            JogForm->BringToFront();
        }
    }
    else if(p == ExitBtn) {
        this->Close();
    }
    else if((TLMDButton*)p == SecsGemBtn) {
//        SecsGemForm->Visible = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PanelClick(TObject *Sender)
{
    TPanel *p = dynamic_cast<TPanel *>(Sender);

    if(p == StartPanel) {
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.On(DOORLOCK);
            Sleep(100);
        }
        if(Chk.m_bMainErrEvent || MsgDlg->Visible || DataViewForm->Visible || MaintForm->Visible ||
            PrepareForm->Visible || WorkSetupForm->Visible || SysSetupForm->Visible) {
            if(MaintForm->Visible)
                MaintForm->WindowState = wsNormal;
            return;
        }

        //2016.06.14 15:05:39 chcho
        if((sys.eng.bFrntDoorSafety || sys.fac.bAlwaysSafetyOn) && !IO.In(fdoorclose)) {
            sys.eng.bSafetySrvOff?IO.Off(SRVENA):IO.On(SRVENA);
            MsgDlg->ShowBox("Front Door Open Error.");
            return;
        }
        if((sys.eng.bUlBarSafety || sys.fac.bAlwaysSafetyOn) && (IO.In(ulbarsafety1) || IO.In(ulbarsafety2))) {
            sys.eng.bSafetySrvOff?IO.Off(SRVENA):IO.On(SRVENA);
            MsgDlg->ShowBox("Unloader Side Door/Sensor Open Error.");
            return;
        }


        if(AnsiString(run.chMdlFile).IsEmpty() || !Init.m_bDone || Chk.m_bMainErrEvent) {
            if(AnsiString(run.chMdlFile).IsEmpty())
                MsgDlg->ShowBox("Model File Not Load.");
            else if(!Init.m_bDone) {
                if(InitForm->Visible)            Init.Stop();
                else if(Work.m_nStatus != RSTOP) Work.Stop(TWR_IDLE);
                MsgDlg->ShowBox("Please, Machine Initializing.");
            }
            return;
        }

        if( sys.eng.UseHeaterAlarm ) {
            if( !IO.In(htrsw) ) {
                MsgDlg->ShowBox("Check Heater S/W.");
                return;
            }
        }

        if(Work.m_nStatus == RSTOP) {
            Work.pNo.nStart = 1;
            Work.m_nStatus = RSTART;
            Work.m_dtStartTime = Now();
            WorkStartTimeLbl->Caption = DateTimeToStr(Work.m_dtStartTime);
            if(Work.m_nRunMode == RUN_REWORK) {
                memset(Work.unit, NULL, sizeof(Work.unit));
                for(int u=0; u<MAX_UNIT; u++) {
                    if(u < mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt) {
                        Work.unit[u].bInspSkip = !m_bSelUnit[u];
                    }
                }
            }
            run.bRearRailWork = RailTabCtrl->TabIndex;
        }
    }
    else if(p == StopPanel) {
        if(DataViewForm->Visible || MaintForm->Visible || PrepareForm->Visible ||
            WorkSetupForm->Visible || SysSetupForm->Visible) return;
        Work.Stop(TWR_STOP);
        //kjseo 2015.01.20
        _pvSignal_Reset(0);
        for(int i=0 ; i<MAX_UNIT ; i++)
        {
            Work.unit[i].bInspSkip = false;
            Work.unit[i].bInspDone = false;
            Work.unit[i].eInspErr = INSP_READY;
            Work.unit[i].bInspManChkDone = false;
            Work.unit[i].bInspGood = false;
        }
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.Off(DOORLOCK);
            Sleep(100);
        }
    }
    else if(p == EmptyStopPanel) {
        if(Work.m_nStatus == RSTART) {
            Work.m_nStatus = CYC_STOP;
            Work.pNo.nCycStop = 1;
        }
        else if(Work.m_nStatus == CYC_STOP) {
            Work.pNo.nCycStop = 0;
            Work.m_nStatus = RSTART;
        }
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.Off(DOORLOCK);
            Sleep(100);
        }
    }
    else if(p == ResetPanel) {
        Chk.m_bMainErrEvent = false;
        Work.isRecvWorkEnd = false;
    }

    /*else if(p == DispComLogPnl) {
        if(Panel10->Floating) {
            Panel10->Dock(Panel1, m_rtComLogPnl);
        } else {
            Panel10->ManualFloat(Panel1->BoundsRect);
        }
    }*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KeyBoardStatus()
{
    TKeyboardState KeyState;
    GetKeyboardState(KeyState);
    if(KeyState[VK_CAPITAL] & 0x01)
        StatusBar->Panels->Items[0]->Text = "Caps";
    else StatusBar->Panels->Items[0]->Text = "";

    if(KeyState[VK_NUMLOCK] & 0x01)
        StatusBar->Panels->Items[1]->Text = "Num";
    else StatusBar->Panels->Items[1]->Text = "";

    if(KeyState[VK_SCROLL] & 0x01)
        StatusBar->Panels->Items[2]->Text = "Scroll";
    else StatusBar->Panels->Items[2]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowHint(TObject *Sender)
{
    if(!Work.m_bProcessNumView)
        StatusBar->Panels->Items[5]->Text = Application->Hint;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendCommand(AnsiString sCmd)
{
    if(AnsiString(sys.fac.chUdpIp).IsEmpty() || !this->Visible)
        return;

try {
    DispUDP->RemoteHost = AnsiString(sys.fac.chUdpIp);
    DispUDP->RemotePort = sys.fac.nUdpPort;
} catch(...) {return;}

    Data.udp.sReply = "";

    strcpy(Data.udp.com.chLetter, sCmd.c_str());
    TMemoryStream *pStream = new TMemoryStream();
    pStream->WriteBuffer(&Data.udp.com.chLetter, sizeof(Data.udp.com.chLetter));
    DispUDP->SendStream(pStream);
    //DispUDP->SendBuffer(Data.udp.com.chLetter, sizeof(Data.udp.com.chLetter), sCmd.Length());
    delete pStream;

    DispComLogListBox->Items->Add("["+Ext.GetCrntTime()+"]Handler->Vision: "+ sCmd);

    if(DispComLogListBox->Items->Count >= 100)
        DispComLogListBox->Items->Delete(0);
    DispComLogListBox->ItemIndex = DispComLogListBox->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DispUDPDataReceived(TComponent *Sender,
      int NumberBytes, AnsiString FromIP, int Port)
{
    if(NumberBytes <= 0 || !this->Visible)
        return;

    TMemoryStream *pStream = new TMemoryStream();
    DispUDP->ReadStream(pStream);
    if(NumberBytes > sizeof(Data.udp.com))
        NumberBytes = sizeof(Data.udp.com);
    pStream->ReadBuffer(&Data.udp.com, NumberBytes);
    delete pStream;


    if(DispComLogListBox->Items->Count >= 100)
        DispComLogListBox->Items->Delete(0);
    DispComLogListBox->ItemIndex = DispComLogListBox->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetPanelMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ResetPanel->BevelOuter = Controls::bvLowered;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetPanelMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ResetPanel->BevelOuter = Controls::bvRaised;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CtrlPanelCanResize(TObject *Sender,
      int &NewWidth, int &NewHeight, bool &Resize)
{
//    ExitBtn->Top = CtrlPanel->Height-83;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AppMessage(tagMSG &Msg, bool &Handled)
{
    if(!ProcessTimer->Enabled) return;

    if(JogForm->Visible && JogForm->BottonPanel->Enabled) {
        if(Msg.message == WM_KEYDOWN)
            JogForm->ArrowKeyDown(Msg.wParam);
        else if(Msg.message == WM_KEYUP)
            JogForm->ArrowKeyUp(Msg.wParam);
        if(Msg.wParam == VK_UP || Msg.wParam == VK_DOWN
            || Msg.wParam == VK_LEFT || Msg.wParam == VK_RIGHT) {
            Msg.wParam = 0;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TempGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    TStringGrid *pGrid = dynamic_cast<TStringGrid*>(Sender);

    /*
    if(ACol > 0 && ARow > 0) {
        int nTemp = mdl.pcb.nHtrTemp[((ACol-1)*(MAX_HTR/2))+(ARow-1)];
        if(pGrid->Cells[ACol][ARow] != "ERROR" && pGrid->Cells[ACol][ARow] != "OFF" &&
            !pGrid->Cells[ACol][ARow].IsEmpty() && sys.opr.bTempErrChk) {
            double dData = pGrid->Cells[ACol][ARow].ToDouble();
            if(dData > nTemp+sys.opr.nTempAlarm)
                pGrid->Canvas->Brush->Color = clRed;
            else if(dData < nTemp-sys.opr.nTempAlarm)
                pGrid->Canvas->Brush->Color = clYellow;
            else pGrid->Canvas->Brush->Color = clLime;
        }
        else pGrid->Canvas->Brush->Color = clWhite;
        pGrid->Canvas->FillRect(Rect);
    } */

    unsigned oldalign = SetTextAlign(pGrid->Canvas->Handle, TA_CENTER|VTA_CENTER);
    pGrid->Canvas->TextRect(Rect, (Rect.Right+Rect.Left)/2,
        Rect.Top+3, pGrid->Cells[ACol][ARow]);
    SetTextAlign(pGrid->Canvas->Handle, oldalign);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SysLogListBoxDrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
    if(SysLogListBox->Items->Strings[Index].SubString(1,1) == "!")
        SysLogListBox->Canvas->Font->Color = clRed;
    SysLogListBox->Canvas->TextOut(Rect.Left, Rect.Top, SysLogListBox->Items->Strings[Index]);

    static int nMaxWidth = 0;
    nMaxWidth = max(SysLogListBox->Canvas->TextWidth(SysLogListBox->Items->Strings[Index]), nMaxWidth);
    SysLogListBox->Perform(LB_SETHORIZONTALEXTENT, nMaxWidth, 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SecsGemBtnClick(TObject *Sender)
{
    SecsGemForm->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DispComLogListBoxDblClick(TObject *Sender)
{
    DispComLogListBox->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatusBarDblClick(TObject *Sender)
{
    Work.m_bProcessNumView = !Work.m_bProcessNumView;
    if(!Work.m_bProcessNumView)
        StatusBar->Panels->Items[5]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LoadUnloadBtnClick(TObject *Sender)
{
    TSpeedButton *pBtn = dynamic_cast<TSpeedButton*>(Sender);

    if(MsgDlg->Visible) return;

    if( pBtn == InspLoadingBtn ) {
        Work.m_sManualCmd[FRNT] = "PCB_LOAD";

    }
    else if( pBtn == InspUnloadingBtn ) {
        IO.Off(CLAMPON);
        IO.Off(FINSPBLKVAC);
        Sleep(500);
        IO.Off(FINSPBLKUP);

    }
    else if( pBtn == LoadingBtn ) {
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.On(DOORLOCK);
            Sleep(100);
        }
        if(MB.InitCheck()) {
            Work.pNo.nUl = 1;
            if(MsgDlg->ShowBox("Unloader Magazine Loading Start.",
                MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
                Work.pNo.nUl = 0;
            }
        }
    }
    else if( pBtn == UnloadingBtn ) {
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.On(DOORLOCK);
            Sleep(100);
        }
        if(MB.InitCheck()) {
            Work.pNo.nUl = 105;
            if(MsgDlg->ShowBox("Unloader Magazine Unloading Start.",
                MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
                Work.pNo.nUl = 0;
            }
        }
    }

//    if(pBtn == LoadingBtn) {
//        if(LdUlSelCmbBox->Text == "UNLOADER") {
//            if(MB.InitCheck()) {
//                Work.pNo.nUl = 1;
//                if(MsgDlg->ShowBox("Unloader Magazine Loading Start.",
//                    MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
//                    Work.pNo.nUl = 0;
//                }
//            }
//        }
//        else if(LdUlSelCmbBox->Text == "INSPECTION") {
//            Work.m_sManualCmd[FRNT] = "PCB_LOAD";
//        }
//        else if(LdUlSelCmbBox->Text == "FRONT") {
//            Work.m_sManualCmd[FRNT] = "PCB_LOAD";
//        }
//        else if(LdUlSelCmbBox->Text == "REAR") {
//            Work.m_sManualCmd[REAR] = "PCB_LOAD";
//        }
//    }
//    else if(pBtn == UnloadingBtn) {
//        if(LdUlSelCmbBox->Text == "UNLOADER") {
//            if(MB.InitCheck()) {
//                Work.pNo.nUl = 105;
//                if(MsgDlg->ShowBox("Unloader Magazine Unloading Start.",
//                    MMB_CANCEL|MMI_INFO,0,STR_MSG) == MID_CANCEL || Chk.m_bMainErrEvent) {
//                    Work.pNo.nUl = 0;
//                }
//            }
//        }
//        else if(LdUlSelCmbBox->Text == "INSPECTION") {
//            /*
//            Work.m_sManualCmd = "PCB_UNLOAD";
//            if(MsgDlg->ShowBox("Manual PCB Unloading.", MMB_CANCEL|MMI_INFO) == MID_CANCEL)
//                Work.m_sManualCmd = "";
//            */
//            //if(IO.In(fcvyinspdct)) {
//                IO.Off(CLAMPON);
//                IO.Off(FINSPBLKVAC);
//                Sleep(500);
//                IO.Off(FINSPBLKUP);
//            //}
//        }
//        else if(LdUlSelCmbBox->Text == "FRONT") {
//            if(IO.In(fcvyinspdct)) {
//                IO.Off(FINSPBLKVAC);
//                Sleep(300);
//                IO.Off(FINSPBLKUP);
//            }
//        }
//        else if(LdUlSelCmbBox->Text == "REAR") {
//            if(IO.In(rcvyinspdct)) {
//                IO.Off(RINSPBLKVAC);
//                Sleep(300);
//                IO.Off(RINSPBLKUP);
//            }
//        }
//    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MgzDrawBoxMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TPaintBox *pBox = dynamic_cast<TPaintBox*>(Sender);

    m_ptMgzDrawBox = TPoint(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MgzDrawBoxDblClick(TObject *Sender)
{
    TPaintBox *pBox = dynamic_cast<TPaintBox*>(Sender);

    MgzStatusDraw(m_ptMgzDrawBox);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DebugBtnClick(TObject *Sender)
{
    DebugForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitStatusDraw(bool bSelect, TRect rtSelect, bool bMove)
{
    RailTabCtrl->Tabs->Items[1]->Visible = (!sys.fac.bNoUseRearRail && sys.fac.nEquipType!=HTYPE_1RAIL);

    if(Work.m_nStatus != RSTOP)
        RailTabCtrl->TabIndex = run.bRearRailWork;

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
    pPntBox->Visible = (IO.In(fcvyinspdct) || IO.In(rcvyinspdct) || RunModeCmbBox->ItemIndex == RUN_REWORK || sys.fac.bNoMachine);

    if(Work.m_nRunMode == RUN_BYPASS)
        UnitDrawBasePanel->Caption = "BY PASS";
    else UnitDrawBasePanel->Caption = "";

    if(!pPanel->Caption.IsEmpty())
        pPntBox->Visible = false;

    if(!pPntBox->Visible || !pPanel->Visible) return;

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
//    for(int m=(mdl.pcb.nCntDir?nX-1:0); (mdl.pcb.nCntDir?m>=0:m<nY); (mdl.pcb.nCntDir?m--:m++)) {
//        for(int n=(mdl.pcb.nCntDir?0:nX-1); (mdl.pcb.nCntDir?n<nY:n>=0); (mdl.pcb.nCntDir?n++:n--)) {
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
            pBmpBox->Canvas->Brush->Color = clGreen;
            pBmpBox->Canvas->FillRect(rtUnit);
            if(RunModeCmbBox->ItemIndex == RUN_REWORK && Work.m_nStatus == RSTOP) {
                if(bSelect) {
                    bool bBreak = false;
                    for(int x=rtSelect.Left; x<=rtSelect.Right; x++) {
                        for(int y=rtSelect.Top; y<=rtSelect.Bottom; y++) {
                            if(PtInRect(&rtUnit, TPoint(x,y))) {
                                m_bSelUnit[nCnt] = !m_bSelUnit[nCnt];
                                bBreak = true; break;
                            }
                        }
                        if(bBreak) break;
                    }
                }
                pBmpBox->Canvas->Brush->Color = (m_bSelUnit[nCnt]?clLime:clGreen);
                pBmpBox->Canvas->FillRect(rtUnit);
            } else {
                if(!Work.unit[nCnt].bInspSkip) {
                    if(Work.unit[nCnt].eInspErr == INSP_NG)
                        pBmpBox->Canvas->Brush->Color = clRed;
                    else if(Work.unit[nCnt].bInspGood)
                        pBmpBox->Canvas->Brush->Color = clLime;
                    else if(Work.unit[nCnt].bInspDone)
                        pBmpBox->Canvas->Brush->Color = clSilver;
                }
                else pBmpBox->Canvas->Brush->Color = clGray;
                pBmpBox->Canvas->FillRect(rtUnit);
            }

            pBmpBox->Canvas->Font->Color = clBlack;
            //pPntBox->Canvas->Font->Style = TFontStyles()<< fsBold;
            pBmpBox->Canvas->Font->Size = (nX*nY>9?6:7);
            pBmpBox->Canvas->Font->Name = "Tahoma";
            pBmpBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top, IntToStr(nCnt+1));
            /*Coord pos = MB.GetHeadPos(nPkr, PKR_FID1, nCnt);
            pPntBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top, Ext.FloatToStr(pos.x,1));
            pPntBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top+12, Ext.FloatToStr(pos.y,1));

            pos = MB.GetHeadPos(nPkr, PKR_FID2, nCnt);
            pPntBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top+24, Ext.FloatToStr(pos.x,1));
            pPntBox->Canvas->TextOut(rtUnit.Left, rtUnit.Top+36, Ext.FloatToStr(pos.y,1));

            pos = MB.GetHeadPos(nPkr, PKR_UNIT, nCnt);
            pPntBox->Canvas->TextOut(rtUnit.Left+25, rtUnit.Top+12, Ext.FloatToStr(pos.x,1));
            pPntBox->Canvas->TextOut(rtUnit.Left+25, rtUnit.Top+24, Ext.FloatToStr(pos.y,1));
            */

            if(bMove) {
                if(rtSelect.Left != 0 && rtSelect.Right != 0 &&
                    rtSelect.Top != 0 && rtSelect.Bottom != 0) {
                    TPoint ptClick = TPoint(rtSelect.Left, rtSelect.Top);
                    if(PtInRect(&rtUnit, ptClick)) {
                        nClickUnit = nCnt;
                    }
                }
            }

            nCnt++;
        }
    }

    pPntBox->Canvas->Draw(0,0,pBmpBox);
    delete pBmpBox;

    if(UnitDragShape->Visible) {
        UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
        UnitDragShape->Invalidate();
    }

    if(nClickUnit > -1) {
        Coord posMove = MB.GetUnitPos(RailTabCtrl->TabIndex, nClickUnit);
        MB.XYMoveTo(IX, posMove);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBoxMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button != mbLeft)
        return;

    m_tUnitClick = clock();

    m_rtUnitSel.Left = X+UnitDrawBox->Left;
    m_rtUnitSel.Top = Y+UnitDrawBox->Top;
    m_rtUnitSel.Right = X+UnitDrawBox->Left;
    m_rtUnitSel.Bottom = Y+UnitDrawBox->Top;

    if(RunModeCmbBox->ItemIndex != RUN_REWORK)
        return;

    UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
    UnitDragShape->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBoxMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(RunModeCmbBox->ItemIndex != RUN_REWORK || !Shift.Contains(ssLeft))
        return;

    m_rtUnitSel.Right = X+UnitDrawBox->Left;
    m_rtUnitSel.Bottom = Y+UnitDrawBox->Top;

    UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBoxMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button != mbLeft)
        return;

    TRect rtSave = m_rtUnitSel;
    if(m_rtUnitSel.Width()<0) {
        m_rtUnitSel.Left = m_rtUnitSel.Right;
        m_rtUnitSel.Right = rtSave.Left;
    }
    if(m_rtUnitSel.Height()<0) {
        m_rtUnitSel.Top = m_rtUnitSel.Bottom;
        m_rtUnitSel.Bottom = rtSave.Top;
    }

    m_rtUnitSel.Left-=UnitDrawBox->Left;
    m_rtUnitSel.Top-=UnitDrawBox->Top;
    m_rtUnitSel.Right-=UnitDrawBox->Left;
    m_rtUnitSel.Bottom-=UnitDrawBox->Top;

    if(RunModeCmbBox->ItemIndex != RUN_REWORK) {
        if(Ext.CheckDelay(m_tUnitClick, 1000))
            UnitStatusDraw(false, m_rtUnitSel, true);
        return;
    }

    UnitDragShape->Visible = false;
    UnitStatusDraw(true, m_rtUnitSel);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBasePanelMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(RunModeCmbBox->ItemIndex != RUN_REWORK || Button != mbLeft)
        return;

    m_rtUnitSel.Left = X+UnitDrawBox->Left;
    m_rtUnitSel.Top = Y+UnitDrawBox->Top;
    m_rtUnitSel.Right = X+UnitDrawBox->Left;
    m_rtUnitSel.Bottom = Y+UnitDrawBox->Top;

    UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
    UnitDragShape->Visible = true;

    m_tUnitClick = clock();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBasePanelMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(RunModeCmbBox->ItemIndex != RUN_REWORK || !Shift.Contains(ssLeft))
        return;

    m_rtUnitSel.Right = X+UnitDrawBox->Left;
    m_rtUnitSel.Bottom = Y+UnitDrawBox->Top;

    UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UnitDrawBasePanelMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(RunModeCmbBox->ItemIndex != RUN_REWORK || Button != mbLeft)
        return;

    m_rtUnitSel.Left = X+UnitDrawBox->Left;
    m_rtUnitSel.Top = Y+UnitDrawBox->Top;
    m_rtUnitSel.Right = X+UnitDrawBox->Left;
    m_rtUnitSel.Bottom = Y+UnitDrawBox->Top;

    UnitDragShape->SetBounds(m_rtUnitSel.Left, m_rtUnitSel.Top, m_rtUnitSel.Width(), m_rtUnitSel.Height());
    UnitDragShape->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DebugFormViewBtnClick(TObject *Sender)
{
    if(!DebugForm->Visible) {
        DebugForm->Align = alClient;
        DebugForm->ManualDock(UnitDrawBasePanel, DebugForm, alClient);
        DebugForm->Show();
        UnitDrawBox->Visible = false;
    } else {
        DebugForm->Close();
        UnitDrawBox->Visible = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MainPageCtrlChange(TObject *Sender)
{
#ifdef PROTECDLL
    if(!this->Visible) return;

try {
   // _pvShowMode(SHOWMODE_RUN);

    if(MainPageCtrl->ActivePageIndex == 1) {
        //_pvShowMode(SHOWMODE_RUN);
        TPoint pt;
        pt.x = TabSheet2->Left;
        pt.y = TabSheet2->Top;

        pt = TabSheet2->ClientToScreen(pt);
        pt.y-=25;
        _pvMoveDlg(pt.x, pt.y, pt.x+TabSheet2->Width, pt.y+TabSheet2->Height);
        _pvShowMode(SHOWMODE_RUN);
    }
    else _pvAllWindowHide();
} catch(...) {}
#endif
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
#ifdef PROTECDLL
try {
    _pvMoveDlg(0, 100, 800, 600+100);
    _pvShowMode(SHOWMODE_RUN);
} catch(...) {}
#endif
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
#ifdef PROTECDLL
try {
    _pvAllWindowHide();
} catch(...) {}
#endif
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button3Click(TObject *Sender)
{
#ifdef PROTECDLL
try {
    _pvSWTrigger(0);
} catch(...) {}
#endif
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::TestRequestJobName()
{
#ifdef PROTECDLL
    _pvSetCallRequestJobName(0, TestRequestJobName1, this);
#endif
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WorkDataRstBtnClick(TObject *Sender)
{
    memset(Work.unit, NULL, sizeof(Work.unit));
}
//---------------------------------------------------------------------------
//소스를 집파일로 만들기
void __fastcall TMainForm::SourceMakeToZip()
{
    TStringList *strList = new TStringList();

    strList->LoadFromFile("FileList.txt");

    AnsiString zipName;
    DateTimeToString(zipName, "yymmddhh", Now());

    zipName = Ext.GetFileName(Application->ExeName)+"("+zipName+").zip";

    if(FileExists(zipName)) DeleteFile(zipName);

    Zip->ZipFileName = zipName;
    Zip->Verbose = true;

    // Add as many filespecs as we want to:
    // (MS-DOS Wildcards are OK)
    for(int i=0; i<strList->Count; i++)
        Zip->FSpecArgs->Add(strList->Strings[i]);

    AnsiString sCfgFileName;
    if(sys.fac.nEquipType==VTYPE_2RAIL) {
        if(sys.fac.bNoUseRearRail)
            sCfgFileName = "VType1Rail.cfg";
        else sCfgFileName = "VType2Rail.cfg";
    }
    else sCfgFileName = "HType2Rail.cfg";
    CopyFile(AnsiString(SYS_FILE_PATH+CFG_FILE_NAME).c_str(), sCfgFileName.c_str(), false);
    Zip->FSpecArgs->Add(sCfgFileName);

    Zip->AddOptions = Zip->AddOptions << AddHiddenFiles;
    Zip->AddOptions = Zip->AddOptions >> AddEncrypt; // no password
    Zip->Add();

    delete strList;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button4Click(TObject *Sender)
{
    m_bDebugFinish = true;
    this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SockDispenserClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SockDispenserClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    static String readStr = "";

    String recvStr = Socket->ReceiveText();

    readStr += recvStr;
    Ext.SysLogAdd( "Received From Dispenser : " + recvStr );

    if( readStr.Pos( "@" ) == 0 )
        return;

    if( recvStr.Pos( "WORK_END;" ) != 0 ) {
        Work.isRecvWorkEnd = true;
    }
    else if( recvStr.Pos( "SUB_CONFIRM;" ) != 0 ) {
        if( recvStr.Pos( "T;" ) != 0 ) {
            Work.SubConfirmPass = COMM_OK;
        }
        else {
            Work.SubConfirmPass = COMM_NG;
        }
    }
    else if( recvStr.Pos( "MAG_CONFIRM;" ) != 0 ) {
        if( recvStr.Pos( "T;" ) != 0 ) {
            Work.MagConfirmPass = COMM_OK;
        }
        else {
            Work.MagConfirmPass = COMM_NG;
        }
    }
    //SUB_MAP_REQ;
    else if( recvStr.Pos( "SUB_MAP;" ) != 0 ) {

        char *str = recvStr.c_str();
        char *ptr;
        int tmp;

        if( recvStr.Pos( ";;;@" ) != 0 ) {
            SubMapReceived = true;
            return;
        }

        //ptr = strtok(str, ",");
        //printf("%s\n" , ptr);
        ptr = strtok(str, ";");
        ptr = strtok(NULL, ";");
        TStringList *list = new TStringList();
        while(ptr != NULL ) {
            list->Add(String(ptr));
            ptr = strtok(NULL, ";");
        }

        Work.SubMapData.row = list->Strings[0].ToInt();
        Work.SubMapData.col = list->Strings[1].ToInt();
        Work.SubMapData.CellStatus = list->Strings[2];
        delete list;
        SubMapReceived = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SendMsgToDp(String msg)
{
    if( SockDispenser->Socket->Connections[0] != NULL ) {
        if( SockDispenser->Socket->Connections[0]->Connected )
            SockDispenser->Socket->Connections[0]->SendText( msg + "@" );
    }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ComPortRfReaderRxChar(TObject *Sender,
      int Count)
{
    Sleep(100);
    TComPort *cPort = (TComPort*)Sender;

    static String RfId = "";
    String tempStr = "";
    cPort->ReadStr( tempStr, 255 );

    if( tempStr == "CHECK" ) {
        SendMsgToDp("CHECK");
        return;
    }

    Ext.SysLogAdd( "Comport Read zz: " + tempStr );
    Ext.MagRfId = tempStr.SubString( 1, tempStr.Pos( " " ));
    //delete 'A2'XXXXXX
    Ext.MagRfId = Ext.MagRfId.Delete(1,2);

//    int i = 0;
//    for(int j = 0; j < Count; j++) {
//        if( tempStr.c_str()[i] == ' ' ) {
//            Ext.MagRfId = RfId;
//            RfId = "";
//            break;
//        }
//        String a = tempStr.c_str()[i];
//        RfId += a;
//        i++;
//    }
}
//---------------------------------------------------------------------------


