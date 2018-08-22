//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "MotionBase.h"
#include "Main.h"
#include "ComidasLX.h"
#include "InitProcess.h"
#include "RunChk.h"
#include "Msg.h"
#include "Init.h"
#include "Jog.h"
#include "Maint.h"
#include "WorkProcess.h"
#include "MeasProcess.h"
#include "Extern.h"
#include "IOPort.h"
#include "WorkSetup.h"
#include "SysSetup.h"
#include "DataClass.h"
#include "Debug.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TMotionBase MB;
//---------------------------------------------------------------------------
__fastcall TMotionBase::TMotionBase()
{
    mbd.hdl[0] = mbd.hdl[1] = NULL;
}
//---------------------------------------------------------------------------
__fastcall TMotionBase::~TMotionBase()
{
    for(int ax=0; ax<AXES; ax++)
        ServoPower(ax, OFF);

    try {
        if(mbd.hdl[0] != NULL) COMILX_UnloadDevice(mbd.hdl[0]);
        if(mbd.hdl[1] != NULL) COMILX_UnloadDevice(mbd.hdl[1]);

        COMILX_UnloadDll();
    } catch(...) {}
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::InitMotionBoard()
{
    MotionBdReset();

    enum {HW_IX, HW_IY, HW_DC=4, HW_UL=5, HW_UY=5, HW_UZ=7};

    m_nHWAxis[IX]      = HW_IX;
    m_nHWAxis[IY]      = HW_IY;
    m_nHWAxis[DC]      = HW_DC;
    m_nHWAxis[UY]      = HW_UY;
    m_nHWAxis[UL]      = HW_UL;
    m_nHWAxis[UZ]      = HW_UZ;

    if(!COMILX_LoadDll()) {
        Application->MessageBox("Comidas.dll load failure.", "Error.", MB_OK);
        return false;
    }

    AnsiString sPathOfThisApp, sTemp;
    if(sys.fac.bNoMachine)
        sPathOfThisApp = ExtractFilePath(Application->ExeName);
    else sPathOfThisApp = MAIN_PATH;

    //첫 번째 보드 환경 설정
    if(mbd.hdl[0] == NULL) {
        mbd.hdl[0] = COMILX_LoadDevice(COMI_LX508, 0);
        if(mbd.hdl[0] == INVALID_HANDLE_VALUE) {
            Application->MessageBox("Can't load COMI-LX508 device#1.", "Error.", MB_OK);
            mbd.hdl[0] = NULL;
            return false;
        }
    }
    COMILX_MC_Reset(mbd.hdl[0]);
    if(sys.fac.bNoMachine)
        sTemp = "XComiBoard#1.cme";
    else if(sys.fac.nEquipType ==HTYPE_1RAIL)
        sTemp = "ZeusInsp_S.cme";
    else sTemp = "ZeusInsp_D.cme";
    sTemp = sPathOfThisApp+sTemp;
    if(COMILX_MC_InitFromFile(mbd.hdl[0], sTemp.c_str()) < 0) {
        Application->MessageBox(AnsiString(sTemp+" config file loading failure.").c_str(), "Error.", MB_OK);
        return false;
    }

    HANDLE hBd; int nCh;
    for(int ax=0; ax<AXES; ax++) {
        if(GetHdl(ax, hBd, nCh)) {
            //COMILX_MC_ResetAxis(hBd, nCh);
            COMILX_MC_DisableSoftLimit(hBd, nCh);
            int nHomeLvl = 1;
            COMILX_MC_SetHomeConfig(hBd, nCh, 1, nHomeLvl, 0, 0, false); //홈센서 레벨 설정
            /*if(ax == IX || ax == IY) {
                if(ax == IX) {
                    long nCmpPulseWidth=1500;  // 1000*1.5us = 1500us
                    COMILX_MC_SetMioCfgCMP(hBd, nCh, nCmpPulseWidth, 0);
                }
                COMILX_MC_SetMioProperty(hBd, nCh, cmMPID_EN_ARDP, TRUE);
            }*/
        }
    }
    /*
//Step Motor
    if(IsServoOn(WD) || IsServoOn(UVX) || IsServoOn(UVY)) {
        if(IsServoOn(WD)) ServoPower(WD, OFF);
        if(IsServoOn(UVX)) ServoPower(UVX, OFF);
        if(IsServoOn(UVY)) ServoPower(UVY, OFF);
        Sleep(1000);
    }
    for(int ax=0; ax<AXES; ax++) {
        if(ax==WD || ax==UVX || ax==UVY) {
            if(GetHdl(ax, hBd, nCh)) {
                COMILX_MC_SetOutputMode(hBd, nCh, 0);
                ResetInposition(ax);
            }
        }
    }
    */

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::MotionBdReset()
{
    if(mbd.hdl[0] != NULL) {
        COMILX_MC_Reset(mbd.hdl[0]);
        mbd.hdl[0] = NULL;
    }
    if(mbd.hdl[1] != NULL) {
        COMILX_MC_Reset(mbd.hdl[1]);
        mbd.hdl[1] = NULL;
    }
}
//---------------------------------------------------------------------------
bool  __fastcall TMotionBase::GetHdl(int nAxis, HANDLE &hBd, int &nCh)
{
    if(nAxis < 0 || nAxis >= AXES) return false;

    if(sys.fac.nEquipType == HTYPE_1RAIL) {
        if(nAxis == DC)
            return false;
    } else {
        if(nAxis == UZ)
            return false;
        if(nAxis == DC && sys.fac.bNoUseRearRail)
            return false;
        if(nAxis == UL && sys.fac.bNoUseUnloader)
            return false;        
    }

    if(mbd.hdl[m_nHWAxis[nAxis]/8] == NULL) return false;
    hBd = mbd.hdl[m_nHWAxis[nAxis]/8];
    nCh = m_nHWAxis[nAxis]%8;
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::ResetInposition(int nAxis)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh)) return;

    COMILX_MC_SetMioCfgINP(hBd, nCh, true, 1);
    Sleep(30);
    COMILX_MC_SetMioCfgINP(hBd, nCh, true, 0);
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::IsServoAlarm(int nAxis)
{
    if(sys.fac.bNoMachine)
        return false;

    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        ULONG dwMioStates = COMILX_MC_GetMioStatus(hBd, nCh);
        return (dwMioStates & 0x02);
    }
    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::PosLimit(int nAxis)
{
    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        ULONG dwMioStates = COMILX_MC_GetMioStatus(hBd, nCh);
        bool b = dwMioStates & 0x04;
        return (dwMioStates & 0x04);
    }
    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::NegLimit(int nAxis)
{
    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        ULONG dwMioStates = COMILX_MC_GetMioStatus(hBd, nCh);
        return (dwMioStates & 0x08);
    }
    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::HomeSensor(int nAxis)
{
    if(sys.fac.bNoMachine)
        return (AxisDone(nAxis) && IsCrntPos(nAxis, 0.));

    HANDLE hBd; int nCh; bool bRtn;
    if(GetHdl(nAxis, hBd, nCh)) {
        ULONG dwMioStates = COMILX_MC_GetMioStatus(hBd, nCh);
        bRtn = dwMioStates & 0x10;
        return (bRtn && AxisDone(nAxis));
    }
    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::IsServoOn(int nAxis)
{
    if(sys.fac.bNoMachine)
        return true;

    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh))
        return true;

    bool bSvrOn = COMILX_MC_GetServoOn(hBd, nCh);

    return bSvrOn;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::ServoReset(int nAxis, bool bOn)
{
    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        nCh = nCh+(nCh/2);
        COMILX_DO_PutOne(hBd, nCh, bOn);

        Init.m_bDone = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::ServoPower(int nAxis, bool bOn)
{
    if(bOn == OFF) {
        if(!AxisDone(nAxis)) {
            MoveStop(nAxis);
            Sleep(100);
        }
    }
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh))
        return;

    COMILX_MC_ServoOn(hBd, nCh, bOn);

    COMILX_MC_SetCount_C(hBd, nCh, GetPulse(nAxis));
    COMILX_MC_SetCount_A(hBd, nCh, GetPulse(nAxis));
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::SetAxisSWLimit(int nAxis, double dMinusLmtmm, double dPlusLmtmm)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh)) return;

    COMILX_MC_SetSoftLimit(hBd, nCh, CalPulse(nAxis, dPlusLmtmm),
        CalPulse(nAxis, dMinusLmtmm)); // 소프트웨어적인 Limit를

    COMILX_MC_EnableSoftLimit(hBd, nCh);
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::SetPosZero(int nAxis, long nPulse)
{
    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        COMILX_MC_SetCount_C(hBd, nCh, 0);
        COMILX_MC_SetCount_A(hBd, nCh, 0);
        COMILX_MC_SetSoftLimit(hBd, nCh, CalPulse(nAxis, sys.fac.mtr[nAxis].dPSftLmt),
            CalPulse(nAxis, sys.fac.mtr[nAxis].dMSftLmt)); // 소프트웨어적인 Limit를 설정합니다.
        if(Init.m_nHomePNo[nAxis] == 0) 
            COMILX_MC_EnableSoftLimit(hBd, nCh); // 소프트웨어적인 Limit의 적용을 Enable시킵니다.
        else COMILX_MC_DisableSoftLimit(hBd, nCh);
    }
}
//---------------------------------------------------------------------------
long __fastcall TMotionBase::GetPulse(int nAxis, bool bCmd)
{
    HANDLE hBd; int nCh;
    if(GetHdl(nAxis, hBd, nCh)) {
        if(sys.fac.bNoMachine || sys.fac.bDebugMode)
            return COMILX_MC_GetPosition_C(hBd, nCh);
        return COMILX_MC_GetPosition_A(hBd, nCh);
    }

    return -1;
}
//---------------------------------------------------------------------------
double __fastcall TMotionBase::GetPos(int nAxis, bool bCmd)
{
	double dPos = double(GetPulse(nAxis, bCmd));
    dPos/=(sys.fac.mtr[nAxis].dPulsePermm+ZERO);
    return dPos;
}
//---------------------------------------------------------------------------
double __fastcall TMotionBase::GetPosInc(int nAxis)
{
	return GetPos(nAxis, false)-move.dBasePos[nAxis];
}
//---------------------------------------------------------------------------
double __fastcall TMotionBase::CalPulse(int nAxis, double dmm)
{
    double dPulse = dmm*sys.fac.mtr[nAxis].dPulsePermm;
    return dPulse;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::AxisDone(int nAxis)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh))
        return true;

    return COMILX_MC_Done(hBd, nCh);
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::DoHomeSearch(int nAxis)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh) || !Chk.IsAxisSafety(nAxis))
        return;

    COMILX_MC_DisableSoftLimit(hBd, nCh); // 소프트웨어적인 Limit의 적용을 disable시킵니다.

    double dAcc = CalPulse(nAxis, sys.eng.mtr[nAxis].nHomeSpd)*(1000./50.);
    double dDec = CalPulse(nAxis, sys.eng.mtr[nAxis].nHomeSpd)*(1000./5.); //가속시간 100msec

    COMILX_MC_SetSpeedMode(hBd, nCh, 2);
    COMILX_MC_SetSpeed(hBd, nCh, 1,  CalPulse(nAxis, sys.eng.mtr[nAxis].nHomeSpd));
    COMILX_MC_SetAccel(hBd, nCh, dAcc, dDec);
    COMILX_MC_SetScurve(hBd, nCh, 0, 0);

    COMILX_MC_SetMioCfgERC(hBd, nCh, 0, 0); // ERC 신호의 입력 로직(Logic) 및 ON time을 설정합니다.
    int nHomeMode = 4;
    int nHomeLvl = 1;
    COMILX_MC_SetHomeConfig(hBd, nCh, nHomeMode, nHomeLvl, 0, 0, false); // 복귀 작업을 수행하기 위한 여러가지 환경설정을 수행합니다.
    double dRvsVel, dEscapeDist;
    dRvsVel = 10., dEscapeDist = 5.;
    COMILX_MC_HomeMoveAuto(hBd, nCh, 0, CalPulse(nAxis, dRvsVel), CalPulse(nAxis, dEscapeDist));

    double dDist = fabs(sys.fac.mtr[nAxis].dPSftLmt-sys.fac.mtr[nAxis].dMSftLmt);
    move.nTimeOut[nAxis] = ((int)(dDist/sys.eng.mtr[nAxis].nHomeSpd)*1000)+MTR_TIMEOUT*3;
    move.tTime[nAxis] = clock();
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::ComiMove(int nAxis, double dPulse, double dVel, int nAcc, bool bWhile)
{
    if((Work.m_nStatus == RSTOP &&  !AxisDone(nAxis)) || !Chk.IsAxisSafety(nAxis))
        return false;

    if(Init.m_nHomePNo[nAxis] == 0) {
        if(!InitCheck())
            return false;
    }

    //double dmm = dPulse/sys.fac.mtr[nAxis].dPulsePermm;
    if(dPulse < CalPulse(nAxis, sys.fac.mtr[nAxis].dMSftLmt)) {
        Chk.ViewAlarm(IntToStr(nAxis)+"S/W Minus Limit Error.");
        return false;
    }
    if(dPulse > CalPulse(nAxis, sys.fac.mtr[nAxis].dPSftLmt)) {
        Chk.ViewAlarm(IntToStr(nAxis)+"S/W Plus Limit Error.");
        return false;
    }

    if(dVel <= 0) {
        Chk.ViewAlarm(IntToStr(nAxis)+"Invalid Speed Error.");
        return false;
    }
    if(nAcc <= 0 || nAcc > 2000) {
        Chk.ViewAlarm(IntToStr(nAxis)+"Invalid Accel Error.");
        return false;
    }

    double dAcc = dVel*(1000.0/nAcc); //가속시간 100msec
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh))
        return true;

    COMILX_MC_SetSpeedMode(hBd, nCh, 1);
    COMILX_MC_SetSpeed(hBd, nCh, 1,  dVel);
    COMILX_MC_SetAccel(hBd, nCh, dAcc, dAcc);
    //double dSCAcc = dVel*(sys.eng.mtr[nAxis].nSCurveRate/100.0);
    COMILX_MC_SetScurve(hBd, nCh, 0, 0);
    COMILX_MC_StartMoveTo(hBd, nCh, dPulse);

    double dDist = fabs(fabs(GetPulse(nAxis))-dPulse);
    move.nTimeOut[nAxis] = (int)((dDist/dVel)*1000)+MTR_TIMEOUT;
    move.tTime[nAxis] = clock();

    move.dCmdPos[nAxis] = dPulse/sys.fac.mtr[nAxis].dPulsePermm;

    if(bWhile) {
        MsgDlg->IsStop(true);
        while(!AxisDone(nAxis)) {
            if(Chk.m_bMainErrEvent || MsgDlg->IsStop())
                return false;
            Ext.DoEvents();
        }
    }

    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::MoveTo(int nAxis, double dmm, bool bWhile, int nSpd)
{
    double dVel;
    int nAcc = sys.eng.mtr[nAxis].nAcc;
    if(Init.m_nHomePNo[nAxis] != 0)
        dVel = sys.eng.mtr[nAxis].nHomeSpd;
    else dVel = (nSpd>0?nSpd:sys.eng.mtr[nAxis].nSpd);

    if(!ComiMove(nAxis, CalPulse(nAxis, dmm), CalPulse(nAxis, dVel), nAcc, bWhile))
        return false;

    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::XYMoveTo(int nAxis, Coord crdmm, bool bWhile, int nSpd)
{
    int nXAxis = IX;
    int nYAxis = IY;

    if(sys.fac.bNoUseXYInterpolation ||
        (sys.fac.mtr[nXAxis].dPulsePermm != sys.fac.mtr[nYAxis].dPulsePermm)) {
        bool bXRtn = MoveTo(nXAxis, crdmm.x, bWhile, nSpd);
        bool bYRtn = MoveTo(nYAxis, crdmm.y, bWhile, nSpd);
        return (bXRtn && bYRtn);
    }

    Coord crdPulse;
    crdPulse.x = crdmm.x*sys.fac.mtr[nXAxis].dPulsePermm;
    crdPulse.y = crdmm.y*sys.fac.mtr[nYAxis].dPulsePermm;

    double dVel = (nSpd>0?nSpd:sys.eng.mtr[nAxis].nSpd);
    int nAcc = sys.eng.mtr[nAxis].nAcc;

    dVel*=sys.fac.mtr[nXAxis].dPulsePermm;
    m_distHeadMove.x = fabs(GetPos(nXAxis)-crdmm.x);
    m_distHeadMove.y = fabs(GetPos(nYAxis)-crdmm.y);

    if(WorkSetupForm->Visible || SysSetupForm->Visible) {
        //if(nSpd == 0 && sys.opr.bUseSafetySpd)
        //    dVel*=(sys.opr.nSafetySpdRate/100.);
    }

    return ComiXYMove(nXAxis, crdPulse, dVel, nAcc, bWhile);
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::ComiXYMove(int nAxis, Coord crdPulse, double dVel, double dAcc, bool bWhile)
{
    int nXAxis = IX;
    int nYAxis = IY;

    if(Work.m_nStatus == RSTOP && (!AxisDone(nXAxis) || !AxisDone(nYAxis)))
        return false;

    if(Init.m_nHomePNo[nXAxis] == 0 && Init.m_nHomePNo[nYAxis] == 0) {
        if(!InitCheck())
            return false;
    }

    if(!Chk.IsAxisSafety(nXAxis) || !Chk.IsAxisSafety(nYAxis))
        return false;

    if(crdPulse.x < CalPulse(nXAxis, sys.fac.mtr[nXAxis].dMSftLmt)) {
        Chk.ViewAlarm(IntToStr(nXAxis)+"S/W Minus Limit Error.");
        return false;
    }
    if(crdPulse.x > CalPulse(nXAxis, sys.fac.mtr[nXAxis].dPSftLmt)) {
        Chk.ViewAlarm(IntToStr(nXAxis)+"S/W Plus Limit Error.");
        return false;
    }
    if(crdPulse.y < CalPulse(nYAxis, sys.fac.mtr[nYAxis].dMSftLmt)) {
        Chk.ViewAlarm(IntToStr(nYAxis)+"S/W Minus Limit Error.");
        return false;
    }
    if(crdPulse.y > CalPulse(nYAxis, sys.fac.mtr[nYAxis].dPSftLmt)) {
        Chk.ViewAlarm(IntToStr(nYAxis)+"S/W Plus Limit Error.");
        return false;
    }

    if(dVel <= 0) {
        Chk.ViewAlarm(IntToStr(nAxis)+"Invalid Speed Error.");
        return false;
    }
    if(dAcc <= 0 || dAcc > 2000) {
        Chk.ViewAlarm(IntToStr(nAxis)+"Invalid Accel Error.");
        return false;
    }

    HANDLE hBd; int nXCH, nYCH;
    if(!GetHdl(nXAxis, hBd, nXCH) || !GetHdl(nYAxis, hBd, nYCH))
        return false;
    
    dAcc = dVel*(1000./dAcc);
    double dPosList[2] = {crdPulse.x, crdPulse.y};
    int nMap = 2;
    COMILX_MC_MapAxes(hBd, nMap, int(pow(2.,(double)nXCH))|int(pow(2.,(double)nYCH)));
    COMILX_MC_SetSpeedModeMx(hBd, nMap, 1);
    COMILX_MC_SetSpeedMx(hBd, nMap, dVel, dAcc);
    COMILX_MC_StartLineTo(hBd, nMap, dPosList);

    Coord crdDist;
    crdDist.x = fabs(GetPulse(nXAxis)-crdPulse.x);
    crdDist.y = fabs(GetPulse(nYAxis)-crdPulse.y);

    if(crdDist.x > crdDist.y) {
        move.nTimeOut[nXAxis] = (int)((crdDist.x/dVel)*1000)+MTR_TIMEOUT;
        move.nTimeOut[nYAxis] = move.nTimeOut[nXAxis];
    } else {
        move.nTimeOut[nYAxis] = (int)((crdDist.y/dVel)*1000)+MTR_TIMEOUT;
        move.nTimeOut[nXAxis] = move.nTimeOut[nYAxis];
    }
    move.tTime[nXAxis] = clock();
    move.tTime[nYAxis] = clock();

    move.dCmdPos[nXAxis] = crdPulse.x/sys.fac.mtr[nXAxis].dPulsePermm;
    move.dCmdPos[nYAxis] = crdPulse.y/sys.fac.mtr[nYAxis].dPulsePermm;

    if(bWhile) {
        while(!AxisDone(nXAxis) || !AxisDone(nYAxis)) {
            if(Chk.m_bMainErrEvent)
                return false;
            Ext.DoEvents();
        }
    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::JogMove(int nAxis, int nDir)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh))
        return;

    if(nDir == MSTOP)
        MoveStop(nAxis);
    else {
        if(!Chk.IsAxisSafety(nAxis, true)) return;

        move.bJog = true;

        double dVel = sys.eng.mtr[nAxis].nJogSpd*sys.fac.mtr[nAxis].dPulsePermm;
        if(JogForm->Visible) {
            if(JogForm->JogSpdTrackBar->Position != 0)
                dVel*=(JogForm->JogSpdTrackBar->Position/100.);
        }

        double dAcc = dVel*(1000./sys.eng.mtr[nAxis].nAcc);

        COMILX_MC_SetSpeedMode(hBd, nCh, 2); //S_Curve
        COMILX_MC_SetSpeed(hBd, nCh, 1,  dVel);
        COMILX_MC_SetAccel(hBd, nCh, dAcc, dAcc);
        COMILX_MC_SetScurve(hBd, nCh, 0, 0);
        COMILX_MC_StartVMove(hBd, nCh, nDir);

        double dDist = fabs(sys.fac.mtr[nAxis].dPSftLmt-sys.fac.mtr[nAxis].dMSftLmt);
        move.nTimeOut[nAxis] = (int)((dDist/sys.eng.mtr[nAxis].nJogSpd)*1000.)+MTR_TIMEOUT*2;
        move.tTime[nAxis] = clock();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::VelMove(int nAxis, int nDir, double dSpd, int nAcc)
{
    HANDLE hBd; int nCh;
    if(!GetHdl(nAxis, hBd, nCh)) return;

    if(nDir == MSTOP) MoveStop(nAxis);
    else {
        if(!Chk.IsAxisSafety(nAxis))
            return;
        double dVel = CalPulse(nAxis, dSpd);
        double dAcc = dVel*(1000.0/nAcc);

        if(JogForm->Visible) {// && !Chk.m_bAutoRun) {
            if(JogForm->JogSpdTrackBar->Position > 0)
                dVel*=(JogForm->JogSpdTrackBar->Position/100.);
        }

        COMILX_MC_SetSpeedMode(hBd, nCh, 2);
        COMILX_MC_SetSpeed(hBd, nCh, 1,  dVel);
        COMILX_MC_SetAccel(hBd, nCh, dAcc, dAcc);
        COMILX_MC_StartVMove(hBd, nCh, nDir);

        double dDist = fabs(sys.fac.mtr[nAxis].dPSftLmt-sys.fac.mtr[nAxis].dMSftLmt);
        move.nTimeOut[nAxis] = (int)((dDist/dSpd)*1000)+MTR_TIMEOUT*2;
        move.tTime[nAxis] = clock();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::MoveStop(int nAxis)
{
    HANDLE hBd; int nCh;
     if(!GetHdl(nAxis, hBd, nCh))
        return;

    COMILX_MC_EmgStop(hBd, nCh);
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::IsNearlyPos(int nAxis, double dPos, double dBand, bool bDoneChk)
{
    if(sys.fac.nEquipType == HTYPE_1RAIL && nAxis == DC)
        return true;

    double dMin, dMax, dCrntPos;
    bool bInPos;

    dBand = (dBand<DEAD_BAND?DEAD_BAND:dBand);

    dCrntPos = fabs(GetPos(nAxis));
    dMin = fabs(dPos)-dBand;
    dMax = fabs(dPos)+dBand;

   	if(dMin <= dCrntPos && dMax >= dCrntPos)
        bInPos = true;
    else bInPos = false;

    if(bDoneChk)
        return (AxisDone(nAxis) && bInPos);
    return bInPos;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::IsCrntPos(int nAxis, double dPos, double dBand, bool bDoneChk)
{
    return IsNearlyPos(nAxis, dPos, dBand, bDoneChk);
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::IsCrntPos(int nAxis, Coord pos, double dBand, bool bDoneChk)
{
    if(nAxis == IX || nAxis == IY)
        return (IsCrntPos(IX, pos.x, dBand, bDoneChk) && IsCrntPos(IY, pos.y, dBand, bDoneChk));
    else if(nAxis == UL || nAxis == UY)
        return (IsCrntPos(UL, pos.z, dBand, bDoneChk) && IsCrntPos(UY, pos.y, dBand, bDoneChk));

    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TMotionBase::InitCheck()
{
    if(sys.fac.bNoMachine)
        return true;

    if(!Init.m_bDone) {
        int nRtn = MsgDlg->ShowBox("System Initialization Start?", MMB_YESNO|MMI_INFO, 0, STR_MSG);
        if(nRtn == MID_YES) {
            Init.m_bAuto = true;
            InitForm->ShowModal();
            if(Init.m_bDone)
                return true;
            else return false;
        }
        else return false;
    }
    else return true;
}
//---------------------------------------------------------------------------
Coord __fastcall TMotionBase::GetHeadPos(int nPosKind, int nTarget)
{
    Coord posMove[2] = {{0., 0.}, {0., 0.}};
    return posMove[0];
}
//---------------------------------------------------------------------------
TPoint __fastcall TMotionBase::GetHeadHomeDir()
{
    TPoint ptDir;

    ptDir.x = 1;
    ptDir.y = 1;

    return ptDir;
}
//---------------------------------------------------------------------------
Coord __fastcall TMotionBase::GetMgzSlotPos(int nAxis, int nMgz, int nSlot)
{
    double dSlotPitch = 0.;
    Coord posSlot = {0., 0., 0., 0.};

    if(sys.fac.nEquipType == HTYPE_1RAIL) {
        if(nAxis == UZ) {
            if(mdl.ul.nMgzSlotNum > 1)
                dSlotPitch = fabs(mdl.ul.posMgzStart.z-mdl.ul.posMgzEnd.z)/(mdl.ul.nMgzSlotNum-1);
            if(mdl.ul.posMgzStart.z > mdl.ul.posMgzEnd.z)
                posSlot.z = mdl.ul.posMgzStart.z-(dSlotPitch*nSlot);
            else posSlot.z = mdl.ul.posMgzStart.z+(dSlotPitch*nSlot);
            posSlot.y = mdl.ul.posMgzStart.y;
        }
    } else {
        if(nAxis == UL) {
            if(mdl.ul.nMgzSlotNum > 1)
                dSlotPitch = fabs(mdl.ul.dMgzStartPos[nMgz]-mdl.ul.dMgzEndPos[nMgz])/(mdl.ul.nMgzSlotNum-1);
            if(mdl.ul.dMgzStartPos[nMgz] > mdl.ul.dMgzEndPos[nMgz])
                posSlot.z = mdl.ul.dMgzStartPos[nMgz]-(dSlotPitch*nSlot);
            else posSlot.z = mdl.ul.dMgzStartPos[nMgz]+(dSlotPitch*nSlot);
        }
    }

    return posSlot;
}
//---------------------------------------------------------------------------
int __fastcall TMotionBase::GetMgzSlotNum(int nAxis, int &nMgz, int &nSlot)
{
    if(sys.fac.nEquipType == HTYPE_1RAIL) {
        if(mdl.ul.nMgzSlotNum <= 1)
            return -1;

        for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
            Coord pos = GetMgzSlotPos(nAxis, -1, s);
            if(nAxis == UZ) {
                if(IsCrntPos(UZ, pos.z) && IsCrntPos(UY, pos.y))
                    return s;
            }
        }
    } else {
        if(&nMgz != NULL && &nSlot != NULL)
            nSlot = nMgz = -1;

        if(mdl.ul.nMgzSlotNum <= 1)
            return -1;

        double dSlotPos, dMin, dMax, dPos;
        dPos = GetPos(nAxis);

        int nCnt = 0;
        for(int m=0; m<MAX_MGZ; m++) {
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                dSlotPos = GetMgzSlotPos(nAxis, m, s).z;
                dMin = dSlotPos-DEAD_BAND;
                dMax = dSlotPos+DEAD_BAND;
                if(dMin <= dPos && dMax >= dPos && dSlotPos != 0.) {
                    if(&nMgz != NULL) nMgz = nCnt/mdl.ul.nMgzSlotNum;
                    if(&nSlot != NULL) nSlot = nCnt%mdl.ul.nMgzSlotNum;
                    return nCnt;
                }
                nCnt++;
            }
        }
    }

    return -1;
}
int __fastcall TMotionBase::GetCrntSlotNum(int nAxis)
{
    return GetMgzSlotNum(nAxis, NULL, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::CenterRotation(double *nx, double *ny, double tx, double ty,
        double cx, double cy, double q)
{
    double cosq = cos(q*(M_PI/180.));
    double sinq = sin(q*(M_PI/180.));

    //회전 중심점 c 가 원점 0 와 일치하도록 회전할 점 t 를 함께 평행이동
    tx-=cx, ty-=cy;
    //원점 0 에 대하여 회전할 점 t 를 d 각 만큼 회전
    *nx = tx * cosq - ty * sinq;
    *ny = ty * cosq + tx * sinq;

    //원점 0 가 원래의 회전 중심점 c 와 일치 하도록 점 n 과 함께 이동
    *nx+=cx;
    *ny+=cy;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::HTypeUlManMove(int nAxis, Coord pos)
{
    if(!AxisDone(UZ) || !AxisDone(UY)) return;

    if(IO.In(ulmgzgripon) && IO.In(ulgripmgzgood) && SysSetupForm->Visible) {
        if(MsgDlg->ShowBox("Caution!, Remove The Magazine In Gripper. Do You Want To Continue Moving?",
            MMI_WARNING|MMB_OKCANCEL, 0, STR_MSG) == MID_CANCEL) {
            return;
        }
    }

    Screen->Cursor = crHourGlass;
    if(MB.GetPos(UY) > 0.)
        MoveTo(UY, 0.);
    while(1) {
        if(Chk.m_bMainErrEvent) return;
        if(AxisDone(UY)) break;
        Ext.DoEvents(); Sleep(1);
        if(DebugForm->Visible) {
            DebugForm->DrawTimerTimer(NULL);
            DebugForm->Refresh();
        }
    }
    MoveTo(UZ, pos.z);
    while(1) {
        if(Chk.m_bMainErrEvent) return;
        if(AxisDone(UZ)) break;
        Ext.DoEvents(); Sleep(1);
        if(DebugForm->Visible) {
            DebugForm->DrawTimerTimer(NULL);
            DebugForm->Refresh();
        }
    }
    MoveTo(UY, pos.y);
    while(1) {
        if(Chk.m_bMainErrEvent) return;
        if(AxisDone(UY)) break;
        Ext.DoEvents(); Sleep(1);
        if(DebugForm->Visible) {
            DebugForm->DrawTimerTimer(NULL);
            DebugForm->Refresh();
        }
    }
    Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TMotionBase::ManualAxisMove(int nAxis, double dPos)
{
}
//---------------------------------------------------------------------------
Coord __fastcall TMotionBase::GetUnitPos(int nLane, int nUnitNo)
{
    Coord pos = {0., 0., 0., 0.};

    if(mdl.pcb.nUnitXCnt < 1 || mdl.pcb.nUnitYCnt < 1) {
        return pos;
    }

    int nXCnt = (mdl.pcb.nCntDir?nUnitNo/mdl.pcb.nUnitYCnt:nUnitNo%mdl.pcb.nUnitXCnt);
    int nYCnt = (mdl.pcb.nCntDir?nUnitNo%mdl.pcb.nUnitYCnt:nUnitNo/mdl.pcb.nUnitXCnt);
    int nXBlk = nXCnt/mdl.pcb.nUnitXCnt0;
    int nYBlk = nYCnt/mdl.pcb.nUnitYCnt0;

    pos.x = mdl.pcb.posFirstUnit[nLane].x+(mdl.pcb.dUnitXPitch*nXCnt)+
                (nXBlk*(mdl.pcb.dBlockXPitch-mdl.pcb.dUnitXPitch*mdl.pcb.nUnitXCnt0));
    pos.y = mdl.pcb.posFirstUnit[nLane].y+(mdl.pcb.dUnitYPitch*nYCnt)+
                (nYBlk*(mdl.pcb.dBlockYPitch-mdl.pcb.dUnitYPitch*mdl.pcb.nUnitYCnt0));

    if(mdl.pcb.nCntDir == XDIR) {
        if((nUnitNo/mdl.pcb.nUnitXCnt)%2) {
            pos.x+=mdl.pcb.ofstEvenCol.x;
            pos.y+=mdl.pcb.ofstEvenCol.y;
        }
    } else {
        if(nUnitNo%2) {
            pos.x+=mdl.pcb.ofstEvenCol.x;
            pos.y+=mdl.pcb.ofstEvenCol.y;
        }
    }

    return pos;
}
//---------------------------------------------------------------------------
Coord __fastcall TMotionBase::GetNextUnitPos(int nLane, int nDir)
{
    Coord pos = {0., 0., 0., 0.};

    if(AnsiString(run.chMdlFile).IsEmpty())
        return pos;

    int nUnit = GetCrntUnitNum(nLane);

    if(nDir == POS) {
        if(++nUnit >= (mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt))
            nUnit = 0;
    }
    else if(nDir == NEG) {
        if(--nUnit < 0)
            nUnit = (mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt)-1;
    }
    pos = GetUnitPos(nLane, nUnit);

    return pos;
}
//---------------------------------------------------------------------------
int __fastcall TMotionBase::GetUnitNum(int nLane, int &nX, int &nY)
{
    if(AnsiString(run.chMdlFile).IsEmpty())
        return -1;

    Coord posCmd, posCrnt, min, max;
    posCrnt.x = fabs(GetPos(IX));
    posCrnt.y = fabs(GetPos(IY));

    for(int i=0; i<mdl.pcb.nUnitXCnt*mdl.pcb.nUnitYCnt; i++) {
        posCmd = GetUnitPos(nLane, i);

        min.x = fabs(posCmd.x)-DEAD_BAND;
        max.x = fabs(posCmd.x)+DEAD_BAND;
        min.y = fabs(posCmd.y)-DEAD_BAND;
        max.y = fabs(posCmd.y)+DEAD_BAND;

        if((min.x <= posCrnt.x && max.x >= posCrnt.x) &&
            (min.y <= posCrnt.y && max.y >= posCrnt.y)) {
            if(&nX != NULL) nX = (mdl.pcb.nCntDir?i/mdl.pcb.nUnitYCnt:i%mdl.pcb.nUnitXCnt)+1;
            if(&nY != NULL) nY = (mdl.pcb.nCntDir?i%mdl.pcb.nUnitYCnt:i/mdl.pcb.nUnitXCnt)+1;
            return i;
        }
    }

    return -1;
}
//---------------------------------------------------------------------------
int __fastcall TMotionBase::GetUnitNumFromCoord(int nLane, int CoordX, int CoordY)
{
    int unitNo = -1;
    if( mdl.pcb.nCntDir == XDIR ) {
        unitNo = CoordX + (mdl.pcb.nUnitYCnt * CoordY);
    }
    else {
        unitNo = (mdl.pcb.nUnitXCnt * CoordX) + CoordY;
    }
    return unitNo;
//    for(int m=0; (mdl.pcb.nCntDir?m<nX:m<nY); m++) {
//        for(int n=0; (mdl.pcb.nCntDir?n<nY:n<nX); n++) {
//
//        }
//
//    }

}
//---------------------------------------------------------------------------

int __fastcall TMotionBase::GetCrntUnitNum(int nLane)
{
    return GetUnitNum(nLane, NULL, NULL);
}

