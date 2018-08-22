//---------------------------------------------------------------------------

#ifndef DM_MgrH
#define DM_MgrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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

#include <ExtCtrls.hpp>
#include <Syncobjs.hpp>
#include <FileCtrl.hpp>

//---------------------------------------------------------------------------
class TDM_Co : public TDataModule
{
__published:	// IDE-managed Components
    TTimer *GUI_Msg;
    void __fastcall GUI_MsgTimer(TObject *Sender);
    void __fastcall DataModuleDestroy(TObject *Sender);

private:	// User declarations
    void __fastcall AppFnException(TObject* Sender, Exception* E);

public:		// User declarations
    __fastcall TDM_Co(TComponent* Owner);

    // Define Member Variable
    TStringList *m_slErrorMsgBuf; // 표시할 Error 메세지 저장 버퍼
    TStringList *m_slAlarmBuf;
    bool        m_bErrorDlg;

    // Define Member Function
};
//---------------------------------------------------------------------------
extern PACKAGE TDM_Co *DM_Co;
//---------------------------------------------------------------------------

// Define Extern Function
extern void  AddErrorMsg(AnsiString strFilePath, AnsiString strLog, AnsiString strCaption=NULL, int nFlag=MB_OK|MB_ICONERROR, bool bBreakStop=false);
extern DWORD GetGUIThreadID();
extern bool  SaveCaptureScreen(AnsiString strFilePath);
extern void  DoEvents();
#endif
