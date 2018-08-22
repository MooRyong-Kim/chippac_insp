//---------------------------------------------------------------------------
#ifndef DataClassH
#define DataClassH
//---------------------------------------------------------------------------
#include "ConstDefine.h"
//***************************************************************************
//**********                  System Config Data              ***************
//***************************************************************************
//Loader/Unloader Position
struct LDUL_DATA {
    int nMgzSlotNum;
    bool bUseRejMgz;
    int nRejMgzSel;

    bool bUseMgz[MAX_MGZ];
    double dMgzStartPos[MAX_MGZ];
    double dMgzEndPos[MAX_MGZ];
    double dMgzChgPos;

    Coord posMgzStart;
    Coord posMgzEnd;
    //Loading Position
    Coord posGripOnPre;
    Coord posGripOnCvy;
    Coord posGripOnUp;
    Coord posGripOnOut;
    //Unloading Position
    Coord posGripOffPre;
    Coord posGripOffCvy;
    Coord posGripOff;
    Coord posGripOffDn;
    Coord posGripOffOut;
    double dSpare[10];
    int nEmptyChkTime;
    int nLdOutSensDly;
    double dSpare1;
};

struct OPERATOR {
    //General
    bool bMsgBoxBuzz;
    int nMsgBoxBuzzTime;
    int nBlkUpDly;
    int nBlkVacOffDly;
    int nCvyStopDly;
    int nUlCvyStopDly;
    int nUlPushOnDly;
    int nCvyStprUpDly;
    bool bVacChkFrntMove;
    int nVsnAutoRtyCnt;
    int nVsnErrSet;
    bool bInspErrCollect;
    int nVsnDly;    
};

struct ENGINEER {
    //System History
    bool bLogItem[12];
    //Password
    char chOprPswd[128];
    char chEngPswd[128];
    //Tower Lamp
    struct TOWER_LAMP {
        int nGrnLight;
        int nGrnFlashIntvl;
        int nYlwLight;
        int nYlwFlashIntvl;
        int nRedLight;
        int nRedFlashIntvl;
        bool bUseBuzz;
        bool bBuzzAutoOff;
        int nBuzzOnTime;
    } twr[10];
    int nFileValidDay;
    //Safety
    bool bSafetySrvOff;
    bool bFrntDoorSafety;
    bool bUlBarSafety;
    int nCylTimeErr;
    int nBlkVacTimeErr;
    int nCvyTimeErr;
    int nComTimeErr;
    bool bUseClamp;
    bool bUvDoorSafety;
    bool UseHeaterAlarm;
//2016.02.15 12:29:51 chcho
    bool UseNetworkFrontDisp;
    bool bSpare[4];
//    bool bSpare[5];
    int BarcodeRetryCnt;
    //2016.02.11 19:37:47 chcho
//    int nSpare[1];
    int nDelayVacuum;

    double dSpare1[8];
    //Conveyor
    bool bWorkBlkClamp;
    bool bNoUseInspBlk;
    bool bNoUseInspBlkVacErr;
    bool bNoUseInspBlkVacOn;
    int nInspBlkVacRtyNum;
    bool bUseUlJamSens;
    bool bUseUlErrMcStop;
    double dSpare2[10];
    //Motor Parameter
    struct MOTOR_PARAMETER {
        int nSpd;
        int nAcc;
        int nJogSpd;
        int nJogAcc;
        int nHomeSpd;
    } mtr[AXES];
    //Work Block Planarity Measurement Data
};

struct FACTORY {
    //Motor Parameter
    struct MOTOR_PARAMETER {
        double dMSftLmt;
        double dPSftLmt;
        double dPulsePermm;
        double dHomeOfst;
    } mtr[AXES];
    //General
    bool bNoMachine;
    bool bEnglishVersion;
    bool bEngSafetySet;
    bool bAutoDoorLock;
    bool bAlwaysSafetyOn;
    bool bDebugMode;
    bool bUseSecsGem;
    bool bUseSmema;
    bool bUseLineScan;
    bool bNoUseUnloader;
    bool bSetupBtnPswd;
    bool bDisSpdAdjust;
    char chUdpIp[48];
    int nUdpPort;
    char chSecsGemIp[48];
    int nSecsGemPort;
    bool bNoUseXYInterpolation;
    int nEquipType;
    bool bUsePreBufCvy;
    bool bNoUseRearRail;
    bool bNoUseFnIo;
};

struct RUN_DATA {
    unsigned long nStartClock[4];
    unsigned long nLoadTime[4];
    bool bRun[4];
    unsigned long nData[12];
    char chData[12][200];
    char chMdlFile[200];
    double dUlZPos;
    Coord posInsp;
    Coord posUl;
    double dRejMgzPos;
    bool bRearRailWork;
};

struct LOT_DATA {
    char chOprName[128];
    char chLotNo[128];
    int nSetPcbCnt;
    int nInPcbCnt;
    int nOutPcbCnt;
    int nUlMgz;
    int nUlSlot;
    int nUlRejSlot;
    int nUph;
    TDateTime dtStartTime;
    TDateTime dtEndTime;
};

struct SYSTEM_CONFIG {
    AnsiString sFileName;
    char chID[10];
    char chModifyTime[200];
    OPERATOR opr;
    ENGINEER eng;
    FACTORY fac;
    LDUL_DATA ul;
};

//***************************************************************************
//**********                   Model Data                     ***************
//***************************************************************************
struct PCB_INFO {
    int nUnitXCnt0;
    int nUnitYCnt0;
    int nUnitXCnt;
    int nUnitYCnt;
    int nBlockXCnt;
    int nBlockYCnt;
    double dUnitXPitch;
    double dUnitYPitch;
    double dBlockYPitch;
    double dBlockXPitch;
    int nCntDir;
    double dCvyInPos;
    double dCvyOutPos[2];    
    Coord posFirstUnit[2];
    char chLoaderFile[128];
    int nUlSlotTerm;
    bool bNoUseZigZag;
    bool bWindowClamp;
    Coord ofstEvenCol;
    bool bUse2ndGroup;
    bool bUseCure;
    int nCureSec;
    bool bUseUvCure;
    int nUvCureSec;

    bool bUseBarcode;
    bool bUseAfterInspCure;
    bool bSpare[6];
    double dBarcodeX;
    double dBarcodeY;
    double dSpare[6];
};

struct MODEL_DATA {
    char chID[10];
    PCB_INFO pcb;
    LDUL_DATA ul;
};

class TDataClass
{
public:
    struct DISPENSER {
        AnsiString sReply;
        struct DISPENSER_PROTOCOL{
            char chLetter[256];
            int nUnitCnt;
            bool bSkipUnit[256];
        } com;
    } udp;
public:
    __fastcall TDataClass();
    __fastcall ~TDataClass();
    double m_dLdCell;
    double m_dHgtLsrData;
    double m_dStartForce;
    bool m_bMdlFileOpening;
    void __fastcall LoadRunData();
    void __fastcall SaveRunData();
    void __fastcall SaveConfigData(bool bProgress = true);
    void __fastcall LoadConfigData(AnsiString sFilePath = "");
    void __fastcall SaveModelData(AnsiString sFileName);
    void __fastcall LoadModelData(AnsiString sFileName, bool bProgress=true, bool bCvyWidth=false);
    bool __fastcall LoaderFileCtrl(AnsiString FileName, bool bSave, bool bSystem);    
};
extern TDataClass Data;
extern SYSTEM_CONFIG sys, sysOld;
extern MODEL_DATA mdl, mdlOld;
extern LOT_DATA lot;
extern RUN_DATA run;
//---------------------------------------------------------------------------
#endif




