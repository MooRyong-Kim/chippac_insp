//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InitProcess.h"
#include "RunChk.h"
#include "Extern.h"
#include "Init.h"
#include "MotionBase.h"
#include "DataClass.h"
#include "IOPort.h"
#include "Msg.h"
#include "WorkProcess.h"
#include "SecsGem.h"
//---------------------------------------------------------------------------
#include <math.h>
#pragma package(smart_init)
TInitProcess Init;
//---------------------------------------------------------------------------
__fastcall TInitProcess::TInitProcess()
{
}
//---------------------------------------------------------------------------
__fastcall TInitProcess::~TInitProcess()
{
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::Start()
{
    if(m_nStatus != RSTART) {
        InitForm->InitMsgListBox->Clear();
        m_bDone = false;
        m_nStatus = RSTART;
        m_nInitPNo = 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::Stop()
{
    m_nInitPNo = 0;
    for(int ax=0; ax<AXES; ax++) {
        m_nHomePNo[ax] = 0;
        MB.MoveStop(ax);
    }

    IO.Off(FINSPCVYRUN);
    if(sys.fac.nEquipType == HTYPE_1RAIL) {
        IO.Off(ULLDCVYRUN);
    } else {
        IO.Off(RINSPCVYRUN);
    }

    AddInitMsg("System Initialize Stop By User.");
    m_nStatus = RSTOP;
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::AddInitMsg(AnsiString sMsg)
{
    if(!InitForm->Visible)
        return;

    int nIdx = Ext.FindMsgIndex(STR_MSG, sMsg);
    AnsiString sList;
    if(nIdx != -1) {
        sList = Ext.m_pLngList[STR_MSG]->Strings[nIdx];
        sList = sList.Delete(1, sList.Pos("<<")+1);
        sMsg = sList.SubString(1, sList.Pos(">>")-1);
    }

    InitForm->InitMsgListBox->Items->Add(sMsg);
    InitForm->InitMsgListBox->ItemIndex = InitForm->InitMsgListBox->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::MainProcess()
{
    InitProcess();
    for(int ax=0; ax<AXES; ax++)
        HomeProcess(ax);
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::InitProcess()
{
    const int  FRNT        = 0;
    const int  REAR        = 1;
    const int  ULR         = 2;
    const int  TOTAL       = 3;

    static int nInitPNo[TOTAL];
    bool bInitEnd;

    if(m_nInitPNo == 0 || Chk.m_bMainErrEvent) {
        for(int i=0; i<TOTAL; i++)
            nInitPNo[i] = 0;
        return;
    }

    switch(m_nInitPNo) {
    case 1://장비 각 영역의 충돌 가능한 물체를 제거한다.
        Ext.SysLogAdd("System Initialize Start.");
        AddInitMsg("System Initialize Start.");
        m_bDone = false;
        IO.On(SRVPWR);
        IO.On(SRVENA);
        if(!MB.InitMotionBoard()) {
            AddInitMsg("Motion Board Initialize Fault!");
            Stop();
            return;
        }
        AddInitMsg("Motion Board Initialize OK!");
        for(int i=0; i<TOTAL; i++) {
            nInitPNo[i] = (sys.fac.bNoMachine?0:1);
            if(sys.fac.nEquipType == HTYPE_1RAIL || sys.fac.bNoUseRearRail)
                nInitPNo[REAR] = 0;
            if(sys.fac.bNoUseUnloader)
                nInitPNo[ULR] = 0;
        }
        SecsGemForm->SendEvent(C_INIT_SYSTEM, false);
        m_nInitPNo = 10;
        break;
    case 10:
        bInitEnd = true;
        for(int i=0; i<TOTAL; i++) {
            if(nInitPNo[i] != 0) {
                bInitEnd &= false;
                break;
            }
        }
        if(bInitEnd) {
            Ext.SysLogAdd("System Initialize End.");
            AddInitMsg("System Initialize End.");
            m_nInitPNo = 0;
            m_nStatus = RSTOP;
            if(m_bAuto)
                InitForm->Close();
            m_bAuto = false;
            m_bDone = true;
        }
        break;
    }

    static clock_t tFrnt;
    switch(nInitPNo[FRNT]) {
    case 1:
        AddInitMsg("Conveyor Part Initialize Start.");
        AddInitMsg("Head Part Initialize Start.");
        m_nHomePNo[IX] = 1;
        m_nHomePNo[IY] = 1;
        IO.Off(FULPUSHDN);
        IO.Off(FULPUSHFWD);
        tFrnt = clock();
        nInitPNo[FRNT] = 5;
        break;
    case 5:
        if(IO.In(fulpushbwd) && IO.In(fulpushup)) {
            if(!IO.In(fcvyinspdct)) {
                IO.Off(FINSPSTPRDN);
                tFrnt = clock();
                nInitPNo[FRNT] = 10;
            }
            else nInitPNo[FRNT] = 15;
        }
        else if(Ext.CheckDelay(tFrnt, sys.eng.nCylTimeErr)) {
            if(!IO.In(fulpushbwd))
                Chk.ViewAlarm("Unloader Conveyor Pusher Off Error."+io(fulpushbwd)+io(FULPUSHFWD));
            else Chk.ViewAlarm("Unloader Conveyor Pusher Up Error."+io(fulpushup)+io(FULPUSHDN));
            return;
        }
        break;
    case 10:
        if(IO.In(finspstprup)) {
            IO.On(FINSPCVYFWD);
            tFrnt = clock();
            nInitPNo[FRNT] = 15;
        }
        else if(Ext.CheckDelay(tFrnt, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Inspection Stopper Up Error."+io(finspstprup)+io(FINSPSTPRDN));
            return;
        }
        break;
    case 15:
        if(m_nHomePNo[IX] == 0 && m_nHomePNo[IY] == 0 && nInitPNo[REAR] == 0 &&
            Ext.CheckDelay(tFrnt, (sys.eng.nCvyTimeErr*1000)/3)) {
            if(m_nHomePNo[IX] == 0 && m_nHomePNo[IY] == 0)
                AddInitMsg("Head Part Initialize End.");
            IO.Off(FINSPCVYFWD);
            if(sys.fac.nEquipType == VTYPE_2RAIL) {
                if(IO.In(fcvyindct)) {
                    Chk.ViewAlarm("Conveyor In Zone Detection Error."+io(fcvyindct));
                    return;
                }
                if(IO.In(rcvyindct)) {
                    Chk.ViewAlarm("Rear Conveyor In Zone Detection Error."+io(rcvyindct));
                    return;
                }
                if(IO.In(fcvyoutdct)) {
                    Chk.ViewAlarm("Unloading Zone Detection Error."+io(fcvyoutdct));
                    return;
                }
                if(IO.In(rcvyoutdct)) {
                    Chk.ViewAlarm("Rear Unloading Zone Detection Error."+io(rcvyoutdct));
                    return;
                }
                m_nHomePNo[DC] = 1;
            }
            nInitPNo[FRNT] = 20;
        }
        break;
    case 20:
        if(m_nHomePNo[DC] == 0) {
            AddInitMsg("Conveyor Part Initialize End.");
            nInitPNo[FRNT] = 0;
        }
        break;
    }

    static clock_t tRear;
    switch(nInitPNo[REAR]) {
    case 1:
        AddInitMsg("Rear Conveyor Part Initialize Start.");
        IO.Off(RULPUSHDN);
        IO.Off(RULPUSHFWD);
        tRear = clock();
        nInitPNo[REAR] = 5;
        break;
    case 5:
        if(IO.In(rulpushbwd) && IO.In(rulpushup)) {
            if(!IO.In(rcvyinspdct)) {
                IO.Off(RINSPSTPRDN);
                tRear = clock();
                nInitPNo[REAR] = 10;
            }
            else nInitPNo[REAR] = 15;
        }
        else if(Ext.CheckDelay(tRear, sys.eng.nCylTimeErr)) {
            if(!IO.In(rulpushbwd))
                Chk.ViewAlarm("Rear Unloader Conveyor Pusher Off Error."+io(rulpushbwd)+io(RULPUSHFWD));
            else Chk.ViewAlarm("Rear Unloader Conveyor Pusher Up Error."+io(rulpushup)+io(RULPUSHDN));
            return;
        }
        break;
    case 10:
        if(IO.In(rinspstprup)) {
            IO.On(RINSPCVYFWD);
            tRear = clock();
            nInitPNo[REAR] = 15;
        }
        else if(Ext.CheckDelay(tRear, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Rear Inspection Stopper Up Error."+io(rinspstprup)+io(RINSPSTPRDN));
            return;
        }
        break;
    case 15:
        if(Ext.CheckDelay(tFrnt, (sys.eng.nCvyTimeErr*1000)/3)) {
            IO.Off(RINSPCVYFWD);
            AddInitMsg("Rear Conveyor Part Initialize End.");
            nInitPNo[REAR] = 0;
        }
        break;
    }

    static clock_t tUl;
    switch(nInitPNo[ULR]) {
    case 1:
        AddInitMsg("Unloader Part Initialization Start.");
        AddInitMsg("Unloader Saved Position:+ "+Ext.FloatToStr(run.dUlZPos)+"mm");
        IO.Off(FULPUSHFWD);
        IO.Off(RULPUSHFWD);
        tUl = clock();
        nInitPNo[ULR] = 2;
        break;
    case 2:
        if(IO.In(fcvyoutdct)) {
            Chk.ViewAlarm("Unloading Zone Detection Error."+io(fcvyoutdct));
            return;
        }
        if(IO.In(fulpushbwd)) {
            //2017.02.20 sjh 21:35:02
            //if( sys.fac.nEquipType == HTYPE_1RAIL)
            if( (sys.fac.nEquipType == VTYPE_2RAIL && sys.fac.bNoUseRearRail == true) || (sys.fac.nEquipType == HTYPE_1RAIL)  )
                nInitPNo[ULR] = 5;
        }
        else if(Ext.CheckDelay(tUl, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Unloader Pusher Backward Error."+io(fulpushbwd));
            return;
        }
        if(sys.fac.nEquipType == VTYPE_2RAIL && !sys.fac.bNoUseRearRail) {
            if(IO.In(rcvyoutdct)) {
                Chk.ViewAlarm("Rear Unloading Zone Detection Error."+io(rcvyoutdct));
                return;
            }
            if(IO.In(fulpushbwd) && IO.In(rulpushbwd)) {
                m_nHomePNo[UL] = 1;
                nInitPNo[ULR] = 100;
            }
            else if(Ext.CheckDelay(tUl, sys.eng.nCylTimeErr)) {
                Chk.ViewAlarm("Rear Unloader Pusher Backward Error."+io(rulpushbwd));
                return;
            }
        }
        break;
    case 5:
        if(IO.In(ulmgzldout)) {
            IO.On(ULLDCVYBWD);
            nInitPNo[ULR] = 10;
        }
        else nInitPNo[ULR] = 20;
        break;
    case 10:
        if(Ext.CheckDelay(tUl, mdl.ul.nLdOutSensDly)) {
            IO.Off(ULLDCVYRUN);
            nInitPNo[ULR] = 20;
        }
        break;
    case 20:
        if(IO.In(ulgripmgzgood)) {
            IO.On(ULMGZGRIP);
            tUl = clock();
            nInitPNo[ULR] = 25;
        }
        else nInitPNo[ULR] = 30;
        break;
    case 25:
        if(IO.In(ulmgzgripon)) {
            tUl = clock();
            nInitPNo[ULR] = 30;
        }
        else if(Ext.CheckDelay(tUl, sys.eng.nCylTimeErr)) {
            Chk.ViewAlarm("Unloader Gripper On Error."+io(ulmgzgripon)+io(ULMGZGRIP));
            return;
        }
        break;
    case 30:
        if(Ext.CheckDelay(tUl, DLY_SENS)) {
            m_nHomePNo[UY] = 1;
            m_nHomePNo[UZ] = 1;
            nInitPNo[ULR] = 35;
        }
        break;
    case 35:
        if(m_nHomePNo[UY] == 0 && m_nHomePNo[UZ] == 0 && MB.AxisDone(UZ)) {
            m_nHomePNo[UZ] = -1;
            if(IO.In(ulmgzgripon) && IO.In(ulgripmgzgood)) {
                if((run.dUlZPos < mdl.ul.posGripOnCvy.z+20. && run.dUlZPos > mdl.ul.posGripOnCvy.z-20.) ||
                   (run.dUlZPos < mdl.ul.posGripOnPre.z+20. && run.dUlZPos > mdl.ul.posGripOnPre.z-20.) ||
                   (run.dUlZPos < mdl.ul.posGripOff.z+20. && run.dUlZPos > mdl.ul.posGripOff.z-20.)) {
                    MB.MoveTo(UZ, MB.GetPos(UZ)+25.);
                }
            }
            nInitPNo[ULR] = 40;
        }
        break;
    case 40:
        if(MB.AxisDone(UZ)) {
            m_nHomePNo[UY] = 6;
            nInitPNo[ULR] = 45;
        }
        break;
    case 45:
        if(m_nHomePNo[UY] == 0) {
            m_nHomePNo[UZ] = 6;
            nInitPNo[ULR] = 100;
        }
        break;
    case 100:
        if(m_nHomePNo[UY] == 0 && m_nHomePNo[UZ] == 0) {
            nInitPNo[ULR] = 0;
            AddInitMsg("Unloader Part Initialization End.");            
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TInitProcess::HomeProcess(int nAxis)
{
    static clock_t tHome[AXES];
    static clock_t tDly[AXES];

    if(m_nHomePNo[nAxis] == 0 || Chk.m_bMainErrEvent) {
        if(Chk.m_bMainErrEvent && m_nHomePNo[nAxis] != 0) {
            m_nHomePNo[nAxis] = 0;
            MB.MoveStop(nAxis);
        }
        tHome[nAxis] = clock();
        return;
    }

    double dDist = fabs(sys.fac.mtr[nAxis].dPSftLmt-sys.fac.mtr[nAxis].dMSftLmt);
    int nHomeTimeOut = (int)((dDist/sys.eng.mtr[nAxis].nHomeSpd)*1000)+30000;

    if(Ext.CheckDelay(tHome[nAxis], nHomeTimeOut)) {
        Chk.ViewAlarm(IntToStr(nAxis)+"Home Searching Time Error.");
        return;
    }

    AnsiString sAxisName = Ext.m_pLngList[STR_AXIS]->Strings[nAxis];
    switch(m_nHomePNo[nAxis]) {
    case 1://Home Initialize
        m_bHomeDone[nAxis] = false;
        AddInitMsg(sAxisName+" Origin Searching Start.");
        MB.MoveStop(nAxis);
        tDly[nAxis] = clock();
        m_nHomePNo[nAxis] = 7;
        break;
    case 7:
        if(Ext.CheckDelay(tDly[nAxis], 300)) {
            if(MB.IsServoAlarm(nAxis)) {
                MB.ServoPower(nAxis, OFF);
                tDly[nAxis] = clock();
                m_nHomePNo[nAxis] = 2;
            }
            else m_nHomePNo[nAxis] = 4;
        }
        break;
    case 2:
        if(Ext.CheckDelay(tDly[nAxis], 300)) {
            MB.ServoReset(nAxis, ON);
            tDly[nAxis] = clock();
            m_nHomePNo[nAxis] = 3;
        }
        break;
    case 3:
        if(Ext.CheckDelay(tDly[nAxis], 3000)) {
            MB.ServoReset(nAxis, OFF);
            tDly[nAxis] = clock();
            m_nHomePNo[nAxis] = 4;
        }
        break;
     case 4:
        if(Ext.CheckDelay(tDly[nAxis], 300)) {
            MB.ServoPower(nAxis, ON);
            tDly[nAxis] = clock();
            m_nHomePNo[nAxis] = 5;
        }
        break;
     case 5:
        if(Ext.CheckDelay(tDly[nAxis], 1000)) {
            if((nAxis == UY || nAxis == UZ) && m_nInitPNo != 0 && sys.fac.nEquipType==HTYPE_1RAIL) {
                m_nHomePNo[nAxis] = 0;
                return;
            }
            else m_nHomePNo[nAxis] = 6;
        }
        break;
     case 6:
        MB.DoHomeSearch(nAxis);
        m_nHomePNo[nAxis] = 10;
        break;
    case 10:
        if(MB.AxisDone(nAxis)) {
            tDly[nAxis] = clock();
            m_nHomePNo[nAxis] = 11;
        }
        break;
    case 11:
        if(Ext.CheckDelay(tDly[nAxis], 1000)) {
            //MB.MoveStop(nAxis);
            m_nHomePNo[nAxis] = 15;
        }
        break;
    case 15:
        if(MB.AxisDone(nAxis)) {
            MB.SetPosZero(nAxis);
            m_nHomePNo[nAxis] = 16;
        }
        break;
    case 16:
        if(MB.AxisDone(nAxis)) {
            //MB.MoveTo(nAxis, sys.fac.mtr[nAxis].dHomeOfst);
            m_nHomePNo[nAxis] = 20;
        }
        break;
    case 20:
        if(MB.AxisDone(nAxis)) {
            m_nHomePNo[nAxis] = 0;
            MB.SetPosZero(nAxis);
            AddInitMsg(sAxisName+" Origin Search Completed.");
            MsgDlg->Close();
            m_bHomeDone[nAxis] = true;
            if(nAxis == UZ) {
                run.dUlZPos = MB.GetPos(UZ);
                Data.SaveRunData();
            }
            if(m_nInitPNo != 0) {
            }
        }
        break;
    }
}
//---------------------------------------------------------------------------



