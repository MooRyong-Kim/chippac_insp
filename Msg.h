//---------------------------------------------------------------------------
#ifndef MsgH
#define MsgH
//---------------------------------------------------------------------------
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <time.h>
#include "LMDBaseControl.hpp"
#include "LMDBaseGraphicControl.hpp"
#include "LMDFill.hpp"
#include "LMDGraphicControl.hpp"
#include "RzBorder.hpp"
#include "RzButton.hpp"
#include "LMDButtonControl.hpp"
#include "LMDCheckBox.hpp"
#include "LMDControl.hpp"
#include "LMDCustomCheckBox.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
//---------------------------------------------------------------------------
#define MMB_OK	                0x01 // The message box contains one push button: OK. This is the default.
#define MMB_OKCANCEL	        0x02 // The message box contains two push buttons: OK and Cancel.
#define MMB_RETRYCANCEL	        0x03 // The message box contains two push buttons: Retry and Cancel.
#define MMB_YESNO	            0x04 // The message box contains two push buttons: Yes and No.
#define MMB_YESNOCANCEL         0x05 // The message box contains three push buttons: Yes, No, and Cancel.
#define MMB_STOPRETRYSKIPWORK   0x06 // The message box contains three push buttons: Abort, Retry, and Ignore.
#define MMB_STOPRETRYSKIP       0x07 // The message box contains three push buttons: Abort, Retry, and Ignore.
#define MMB_WAITTIME            0x08 // The message box contains timer only, and it will be hide after time
#define MMB_SHOWONLY            0x09 // The message box is show only.
#define MMB_HIDEONLY            0x0A // The message box is hide only.
#define MMB_STOPWORK            0x0B // The message box contains Stop,Work
#define MMB_CANCEL              0x0C // The message box contains two push buttons: Cancel.
#define MMB_ABORTRETRYIGNORE    0x0D
#define MMB_SHOWONLYCANCEL      0x0E

#define MMI_STOP                0x10 // Image Stop
#define MMI_HELP                0x20 // Image Help (Question Mark)
#define MMI_INFO                0x30 // Image Information
#define MMI_CANCEL              0x40 // Image Cancel
#define MMI_WARNING             0x50 // Image Warning
#define MMI_TIMER               0x60 // Image Timer

#define MID_YES	                1 // A button with "Yes" on its face.
#define MID_NO	                2 // A button the text "No" on its face.
#define MID_OK	                3 // A button the text "OK" on its face.
#define MID_CANCEL	            4 // A button with the text "Cancel" on its face.
#define MID_STOP  	            5 // A button with the text "Abort" on its face
#define MID_RETRY	            6 // A button with the text "Retry" on its face
#define MID_SKIP 	            7 // A button the text "Ignore" on its face
#define MID_WORK                 9
#define MID_ABORT                10
#define MID_IGNORE               11
//---------------------------------------------------------------------------
class TMsgDlg : public TForm
{
__published:	// IDE-managed Components
    TTimer *FlashTimer;
    TLabel *MsgLbl;
    TImage *ImgStop;
    TImage *ImgHelp;
    TImage *ImgInfo;
    TImage *ImgCancel;
    TImage *ImgWarning;
    TImage *ImgTimer;
    TProgressBar *ProgressBar;
    TTimer *TickTimer;
    TLMDFill *LMDFill1;
    TRzLEDDisplay *TimerDispLbl;
    TMemo *BtnCommentMemo;
    TRzBitBtn *BtnOk;
    TRzBitBtn *BtnCancel;
    TRzBitBtn *BtnStop;
    TRzBitBtn *BtnRetry;
    TRzBitBtn *BtnYes;
    TRzBitBtn *BtnNo;
    TRzBitBtn *BtnAbort;
    TRzBitBtn *BtnWork;
    TRzBitBtn *BtnSkip;
    TRzBitBtn *BtnIgnore;
    TLMDCheckBox *AllSkipChkBox;
    void __fastcall BitBtnClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall TickTimerTimer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FlashTimerTimer(TObject *Sender);
private:	// User declarations
    TDateTime m_dtStartTime;
    bool m_bWaitTime;
    int m_nWaitSec;
    int m_nPgsCnt;
    int m_nPgsWait;
    clock_t m_tBuzzOn;
    clock_t m_tPgs;
    void __fastcall ComponentInit();
    void __fastcall CreateParams(TCreateParams& Params);
public:		// User declarations
    AnsiString m_sMsg;
    unsigned ResultID;
    int m_nAlarmBoxPNo;
    int m_bBlink;    
    __fastcall TMsgDlg(TComponent* Owner);
    void __fastcall ShowPgsDlg(int nMax, AnsiString sMsg);
    int FindMsgIndex(int nStrList, AnsiString sTag);
    void ShowBox(AnsiString sCaption);
    int ShowBox(AnsiString sMsg,unsigned BtnStyle);
    int ShowBox(AnsiString sCaption,unsigned BtnStyle,int nWaitTime);
    int ShowBox(AnsiString sMsg,unsigned BtnStyle,int nWaitTime,int nStrList);
    void __fastcall AlarmMsgBoxProcess();
    void __fastcall ChangeLanguage(int nLanguage, bool bSetCaption = false);
    bool __fastcall IsStop(bool bReset = false);
};
//---------------------------------------------------------------------------
extern PACKAGE TMsgDlg *MsgDlg;
//---------------------------------------------------------------------------
#endif
