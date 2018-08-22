/***************************************************************************
'   created       : 2015-11-25 PM 8:00:00
'   file name     : Common Data Module
'   function name : System Error Watcher.
'   argument      :
'   return        : Snapshot of Exception Error.
'   purpose       :
'   caution       : It should be the first to Create When creating applications.
'   author        : Ki-Joo, Jeong CJ(PROTEC Co.,Ltd.)
****************************************************************************/
//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <exception>
#pragma hdrstop

#include "DM_Common.h"
#include "SystemErrorView.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TDM_Co      *DM_Co;

// GUI Thread ID
DWORD       g_dwGuiThreadId(0);

// Error Message 관리
AnsiString  g_strErrorMsg("");
AnsiString  g_strDlgCaption("");
AnsiString  g_strPrevLog("");
int         g_nFlag(0);
int         g_nDlgRet(0);

// Evnet
TEvent      *g_eventMsg(NULL); // Message or Dialog를 위한 이벤트

//---------------------------------------------------------------------------
__fastcall TDM_Co::TDM_Co(TComponent* Owner)
	: TDataModule(Owner)
{
    AnsiString strGuiThreadId("");
    m_bErrorDlg     = false;
    m_slErrorMsgBuf = new TStringList();
    m_slAlarmBuf    = new TStringList();
    g_eventMsg      = new TEvent(NULL, true, true, "SysErrorEvent");

    // Get Current GUI Thread ID.
    g_dwGuiThreadId = GetCurrentThreadId();
    strGuiThreadId.printf("GUI Thread Id = %d", g_dwGuiThreadId);
    //AddErrorMsg(strGuiThreadId);

    g_eventMsg->ResetEvent();

    Application->OnException = AppFnException; // Set Exception event handler.
}
//---------------------------------------------------------------------------
void __fastcall TDM_Co::DataModuleDestroy(TObject *Sender)
{
    if(m_slErrorMsgBuf != NULL)
    {
        m_slErrorMsgBuf->Clear();
        delete m_slErrorMsgBuf;
    }
    if(m_slAlarmBuf != NULL)
    {
        m_slAlarmBuf->Clear();
        delete m_slAlarmBuf;
    }

    delete g_eventMsg;
}
//---------------------------------------------------------------------------
// Create Exception event Handler.
void __fastcall TDM_Co::AppFnException(System::TObject* Sender, Sysutils::Exception* E)
{
    AnsiString sDirectoryPath("");
    String sObj(""), strErrorInfo(""), strErrorMsg("");

    if(Sender)
    {
        if(Sender->InheritsFrom(__classid(TControl)))
        {
            // 1. Exception Case : Control
            TControl* ctrl = (TControl*)Sender;
            while(ctrl)
            {
                sObj = ctrl->Name + " -> " + sObj;
                ctrl = ctrl->Parent ;
            }
            strErrorInfo = + "Control Object : " + sObj;
        }
        else if(Sender->InheritsFrom(__classid(TComponent)))
        {
            // 2. Exception Case : Component
            TComponent* comp = (TComponent*)Sender;
            sObj = comp->Name;
            if(comp->Owner)
            {
                sObj = comp->Owner->Name +  " -> " +  sObj;
            }
            strErrorInfo = "Component Object : "  + sObj;
        }
        else
        {
            // 3. Exception Case : Moduel / Class
            strErrorInfo = "Module Object : " + Sender->ClassName();
        }
    }

    strErrorMsg = "Time : "    + Now().FormatString("yyyy-mm-dd hh:nn:ss") + "\r\n"
                + strErrorInfo + "\r\n"
                + "Message : " + E->Message + "\r\n";

    // Check Directory Exists : ERROR
    sDirectoryPath = ExtractFilePath(Application->ExeName) + "ERROR\\";
    if (!DirectoryExists(sDirectoryPath))
    {
    	ForceDirectories(sDirectoryPath);
    }

    // Check Directory Exists : Date
    sDirectoryPath += FormatDateTime("[yyyy-mm-dd]", Now()) + "\\";
    if (!DirectoryExists(sDirectoryPath))
    {
    	ForceDirectories(sDirectoryPath);
    }

    AddErrorMsg(sDirectoryPath, strErrorMsg, "[Dispenser Error Information]");
}
//---------------------------------------------------------------------------
void __fastcall TDM_Co::GUI_MsgTimer(TObject *Sender)
{
    if(g_strErrorMsg.IsEmpty() == false)
    {
        if(g_strDlgCaption != NULL)
        {
            AnsiString s(FormatDateTime("[mm-dd hh:nn:ss] ", Now()));
            s += "[" + g_strDlgCaption + "]" + g_strErrorMsg;

            g_eventMsg->SetEvent();
            AnsiString sTemp(g_strErrorMsg);
            g_strErrorMsg = "";
        }
        else
        {
            AnsiString s(FormatDateTime("[mm-dd hh:nn:ss] ", Now()));
            s += g_strErrorMsg;

            g_eventMsg->SetEvent();
            g_strErrorMsg = "";
        }
    }
}
//---------------------------------------------------------------------------
void AddErrorMsg(AnsiString strFilePath, AnsiString strMsg, AnsiString strCaption, int nFlag, bool bBreakStop)
{
    if(GetCurrentThreadId() != g_dwGuiThreadId)
    {
        AnsiString s(FormatDateTime("[mm-dd hh:nn:ss] ", Now()));

        g_eventMsg->WaitFor(100);
        g_eventMsg->ResetEvent();

        g_strErrorMsg   = strMsg;
        g_nFlag         = nFlag;
        g_strDlgCaption = strCaption;

        s += "[" + g_strDlgCaption + "]" + g_strErrorMsg;

        if(strCaption != NULL && (nFlag>>4)==(MB_ICONERROR>>4))
        {
            DM_Co->m_slAlarmBuf->Add(s);
        }

        DM_Co->m_slErrorMsgBuf->Add(s);
    }
    else
    {
        // timer등에 의한 반복 실행 방지
        if(g_strPrevLog == strMsg)
        {
            return;
        }

        g_strPrevLog  = strMsg;
        g_strErrorMsg = strMsg;

        // GUI Thread에서 나온 event 처리
        if(strCaption != NULL)
        {
            AnsiString s(FormatDateTime("[mm-dd hh:nn:ss] ", Now()));
            s += "[" + strCaption + "]" + strMsg;
        }
        else
        {
            AnsiString s(FormatDateTime("[mm-dd hh:nn:ss] ", Now()));
            s += strMsg;
        }

        if(strCaption != NULL)
        {
            // Dlg SystemErrorViewForm 생성 후.
            if(SystemErrorViewForm != NULL)
            {
                SystemErrorViewForm->SysErrorShow(strMsg, strCaption);
                Sleep(100);
                DoEvents();
                Sleep(300);
                DoEvents();
                SaveCaptureScreen(strFilePath);
            }
            else
            {
              // Dlg SystemErrorViewForm 생성 전.
              g_nDlgRet = Application->MessageBox(strMsg.c_str(), strCaption.c_str(), nFlag);  // todo : Dialog -> Dlg
            }
        }
    }
}
//---------------------------------------------------------------------------
bool SaveCaptureScreen(AnsiString strFilePath)
{
    DWORD               dwBytesWritten(0);
    DWORD               dwBmpSize(0);
    DWORD               dwSizeofDIB(0);
    RECT                rcClient;
    char                *lpbitmap;
    AnsiString          sFileName("");
    SYSTEMTIME	        SystemTime;
    HANDLE              hDIB(NULL);
    HANDLE              hFile(NULL);

    BITMAPFILEHEADER    bmpFileHeader;
    BITMAPINFOHEADER    bmpInfoHeader;
    HWND                hWnd(::GetDesktopWindow());
    HDC                 hdcScreen(::GetDC(NULL));                   // Retrieve the handle to a display device context for the client
    HDC                 hdcWindow(::GetDC(hWnd));                   // area of the window.
    HDC                 hdcMemDC(::CreateCompatibleDC(hdcWindow));  // Create a compatible DC which is used in a BitBlt from the window DC
    HBITMAP             hbmScreen(NULL);
    BITMAP              bmpScreen;

    if(!hdcMemDC)
    {
        Application->MessageBox("CreateCompatibleDC has failed", "Failed", MB_OK|MB_ICONERROR);
        ::DeleteObject(hbmScreen); ::DeleteObject(hdcMemDC); ::ReleaseDC(NULL,hdcScreen); ::ReleaseDC(hWnd,hdcWindow);
        return false;
    }

    ::GetClientRect(hWnd, &rcClient);            // Get the client area for size calculation
    ::SetStretchBltMode(hdcWindow, HALFTONE);    // This is the best stretch mode

    // The source DC is the entire screen and the destination DC is the current window (HWND)
    if(!::StretchBlt(hdcWindow, 0, 0, rcClient.right, rcClient.bottom, hdcScreen, 0, 0, GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN), 13369376))
    {
        Application->MessageBox("StretchBlt has failed", "Failed", MB_OK|MB_ICONERROR);
        ::DeleteObject(hbmScreen); ::DeleteObject(hdcMemDC); ::ReleaseDC(NULL,hdcScreen); ::ReleaseDC(hWnd,hdcWindow);
        return false;
    }

    // Create a compatible bitmap from the Window DC
    hbmScreen = ::CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);
    
    if(!hbmScreen)
    {
        Application->MessageBox("CreateCompatibleBitmap Failed", "Failed", MB_OK|MB_ICONERROR);
        ::DeleteObject(hbmScreen); ::DeleteObject(hdcMemDC); ::ReleaseDC(NULL,hdcScreen); ::ReleaseDC(hWnd,hdcWindow);
        return false;
    }

    ::SelectObject(hdcMemDC,hbmScreen); // Select the compatible bitmap into the compatible memory DC.

    // Bit block transfer into our compatible memory DC.
    if(!::BitBlt(hdcMemDC, 0, 0, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, hdcWindow, 0, 0, 13369376))
    {
        Application->MessageBox("BitBlt has failed", "Failed", MB_OK|MB_ICONERROR);
        ::DeleteObject(hbmScreen); ::DeleteObject(hdcMemDC); ::ReleaseDC(NULL,hdcScreen); ::ReleaseDC(hWnd,hdcWindow);
        return false;
    }

    ::GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen); // Get the BITMAP from the HBITMAP

    bmpInfoHeader.biSize          = sizeof(BITMAPINFOHEADER);
    bmpInfoHeader.biWidth         = bmpScreen.bmWidth;
    bmpInfoHeader.biHeight        = bmpScreen.bmHeight;
    bmpInfoHeader.biPlanes        = 1;
    bmpInfoHeader.biBitCount      = 32;
    bmpInfoHeader.biCompression   = BI_RGB;
    bmpInfoHeader.biSizeImage     = 0;
    bmpInfoHeader.biXPelsPerMeter = 0;
    bmpInfoHeader.biYPelsPerMeter = 0;
    bmpInfoHeader.biClrUsed       = 0;
    bmpInfoHeader.biClrImportant  = 0;

    dwBmpSize = ((bmpScreen.bmWidth * bmpInfoHeader.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;

    // Starting with 32-bit Windows, GlobalAlloc and LocalAlloc are implemented as wrapper functions that
    // call HeapAlloc using a handle to the process's default heap. Therefore, GlobalAlloc and LocalAlloc
    // have greater overhead than HeapAlloc.
    hDIB = ::GlobalAlloc(GHND,dwBmpSize);
    lpbitmap = (char *)::GlobalLock(hDIB);

    ::GetDIBits(hdcWindow, hbmScreen, 0, (UINT)bmpScreen.bmHeight, lpbitmap,(BITMAPINFO *)&bmpInfoHeader, DIB_RGB_COLORS); // Gets the "bits" from the bitmap and copies them into a buffer. which is pointed to by lpbitmap.

    ::GetLocalTime(&SystemTime);
    sFileName.sprintf( "%s[ERROR]%04d%02d%02d-%02d%02d%02d.bmp", strFilePath, SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay, SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);

    hFile = CreateFile(sFileName.c_str(), GENERIC_WRITE, 0 ,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);   // A file is created, this is where we will save the screen capture.

    dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);                              // Add the size of the headers to the size of the bitmap to get the total file size

    bmpFileHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER);                // Offset to where the actual bitmap bits start.
    bmpFileHeader.bfSize    = dwSizeofDIB;                                                                      // Size of the file
    bmpFileHeader.bfType    = 0x4D42;                                                                           // bfType must always be BM for Bitmaps//BM

    ::WriteFile(hFile, (LPSTR)&bmpFileHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
    ::WriteFile(hFile, (LPSTR)&bmpInfoHeader, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
    ::WriteFile(hFile, (LPSTR)lpbitmap,       dwBmpSize,                &dwBytesWritten, NULL);

    // Unlock and Free the DIB from the heap
    ::GlobalUnlock(hDIB);
    ::GlobalFree(hDIB);

    // Close the handle for the file that was created
    ::CloseHandle(hFile);
       
    // Clean up
    ::DeleteObject(hbmScreen);
    ::DeleteObject(hdcMemDC);
    ::ReleaseDC(NULL,hdcScreen);
    ::ReleaseDC(hWnd,hdcWindow);

    return true;
}
//---------------------------------------------------------------------------
void DoEvents()
{
	MSG message;

	if(::PeekMessage(&message,NULL,0,0,PM_REMOVE))
	{
		::TranslateMessage(&message);
		::DispatchMessage(&message);
	}
}
