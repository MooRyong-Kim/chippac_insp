//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Extern.h"
#include "Main.h"
#include "WorkProcess.h"
#include "RunChk.h"
#include "MotionBase.h"
#include "IOPort.h"
#include <Math.hpp>
#include <classes.hpp>
#include "Maint.h"
#include <TlHelp32.h>
#include "FileCtrl.hpp"
#include "DataClass.h"
#include "Msg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TExtern Ext;
//---------------------------------------------------------------------------
__fastcall TExtern::TExtern()
{
	if(!QueryPerformanceFrequency(&m_CPU_Frequency))
		ShowMessage("Can not know CPU clock speed");
}
//---------------------------------------------------------------------------
__fastcall TExtern::~TExtern()
{
    for(int i=0; i<STR_MAX; i++) {
        if(m_pLngList != NULL) {
            delete m_pLngList[i];
            m_pLngList[i] = NULL;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TExtern::Sleep(int nmsec)
{
//    ::Sleep(nmsec);
//    return;
    if(nmsec <= 300)
        ::Sleep(nmsec);
    else {
        clock_t tDly = clock();
        while(1) {
            if(CheckDelay(tDly, nmsec) || Chk.m_bMainErrEvent) break;
            DoEvents();
        }
    }
}
//---------------------------------------------------------------------------
// 시간의 경과를 체크하여 플래그로 되 돌려 줌.
bool __fastcall TExtern::CheckDelay(clock_t tmpTime, int msec)
{
	clock_t current;
    int tmp;

    current = clock();
    tmp = (int)((current-tmpTime)/CLK_TCK*1000);
	if(tmp >= msec)
    	return true;
   	return false;
}
//---------------------------------------------------------------------------
// 시간의 경과를 체크하여 시간으로 되돌려 줌.
int __fastcall TExtern::GetLapTime(clock_t t)
{
    clock_t c;
    int tmp;

    c=clock();
    tmp = (int)((c-t)/CLK_TCK*1000);
    return (tmp);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::ClockToString(clock_t tTime)
{
	clock_t tCurrent;
    int tmp;

    tCurrent = clock();
    tmp = (int)((tCurrent-tTime)/CLK_TCK*1000);

    return IntToStr(tmp);
}
//---------------------------------------------------------------------------
// 시간의 지연을 줌
void __fastcall TExtern::ClockDelay(int msec)
{
	clock_t start,end;
    int tmp;

    start=clock();
    do {
    	end=clock();
        if( end-start>0 )	tmp=(int)((end-start)/CLK_TCK*1000);
        else				tmp = 0;
    } while (tmp<msec);
}
//---------------------------------------------------------------------------
// 시간의 지연을 줌
void __fastcall TExtern::TimeDelay(int nmsec)
{
	LARGE_INTEGER setTime;
	QueryPerformanceCounter(&setTime);
	setTime.QuadPart += (__int64)(nmsec * (double) m_CPU_Frequency.QuadPart / 1000.0);

	LARGE_INTEGER curTime;
	QueryPerformanceCounter(&curTime);
	while(curTime.QuadPart < setTime.QuadPart)
	{
		QueryPerformanceCounter(&curTime);
	}
}
//---------------------------------------------------------------------------
// Get application running time
// st 날짜의 절대 초를 구한다. 2000년 1월 1일 자정 기준
DWORD __fastcall TExtern::MyGetAbsSecond(SYSTEMTIME st)
{
	INT64 i64;
	FILETIME fst;

	SystemTimeToFileTime(&st,&fst);
	i64=(((INT64)fst.dwHighDateTime) << 32) + fst.dwLowDateTime;
	// 초단위로 환산하고 2000 년 1월 1일 자정 기준으로 바꾼다.
	i64 = i64 / 10000000 - (INT64)145731 * 86400;

	return (DWORD)i64;
}
//---------------------------------------------------------------------------
// 절대초를 시스템 타임으로 바꾼다.
void __fastcall TExtern::MyAbsSecondToSystem(DWORD Abs, SYSTEMTIME &st)
{
	INT64 i64;
	FILETIME fst;

	i64=(Abs + (INT64)145731 * 86400)*10000000;
	fst.dwHighDateTime = (DWORD)(i64 >> 32);
	fst.dwLowDateTime = (DWORD)(i64 & 0xffffffff);
	FileTimeToSystemTime(&fst, &st);
}
//---------------------------------------------------------------------------
void __fastcall TExtern::CheckProgressTime(int pTime[4], TDateTime dtStartTime)
{
	SYSTEMTIME tNow, tStart;
	DWORD nNow, nStart; // 절대 초

    // 현재의 절대초
 	GetLocalTime(&tNow);
    nNow = MyGetAbsSecond(tNow);

    // 진행 시작시의 절대초
    DateTimeToSystemTime(dtStartTime, tStart);
    nStart = MyGetAbsSecond(tStart);

    pTime[SEC] = nNow-nStart;
  	pTime[DAY] = pTime[SEC]/86400;
	pTime[HOUR] = (pTime[SEC] % 86400)/3600;
	pTime[MIN] = (pTime[SEC] % 3600)/60;
    pTime[SEC]%=60;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::GetCrntTime()
{
    Word Hour, Min, Sec, MSec;
    DecodeTime(Now(), Hour, Min, Sec, MSec);
    AnsiString sTime;
    sTime.sprintf ("%02d:%02d:%02d",Hour, Min, Sec);
    return sTime;
}
//---------------------------------------------------------------------------
int __fastcall TExtern::GetLapSec(TDateTime dtStartTime)
{
	SYSTEMTIME tNow, tStart;
	DWORD nNow, nStart; // 절대 초

    // 현재의 절대초
 	GetLocalTime(&tNow);
    nNow = MyGetAbsSecond(tNow);

    // 진행 시작시의 절대초
    DateTimeToSystemTime(dtStartTime, tStart);
    nStart = MyGetAbsSecond(tStart);

    return nNow-nStart;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::SecToStr(int nSec, int nCipher)
{
    unsigned int Day, Hour, Sec, Min;

    Sec = nSec;
  	Day = Sec/86400;
	Hour = (Sec % 86400)/3600;
	Min = (Sec % 3600)/60;
    Sec%=60;

	// 경과 시간 리턴
    AnsiString sRunTime;
    AnsiString sStyle = "%0"+IntToStr(nCipher)+"d:%02d:%02d";
    sRunTime.sprintf(sStyle.c_str(), Hour+(Day*24), Min, Sec);
    return sRunTime;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::FloatToStr(double dData, int nPoint)
{
    return FloatToStrF(dData, ffFixed, 10, nPoint);
}
//---------------------------------------------------------------------------
int __fastcall TExtern::R(TColor color)
{
    return GetRValue(color);
}
//---------------------------------------------------------------------------
int __fastcall TExtern::B(TColor color)
{
    return GetBValue(color);
}
//---------------------------------------------------------------------------
int __fastcall TExtern::G(TColor color)
{
    return GetGValue(color);
}
//---------------------------------------------------------------------------
int __fastcall TExtern::FindMsgIndex(int nStrList, AnsiString sTag)
{
    AnsiString sTmp;
    for(int i=0; i<m_pLngList[nStrList]->Count; i++) {
        sTmp = m_pLngList[nStrList]->Strings[i];
        sTmp = sTmp.SubString(1,sTmp.Pos("<<")-1);
        if(sTmp.AnsiCompare(sTag) == 0)
            return i;
    }
    return -1;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::SysLogAdd(AnsiString sLog)
{
    if(!sys.eng.bLogItem[LOG_PWRON]) {
        if(sLog == "System Power On.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_PWROFF]) {
        if(sLog == "System Power Off.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_INIT]) {
        if(sLog == "System Initialization Start." || sLog == "System Initialization End.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_ALARM]) {
        if(sLog.AnsiPos("!"))
            return;
    }
    else if(!sys.eng.bLogItem[LOG_WORKLOAD]) {
        if(sLog == "Work File Load.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_WORKMODIFY]) {
        if(sLog == "Work File Save.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_START]) {
        if(sLog == "Work Start.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_STOP]) {
        if(sLog == "Work Stop.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_LOTCHG]) {
        if(sLog == "Lot Change.")
            return;
    }
    else if(!sys.eng.bLogItem[LOG_CFGMODIFY]) {
        if(sLog == "System Config File Modify.")
            return;
    }

    AnsiString sFileName, sTmp, sList;
    int nIdx;

    sFileName = SYSLOG_FILE_PATH+"EventLog\\";
    if(!DirectoryExists(sFileName)) CreateDir(sFileName);
    sFileName = sFileName+FormatDateTime("yyyy-mm-dd", Now())+".Log";
    FILE *fp;
    fp=fopen(sFileName.c_str(),"a+");

    AnsiString sComment, sIo;
    if(sLog.AnsiPos("@")) {
        sComment = sLog.SubString(sLog.AnsiPos("@")+1, sLog.Length());
        sLog = sLog.SubString(1, sLog.AnsiPos("@")-1);
    }
    if(sLog.AnsiPos("^")) {
        sIo = sLog.SubString(sLog.AnsiPos("^"), sLog.Length());
        sLog = sLog.SubString(1, sLog.AnsiPos("^")-1);
    }

    if(sLog.AnsiPos("!")) {
        sLog.Delete(1,1);
        nIdx = FindMsgIndex(STR_ERR, sLog);
        if(nIdx != -1) {
            sList = m_pLngList[STR_ERR]->Strings[nIdx];
            sList = sList.Delete(1, sList.Pos("<<")+1);
            sTmp = sList.SubString(1, sList.Pos(">>")-1);
        }
        else sTmp = sLog;
        sTmp = "!["+DateTimeToStr(Now())+"] CODE["+IntToStr(nIdx+1)+"]-"+sTmp+sComment;
    } else {
        nIdx = FindMsgIndex(STR_MSG, sLog);
        if(nIdx != -1) {
            sList = m_pLngList[STR_MSG]->Strings[nIdx];
            sList = sList.Delete(1, sList.Pos("<<")+1);
            sTmp = sList.SubString(1, sList.Pos(">>")-1);
        }
        else sTmp = sLog;
        if(sLog == "Work File Save" || sLog == "Work File Load") {
            sTmp = " ["+DateTimeToStr(Now())+"] \""+AnsiString(run.chMdlFile)+"\" "+sTmp+sComment;
        } else {
            sTmp = " ["+DateTimeToStr(Now())+"] "+sTmp+sComment;
        }
    }

    fseek(fp,0,2); //Search End of
    fprintf(fp, "%s \r\n", sTmp.c_str());
    fclose(fp);

    MainForm->LogPageCtrl->ActivePageIndex = 0;
    MainForm->SysLogListBox->Items->Add(sTmp);
    if(MainForm->SysLogListBox->Items->Count >= 300)
        MainForm->SysLogListBox->Items->Delete(0);
    MainForm->SysLogListBox->ItemIndex = MainForm->SysLogListBox->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::LoadLangFile(AnsiString sLangFile)
{
    for(int i=0; i<STR_MAX; i++)
        m_pLngList[i] = new TStringList;

    if(!FileExists(sLangFile))
        return;

    m_pLngList[STR_TEMP]->LoadFromFile(sLangFile);

    int nStrList = 0;

    for(int i=0; i<m_pLngList[STR_TEMP]->Count; i++) {
        if(m_pLngList[STR_TEMP]->Strings[i].Pos("#####")) {
            nStrList++;
            m_pLngList[nStrList]->Clear();
        } else {
            if(!m_pLngList[STR_TEMP]->Strings[i].Pos("***") && m_pLngList[STR_TEMP]->Strings[i] != "")
                m_pLngList[nStrList]->Add(m_pLngList[STR_TEMP]->Strings[i]);
        }
    }

    for(int i=m_pLngList[STR_AXIS]->Count; i<AXES; i++)
        m_pLngList[STR_AXIS]->Add("Not Use");

    //축 이름을 사용하는 일반메시지는 여기서 디코드 한다.
    m_pLngList[STR_TEMP]->Clear();
    for(int idx=0; idx<m_pLngList[STR_MSG]->Count; idx++) {
        if(m_pLngList[STR_MSG]->Strings[idx].Pos("AxisName")) {
           	for(int ax=0; ax<AXES; ax++) {
                AnsiString sTmp = m_pLngList[STR_MSG]->Strings[idx].Delete(1, 9);
                sTmp.Insert(m_pLngList[STR_AXIS]->Strings[ax]+" ", sTmp.Pos("<<")+2);
                m_pLngList[STR_TEMP]->Add(IntToStr(ax)+sTmp);
            }
            m_pLngList[STR_MSG]->Delete(idx);
        } else m_pLngList[STR_TEMP]->Add(m_pLngList[STR_MSG]->Strings[idx]);
    }
    m_pLngList[STR_MSG]->Clear();
    for(int idx=0; idx<m_pLngList[STR_TEMP]->Count; idx++)
        m_pLngList[STR_MSG]->Add(m_pLngList[STR_TEMP]->Strings[idx]);

    m_pLngList[STR_ALID]->Clear();
    //축 이름을 사용하는 에러 메시지는 여기서 디코드 한다.
    m_pLngList[STR_TEMP]->Clear();
    for(int idx=0; idx<m_pLngList[STR_ERR]->Count; idx++) {
        if(m_pLngList[STR_ERR]->Strings[idx].Pos("AxisName")) {
           	for(int ax=0; ax<AXES; ax++) {
                AnsiString sTmp = m_pLngList[STR_ERR]->Strings[idx].Delete(1, 9);
                sTmp.Insert(m_pLngList[STR_AXIS]->Strings[ax]+" ", sTmp.Pos("<<")+2);
                m_pLngList[STR_TEMP]->Add(IntToStr(ax)+sTmp);
                AnsiString sALID = m_pLngList[STR_AXIS]->Strings[ax]+" "+sTmp.SubString(1, sTmp.Pos("<<")-1);
                m_pLngList[STR_ALID]->Add(sALID);
            }
        } else {
            m_pLngList[STR_TEMP]->Add(m_pLngList[STR_ERR]->Strings[idx]);
            AnsiString sALID = m_pLngList[STR_ERR]->Strings[idx].SubString(1, m_pLngList[STR_ERR]->Strings[idx].Pos("<<")-1);
            m_pLngList[STR_ALID]->Add(sALID);
        }
    }
    //m_pLngList[STR_ALID]->SaveToFile("ALID.txt");    

    m_pLngList[STR_ERR]->Clear();
    for(int idx=0; idx<m_pLngList[STR_TEMP]->Count; idx++)
        m_pLngList[STR_ERR]->Add(m_pLngList[STR_TEMP]->Strings[idx]);

    delete m_pLngList[STR_TEMP];
    m_pLngList[STR_TEMP] = NULL;
}
//---------------------------------------------------------------------------
double __fastcall TExtern::CalDist(Coord pos1, Coord pos2)
{
    return sqrt(pow((pos2.x-pos1.x),2)+pow((pos2.y-pos1.y),2));
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::TtlPgsTime(int nDataNum, bool bRun, bool bReset)
{
    static unsigned long nTimeOfst[TTL_RUN];

    if(bRun)
        nTimeOfst[nDataNum] = (::GetTickCount()+run.nData[nDataNum])-run.nStartClock[nDataNum];
    else run.nData[nDataNum] = nTimeOfst[nDataNum];

    if(bReset)
        run.nData[nDataNum] = nTimeOfst[nDataNum] = 0;;

    unsigned int Day, Hour, Min, nSec = (nTimeOfst[nDataNum]/1000);
	Day=nSec/86400;
	Hour=(nSec % 86400)/3600;
	Min=(nSec % 3600)/60;
    nSec%=60;

    AnsiString sTime;
    sTime.sprintf("%04d:%02d:%02d", Hour+(Day*24), Min, nSec);
    return sTime;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::TtlPgsTime(int nDataNum, bool bRun)
{
    static bool bOneTimeRun[4];

    if(bRun) {
        run.nData[nDataNum] =
            (::GetTickCount()+run.nLoadTime[nDataNum])-run.nStartClock[nDataNum];
        bOneTimeRun[nDataNum] = true;
    } else {
        run.nStartClock[nDataNum] = ::GetTickCount();
        if(bOneTimeRun[nDataNum])
            run.nLoadTime[nDataNum] = run.nData[nDataNum];
    }

    unsigned int Day, Hour, Min, nSec = (run.nData[nDataNum]/1000);
	Day=nSec/86400;
	Hour=(nSec % 86400)/3600;
	Min=(nSec % 3600)/60;
    nSec%=60;

    AnsiString sTime;
    sTime.sprintf("%04d:%02d:%02d", Hour+(Day*24), Min, nSec);
    return sTime;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::RefreshSysRunData()
{
    run.bRun[TM_RUN] = (Work.m_nStatus != RSTOP && MainForm->ProductPanel->Visible);
    run.bRun[TM_STOP] = (Work.m_nStatus == RSTOP && MainForm->ProductPanel->Visible);
    run.bRun[TM_ERR] = (Chk.m_bMainErrEvent);

    static bool bErr;
    if(!Chk.m_bMainErrEvent) {
        bErr = false;
        run.bRun[TM_ERR] = false;
    }
    else if(!bErr && Chk.m_bMainErrEvent && Work.m_nStatus != RSTOP) {
        bErr = true;
        run.bRun[TM_ERR] = true;
        run.nData[TTL_ERR]++;
    }

    if(run.nData[TM_RUN] == 0)
        run.nData[TTL_UPH] = 0;
    else run.nData[TTL_UPH] = run.nData[TTL_OUT]*(3600.0/(run.nData[TM_RUN]/1000.));
    if(run.nData[TTL_ERR] == 0)
        run.nData[MTBA] = 0;
    else run.nData[MTBA] = (run.nData[TM_RUN]/1000.)/run.nData[TTL_ERR];
    run.nData[MTBF] = run.nData[MTBA];

    for(int i=0; i<=TM_ERR; i++)
        strcpy(run.chData[i], TtlPgsTime(i, run.bRun[i]).c_str());
    for(int i=MTBA; i<=MTTR; i++)
        strcpy(run.chData[i], SecToStr(run.nData[i], 4).c_str());
    for(int i=TTL_UPH; i<=TTL_ERR; i++)
        strcpy(run.chData[i], IntToStr(run.nData[i]).c_str());
}
//---------------------------------------------------------------------------
AnsiString __fastcall TExtern::GetFileName(AnsiString sFile)
{
    sFile = ExtractFileName(sFile);
    return sFile.Delete(sFile.Length()-3, sFile.Length());
}
//---------------------------------------------------------------------------
unsigned int __fastcall TExtern::StopWatch(bool bReset, bool bRun)
{
    static unsigned long nTtlClock, nTimeOfst, nStartClock;

    if(bRun)
        nTimeOfst = (::GetTickCount()+nTtlClock)-nStartClock;
    else {
        nTtlClock = nTimeOfst;
        nStartClock = ::GetTickCount();
    }

    if(bReset) nTimeOfst = nTtlClock = 0;

    return (nTimeOfst/1000);;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::DeleteAllFile(AnsiString sFilePath, AnsiString sFileName)
{
    int hFind;
    WIN32_FIND_DATA data;
    AnsiString sDir = sFilePath+"\\*.*";
    TSearchRec sr;

    hFind = FindFirst(sDir, faAnyFile, sr);
    while(hFind == 0) {
        if((sr.Attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
            AnsiString sName = sr.FindData.cFileName;
            if ( ( sName != ".") && ( sName != "..")) {
                sDir = sFilePath+"\\"+sName;
                DeleteAllFile(sDir, (sFileName.IsEmpty()?sDir:sFileName));
            }
        } else {
            AnsiString sName = sr.FindData.cFileName;
            if(sName.AnsiPos(sFileName) || sFileName.IsEmpty()) {
                sName = ExtractFilePath(sDir)+sName;
                DeleteFile(sName);
            }
        }
        hFind = FindNext(sr);
    }
    FindClose(sr);
}
//---------------------------------------------------------------------------
void __fastcall TExtern::ValidDayFileClean(AnsiString sPath, int nDay)
{
    Screen->Cursor = crHourGlass;
    MsgDlg->ShowBox("Validate Day File Cleaning.", MMB_SHOWONLY);

    int hFind;
    WIN32_FIND_DATA data;
    AnsiString sDir = sPath+"\\*.*";
    AnsiString sFileName ;
    TSearchRec sr;

    hFind = FindFirst(sDir, faAnyFile, sr);
    while(hFind == 0) {
        if((sr.Attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
            sFileName = sr.FindData.cFileName;
            if(sFileName != "." && sFileName != "..") {
                sDir = sPath+"\\"+sFileName;
                ValidDayFileClean(sDir, nDay);
            }
        } else {
            sFileName = sr.FindData.cFileName;
            if(FileDateToDateTime(sr.Time) < TDateTime(Now())-nDay) {
                AnsiString sFile = ExtractFilePath(sDir)+sFileName;
                DeleteFile(sFile);
            }
        }
        hFind = FindNext(sr);
    }
    FindClose(sr);

    MsgDlg->Close();
    Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::ValidDayDirClean(AnsiString sPath, int nDay)
{
    Screen->Cursor = crHourGlass;
    MsgDlg->ShowBox("Validate Day Directory Cleaning.", MMB_SHOWONLY);

    int hFind;
    WIN32_FIND_DATA data;
    AnsiString sDir = sPath+"\\*.*";
    AnsiString sFileName ;
    TSearchRec sr;

    hFind = FindFirst(sDir, faDirectory, sr);
    while(hFind == 0) {
        if((sr.Attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
            sFileName = sr.FindData.cFileName;
            if((sFileName != ".") && (sFileName != "..")) {
                sDir = sPath+"\\"+sFileName;
                if(FileDateToDateTime(sr.Time) < TDateTime(Now())-nDay) {
                    TSearchRec srFile;
                    sDir = sDir+"\\*.*";
                    int hFile = FindFirst(sDir, faAnyFile, srFile);
                    GO_BACK:
                    while(hFile == 0) {
                        if((srFile.Attr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
                            hFile = FindNext(srFile);
                            goto GO_BACK;
                        } else {
                            AnsiString sFile = srFile.FindData.cFileName;
                            sFile = ExtractFilePath(sDir)+sFile;
                            DeleteFile(sFile);
                        }
                        hFile = FindNext(srFile);
                    }
                    FindClose(srFile);
                    RemoveDirectory(ExtractFilePath(sDir).c_str());
                }
            }
        }
        hFind = FindNext(sr);
    }
    FindClose(sr);

    MsgDlg->Close();
    Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
double __fastcall TExtern::CalTwoPointDist(Coord pos1, Coord pos2)
{
    return sqrt(pow((pos2.x-pos1.x),2)+pow((pos2.y-pos1.y),2));
}
//---------------------------------------------------------------------------
void __fastcall TExtern::DrawWireRects(LPRECT lprcFrom, LPRECT lprcTo)
{
    /*
    UINT nMilliSecSpeed = 5;
    const int nNumSteps = 10;

    GdiFlush();
    Sleep(50);  // Let the desktop window sort itself out

    // if hwnd is null - "you have the CON".
    HDC hDC = ::GetDC(NULL);

    // Pen size, urmmm not too thick
    HPEN hPen = ::CreatePen(PS_SOLID, 2, RGB(0,0,0));

    int nMode = ::SetROP2(hDC, R2_NOT);
    HPEN hOldPen = (HPEN) ::SelectObject(hDC, hPen);

    for (int i = 0; i < nNumSteps; i++)
    {
        double dFraction = (double) i / (double) nNumSteps;

        RECT transition;
        transition.left   = lprcFrom->left +
            (int)((lprcTo->left - lprcFrom->left) * dFraction);
        transition.right  = lprcFrom->right +
            (int)((lprcTo->right - lprcFrom->right) * dFraction);
        transition.top    = lprcFrom->top +
            (int)((lprcTo->top - lprcFrom->top) * dFraction);
        transition.bottom = lprcFrom->bottom + 
            (int)((lprcTo->bottom - lprcFrom->bottom) * dFraction);

        POINT pt[5];
        pt[0] = TPoint(transition.left, transition.top);
        pt[1] = TPoint(transition.right,transition.top);
        pt[2] = TPoint(transition.right,transition.bottom);
        pt[3] = TPoint(transition.left, transition.bottom);
        pt[4] = TPoint(transition.left, transition.top);

        // We use Polyline because we can determine our own pen size
        // Draw Sides
        ::Polyline(hDC,pt,5);

        GdiFlush();

        Sleep(nMilliSecSpeed);

        // UnDraw Sides
        ::Polyline(hDC,pt,5);

        GdiFlush();
    }

    ::SetROP2(hDC, nMode);
    ::SelectObject(hDC, hOldPen);

    ::ReleaseDC(NULL,hDC);
    */
}
//---------------------------------------------------------------------------
double __fastcall TExtern::GetPkrHgtLsr()
{
/*
    TComPort *pCom = MainForm->PkrHgtLsrCom;
    char RecieveData[25],CheckErrData[25];
    char SendData[30]; AnsiString sBCC;
    unsigned int i, WaitTime; bool isComOk=false;
    unsigned BCC;  float Value;  int RetryCnt=2;
    AnsiString strP; bool isCheckErr;

    if(IO.In(pkrlsralarm))
        return pkrlsralarm;
    if(!pCom->Connected)
        return COM_ERR;

    strP.sprintf("%c010000101C00002000001%c",STX,ETX);
    strcpy(SendData,strP.c_str()); BCC = 0;
    for(i=1;i<strlen(SendData);i++)
        BCC^=SendData[i];
    sBCC.sprintf ("%c",BCC);
    strcat (SendData,sBCC.c_str());

    while (!isComOk) {
COM_AGAIN:
        CheckErrData[0]='\0';
        if (pCom->InputCount()>0) // Buffer clear
            pCom->Read(RecieveData,pCom->InputCount());
        pCom->WriteStr((AnsiString)SendData);
        WaitTime=GetTickCount()+300;
        int RecieveLength=25;
        isCheckErr=false;
        while (true) {
            if (pCom->InputCount()>=RecieveLength) {
                isComOk=true;
                break;
            }
            if (!isCheckErr && pCom->InputCount()>=9) {
                i=pCom->InputCount();
                pCom->Read(CheckErrData,i);
                CheckErrData[i]='\0';
                strP=(AnsiString)CheckErrData;
                // Return Code가 Error일 경우 자동으로 재 시도한다.
                if (strP.SubString(6,2)!="00")   goto COM_AGAIN;
                isCheckErr=true;
                RecieveLength=24-StrLen(CheckErrData);
            }
            DoEvents();
            if(GetTickCount()>WaitTime) break;
        }
        if (!isComOk) {
            if (--RetryCnt<0) return COM_ERR;
            Sleep(100);
        }
    }
    if (isCheckErr) {
        strcpy(RecieveData,CheckErrData);
        pCom->Read(CheckErrData,pCom->InputCount());
        strcat(RecieveData,CheckErrData);
    } else pCom->Read(RecieveData,pCom->InputCount());
    if (AnsiString(RecieveData)=="") return COM_ERR;
    strP=(AnsiString)RecieveData;
    if(strP.IsEmpty())
        return COM_ERR;
    try {
    Value=(float)StrToInt("0x"+strP.SubString(16,8))/1000.;
    } catch(...) { return COM_ERR;  }
    if (Value>=10. || Value<=-10.) return COM_ERR;
    return Value;
*/
    return 0.;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::trace(LPCTSTR lpszFormat)
{
	HWND hTracePlus = ::FindWindow(NULL,"TracePlus");
	if (hTracePlus)
	{
		char szBuf[4096]={0,};
		va_list args;
		va_start(args, lpszFormat);
		_vsntprintf(szBuf, 4095, lpszFormat, args);
		va_end(args);
		szBuf[4095] = 0;

		COPYDATASTRUCT cds;
		cds.dwData = 0;
		cds.cbData = strlen(szBuf);
		cds.lpData = szBuf;
		::SendMessage(hTracePlus, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
	}
}
//---------------------------------------------------------------------------
double __fastcall TExtern::GetMovingAvg(double dData)
{
    static int nCnt;
    static double *dTempData;
    static double *dOldData;
    double dMovingAvg = 0;

    if(nCnt < 9999) {
        dTempData = new double[nCnt+1];
        for(int i=0; (nCnt>0 && i<nCnt); i++)
            dTempData[i] = dOldData[i];
        delete dOldData;

        dTempData[nCnt] = dData;
        if(nCnt > 1)
            dMovingAvg = Math::Mean(dTempData, nCnt);

        dOldData = new double[nCnt+1];
        for(int i=0; i<nCnt+1; i++)
            dOldData[i] = dTempData[i];
        delete dTempData;
        nCnt++;
    } else {
        dTempData = new double[nCnt];
        for(int i=1; i<nCnt; i++)
            dTempData[i-1] = dOldData[i];
        delete dOldData;

        dTempData[nCnt-1] = dData;

        dMovingAvg = Math::Mean(dTempData, nCnt);

        dOldData = new double[nCnt];
        for(int i=0; i<nCnt; i++)
            dOldData[i] = dTempData[i];
        delete dTempData;
    }
    return dMovingAvg;
}
//---------------------------------------------------------------------------
double __fastcall TExtern::GetAngle(Coord crdOrg, Coord crdEnd)
{
    double dAngle;
    //작업시의 자재의 각도
    crdEnd.x = crdEnd.x-crdOrg.x;
    crdEnd.y = crdEnd.y-crdOrg.y;

    if(crdEnd.x == 0.) {
        if(crdEnd.y == 0.)
            dAngle = 0.;
        else if(crdEnd.y < 0.)
            dAngle = -90.;
        else dAngle = 90.;
    }
    else dAngle = atan2(crdEnd.y, crdEnd.x)*(180./M_PI);

    return dAngle;
}
//---------------------------------------------------------------------------
int __fastcall TExtern::GetMemoHeight(TMemo *Memo, int LineCount)
{
    if(!Memo->Visible)
        return 0;

    TCanvas *Can=new TCanvas;
    Can->Handle=GetDC(Memo->Handle);
    Can->Font=Memo->Font;
    int iHei=Can->TextHeight("W");
    ReleaseDC(Memo->Handle,Can->Handle);
    delete Can;

    if(LineCount == -1)
        return iHei*(Memo->Lines->Count)+8;
    return iHei*LineCount;
}
//---------------------------------------------------------------------------
DWORD __fastcall TExtern::FindProcessPid(String sExeFullName)
{
    String sExeName=ExtractFileName(sExeFullName);
    sExeName=sExeName.LowerCase();
    PROCESSENTRY32 pe32 = {0} ;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0) ;
    if (hSnapshot == INVALID_HANDLE_VALUE) return 0;
    if (!Process32First(hSnapshot, &pe32))return 0;
    do
    {
        String sProcessName=pe32.szExeFile;
        sProcessName=sProcessName.LowerCase();
       if(sProcessName==sExeName)
       {
            DWORD pid=pe32.th32ProcessID ;
            CloseHandle(hSnapshot);
            return pid;
       }
    } while(Process32Next(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
    return NULL;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::VisionDataLogAdd(bool bEnable, TListBox *pListBox)
{
    if(!bEnable) return;

    AnsiString sFileName = SYSLOG_FILE_PATH+"VisionData\\";
    if(!DirectoryExists(sFileName)) CreateDir(sFileName);

    sFileName = sFileName+FormatDateTime("yyyy-mm-dd", Now())+".vdl";

    FILE *fp;
    fp=fopen(sFileName.c_str(),"a+");
    fseek(fp,0,2); //Search End of
    AnsiString sTime = FormatDateTime("yyyy-mm-dd AM/PM hh:nn:ss", Now());
    fprintf(fp, "%s \r\n", sTime.c_str());
    for(int i=0; i<pListBox->Items->Count; i++)
        fprintf(fp, "%s \r\n", pListBox->Items->Strings[i].c_str());
    fclose(fp);
}
//---------------------------------------------------------------------------
void __fastcall TExtern::MarsLogAdd(AnsiString sMotion, int nMode, int nInPort, AnsiString sStartEnd)
{
    if(sMotion.IsEmpty()) return;

    AnsiString sFileName;
    sFileName = SYSLOG_FILE_PATH+"Motion\\";
    ForceDirectories(sFileName);
    sFileName = sFileName+FormatDateTime("yyyymmdd", Now())+"_MARS Log.log";

    AnsiString sDate = FormatDateTime("yyyy", Now())+"/"+FormatDateTime("mm", Now())+"/"+
            FormatDateTime("dd\thh:mm:ss.zzz\t", Now());
    AnsiString sLog = sDate+sMotion;

    AnsiString sMode;
    if(nMode == 0) {
        sMode = "";
    }
    else if(nMode == 1) {
        sMode = "";
    }
    else if(nMode == 2) {
        sMode = "";
    }
    else if(nMode == 3) {
        sMode = "";
    }

    sLog = sLog+sMode+"\t"+sStartEnd;

    FILE *fp;
    fp=fopen(sFileName.c_str(),"a+");
    fseek(fp,0,2); //Search End of
    fprintf(fp, "%s \r\n", sLog.c_str());
    fclose(fp);
}
//---------------------------------------------------------------------------
void __fastcall TExtern::DoEvents()
{
     MSG msg;
     if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
     }
}
//---------------------------------------------------------------------------
void __fastcall TExtern::CimLogAdd(AnsiString sLog)
{
    sLog.sprintf ("[%s] %s",TimeToStr(Now()),sLog);
    MainForm->CimLogListBox->Items->Add(sLog);
    if(MainForm->CimLogListBox->Items->Count >= 1000)
        MainForm->CimLogListBox->Items->Delete(0);
    MainForm->CimLogListBox->ItemIndex = MainForm->CimLogListBox->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TExtern::GetDescendantDir(TStringList *pListDirNames, AnsiString sPath)
{
    TSearchRec sr;
    try {
        if(FindFirst(sPath + "*.*", faAnyFile, sr) ==0) {
            while(FindNext(sr) == 0) {
                if(sr.Name != "." && sr.Name != ".." && sr.Attr == faDirectory) {
                    pListDirNames->Add(sPath + sr.Name + "\\");
                    GetDescendantDir(pListDirNames, sPath + sr.Name + "\\");
                }
            }
        }
    } __finally {
        FindClose(sr);
    }
}
//---------------------------------------------------------------------------
void __fastcall TExtern::GetDirFile(TStringList *pListFileName, AnsiString sPath)
{
    TSearchRec sr;
    try {
        if(FindFirst(sPath + "*.*", faAnyFile, sr) ==0) {
            while(FindNext(sr) == 0) {
                if(sr.Name != "." && sr.Name != ".." && sr.Attr != faDirectory)
                    pListFileName->Add(sPath + sr.Name);
            }
        }
    } __finally {
        FindClose(sr);
    }
}
//---------------------------------------------------------------------------
void __fastcall TExtern::GetAllFile(TStringList *pListFileName, AnsiString sPath)
{
    pListFileName->Clear();

    TStringList *pListDescPath = new TStringList;
    try {
        pListDescPath->Add(sPath);
        GetDescendantDir(pListDescPath, sPath);
        while(pListDescPath->Count) {
            GetDirFile(pListFileName, pListDescPath->Strings[pListDescPath->Count-1]);
            pListDescPath->Delete(pListDescPath->Count-1);
        }
    } __finally {
        delete pListDescPath;
    }
}
//---------------------------------------------------------------------------

void __fastcall TExtern::ReadMagRfTag( int TagNo )
{
    try{
        MagRfId = "";
        if( MainForm->ComPortRfReader->Connected )
            MainForm->ComPortRfReader->Close();
        MainForm->ComPortRfReader->Open();
        
        if( !MainForm->ComPortRfReader->Connected )
            throw;

        String type = "";
        String sendMsg = "\x44\x30\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";

        sendMsg += IntToStr( TagNo );

        int chksum = 0;
        for( int i = 0; i < sendMsg.Length();i++ )
            chksum ^= sendMsg.c_str()[i];
        sendMsg += (char)chksum;

        MainForm->ComPortRfReader->WriteStr(sendMsg);

    }
    catch(...) {

    }





}
//---------------------------------------------------------------------------

