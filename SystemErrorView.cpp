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

#include <vcl.h>
#pragma hdrstop

#include "SystemErrorView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSystemErrorViewForm *SystemErrorViewForm;
//---------------------------------------------------------------------------
__fastcall TSystemErrorViewForm::TSystemErrorViewForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSystemErrorViewForm::FormCreate(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TSystemErrorViewForm::FormShow(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TSystemErrorViewForm::btnCloseClick(TObject *Sender)
{
    this->Hide();
}
//---------------------------------------------------------------------------
void TSystemErrorViewForm::SysErrorShow(AnsiString strMsg, AnsiString strCaption, int nFlag)
{
    this->Caption = strCaption;
    this->memoSysError->Clear();
    this->memoSysError->Text = strMsg;
    this->Show();
    this->Repaint();
}


