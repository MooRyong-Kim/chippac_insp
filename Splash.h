//---------------------------------------------------------------------------

#ifndef SplashH
#define SplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomPanelFill.hpp"
#include "LMDCustomParentPanel.hpp"
#include "LMDPanelFill.hpp"
//---------------------------------------------------------------------------
class TSplashForm : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TLMDPanelFill *LMDPanelFill1;
    TLMDPanelFill *LMDPanelFill2;
    TLabel *InitPgsIndiLbl;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
//    void __fastcall CreateParams(TCreateParams &Params);
public:		// User declarations
    __fastcall TSplashForm(TComponent* Owner);
    void __fastcall InitStatus(AnsiString sInitMsg);    
};
//---------------------------------------------------------------------------
extern PACKAGE TSplashForm *SplashForm;
//---------------------------------------------------------------------------
#endif
