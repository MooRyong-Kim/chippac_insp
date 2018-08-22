//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Debug.h"
#include "MotionBase.h"
#include "Extern.h"
#include "Main.h"
#include "IOPort.h"
#include "WorkProcess.h"
#include "Msg.h"
#include "DataClass.h"
#include "WorkSetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDebugForm *DebugForm;
//---------------------------------------------------------------------------
__fastcall TDebugForm::TDebugForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormCreate(TObject *Sender)
{
    m_rtForm.Left = this->Left;
    m_rtForm.Top = this->Top;
    m_rtForm.Right = this->Left+this->Width;
    m_rtForm.Bottom = this->Top+this->Height;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormShow(TObject *Sender)
{
    this->DoubleBuffered = true;
    run.posInsp.x = InspPnl->Left;
    run.posInsp.y = InspPnl->Top;

    run.posUl.y = UlPnl->Left;
    run.posUl.z = MgzPnl->Top;

    run.dRejMgzPos = RejMgzPnl->Top;

    DrawTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::MotionDraw()
{
    InspPnl->Left = run.posInsp.x+(MB.GetPos(IX)/2.);
    InspPnl->Top = run.posInsp.y+(MB.GetPos(IY)/2.);

    UlPnl->Left = run.posUl.y-(MB.GetPos(UY)/2.);
    MgzPnl->Top = run.posUl.z-(MB.GetPos(UZ)/2.);

}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::DrawTimerTimer(TObject *Sender)
{
    MotionDraw();

    static clock_t tTick = clock();
    if(Ext.CheckDelay(tTick, 50)) {
        MainForm->MgzStatusDraw();
        tTick = clock();
    }
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    DrawTimer->Enabled = false;
    DebugForm->Align = alNone;
    this->ManualFloat(m_rtForm);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::MenuItemClick(TObject *Sender)
{
    TMenuItem *pItem = dynamic_cast<TMenuItem*>(Sender);

    if(pItem == PositionReset1) {
        if(MsgDlg->ShowBox("Do Position Reset?",MMB_YESNO|MMI_INFO,0,STR_MSG) == MID_NO)
            return;

        for(int i=0; i<AXES; i++)
            MB.SetPosZero(i);

        run.posInsp.x = InspPnl->Left;
        run.posInsp.y = InspPnl->Top;

        run.posUl.y = UlPnl->Left;
        run.posUl.z = MgzPnl->Top;

        Data.SaveRunData();
    }
    else if(pItem == Home1) {
        for(int i=0; i<AXES; i++)
            MB.SetPosZero(i);
    }
}
//---------------------------------------------------------------------------


