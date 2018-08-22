//---------------------------------------------------------------------------

#ifndef MotionBaseH
#define MotionBaseH
//---------------------------------------------------------------------------
#include <Time.h>
#include "ConstDefine.h"
//---------------------------------------------------------------------------
class TMotionBase
{
private:
    int m_nHWAxis[AXES];
    bool  __fastcall GetHdl(int nAxis, HANDLE &hBd, int &nCh);
protected:
public:
    struct MOTION_BOARD {
        HANDLE hdl[3];
        int nAxes[3];
    } mbd;
    struct MOVE {
        double dBasePos[AXES];
        double dCmdPos[AXES];
        clock_t tTime[AXES];
        int nTimeOut[AXES];
        bool bJog;
        bool bAuto;
    } move;
    Coord m_distHeadMove;
    __fastcall TMotionBase();
    __fastcall ~TMotionBase();
    bool __fastcall InitMotionBoard();
    void __fastcall ResetInposition(int nAxis);    
    bool __fastcall IsServoAlarm(int nAxis);
    bool __fastcall HomeSensor(int nAxis);
    bool __fastcall PosLimit(int nAxis);
    bool __fastcall NegLimit(int nAxis);
    void __fastcall ServoReset(int nAxis, bool bOn);
    bool __fastcall IsServoOn(int nAxis);
    void __fastcall ServoPower(int nAxis, bool bOn);
    bool __fastcall ComiMove(int nAxis, double dPulse, double dVel, int nAcc, bool bWhile=false);
    bool __fastcall MoveTo(int nAxis, double dmm, bool bWhile=false, int nSpd=0);
    bool __fastcall ComiXYMove(int nAxis, Coord crdPulse, double dVel, double dAcc, bool bWhile=false);
    bool __fastcall XYMoveTo(int nAxis, Coord mm, bool bWhile=false, int nSpd=0);
    void __fastcall MoveStop(int nAxis);
    void __fastcall JogMove(int nAxis, int nCmd);
    bool __fastcall IsNearlyPos(int nAxis, double dPos, double dBand, bool bDoneChk=false);    
    bool __fastcall IsCrntPos(int nAxis, double dPos, double dBand=DEAD_BAND, bool bDoneChk=true);
    bool __fastcall IsCrntPos(int nAxis, Coord pos, double dBand=DEAD_BAND, bool bDoneChk=true);
    void __fastcall DoHomeSearch(int nAxis);
    Coord __fastcall VsnRltPxlToRobotPos(int nCam, Coord posVsnChk, Coord pxlVsnRlt);
    Coord __fastcall VsnRltPxlTomm(int nCam, Coord pxlVsnRlt);
    Coord __fastcall VsnRltPxlTomm(int nCam, Coord pxlCtr, Coord pxlVsnRlt);
    bool __fastcall InitCheck();
    long __fastcall GetPulse(int nAxis, bool bCmd = false);
    double __fastcall GetPos(int nAxis, bool bCmd = false);
    double __fastcall GetPosInc(int nAxis);
    double __fastcall CalPulse(int nAxis, double dmm);
    bool __fastcall AxisDone(int nAxis);
    Coord __fastcall GoToAtchPos(int nPkr, int nTarget, bool bOverride=false);
    void __fastcall VelMove(int nAxis, int nDir, double dSpd, int nAcc);
    void __fastcall SetAxisSWLimit(int nAxis, double dMinusLmtmm, double dPlusLmtmm);
    void __fastcall SetPosZero(int nAxis, long nPulse=0);
    Coord __fastcall GetHeadPos(int nPosKind, int nTarget);
    int __fastcall GetCrntTargetNum(int nPosKind, bool bRearRail = false);
    Coord __fastcall GetNextTargetPos(int nDir, int nPosKind, bool bRearRail=false);
    bool __fastcall HeadDone(int nZHomeChkMode=1);
    Coord __fastcall GetPickUpPos(int nPkr, int nPocket);
    void __fastcall SprPrsMove(int nAxis, double dPrsDist);
    void __fastcall MotionBdReset();
    TPoint __fastcall GetHeadHomeDir();
    double __fastcall SetBtmVsnTrigger(bool bOn, bool bPkr1=false, bool bPkr2=false);
    Coord __fastcall GetCenter(Coord posPt1, Coord posPt2);
    bool __fastcall SetConveyorWidth(double dWidth,bool bMsg, bool bHome=false);
    bool __fastcall HeadManualMoveTo(int nPkr, Coord pos, bool bZMove=false, bool bZDownMsg=false);
    Coord __fastcall PkrDownSafetyDist(int nFdr, bool bAtch);
    Coord __fastcall GetMgzSlotPos(int nAxis, int nMgz, int nSlot);
    int __fastcall GetMgzSlotNum(int nAxis, int &nMgz, int &nSlot);
    int __fastcall GetCrntSlotNum(int nAxis);
    void __fastcall CenterRotation(double *nx, double *ny, double tx, double ty,
            double cx, double cy, double q);
    Coord __fastcall GetPosFromCharData(char *chData, int nTarget=-1, bool bInsp=false);
    void __fastcall HTypeUlManMove(int nAxis, Coord pos);
    void __fastcall ManualAxisMove(int nAxis, double dPos);
    Coord __fastcall GetUnitPos(int nLane, int nUnitNo);
    Coord __fastcall GetNextUnitPos(int nLane, int nDir);
    int __fastcall GetUnitNum(int nLane, int &nX, int &nY);
    int __fastcall GetUnitNumFromCoord(int nLane, int CoordX, int CoordY);
    int __fastcall GetCrntUnitNum(int nLane);    
};
extern TMotionBase MB;
#endif













