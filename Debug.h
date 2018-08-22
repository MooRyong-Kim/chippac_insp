//---------------------------------------------------------------------------

#ifndef DebugH
#define DebugH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TDebugForm : public TForm
{
__published:	// IDE-managed Components
    TTimer *DrawTimer;
    TPanel *InspPnl;
    TShape *Shape1;
    TShape *Shape2;
    TShape *Shape3;
    TShape *Shape4;
    TShape *Shape5;
    TPanel *UlPnl;
    TPanel *MgzPnl;
    TPaintBox *GoodMgzDrawBox;
    TPanel *RejMgzPnl;
    TPaintBox *RejMgzDrawBox;
    TPanel *Panel2;
    TPanel *Panel3;
    TShape *Shape6;
    TPanel *Panel4;
    TShape *Shape7;
    TCheckBox *Roll3DctChkBox;
    TCheckBox *Roll2DctChkBox;
    TCheckBox *Roll1DctChkBox;
    TCheckBox *InspZoneDctChkBox;
    TCheckBox *MgzGripGoodChkBox;
    TCheckBox *RejCvyStprDctChkBox;
    TCheckBox *UlCvyStprDctChkBox;
    TPopupMenu *PopupMenu1;
    TMenuItem *PositionReset1;
    TMenuItem *Home1;
    TCheckBox *InspRdyOkChkBox;
    TPanel *Panel1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall DrawTimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall MenuItemClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
    TRect m_rtForm;
    void __fastcall PickUpToolStatusDraw();
public:		// User declarations
    __fastcall TDebugForm(TComponent* Owner);
    void __fastcall MotionDraw();
};
//---------------------------------------------------------------------------
extern PACKAGE TDebugForm *DebugForm;
//---------------------------------------------------------------------------
#endif
