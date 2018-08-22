//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomPanel"
#pragma link "LMDCustomPanelFill"
#pragma link "LMDCustomParentPanel"
#pragma link "LMDPanelFill"
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
void __fastcall TSplashForm::CreateParams(TCreateParams &Params)
{
    TForm::CreateParams(Params);
    Params.Style &= ~WS_CAPTION;
}
//---------------------------------------------------------------------------
*/
void __fastcall TSplashForm::FormCreate(TObject *Sender)
{
    HWND hRegion;
    hRegion = CreateRoundRectRgn(0,0, 502, 253, 40, 40);
    SetWindowRgn(SplashForm->Handle, hRegion, True);
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::InitStatus(AnsiString sInitMsg)
{
    SplashForm->InitPgsIndiLbl->Caption = sInitMsg;
    SplashForm->Repaint();
    Sleep(50);
}

