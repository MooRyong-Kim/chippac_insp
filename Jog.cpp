//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Jog.h"
#include "Main.h"
#include "Extern.h"
#include "MotionBase.h"
#include "WorkSetup.h"
#include "RunChk.h"
#include "WorkProcess.h"
#include "InitProcess.h"
#include "MeasProcess.h"
#include "IOPort.h"
#include "DataClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicButton"
#pragma link "LMDButton"
#pragma link "LMDControl"
#pragma link "LMDCustomButton"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomPanel"
#pragma link "LMDCustomScrollBox"
#pragma link "LMDListBox"
#pragma link "LMDSpeedButton"
#pragma link "LMDTrackBar"
#pragma link "LMDBaseGraphicControl"
#pragma resource "*.dfm"
TJogForm *JogForm;
//---------------------------------------------------------------------------
__fastcall TJogForm::TJogForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::FormCreate(TObject *Sender)
{
    JogAxisSelListBox->ControlStyle = JogAxisSelListBox->ControlStyle << csOpaque;
    JogAxisSelListBox->DoubleBuffered = true;
    //Application->OnMessage = AppMessage;
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::FormShow(TObject *Sender)
{
    //SetWindowPos(Handle, true?HWND_TOPMOST:HWND_NOTOPMOST,
    //    0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
    JogPartSelCmbBox->Clear();
    JogPartSelCmbBox->Items->Add("INSPECTION");
    JogPartSelCmbBox->Items->Add("UNLOADER");
    JogPartSelCmbBox->ItemIndex = 0;

    if(AbsBtn->Down) {
        SpdBtnClick(AbsBtn);
        AbsBtn->Down = false;
    }
    if(PitchMoveBtn->Down) {
        SpdBtnClick(PitchMoveBtn);
        PitchMoveBtn->Down = false;
    }

    JogAxisSelListBox->HeaderHeight = 23;
    JogAxisSelListBox->ItemHeight = 24;
    JogPartSelCmbBoxChange(Sender);

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->JogBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->JogBtn->Width, pt.y+MainForm->JogBtn->Height};
    Ext.DrawWireRects(&rectTo, &rectFrom);

    TickTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    //SendJogPadCommand(JOG_CMD_JogDisable, '0');
    AbsBtn->Down = false;
    SpdBtnClick(AbsBtn);

    TickTimer->Enabled = false;

    RECT rectFrom;
	::GetWindowRect(this->Handle, &rectFrom);
    TPoint pt = TPoint(0,0);
    pt = MainForm->ScreenToClient(MainForm->JogBtn->ClientToScreen(pt));
	RECT rectTo = {pt.x, pt.y, pt.x+MainForm->JogBtn->Width, pt.y+MainForm->JogBtn->Height};
    Ext.DrawWireRects(&rectFrom, &rectTo);
}
//---------------------------------------------------------------------------
int __fastcall TJogForm::MoveDir(int nAxis, int nDir)
{
    if(nDir == UP) {
        if(nAxis == IY)      return NEG;
        else if(nAxis == DC) return NEG;
        else if(nAxis == UL && sys.fac.nEquipType==VTYPE_2RAIL) return NEG;
        else if(nAxis == UZ && sys.fac.nEquipType==HTYPE_1RAIL) return POS;
    }
    else if(nDir == DN) {
        if(nAxis == IY)      return POS;
        else if(nAxis == DC) return POS;
        else if(nAxis == UL && sys.fac.nEquipType==VTYPE_2RAIL) return POS;
        else if(nAxis == UZ && sys.fac.nEquipType==HTYPE_1RAIL) return NEG;
    }
    else if(nDir == LE) {
        if(nAxis == IX)      return NEG;
        else if(nAxis == UY && sys.fac.nEquipType==HTYPE_1RAIL) return POS;
    }
    else if(nDir == RI) {
        if(nAxis == IX)      return POS;
        else if(nAxis == UY && sys.fac.nEquipType==HTYPE_1RAIL) return NEG;
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::ArrowKeyDown(int nDir)
{
    int nAxis = -1;
    if(JogPartSelCmbBox->ItemIndex == 0) {
        if(JogAxisSelListBox->Selected[0]) nAxis = IX;
        else if(JogAxisSelListBox->Selected[2]) nAxis = DC;
    }
    else if(JogPartSelCmbBox->ItemIndex == 1) {
        if(JogAxisSelListBox->Selected[0]) nAxis = UL;
        else if(JogAxisSelListBox->Selected[1]) nAxis = UZ;
    }
    if(nAxis == -1)
        return;

    if(nDir != VK_UP && nDir != VK_DOWN && nDir != VK_LEFT && nDir != VK_RIGHT)
        return;

    if(PitchMoveBtn->Down) {
        double dPitch;
        try { dPitch = StrToFloat(PitchMoveEdit->Text); }
        catch(...) { dPitch = 0.; }

        if(nAxis == IX) {
            if(!MB.AxisDone(IX) || !MB.AxisDone(IY))
                return;
            if(nDir == VK_UP)         PitchMove(IY, dPitch, MoveDir(IY, UP));
            else if(nDir == VK_DOWN)  PitchMove(IY, dPitch, MoveDir(IY, DN));
            if(nDir == VK_LEFT)       PitchMove(IX, dPitch, MoveDir(IX, LE));
            else if(nDir == VK_RIGHT) PitchMove(IX, dPitch, MoveDir(IX, RI));
        }
        else if(nAxis == UL) {
            if(!MB.AxisDone(UY) || !MB.AxisDone(UZ))
                return;
            if(sys.fac.nEquipType == HTYPE_1RAIL) {
                if(nDir == VK_UP)         PitchMove(UZ, dPitch, MoveDir(UZ, UP));
                else if(nDir == VK_DOWN)  PitchMove(UZ, dPitch, MoveDir(UZ, DN));
                if(nDir == VK_LEFT)       PitchMove(UY, dPitch, MoveDir(UY, LE));
                else if(nDir == VK_RIGHT) PitchMove(UY, dPitch, MoveDir(UY, RI));
            } else {
                if(nDir == VK_UP)         PitchMove(UL, dPitch, MoveDir(UL, UP));
                else if(nDir == VK_DOWN)  PitchMove(UL, dPitch, MoveDir(UL, DN));
            }
        } else {
            if(!MB.AxisDone(nAxis))
                return;
            if(nAxis == DC) {
                if(nDir == VK_UP)        PitchMove(nAxis, dPitch, MoveDir(DC, UP));
                else if(nDir == VK_DOWN) PitchMove(nAxis, dPitch, MoveDir(DC, DN));
            }
        }
    } else {
        if(nAxis == IX) {
            if(nDir == VK_UP)         MB.JogMove(IY, MoveDir(IY, UP));
            else if(nDir == VK_DOWN)  MB.JogMove(IY, MoveDir(IY, DN));
            if(nDir == VK_LEFT)       MB.JogMove(IX, MoveDir(IX, LE));
            else if(nDir == VK_RIGHT) MB.JogMove(IX, MoveDir(IX, RI));
        }
        else if(nAxis == UL) {
            if(sys.fac.nEquipType == HTYPE_1RAIL) {
                if(nDir == VK_UP)         MB.JogMove(UZ, MoveDir(UZ, UP));
                else if(nDir == VK_DOWN)  MB.JogMove(UZ, MoveDir(UZ, DN));
                if(nDir == VK_LEFT)       MB.JogMove(UY, MoveDir(UY, LE));
                else if(nDir == VK_RIGHT) MB.JogMove(UY, MoveDir(UY, RI));
            } else {
                if(nDir == VK_UP)         MB.JogMove(UL, MoveDir(UL, UP));
                else if(nDir == VK_DOWN)  MB.JogMove(UL, MoveDir(UL, DN));
            }
        } else {
            if(!MB.AxisDone(nAxis))
                return;
            if(nAxis == DC) {
                if(nDir == VK_UP)        MB.JogMove(nAxis, MoveDir(DC, UP));
                else if(nDir == VK_DOWN) MB.JogMove(nAxis, MoveDir(DC, DN));
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::ArrowKeyUp(int nKey)
{
    if(PitchMoveBtn->Down) return;

    if(JogPartSelCmbBox->ItemIndex == 0) {
        if(JogAxisSelListBox->Selected[0]) {
            if(nKey == VK_LEFT || nKey == VK_RIGHT)
                MB.JogMove(IX, MSTOP);
            if(nKey == VK_UP || nKey == VK_DOWN)
                MB.JogMove(IY, MSTOP);
        }
        else if(JogAxisSelListBox->Selected[2])
                MB.JogMove(DC, MSTOP);
    }
    else if(JogPartSelCmbBox->ItemIndex == 1) {
        if(sys.fac.nEquipType == HTYPE_1RAIL) {
            if(nKey == VK_LEFT || nKey == VK_RIGHT)
                MB.JogMove(UY, MSTOP);
            if(nKey == VK_UP || nKey == VK_DOWN)
                MB.JogMove(UZ, MSTOP);
        }
        else MB.JogMove(UL, MSTOP);
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogBtnClick(TObject *Sender)
{
   if(!PitchMoveBtn->Down) return;
   double dPitch;
   try { dPitch = StrToFloat(PitchMoveEdit->Text); }
   catch(...) { dPitch = 0.; }

    int nAxis = -1;
    if(JogPartSelCmbBox->ItemIndex == 0) {
        if(JogAxisSelListBox->Selected[0])      nAxis = IX;
        else if(JogAxisSelListBox->Selected[2]) nAxis = DC;
    }
    else if(JogPartSelCmbBox->ItemIndex == 1) {
        if(JogAxisSelListBox->Selected[0])      nAxis = UL;
    }
    if(nAxis == -1)
        return;

    TLMDSpeedButton *p = dynamic_cast<TLMDSpeedButton*>(Sender);

    if(nAxis == IX) {
        if(p->Name.AnsiPos("Up"))    PitchMove(IY, dPitch, MoveDir(IY, UP));
        if(p->Name.AnsiPos("Down"))  PitchMove(IY, dPitch, MoveDir(IY, DN));
        if(p->Name.AnsiPos("Left"))  PitchMove(IX, dPitch, MoveDir(IX, LE));
        if(p->Name.AnsiPos("Right")) PitchMove(IX, dPitch, MoveDir(IX, RI));
    }
    else if(nAxis == DC) {
        if(p->Name.AnsiPos("Up"))    PitchMove(DC, dPitch, MoveDir(DC, UP));
        if(p->Name.AnsiPos("Down"))  PitchMove(DC, dPitch, MoveDir(DC, DN));
    }
    else if(nAxis == UL) {
        if(sys.fac.nEquipType == HTYPE_1RAIL) {
            if(p->Name.AnsiPos("Up"))    PitchMove(UZ, dPitch, MoveDir(UZ, UP));
            if(p->Name.AnsiPos("Down"))  PitchMove(UZ, dPitch, MoveDir(UZ, DN));
            if(p->Name.AnsiPos("Left"))  PitchMove(UY, dPitch, MoveDir(UY, LE));
            if(p->Name.AnsiPos("Right")) PitchMove(UY, dPitch, MoveDir(UY, RI));
        } else {
            if(p->Name.AnsiPos("Up"))    MB.JogMove(UL, MoveDir(UL, UP));
            if(p->Name.AnsiPos("Down"))  MB.JogMove(UL, MoveDir(UL, DN));
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogBtnMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(PitchMoveBtn->Down) return;

    int nAxis = -1;

    if(JogPartSelCmbBox->ItemIndex == 0) {
        if(JogAxisSelListBox->Selected[0])      nAxis = IX;
        else if(JogAxisSelListBox->Selected[2]) nAxis = DC;
    }
    else if(JogPartSelCmbBox->ItemIndex == 1) {
        if(JogAxisSelListBox->Selected[0])      nAxis = UL;
    }

    if(nAxis == -1)
        return;

    TLMDSpeedButton *p = dynamic_cast<TLMDSpeedButton*>(Sender);

    if(nAxis == IX) {
        if(p->Name.AnsiPos("Up"))    MB.JogMove(IY, MoveDir(IY, UP));
        if(p->Name.AnsiPos("Down"))  MB.JogMove(IY, MoveDir(IY, DN));
        if(p->Name.AnsiPos("Left"))  MB.JogMove(IX, MoveDir(IX, LE));
        if(p->Name.AnsiPos("Right")) MB.JogMove(IX, MoveDir(IX, RI));
    }
    else if(nAxis == DC) {
        if(p->Name.AnsiPos("Up"))    MB.JogMove(DC, MoveDir(DC, UP));
        if(p->Name.AnsiPos("Down"))  MB.JogMove(DC, MoveDir(DC, DN));
    }
    else if(nAxis == UL) {
        if(sys.fac.nEquipType == HTYPE_1RAIL) {
            if(p->Name.AnsiPos("Up"))    MB.JogMove(UZ, MoveDir(UZ, UP));
            if(p->Name.AnsiPos("Down"))  MB.JogMove(UZ, MoveDir(UZ, DN));
            if(p->Name.AnsiPos("Left"))  MB.JogMove(UY, MoveDir(UY, LE));
            if(p->Name.AnsiPos("Right")) MB.JogMove(UY, MoveDir(UY, RI));
        } else {
            if(p->Name.AnsiPos("Up"))    MB.JogMove(UL, MoveDir(UL, UP));
            if(p->Name.AnsiPos("Down"))  MB.JogMove(UL, MoveDir(UL, DN));
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogBtnMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(PitchMoveBtn->Down) return;

    for(int ax=0; ax<AXES; ax++) {
        if(!MB.AxisDone(ax))
            MB.JogMove(ax, MSTOP);
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogPartSelCmbBoxChange(TObject *Sender)
{
    if(JogPartSelCmbBox->ItemIndex < 0 || JogPartSelCmbBox->ItemIndex > 1)
        return;

    JogAxisSelListBox->Items->BeginUpdate();
    JogAxisSelListBox->Clear();

    int nAxStart, nAxEnd = 0;
    if(JogPartSelCmbBox->ItemIndex == 0)      nAxStart = IX,   nAxEnd = (sys.fac.nEquipType==HTYPE_1RAIL?IY:DC);
    else if(JogPartSelCmbBox->ItemIndex == 1) nAxStart = UY,   nAxEnd = (sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL);
    for(int ax=nAxStart; ax<=nAxEnd; ax++)
        JogAxisSelListBox->Items->Add(";;");

    int nListHgt = JogAxisSelListBox->HeaderHeight;
    for(int i=0; i<=JogAxisSelListBox->Items->Count; i++)
        nListHgt+=JogAxisSelListBox->ItemHeight;
    this->Height = TopPanel->Height+nListHgt+BottonPanel->Height+6;

    JogAxisSelListBox->Items->EndUpdate();
    JogAxisSelListBox->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogBtnMouseEnter(TObject *Sender)
{
    TLMDSpeedButton *p = dynamic_cast<TLMDSpeedButton *>(Sender);
    p->Color = (p==JogEnterBtn)?clLime:clYellow;
}
//---------------------------------------------------------------------------
 void __fastcall TJogForm::JogBtnMouseExit(TObject *Sender)
{
    TLMDSpeedButton *p = dynamic_cast<TLMDSpeedButton *>(Sender);
    p->Color = clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::TickTimerTimer(TObject *Sender)
{
    if(JogPartSelCmbBox->ItemIndex < 0 || JogPartSelCmbBox->ItemIndex > 4)
        return;

    JogFormDataRefresh();

    if((Work.m_nStatus != RSTOP || Init.m_nStatus != RSTOP || !Meas.m_bDone))
        BottonPanel->Enabled = false;
    else BottonPanel->Enabled = true;

    if(BottonPanel->Enabled)
        BottonPanel->Color = clBtnFace;
    else {
        AbsBtn->Down = false;
        SpdBtnClick(AbsBtn);
        BottonPanel->Color = clGray;
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::JogFormDataRefresh()
{
    if(JogPartSelCmbBox->ItemIndex < 0 || JogPartSelCmbBox->ItemIndex > 4)
        return;

    int nAxStart, nAxEnd;
    if(JogPartSelCmbBox->ItemIndex == 0)      nAxStart = IX, nAxEnd = sys.fac.nEquipType==HTYPE_1RAIL?IY:DC;
    else if(JogPartSelCmbBox->ItemIndex == 1) nAxStart = UY, nAxEnd = sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL;

    static AnsiString sName[] = { {"      X;  "}, {"      Y;  "}, {"DISRIBUTER;"},

                                  {"      Y;  "}, {"      Z;  "}};
    if(sys.fac.nEquipType == VTYPE_2RAIL)
        sName[UL] = "      Z;  ";

    JogAxisSelListBox->Items->BeginUpdate();

    for(int ax=nAxStart; ax<=nAxEnd; ax++) {
        JogAxisSelListBox->Items->Strings[ax-nAxStart] = sName[ax]+
            Ext.FloatToStr(MB.GetPosInc(ax))+";  mm";
    }

    if(JogPartSelCmbBox->ItemIndex == 0) {
        bool bX = (JogAxisSelListBox->ItemIndex==0);
        bool bY = (JogAxisSelListBox->ItemIndex==1);
        bool bDC = (sys.fac.nEquipType==VTYPE_2RAIL?JogAxisSelListBox->ItemIndex==2:false);

        bX = bY = (bX||bY);
        JogAxisSelListBox->Selected[0] = (bX||bY);
        JogAxisSelListBox->Selected[1] = (bX||bY);
        if(sys.fac.nEquipType==VTYPE_2RAIL)
            JogAxisSelListBox->Selected[2] = bDC;

        JogUpBtn->Enabled           = bY||bDC;
        JogDownBtn->Enabled         = bY||bDC;
        JogLeftBtn->Enabled         = bX;
        JogRightBtn->Enabled        = bX;
        JogLeftUpBtn->Enabled       = (bX&&bY);
        JogRightUpBtn->Enabled      = (bX&&bY);
        JogLeftDownBtn->Enabled     = (bX&&bY);
        JogRightDownBtn->Enabled    = (bX&&bY);
    }
    else if(JogPartSelCmbBox->ItemIndex == 1) {
        bool bY = (JogAxisSelListBox->ItemIndex==0&&sys.fac.nEquipType==HTYPE_1RAIL);
        bool bZ = (JogAxisSelListBox->ItemIndex==1||sys.fac.nEquipType==VTYPE_2RAIL);

        if(sys.fac.nEquipType==HTYPE_1RAIL) {
            bY = bZ = (bY||bZ);
            JogAxisSelListBox->Selected[0] = (bY||bZ);
            JogAxisSelListBox->Selected[1] = (bY||bZ);
        }
        else JogAxisSelListBox->Selected[0] = bZ;

        JogUpBtn->Enabled           = bZ;
        JogDownBtn->Enabled         = bZ;
        JogLeftBtn->Enabled         = bY;
        JogRightBtn->Enabled        = bY;
        JogLeftUpBtn->Enabled       = (bY&&bZ);
        JogRightUpBtn->Enabled      = (bY&&bZ);
        JogLeftDownBtn->Enabled     = (bY&&bZ);
        JogRightDownBtn->Enabled    = (bY&&bZ);
    }

    JogAxisSelListBox->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::SpdBtnClick(TObject *Sender)
{
    TSpeedButton *p = dynamic_cast<TSpeedButton *>(Sender);

    if(p == AbsBtn) {
        if(AbsBtn->Down) {
            for(int i=0 ; i<AXES; i++)
                 MB.move.dBasePos[i] = MB.GetPos(i);
        } else {
            for(int i=0 ; i<AXES; i++)
                 MB.move.dBasePos[i] = 0.;
        }
    }
    else if(p == PitchMoveBtn) {}
    else if(p == HomeBtn) {
        int nAxis;
        if(JogPartSelCmbBox->ItemIndex == 0) {
            if(JogAxisSelListBox->Selected[0] || JogAxisSelListBox->Selected[1]) {
                if(JogAxisSelListBox->Selected[0])      nAxis = IX;
                else if(JogAxisSelListBox->Selected[1]) nAxis = IY;
                Coord pos = {0., 0.};
                MB.XYMoveTo(nAxis, pos, false, sys.eng.mtr[nAxis].nHomeSpd);
            }
            else if(JogAxisSelListBox->Selected[2]) {
                MB.MoveTo(DC, 0., sys.eng.mtr[DC].nHomeSpd);
            }
        }
        else if(JogPartSelCmbBox->ItemIndex == 1) {
            if(JogAxisSelListBox->Selected[0] && JogAxisSelListBox->Selected[1]) {
                Coord pos = {0., 0.};
                MB.HTypeUlManMove(UL, pos);
            }
            else if(JogAxisSelListBox->Selected[0]) {
                MB.MoveTo(UL, 0., sys.eng.mtr[UL].nHomeSpd);
            }
        }
    }
}
//---------------------------------------------------------------------------
bool __fastcall TJogForm::IsInRect(TRect rtRect, TPoint ptPos)
{
    if(rtRect.Left <= ptPos.x && rtRect.Top <= ptPos.y &&
        rtRect.Right >= ptPos.x && rtRect.Bottom >= ptPos.y)
        return true;
    return false;
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::AppMessage(tagMSG &Msg, bool &Handled)
{
    if(JogForm->Visible && TickTimer->Enabled) {
        if(Msg.message == WM_KEYDOWN) {
            JogForm->ArrowKeyDown(Msg.wParam);
        }
        else if(Msg.message == WM_KEYUP) {
            JogForm->ArrowKeyUp(Msg.wParam);
        }
        if(Msg.wParam == VK_UP || Msg.wParam == VK_DOWN ||
            Msg.wParam == VK_LEFT || Msg.wParam == VK_RIGHT) {
            Msg.wParam = 0;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TJogForm::PitchMove(int nAxis, double dPitch, int nDir)
{
    MB.MoveTo(nAxis, MB.GetPos(nAxis, true)+dPitch*nDir, sys.eng.mtr[nAxis].nJogSpd);
}
//---------------------------------------------------------------------------

