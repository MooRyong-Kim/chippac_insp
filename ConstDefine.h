#ifndef ConstDefineH
#define ConstDefineH
//---------------------------------------------------------------------------
#define TAG "Data["+IntToStr(++nDataCnt)+"]"

#define WINIF  pIniFile->WriteFloat
#define WINIB  pIniFile->WriteBool
#define WINII  pIniFile->WriteInteger
#define WINIS  pIniFile->WriteString

#define RINIF  pIniFile->ReadFloat
#define RINIB  pIniFile->ReadBool
#define RINII  pIniFile->ReadInteger
#define RINIS  pIniFile->ReadString

#define io(IO) ("^"+AnsiString(IO)+"`")
#define PROTECDLL


//---------------------------------------------------------------------------
extern struct Coord {
    double x;
    double y;
    double z;
    double r;
} crd;
//---------------------------------------------------------------------------
const AnsiString DATA_ID            = "ZEUS_INSP";
const AnsiString REG_KEY            = "Software\\Protec\\ZeusInsp";
const int MAX_TARGET                = 3000;
const int MAX_FDR                   = 5;
const int REC_SIZE                  = 10000;
const double DEAD_BAND              = 0.15;
const double VSN_CTR                = 0.030;
const int PKRCTR_CHKNUM             = 120;
const double ANGLE_BAND             = 44.999;
const double CAMPROFILE_RATE        = 0.85;
const double ZERO                   = 0.0000001;
const int MTR_TIMEOUT               = 5000;
const int BLK_CHK_PT                = 10;
const int HGT_CHK_PT                = 20;
const double WAIT_DATA              = 12345.;
const double PKR_BAND               = 10.;
const double DIPPING_TEST_TICK      = 5.;
const double FAST_MOVE_ZHGT         = 10.;
const AnsiString MAIN_PATH          = "d:\\ZeusInsp_data\\";
const AnsiString BACKUP_PATH        = "d:\\ZeusInsp_backup\\";
const AnsiString SYS_FILE_PATH      = "d:\\ZeusInsp_data\\sys_data\\";
const AnsiString MODEL_FILE_PATH    = "d:\\ZeusInsp_data\\model_data\\";
const AnsiString SYSLOG_FILE_PATH   = "d:\\ZeusInsp_data\\sys_log\\";
const AnsiString CFG_FILE_NAME      = "ZeusInsp.cfg";
const AnsiString RUN_FILE_NAME      = "ZeusInsp.run";
//---------------------------------------------------------------------------
const int MAX_UNIT =    1000;
//---------------------------------------------------------------------------
const int FRNT            = 0;
const int REAR            = 1;
//---------------------------------------------------------------------------
const int HTYPE_1RAIL     = 0;
const int VTYPE_2RAIL     = 1;
//---------------------------------------------------------------------------
const int CVY_START_CHECK_DELAY = 5000;
//TStringList define
const int STR_TEMP          = 0;
const int STR_AXIS          = 1;
const int STR_MSG           = 2;
const int STR_ERR           = 3;
const int STR_ALID          = 4;
const int STR_MAX           = 5;
//---------------------------------------------------------------------------
const double POCKET_PITCH   = 58.2;
const double ELEV_PITCH     = 80.2;
//---------------------------------------------------------------------------
const int COM_ERR       = -100;
const int UL_ERR       = 3;
const int UL_SAFETY    = 4;
//---------------------------------------------------------------------------
//IOPanel Array
const unsigned int IO_MAX   = 96;
const unsigned int IO_COL   = 12;
const unsigned int IO_ROW   = 8;
//---------------------------------------------------------------------------
const int IO_IN             = 0;
const int IO_OUT            = 1;
const int FN_IO             = 48;
//---------------------------------------------------------------------------
const int FDR_STS           = 0;
const int FDR_ADV           = 1;
const int FDR_RDY           = 2;
const int FDR_NDY           = 3;
const int FDR_ACK           = 4;
const int FDR_NCK           = 5;
//---------------------------------------------------------------------------
const int MGZ_NUM           = 3;
//---------------------------------------------------------------------------
const int PKR1              = 0;
const int PKR2              = 1;
//---------------------------------------------------------------------------
const int PRE               = 0;
const int WORK              = 1;
const int POST              = 2;
const int MAX_ZONE          = 3;
//---------------------------------------------------------------------------
const bool PREV             = 1;
const bool NEXT             = 0;
//---------------------------------------------------------------------------
const int POS_FID1          = 0;
const int POS_FID2          = 1;
const int POS_PKR1          = 2;
const int POS_PKR2          = 3;
const int POS_TARGET        = 4;
const int POS_XFID          = 5;
const int POS_TPKR1         = 6;
const int POS_TPKR2         = 7;
const int POS_TUNIT         = 8;
const int POS_UVCURE        = 9;
//---------------------------------------------------------------------------
//Password
const AnsiString FACTORY_PASSWORD   = "protecfds-2002";
const int PSWD_MISS         = 0;
const int PSWD_CANCEL       = 1;
const int PSWD_OPR_MATCH    = 2;
const int PSWD_ENG_MATCH    = 3;
const int PSWD_FAC_MATCH    = 4;
//---------------------------------------------------------------------------
//Product Work Status
const int RSTOP             = 0;
const int RSTART            = 1;
const int CYC_STOP          = 2;
const int LOT_CHG           = 3;
//---------------------------------------------------------------------------
//Vision Alarm Process
const int VSN_ALARM         = 0;
const int VSN_WAIT          = 1;
const int VSN_SKIP          = 2;
const int VSN_BEFOREDATA    = 3;
//---------------------------------------------------------------------------
//Run Mode Select
const int RUN_REAL          = 0;
const int RUN_REWORK        = 1;
const int RUN_DRY           = 2;
const int RUN_BYPASS        = 3;
const int RUN_VSN           = 4;
//---------------------------------------------------------------------------
//Direction
const int UP                = 0;
const int DN                = 1;
const int LE                = 2;
const int RI                = 3;
const int LEUP              = 4;
const int RIUP              = 5;
const int LEDN              = 6;
const int RIDN              = 7;
//---------------------------------------------------------------------------
//Work Flow
const int LTOR              = 0;
const int RTOL              = 1;
//---------------------------------------------------------------------------
//Head Home Direction
const int LT                = 0;
const int RT                = 1;
const int LB                = 2;
const int RB                = 3;
//---------------------------------------------------------------------------
//Ÿ������ ����
const int TWR_IDLE          = 0; //���� ��带 ������ �ٸ� �������� �����Ǿ��ִ� ���
const int TWR_START         = 1; //���� ��忡�� �۾��� �ϰ� ���� ��
const int TWR_STOP          = 2; //���� ��忡�� ������ ���
const int TWR_ALARM         = 3; //���� ��忡�� �˶��� �߻��� ���
const int TWR_CHANGE        = 4; //���� ��忡�� �Ű����� ��ü �ؾ� �� ���
const int TWR_END           = 5; //���� ��忡�� �۾� �Ϸ� ��
const int TWR_MAX           = 6;
//---------------------------------------------------------------------------
const int LOG_PWRON         = 0;
const int LOG_PWROFF        = 1;
const int LOG_INIT          = 2;
const int LOG_ALARM         = 3;
const int LOG_WORKLOAD      = 4;
const int LOG_WORKMODIFY    = 5;
const int LOG_START         = 6;
const int LOG_STOP          = 7;
const int LOG_LOTCHG        = 8;
const int LOG_CFGMODIFY     = 9;
const int LOG_MAX           = 10;
//---------------------------------------------------------------------------
//���� ���� ����
const bool DEC_STOP         = true;
const bool EMG_STOP         = false;
//---------------------------------------------------------------------------
//���� ����
const int POS               = 1;
const int NEG               = -1;
const int FWD               = 1;
const int BWD               = -1;
const int MSTOP             = 0;
//---------------------------------------------------------------------------
//ī�޶� ����
const int TOP               = 0;
const int BTM               = 1;
//---------------------------------------------------------------------------
//Vision Sorce
const int PRONTOCAM         = 0;
const int HARMONY           = 1;
//---------------------------------------------------------------------------
const int FIND              = 0;
const int AREA              = 1;
const int DIST              = 2;
//---------------------------------------------------------------------------
const int MDL               = 0;
const int SCH               = 1;
const int DCT               = SCH;
const int HDCT              = 2;
//---------------------------------------------------------------------------
//�ǵ�� ����
const int FID1              = 0;
const int FID2              = 1;
const int PIN1              = 2;
//---------------------------------------------------------------------------
//���� ����
const int INSP_T1           = 0; //PCB Fiducial1
const int INSP_T2           = 1; //PCB Fiducial2
const int INSP_B            = 2; //Shield Cap
const int INSP_T3           = 3; //Tray Align Mark#1 Or Bad Mark
const int INSP_T4           = 4; //Tray Align Mark#2 Or Bad Mark
const int INSP_MAX          = 4;
//---------------------------------------------------------------------------
//Vision Light Channel
const int LED_T1            = 0;
const int LED_T2            = 1;
const int LED_T3            = 2;
const int LED_B             = 3;
const int LED_MAX           = 4;
//---------------------------------------------------------------------------
const int XDIR              = 0;
const int YDIR              = 1;
//---------------------------------------------------------------------------
const int NO_INSP           = -1;
const int REJRCT            = 0;
const int GOOD              = 1;
//---------------------------------------------------------------------------
//Loader/Unloader Magazine
const int MAX_MGZ_KIND      = 10;
const int MAX_SLOT          = 40;
const int MAX_MGZ           = 4;
//---------------------------------------------------------------------------
const int AA                = 0;
const int BB                = 1;
//---------------------------------------------------------------------------
const int LDUL              = 0;
const int LDR               = 1;
const int ULR               = 2;
//---------------------------------------------------------------------------
const int REEL              = 0;
const int TRAY              = 1;
const int BOWL              = 2;
const int SLUG              = 3;
//---------------------------------------------------------------------------
//Tower Lamp
const int OFF               = 0;
const int ON                = 1;
const int FLASH             = 2;
//---------------------------------------------------------------------------
const int FAST_XY           = 1;
const int FAST_Z            = 2;
//---------------------------------------------------------------------------
const int NO_HOME_CHK       = 0;
const int HOME_CHK          = 1;
const int FAST_HOME_CHK     = 2;
//---------------------------------------------------------------------------
//Delay
const int DLY_SENS          = 100;
const int DLY_CAL           = 500;
const int DLY_BLK           = 700;
const int DLY_CVY           = 1000;
const int DLY_ULPUSH        = 1500;
const int DLY_COM           = 1000;
//---------------------------------------------------------------------------
//RunData Define
const int TM_PGM            = 0;
const int TM_RUN            = 1;
const int TM_STOP           = 2;
const int TM_ERR            = 3;
const int MTBA              = 4;
const int MTBF              = 5;
const int MTTR              = 6;
const int TTL_UPH           = 7;
const int TTL_IN            = 8;
const int TTL_OUT           = 9;
const int TTL_REJ           = 10;
const int TTL_ERR           = 11;
const int TTL_RUN           = 12;
//---------------------------------------------------------------------------
//Software ���� �� ����

const int IX    = 0;
const int IY    = 1;
const int DC    = 2;
const int UL    = 3;
const int UY    = 3;
const int UZ    = 4;
const int AXES  = 5;
//*/
/*
const int IX    = 0;
const int IY    = 1;
const int IZ    = 2;
const int IFD   = 4;
const int AXES  = 4;
//*/
//---------------------------------------------------------------------------

const int BARCODE_INDEX = 100;

#endif
