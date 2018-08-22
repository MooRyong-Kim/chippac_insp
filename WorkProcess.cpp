//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "WorkProcess.h"
#include "Main.h"
#include "IOPort.h"
#include "Msg.h"
#include "MeasProcess.h"
#include "RunChk.h"
#include "MotionBase.h"
#include "Prepare.h"
#include "Extern.h"
#include "InitProcess.h"
#include "Math.h"
#include "Password.h"
#include "SecsGem.h"
#include "DataClass.h"
#include "Debug.h"
#include "ProtecDll.h"
//---------------------------------------------------------------------------
#include <Math.hpp>
#pragma package(smart_init)
TWorkProcess Work;
//---------------------------------------------------------------------------
__fastcall TWorkProcess::TWorkProcess()
{
    memset(m_bUlEmptySlot, true, sizeof(m_bUlEmptySlot));
    ProcessSetZero();    
    m_nStatus = RSTOP;
    m_dtStartTime = Now();

    isRecvWorkEnd = false;
    isLastPcb = false;
}
//---------------------------------------------------------------------------
__fastcall TWorkProcess::~TWorkProcess()
{
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::ProcessSetZero()
{
    memset(&pNo, 0, sizeof(pNo));
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::MainProcess(bool bThread)
{
    if(m_bProcessNumView) {
        MainForm->StatusBar->Panels->Items[5]->Text =
            "/FCVY:"+IntToStr(pNo.nInspCvy[FRNT])+
            "/RCVY:"+IntToStr(pNo.nInspCvy[REAR])+
            "/UNIT:"+IntToStr(pNo.nUnit)+
            "/UL:"+IntToStr(pNo.nUl);
    }

    MainForm->ProcessNumListBox->Items->BeginUpdate();
    PreCvyProcess();
    InspCvyProcess(FRNT);
    InspCvyProcess(REAR);
    UnitProcess();
    HoriUlProcess();
    VertUlProcess();
    StartProcess();
    StopProcess();
    CycleStopProcess();
    MainForm->ProcessNumListBox->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::StartProcess()
{
    if(pNo.nStart == 0 || Chk.m_bMainErrEvent || m_nStatus == RSTOP || !Init.m_bDone)
        return;

    static clock_t tChk;

    switch(pNo.nStart) {
    case 1:
        if(pNo.nStop == 0) {
            IO.SetTowerLamp(TWR_START);
            Ext.SysLogAdd("Work Start.");
            if(m_nRunMode == RUN_DRY) {
               //SecsGemForm->SendEvent(C_WARM_START, false);
            }
            //SecsGemForm->SendEvent(C_START_RUN);
            //SecsGemForm->m_bCycleStopDone = false;
            tChk = clock();
            pNo.nStart = 15;
        }
        break;
    case 15:
        pNo.nStart = 20;
        break;
    case 20:
        pNo.nStart = 100;
        break;
    case 100:
        if(m_nRunMode != RUN_VSN) {
            if(IO.In(fulenadct) && IO.In(fcvyoutdct))
                m_bResevePusher[FRNT] = false;
            if(IO.In(rulenadct) && IO.In(rcvyoutdct))
                m_bResevePusher[REAR] = false;
            if(m_bResevePusher[FRNT] || m_bResevePusher[REAR]) {
                if(m_bResevePusher[FRNT]) pNo.nInspCvy[FRNT] = 50;
                if(m_bResevePusher[REAR]) pNo.nInspCvy[REAR] = 50;
            } else {
                pNo.nInspCvy[FRNT] = 1;
                pNo.nInspCvy[REAR] = 1;
                pNo.nUl = 1;
            }
            m_bLotChgStart = false;
            m_nUphUnitCnt = 0;
            m_bUPHStartTimeReset = true;
        }
        else pNo.nUnit = 1;
        #ifdef PROTECDLL
            MainForm->MainPageCtrlChange(NULL);
            _pvInspChange(0, 0, 1);
        #endif
        pNo.nStart = 0;
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::InspCvyProcess(int n)
{
    if((sys.fac.nEquipType==HTYPE_1RAIL || sys.fac.bNoUseRearRail) && n>0) {
        run.bRearRailWork = false;
        return;
    }

    static bool bCvyStartChk[2], bLoading[2], bVacErrIgnore[2];
    static int nUlCvyPNo[2], nVacRtyCnt[2], bEject[2];
    static clock_t tDly[2], tSens[2];
    static clock_t tDly2[2], tSens2[2];
    static clock_t tCure[2];
    static int BarcodeRetry = 0;

    AnsiString sRail = (n==FRNT?"Front ":"Rear ");
    AnsiString cvyindct = (n==FRNT?fcvyindct:rcvyindct);
    AnsiString cvyinspdct = (n==FRNT?fcvyinspdct:rcvyinspdct);
    AnsiString ulenadct = (n==FRNT?fulenadct:rulenadct);
    AnsiString cvyoutdct = (n==FRNT?fcvyoutdct:rcvyoutdct);

    AnsiString inspstprup = (n==FRNT?finspstprup:rinspstprup);
    AnsiString inspstprdn = (n==FRNT?finspstprdn:rinspstprdn);
    AnsiString inspblkup = (n==FRNT?finspblkup:rinspblkup);
    AnsiString inspblkdn = (n==FRNT?finspblkdn:rinspblkdn);
    AnsiString inspblkvac = (n==FRNT?finspblkvac:rinspblkvac);

    AnsiString ulpushfwd = (n==FRNT?fulpushfwd:rulpushfwd);
    AnsiString ulpushbwd = (n==FRNT?fulpushbwd:rulpushbwd);
    AnsiString ulpushjam = (n==FRNT?fulpushjam:rulpushjam);
    AnsiString ulpushup = (n==FRNT?fulpushup:rulpushup);
    AnsiString ulpushdn = (n==FRNT?fulpushdn:rulpushdn);

    AnsiString postsmmnotrdy = (n==FRNT?fpostsmmnotrdy:rpostsmmnotrdy);
    AnsiString presmmrdy = (n==FRNT?fpresmmrdy:rpresmmrdy);

    AnsiString CVYFWD = (n==FRNT?FINSPCVYFWD:RINSPCVYFWD);
    AnsiString CVYRUN = (n==FRNT?FINSPCVYRUN:RINSPCVYRUN);
    AnsiString INSPBLKVAC = (n==FRNT?FINSPBLKVAC:RINSPBLKVAC);
    AnsiString INSPSTPRDN = (n==FRNT?FINSPSTPRDN:RINSPSTPRDN);
    AnsiString INSPBLKUP = (n==FRNT?FINSPBLKUP:RINSPBLKUP);
    AnsiString ULPUSHFWD = (n==FRNT?FULPUSHFWD:RULPUSHFWD);
    AnsiString ULPUSHDN = (n==FRNT?FULPUSHDN:RULPUSHDN);
    AnsiString IMSMMRDYTOPRE = (n==FRNT?FIMSMMRDYTOPRE:RIMSMMRDYTOPRE);
    AnsiString IMSMMRDYTOPOST = (n==FRNT?FIMSMMRDYTOPOST:RIMSMMRDYTOPOST);

    MainForm->ProcessNumListBox->Items->Strings[1] = "INSP CVY;    "+IntToStr(pNo.nInspCvy[0]);
    MainForm->ProcessNumListBox->Items->Strings[2] = "REAR INSP CVY;    "+IntToStr(pNo.nInspCvy[1]);
    MainForm->ProcessNumListBox->Items->Strings[4] = "UL CVY;    "+IntToStr(nUlCvyPNo[0]);
    MainForm->ProcessNumListBox->Items->Strings[5] = "REAR UL CVY;    "+IntToStr(nUlCvyPNo[1]);

    if(m_nStatus == RSTOP && m_nRunMode == RUN_BYPASS && IO.In(cvyinspdct) && IO.In(inspblkup) &&
        mdl.pcb.bUseCure && Ext.CheckDelay(tCure[n], mdl.pcb.nCureSec*1000)) {
        if(sys.eng.bUseClamp) IO.Off(CLAMPON);
        IO.Off(INSPBLKVAC);
        while(true) {
            if(Ext.CheckDelay(tDly[n], 1500) || !IO.In(inspblkvac)) {
                IO.Off(INSPBLKUP);
                break;
            }
            Ext.DoEvents();
        }
        if(m_nRunMode == RUN_BYPASS)
            m_bSetUnload[n] = true;
    }
    int nElapsed = mdl.pcb.nCureSec-(Ext.GetLapTime(tCure[n])/1000.);
    if(!mdl.pcb.bUseCure || !IO.In(cvyinspdct) || !IO.In(inspblkup)) {
        tCure[n] = clock();
        nElapsed = 0;
    }
    nElapsed = (nElapsed<0?0:nElapsed);
    AnsiString sElapsed; sElapsed = sElapsed.sprintf("%04d", nElapsed);
    if(n == FRNT)
        MainForm->FrntCureElapsedLed->Caption = sElapsed;
    else MainForm->RearCureElapsedLed->Caption = sElapsed;

    if(!Init.m_bDone || Chk.m_bMainErrEvent ||
        (m_nStatus == RSTOP && Work.m_sManualCmd[n].IsEmpty())) {
        if(!Init.m_bDone) {
            m_bSetUnload[n] = false;
            m_bReservePusher[n] = false;
        }
        bCvyStartChk[n] = true;
        tSens[n] = clock();;
        pNo.nInspCvy[n] = nUlCvyPNo[n] = 0;
        return;
    }

    if(pNo.nInspCvy[n] == 0)
        pNo.nInspCvy[n] = 1;

    if(nUlCvyPNo[n] == 0 && sys.fac.nEquipType == HTYPE_1RAIL) {
        IO.On(INSPPCBSENSON);
        nUlCvyPNo[n] = 1;
    }

    switch(pNo.nInspCvy[n]) {
    case 1:
        if(MB.AxisDone(DC)) {
            if(IO.In(cvyinspdct)) {
                if(Ext.CheckDelay(tSens[n], DLY_SENS)) {
                    if(m_bSetUnload[n]) {
                        pNo.nInspCvy[n] = (IO.In(inspstprdn)?55:46);
                    } else {
                        if(bLoading[n] && (IO.In(inspblkup) || sys.eng.bNoUseInspBlk || m_nRunMode == RUN_BYPASS)) {
                            if(IO.In(inspblkvac) || sys.eng.bNoUseInspBlkVacOn || m_nRunMode == RUN_BYPASS)
                                pNo.nInspCvy[n] = 40;//(m_nRunMode==RUN_BYPASS&&!mdl.pcb.bUseCure?40:35);
                            else pNo.nInspCvy[n] = 15;
                        } else {
                            if(m_nRunMode == RUN_BYPASS && !mdl.pcb.bUseCure)
                                pNo.nInspCvy[n] = 35;
                            else pNo.nInspCvy[n] = 15;
                        }
                    }
                    bCvyStartChk[n] = false;
                }
            } else {
                if(sys.eng.bUseClamp) IO.Off(CLAMPON);
                IO.Off(INSPBLKVAC);
                IO.Off(INSPBLKUP);
                IO.Off(INSPSTPRDN);
                m_bSetUnload[n] = bLoading[n] = false;
                nVacRtyCnt[n] = 0;
                bVacErrIgnore[n] = false;
                tDly[n] = tSens[n] = clock();
                pNo.nInspCvy[n] = 5;

                m_strBarcode = "";
            }
        }
        break;
    case 5:
        if( isRecvWorkEnd ) {
            Stop( TWR_END );
            pNo.nUl = 105;
            return;
        }
        if(IO.In(inspblkdn) && IO.In(inspstprup)) {
            if(bCvyStartChk[n]) {
                IO.On(CVYFWD);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 6;
            } else {
                if(MB.AxisDone(DC) && pNo.nInspCvy[!n] < 40) {
                    if(MB.IsCrntPos(DC, mdl.pcb.dCvyInPos)) {
                        if(IO.In(presmmrdy)) {
                            tDly[n] = clock();
                            IO.On(CVYFWD);
                        }
                        if(IO.In(cvyindct) || IO.In(cvyinspdct)) {
                            if(Ext.CheckDelay(tSens[n], DLY_SENS)) {
                                IO.On(CVYFWD);
                                IO.Off(IMSMMRDYTOPRE);
                                tDly[n] = clock();
                                pNo.nInspCvy[n] = 10;
                                return;
                            }
                        } else {
                            IO.On(IMSMMRDYTOPRE);
                            tSens[n] = clock();
                        }
                    }
                    else MB.MoveTo(DC, mdl.pcb.dCvyInPos);
                }
                if(Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000) && IO.GetOut(CVYRUN) && !IO.In(presmmrdy))
                    IO.Off(CVYRUN);
            }
        }
        else if(Ext.CheckDelay(tDly[n], sys.eng.nCylTimeErr)) {
            if(!IO.In(inspblkdn))
                Chk.ViewAlarm("Inspection Block Down Error."+io(inspblkdn)+io(INSPBLKUP));
            else Chk.ViewAlarm("Inspection Stopper Up Error."+io(inspstprup)+io(INSPSTPRDN));
            return;
        }
        break;
    case 6:
        if(IO.In(cvyinspdct)) {
            tDly[n] = tSens[n] = clock();
            pNo.nInspCvy[n] = 15;
        }
        else tSens[n] = clock();
        if(Ext.CheckDelay(tDly[n], CVY_START_CHECK_DELAY)) {
            IO.Off(CVYFWD);
            bCvyStartChk[n] = false;
            pNo.nInspCvy[n] = 5;
        }
        break;
    case 10:
        if(IO.In(cvyindct) || IO.In(cvyinspdct)) {
            if(Ext.CheckDelay(tSens[n], DLY_SENS)) {
                tDly[n] = tSens[n] = clock();
                pNo.nInspCvy[n] = 15;
            }
        }
        else tSens[n] = clock();
        if(Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm(sRail+ "Conveyor In Zone Transfer Error."+io(cvyindct));
            return;
        }
        break;
    case 15:
        if(IO.In(cvyinspdct)) {
            IO.On(CVYFWD);
            if(Ext.CheckDelay(tSens[n], DLY_SENS)) {
                tDly[n] = clock();
                pNo.nInspCvy[n] = (m_nRunMode==RUN_BYPASS&&!mdl.pcb.bUseCure?45:20);
            }
        }
        else tSens[n] = clock();
        if(Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm(sRail+ "Conveyor Inspection Zone Transfer Error."+io(cvyinspdct));
            return;
        }
        break;
    case 20:
        if(Ext.CheckDelay(tDly[n], sys.opr.nCvyStopDly)) {
            if(sys.eng.bUseClamp) IO.On(CLAMPON);
            //2016.02.11 20:06:56 chcho//
//            IO.On(INSPBLKVAC);
            //2016.02.11 20:10:23 chcho
            IO.Off(CVYFWD);

            IO.On(INSPBLKUP);
            IO.On(INSPSTPRDN);

            tDly[n] = clock();
            tDly2[n] = clock();
            pNo.nInspCvy[n] = 25;
        }
        break;
    case 25:
        //2016.02.11 19:54:15 chcho
        if( Ext.CheckDelay( tDly2[n], sys.eng.nDelayVacuum ) ) {
            IO.On(INSPBLKVAC);
        }
        else {
            return;
        }

        if(IO.In(inspblkup)) {
            //2016.02.11 20:10:11 chcho//
//            IO.Off(CVYFWD);
            if(pNo.nUnit == 0) {
                if(m_nRunMode != RUN_REWORK)
                    run.bRearRailWork = (n!=FRNT);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 30;
            }
        }
        //2016.02.11 20:04:58 chcho
        else if(Ext.CheckDelay(tDly[n], sys.eng.nCylTimeErr + sys.eng.nDelayVacuum)) {
            Chk.ViewAlarm(sRail+ "Inspection Block Up Error."+io(inspblkup)+io(INSPBLKUP));
            return;
        }
        break;
    case 30:
        if(Ext.CheckDelay(tDly[n], sys.opr.nBlkUpDly)) {
            if(sys.eng.bUseClamp) IO.On(CLAMPON);
            IO.On(INSPBLKVAC);
            tDly[n] = clock();
            pNo.nInspCvy[n] = 35;
        }
        break;
    case 35:
        if(IO.In(inspblkvac) || sys.eng.bNoUseInspBlkVacOn || m_nRunMode == RUN_BYPASS || bVacErrIgnore) {
            if(Work.m_sManualCmd[n] == "PCB_LOAD") {
                MsgDlg->Close();
                Work.m_sManualCmd[n] = "";
            }
            if(n != run.bRearRailWork || pNo.nInspCvy[!n] >= 40)
                return;
            if(m_nRunMode != RUN_REWORK && !bLoading[n])
                memset(unit, NULL, sizeof(unit));
            //if(m_nRunMode != RUN_BYPASS)
            //    IO.On(INSPSTPRDN);
            bLoading[n] = true;
            tDly[n] = clock();
            tCure[n]  = clock();
            pNo.nInspCvy[n] = (m_nRunMode==RUN_BYPASS&&!mdl.pcb.bUseCure?45:40);
        }
        else if(Ext.CheckDelay(tDly[n], sys.eng.nBlkVacTimeErr)) {
            if(++nVacRtyCnt[n]<=sys.eng.nInspBlkVacRtyNum) {
                if(sys.eng.bUseClamp) IO.Off(CLAMPON);
                IO.Off(INSPBLKVAC);
                IO.Off(INSPBLKUP);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 36;
                return;
            } else {
                MsgDlg->Close();
                pNo.nInspCvy[n] = 37;
            }
        }
        break;
    case 36:
        if(IO.In(inspblkdn)) {
            IO.On(CVYFWD);
            if(Ext.CheckDelay(tDly[n], 1000)) {
                IO.On(INSPBLKUP);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 37;
            }
        }
        else if(Ext.CheckDelay(tDly[n], sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm(sRail+ "Inspection Block Down Error."+io(inspblkdn)+io(INSPBLKUP));
            return;
        }
        break;
    case 37:
        if(!MsgDlg->Visible) {
            AnsiString sErrMsg = sRail+"Inspection Block Vacuum On Error."+io(INSPBLKVAC);
            Chk.SetAlarm(sErrMsg);
            int nRtn = MsgDlg->ShowBox(sErrMsg, MMB_ABORTRETRYIGNORE|MMI_STOP, 0, STR_ERR);
            if(nRtn == MID_ABORT) {
                Stop(TWR_STOP);
                return;
            }
            else if(nRtn == MID_RETRY) {
                IO.SetTowerLamp(TWR_START);
                nVacRtyCnt[n] = 0;
                pNo.nInspCvy[n] = 25;
            }
            else if(nRtn == MID_IGNORE) {
                if(sys.eng.bUseClamp) IO.On(CLAMPON);
                IO.SetTowerLamp(TWR_START);
                bVacErrIgnore[n] = true;
                tDly[n] = clock();
                pNo.nInspCvy[n] = 35;
            }
            Chk.m_bMainErrEvent = false;
        }
        break;
    case 40:
        if( m_nRunMode == RUN_BYPASS ) {
            pNo.nInspCvy[n] = 45;
            return;
        }
        if( mdl.pcb.bUseBarcode ) {
            Coord pos;
            pos.x = mdl.pcb.dBarcodeX;
            pos.y = mdl.pcb.dBarcodeY;
            MB.XYMoveTo( IX, pos );

            pNo.nInspCvy[n] = 41;
            return;
        }
        else {
            tDly[n] = clock();
            pNo.nInspCvy[n] = 44;
        }
        break;
    case 41:
        if( MB.AxisDone(IX) && MB.AxisDone(IY) ) {
            if(Ext.CheckDelay(tDly[n], sys.opr.nVsnDly)) {
                g_sInspResult = "";
                _pvInspChange(0, 0, BARCODE_INDEX);
                _pvSWTrigger(0);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 42;
                BarcodeRetry++;
            }
        }
        else {
            pNo.nInspCvy[n] = 40;
        }
        break;
    case 42:
        if( Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000) ) {
            //2015.09.10 chcho
            if( BarcodeRetry <= sys.eng.BarcodeRetryCnt ) {
                pNo.nInspCvy[n] = 40;
                tDly[n] = clock();
                return;
            }
            Ext.SysLogAdd("Barcode Reading Failed.");
            BarcodeRetry = 0;
            return;
        }
        else if( !g_sInspResult.IsEmpty() ) {
            BarcodeRetry = 0;
            m_strBarcode = g_sInspResult;
            tDly[n] = clock();
            pNo.nInspCvy[n] = 43;

            //SUB_LOAD_EVENT
//            if( MainForm->SockDispenser->Socket->Connected ) {
//                SubConfirmPass = COMM_STANDBY;
//                tDly2[n] = clock();
//                MainForm->SendMsgToDp( "SUB_LOAD;" + m_strBarcode + ";" );
//                Ext.SysLogAdd( "Send To Dispenser : SUB_LOAD" );
//            }
        }
        break;

    case 43:
//        if( MainForm->SockDispenser->Socket->Connected ) {
//            if( SubConfirmPass == COMM_STANDBY ) {
//                if( !Ext.CheckDelay(tDly2[n], sys.eng.nComTimeErr) ) {
//                    Chk.ViewAlarm(sRail+"No Response From Server Error.");
//                    return;
//                }
//                return;
//            }
//            else if( SubConfirmPass == COMM_NG ) {
//                Chk.ViewAlarm(sRail+"Reject PCB From Server Error.");
//                return;
//            }
//        }
        if( MainForm->SockDispenser->Socket->Connected ) {
            tDly2[n] = clock();
            SubMapData.row = 1;
            SubMapData.col = 1;
            SubMapData.CellStatus = "";
            MainForm->SubMapReceived = false;
            MainForm->SendMsgToDp( "SUB_MAP_REQ;" );
            Ext.SysLogAdd( "Send To Dispenser : SUB_MAP_REQ" );
        }
        pNo.nInspCvy[n] = 44;

        break;

    case 44:
        if( MainForm->SockDispenser->Socket->Connected ) {
            static int loop = 0;
            if( !MainForm->SubMapReceived ) {
                if( Ext.CheckDelay(tDly2[n], sys.eng.nComTimeErr*1000) ) {
                    loop++;
                    if( loop < 3 ) {
                        pNo.nInspCvy[n] = 43;
                        return;
                    }
                    Chk.ViewAlarm(sRail+"No Response From Server Error.(Sub-Map)");
                    loop = 0;
                    return;
                }
                return;
            }
            loop = 0;
        }

        if( mdl.pcb.bUseAfterInspCure ) {
            if( !MsgDlg->Showing ) {
                MsgDlg->ShowBox("Curring...  " + IntToStr(mdl.pcb.nCureSec) + " sec", MMB_SHOWONLY);
            }
            if( !Ext.CheckDelay(tDly[n], mdl.pcb.nCureSec * 1000 ) ) {
                return;
            }
            if( MsgDlg->Showing ) {
                MsgDlg->Close();
            }
        }
        if(pNo.nUnit == 0) {
            _pvInspChange(0, 0, 1);
            memset(unit, NULL, sizeof(unit));
            pNo.nUnit = 1;
            m_nCurLane = n;
            pNo.nInspCvy[n] = 45;
            _pvSignal_Reset(0);
        }
        break;
    case 45:
        if(pNo.nUnit == 0 && (!mdl.pcb.bUseCure || Ext.CheckDelay(tCure[n], mdl.pcb.nCureSec*1000))) {

            run.bRearRailWork = !run.bRearRailWork;
            //2016.06.14 14:03:37 chcho //
//            m_bSetUnload[n] = true;
            if(m_nRunMode == RUN_REWORK) {
                Stop(TWR_STOP);
                return;
            } else {
                if(sys.eng.bUseClamp) IO.Off(CLAMPON);
                IO.Off(INSPBLKVAC);
                tDly[n] = clock();
                pNo.nInspCvy[n] = 46;
            }
        }
        break;
    case 46:
        if(Ext.CheckDelay(tDly[n], 1500) || !IO.In(inspblkvac)) {
            IO.Off(INSPBLKUP);
            tDly[n] = clock();
            pNo.nInspCvy[n] = 47;
        }
        break;
    case 47:
        if(IO.In(inspblkdn)) {
            pNo.nInspCvy[n] = 50;
        }
        else if(Ext.CheckDelay(tDly[n], sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm(sRail+"Inspection Block Down Error."+io(inspblkdn)+io(INSPBLKUP));
            return;
        }
        break;
    case 50://xxx
        if((nUlCvyPNo[n] == 0 || nUlCvyPNo[n] == 1) && pNo.nUl == 0 && MB.AxisDone(DC) &&
            MB.AxisDone(UY) && MB.AxisDone(UZ) && (!sys.eng.bUlBarSafety || (!IO.In(ulbarsafety1) && !IO.In(ulbarsafety2))) ) {
            nCrntSlot = MB.GetCrntSlotNum(sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL);
            int nSlot;
            for(nSlot=0; nSlot<mdl.ul.nMgzSlotNum*MAX_MGZ; nSlot++) {
                if(m_bUlEmptySlot[nSlot])
                    break;
            }
            if( ((sys.fac.nEquipType == HTYPE_1RAIL && IO.In(ulgripmgzgood)) ||
                (sys.fac.nEquipType == VTYPE_2RAIL && IO.In(ulmgzdct)) ) &&
                ((nCrntSlot>0 && nCrntSlot == nSlot-1) || nCrntSlot == nSlot || m_bResevePusher[n])) {
                if(MB.AxisDone(DC) && pNo.nInspCvy[!n] <= 50) {
                    if(!MB.IsCrntPos(DC, mdl.pcb.dCvyOutPos[n]))
                        MB.MoveTo(DC, mdl.pcb.dCvyOutPos[n]);
                    if(!m_bResevePusher[n]) {
                        if(sys.fac.nEquipType == HTYPE_1RAIL)
                            HoriUlProcess(true);
                        else VertUlProcess(true);
                    }
                    m_bResevePusher[n] = true;
                    pNo.nInspCvy[n] = 51;

                    //2015.11.09 15:05:25 chcho
                    if( isRecvWorkEnd ) {
                        isRecvWorkEnd = false;
                        isLastPcb = true;
                    }
                }
            }
            else if(!m_bResevePusher[n]) {
                pNo.nUl = 1;
            }
        }
        break;
    case 51:
        if(MB.AxisDone(DC)) {

            if( MainForm->SockDispenser->Socket->Connected ) {
                MainForm->SendMsgToDp( "SUB_UNLOAD;" + m_strBarcode + ";" + Ext.MagRfId + ";" + nCrntSlot + ";" );

                
//                ??????????
//                //2016.10.13 chcho
//                UnloadEventStr += IntToStr(total);
//                UnloadEventStr += IntToStr(good);
//                ???????????


                Ext.SysLogAdd( "Send To Dispenser : SUB_UNLOAD" );
                MagSubId.push_back( m_strBarcode );

                //test
//                SubMapData.CellStatus = "0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 2 0 1 2 0 1 2 0 1 2 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 2 0 1 2 0 1 2 0 1 2 0 0 1 0 0 1 0 0 1 0 0 1 0";

                char *cellSt = SubMapData.CellStatus.c_str();

                if( SubMapData.CellStatus.Length() > 4 ) {
                    String SubmapResult = "";
                    // submap index (this is fixed)
                    //7 4 1
                    //8 5 2
                    //9 6 3
                    int cnt = 0;
                    for( int i = mdl.pcb.nUnitXCnt - 1; i >= 0; i--) {
                        for( int j = 0; j < mdl.pcb.nUnitYCnt; j++) {

                            int unitNo = MB.GetUnitNumFromCoord(n, i, j);

                            if(unit[unitNo].bInspDone ) {
                                if( unit[unitNo].eInspErr == INSP_NG && (cellSt[cnt*2] == '0' || cellSt[cnt*2] == '1') ) {
                                    SubmapResult += "1 ";
                                }
                                else if( unit[unitNo].eInspErr == INSP_OK && (cellSt[cnt*2] == '0' || cellSt[cnt*2] == '1') ) {
                                    SubmapResult += "0 ";
                                }
                                else if( unit[unitNo].eInspErr == INSP_NONE_TARGET && cellSt[cnt*2] != '2' ) {
                                    SubmapResult += "2 ";
                                }
                                else {
                                    SubmapResult += "1 ";
                                }

                            }
                            cnt++;
                        }
                    }
                    SubMapData.CellGrade = SubmapResult;

                    MainForm->SendMsgToDp( "SUB_MAP_UPLOAD;" + SubMapData.CellGrade + ";" );

                    Ext.SysLogAdd( "Send To Dispenser : SUB_MAP_UPLOAD" );
                    FormSubMapViewer->SaveSubmapLogFile( SubMapData );
                }
            }

            IO.On(INSPSTPRDN);
            tDly[n] = clock();
            pNo.nInspCvy[n] = 55;
        }
        break;
    case 55:
        if(IO.In(inspstprdn)) {
            IO.On(CVYFWD);
            tDly[n] = clock();
            pNo.nInspCvy[n] = 60;
        }
        else if(Ext.CheckDelay(tDly[n], sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm(sRail+"Inspection Stopper Down Error."+io(inspstprdn)+io(INSPSTPRDN));
            return;
        }
        break;
    case 60:
        if(!IO.In(cvyinspdct)) {
            tDly[n] = tSens[n] = clock();
            pNo.nInspCvy[n] = 65;
        }
        else tSens[n] = clock();
        if(Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm(sRail+"Conveyor Out Zone Transfer Error."+io(cvyinspdct));
            return;
        }
        break;
    case 65:
        if(!IO.In(ulenadct)) {
            if(Ext.CheckDelay(tSens[n], DLY_SENS*3)) {
                IO.Off(INSPSTPRDN);
                tDly[n] = clock();
                if(sys.fac.nEquipType == HTYPE_1RAIL) {
                    tDly2[n] = tSens2[n] = clock();
                    nUlCvyPNo[n] = 70;
                    pNo.nInspCvy[n] = 1;
                } else {
                    tDly2[n] = clock();
                    nUlCvyPNo[n] = 70;
                    pNo.nInspCvy[n] = 70;
                }
            }
        }
        else tSens[n] = clock();
        if(Ext.CheckDelay(tDly[n], sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm(sRail+"Conveyor Out Zone Transfer Error."+io(ulenadct));
            return;
        }
        break;
    case 70:
        if(nUlCvyPNo[n] == 0) {
            pNo.nInspCvy[n] = 1;
        }
        break;
    }

    switch(nUlCvyPNo[n]) {
    case 1:
        if(IO.In(ulenadct) || IO.In(cvyoutdct)) {
            if(Ext.CheckDelay(tSens2[n], DLY_SENS)) {
                IO.On(CVYFWD);
                tDly2[n] = tSens2[n] = clock();
                nUlCvyPNo[n] =  5;
            }
        }
        else {
            tSens2[n] = clock();
            if(Ext.CheckDelay(tDly2[n], DLY_SENS*3))
                nUlCvyPNo[n] = 0;
        }
        break;
    case 5:
        if(!IO.In(ulenadct) && IO.In(cvyoutdct)) {
            if(Ext.CheckDelay(tSens2[n], DLY_SENS)) {
                tDly2[n] = clock();
                nUlCvyPNo[n] =  70;
            }
        }
        else tSens2[n] = clock();
        if(Ext.CheckDelay(tDly2[n], sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm(sRail+"Conveyor Out Zone Transfer Error."+io(ulenadct)+io(cvyoutdct));
            return;
        }
        //2015.11.03 chcho
        IO.On(CVYRUN);
        break;
    case 70:
        if(Ext.CheckDelay(tDly2[n], sys.opr.nUlCvyStopDly)) {

            IO.Off(CVYRUN);
            IO.On(ULPUSHDN);
            tDly2[n] = clock();
            nUlCvyPNo[n] = 71;
        }
        break;
    case 71:
        if(IO.In(ulpushdn)) {
            IO.On(ULPUSHFWD);
            tDly2[n] = clock();
            nUlCvyPNo[n] = 75;
        }
        if(Ext.CheckDelay(tDly2[n], sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm(sRail+"Unloader Pusher Down Error."+io(ulpushdn)+io(ULPUSHDN));
            return;
        }
        break;
    case 75:
        if(IO.In(ulpushfwd)) {
            if(Ext.CheckDelay(tSens2[n], sys.opr.nUlPushOnDly)) {
                IO.Off(ULPUSHFWD);
                tDly2[n] = clock();
                nUlCvyPNo[n] = 80;
            }
        }
        else tSens2[n] = clock();
        if(Ext.CheckDelay(tDly2[n], sys.eng.nCylTimeErr+sys.opr.nUlPushOnDly)) {
            Chk.ViewAlarm(sRail+"Unloader Pusher Forward Error."+io(ulpushfwd)+io(ULPUSHFWD));
            return;
        }
        break;
    case 80:
        if(Ext.CheckDelay(tDly2[n], 1000))
            IO.Off(ULPUSHDN);
        if(IO.In(ulpushbwd) && IO.In(ulpushup)) {
            m_bResevePusher[n] = false;
            if(!IO.In(cvyoutdct)) {
                pNo.nUl = 1;
                nUlCvyPNo[n] = (sys.fac.nEquipType==HTYPE_1RAIL?1:0);

                //2015.11.09 15:16:31 chcho
                if( isLastPcb ) {
                    isLastPcb = false;
                    Stop( TWR_END );
                    pNo.nUl = 105;
                }

            } else {
                Chk.ViewAlarm(sRail+"Unloading Error."+io(cvyoutdct));
                return;
            }
        }
        if(Ext.CheckDelay(tDly2[n], sys.eng.nCylTimeErr+1000)) {
            if(!IO.In(ulpushbwd))
                Chk.ViewAlarm(sRail+"Unloader Pusher Backward Error."+io(ulpushbwd)+io(ULPUSHFWD));
            else Chk.ViewAlarm(sRail+"Unloader Pusher Up Error."+io(ulpushup)+io(ULPUSHDN));
            return;
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::UnitProcess()
{
    MainForm->ProcessNumListBox->Items->Strings[3] = "UNIT;    "+IntToStr(pNo.nUnit);

    if(!Init.m_bDone || m_nRunMode == RUN_BYPASS) {
        pNo.nUnit = 0;
        return;
    }

    if(m_nStatus == RSTOP || pNo.nUnit == 0 || Chk.m_bMainErrEvent) {
        return;
    }

    static int nInspUnit, nInspRty;
    static clock_t tDly;
//    static bool reInspRun = false;

    switch(pNo.nUnit) {
    case 1:
        if(MB.AxisDone(IX) && MB.AxisDone(IY) && MB.AxisDone(DC)) {
            //nInspRty = 0;
            int nTtlUnit = mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt;
            //검사 안 한 유닛을 찾는다.
            nInspUnit = -1;
            for(int i=0; i<nTtlUnit; i++) {
                if((i/(mdl.pcb.nCntDir==YDIR?mdl.pcb.nUnitYCnt:mdl.pcb.nUnitXCnt))%2 && !mdl.pcb.bNoUseZigZag) {
                    int nStart = i+(mdl.pcb.nCntDir==YDIR?mdl.pcb.nUnitYCnt:mdl.pcb.nUnitXCnt)-1;
                    nStart = (nStart>=nTtlUnit?nTtlUnit-1:nStart);
                    for(int j=nStart; j>=i; j--) {
                        if(!unit[j].bInspSkip && !unit[j].bInspDone) {
                            nInspUnit = j;
                            break;
                        }
                    }
                }
                else if(!unit[i].bInspSkip && !unit[i].bInspDone) {
                    nInspUnit = i;
                }
                if(nInspUnit > -1)
                    break;
            }
            m_bAllSkip = false;
            bool bAllPass = true;
            if(sys.opr.bInspErrCollect && nInspUnit == -1) {

                for(int u=0; u<nTtlUnit; u++) {
                    if(unit[u].bInspDone && ( unit[u].eInspErr == INSP_NG ) &&!unit[u].bInspManChkDone) {
                        bAllPass = false;
                        break;
                    }
                }
                if( !bAllPass ) {
                    if(++nInspRty <= sys.opr.nVsnAutoRtyCnt) {
                        _pvInspChange(0, 0, 1);

                        //memset(unit, NULL, sizeof(unit));

                        for(int u=0; u<nTtlUnit; u++) {
                            if(unit[u].bInspDone && (unit[u].eInspErr == INSP_NG ) &&!unit[u].bInspManChkDone) {
                                unit[u].bInspDone = false;
                            }
                        }
//                        reInspRun = true;
                        _pvSignal_Reset(0);

                        return;
                    }

                    if(sys.opr.nVsnErrSet == VSN_ALARM) {
                        //
                    }
                    else if(sys.opr.nVsnErrSet == VSN_SKIP) {
                        pNo.nUnit = 0;
                        return;
                    }
                    else if(sys.opr.nVsnErrSet == VSN_WAIT) {
                        MsgDlg->Close();
                        pNo.nUnit = 25;
                        nInspRty = 0;
                        return;
                    }

                    pNo.nUnit = -1;
                    AnsiString sErrMsg = "Dispenser Inspection Error.";
                    Chk.ViewAlarm(sErrMsg);
                    nInspRty = 0;
                    return;
                }
            }

            if( nInspUnit == -1 ) {
                nInspRty = 0;
            }

            if(nInspUnit > -1) {
                Coord posInsp = MB.GetUnitPos(run.bRearRailWork?REAR:FRNT, nInspUnit);
                MB.XYMoveTo(IX, posInsp);
                MB.MoveTo(DC, mdl.pcb.dCvyInPos);
                pNo.nUnit = 10;
            } else {
                Coord pos = {0., 0.};
                MB.XYMoveTo(IX, pos);

//                reInspRun = false;

                if(m_nRunMode == RUN_VSN) {
                    memset(unit, NULL, sizeof(unit));
                }
                else pNo.nUnit = 0;
            }
        }
        break;
    case 5:
        break;
    case 10:
        if(MB.AxisDone(IX) && MB.AxisDone(IY) && MB.AxisDone(DC)) {
            tDly = clock();
            pNo.nUnit = 15;
        }
        break;
    case 15:
        if(Ext.CheckDelay(tDly, sys.opr.nVsnDly)) {
        #ifdef PROTECDLL
            g_sInspResult = "";
            try {
                //2015.10.25 chcho
//                if( reInspRun ) {
//                    int a = 9;
//                    //_pvReInspection(0, nInspUnit);
//                }

                _pvSWTrigger(0);
            } catch(...) {}
        #endif
            pNo.nUnit = 20;
        }
        break;
    case 20:
        if(sys.fac.bNoMachine || m_nRunMode == RUN_DRY || !g_sInspResult.IsEmpty()) {
            if( (g_sInspResult != "0" && g_sInspResult != "9") && m_nRunMode != RUN_DRY) {
//                if(++nInspRty <= sys.opr.nVsnAutoRtyCnt) {
//                    pNo.nUnit = 15;
//                    return;
//                }
                if(sys.opr.bInspErrCollect && !unit[nInspUnit].bInspDone) {
                    unit[nInspUnit].bInspDone = true;
                    unit[nInspUnit].eInspErr = INSP_NG;
                    pNo.nUnit = 1;
                }
                else {
                    if(sys.opr.nVsnErrSet == VSN_ALARM) {
                        AnsiString sErrMsg = "Dispenser Inspection Error.@(Unit#"+IntToStr(nInspUnit+1)+")";
                        Chk.ViewAlarm(sErrMsg);
                        return;
                    }
                    else if(sys.opr.nVsnErrSet == VSN_SKIP) {
                        if(unit[nInspUnit].bInspDone)
                            unit[nInspUnit].bInspManChkDone = true;
                        unit[nInspUnit].bInspDone = true;
                        unit[nInspUnit].eInspErr = INSP_NG;
                        pNo.nUnit = 1;
                    }
                    else if(sys.opr.nVsnErrSet == VSN_WAIT) {
                        MsgDlg->Close();
                        pNo.nUnit = 25;
                    }
                }
            }
            else if( g_sInspResult == "9" ) {
                unit[nInspUnit].bInspDone = true;
                unit[nInspUnit].eInspErr = INSP_NONE_TARGET;
                pNo.nUnit = 1;
            }
            else {
                unit[nInspUnit].bInspDone = true;
                unit[nInspUnit].eInspErr = INSP_OK;
                pNo.nUnit = 1;
            }
        }
        break;
    case 25:
        if(!MsgDlg->Visible && !PasswordForm->Visible && pNo.nUnit == 25) {
            pNo.nUnit = -1;
//            AnsiString sErrMsg = "Dispenser Inspection Error.@(Unit#"+IntToStr(nInspUnit+1)+")";
            AnsiString sErrMsg = "Dispenser Inspection Error.";
            Chk.SetAlarm(sErrMsg, true);
//            int nRtn = MsgDlg->ShowBox(sErrMsg, MMB_STOPRETRYSKIPWORK|MMI_STOP, 0, STR_ERR);
            int nRtn = MsgDlg->ShowBox(sErrMsg, MMB_STOPRETRYSKIP|MMI_STOP, 0, STR_ERR);

            if(nRtn == MID_RETRY) {
                nInspRty = -1;
                IO.SetTowerLamp(TWR_START);
                pNo.nUnit = 1;
                pNo.nInspCvy[m_nCurLane] = 45;
            }
            else if(nRtn == MID_SKIP) {
//                if(unit[nInspUnit].bInspDone)
//                    unit[nInspUnit].bInspManChkDone = true;
//                if(MsgDlg->AllSkipChkBox->Checked) {
//                    for(int u=0; u<mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt; u++)
//                        unit[u].bInspManChkDone = true;
//                    MsgDlg->AllSkipChkBox->Checked = false;
//                }
//                unit[nInspUnit].bInspDone = true;
//                unit[nInspUnit].bInspErr = true;
                IO.SetTowerLamp(TWR_START);
                pNo.nUnit = 0;
                pNo.nInspCvy[m_nCurLane] = 45;
            }
//            else if(nRtn == MID_WORK) {
//                pNo.nUnit = 27;
//            }
            else {
                Stop(TWR_STOP);
            }

            Chk.m_bMainErrEvent = false;
        }
        break;
    case 27:
        if(!MsgDlg->Visible && !PasswordForm->Visible) {
            pNo.nUnit = 28;
            PasswordForm->PasswordCheck(10);
        }
        break;
    case 28:
        if(!PasswordForm->Visible) {
            if(PasswordForm->m_nResult == 11 || PasswordForm->m_nResult == PSWD_ENG_MATCH || PasswordForm->m_nResult == PSWD_FAC_MATCH) {
                if(unit[nInspUnit].bInspDone)
                    unit[nInspUnit].bInspManChkDone = true;
                unit[nInspUnit].bInspDone = true;
                unit[nInspUnit].eInspErr = INSP_OK;
                IO.SetTowerLamp(TWR_START);
                pNo.nUnit = 1;
            } else {
                Chk.ViewAlarm("Invalid Password Error.");
                return;
            }
        }
        break;
    case 35:
        if(sys.fac.bNoMachine || m_nRunMode == RUN_DRY) {
            unit[nInspUnit].bInspDone = true;
            pNo.nUnit = 1;
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::HoriUlProcess(bool bSetSlot)
{
    static int nMgzLdPNo, nMgzUlPNo;
    static double dSaveMgzSlotPos;
    static clock_t tDly, tErrWait;

    if(sys.fac.nEquipType != HTYPE_1RAIL) return;

    MainForm->ProcessNumListBox ->Items->Strings[5] = "UL;    "+IntToStr(pNo.nUl);
    MainForm->ProcessNumListBox->Items->Strings[6] = "MGZ LD;    "+IntToStr(nMgzLdPNo);
    MainForm->ProcessNumListBox->Items->Strings[7] = "MGZ UL;    "+IntToStr(nMgzUlPNo);

    if(bSetSlot) {
        int nSlot = MB.GetCrntSlotNum(UZ);
        if(nSlot > -1) {
            m_bUlEmptySlot[nSlot] = false;
            for(int i=nSlot; i<nSlot+mdl.pcb.nUlSlotTerm; i++)
                m_bUlEmptySlot[i] = false;
            lot.nOutPcbCnt++;
        } else {
            Chk.ViewAlarm("Invalid Unloader Elevator Slot Position Error.");
        }
        return;
    }

    if(!Init.m_bDone) {
        pNo.nUl = 0;
        return;
    }

    static bool bUlBarSafety;
    if(sys.eng.bUlBarSafety && (IO.In(ulbarsafety1) || IO.In(ulbarsafety2))) {
        bUlBarSafety = true;
        tErrWait = clock();
        return;
    }
    if(bUlBarSafety && MsgDlg->Visible && Chk.m_nAlarmPart == UL_SAFETY && Ext.CheckDelay(tErrWait, 1000)) {
        bUlBarSafety = false;
        MsgDlg->BitBtnClick(MsgDlg->BtnWork);
    }

    if(!Init.m_bDone || pNo.nUl == 0 || Chk.m_nAlarmPart == UL_ERR) {
        pNo.nUl = nMgzLdPNo = nMgzUlPNo = 0;
        return;
    }

    switch(pNo.nUl) {
    case 1:
        if(!sys.fac.bNoMachine && IO.In(fcvyoutdct)) {
            pNo.nUl = 0;
            return;
        }
        if(nMgzLdPNo == 0 && nMgzUlPNo == 0 && IO.In(fulpushbwd)) {
            nMgzLdPNo = 1;
            pNo.nUl = 10;
        }
        break;
    case 10:
        //kjseo 2017.03.23
        if(!Chk.IsAxisSafety(UZ) || !Chk.IsAxisSafety(UZ))
        {
            MsgDlg->Close();
            pNo.nUl = 0;
            return ;
        }

        if(nMgzLdPNo == 0 && nMgzUlPNo == 0 && MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(m_nStatus == RSTOP) {
                MsgDlg->Close();
                pNo.nUl = 0;
                return;
            }
            //자재가 없는 슬롯을 찾아서 이동한다.
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                if(m_bUlEmptySlot[s]) {
                    MB.MoveTo(UY, mdl.ul.posMgzStart.y);
                    dSaveMgzSlotPos = MB.GetMgzSlotPos(UZ, 0, s).z;
                    MB.MoveTo(UZ, dSaveMgzSlotPos);
                    pNo.nUl = 11;
                    return;
                }
            }
            nMgzUlPNo = 1;
            pNo.nUl = 1;
        }
        break;
    case 11:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posMgzStart.y) && MB.IsCrntPos(UZ, dSaveMgzSlotPos)) {
                pNo.nUl = 0;
            } else {
                MB.MoveTo(UY, mdl.ul.posMgzStart.y);
                MB.MoveTo(UZ, dSaveMgzSlotPos);
            }
        }
        break;
    case 105://for megazine slot empty lot change
        nMgzUlPNo = 1;
        pNo.nUl = 110;
        break;
    case 110:
        if(nMgzUlPNo == 0) {
            if(m_nStatus == RSTOP) {
                MsgDlg->Close();
                pNo.nUl = 0;
                return;
            }
            nMgzLdPNo = 1;
            pNo.nUl = 115;
        }
        break;
    case 115:
        if(nMgzLdPNo == 0) {
            nMgzUlPNo = 1;
            pNo.nUl = 120;
        }
        break;
    case 120://Lot Change End!
        if(nMgzUlPNo == 0) {
            m_nStatus = RSTART;
            IO.SetTowerLamp(TWR_START);
            pNo.nUl = 1;
        }
        break;
    }

    if(IO.In(rstbtn) || IO.In(ulrstbtn)) {
        if(nMgzLdPNo == -1)
            nMgzLdPNo = 1;
        else if(nMgzUlPNo == -1)
            nMgzUlPNo = (IO.In(ulmgzgripon)?1:0);
    }

    if(nMgzLdPNo == 7 || nMgzLdPNo == -1 || nMgzUlPNo == 7 || nMgzUlPNo == -1) {//메거진을 교체 해야 된다면 리셋 램프가 깜박 거린다.
        if(Ext.CheckDelay(tDly, 1000)) {
            if(IO.GetOut(ULRSTLAMP)) {
                IO.Off(ULRSTLAMP);
                IO.Off(RSTLAMP);
            } else {
                IO.On(ULRSTLAMP);
                IO.On(RSTLAMP);
            }
            tDly = clock();
        }
    }

    switch(nMgzLdPNo) {
    case 1:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(IO.In(ulmgzgripon) || !IO.In(ulmgzgripoff)) {
                if(IO.In(ulgripmgzgood))  {
                    if(m_nStatus != RSTOP) {
                        int nCnt = 0;
                        for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                            if(m_bUlEmptySlot[s]) nCnt++;
                        }
                        if(nCnt == 0) {
                            nMgzLdPNo = 0;
                            nMgzUlPNo = 1;
                            return;
                        }
                    }
                    if(MB.IsCrntPos(UY, mdl.ul.posGripOnPre.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnPre.z))
                        nMgzLdPNo = 5;
                    else if(MB.IsCrntPos(UY, mdl.ul.posGripOnCvy.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnCvy.z))
                        nMgzLdPNo = 30;
                    else if(MB.IsCrntPos(UY, mdl.ul.posGripOnUp.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnUp.z))
                        nMgzLdPNo = 30;
                    else if(MB.IsCrntPos(UY, mdl.ul.posGripOnOut.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnOut.z))
                        nMgzLdPNo = 45;
                    else if(MB.GetPos(UY) < mdl.ul.posGripOnPre.y+DEAD_BAND || MB.GetPos(UY) < 0.+DEAD_BAND ||
                        MB.GetPos(UY) < mdl.ul.posMgzStart.y+DEAD_BAND || MB.GetCrntSlotNum(UZ) > -1) {
                        nMgzLdPNo = 0;
                    } else {
                        Chk.ViewAlarm("Unloader Is Not Safety Position Error. Please, Open The Gripper By Manual Operation.", UL_ERR);
                        return;
                    }
                } else {
                    Chk.ViewAlarm("Unloader Gripper Magazine Not Detection Error."+io(ulgripmgzgood), UL_ERR);
                    return;
                }
            } else {//클램프를 초기화 한다.
                if(MB.IsCrntPos(UY, mdl.ul.posGripOff.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOff.z)) {
                    nMgzLdPNo = 0;
                    nMgzUlPNo = 1;
                    return;
                }
                else if(MB.IsCrntPos(UY, mdl.ul.posGripOnPre.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnPre.z)) {
                    nMgzLdPNo = 3;
                    return;
                }
                else if((MB.IsCrntPos(UY, mdl.ul.posGripOnCvy.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnCvy.z)) ||
                    (MB.IsCrntPos(UY, mdl.ul.posGripOnUp.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnUp.z))) {
                    nMgzLdPNo = 30;
                    return;
                }

                if(IO.In(ulgripmgzgood)) {
                    Chk.ViewAlarm("Unloader Gripper On/Off Sensor Broaken Error."+io(ulgripmgzgood), UL_ERR);
                    return;
                }

                if(MB.IsCrntPos(UY, mdl.ul.posGripOnPre.y)) {
                    IO.Off(ULMGZGRIP);
                    IO.On(ULMGZGRIPUP);
                    IO.Off(ULMGZGRIPDOWN);
                    tDly = clock();
                    nMgzLdPNo = 2;
                }
                else MB.MoveTo(UY, mdl.ul.posGripOnPre.y);
            }
        }
        break;
    case 2:
        if(IO.In(ulmgzgripoff)) {
            if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
                if(MB.IsCrntPos(UZ, mdl.ul.posGripOnPre.z))
                    nMgzLdPNo = 3;
                else MB.MoveTo(UZ, mdl.ul.posGripOnPre.z);
            }
        }
        else if(Ext.CheckDelay(tDly, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Unloader Gripper Magazine Grip Error."+io(ulmgzgripoff), UL_ERR);
            return;
        }
        break;
    case 3:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++)
                m_bUlEmptySlot[s] = false;
            if(!IO.In(ulmgzldout)) {
                IO.On(ULLDCVYFWD);
                tDly = clock();
                nMgzLdPNo = 5;
            }
            else nMgzLdPNo = 10;
        }
        break;
    case 5:
        if(IO.In(ulmgzldout)) {
            tDly = clock();
            nMgzLdPNo = 10;
        }
        else if(Ext.CheckDelay(tDly, (mdl.ul.nEmptyChkTime*1000))) {
            IO.Off(ULLDCVYRUN);
            IO.SetTowerLamp(TWR_CHANGE);
            IO.On(ULRSTLAMP);
            nMgzLdPNo = 6;
        }
        break;
    case 6:
        if(!MsgDlg->Visible)
            nMgzLdPNo = 7;
        break;
    case 7:
        if(IO.In(rstbtn) || IO.In(ulrstbtn)) {
            IO.Off(ULRSTLAMP);
            IO.Off(RSTLAMP);
            IO.SetTowerLamp(TWR_START);
            if(MsgDlg->Visible)
                MsgDlg->BitBtnClick(MsgDlg->BtnOk);
            return;
        }
        if(!MsgDlg->Visible) {
            if(MsgDlg->ShowBox("Unloader Magazine Empty.", MMB_OKCANCEL|MMI_INFO) == MID_OK) {
                IO.SetTowerLamp(TWR_START);
                nMgzLdPNo = 1;
            }
            else nMgzLdPNo = -1;
            IO.Off(ULRSTLAMP);
            IO.Off(RSTLAMP);
        }
        break;
    case 10:
        if(Ext.CheckDelay(tDly, mdl.ul.nLdOutSensDly)) {
            IO.Off(ULLDCVYRUN);
            nMgzLdPNo = 15;
        }
        break;
    case 15:
        if(!IO.In(ulmgzldout)) {
            nMgzLdPNo = 1;
            return;
        }
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOnPre.y))
                nMgzLdPNo = 20;
            else MB.MoveTo(UY, mdl.ul.posGripOnPre.y);
        }
        break;
    case 20:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UZ, mdl.ul.posGripOnPre.z))
                nMgzLdPNo = 25;
            else MB.MoveTo(UZ, mdl.ul.posGripOnPre.z);
        }
        break;
    case 25:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOnCvy.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnCvy.z))
                nMgzLdPNo = 30;
            else {
                MB.MoveTo(UY, mdl.ul.posGripOnCvy.y);
                MB.MoveTo(UZ, mdl.ul.posGripOnCvy.z);
            }
        }
        break;
    case 30:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOnUp.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnUp.z)) {
                DebugForm->MgzGripGoodChkBox->Checked = true;
                IO.On(ULMGZGRIP);
                //kjseo 20170223
                IO.Off(ULMGZGRIPUP);
                IO.On(ULMGZGRIPDOWN);

                tDly = clock();
                nMgzLdPNo = 40;
            } else {
                MB.MoveTo(UY, mdl.ul.posGripOnUp.y);
                MB.MoveTo(UZ, mdl.ul.posGripOnUp.z);
            }
        }
        break;
    case 40:
        if(IO.In(ulmgzgripon) && IO.In(ulgripmgzgood)) {
            if(!PrepareForm->m_bUlDataReset) {
                for(int s=0; s<mdl.ul.nMgzSlotNum; s++)
                    m_bUlEmptySlot[s] = true;
            }
            PrepareForm->m_bUlDataReset = false;
            tDly = clock();
            nMgzLdPNo = 45;
        }
        else if(Ext.CheckDelay(tDly, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Unloader Gripper Magazine Grip Error."+io(ulmgzgripon)+io(ulgripmgzgood), UL_ERR);
            return;
        }
        break;
    case 45:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOnOut.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOnOut.z)) {
                nMgzLdPNo = 65;
            } else {
                MB.MoveTo(UY, mdl.ul.posGripOnOut.y);
                MB.MoveTo(UZ, mdl.ul.posGripOnOut.z);
            }
        }
        break;
    case 65:
        nMgzLdPNo = 70;
        break;
    case 70:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posMgzStart.y))
                nMgzLdPNo = 75;
            else MB.MoveTo(UY, mdl.ul.posMgzStart.y);
        }
        break;
    case 75:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UZ, mdl.ul.posMgzStart.z)) {
                if( MainForm->SockDispenser->Socket->Connected ) {
                    nMgzLdPNo = 80;
                    MagConfirmPass = COMM_STANDBY;
                    Ext.ReadMagRfTag(2);
                    tDly = clock();
                    Ext.SysLogAdd( "Reading MAG RF-ID" );
                    return;
                }
                nMgzLdPNo = 0;
            }
            else {
                MB.MoveTo(UZ, mdl.ul.posMgzStart.z);
            }

        }
        break;

    case 80:
        if( Ext.MagRfId.Length() > 2 ) {
            if( Ext.CheckDelay(tDly, 200) ) {
                Ext.SysLogAdd( "Current MAG RF-ID : " + Ext.MagRfId );
                MagSubId.clear();
                MainForm->SendMsgToDp( "MAG_LOAD;" + Ext.MagRfId + ";" );
                tDly = clock();
                nMgzLdPNo = 85;
            }
        }
        else if( Ext.CheckDelay(tDly, sys.eng.nComTimeErr*1000) ) {
            Ext.SysLogAdd( "MAG RF-ID read fail" );
            MainForm->SendMsgToDp( "MAG_LOAD;" + Ext.MagRfId + ";" );
            tDly = clock();
            nMgzLdPNo = 85;
        }
        break;

    case 85:
        if( MagConfirmPass == COMM_STANDBY ) {
            if( Ext.CheckDelay(tDly, sys.eng.nComTimeErr*1000) ) {
                Chk.ViewAlarm("No Response MAG_CONFIRM From Server Error.");
                return;
            }
            return;
        }
        else if( MagConfirmPass == COMM_NG ) {
            Chk.ViewAlarm("MAG NG From Server Error.");
            return;
        }
        else {
            nMgzLdPNo = 0;
        }
        break;

    }

    static bool bUlMgzUlInErr;
    switch(nMgzUlPNo) {
    case 1:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {

            if( MainForm->SockDispenser->Socket->Connected ) {
                Ext.SysLogAdd( "MAG Unload Start." );

                String UnloadEventStr = "";
                UnloadEventStr += "MAG_UNLOAD;";
                UnloadEventStr += Ext.MagRfId + ";";
                UnloadEventStr += IntToStr( MagSubId.size() )+ ";";
                for( int i = 0; i < MagSubId.size(); i++ ) {
                    UnloadEventStr += MagSubId[i] + ";";
                }

                MainForm->SendMsgToDp( UnloadEventStr + ";" );
            }

            bUlMgzUlInErr = false;
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffPre.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffPre.z))
                nMgzUlPNo = 15;
            else if(MB.IsCrntPos(UY, mdl.ul.posGripOffCvy.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffCvy.z))
                nMgzUlPNo = 15;
            else if(MB.IsCrntPos(UY, mdl.ul.posGripOff.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOff.z))
                nMgzUlPNo = 20;
            else if(MB.IsCrntPos(UY, mdl.ul.posGripOffDn.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffDn.z))
                nMgzUlPNo = 45;
            else if(MB.IsCrntPos(UY, mdl.ul.posGripOffOut.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffOut.z))
                nMgzUlPNo = 45;
            else if(MB.GetPos(UY) < mdl.ul.posGripOffPre.y+DEAD_BAND || MB.GetPos(UY) < 0.+DEAD_BAND ||
                MB.GetPos(UY) < mdl.ul.posMgzStart.y+DEAD_BAND || MB.GetCrntSlotNum(UZ) > -1) {
                nMgzUlPNo = (m_nStatus==RSTOP?10:5);
            } else {
                Chk.ViewAlarm("Unloader Is Not Safety Position Error. Please, Open The Gripper By Manual Operation.", UL_ERR);
                return;
            }
        }
        break;
    case 5:
        nMgzUlPNo = 6;
        break;
    case 6:
        if(IO.In(ulmgzulfull) && !sys.fac.bNoMachine) {
            IO.SetTowerLamp(TWR_CHANGE);
            IO.On(ULRSTLAMP);
            tDly = clock();
            MsgDlg->Close();
            nMgzUlPNo = 7;
        } else {
            if(IO.In(ulgripmgzgood))
                nMgzUlPNo = 10;
            else nMgzUlPNo = 0;
        }
        break;
    case 7:
        if(IO.In(rstbtn) || IO.In(ulrstbtn)) {
            IO.Off(ULRSTLAMP);
            IO.Off(RSTLAMP);
            IO.SetTowerLamp(TWR_START);
            if(MsgDlg->Visible)
                MsgDlg->BitBtnClick(MsgDlg->BtnOk);
            return;
        }
        if(!MsgDlg->Visible) {
            if(MsgDlg->ShowBox("Unloader Magazine Unloading Zone Full.", MMB_OKCANCEL|MMI_INFO) == MID_OK) {
                IO.SetTowerLamp(TWR_START);
                if(IO.In(ulmgzgripon))
                    nMgzUlPNo = 1;
                else nMgzUlPNo = 0;
            }
            else nMgzUlPNo = -1;
            IO.Off(ULRSTLAMP);
            IO.Off(RSTLAMP);
        }
        break;
    case 10:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffPre.y))
                nMgzUlPNo = 11;
            else MB.MoveTo(UY, mdl.ul.posGripOffPre.y);
        }
        break;
    case 11:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UZ, mdl.ul.posGripOffPre.z))
                nMgzUlPNo = 15;
            else MB.MoveTo(UZ, mdl.ul.posGripOffPre.z);
        }
        break;
    case 15:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UZ, mdl.ul.posGripOffCvy.z))
                nMgzUlPNo = 16;
            else MB.MoveTo(UZ, mdl.ul.posGripOffCvy.z);
        }
        break;
    case 16:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffCvy.y))
                nMgzUlPNo = 20;
            else MB.MoveTo(UY, mdl.ul.posGripOffCvy.y);
        }
        break;
    case 20:
        /*if(IO.In(ulmgzulout)) {
            MB.MoveStop(UY);
            nMgzUlPNo = 21;
            return;
        }*/
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOff.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOff.z)) {
                IO.Off(ULMGZGRIP);
                IO.On(ULMGZGRIPUP);
                IO.Off(ULMGZGRIPDOWN);
                tDly = clock();
                nMgzUlPNo = 30;
            } else {
                MB.MoveTo(UY, mdl.ul.posGripOff.y);
                MB.MoveTo(UZ, mdl.ul.posGripOff.z);
            }
        }
        break;
    case 21:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffPre.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffPre.z))
                nMgzUlPNo = 7;
            else {
                MB.MoveTo(UY, mdl.ul.posGripOffPre.y);
                MB.MoveTo(UZ, mdl.ul.posGripOffPre.z);
            }
        }
        break;
    case 30:
        if(IO.In(ulmgzgripoff)) {
            tDly = clock();
            nMgzUlPNo = 35;
            return;
        }
        else if(Ext.CheckDelay(tDly, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Unloader Magazine Gripper Off Error."+io(ulmgzgripoff), UL_ERR);
            return;
        }
        break;
    case 35:
        if(Ext.CheckDelay(tDly, DLY_SENS)) {
            nMgzUlPNo = 40;
        }
        break;
    case 40:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffDn.y) && MB.IsCrntPos(UZ, mdl.ul.posGripOffDn.z)) {
                DebugForm->MgzGripGoodChkBox->Checked = false;
                //bUlMgzUlInErr = !IO.In(ulmgzulin);
                nMgzUlPNo = 45;
            } else {
                MB.MoveTo(UY, mdl.ul.posGripOffDn.y);
                MB.MoveTo(UZ, mdl.ul.posGripOffDn.z);
            }
        }
        break;
    case 45:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UZ, mdl.ul.posGripOffOut.z))
                nMgzUlPNo = 46;
            else MB.MoveTo(UZ, mdl.ul.posGripOffOut.z);
        }
        break;
    case 46:
        if(MB.AxisDone(UY) && MB.AxisDone(UZ)) {
            if(MB.IsCrntPos(UY, mdl.ul.posGripOffOut.y)) {
                if(m_nStatus != RSTOP) {
                    SecsGemForm->SendEvent(C_MAGAZINE_UNLOAD);
                    if(IO.In(ulmgzulfull) && !sys.fac.bNoMachine) {
                        nMgzUlPNo = 7;
                        return;
                    }
                    nMgzUlPNo = 0;
                    if(bUlMgzUlInErr) {
                        bUlMgzUlInErr = false;
                        Chk.ViewAlarm("Unloader Magazine Unloading Error.", UL_ERR);
                        return;
                    }
                }
                else nMgzUlPNo = 0;
            }
            else MB.MoveTo(UY, mdl.ul.posGripOffOut.y);
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::VertUlProcess(bool bSetSlot)
{
    if(sys.fac.nEquipType != VTYPE_2RAIL) return;

    MainForm->ProcessNumListBox->Items->Strings[6] = "UL;    "+IntToStr(pNo.nUl);
    MainForm->ProcessNumListBox->Items->Strings[7] = ";";

    if(bSetSlot) {
        int nSlot = MB.GetCrntSlotNum(UL);
        if(nSlot > -1) {
            m_bUlEmptySlot[nSlot] = false;
            for(int i=nSlot; i<nSlot+mdl.pcb.nUlSlotTerm; i++)
                m_bUlEmptySlot[i] = false;
            lot.nOutPcbCnt++;
        } else {
            Chk.ViewAlarm("Invalid Unloader Elevator Slot Position Error.");
        }
        return;
    }

    if(!Init.m_bDone) {
        pNo.nUl = 0;
        return;
    }

    static int nMgzLdPNo, nMgzUlPNo, nStep;
    static double dSaveMgzSlotPos;
    static clock_t tDly, tErrWait;
    static bool bUlBarSafety, bRejBoat;

    if(sys.eng.bUlBarSafety && IO.In(ulsafety)) {
        bUlBarSafety = true;
        tErrWait = clock();
        return;
    }
    if(bUlBarSafety && MsgDlg->Visible && Chk.m_nAlarmPart == UL_SAFETY && Ext.CheckDelay(tErrWait, 1000)) {
        bUlBarSafety = false;
        MsgDlg->BitBtnClick(MsgDlg->BtnWork);
    }

    if(!Init.m_bDone || pNo.nUl == 0 || Chk.m_nAlarmPart == UL_ERR) {
        pNo.nUl = nMgzLdPNo = nMgzUlPNo = 0;
        return;
    }

    switch(pNo.nUl) {
    case 1:
        if( (MB.IsCrntPos(DC, mdl.pcb.dCvyOutPos[FRNT]) && (IO.In(fulenadct) || IO.In(fcvyoutdct))) ||
            (MB.IsCrntPos(DC, mdl.pcb.dCvyOutPos[REAR]) && (IO.In(rulenadct) || IO.In(rcvyoutdct))) ) {
            pNo.nUl = 0;
            return;
        }
        if(MB.AxisDone(UL)) {
            nStep = 0;
            bRejBoat = false;
            if(mdl.ul.bUseRejMgz && (m_bSetUnload[FRNT] || m_bSetUnload[REAR])) {
                for(int i=0; i<mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt; i++) {
                    if(m_bSetUnload[FRNT]?rltMem.bRailRejUnit[FRNT][i]:rltMem.bRailRejUnit[REAR][i]) {
                        bRejBoat = true;
                        break;
                    }
                }
            }
            for(int m=0; m<MAX_MGZ ; m++) {
                for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                    if(!mdl.ul.bUseRejMgz || (!bRejBoat && m>0) || (bRejBoat && m==0)) {
                        if(!mdl.ul.bUseMgz[m])
                            m_bUlEmptySlot[nStep] = false;
                        if(m_bUlEmptySlot[nStep]) {
                            dSaveMgzSlotPos = MB.GetMgzSlotPos(UL, m, s).z;
                            MB.MoveTo(UL, dSaveMgzSlotPos);
                            pNo.nUl = 10;
                            return;
                        }
                    }
                    nStep++;
                }
            }
            pNo.nUl = 2;
        }
        break;
    case 2:
        if(MB.AxisDone(UL)) {
            MB.MoveTo(UL, mdl.ul.dMgzChgPos);
            pNo.nUl = 5;
        }
        break;
    case 5:
        if(MB.AxisDone(UL)) {
            if(MB.IsCrntPos(UL, mdl.ul.dMgzChgPos)) {
                if(!MsgDlg->Visible && pNo.nUl != -1) {
                    IO.SetTowerLamp(TWR_CHANGE);
                    IO.On(ULRSTLAMP);
                    AnsiString sMsg = (bRejBoat?"Unloader Reject Magazine Full.":"Unloader Magazine Full.");
                    if(MsgDlg->ShowBox(sMsg, MMB_OKCANCEL|MMI_INFO) == MID_OK) {
                        pNo.nUl = 6;
                        return;
                    } else {
                        IO.SetTowerLamp(m_nStatus==RSTOP?TWR_STOP:TWR_START);
                        pNo.nUl = -1;
                    }
                }
            }
            else MB.MoveTo(UL, mdl.ul.dMgzChgPos);
        }
        break;
    case 6:
        nStep = 0;
        for(int m=0; m<MAX_MGZ ; m++) {
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                if(!mdl.ul.bUseRejMgz || (!bRejBoat && m>0) || (bRejBoat && m==0))
                    m_bUlEmptySlot[nStep] = mdl.ul.bUseMgz[m];
                nStep++;
            }
        }
        IO.SetTowerLamp(TWR_START);
        IO.Off(ULRSTLAMP);
        pNo.nUl = 1;
        break;
    case 10:
        if(MB.AxisDone(UL)) {
            if(MB.IsCrntPos(UL, dSaveMgzSlotPos)) {
                if(IO.In(ulmgzdct))
                    pNo.nUl = 0;
                else {
                    int nMgz, nSlot;
                    MB.GetMgzSlotNum(UL, nMgz, nSlot);
                    for(int s=0; s<mdl.ul.nMgzSlotNum*MAX_MGZ; s++)
                        m_bUlEmptySlot[s]  = (nStep >= (nMgz*mdl.ul.nMgzSlotNum)+mdl.ul.nMgzSlotNum);
                    pNo.nUl = 1;
                }
            }
            else MB.MoveTo(UL, dSaveMgzSlotPos);
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::Stop(int nTwrLmp)
{
    if(m_nStatus != RSTOP) {
        if(nTwrLmp == TWR_STOP) {
            Ext.SysLogAdd("Work Stop.");
        }
        else if(nTwrLmp == TWR_END) {
            Ext.SysLogAdd("Work End.");
            MainForm->SendMsgToDp("WORK_END" );
        }

//        SecsGemForm->SendEvent(C_PAUSE_RUN);
        m_nStatus = RSTOP;
        IO.SetTowerLamp(nTwrLmp);
    }

    m_nStatus = RSTOP;

    IO.Off(FIMSMMRDYTOPRE);
    IO.Off(RIMSMMRDYTOPRE);
    ProcessSetZero();
    Chk.m_bMainErrEvent = false;
    m_bUPHStartTimeReset = true;

    MsgDlg->Close();
    PasswordForm->Close();

    IO.Off(FINSPCVYFWD);
    IO.Off(RINSPCVYFWD);
    IO.Off(ULLDCVYFWD);
    IO.Off(FULPUSHFWD);
    IO.Off(RULPUSHFWD);
    IO.Off(ULRSTLAMP);

    m_bLotChgStart = false;
    MainForm->RunModeCmbBox->Enabled = true;
    Work.m_sManualCmd[FRNT] = "";
    Work.m_sManualCmd[REAR] = "";

    if(pNo.nStop == 0)
        pNo.nStop = 1;

    IO.SetTowerLamp(nTwrLmp, false);
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::StopProcess()
{
    static clock_t tDly;

    if(pNo.nStop == 0 || !Init.m_bDone) {
        tDly = clock();
        pNo.nStop = 0;
        return;
    }

    switch(pNo.nStop) {
    case 1:
        if(MB.AxisDone(IX) && MB.AxisDone(IY) &&
            (IO.In(fulpushbwd) && (sys.fac.nEquipType!=VTYPE_2RAIL||sys.fac.bNoUseRearRail||IO.In(rulpushbwd))) ||
            Ext.CheckDelay(tDly, sys.eng.nCylTimeErr*1500)) {
            IO.Off(FULPUSHDN);
            if(sys.fac.nEquipType == VTYPE_2RAIL)
                IO.Off(RULPUSHDN);
            Coord pos = {0., 0.};
            MB.XYMoveTo(IX, pos);
            pNo.nStop = 5;
        }
        break;
    case 5:
        if(MB.AxisDone(IX) && MB.AxisDone(IY))
            pNo.nStop = 0;
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::CycleStopProcess()
{
    if(pNo.nCycStop == 0 || Chk.m_bMainErrEvent || m_nStatus == RSTOP || !Init.m_bDone)
        return;

        /*
    switch(pNo.nCycStop) {
    case 1:
        if(m_nRejUlPNo == 0) {
            if(!IO.In(sprspostindct) && !IO.In(sprspostzonedct) && !IO.In(sprspostoutdct) &&
                !IO.In(sprsprszonedct) && !IO.In(sprspreindct) && !IO.In(sprsprezonedct) &&
                !IO.In(sprspreoutdct)) {
                for(int ax=0; ax<AXES; ax++) {
                    if(!MB.AxisDone(ax))
                        return;
                }
                //SecsGemForm->m_bCycleStopDone = true;
                if(m_nStatus == CYC_STOP)
                    Stop(TWR_STOP);
                pNo.nCycStop = 0;
            }
        }
        break;
    }
    */
}
//---------------------------------------------------------------------------
bool __fastcall TWorkProcess::IsWorkEnd()
{
    return false;
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::WorkEndCheck()
{
    if(!Chk.m_bMainErrEvent && m_nStatus != RSTOP && pNo.nStart == 0) {
        /*if(PrepareForm->PdtReseveQtySpinEdit->Value == PrepareForm->PkgInputDigitLbl->Value) {
            if(!WRK.Pkg.bEmptySlotLotChg && PrepareForm->m_bLotChange) {
                m_nStatus = CYC_STOP;
                pNo.nCycStop = 1;
            }
        }*/
        if(IsWorkEnd()) {
            Stop(TWR_END);
            PrepareForm->LotStartTimeLbl->Caption = DateTimeToStr(Now());
            MsgDlg->ShowBox("Work Complete.");
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TWorkProcess::PreCvyProcess()
{
    static bool bCvyStartChk;
    static int nPreCvyPNo;
    static clock_t tDly, tSens, tTrans;

    MainForm->ProcessNumListBox->Items->Strings[0] = "PRE CVY;    "+IntToStr(nPreCvyPNo);

    if(!sys.fac.bUsePreBufCvy || !Init.m_bDone || Chk.m_bMainErrEvent || m_nStatus == RSTOP) {
        bCvyStartChk = true;
        tSens = clock();
        nPreCvyPNo = 0;
        return;
    }

    if(nPreCvyPNo == 0)
        nPreCvyPNo = 1;

    switch(nPreCvyPNo) {
    case 1:
        if(!bCvyStartChk) {
            if(IO.In(cvypredct)) {
                if(Ext.CheckDelay(tSens, DLY_SENS)) {
                    m_bBoatSent = false;
                    if(!IO.In(fcvyinspdct) && IO.In(finspstprup)) {
                        IO.On(PRESTPRDN);
                        tDly = clock();
                    }
                }
            }
            else tSens = clock();

            if(!m_bBoatSent || IO.In(cvypredct)) {
                tTrans = clock();
                if(IO.GetOut(FINSPCVYRUN) && Ext.CheckDelay(tDly, (sys.eng.nCvyTimeErr/2)*1000) &&
                    (Ext.CheckDelay(tSens, sys.opr.nCvyStopDly) || !IO.In(cvypredct)) ) {
                    IO.Off(FINSPCVYRUN);
                    tDly = clock();
                    if(IO.In(cvypredct))
                        lot.nInPcbCnt++;
                }
            }
            else if(m_bBoatSent) {
                tDly= clock();
                IO.On(FINSPCVYFWD);
                if(Ext.CheckDelay(tTrans, sys.eng.nCvyTimeErr*2000)) {
                    tTrans = clock();
                    m_bBoatSent = false;
                    Chk.ViewAlarm("Dispenser To Inspection Pre Zone Transfer Error.");
                    return;
                }
            }

            if(!IO.In(prestprup) && !IO.In(cvypredct)) {
                IO.Off(PRESTPRDN);
                tDly = clock();
                nPreCvyPNo = 5;
            }
        }
        break;
    case 5:
        if(IO.In(prestprup)) {
            nPreCvyPNo = 1;
        }
        else if(Ext.CheckDelay(tDly, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Conveyor Pre Stopper Up Error.");
            return;
        }
        break;
    case 10:
        if(IO.In(prestprdn)) {
            IO.On(INSPCVYFWD);
            tDly = clock();
            nPreCvyPNo = 15;
        }
        else if(Ext.CheckDelay(tDly, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Coveyor Pre Stopper Down Error.");
            return;
        }
        break;
    case 15:
        IO.On(INSPCVYFWD);
        if(IO.In(fcvyinspdct)) {
            if(Ext.CheckDelay(tSens, DLY_SENS)) {
                tDly = clock();
                nPreCvyPNo = 1;
            }
        }
        else tSens = clock();
        if(Ext.CheckDelay(tDly, sys.eng.nCvyTimeErr*1000)) {
            Chk.ViewAlarm("Conveyor Pre To Inspection Zone Moving Error.");
            return;
        }
    }
}
//---------------------------------------------------------------------------

