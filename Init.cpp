//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Init.h"
#include "DataClass.h"
#include "Extern.h"
#include "MotionBase.h"
#include "InitProcess.h"
#include "Main.h"
#include "IOPort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzButton"
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDBaseLabel"
#pragma link "LMDCustomGlyphLabel"
#pragma link "LMDGlyphLabel"
#pragma resource "*.dfm"
TInitForm *InitForm;
//---------------------------------------------------------------------------
__fastcall TInitForm::TInitForm(TComponent* Owner)
    : TForm(Owner)
{
    m_nStatus = RSTOP;
}
//---------------------------------------------------------------------------
void __fastcall TInitForm::FormShow(TObject *Sender)
{
   	for(int ax=0; ax<AXES; ax++) {
        m_pHomeLbl[ax] = new TLMDGlyphLabel(this);
        m_pHomeLbl[ax]->Parent        = HomeSensGrpBox;
        m_pHomeLbl[ax]->ParentFont    = false;
        m_pHomeLbl[ax]->AutoSize      = false;
        m_pHomeLbl[ax]->Left 	      = HomeSensGrpBox->Left+6;
        m_pHomeLbl[ax]->Width         = 180;
        m_pHomeLbl[ax]->Font->Name    = "Arial";
        m_pHomeLbl[ax]->Font->Size    = 9;
        //m_pHomeLbl[ax]->Font->Style   = TFontStyles()<<fsBold;
        m_pHomeLbl[ax]->Caption       = Ext.m_pLngList[STR_AXIS]->Strings[ax];
        m_pHomeLbl[ax]->ImageList     = MainForm->LEDImageList1;
        m_pHomeLbl[ax]->ImageIndex    = 0;
    }

    int nPitch = HomeSensGrpBox->Height/(AXES+1);
    for(int i=0; i<AXES; i++)
        m_pHomeLbl[i]->Top = (HomeSensGrpBox->Top+(nPitch/2.0))+(nPitch*(i));

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->InitBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->InitBtn->Width, pt.y+MainForm->InitBtn->Height};
    Ext.DrawWireRects(&rectTo, &rectFrom);

    if(Init.m_bAuto)
        InitBtnClick(StartBtn);

    TickTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TInitForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if(Init.m_nStatus == RSTART)
        CanClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TInitForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    TickTimer->Enabled = false;

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->InitBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->InitBtn->Width, pt.y+MainForm->InitBtn->Height};
    Ext.DrawWireRects(&rectFrom, &rectTo);

}
//---------------------------------------------------------------------------
void __fastcall TInitForm::TickTimerTimer(TObject *Sender)
{
    static clock_t t1000ms = clock();
    if(Ext.CheckDelay(t1000ms, 1000)) {
        if(Init.m_nStatus != RSTOP) {
            if(StartBtn->Color == clGreen)
                StartBtn->Color = clLime;
            else StartBtn->Color = clGreen;
        }
        else StartBtn->Color = clGreen;
        t1000ms = clock();
    }
    
    StartBtn->Down = (Init.m_nStatus != RSTOP);
    StopBtn->Down = (Init.m_nStatus == RSTOP);

    if(Init.m_nStatus == RSTOP) {
        StopBtn->Color = clRed;
        StartBtn->Color = clGreen;
    }
    else StopBtn->Color = clMaroon;

    for(int ax=0; ax<AXES; ax++)
        m_pHomeLbl[ax]->ImageIndex = (Init.m_nHomePNo[ax]==0);
}
//---------------------------------------------------------------------------
void __fastcall TInitForm::InitBtnClick(TObject *Sender)
{
    TRzButton *ptr = dynamic_cast<TRzButton *>(Sender);

    if(ptr == StartBtn)
    {
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.On(DOORLOCK);
            Sleep(100);
        }
        Init.Start();
    }
    else if(ptr == StopBtn)
    {
        //kjseo 2017.03.23
        if( sys.fac.bAutoDoorLock )
        {
            IO.Off(DOORLOCK);
            Sleep(100);
        }
        Init.Stop();
    }
}
//---------------------------------------------------------------------------






