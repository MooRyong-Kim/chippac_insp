//---------------------------------------------------------------------------

#ifndef InitH
#define InitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include "RzButton.hpp"
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDBaseLabel.hpp"
#include "LMDCustomGlyphLabel.hpp"
#include "LMDGlyphLabel.hpp"
class TInitForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *HomeSensGrpBox;
    TGroupBox *InitPgsViewGrpBox;
    TListBox *InitMsgListBox;
    TPanel *Panel3;
    TTimer *TickTimer;
    TBitBtn *BitBtn1;
    TRzButton *StartBtn;
    TRzButton *StopBtn;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall InitBtnClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
    TLMDGlyphLabel *m_pHomeLbl[AXES];
    int m_nLEDCnt;
public:		// User declarations
    int m_nStatus;
    __fastcall TInitForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInitForm *InitForm;
//---------------------------------------------------------------------------
#endif
