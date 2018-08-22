//---------------------------------------------------------------------------

#ifndef WorkProcessH
#define WorkProcessH
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include "SubmapViwer.h"
#include <time.h>
#include <vector>
//---------------------------------------------------------------------------
enum COMM_STATUS {
    COMM_STANDBY,
    COMM_OK,
    COMM_NG,

};

enum INSP_RESULT {
    INSP_READY,
    INSP_OK,
    INSP_NG,
    INSP_NONE_TARGET,

};

class TWorkProcess
{
private:
    int m_nSort;
    bool m_bResevePusher[2];
    int m_nCurLane;
    String m_strBarcode;
protected:
//Motion Process
    void __fastcall StartProcess();
    void __fastcall StopProcess();
    void __fastcall WorkEndCheck();
    void __fastcall CycleStopProcess();
    void __fastcall PreCvyProcess();
    void __fastcall InspCvyProcess(int nRail);
    void __fastcall InspCvyProcess();
    void __fastcall UlCvyProcess();
    void __fastcall VertUlProcess(bool bSetSlot=false);
    void __fastcall HoriUlProcess(bool bSetSlot=false);
    void __fastcall UnitProcess();
public:
    struct {
        int nStart;
        int nStop;
        int nCycStop;
        int nInspCvy[2];
        int nUnit;
        int nUl;
        int nUlCvy;
    } pNo;

    bool m_bLotChgStart;
    bool m_bTempErrIgnore;
    bool m_bBoatSent;
    int m_nRunMode;
    int m_nStatus;
    TDateTime m_dtStartTime;
    clock_t m_tPrsElapsed;
    int m_nUphUnitCnt;
    TDateTime m_dtUPHStartTime;
    bool m_bUPHStartTimeReset;
    int m_nOutStripCnt;
    bool m_bProcessNumView;
    bool m_bUlEmptySlot[MAX_SLOT];
    AnsiString m_sManualCmd[2];    
    bool m_bReservePusher[2];
    bool m_bSetUnload[2];
    int nVsnRtyCnt;
    bool m_bAllSkip;

    typedef struct {
        bool bInspSkip;
        bool bInspDone;
        INSP_RESULT eInspErr;
        bool bInspManChkDone;        
        bool bInspGood;
    } UNIT_DATA;
    UNIT_DATA unit[MAX_UNIT];

    struct RESULT_DATA_MEMORY {
        bool bRailRejUnit[2][MAX_UNIT];
        bool bMgzRejUnit[MAX_MGZ][MAX_SLOT][MAX_UNIT];
    } rltMem;

    __fastcall TWorkProcess();
    __fastcall ~TWorkProcess();
    void __fastcall MainProcess(bool bThread=true);
    void __fastcall Stop(int nTwrLmp);
    void __fastcall ViewAlarm(AnsiString sErrMsg);
    bool __fastcall IsWorkEnd();
    void __fastcall ProcessSetZero();

    bool isRecvWorkEnd;
    bool isLastPcb;

    COMM_STATUS SubConfirmPass;
    COMM_STATUS MagConfirmPass;
    int nCrntSlot;
    std::vector<String> MagSubId;
    SUB_MAP_INFO SubMapData;
};
extern TWorkProcess Work;
#endif





