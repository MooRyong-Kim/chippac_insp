//---------------------------------------------------------------------------
#include <vcl.h>
#include "SystemErrorView.h"
#pragma hdrstop
USEFORM("Jog.cpp", JogForm);
USEFORM("Password.cpp", PasswordForm);
USEFORM("Splash.cpp", SplashForm);
USEFORM("Init.cpp", InitForm);
USEFORM("Maint.cpp", MaintForm);
USEFORM("WorkSetup.cpp", WorkSetupForm);
USEFORM("Prepare.cpp", PrepareForm);
USEFORM("Msg.cpp", MsgDlg);
USEFORM("Main.cpp", MainForm);
USEFORM("DataView.cpp", DataViewForm);
USEFORM("SysSetup.cpp", SysSetupForm);
USEFORM("SecsGem.cpp", SecsGemForm);
USEFORM("Debug.cpp", DebugForm);
USEFORM("SystemErrorView.cpp", SystemErrorViewForm);
USEFORM("DM_Common.cpp", DM_Co); /* TDataModule: File Type */
USEFORM("SubmapViwer.cpp", FormSubMapViewer);
//---------------------------------------------------------------------------
#include "Splash.h"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    HANDLE Mutex;
    try
    {
        const char *ProgMutex = "ZeusInsp";
        Mutex = OpenMutex(MUTEX_ALL_ACCESS, false, ProgMutex);
        if(!Mutex)
            CreateMutex(NULL, true, ProgMutex);
        else {
            ShowMessage("Already Program Running!");
            return 0;
        }

         Application->Initialize();
         Application->Title = "ZeusInsp";
         Application->CreateForm(__classid(TDM_Co), &DM_Co);
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TSplashForm), &SplashForm);
         Application->CreateForm(__classid(TMsgDlg), &MsgDlg);
         Application->CreateForm(__classid(TPrepareForm), &PrepareForm);
         Application->CreateForm(__classid(TPasswordForm), &PasswordForm);
         Application->CreateForm(__classid(TJogForm), &JogForm);
         Application->CreateForm(__classid(TInitForm), &InitForm);
         Application->CreateForm(__classid(TMaintForm), &MaintForm);
         Application->CreateForm(__classid(TWorkSetupForm), &WorkSetupForm);
         Application->CreateForm(__classid(TDataViewForm), &DataViewForm);
         Application->CreateForm(__classid(TSysSetupForm), &SysSetupForm);
         Application->CreateForm(__classid(TSecsGemForm), &SecsGemForm);
         Application->CreateForm(__classid(TDebugForm), &DebugForm);
         Application->CreateForm(__classid(TSystemErrorViewForm), &SystemErrorViewForm);
         Application->CreateForm(__classid(TFormSubMapViewer), &FormSubMapViewer);
         Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    ReleaseMutex(Mutex);
    return 0;
}
//--------------------------------------------------------------------------


