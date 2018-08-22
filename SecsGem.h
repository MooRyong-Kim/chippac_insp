//---------------------------------------------------------------------------

#ifndef SecsGemH
#define SecsGemH
#include <map.h>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include "EZGEMLib_OCX.h"
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDBaseLabel.hpp"
#include "LMDCustomGlyphLabel.hpp"
#include "LMDCustomImageList.hpp"
#include "LMDGlyphLabel.hpp"
#include "LMDImageList.hpp"
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <OleCtrls.hpp>
#include <StdCtrls.hpp>


enum {HOST_DISCONNECT, HOST_CONNECT, HOST_WAITING};
enum {MODE_OFFLINE, MODE_LOCAL, MODE_REMOTE};
enum {STAT_UNKNOWN, STAT_RUN, STAT_STOP, STAT_ERROR, STAT_IDLE, STAT_PROGRAM};
enum {ALID, CEID, SVID, ECID, ID_MAX};
enum enum_ECID
{
    CONNECTION_MODE = 3001, PORT_NUMBER, REMOTE_IP_ADDRESS,
    T3, T5, T6, T7, T8, LINK_TEST_INTERVAL, RETRY_LIMIT, DEVICE_ID
};


const int MAX_CEID      = 50;
const int MAX_ERROR     = 1000;

#define EQP_OFF_LINE    1
#define ATTEMP_ONLINE   2
#define HOST_OFF_LINE   3
#define ONLINE_LOCAL    4
#define ONLINE_REMOTE   5

#define MODEL_TYPE "PRO2020NT_ATTACH"

#define FDC_NOCONTENS       0
#define FDC_INCONTENS       1
#define FDC_UPLOADING       2
#define FDC_UPLOADFAIL      3
#define FDC_INVALIDPARM     4
//************* CEID ********************
#define  START_CEID             1001
#define  C_LOCAL                1001
#define  C_REMOTE               1002
#define  C_OFFLINE              1003
#define  C_PROCESS_STATE_CHG    1004
#define  C_TERMINAL_MSG_ACK     1005
#define  C_POWER_ON             1008
#define  C_INIT_SYSTEM          1009
#define  C_WARM_START           1010
#define  C_EDIT_PROGRAM         1011
#define  C_POWER_OFF            1012
#define  C_OPEN_FILE            1013
#define  C_START_RUN            1014
#define  C_ALARM_SET            1016
#define  C_ALARM_CLEAR          1017
#define  C_PAUSE_RUN            1018
#define  C_START_NEW_LOT        1019
#define  C_CHANGE_CFG           1020
#define  C_VISION_ERR           1021
#define  C_SAFETY_UNLOCK        1022
#define  C_SAFETY_LOCK          1023
#define  C_WORK_END             1024
#define  C_TRACK_OUT            1025
#define  C_LAST_PCB_UNLOAD      1026
#define  C_FDC_UPLOAD           1027
#define  C_EVERY_PCB_UNLOAD     1028
#define  C_LID_SUPPLY           1029
#define  C_MAGAZINE_UNLOAD      1030
#define  C_LAST_CHIP_WORK_END   1031
#define  C_ALARM_CLEAR_RUN      1032
/*
1032	Work Complete	At all of loading PCB’s working is completedRef. SVID 2028: ProductionEndTimeRef. SVID2087, 2088, 2089: production q’ty
1033	First PCB is Loading at first magazine	At first PCB’s of first magazines is loadingRef. SVID 2027: ProductionStartTime
1034	First PCB is Loading at every magazine	At first PCB’s of every magazine is loading
1035	Last PCB is unloading at every magazine	At last PCB’s of every magazine is unloading
1036	Every PCB is loading	At every PCB is loading at every magazine
1037	Every PCB is unloading	At every PCB is unloading at every magazine
1038	TRACK IN	At new lot is started (The new lot ID is tracked by operator)Ref. SVID2017:Operator ID, SVID2019:Lot ID
1039	TRACK OUT	At current lot is finished (Same as CEID1032)Ref. SVID2087~2089 Producted Q’ty of current lot
1040	LOT DATA RESET
*/
//for samsung electronis
#define  C_UNLOAD_REQUEST       1033
#define  C_UNLOAD_COMPLETE      1034

struct SVID_LIST {
    BYTE CommState;
    BYTE ControlState;
    BYTE PrevControlState;
    BYTE ProcessState;
    BYTE PrevProcessState;
    AnsiString CurrentPPID;
    float CycleTime;
    int TotalCount;
    int ProductCount;
    int RejectCount;
    float UPH;
    AnsiString OperatorID;
    AnsiString DeviceName;
    AnsiString LotID;
    bool MainAirStatus;
    bool MachineInialized;
    AnsiString EQLifeTime;
    AnsiString EQRunTime;
    AnsiString EQStopTime;
    AnsiString EQErrorTime;
    AnsiString EQMTBA;
    AnsiString ProductStartTime;
    AnsiString ProductEndTime;
    bool UnitHeightInspection;
    bool DispensingInspection;
    float Pkr1AttachHeight;
    float Pkr2AttachHeight;
    float PressMinForce;
    float PressSetForce;
    float PressMaxForce;
    float PressingSpeed;
    int PressingDelay;
    int PressCount;
    bool bLidTiltInsp;
    float fLidTiltMinMaxVal;
    float fLidDoubleDctVal;
    bool bLidOrientInsp;
    int nLidOrientDctScore;

    int nPickUpSpd;
    int nPickUpAcc;
    bool bAtch1BarSafety;
    bool bAtch2BarSafety;
    bool bHtrSWOffAlarm;
    bool bHtrTempAlarm;
    int nHtrTempErrDctTime;
    int nHtrLowTempStart;
    int nUnitAlignDly;
    int nSlugAlignDly;
    int nDispInspDly;
    int nHgtLsrDly;
    int nUnitAlignMsgSet;
    int nLidAlignMsgSet;
    int nDispInspMsgSet;
    int nLidInspMsgSet;
    AnsiString sOprPswd;
    AnsiString sEngPswd;
    bool bPrsForceLog;
    bool bHgtInspLog;
    bool bLidHoleInspLog;
    bool bMcStopAtVacErr;
    bool bUseUlPusherJam;
    int nHeadMoveSpd;
    int nHeadMoveAcc;
//for Samsung Cim
    int PortID;   // Event 발생 할때 Loader=0, Unloader=1
    AnsiString MagID;    // Event 발생 할때 LD 또는 UL 의 Magazine ID
    int SlotID;   // Event 발생 할때 PCB 의 Slot No
    AnsiString Clock;  // hhmmsstt  현재 시간
    AnsiString UserData;
    AnsiString SlotMap;

    SVID_LIST () {
        CommState            = 7; // Communicating
        ControlState         = 4; // On Line, Local
        PrevControlState     = 0; // Unknown
        ProcessState         = 4; // Idle
        PrevProcessState     = 0; // Unknown
        CurrentPPID          = " ";
        CycleTime            = 0.0;
        TotalCount           = 0;
        ProductCount         = 0;
        RejectCount          = 0;
        UPH                  = 0;
        OperatorID           = " ";
        DeviceName           = " ";
        LotID                = " ";
        MainAirStatus        = true; // On
        MachineInialized     = false; // Not Inited
        EQLifeTime           = "00000000";
        EQRunTime            = "00000000";
        EQStopTime           = "00000000";
        EQErrorTime          = "00000000";
        EQMTBA               = "00000000";
        ProductStartTime     = "00000000000000";
        ProductEndTime       = "00000000000000";
        UnitHeightInspection = false;
        DispensingInspection = false;
        Pkr1AttachHeight     = 0.0;
        Pkr2AttachHeight     = 0.0;
        PressMinForce        = 0.0;
        PressSetForce        = 0.0;
        PressMaxForce        = 0.0;
        PressingSpeed        = 0.0;
        PressingDelay        = 0;
        PressCount           = 0;
        bLidTiltInsp         = false;
        fLidTiltMinMaxVal    = 0.;
        fLidDoubleDctVal     = 0.;
        bLidOrientInsp       = false;
        nLidOrientDctScore   = 0;

        nPickUpSpd           = 500;
        nPickUpAcc           = 100;
        bAtch1BarSafety      = true;
        bAtch2BarSafety      = true;
        bHtrSWOffAlarm       = false;
        bHtrTempAlarm        = true;
        nHtrTempErrDctTime   = 15;
        nHtrLowTempStart     = 0;
        nUnitAlignDly        = 20;
        nSlugAlignDly        = 20;
        nDispInspDly         = 20;
        nHgtLsrDly           = 50;
        nUnitAlignMsgSet     = 1;
        nLidAlignMsgSet      = 1;
        nDispInspMsgSet      = 1;
        nLidInspMsgSet       = 1;              
        sOprPswd             = "protecfds-2002";
        sEngPswd             = "protecfds-2002";
        bPrsForceLog         = true;
        bHgtInspLog          = true;
        bLidHoleInspLog      = true;
        bMcStopAtVacErr      = true;
        bUseUlPusherJam      = true;
        nHeadMoveSpd         = 1000;
        nHeadMoveAcc         = 200;

        PortID               = 0;
        MagID                = "0";
        SlotID               = 0;
        Clock                = "00000000";
        UserData             = " ";
        SlotMap              = "1:2:3:4:5:6:7:8:9:10:11:12:13:14:15:16:17:18:19:20";
    };
};
//---------------------------------------------------------------------------
class TSecsGemForm : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TMemo *SendMsgMemo;
    TMemo *RcvMsgMemo;
    TPanel *Panel1;
    TPanel *Panel2;
    TBitBtn *MsgSendBtn;
    TBitBtn *MsgClearBtn;
    TLMDImageList *LEDImage;
    TListBox *LogListBox;
    TPanel *Panel3;
    TSpeedButton *OnlineBtn;
    TSpeedButton *AllowRemoteBtn;
    TBitBtn *m_Close;
    TPanel *Panel5;
    TEdit *m_MachineNo;
    TPanel *Panel7;
    TEdit *m_HeadNo;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TTimer *SvidTimer;
    TTimer *EventTimer;
    TPanel *Panel4;
    TBevel *Bevel1;
    TLMDGlyphLabel *HostConnectedLed;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TPanel *m_CIMStatus;
    TPanel *m_CIMError;
    TPanel *m_CIMConnect;
    TEdit *SecsGemIpEdit;
    TBitBtn *m_IPChange;
    TPanel *m_SVID_Disp;
    TEdit *SecsGemPortEdit;
    TSpeedButton *OpenLogFolderBtn;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall MsgSendBtnClick(TObject *Sender);
    void __fastcall SvidTimerTimer(TObject *Sender);
    void __fastcall m_CloseClick(TObject *Sender);
    void __fastcall OnlineBtnClick(TObject *Sender);
    void __fastcall MsgClearBtnClick(TObject *Sender);
    void __fastcall m_IPChangeClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall AllowRemoteBtnClick(TObject *Sender);
    void __fastcall EventTimerTimer(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall LogListBoxDblClick(TObject *Sender);
    void __fastcall OpenLogFolderBtnClick(TObject *Sender);

    void __fastcall gemConnected(TObject *Sender);
    void __fastcall gemDisconnected(TObject *Sender);
    void __fastcall gemDateTimeSetRequest(TObject *Sender, long lMsgId, BSTR strNewDateTime);
    void __fastcall gemEstablishCommRequest(TObject *Sender, long lMsgId);
    void __fastcall gemCommEstablished(TObject *Sender);
    void __fastcall gemOnlineRequest(TObject *Sender, long lMsgId);
    void __fastcall gemOfflineRequest(TObject *Sender, long lMsgId);
    void __fastcall gemOnlineLocal(TObject *Sender);
    void __fastcall gemOnlineRemote(TObject *Sender);
    void __fastcall gemTerminalMessageSingle(TObject *Sender, long lMsgId, BSTR strCommand, short nParamCount);
    void __fastcall gemTerminalMessageMulti(TObject *Sender, long lMsgId, short nCode, short nCount);
    void __fastcall gemSecsMsgIn(TObject *Sender, short nStream, short nFunction, short nWbit, long lSysByte);
    void __fastcall gemSecsMsgOut(TObject *Sender, short nStream, short nFunction, short nWbit, long lSysByte);
    void __fastcall gemMsgRequested(TObject *Sender, long lMsgId);
    void __fastcall gemNewEquipConst(TObject *Sender, long lMsgId, short nCount);
    void __fastcall gemRemoteCommand(TObject *Sender, long lMsgId,
          BSTR strCommand, short nParamCount);
    void __fastcall gemProcessProgramLoadInquire(TObject *Sender,
          long lMsgId, BSTR strPPID, long lLength);
    void __fastcall gemProcessProgramRequested(TObject *Sender, BSTR PPID);
    void __fastcall gemProcessProgramSending(TObject *Sender, BSTR PPID);
    void __fastcall gemFormattedPPReceived(TObject *Sender, BSTR PPID,
          short nCommCodeCount, short nParamCount);
private:	// User declarations
    TEZGEM* gem;
    // Gem State
    map<int, AnsiString> mapSvid;
    map<int, AnsiString> tmpSvid;

    bool __fastcall AddID() ;
    void __fastcall SetLog(AnsiString txt);
    void AddLog(AnsiString sMsg);
    AnsiString GetDateTimeString(TDateTime td);
    AnsiString CnvDateTime(long TimeMS);
    AnsiString ZipPrgFiles(AnsiString prgFullName);
    int UnzipPrgFiles(AnsiString prgID);
    int __fastcall GetBinaryItem(AnsiString body, short* pList);
    AnsiString __fastcall HexToInt(AnsiString str);
public:		// User declarations
    __fastcall TSecsGemForm(TComponent* Owner);
    void __fastcall StartGem();
    void __fastcall StopGem(AnsiString strReason);
    bool __fastcall IsAllConnected();
    void __fastcall SetCommCfg();
    void __fastcall SetECID();
    void __fastcall SetSVID(bool bInit=false);
    void __fastcall SendTerminalMsg(AnsiString txt);
    void __fastcall AlarmSet(int nALCD, int nALID);

    int m_nHostConnected;
    int GetAlCD(int AlCode, bool isSetAlarm=false);
    void SendSVID();
    void RefreshSVID();
    bool SECSGEM_isEnabledEventReport[MAX_CEID];
    bool SECSGEM_isEnabledAlarmReport[MAX_ERROR+1];
    TDateTime StartProductionTime;
    TDateTime EndProductionTime;
    int MACHINE_NO;
    SVID_LIST SECSGEM_SVID;
    bool m_bCycleStopDone;
    bool m_bLotEndTime;
    TDateTime m_dtLotEndTime;
    int m_nLotStrip;
    int EventPortNo;
    AnsiString EventMagIDStr; // Mag Bar Code No
    int m_nChangedFdc;  //FDC전송용 ini파일이 갱신된경우, by ykm

    void __fastcall SendEvent(int nCEID, bool bSVID=true);
    void __fastcall SendALCD(bool bSet, AnsiString sErrMsg);
    void __fastcall WorkDataToTextFile(AnsiString sFileName="");
};
//---------------------------------------------------------------------------
extern PACKAGE TSecsGemForm *SecsGemForm;
//---------------------------------------------------------------------------
#endif
