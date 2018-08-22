//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Msg.h"
#include "MotionBase.h"
#include "DataClass.h"
#include "RunChk.h"
#include "Extern.h"
#include "InitProcess.h"
#include "Init.h"
#include "WorkProcess.h"
#include "IOPort.h"
#include <registry.hpp>
#include "Main.h"
#include "SecsGem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDFill"
#pragma link "LMDGraphicControl"
#pragma link "RzBorder"
#pragma link "RzButton"
#pragma link "LMDButtonControl"
#pragma link "LMDCheckBox"
#pragma link "LMDControl"
#pragma link "LMDCustomCheckBox"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomPanel"
#pragma resource "*.dfm"
TMsgDlg *MsgDlg;
//---------------------------------------------------------------------------
__fastcall TMsgDlg::TMsgDlg(TComponent* Owner)
     : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::CreateParams(TCreateParams& Params)
{
    TForm::CreateParams(Params);
    Params.WindowClass.style |= CS_NOCLOSE;
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::FormCreate(TObject *Sender)
{
//    ChangeLanguage(KOREAN, true);
    this->DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::FormShow(TObject *Sender)
{
    //폼 위치 불러오기
    TRegistryIniFile *pReg = new TRegistryIniFile(REG_KEY);
    int nLeft = pReg->ReadInteger("MsgDlg", "Left", MsgDlg->Left);
    if(nLeft>0 && MainForm->Width>nLeft) MsgDlg->Left = nLeft;
    int nTop = pReg->ReadInteger("MsgDlg", "Top", MsgDlg->Top);
    if(nTop>0 && MainForm->Top>nTop) MsgDlg->Top = nTop;
    delete pReg;

//    ChangeLanguage(sys.opr.nLanguage);

    this->Color = clBtnFace;
    this->BringToFront();
    ResultID = 0;
    ::SetWindowPos(this->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE|SWP_NOMOVE);
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    IO.Off(BUZZ);
    m_bWaitTime = false;
    m_sMsg = "";
    m_bBlink = false;
    BtnCommentMemo->Visible = false;

    TRegistryIniFile *pReg = new TRegistryIniFile(REG_KEY);
    pReg->WriteInteger("MsgDlg", "Left",MsgDlg->Left);
    pReg->WriteInteger("MsgDlg", "Top", MsgDlg->Top);
    delete pReg;

    MainForm->Enabled = true;
}
//---------------------------------------------------------------------------
bool __fastcall TMsgDlg::IsStop(bool bReset)
{
    if(bReset) ResultID = 0;

    return (ResultID==MID_CANCEL || ResultID==MID_STOP || ResultID==MID_ABORT);
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::ComponentInit()
{
    ImgStop->Visible = false;
    ImgHelp->Visible = false;
    ImgInfo->Visible = false;
    ImgCancel->Visible = false;
    ImgWarning->Visible = false;
    ImgTimer->Visible = false;

    BtnOk->Visible = false;
    BtnCancel->Visible = false;
    BtnYes->Visible = false;
    BtnNo->Visible = false;
    BtnStop->Visible = false;
    BtnRetry->Visible = false;
    BtnSkip->Visible = false;
    BtnWork->Visible = false;
    BtnAbort->Visible = false;
    BtnIgnore->Visible = false;

    ProgressBar->Visible = false;
    TimerDispLbl->Visible = false;
    MsgLbl->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::ShowPgsDlg(int nPgsWait, AnsiString sMsg)
{
    Screen->Cursor = crHourGlass;
    ComponentInit();
    MsgDlg->Width = 340;
    MsgDlg->Height = 150;
    MsgDlg->Caption = sMsg;
    ProgressBar->Width = MsgDlg->Width-40;
    ProgressBar->Height = 20;
    ProgressBar->Left = (MsgDlg->ClientWidth-ProgressBar->Width)/2;
    ProgressBar->Top = (MsgDlg->ClientHeight-ProgressBar->Height)/2;
    ProgressBar->Position = 0;
    m_nPgsWait = nPgsWait;
    m_tPgs = clock();
    ProgressBar->Visible = true;
    this->Color = clBtnFace;
    FlashTimer->Enabled = false;
    MsgDlg->ShowModal();
}
//---------------------------------------------------------------------------
void TMsgDlg::ShowBox(AnsiString sMsg)
{
     ShowBox(sMsg,MMB_OK|MMI_INFO,0,STR_MSG);
}
//---------------------------------------------------------------------------
int TMsgDlg::ShowBox(AnsiString sMsg,unsigned BtnStyle)
{
    return ShowBox(sMsg,BtnStyle,0,STR_MSG);
}
//---------------------------------------------------------------------------
int TMsgDlg::ShowBox(AnsiString sMsg,unsigned BtnStyle,int nWaitTime)
{
    return ShowBox(sMsg,BtnStyle,nWaitTime,STR_MSG);
}
//---------------------------------------------------------------------------
int TMsgDlg::ShowBox(AnsiString sTag, unsigned BtnStyle, int nWaitTime, int nStrList)
{
    if(MsgDlg->Visible && BtnStyle != MMB_HIDEONLY)
        return 0;

    bool bModal;  int nMsgIndex;
    int nBtnHgt = 70;
    AnsiString sComment, sIo;
    m_sMsg = sTag;

    ComponentInit();
    MsgLbl->Visible = true;
    TimerDispLbl->Visible = true;
    this->Color = clSilver;
    FlashTimer->Enabled = true;
    BtnCommentMemo->Visible = false;
    BtnCommentMemo->Height = 0;
    m_bWaitTime = false;

    if(sTag.AnsiPos("@")) {
        sComment = sTag.SubString(sTag.AnsiPos("@")+1, sTag.Length());
        sTag = sTag.SubString(1, sTag.AnsiPos("@")-1);
    }
    if(sTag.AnsiPos("^")) {
        sIo = sTag.SubString(sTag.AnsiPos("^"), sTag.Length());
        sTag = sTag.SubString(1, sTag.AnsiPos("^")-1);
    }

    nMsgIndex = Ext.FindMsgIndex(nStrList, sTag);

    if(nStrList > 0 && nMsgIndex >= 0 && nMsgIndex < Ext.m_pLngList[nStrList]->Count) {
        AnsiString sStr = Ext.m_pLngList[nStrList]->Strings[nMsgIndex];
        sStr = sStr.Delete(1, sStr.Pos("<<")+1);
        if(nStrList == STR_MSG)
            MsgLbl->Caption = "[MSG"+IntToStr(nMsgIndex+1)+"] "+sStr.SubString(1, sStr.Pos(">>")-1);
        else if(nStrList == STR_ERR)
            MsgLbl->Caption = "[ERR"+IntToStr(nMsgIndex+1)+"] "+sStr.SubString(1, sStr.Pos(">>")-1);
        MsgDlg->Caption = sStr.Delete(1, sStr.Pos(">>")+1);
        MsgLbl->Caption = MsgLbl->Caption+sComment;
        if(MsgLbl->Caption.Length()>150)
            MsgLbl->Width=330+(MsgLbl->Caption.Length()-150)*5;

        if(Ext.m_pLngList[nStrList]->Strings[nMsgIndex+1].Pos("^") || !sIo.IsEmpty()) {
            BtnCommentMemo->Clear();
        	TCanvas *pCanvas = new TCanvas;
        	HWND hWnd = BtnCommentMemo->Handle;
	        HDC hDc = GetDC(hWnd);
            pCanvas->Handle = hDc;
            pCanvas->Font = BtnCommentMemo->Font;
            BtnCommentMemo->Height = 0;
            BtnCommentMemo->Height = pCanvas->TextHeight("T");
            for(int i=1; i<10; i++) {
                if(nMsgIndex+i < Ext.m_pLngList[nStrList]->Count) {
                    AnsiString sTemp = Ext.m_pLngList[nStrList]->Strings[nMsgIndex+i];
                    if(sTemp.Pos("^")) {
                        BtnCommentMemo->Height+=pCanvas->TextHeight("T");
                        BtnCommentMemo->Lines->Add(sTemp.SubString(2, sTemp.Length()));
                    }
                    else break;
                }
                else break;
            }
            AnsiString sIoMemo;
            while(!sIo.IsEmpty()) {
                AnsiString sSub = sIo.SubString(2, sIo.AnsiPos("`")-2);
                sIo = sIo.Delete(1, sIo.AnsiPos("`"));
                if(IO.EnumMap[IO_IN][sSub]) {
                    if(!sIoMemo.AnsiPos("IN"))
                        sIoMemo+=("*IN["+IntToStr(IO.EnumMap[IO_IN][sSub])+"]");
                    else sIoMemo+=("["+IntToStr(IO.EnumMap[IO_IN][sSub])+"]");
                }
                else if(IO.EnumMap[IO_OUT][sSub]) {
                    if(!sIoMemo.AnsiPos("OUT"))
                        sIoMemo+=("*OUT["+IntToStr(IO.EnumMap[IO_OUT][sSub])+"]");
                    else sIoMemo+=("["+IntToStr(IO.EnumMap[IO_OUT][sSub])+"]");
                }
                if(sIo.IsEmpty()) {
                    BtnCommentMemo->Height+=pCanvas->TextHeight("T");
                    BtnCommentMemo->Lines->Add(sIoMemo);
                    break;
                }
            }
            BtnCommentMemo->Height+=15;
            BtnCommentMemo->Visible = true;
            delete pCanvas;
        }
    } else { // Can't Find Msg Tag -> Display default caption and Tag
        MsgDlg->Caption = "Protec Message.";
        MsgLbl->Caption = sTag;
        MsgLbl->Caption = MsgLbl->Caption+sComment;
        //MsgLbl->Height=48;
        MsgLbl->Width=330;
    }

    MsgLbl->Font->Color = (Chk.m_bMainErrEvent?clRed:clBlack);
    MsgLbl->Refresh();
    MsgDlg->Width = MsgLbl->Width+100;
    MsgDlg->Height = MsgLbl->Height+145+BtnCommentMemo->Height;
    TimerDispLbl->Caption = "00:00:00";
    TimerDispLbl->Top = MsgLbl->Height+20;
    TimerDispLbl->Left = (MsgDlg->Width-TimerDispLbl->Width)/2;
 #define MSG_GAP 7
    switch(BtnStyle & 0xF) { // Button Style
    case MMB_STOPRETRYSKIPWORK:
        bModal = true;
        BtnStop->Top = MsgLbl->Height+nBtnHgt;
        BtnStop->Left = (MsgDlg->Width-(BtnStop->Width*4+MSG_GAP*2))/2;
        BtnStop->Visible = true;
        BtnRetry->Top = MsgLbl->Height+nBtnHgt;
        BtnRetry->Left = BtnStop->Left+BtnStop->Width+MSG_GAP;
        BtnRetry->Visible = true;
        BtnSkip->Top = MsgLbl->Height+nBtnHgt;
        BtnSkip->Left = BtnStop->Left+BtnStop->Width*2+MSG_GAP*2;
        BtnSkip->Visible = true;
        BtnWork->Top = MsgLbl->Height+nBtnHgt;
        BtnWork->Left = BtnStop->Left+BtnStop->Width*3+MSG_GAP*3;
        BtnWork->Visible = true;
        break;
    case MMB_STOPRETRYSKIP:
        bModal = true;
        BtnStop->Top = MsgLbl->Height+nBtnHgt;
        BtnStop->Left = (MsgDlg->Width-(BtnStop->Width*3+MSG_GAP*2))/2;
        BtnStop->Visible = true;
        BtnRetry->Top = MsgLbl->Height+nBtnHgt;
        BtnRetry->Left = BtnStop->Left+BtnStop->Width+MSG_GAP;
        BtnRetry->Visible = true;
        BtnSkip->Top = MsgLbl->Height+nBtnHgt;
        BtnSkip->Left = BtnStop->Left+BtnStop->Width*2+MSG_GAP*2;
        BtnSkip->Visible = true;
        break;
    case MMB_ABORTRETRYIGNORE:
        bModal = true;
        BtnAbort->Top = MsgLbl->Height+nBtnHgt;
        BtnAbort->Left = (MsgDlg->Width-(BtnAbort->Width*3+MSG_GAP*2))/2;
        BtnAbort->Visible = true;
        BtnRetry->Top = MsgLbl->Height+nBtnHgt;
        BtnRetry->Left = BtnAbort->Left+BtnAbort->Width+MSG_GAP;
        BtnRetry->Visible = true;
        BtnIgnore->Top = MsgLbl->Height+nBtnHgt;
        BtnIgnore->Left = BtnAbort->Left+BtnAbort->Width*2+MSG_GAP*2;
        BtnIgnore->Visible = true;
        break;
    case MMB_STOPWORK:
        bModal = true;
        BtnStop->Top = MsgLbl->Height+nBtnHgt;
        BtnStop->Left = (MsgDlg->Width-(BtnStop->Width*2+MSG_GAP))/2;
        BtnStop->Visible = true;
        BtnWork->Top = MsgLbl->Height+nBtnHgt;
        BtnWork->Left = BtnStop->Left+BtnStop->Width+MSG_GAP;
        BtnWork->Visible = true;
        break;
    case MMB_OKCANCEL:
        bModal = true;
        BtnOk->Top = MsgLbl->Height+nBtnHgt;
        BtnOk->Left = (MsgDlg->Width-(BtnOk->Width*2+MSG_GAP))/2;
        BtnOk->Visible = true;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = BtnOk->Left+BtnOk->Width+MSG_GAP;
        BtnCancel->Visible = true;
        break;
    case MMB_RETRYCANCEL:
        bModal = true;
        BtnRetry->Top = MsgLbl->Height+nBtnHgt;
        BtnRetry->Left = (MsgDlg->Width-(BtnRetry->Width*2+MSG_GAP))/2;
        BtnRetry->Visible = true;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = BtnRetry->Left+BtnRetry->Width+MSG_GAP;
        BtnCancel->Visible = true;
        break;
    case MMB_YESNO:
        bModal = true;
        BtnYes->Top = MsgLbl->Height+nBtnHgt;
        BtnYes->Left = (MsgDlg->Width-(BtnYes->Width*2+MSG_GAP))/2;
        BtnYes->Visible = true;
        BtnNo->Top = MsgLbl->Height+nBtnHgt;
        BtnNo->Left = BtnYes->Left+BtnYes->Width+MSG_GAP;
        BtnNo->Visible = true;
        break;
    case MMB_YESNOCANCEL:
        bModal = true;
        BtnYes->Top = MsgLbl->Height+nBtnHgt;
        BtnYes->Left = (MsgDlg->Width-(BtnYes->Width*3+MSG_GAP*2))/2;
        BtnYes->Visible = true;
        BtnNo->Top = MsgLbl->Height+nBtnHgt;
        BtnNo->Left = BtnYes->Left+BtnYes->Width+MSG_GAP;
        BtnNo->Visible = true;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = BtnYes->Left+BtnYes->Width*2+MSG_GAP*2;
        BtnCancel->Visible = true;
        break;
    case MMB_WAITTIME:
        m_bWaitTime = true;
        bModal = true;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = (MsgDlg->Width-BtnCancel->Width)/2;
        BtnCancel->Visible = true;
        break;
    case MMB_SHOWONLY:
        MsgDlg->Height = MsgLbl->Height+110;
        bModal = false;
        break;
    case MMB_SHOWONLYCANCEL:
        bModal = false;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = (MsgDlg->Width-BtnOk->Width)/2;
        BtnCancel->Visible = true;
        MainForm->Enabled = false;
        break;
    case MMB_HIDEONLY:
        MsgDlg->Close();
        return 0;
        break;
    case MMB_CANCEL:
        bModal = true;
        BtnCancel->Top = MsgLbl->Height+nBtnHgt;
        BtnCancel->Left = (MsgDlg->Width-BtnOk->Width)/2;
        BtnCancel->Visible = true;
        break;
    case MMB_OK: default:
        bModal = true;
        BtnOk->Top = MsgLbl->Height+nBtnHgt;
        BtnOk->Left = (MsgDlg->Width-BtnOk->Width)/2;
        BtnOk->Visible = true;
        break;
    }
    switch(BtnStyle & 0xF0) { // Image Style
    case MMI_STOP:
        ImgStop->Left = 16; ImgStop->Top = MsgLbl->Top+(MsgLbl->Height-ImgStop->Height)/2;
        ImgStop->Visible = true;
        MsgDlg->Icon = (TIcon*)ImgStop->Picture;
        break;
    case MMI_HELP:
        ImgHelp->Left = 16; ImgHelp->Top = MsgLbl->Top+(MsgLbl->Height-ImgTimer->Height)/2;;
        ImgHelp->Visible = true;
        MsgDlg->Icon = (TIcon*)ImgHelp->Picture;
        break;
    case MMI_INFO:
        ImgInfo->Left = 16; ImgInfo->Top = MsgLbl->Top+(MsgLbl->Height-ImgTimer->Height)/2;;
        ImgInfo->Visible = true;
        MsgDlg->Icon = (TIcon*)ImgInfo->Picture;
        break;
    case MMI_CANCEL:
        ImgCancel->Left = 16; ImgCancel->Top = MsgLbl->Top+(MsgLbl->Height-ImgTimer->Height)/2;;
        ImgCancel->Visible = true;
        MsgDlg->Icon = (TIcon*)ImgCancel->Picture;
        break;
    case MMI_WARNING:
        ImgWarning->Left=16; ImgWarning->Top=MsgLbl->Top+(MsgLbl->Height-ImgTimer->Height)/2;;
        ImgWarning->Visible=true;
        MsgDlg->Icon = (TIcon*)ImgWarning->Picture;
        break;
    case MMI_TIMER:
        ImgTimer->Left=16; ImgTimer->Top=MsgLbl->Top+(MsgLbl->Height-ImgTimer->Height)/2;;
        ImgTimer->Visible=true;
        MsgDlg->Icon = (TIcon*)ImgTimer->Picture;
        break;
    default: break;
    }

    for(int i=0; i<this->ComponentCount; i++) {
        if(((TRzBitBtn*)Components[i])->Visible) {
            if( ((TRzBitBtn*)Components[i])->Name == "BtnOk" ||
                ((TRzBitBtn*)Components[i])->Name == "BtnYes" ||
                ((TRzBitBtn*)Components[i])->Name == "BtnRetry" ||
                ((TRzBitBtn*)Components[i])->Name == "BtnWork" ) {
                ((TRzBitBtn*)Components[i])->TabOrder = 1;
                break;
            }
        }
    }

    if( sys.opr.bMsgBoxBuzz && !Chk.m_bMainErrEvent) {
        IO.On(BUZZ);
        m_tBuzzOn = clock();
    }

    m_nWaitSec = nWaitTime;
    m_dtStartTime = Now();

    if(bModal) {
        try {
            MsgDlg->ShowModal();
        } catch(...) {
            MsgDlg->Close();
            return MID_CANCEL;
        }
    }
    else MsgDlg->Show();
    IO.Off(BUZZ);

    return ResultID;
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::BitBtnClick(TObject *Sender)
{
   TRzBitBtn *pBtn = dynamic_cast<TRzBitBtn*>(Sender);

    if(pBtn == BtnOk)
        ResultID=MID_OK;
    else if(pBtn == BtnYes)
        ResultID=MID_YES;
    else if(pBtn == BtnNo)
        ResultID=MID_NO;
    else if(pBtn == BtnCancel)
        ResultID=MID_CANCEL;
    else if(pBtn == BtnStop)
        ResultID=MID_STOP;
    else if(pBtn == BtnRetry)
        ResultID=MID_RETRY;
    else if(pBtn == BtnSkip)
        ResultID=MID_SKIP;
    else if(pBtn == BtnWork)
        ResultID=MID_WORK;
    else if(pBtn == BtnAbort)
        ResultID=MID_ABORT;
    else if(pBtn == BtnIgnore)
        ResultID=MID_IGNORE;

    MsgDlg->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::TickTimerTimer(TObject *Sender)
{
    if( sys.opr.bMsgBoxBuzz && MsgDlg->Visible && !Chk.m_bMainErrEvent) {
        if(Ext.CheckDelay(m_tBuzzOn, sys.opr.nMsgBoxBuzzTime))
            IO.Off(BUZZ);
    }

    if(ProgressBar->Visible) {
        ProgressBar->Position = (Ext.GetLapTime(m_tPgs)/(double)m_nPgsWait)*100;
        if(Ext.CheckDelay(m_tPgs, m_nPgsWait)) {
            MsgDlg->Close();
            Screen->Cursor = crDefault;
        }
    } else {
        if(!m_bWaitTime)
            TimerDispLbl->Caption = Ext.SecToStr(Ext.GetLapSec(m_dtStartTime),2);
        else {
            int nRemainSec = m_nWaitSec-Ext.GetLapSec(m_dtStartTime);
            if(nRemainSec <= 0) { // Time Over
                ResultID=MID_OK;
                MsgDlg->Close();
            }
            TimerDispLbl->Caption = Ext.SecToStr(nRemainSec,2);;
        }
    }                              

    AlarmMsgBoxProcess();

    if(this->Visible)
        this->BringToFront();

    if(m_bBlink) {
        static clock_t t1000 = clock();
        if(Ext.CheckDelay(t1000, 1000)) {
            if(this->Color == clRed)
                this->Color = clYellow;
            else this->Color = clRed;
            t1000 = clock();
        }
    }

    AllSkipChkBox->Left = (BtnSkip->Left+AllSkipChkBox->Width/2);
    AllSkipChkBox->Top = (BtnSkip->Top-AllSkipChkBox->Height+5);
    AllSkipChkBox->Visible = (Work.m_bAllSkip&&BtnSkip->Visible);
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::AlarmMsgBoxProcess()
{
    switch(m_nAlarmBoxPNo) {
    case 1:
        if(!MsgDlg->Visible) {
            m_nAlarmBoxPNo = 5;
            int nBtnStyle;
            if(Work.m_nStatus != RSTOP || Init.m_nStatus != RSTOP)
                nBtnStyle = (Chk.m_bMainErrEvent?MMI_STOP|MMB_OK:MMI_STOP|MMB_STOPWORK);
            else nBtnStyle = (Chk.m_bMainErrEvent?MMI_WARNING|MMB_OK:MMI_WARNING|MMB_STOPWORK);
            MsgDlg->ShowBox(Chk.m_sErrMsg, nBtnStyle, 0, STR_ERR);
        }
        break;
    case 5:
        if(!MsgDlg->Visible) {
            if(MsgDlg->ResultID == MID_WORK) {
                if(InitForm->Visible)
                    Init.Start();
                IO.SetTowerLamp(TWR_START);
            } else {
                if(InitForm->Visible) {
                    IO.SetTowerLamp(TWR_IDLE);
                    Init.Stop();
                } else {
                    if(Work.m_nStatus != RSTOP) {
                        IO.SetTowerLamp(TWR_START);
                        if(Chk.m_bMainErrEvent || Chk.m_nAlarmPart == UL_ERR)
                            Work.Stop(TWR_STOP);
                    }
                    else IO.SetTowerLamp(TWR_IDLE);
                }
            }
            Chk.m_nAlarmPart = 0;
            Chk.m_bMainErrEvent = false;
            SecsGemForm->SendALCD(false, Chk.m_sErrMsg);
            m_nAlarmBoxPNo = 0;
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::FlashTimerTimer(TObject *Sender)
{
    static bool bFlash = false;
    if(this->Visible) {
        if(bFlash) this->Color = clGray;
        else this->Color = clSilver;
        bFlash=!bFlash;
    }
    //FlashWindow((HWND)this->Handle, true);
}
//---------------------------------------------------------------------------
void __fastcall TMsgDlg::ChangeLanguage(int nLanguage, bool bSetCaption)
{
/*
    static AnsiString sCaption[15];
    int nCnt = 0;

    if(bSetCaption) {
        sCaption[nCnt++] = "확인]["         +BtnOk->Caption;
        sCaption[nCnt++] = "취소]["         +BtnCancel->Caption;
        sCaption[nCnt++] = "정지]["         +BtnStop->Caption;
        sCaption[nCnt++] = "재시도]["       +BtnRetry->Caption;
        sCaption[nCnt++] = "예]["           +BtnYes->Caption;
        sCaption[nCnt++] = "아니오]["       +BtnNo->Caption;
        sCaption[nCnt++] = "건너뛰기]["     +BtnSkip->Caption;
        sCaption[nCnt++] = "그냥 작업]["    +BtnWork->Caption;
        sCaption[nCnt++] = "중단]["         +BtnAbort->Caption;
        sCaption[nCnt++] = "무시]["         +BtnIgnore->Caption;
    } else {
        BtnOk->Caption                      = GET_LANGUAGE;
        BtnCancel->Caption                  = GET_LANGUAGE;
        BtnStop->Caption                    = GET_LANGUAGE;
        BtnRetry->Caption                   = GET_LANGUAGE;
        BtnYes->Caption                     = GET_LANGUAGE;
        BtnNo->Caption                      = GET_LANGUAGE;
        BtnSkip->Caption                    = GET_LANGUAGE;
        BtnWork->Caption                    = GET_LANGUAGE;
        BtnAbort->Caption                   = GET_LANGUAGE;
        BtnIgnore->Caption                  = GET_LANGUAGE;
    }
    */
}
//---------------------------------------------------------------------------

