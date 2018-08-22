//---------------------------------------------------------------------------

#ifndef PrepareH
#define PrepareH
//---------------------------------------------------------------------------
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include "LMDBaseEdit.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomEdit.hpp"
#include "LMDCustomExtSpinEdit.hpp"
#include "LMDCustomMaskEdit.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDSpinEdit.hpp"
class TPrepareForm : public TForm
{
__published:	// IDE-managed Components
    TOpenDialog *OpenDlg;
    TPanel *Panel1;
    TBitBtn *CloseBtn;
    TPanel *Panel2;
    TPageControl *PreparePageCtrl;
    TTabSheet *PreparePage0;
    TTabSheet *PreparePage1;
    TPanel *Panel5;
    TBitBtn *DataViewBtn;
    TTimer *TickTimer;
    TImageList *PageCtrlImageList;
    TPanel *Panel3;
    TBitBtn *GoToWorkBtn;
    TBitBtn *WorkFileOpenBtn;
    TPanel *Panel6;
    TEdit *WorkFileEdit;
    TBitBtn *WorkFileDelBtn;
    TPanel *Panel4;
    TLabel *Page1Lbl0;
    TLabel *Page1Lbl1;
    TLabel *Page1Lbl2;
    TLabel *Page1Lbl3;
    TLabel *Page1Lbl4;
    TLabel *Page1Lbl5;
    TLabel *Page1Lbl6;
    TLabel *LotStartTimeLbl;
    TLabel *LotEndTimeLbl;
    TEdit *OperNameEdit;
    TEdit *LotNumEdit;
    TLMDSpinEdit *UnitReseveSpinEdit;
    TPanel *Panel8;
    TBitBtn *LOTChgBtn;
    TLabel *Label1;
    TLabel *Page1Lbl8;
    TLabel *Page1Lbl9;
    TLabel *Label2;
    TLabel *Page1Lbl12;
    TLMDSpinEdit *LdStartMgzSpinEdit;
    TLMDSpinEdit *LdMgzStartSlotSpinEdit;
    TLMDSpinEdit *UlMgzSpinEdit;
    TButton *UlGoodMgzRstBtn;
    TLabel *Label3;
    TLMDSpinEdit *UlRejSlotSpinEdit;
    TButton *UlRejMgzRstBtn;
    TBevel *Bevel1;
    TEdit *InputPcbCntEdit;
    TEdit *OutputPcbCntEdit;
    TLabel *Label4;
        TLMDSpinEdit *UlMgzSlotSpinEdit;
    TBitBtn *SubmapViewBtn;
    void __fastcall BitBtnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall PreparePageCtrlChanging(TObject *Sender,
          bool &AllowChange);
    void __fastcall UlGoodMgzRstBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool m_bLotChange;
    bool m_bUlDataReset;
    __fastcall TPrepareForm(TComponent* Owner);
    void __fastcall LotDataChange();    
};
//---------------------------------------------------------------------------
extern PACKAGE TPrepareForm *PrepareForm;
//---------------------------------------------------------------------------
#endif
