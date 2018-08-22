//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RunChk.h"
#include "Msg.h"
#include "DataClass.h"
#include "Main.h"
#include "Init.h"
#include "MotionBase.h"
#include "InitProcess.h"
#include "WorkProcess.h"
#include "Extern.h"
#include "IOPort.h"
#include "Jog.h"
#include "MeasProcess.h"
#include "Maint.h"
#include "SecsGem.h"
#include "WorkSetup.h"
#include "SysSetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TRunChk Chk;
//---------------------------------------------------------------------------
__fastcall TRunChk::TRunChk()
{
}
//---------------------------------------------------------------------------
__fastcall TRunChk::~TRunChk()
{
}
//---------------------------------------------------------------------------
void __fastcall TRunChk::ViewAlarm(AnsiString sErrMsg, int nAlarmPart, AnsiString sIo)
{
    if(m_bMainErrEvent || (m_nAlarmPart != 0 && nAlarmPart > 0))
        return;

    m_nAlarmPart = (nAlarmPart==-1?0:nAlarmPart);
    m_bMainErrEvent = (nAlarmPart == -1 || !Init.m_bDone);

    if(Work.m_nStatus != RSTOP)
        SetAlarm(sErrMsg, false, nAlarmPart);
    else if(Init.m_nStatus != RSTOP)
        Init.Stop();

    IO.SetTowerLamp(TWR_ALARM);        
    m_sErrMsg = sErrMsg;
    MsgDlg->Close();
    MsgDlg->m_nAlarmBoxPNo = 1;
}
//---------------------------------------------------------------------------
void __fastcall TRunChk::SetAlarm(AnsiString sErrMsg, bool bMsgBoxBlink, int nAlarmPart)
{
    //2015.06.02 chcho
    String ErrorPrcNo = "Error Proc - / INSP CVY:"+IntToStr(Work.pNo.nInspCvy[0])
                         + " / REAR INSP CVY:"+IntToStr(Work.pNo.nInspCvy[1])
                         + " / Unit:"  + IntToStr(Work.pNo.nUnit)
                         + " / UL:"+IntToStr(Work.pNo.nUl);

    Ext.SysLogAdd( ErrorPrcNo );


    m_nAlarmPart = (nAlarmPart==-1?0:nAlarmPart);
    m_bMainErrEvent = (nAlarmPart == -1 || !Init.m_bDone);

    m_sErrMsg = sErrMsg;
    Ext.SysLogAdd("!"+sErrMsg);
    IO.SetTowerLamp(TWR_ALARM);
    MsgDlg->m_bBlink = bMsgBoxBlink;

    if(m_bMainErrEvent) 
        SecsGemForm->SendALCD(true, sErrMsg);
}
//---------------------------------------------------------------------------
bool __fastcall TRunChk::IsSensorSafety(int nAxis)
{
    if(sys.fac.bNoMachine)
        return true;


    static bool bMainAirGood = true;
    if(!IO.In(mainairgood) && bMainAirGood) {
        bMainAirGood = false;
        ViewAlarm("Main Air Low Error."+io(mainairgood));
        return false;
    }
    else bMainAirGood = true;

    if(IO.In(emgsw) || IO.In(ulemgsw)) {
        for(int ax=0; ax<AXES; ax++) {
            if(MB.IsServoOn(ax))
                MB.ServoPower(ax, OFF);
        }
        Init.m_bDone = false;
        if(IO.In(emgsw))        ViewAlarm("Main Emergency Switch Press Error."+io(emgsw));
        else if(IO.In(ulemgsw)) ViewAlarm("Unloader Emergency Switch Press Error."+io(ulemgsw));
        return false;
    }

    LOOP:
    if(!IO.In(srvpwr)) {
        Init.m_bDone = false;
        for(int ax=0; ax<AXES; ax++) {
            if(MB.IsServoOn(ax))
                MB.ServoPower(ax, OFF);
        }
        ViewAlarm("Servo Power Switch Off Error."+io(srvpwr));
        return false;
    }
//Safety Sensor check
    bool bAlwaysSafetyOn = (sys.fac.bAlwaysSafetyOn && Work.m_nStatus != RSTOP);

    if((sys.eng.bFrntDoorSafety || bAlwaysSafetyOn) && !IO.In(fdoorclose)) {
        if(nAxis == IX || nAxis == IY || !MB.AxisDone(IX) || !MB.AxisDone(IY)) {
            sys.eng.bSafetySrvOff?IO.Off(SRVENA):IO.On(SRVENA);
            ViewAlarm("Front Door Open Error."+io(fdoorclose));
            return false;
        }
    }

    if((sys.eng.bUlBarSafety || bAlwaysSafetyOn) && (IO.In(ulbarsafety1) || IO.In(ulbarsafety2))) {
        if(nAxis == UZ || nAxis == UY || !MB.AxisDone(UZ) || !MB.AxisDone(UY)) {
            sys.eng.bSafetySrvOff?IO.Off(SRVENA):IO.On(SRVENA);
            if(IO.In(ulbarsafety1))
                ViewAlarm("Unloader Side Bar Safety Error."+io(ulbarsafety1));
            else
                ViewAlarm("Unloader Side Bar Safety Error."+io(ulbarsafety2));
            return false;
        }
        /*
        if(nAxis == RU || !MB.AxisDone(RU)) {
            sys.eng.bSafetySrvOff?IO.Off(SRVENA):IO.On(SRVENA);
            ViewAlarm("Unloader Bar Safety Error.");
            return false;
        }*/
    }

    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TRunChk::IsAxisSafety(int nAxis, bool bJogMove)
{
    if(sys.fac.bNoMachine)
        return true;

    if(!IsSensorSafety(nAxis))
        return false;

    if(MB.IsServoAlarm(nAxis) && Init.m_nHomePNo[nAxis] != 1) {
        MB.MoveStop(nAxis);
        MB.ServoPower(nAxis, OFF);
        ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[nAxis]+" Servo Amp Alarm.");
        return false;
    }
    if(Init.m_bDone) {
        if(!MB.IsServoOn(nAxis)) {
            ViewAlarm(IntToStr(nAxis)+" Servo Power Off.");
            return false;
        }
        if(Work.m_nStatus != RSTOP) {
            if(MB.PosLimit(nAxis)) {
                ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[nAxis]+" H/W Plus Limit Error.");
                return false;
            }
            if(MB.NegLimit(nAxis)) {
                ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[nAxis]+" H/W Minus Limit Error.");
                return false;
            }
        }
    }

    if(nAxis==DC && sys.fac.nEquipType==VTYPE_2RAIL) {
        if(IO.In(fcvyindct)) {
            ViewAlarm("Front Conveyor In Zone Detection Error."+io(fcvyindct));
            return false;
        }
        else if(IO.In(rcvyindct)) {
            ViewAlarm("Rear Conveyor In Zone Detection Error."+io(rcvyindct));
            return false;
        }
        if(IO.In(fcvyoutdct)) {
            ViewAlarm("Front Conveyor Out Zone Detection Error."+io(fcvyoutdct));
            return false;
        }
        else if(IO.In(rcvyoutdct)) {
            ViewAlarm("Rear Conveyor Out Zone Detection Error."+io(rcvyoutdct));
            return false;
        }
    }

    if(nAxis == UL || nAxis == UZ) {
        if(!IO.In(fulpushbwd)) {
            IO.Off(FULPUSHFWD);
            IO.Off(FULPUSHDN);
            ViewAlarm("Unloading Conveyor Pusher Off Error."+io(fulpushbwd)+io(FULPUSHFWD), -1);
            return false;
        }
        if(IO.In(fcvyoutdct)) {
            ViewAlarm("Unloading Conveyor Out Zone Detection Error."+io(fcvyoutdct), -1);
            return false;
        }
        if(sys.fac.nEquipType == VTYPE_2RAIL && !sys.fac.bNoUseRearRail) {
            if(!IO.In(rulpushbwd)) {
                IO.Off(RULPUSHFWD);
                IO.Off(RULPUSHDN);
                ViewAlarm("Rear Unloading Conveyor Pusher Off Error."+io(rulpushbwd)+io(RULPUSHFWD), -1);
                return false;
            }
            if(IO.In(rcvyoutdct)) {
               ViewAlarm("Unloading Conveyor Out Zone Detection Error."+io(rcvyoutdct), -1);
               return false;
            }
        }
    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TRunChk::AutoRunSafety()
{
    if(sys.fac.bNoMachine || m_bMainErrEvent)
        return;

    bool bHoming = false;
    bool bMoving = false;
    bool bAlwaysSafetyOn = (sys.fac.bAlwaysSafetyOn && Work.m_nStatus != RSTOP);

    if(MB.move.bJog) {
        for(int i=0; i<AXES; i++) {
            if(!MB.AxisDone(i))
                continue;
            else if(i == AXES-1)
                MB.move.bJog = false;
        }
    }

    for(int ax=0; ax<AXES; ax++) {
        if(Init.m_nHomePNo[ax] != 0)
            bHoming = true;
        if(!MB.AxisDone(ax) && Init.m_bDone)
            bMoving = true;
        if(MB.AxisDone(ax))
            MB.move.tTime[ax] = clock();
        else if(MB.move.nTimeOut[ax] > 0 && Ext.CheckDelay(MB.move.tTime[ax], MB.move.nTimeOut[ax])) {
            MB.MoveStop(ax);
            Sleep(300);
            MB.ResetInposition(ax);
            MB.move.tTime[ax] = clock();
            if(!m_bMainErrEvent) {
                ViewAlarm(IntToStr(ax)+"Move Time Error.");
                return;
            }
        }
    }

    if(m_bMainErrEvent)
        return;

    //2016.10.12 sjso   If status==RSTART, Always check Door Safety (while X Y axis moving ALSO check)
    //                  (before: check door safety ONLY while X Y axis moving)
//    if(!MB.AxisDone(IX) || !MB.AxisDone(IY)) {
    if(!MB.AxisDone(IX) || !MB.AxisDone(IY) || Work.m_nStatus == RSTART) {
        if((sys.eng.bFrntDoorSafety || bAlwaysSafetyOn) && !IO.In(fdoorclose)) {
            MB.MoveStop(IX);
            MB.MoveStop(IY);
            ViewAlarm("Front Door Open Error."+io(fdoorclose));
            return;
        }
    }

    if(!MB.AxisDone(UZ) || !MB.AxisDone(UY)) {
        if((sys.eng.bUlBarSafety || bAlwaysSafetyOn) && (IO.In(ulbarsafety1) || IO.In(ulbarsafety2))) {
            MB.MoveStop(UZ);
            MB.MoveStop(UY);
            if(IO.In(ulbarsafety1))
                ViewAlarm("Unloader Side Bar Safety Error."+io(ulbarsafety1), UL_SAFETY);
            else
                ViewAlarm("Unloader Side Bar Safety Error."+io(ulbarsafety2), UL_SAFETY);
            return;
        }
        if(!IO.In(fulpushbwd)) {
            IO.Off(FULPUSHFWD);
            IO.Off(FULPUSHDN);
            MB.MoveStop(UZ);
            MB.MoveStop(UY);
            ViewAlarm("Unloading Conveyor Pusher Off Error."+io(fulpushbwd)+io(FULPUSHFWD), UL_ERR);
            return;
        }
        if(IO.In(fcvyoutdct)) {
            MB.MoveStop(UZ);
            MB.MoveStop(UY);
            ViewAlarm("Unloading Conveyor Out Zone Detection Error."+io(fcvyoutdct), UL_ERR);
            return;
        }
        if(sys.fac.nEquipType == VTYPE_2RAIL && !sys.fac.bNoUseRearRail) {
            if(!IO.In(rulpushbwd)) {
                IO.Off(RULPUSHFWD);
                IO.Off(RULPUSHDN);
                MB.MoveStop(UZ);
                MB.MoveStop(UY);
                ViewAlarm("Rear Unloading Conveyor Pusher Off Error."+io(rulpushbwd)+io(FULPUSHFWD), UL_ERR);
                return;
            }
            if(IO.In(rcvyoutdct)) {
                MB.MoveStop(UZ);
                MB.MoveStop(UY);
                ViewAlarm("Rear Unloading Conveyor Out Zone Detection Error."+io(rcvyoutdct), UL_ERR);
                return;
            }
        }
    }

    if(!MB.AxisDone(DC) && sys.fac.nEquipType==VTYPE_2RAIL) {
        if(IO.In(fcvyindct)) {
            ViewAlarm("Front Conveyor In Zone Detection Error."+io(fcvyindct));
            return;
        }
        if(IO.In(fcvyoutdct)) {
            ViewAlarm("Front Conveyor Out Zone Detection Error."+io(fcvyoutdct));
            return;
        }
        if(!sys.fac.bNoUseRearRail) {
            if(IO.In(rcvyindct)) {
                ViewAlarm("Rear Conveyor In Zone Detection Error."+io(rcvyindct));
                return;
            }
            if(IO.In(rcvyoutdct)) {
                ViewAlarm("Rear Conveyor Out Zone Detection Error."+io(rcvyoutdct));
                return;
            }
        }
    }

    MB.move.bAuto = (Work.m_nStatus != RSTOP || Init.m_nStatus != RSTOP || !Meas.m_bDone || bHoming);

    if(MB.move.bAuto || bMoving) {
        if(!IsSensorSafety())
            return;

        if((Work.m_nStatus != RSTOP || !Meas.m_bDone) && !Init.m_bDone) {
            ViewAlarm("Did Not Initialize Error.");
            return;
        }

        for(int ax=0; ax<AXES; ax++) {
            if(!Init.m_bDone && Init.m_nHomePNo[ax] < 10)
                continue;

            if(MB.IsServoAlarm(ax)) {
                MB.MoveStop(ax);
                MB.ServoPower(ax, OFF);
                ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[ax]+" Servo Amp Alarm.");
                return;
            }
            /*if(!MB.IsServoOn(ax)) {
                //Init.m_bDone = false;
                ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[ax]+" Servo Power Off.");
                return;
            }*/
            if(MB.move.bAuto && !MB.move.bJog && !bHoming) {
                if(MB.PosLimit(ax)) {
                    ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[ax]+" H/W Plus Limit Error.");
                    return;
                }
                if(MB.NegLimit(ax)) {
                    ViewAlarm(Ext.m_pLngList[STR_AXIS]->Strings[ax]+" H/W Minus Limit Error.");
                    return;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TRunChk::MachineBtnProcess()
{
    if(MaintForm->Visible && Work.m_nStatus == RSTOP) return;

    if(MB.move.bAuto) {
        IO.On(STARTLAMP);
        IO.Off(STOPLAMP);
    } else {
        IO.Off(STARTLAMP);
        IO.On(STOPLAMP);
    }

    static clock_t tRstLamp;

    if(m_bMainErrEvent) {
        if(!IO.GetOut(RSTLAMP)) {
            if(Ext.CheckDelay(tRstLamp, 1000)) {
                IO.On(RSTLAMP);
                tRstLamp = clock();
            }
        } else {
            if(Ext.CheckDelay(tRstLamp, 1000)) {
                IO.Off(RSTLAMP);
                tRstLamp = clock();
            }
        }
    }
    else IO.Off(RSTLAMP);

    static bool bBtn[10];
    enum RunChkBtn {BTN_START, BTN_STOP, BTN_RESET, BTN_VAC, BTN_LDRST, BTN_ULRST, };

    if(IO.In(stopbtn))
        bBtn[BTN_STOP] = true;
    else if(!IO.In(stopbtn) && bBtn[BTN_STOP]) {
        bBtn[BTN_STOP] = false;
        if(InitForm->Visible)
            InitForm->InitBtnClick(InitForm->StopBtn);
        else if(!WorkSetupForm->Visible && !SysSetupForm->Visible)
            MainForm->PanelClick(MainForm->StopPanel);
    }
    if(IO.In(startbtn) && !m_bMainErrEvent)
        bBtn[BTN_START] = true;
    else if(!IO.In(startbtn) && bBtn[BTN_START]) {
        bBtn[BTN_START] = false;
        if(InitForm->Visible)
            InitForm->InitBtnClick(InitForm->StartBtn);
        else MainForm->PanelClick(MainForm->StartPanel);
    }
    else if(IO.In(rstbtn)) {
        bBtn[BTN_RESET] = true;
        IO.On(RSTLAMP);
    }
    else if(!IO.In(rstbtn) && bBtn[BTN_RESET]) {
        bBtn[BTN_RESET] = false;
        IO.Off(RSTLAMP);
        if(MsgDlg->Visible) {
            MsgDlg->ResultID = MID_OK;
            MsgDlg->Close();
        }
    }
    else if(IO.In(ulrstbtn)) {
        bBtn[BTN_ULRST] = true;
        IO.On(ULRSTLAMP);
    }
    else if(!IO.In(ulrstbtn) && bBtn[BTN_ULRST]) {
        bBtn[BTN_ULRST] = false;
        IO.Off(ULRSTLAMP);
    }
    else if(IO.In(vacsw)) {
        bBtn[BTN_VAC] = true;
        IO.On(VACSWLAMP);
    }
    else if(!IO.In(vacsw) && bBtn[BTN_VAC]) {
        bBtn[BTN_VAC] = false;
        IO.Off(VACSWLAMP);
    }
}
//---------------------------------------------------------------------------

