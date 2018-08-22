//---------------------------------------------------------------------------

#ifndef PasswordH
#define PasswordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
class TPasswordForm : public TForm
{
__published:	// IDE-managed Components
     TLabel *Label1;
     TEdit *PasswordInput;
     TBitBtn *Permission;
     TBitBtn *Cancel;
     TImage *Image1;
     TLabel *LevelDisp;
    TTimer *TickTimer;
     void __fastcall PermissionClick(TObject *Sender);
     void __fastcall CancelClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    int m_nLevel;
public:		// User declarations
    int m_nResult;
     __fastcall TPasswordForm(TComponent* Owner);
    int __fastcall PasswordCheck(int nLevel, AnsiString sMsg="");
};
//---------------------------------------------------------------------------
extern PACKAGE TPasswordForm *PasswordForm;
//---------------------------------------------------------------------------
#endif
