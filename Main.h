//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include "ConstDefine.h"
#include "ProcessThread.h"

#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
#include <NMUDP.hpp>
#include <OleCtrls.hpp>
#include <StdCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <time.h>
#include <Grids.hpp>
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDBaseMeter.hpp"
#include "LMDButton.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomButton.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomGroupBox.hpp"
#include "LMDCustomImageList.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomPanelFill.hpp"
#include "LMDCustomParentPanel.hpp"
#include "LMDCustomProgressFill.hpp"
#include "LMDFill.hpp"
#include "LMDGraphicControl.hpp"
#include "LMDGroupBox.hpp"
#include "LMDImageList.hpp"
#include "LMDPanelFill.hpp"
#include "LMDProgressFill.hpp"
#include "RzBorder.hpp"
#include "RzTabs.hpp"
#include "RzButton.hpp"
#include "RzPanel.hpp"
#include "LMDCustomScrollBox.hpp"
#include "LMDListBox.hpp"
#include <ScktComp.hpp>
#include "CPort.hpp"
#include "ZipBuilder.h"
//---------------------------------------------------------------------------
#define EURESYS
extern AnsiString g_sInspResult;
static int pResultCall(char *chInspResult, LPVOID pParam);
static int pMovingCall(char *chInspMoving, LPVOID pParam);
static int pGrabEndCall(LPVOID pParam);
static bool TestRequestJobName1(LPVOID pParam);

class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TImageList *PageCtrlImageList;
    TPanel *ProductPanel;
    TPanel *Panel2;
    TStatusBar *StatusBar;
    TOpenDialog *OpenDlg;
    TNMUDP *DispUDP;
    TPanel *MainPanel;
    TTimer *TickTimer;
    TLMDPanelFill *LMDPanelFill1;
    TPanel *ModelNamePanel;
    TLMDImageList *LEDImageList1;
    TTimer *ProcessTimer;
    TLMDPanelFill *LMDPanelFill4;
    TComboBox *RunModeCmbBox;
    TLMDPanelFill *LMDPanelFill2;
    TPanel *ResetPanel;
    TPanel *EmptyStopPanel;
    TPanel *StopPanel;
    TPanel *StartPanel;
    TLMDPanelFill *LMDPanelFill3;
    TLabel *VersionLbl;
    TLMDButton *SecsGemBtn;
    TLMDGroupBox *LMDGroupBox1;
    TMemo *CommonMemo;
    TRzBitBtn *PrepareBtn;
    TRzBitBtn *WorkSetupBtn;
    TRzBitBtn *SysSetupBtn;
    TRzBitBtn *ManualBtn;
    TRzBitBtn *InitBtn;
    TRzBitBtn *JogBtn;
    TRzBitBtn *ExitBtn;
    TBevel *Bevel1;
    TComboBox *LdUlSelCmbBox;
    TSpeedButton *LoadingBtn;
    TSpeedButton *UnloadingBtn;
    TRzPageControl *MainPageCtrl;
        TRzTabSheet *TabSheet1;
        TRzTabSheet *TabSheet2;
        TPanel *Panel6;
        TPanel *Panel1;
        TPanel *Panel4;
        TRzGroupBox *RzGroupBox3;
        TShape *Shape12;
        TPanel *Panel5;
        TRzGroupBox *RzGroupBox1;
        TLMDFill *LMDFill1;
        TLabel *Label2;
        TShape *Shape7;
        TLabel *Page0Lbl1;
        TLabel *Page0Lbl2;
        TLabel *Page0Lbl3;
        TLabel *Page0Lbl4;
        TLabel *Page0Lbl0;
        TLMDProgressFill *WorkRatioPgsBar;
        TLabel *LotStartTimeLbl;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *WorkStartTimeLbl;
        TLabel *LotNumLbl;
        TLabel *OperNameLbl;
        TShape *Shape5;
        TShape *Shape6;
        TShape *Shape4;
        TShape *Shape3;
        TShape *Shape2;
        TShape *Shape10;
        TShape *Shape1;
        TShape *Shape9;
        TShape *Shape8;
        TRzLEDDisplay *UphLed;
        TRzLEDDisplay *WorkPgsTimeLed;
        TRzLEDDisplay *RzLEDDisplay1;
        TRzLEDDisplay *LotPgsTimeLed;
        TLabel *Page0Lbl7;
        TShape *Shape11;
        TRzPageControl *LogPageCtrl;
        TRzTabSheet *TabSheet4;
        TListBox *SysLogListBox;
        TRzTabSheet *TabSheet5;
        TListBox *DispComLogListBox;
        TRzTabSheet *TabSheet6;
        TListBox *CimLogListBox;
    TPaintBox *MgzDrawBox;
        TRzTabControl *RailTabCtrl;
        TPanel *UnitDrawBasePanel;
        TPaintBox *UnitDrawBox;
        TShape *UnitDragShape;
    TLMDListBox *ProcessNumListBox;
    TSpeedButton *WorkDataRstBtn;
    TPanel *DebugPanel;
    TButton *Button1;
    TButton *Button2;
    TButton *DebugBtn;
    TButton *Button3;
    TPanel *WorkStatusPanel;
        TLabel *Label1;
    TRzLEDDisplay *FrntCureElapsedLed;
    TRzLEDDisplay *RearCureElapsedLed;
    TButton *Button4;
    TSpeedButton *InspLoadingBtn;
    TSpeedButton *InspUnloadingBtn;
    TServerSocket *SockDispenser;
    TComPort *ComPortRfReader;
    TZipBuilder *Zip;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall RunModeCmbBoxChange(TObject *Sender);
    void __fastcall PanelClick(TObject *Sender);
    void __fastcall DispUDPDataReceived(TComponent *Sender,
          int NumberBytes, AnsiString FromIP, int Port);
    void __fastcall ResetPanelMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall ResetPanelMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CtrlPanelCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
    void __fastcall ProcessTimerTimer(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall SysLogListBoxDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
    void __fastcall SecsGemBtnClick(TObject *Sender);
    void __fastcall DispComLogListBoxDblClick(TObject *Sender);
    void __fastcall StatusBarDblClick(TObject *Sender);
    void __fastcall LoadUnloadBtnClick(TObject *Sender);
    void __fastcall TempGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall MainBtnClick(TObject *Sender);
    void __fastcall DebugBtnClick(TObject *Sender);
    void __fastcall MgzDrawBoxDblClick(TObject *Sender);
    void __fastcall MgzDrawBoxMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBoxMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBoxMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBoxMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBasePanelMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBasePanelMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall UnitDrawBasePanelMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall DebugFormViewBtnClick(TObject *Sender);
    void __fastcall MainPageCtrlChange(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall WorkDataRstBtnClick(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall SockDispenserClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall SockDispenserClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ComPortRfReaderRxChar(TObject *Sender, int Count);
private:	// User declarations
    TPoint m_ptMgzDrawBox;
    TProcessThread *m_pProcessThread;
    TRect m_rtUnitSel;
    clock_t m_tUnitClick;
    bool m_bDebugFinish;
    void __fastcall SourceMakeToZip();
    void __fastcall KeyBoardStatus();
    void __fastcall ShowHint(TObject *Sender);
    void __fastcall AppMessage(tagMSG &Msg, bool &Handled);
    void __fastcall UnitStatusDraw(bool bSelTarget=false, TRect rtSelect = TRect(0,0,0,0), bool bMove=false);
public:		// User declarations
    int m_nUph;
    bool m_bSelUnit[MAX_UNIT];
    AnsiString m_sManMotionCmd;
    int m_nDataViewSelMgz;
    int m_nDataViewSelStep;
    bool m_bInitVision;
    HINSTANCE mCodeInst;
    __fastcall TMainForm(TComponent* Owner);
    void __fastcall SendCommand(AnsiString sCmd);
    void __fastcall Process1msec();
    void __fastcall Process100msec();
    void __fastcall Process1000msec();
    void __fastcall MgzStatusDraw(TPoint ptMouse=TPoint(-1, 1));
    bool __fastcall TestRequestJobName();
    void __fastcall SendMsgToDp(String msg);

    bool SubMapReceived;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
