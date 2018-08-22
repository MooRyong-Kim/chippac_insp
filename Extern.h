//---------------------------------------------------------------------------
#ifndef ExternH
#define ExternH
//---------------------------------------------------------------------------
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "ConstDefine.h"
//---------------------------------------------------------------------------
//Time Factor
const int DAY = 0;
const int HOUR = 1;
const int MIN = 2;
const int SEC = 3;
const int TIME = 4;
//---------------------------------------------------------------------------
class TExtern
{
private:
    LARGE_INTEGER m_CPU_Frequency;
    DWORD __fastcall MyGetAbsSecond(SYSTEMTIME st);
    void __fastcall MyAbsSecondToSystem(DWORD Abs, SYSTEMTIME &st);
public:
    TStringList *m_pLngList[STR_MAX];
    
//Extern Function
    __fastcall TExtern();
    __fastcall ~TExtern();
    int __fastcall GetLapTime(clock_t t);
    bool __fastcall CheckDelay(clock_t tmpTime, int msec);
    void __fastcall ClockDelay(int msec);
    void __fastcall TimeDelay(int nmsec);
    void __fastcall CheckProgressTime(int pTime[4], TDateTime dtStartTime);
    AnsiString __fastcall ClockToString(clock_t tTime);
    AnsiString __fastcall FloatToStr(double dData, int nPoint=3);
    int __fastcall R(TColor color);
    int __fastcall G(TColor color);
    int __fastcall B(TColor color);
    void __fastcall SysLogAdd(AnsiString sLog);
    void __fastcall AlarmLogAdd(AnsiString sAlarmLog);
    AnsiString __fastcall SecToStr(int nSec, int nCipher);
    int __fastcall FindMsgIndex(int nStrList, AnsiString sTag);
    double __fastcall CalDist(Coord pos1, Coord pos2);
    int  __fastcall GetLapSec(TDateTime dtStartTime);
    void __fastcall LoadLangFile(AnsiString sLangFile);
    AnsiString __fastcall TtlPgsTime(int nDataNum, bool bRun);    
    void __fastcall RefreshSysRunData();
    AnsiString __fastcall TtlPgsTime(int nDataNum, bool bRun, bool bReset);
    AnsiString __fastcall GetFileName(AnsiString sFile);
    unsigned int __fastcall StopWatch(bool bReset, bool bRun);
    void __fastcall DeleteAllFile(AnsiString sFilePath, AnsiString sFileName="");
    void __fastcall ValidDayFileClean(AnsiString sPath, int nDay);
    void __fastcall ValidDayDirClean(AnsiString sPath, int nDay);
    double __fastcall CalTwoPointDist(Coord pos1, Coord pos2);
    void __fastcall DrawWireRects(LPRECT lprcFrom, LPRECT lprcTo);
    double __fastcall GetPkrHgtLsr();
    void __fastcall trace(LPCTSTR lpszFormat);
    AnsiString __fastcall GetCrntTime();
    int __fastcall SetTempSetPoint(int ChNo,int TempValue);
    double __fastcall GetTempValue(int ChNo);
    int __fastcall SetTempRunStop(int ChNo,bool Flag);
    int __fastcall SetTempWriteEnable(int ChNo,bool Flag);
    void __fastcall GetTempValueCmd(int ChNo);
    void __fastcall Sleep(int nmsec);
    double __fastcall GetMovingAvg(double dData);
    double __fastcall GetAngle(Coord crdOrg, Coord crdEnd);
    int __fastcall GetMemoHeight(TMemo *Memo, int LineCount=-1);
    DWORD __fastcall FindProcessPid(String sExeFullName);
    void __fastcall VisionDataLogAdd(bool bEnable, TListBox *pListBox);
    void __fastcall MarsLogAdd(AnsiString sMotion, int nMode, int nInPort, AnsiString sStartEnd);
    void __fastcall DoEvents();
    void __fastcall CimLogAdd(AnsiString sLog);
    void __fastcall GetDescendantDir(TStringList *pListDirNames, AnsiString sPath);    
    void __fastcall GetDirFile(TStringList *pListFileName, AnsiString sPath);
    void __fastcall GetAllFile(TStringList *pListFileName, AnsiString sPath);

    void __fastcall ReadMagRfTag( int TagNo );
    String MagRfId;
};
extern TExtern Ext;
#endif
