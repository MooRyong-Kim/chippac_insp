//---------------------------------------------------------------------------

#ifndef JogH
#define JogH
//---------------------------------------------------------------------------
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicButton.hpp"
#include "LMDButton.hpp"
#include "LMDControl.hpp"
#include "LMDCustomButton.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomScrollBox.hpp"
#include "LMDCustomSpeedButton.hpp"
#include "LMDCustomTrackBar.hpp"
#include "LMDListBox.hpp"
#include "LMDSpeedButton.hpp"
#include "LMDTrackBar.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include <Buttons.hpp>
#include "LMDBaseGraphicControl.hpp"
//---------------------------------------------------------------------------
class TJogForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *BottonPanel;
    TLMDTrackBar *JogSpdTrackBar;
    TShape *Shape2;
    TPanel *TopPanel;
    TComboBox *JogPartSelCmbBox;
    TLMDListBox *JogAxisSelListBox;
    TLMDSpeedButton *JogLeftUpBtn;
    TLMDSpeedButton *JogUpBtn;
    TLMDSpeedButton *JogRightUpBtn;
    TLMDSpeedButton *JogRightBtn;
    TLMDSpeedButton *JogRightDownBtn;
    TLMDSpeedButton *JogDownBtn;
    TLMDSpeedButton *JogEnterBtn;
    TLMDSpeedButton *JogLeftBtn;
    TLMDSpeedButton *JogLeftDownBtn;
    TSpeedButton *HomeBtn;
    TTimer *TickTimer;
    TSpeedButton *AbsBtn;
    TEdit *PitchMoveEdit;
    TSpeedButton *PitchMoveBtn;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall JogBtnMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall JogBtnMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall JogPartSelCmbBoxChange(TObject *Sender);
    void __fastcall JogBtnMouseEnter(TObject *Sender);
    void __fastcall JogBtnMouseExit(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall JogBtnClick(TObject *Sender);
    void __fastcall SpdBtnClick(TObject *Sender);
private:	// User declarations
    int __fastcall MoveDir(int nAxis, int nDir);
    void __fastcall JogFormDataRefresh();    
    void __fastcall AppMessage(tagMSG &Msg, bool &Handled);
    void __fastcall PitchMove(int nAxis, double dPitch, int nDir);
public:		// User declarations
    double m_dBasePos[AXES];
    __fastcall TJogForm(TComponent* Owner);
    void __fastcall DrawHeadPosOnMovePanel(TImage *pPanel, int nPkr);
    bool __fastcall IsInRect(TRect rtRect, TPoint ptPos);
    bool __fastcall SendJogPadCommand(char cmd, char dat);
    void __fastcall ArrowKeyDown(int nDir);
    void __fastcall ArrowKeyUp(int nDir);
};
//---------------------------------------------------------------------------
extern PACKAGE TJogForm *JogForm;
//---------------------------------------------------------------------------
#endif
