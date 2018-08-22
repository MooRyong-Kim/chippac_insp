//---------------------------------------------------------------------------

#ifndef WorkSetupH
#define WorkSetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeeFunci.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <math.h>
#include "ConstDefine.h"
#include <CheckLst.hpp>
#include "LMDBaseEdit.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomEdit.hpp"
#include "LMDCustomExtSpinEdit.hpp"
#include "LMDCustomMaskEdit.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDSpinEdit.hpp"
#include "RzButton.hpp"
#include "RzTabs.hpp"
#include "LMDCustomBrowseEdit.hpp"
#include "LMDCustomFileEdit.hpp"
#include "LMDFileOpenEdit.hpp"
#include "LMDButtonControl.hpp"
#include "LMDCheckBox.hpp"
#include "LMDCustomCheckBox.hpp"
//---------------------------------------------------------------------------
class TWorkSetupForm : public TForm
{
__published:	// IDE-managed Components
    TOpenDialog *OpenDlg;
    TSaveDialog *SaveDlg;
    TPanel *WorkSetPanel;
    TTimer *TickTimer;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TRzPageControl *WorkSetupPageCtrl;
    TRzTabSheet *TabSheet2;
    TRzTabSheet *TabSheet3;
    TPanel *UnitDrawBasePanel;
    TPaintBox *UnitDrawBox;
    TGroupBox *PkgInfoGrpBox;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label35;
    TLabel *Label43;
    TLMDSpinEdit *UnitYCntSpinEdit;
    TLMDSpinEdit *UnitXCntSpinEdit;
    TLMDSpinEdit *BlockXCntSpinEdit;
    TLMDSpinEdit *BlockYCntSpinEdit;
    TGroupBox *GroupBox11;
    TLabel *Label20;
    TLabel *Label3;
    TLabel *Label36;
    TLabel *Label44;
    TEdit *UnitXPitchEdit;
    TEdit *UnitYPitchEdit;
    TEdit *BlockXPitchEdit;
    TEdit *BlockYPitchEdit;
    TGroupBox *GroupBox23;
    TLabel *Label4;
    TLabel *Label45;
    TLMDSpinEdit *UlMgzSlotTermSpinEdit;
    TComboBox *UlPosSelCmbBox;
    TLMDFileOpenEdit *LdFileOpenEdit;
    TGroupBox *GroupBox53;
    TLabel *Label200;
    TLabel *Label202;
    TEdit *DistCvyInPosEdit;
    TEdit *DistCvyFrntOutPosEdit;
    TRzBitBtn *DistCvyInPosGetBtn;
    TRzBitBtn *DistCvyInPosGoBtn;
    TRzBitBtn *DistCvyFrntOutPosGetBtn;
    TRzBitBtn *DistCvyFrntOutPosGoBtn;
    TGroupBox *GroupBox9;
    TRzPageControl *ToolPageCtrl;
    TGroupBox *PkgVsnTchPosGrpBox;
    TLabel *Label21;
    TLabel *Label6;
    TEdit *FrntFirstUnitXPosEdit;
    TEdit *FrntFirstUnitYPosEdit;
    TRzBitBtn *FrntFirstUnitPosGetBtn;
    TRzBitBtn *FrntFirstUnitPosGoBtn;
    TRadioGroup *PcbCntDirRdoGrp;
    TCheckBox *NoUseZigZagChkBox;
    TGroupBox *GroupBox1;
    TLabel *Label5;
    TLabel *Label7;
    TEdit *RearFirstUnitXPosEdit;
    TEdit *RearFirstUnitYPosEdit;
    TRzBitBtn *RearFirstUnitPosGetBtn;
    TRzBitBtn *RearFirstUnitPosGoBtn;
    TCoolBar *CoolBar2;
    TToolBar *ToolBar1;
    TSpeedButton *FileNewBtn;
    TSpeedButton *FileOpenBtn;
    TSpeedButton *CancelBtn;
    TSpeedButton *FileSaveBtn;
    TToolButton *ToolButton1;
    TSpeedButton *PrevBtn;
    TSpeedButton *NextBtn;
    TToolButton *ToolButton2;
    TSpeedButton *PkgLoadBtn;
    TSpeedButton *PkgUnloadBtn;
    TToolButton *ToolButton4;
    TSpeedButton *CloseBtn;
        TLMDCheckBox *RearCvySelChkBox;
    TLabel *Label8;
    TEdit *DistCvyRearOutPosEdit;
    TRzBitBtn *DistCvyRearOutPosGetBtn;
    TRzBitBtn *DistCvyRearOutPosGoBtn;
        TCheckBox *UseWindowClampChkBox;
    TRzTabSheet *ToolsPage;
    TRzTabSheet *VsnPage;
    TGroupBox *GroupBox2;
    TLabel *Label9;
    TEdit *EvenColOfstXEdit;
    TLabel *Label10;
    TEdit *EvenColOfstYEdit;
    TRzBitBtn *EvenColOfstGetBtn;
    TGroupBox *GroupBox3;
    TCheckBox *UseCureChkBox;
    TLMDSpinEdit *CureSecSpinEdit;
    TCheckBox *ChkUseBarcode;
    TGroupBox *GroupBox7;
    TLabel *Label17;
    TLabel *Label18;
    TEdit *EditBarcodeX;
    TEdit *EditBarcodeY;
    TRzBitBtn *BtnBarcodePosGet;
    TRzBitBtn *BtnBarcodePosGo;
    TRzBitBtn *BtnBarcodeTest;
    TCheckBox *ChkInspAfterCure;
    void __fastcall ToolBarBtnClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall GetPosBtnClick(TObject *Sender);
    void __fastcall GoBtnClick(TObject *Sender);
    void __fastcall UnitDrawBoxPaint(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall DataChange(TObject *Sender);
    void __fastcall WorkSetupPageCtrlChanging(TObject *Sender,
          bool &AllowChange);
    void __fastcall WorkSetupPageCtrlChange(TObject *Sender);
    void __fastcall UnitDrawBoxMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ToolPageCtrlChange(TObject *Sender);
    void __fastcall LdFileOpenEditChange(TObject *Sender);
    void __fastcall ChkUseBarcodeClick(TObject *Sender);
    void __fastcall BtnBarcodeTestClick(TObject *Sender);
private:	// User declarations
    void __fastcall UnitDraw(TPoint ptClick=TPoint(0,0));
public:		// User declarations
    bool m_bDataChange;
    __fastcall TWorkSetupForm(TComponent* Owner);
    void __fastcall ComponentToVar();
    void __fastcall VarToComponent();
};
//---------------------------------------------------------------------------
extern PACKAGE TWorkSetupForm *WorkSetupForm;
//---------------------------------------------------------------------------
#endif
