/***************************************************************************
'   created       : 2015-11-25 PM 8:00:00
'   file name     : Common Data Module
'   function name : System Error Viewer.
'   argument      :
'   return        : Display of Exception Error.
'   purpose       :
'   caution       :
'   author        : Ki-Joo, Jeong CJ(PROTEC Co.,Ltd.)
****************************************************************************/

#ifndef SystemErrorViewH
#define SystemErrorViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSystemErrorViewForm : public TForm
{
__published:	// IDE-managed Components
    TMemo *memoSysError;
    TButton *btnClose;
    TLabel *Label1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TSystemErrorViewForm(TComponent* Owner);

    // Define Member Function
    void SysErrorShow(AnsiString strMsg, AnsiString strCaption, int nFlag=MB_OK|MB_ICONERROR);
};
//---------------------------------------------------------------------------
extern PACKAGE TSystemErrorViewForm *SystemErrorViewForm;
//---------------------------------------------------------------------------
#endif
