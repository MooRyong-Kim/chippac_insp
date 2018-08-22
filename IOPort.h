//---------------------------------------------------------------------------
#ifndef IOPortH
#define IOPortH
//---------------------------------------------------------------------------
#include <time.h>
#include "constdefine.h"
#include "CrevisFnIO.h"
#pragma warn -pck
#include <map.h>
#pragma warn +pck
//---------------------------------------------------------------------------
///////////////////////////////////////////////////
///********   I/O output  name define   *********//
///////////////////////////////////////////////////
//************  Input *********************
#define    startbtn        "startbtn"
#define    stopbtn         "stopbtn"
#define    rstbtn          "rstbtn"
#define    emgsw           "emgsw"
#define    lightsw         "lightsw"
#define    htrsw           "htrsw"
#define    vacsw           "vacsw"
#define    srvpwr          "srvpwr"
#define    fdoorclose      "fdoorclose"
#define    rulpushfwd      "rulpushfwd"
#define    rulpushbwd      "rulpushbwd"
#define    rulpushjam      "rulpushjam"
#define    rulpushup       "rulpushup"
#define    rulpushdn       "rulpushdn"
#define    mainairgood     "mainairgood"
#define    fpostsmmnotrdy  "fpostsmmnotrdy"
#define    fpresmmrdy      "fpresmmrdy"
#define    rpostsmmnotrdy  "rpostsmmnotrdy"
#define    rpresmmrdy      "rpresmmrdy"
#define    fcvyinspdct     "fcvyinspdct"
#define    fcvyindct       "fcvyindct"
#define    ulbarsafety     "ulbarsafety"
#define    finspstprup     "finspstprup"
#define    finspstprdn     "finspstprdn"
#define    finspblkup      "finspblkup"
#define    finspblkdn      "finspblkdn"
#define    finspblkvac     "finspblkvac"
#define    ulmgzdct        "ulmgzdct"
#define    fulpushfwd       "fulpushfwd"
#define    fulpushbwd       "fulpushbwd"
#define    fulpushjam       "fulpushjam"
#define    fulpushup        "fulpushup"
#define    fulpushdn        "fulpushdn"
#define    fcvyoutdct      "fcvyoutdct"
#define    rcvyindct       "rcvyindct"
#define    rcvyinspdct     "rcvyinspdct"
#define    rinspstprup     "rinspstprup"
#define    rinspstprdn     "rinspstprdn"
#define    rinspblkup      "rinspblkup"
#define    rinspblkdn      "rinspblkdn"
#define    rinspblkvac     "rinspblkvac"
#define    rcvyoutdct      "rcvyoutdct"
#define    fulenadct       "fulenadct"
#define    finspblkvac     "finspblkvac"
#define    rinspblkvac     "rinspblkvac"
#define    ulrstbtn        "ulrstbtn"
#define    ulemgsw         "ulemgsw"
#define    ulsafety        "ulsafety"
#define    rulenadct       "rulenadct"
//Adding Zeus single
#define    cvypredct       "cvypredct"

#define    clampup1        "clampup1"
#define    prestprup       "prestprup"
#define    prestprdn       "prestprdn"

#define    clampon         "clampon"
#define    clampoff        "clampoff"

#define    clampfwd        "clampfwd"
#define    clampbwd        "clampbwd"

#define    mainairgood     "mainairgood"
#define    clampdn1        "clampdn1"
#define    clampup2        "clampup2"
#define    clampdn2        "clampdn2"

#define    ulmgzdct        "ulmgzdct"
#define    ulbarsafety1    "ulbarsafety1"
#define    ulbarsafety2    "ulbarsafety2"
#define    ulemgsw         "ulemgsw"
#define    ulrstbtn        "ulrstbtn"
#define    uldoorclose     "uldoorclose"
#define    ulgripmgzgood   "ulgripmgzgood"
#define    ulmgzgripoff    "ulmgzgripoff"
#define    ulmgzgripon     "ulmgzgripon"
#define    ulmgzldout      "ulmgzldout"
#define    ulmgzulfull     "ulmgzulfull"
//Adding for UV Cure Zone
#define    uvdoorclose     "uvdoorclose"
#define    uv1status       "uv1status"
#define    uv1rdy          "uv1rdy"
#define    uv1alarm        "uv1alarm"
#define    uv2status       "uv2status"
#define    uv2rdy          "uv2rdy"
#define    uv2alarm        "uv2alarm"
#define    uvzonedct       "uvzonedct"
#define    uvstprup        "uvstprup"
#define    uvstprdn        "uvstprdn"
//2017.02.22 sjh 15:26:07
#define    ulcvymgzindtc   "ulcvymgzindtc"
#define    ulcvymgzoutdtc  "ulcvymgzoutdtc"

//************  Output *********************
#define    STARTLAMP       "STARTLAMP"
#define    STOPLAMP        "STOPLAMP"
#define    RSTLAMP         "RSTLAMP"
#define    LIGHTSWLAMP     "LIGHTSWLAMP"
#define    VACSWLAMP       "VACSWLAMP"
#define    SRVENA          "SRVENA"
#define    SRVPWR          "SRVPWR"
#define    MAINAIR         "MAINAIR"
#define    BUZZ            "BUZZ"
#define    TWRRED          "TWRRED"
#define    TWRYLW          "TWRYLW"
#define    TWRGRN          "TWRGRN"
#define    WRKBLKHTR       "WRKBLKHTR"
#define    FIMSMMRDYTOPOST "FIMSMMRDYTOPOST"
#define    FIMSMMRDYTOPRE  "FIMSMMRDYTOPRE"
#define    RIMSMMRDYTOPOST "RIMSMMRDYTOPOST"
#define    RIMSMMRDYTOPRE  "RIMSMMRDYTOPRE"
#define    FINSPBLKVAC     "FINSPBLKVAC"
#define    FINSPBLKBLOW    "FINSPBLKBLOW"
#define    FINSPCVYRUN     "FINSPCVYRUN"
#define    FINSPCVYDIR     "FINSPCVYDIR"
#define    DOORLOCK        "DOORLOCK"       
#define    FINSPSTPRDN     "FINSPSTPRDN"
#define    FINSPBLKUP      "FINSPBLKUP"
#define    FULPUSHFWD      "FULPUSHFWD"
#define    FULPUSHDN       "FULPUSHDN"
#define    ULRSTLAMP       "ULRSTLAMP"
#define    RINSPCVYRUN     "RINSPCVYRUN"
#define    RINSPCVYDIR     "RINSPCVYDIR"
#define    RINSPSTPRDN     "RINSPSTPRDN"
#define    RINSPBLKUP      "RINSPBLKUP"
#define    RINSPBLKVAC     "RINSPBLKVAC"
#define    RINSPBLKBLOW    "RINSPBLKBLOW"
#define    RULPUSHFWD      "RULPUSHFWD"
#define    RULPUSHDN       "RULPUSHDN"
#define    INSPPCBSENSON   "INSPPCBSENSON"
#define    CLAMPON         "CLAMPON"
//Adding for Zeus single
#define    CLAMPFWD        "CLAMPFWD"
#define    CLAMPDN         "CLAMPDN"
#define    PRESTPRDN       "PRESTPRDN"
#define    INSPPCBSENSON   "INSPPCBSENSON"
#define    DOORINTLOCK     "DOORINTLOCK"
#define    INSPCVYFWD      "INSPCVYFWD"
#define    ULRSTLAMP       "ULRSTLAMP"
#define    ULMGZGRIPOFF    "ULMGZGRIPOFF"
#define    ULLDCVYRUN      "ULLDCVYRUN"
#define    ULLDCVYDIR      "ULLDCVYDIR"

//#define    ULMGZGRIPON     "ULMGZGRIPON"
//2017.02.21 sjh 10:17:10     
#define    ULMGZGRIPDOWN   "ULMGZGRIPDOWN"
#define    ULMGZGRIPUP     "ULMGZGRIPUP"
#define    ULUDCVYRUN      "ULUDCVYRUN"
#define    ULUDCVYDIR      "ULUDCVYDIR"

//Adding for UV Cure Zone
#define    UV1ON           "UV1ON"
#define    UV1RST          "UV1RST"
#define    UV2ON           "UV2ON"
#define    UV2RST          "UV2RST"
#define    UVALLON         "UVALLON"
#define    UVSTPRDN        "UVSTPRDN"
#define    UVCVYRUN        "UVCVYRUN"
#define    UVCVYDIR        "UVCVYDIR"
#define    UVCVYFWD        "UVCVYFWD"
#define    UVCVYBWD        "UVCVYBWD"
//더블 타입
#define    FINSPCVYFWD     "FINSPCVYFWD"
#define    FINSPCVYBWD     "FINSPCVYBWD"
#define    RINSPCVYFWD     "RINSPCVYFWD"
#define    RINSPCVYBWD     "FINSPCVYBWD"

#define    ULLDCVYFWD      "ULLDCVYFWD"
#define    ULLDCVYBWD      "ULLDCVYBWD"
#define    ULMGZGRIP       "ULMGZGRIP"

//2017.02.21 sjh 10:59:08
#define    ULUDCVYFWD      "ULUDCVYFWD"
#define    ULUDCVYBWD      "ULUDCVYBWD"


//---------------------------------------------------------------------------
class TIOPort
{
private:
    HANDLE m_hBd[3];
    int m_nNewTwrSetNum;
    int m_nOldTwrSetNum;
    struct TowerLamp {
        clock_t tValid;
        clock_t tGrnFlash;
        clock_t tYlwFlash;
        clock_t tRedFlash;
        clock_t tBuzzOn;
        clock_t tBuzzTick;
    } TwrClk;
  	FNIO_HANDLE	m_hFnIoSys, m_hFnIoDev;
protected:
    bool __fastcall GetHdl(int nPort, HANDLE *hBd, int *nCh);
public:
	struct IO_STRING_FORMAT {
        char chIO[10];
        int nPort;
        int nGroup;
        char chLevel;
        int nAddress;
        char chEnum[32];
        char chName[32];
    } io_Fmt[2][IO_MAX+1];
    map<AnsiString,int> EnumMap[2];
    map<AnsiString,int> NameMap[2];
    TStringList *m_pEnumList[2];
    void __fastcall ReadAndDecodeFromIOFile();
    int m_nCrntTwrSetNum;
    __fastcall TIOPort();
    __fastcall ~TIOPort();
    bool __fastcall InitIOBoard();
    void __fastcall FreeIOBoard();
    bool __fastcall In(int nPort);
    bool __fastcall In(AnsiString sPort, bool bName = false);
    void __fastcall SetBit(AnsiString sPort, bool bName = false);
    void __fastcall ResetBit(AnsiString sPort, bool bName = false);
    bool __fastcall GetOut(AnsiString sPort, bool bName = false);
    void __fastcall SetBit(int nPort);
    void __fastcall ResetBit(int nPort);
    bool __fastcall GetOut(int nPort);
    void __fastcall On(AnsiString sPort, bool bName = false);
    void __fastcall Off(AnsiString sPort, bool bName = false);
    void __fastcall TowerLampProcess();
    void __fastcall SetTowerLamp(int nTwrNum, bool bSecsGem=true);
    void __fastcall FnSetBit(int nPort);
    void __fastcall FnResetBit(int nPort);
    bool __fastcall FnGetOut(int nPort);
    bool __fastcall FnIn(int nPort);
    void __fastcall DisplayFnIoErr();
    bool __fastcall FnIoOpenDevice();
};
extern TIOPort IO;
//---------------------------------------------------------------------------
#endif
