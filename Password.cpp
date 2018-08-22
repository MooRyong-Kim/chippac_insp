//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Password.h"
#include "DataClass.h"
#include "WorkProcess.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPasswordForm *PasswordForm;
//---------------------------------------------------------------------------
__fastcall TPasswordForm::TPasswordForm(TComponent* Owner)
     : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::FormShow(TObject *Sender)
{
    if(m_nLevel == 0)
        LevelDisp->Caption="Operator Level";
    else if(m_nLevel == 10)
        LevelDisp->Caption="Engineer Level";
    else if(m_nLevel == 100)
        LevelDisp->Caption="Factory Level";

    m_nResult = PSWD_MISS;
    PasswordInput->Visible = true;    
    PasswordInput->Text="";
    PasswordInput->SetFocus();
    TickTimer->Enabled = true;
}
//---------------------------------------------------------------------------
int __fastcall TPasswordForm::PasswordCheck(int nLevel, AnsiString sMsg)
{
    m_nLevel = nLevel;

    if(!sMsg.IsEmpty())
        PasswordForm->Caption = sMsg;
    else PasswordForm->Caption = "Password";
    PasswordForm->ShowModal();

    return m_nResult;
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    TickTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::PermissionClick(TObject *Sender)
{
    if(PasswordInput->Text != "") {
        if(m_nLevel == 0) {
            if(PasswordInput->Text == AnsiString(sys.eng.chOprPswd))
                m_nResult = PSWD_OPR_MATCH;
        }
        else if(m_nLevel == 0 || m_nLevel == 10) {
            if(PasswordInput->Text == AnsiString(sys.eng.chEngPswd))
                m_nResult = PSWD_ENG_MATCH;
        }
        AnsiString sTime;
        sTime.sprintf("HHMMDD", Now());

        if(PasswordInput->Text == FACTORY_PASSWORD ||
            PasswordInput->Text == sTime) {
            m_nResult = PSWD_FAC_MATCH;
        }
    }
    PasswordForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::CancelClick(TObject *Sender)
{
    m_nResult = PSWD_CANCEL;
    PasswordForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::FormKeyPress(TObject *Sender, char &Key)
{
    if(Key == 27) //ESC
        CancelClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPasswordForm::TickTimerTimer(TObject *Sender)
{
    if(sys.fac.bDebugMode) {
        m_nResult = PSWD_FAC_MATCH;
        this->Close();
    }
    TickTimer->Interval = 300;

    for(char c='d'; c<='z'; c++) {
        AnsiString sDrive = AnsiString(c)+":\\";
        if(GetDriveType(sDrive.c_str()) == DRIVE_REMOVABLE) {
            AnsiString sFilePath = sDrive+"Password.protec";
            FILE *fp;
            if((fp=fopen(sFilePath.c_str(), "rb")) != NULL) {
                char chData[32];
                fread(&chData, sizeof(chData), 1, fp);
                fclose(fp);
                PasswordInput->Visible = false;
                PasswordInput->Text = chData;
                PermissionClick(Sender);
            }
        }
    }
}
//---------------------------------------------------------------------------


