//---------------------------------------------------------------------------

#ifndef MaintH
#define MaintH
#include "ConstDefine.h"
//---------------------------------------------------------------------------
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
#include <ImgList.hpp>
#include "LMDBaseControl.hpp"
#include "LMDBaseEdit.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDBaseLabel.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomEdit.hpp"
#include "LMDCustomExtSpinEdit.hpp"
#include "LMDCustomGlyphLabel.hpp"
#include "LMDCustomImageList.hpp"
#include "LMDCustomMaskEdit.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDGlyphLabel.hpp"
#include "LMDImageList.hpp"
#include "LMDSpinEdit.hpp"
#include "RzPanel.hpp"
#include "RzRadGrp.hpp"
#include "RzTabs.hpp"
#include "LMDButtonControl.hpp"
#include "LMDCheckBox.hpp"
#include "LMDCustomCheckBox.hpp"
#include "RzButton.hpp"
class TMaintForm : public TForm
{
__published:	// IDE-managed Components
    TLMDImageList *LEDImageList1;
    TLMDImageList *LEDImageList2;
    TPanel *BtnPanel;
    TBitBtn *CloseBtn;
    TButton *ReadIOBtn;
    TRzPageControl *MaintPageCtrl;
    TRzTabSheet *TabSheet7;
    TRzTabSheet *TabSheet9;
    TRzTabSheet *TabSheet10;
    TRzTabSheet *TabSheet12;
    TRzTabSheet *TabSheet13;
    TRzGroupBox *RzGroupBox1;
    TLMDGlyphLabel *InLED0;
    TLMDGlyphLabel *InLED1;
    TLMDGlyphLabel *InLED4;
    TLMDGlyphLabel *InLED2;
    TLMDGlyphLabel *InLED3;
    TLMDGlyphLabel *InLED5;
    TLMDGlyphLabel *InLED6;
    TRzGroupBox *RzGroupBox2;
    TLMDGlyphLabel *InLED66;
    TRzGroupBox *RzGroupBox3;
    TLMDGlyphLabel *InLED8;
    TLMDGlyphLabel *InLED9;
    TLMDGlyphLabel *InLED10;
    TLMDGlyphLabel *InLED11;
    TRzGroupBox *RzGroupBox4;
    TSpeedButton *OutBtn4;
    TSpeedButton *OutBtn5;
    TSpeedButton *OutBtn6;
    TSpeedButton *OutBtn0;
    TSpeedButton *OutBtn1;
    TSpeedButton *OutBtn2;
    TSpeedButton *OutBtn3;
    TSpeedButton *OutBtn7;
    TSpeedButton *OutBtn9;
    TSpeedButton *OutBtn8;
    TSpeedButton *OutBtn10;
    TSpeedButton *OutBtn11;
    TSpeedButton *OutBtn20;
    TRzGroupBox *RzGroupBox7;
    TPanel *Panel8;
    TLMDGlyphLabel *PLmtLED0;
    TLMDGlyphLabel *HomeLED0;
    TLMDGlyphLabel *MLmtLED0;
    TLMDGlyphLabel *AmpFltLED0;
    TPanel *Panel11;
    TSpeedButton *HomeBtn0;
    TSpeedButton *AmpOnBtn0;
    TSpeedButton *AmpOffBtn0;
    TSpeedButton *AmpRstBtn0;
    TRzGroupBox *RzGroupBox14;
    TRzGroupBox *RzGroupBox18;
    TRzGroupBox *FullInGrpBox;
    TPanel *InBasePanel;
    TPanel *OutBasePanel;
    TSpeedButton *OutAllOnBtn;
    TSpeedButton *OutAllOffBtn;
    TRzGroupBox *RzGroupBox20;
    TGroupBox *GroupBox1;
    TSpeedButton *CylTestStartBtn;
    TSpeedButton *CylTestStopBtn;
    TGroupBox *GroupBox2;
    TLMDSpinEdit *CylChkTimeSpinEdit;
    TRzGroupBox *RzGroupBox21;
    TPanel *CylChkMsgPanel;
    TMemo *CylChkErrMemo;
    TRzGroupBox *RzGroupBox22;
    TRzRadioGroup *RzRadioGroup1;
    TSpeedButton *SpeedButton66;
    TProgressBar *CylChkTimePgsBar;
    TRzGroupBox *RzGroupBox19;
    TPanel *Panel2;
    TLMDGlyphLabel *LMDGlyphLabel26;
    TRzGroupBox *RzGroupBox24;
    TSpeedButton *UnitPosDecBtn;
    TSpeedButton *UnitPosIncBtn;
    TLMDGlyphLabel *LMDGlyphLabel33;
    TRzTabSheet *TabSheet1;
        TRzPageControl *CvyPageCtrl;
    TRzTabSheet *TabSheet2;
    TRzTabSheet *TabSheet3;
    TRzGroupBox *RzGroupBox6;
    TLMDGlyphLabel *LMDGlyphLabel5;
    TLMDGlyphLabel *LMDGlyphLabel6;
    TLMDGlyphLabel *LMDGlyphLabel7;
    TLMDGlyphLabel *LMDGlyphLabel8;
    TLMDGlyphLabel *LMDGlyphLabel41;
    TLMDGlyphLabel *LMDGlyphLabel42;
    TLMDGlyphLabel *LMDGlyphLabel43;
    TLMDGlyphLabel *LMDGlyphLabel44;
    TLMDGlyphLabel *LMDGlyphLabel52;
    TLMDGlyphLabel *LMDGlyphLabel53;
    TLMDGlyphLabel *LMDGlyphLabel54;
    TLMDGlyphLabel *LMDGlyphLabel55;
    TLMDGlyphLabel *LMDGlyphLabel56;
    TRzGroupBox *RzGroupBox25;
    TSpeedButton *SpeedButton17;
    TSpeedButton *SpeedButton18;
    TSpeedButton *SpeedButton19;
    TSpeedButton *SpeedButton20;
    TSpeedButton *SpeedButton25;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox15;
        TSpeedButton *SpeedButton21;
        TSpeedButton *SpeedButton22;
        TRzGroupBox *RzGroupBox26;
        TLMDGlyphLabel *LMDGlyphLabel45;
        TLMDGlyphLabel *LMDGlyphLabel46;
        TLMDGlyphLabel *LMDGlyphLabel51;
        TLMDGlyphLabel *LMDGlyphLabel57;
        TLMDGlyphLabel *LMDGlyphLabel61;
        TLMDGlyphLabel *LMDGlyphLabel62;
        TLMDGlyphLabel *LMDGlyphLabel63;
        TLMDGlyphLabel *LMDGlyphLabel64;
        TLMDGlyphLabel *LMDGlyphLabel65;
        TLMDGlyphLabel *LMDGlyphLabel67;
        TLMDGlyphLabel *LMDGlyphLabel74;
        TLMDGlyphLabel *LMDGlyphLabel75;
        TLMDGlyphLabel *LMDGlyphLabel76;
        TRzGroupBox *RzGroupBox27;
        TSpeedButton *SpeedButton23;
        TSpeedButton *SpeedButton26;
        TSpeedButton *SpeedButton27;
        TSpeedButton *SpeedButton28;
        TSpeedButton *SpeedButton30;
        TSpeedButton *SpeedButton31;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TCheckBox *CheckBox19;
    TLMDCheckBox *UnitPosLaneSelChkBox;
        TLMDGlyphLabel *LMDGlyphLabel9;
        TLMDGlyphLabel *LMDGlyphLabel15;
    TRzBitBtn *UlMgzSlotGoBtn;
    TLabel *Label2;
    TLabel *Label3;
    TLMDSpinEdit *UlSlotNumSpinEdit;
    TLMDSpinEdit *UlMgzNumSpinEdit;
        TLMDGlyphLabel *LMDGlyphLabel10;
        TLMDGlyphLabel *LMDGlyphLabel11;
    TRzGroupBox *RzGroupBox9;
    TPanel *Panel3;
    TLMDGlyphLabel *PLmtLED3;
    TLMDGlyphLabel *HomeLED3;
    TLMDGlyphLabel *MLmtLED3;
    TLMDGlyphLabel *AmpFltLED3;
    TPanel *Panel4;
    TSpeedButton *HomeBtn3;
    TSpeedButton *AmpOnBtn3;
    TSpeedButton *AmpOffBtn3;
    TSpeedButton *AmpRstBtn3;
    TRzGroupBox *RzGroupBox11;
    TPanel *Panel40;
    TLMDGlyphLabel *PLmtLED2;
    TLMDGlyphLabel *HomeLED2;
    TLMDGlyphLabel *MLmtLED2;
    TLMDGlyphLabel *AmpFltLED2;
    TPanel *Panel41;
    TSpeedButton *AmpHomeBtn2;
    TSpeedButton *AmpOnBtn2;
    TSpeedButton *AmpOffBtn2;
    TSpeedButton *AmpRstBtn2;
    TRzGroupBox *RzGroupBox8;
    TPanel *Panel30;
    TLMDGlyphLabel *PLmtLED1;
    TLMDGlyphLabel *HomeLED1;
    TLMDGlyphLabel *MLmtLED1;
    TLMDGlyphLabel *AmpFltLED1;
    TPanel *Panel31;
    TSpeedButton *HomeBtn1;
    TSpeedButton *AmpOnBtn1;
    TSpeedButton *AmpOffBtn1;
    TSpeedButton *AmpRstBtn1;
    TRzGroupBox *RzGroupBox5;
    TPanel *Panel5;
    TLMDGlyphLabel *PLmtLED4;
    TLMDGlyphLabel *HomeLED4;
    TLMDGlyphLabel *MLmtLED4;
    TLMDGlyphLabel *AmpFltLED4;
    TPanel *Panel6;
    TSpeedButton *HomeBtn4;
    TSpeedButton *AmpOnBtn4;
    TSpeedButton *AmpOffBtn4;
    TSpeedButton *AmpRstBtn4;
    TLMDGlyphLabel *LMDGlyphLabel1;
    TLMDGlyphLabel *LMDGlyphLabel2;
    TLMDGlyphLabel *LMDGlyphLabel3;
    TLMDGlyphLabel *LMDGlyphLabel4;
    TLMDGlyphLabel *LMDGlyphLabel12;
    TLMDGlyphLabel *LMDGlyphLabel13;
    TRzGroupBox *RzGroupBox10;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton5;
    TSpeedButton *SpeedButton6;
    TLMDGlyphLabel *LMDGlyphLabel14;
    TSpeedButton *SpeedButton1;
    TCheckBox *CheckBox1;
    TLMDGlyphLabel *LMDGlyphLabel16;
    TLMDGlyphLabel *LMDGlyphLabel17;
    TLMDGlyphLabel *LMDGlyphLabel18;
    TLMDGlyphLabel *LMDGlyphLabel19;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton7;
        TCheckBox *CheckBox5;
        TLMDGlyphLabel *LMDGlyphLabel20;
    TPanel *Panel1;
    TSpeedButton *UlMgzSlotUpBtn;
    TSpeedButton *UlMgzSlotDnBtn;
    TTimer *TickTimer;
    TCheckBox *CheckBox8;
        TLMDGlyphLabel *LMDGlyphLabel21;
        TSpeedButton *SpeedButton8;
    TSpeedButton *SpeedButton9;
    TSpeedButton *SpeedButton10;
    TSpeedButton *SpeedButton11;
    TSpeedButton *SpeedButton12;
    TLMDGlyphLabel *LMDGlyphLabel22;
    TLMDGlyphLabel *LMDGlyphLabel23;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall AmpPwrOnBtnClick(TObject *Sender);
    void __fastcall AmpPwrOffBtnClick(TObject *Sender);
    void __fastcall OutBtnClick(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall HomeBtnClick(TObject *Sender);
    void __fastcall AmpRstBtnClick(TObject *Sender);
    void __fastcall InitBtnClick(TObject *Sender);
    void __fastcall OutAllBtnClick(TObject *Sender);
    void __fastcall MaintPageCtrlChange(TObject *Sender);
    void __fastcall CvyMoveBtnMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall CvyMoveBtnMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall CvyBtnClick(TObject *Sender);
    void __fastcall SpdBtnClick(TObject *Sender);
    void __fastcall CloseBtnClick(TObject *Sender);
    void __fastcall MoveBtnClick(TObject *Sender);
    void __fastcall ReadIOBtnClick(TObject *Sender);
    void __fastcall ComTestBtnClick(TObject *Sender);
    void __fastcall UnitPosGoBtnClick(TObject *Sender);
private:	// User declarations
    AnsiString m_sCylSensName[IO_MAX][2];
	TPanel *m_pInPnl[IO_MAX];
	TPanel *m_pOutPnl[IO_MAX];
    bool m_bPreOut[IO_MAX];
    int m_nCylChkPNo;
    TLMDGlyphLabel *m_lblIn[IO_MAX];
    TSpeedButton *m_btnOut[IO_MAX];
    TCheckBox *m_chkCyl[IO_MAX];    

    void __fastcall IOPanelCreate();
    void __fastcall FullIOPortIndicate();
    void __fastcall OutPanelClick(TObject *Sender);
    void __fastcall CylChkMsg(AnsiString sPort, bool bError= false);
    void __fastcall CylChkProcess();
    void __fastcall ElevatorMotion();
    void __fastcall InputStatusIndicate();
    void __fastcall CylinderAutoRepeat();
public:		// User declarations
    TRect m_rtForm;
    __fastcall TMaintForm(TComponent* Owner);
};
//--------------------------------------------------------------------------
extern PACKAGE TMaintForm *MaintForm;
//---------------------------------------------------------------------------
#endif
