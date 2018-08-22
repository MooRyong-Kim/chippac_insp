//---------------------------------------------------------------------------

#ifndef DataViewH
#define DataViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#include "ConstDefine.h"
class TDataViewForm : public TForm
{
__published:	// IDE-managed Components
    TPageControl *DataViewPage;
    TTabSheet *TabSheet1;
    TPageControl *PageControl2;
    TPanel *Panel2;
    TLabel *Label1;
    TLabel *Label2;
    TBitBtn *SysLogSearchBtn;
    TBitBtn *SysLogTextFileBtn;
    TDateTimePicker *SysLogStartDatePicker;
    TDateTimePicker *SysLogEndDatePicker;
    TPageControl *SysLogPage;
    TTabSheet *TabSheet3;
    TListBox *SysLogListBox;
    TTabSheet *TabSheet4;
    TPanel *ErrViewPanel;
    TTabSheet *TabSheet2;
    TPanel *PdtDataPanel;
    TTabSheet *TabSheet5;
    TTimer *TickTimer;
    TSaveDialog *TextFileSaveDlg;
    TChart *ErrGraph;
    TPanel *Panel3;
    TPanel *GraphRightSizePanel;
    TPanel *GraphLeftSizePanel;
    TScrollBar *ErrScrollBar;
    TBarSeries *Series1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BitBtnClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall SysLogListBoxDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
    void __fastcall ErrGraphMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall ErrScrollBarChange(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
private:	// User declarations
    TLabel *m_pLbl[12];
    TPanel *m_pPnl[12];
    TBitBtn *m_pBitBtn[12];
    int *m_pErrCnt;
    int m_nPdtDataCnt;
    TDateTime m_dtSysLogDate;
    void __fastcall DataResetBitBtnClick(TObject *Sender);
    void __fastcall SysLogDataMerge(TDateTime StartDate, TDateTime EndDate);
public:		// User declarations
    __fastcall TDataViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataViewForm *DataViewForm;
//---------------------------------------------------------------------------
#endif
