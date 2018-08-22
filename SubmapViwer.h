//---------------------------------------------------------------------------

#ifndef SubmapViwerH
#define SubmapViwerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LMDBackPanel.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomParentPanel.hpp"
#include <Grids.hpp>
#include <ValEdit.hpp>
#include "LMDCustomScrollBox.hpp"
#include "LMDListBox.hpp"
#include <ComCtrls.hpp>
#include "LMDCustomPanelFill.hpp"
#include "LMDCustomSheetControl.hpp"
#include "LMDPageControl.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
struct SUB_MAP_INFO {
    String SubID;
    int row;
    int col;
    String CellStatus;
    String CellGrade;
    String Result;
};

enum SUB_MAP_ID {
    CELL_GRADE,
    CELL_STATUS,
};

class TFormSubMapViewer : public TForm
{
__published:	// IDE-managed Components
    TLMDBackPanel *LMDBackPanel1;
    TLMDBackPanel *LMDBackPanel2;
    TLMDListBox *LMDListBox1;
    TLMDBackPanel *LMDBackPanel3;
    TLMDBackPanel *LMDBackPanel4;
    TLMDPageControl *LMDPageControl1;
    TLMDTabSheet *LMDTabSheet1;
    TLMDTabSheet *LMDTabSheet2;
    TStringGrid *StringGrid1;
    TStringGrid *StringGrid2;
    TLMDBackPanel *LMDBackPanel5;
    TDateTimePicker *SysLogEndDatePicker;
    TLabel *Label2;
    TLabel *Label1;
    TDateTimePicker *SysLogStartDatePicker;
    TBitBtn *SysLogSearchBtn;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall LMDListBox1Select(TObject *Sender);
    void __fastcall StringGridDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall SysLogSearchBtnClick(TObject *Sender);
private:	// User declarations
    void __fastcall DrawSubmap( TStringGrid *target, int row, int col, String Submap, SUB_MAP_ID id );
    String __fastcall LoadSubmapLogFile();
public:		// User declarations
    __fastcall TFormSubMapViewer(TComponent* Owner);
    void __fastcall SaveSubmapLogFile( SUB_MAP_INFO data );

};
//---------------------------------------------------------------------------
extern PACKAGE TFormSubMapViewer *FormSubMapViewer;
//---------------------------------------------------------------------------
#endif
