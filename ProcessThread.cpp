//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "ProcessThread.h"
#include "WorkProcess.h"
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TProcessThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall TProcessThread::TProcessThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TProcessThread::Execute()
{
    static bool bInThread;
	//---- Place thread code here ----
    while(!Terminated) {
		Synchronize(Update);
        WaitForSingleObject((void *)this->Handle, 1);
    }
}
//---------------------------------------------------------------------------
void __fastcall TProcessThread::Update()
{
    static bool bInThread;

    if(!bInThread) {
        bInThread = true;
        Work.MainProcess();
        bInThread = false;
    }
}
//---------------------------------------------------------------------------


