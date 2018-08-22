//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataView.h"
#include "DataClass.h"
#include "Extern.h"
#include "WorkProcess.h"
#include "RunChk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataViewForm *DataViewForm;
//---------------------------------------------------------------------------
__fastcall TDataViewForm::TDataViewForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::FormCreate(TObject *Sender)
{
    DataViewForm->Height = 640;
    DataViewForm->Width = 720;

    TStringList *pStrList = new TStringList;
    pStrList->Clear();
    pStrList->Add("Total Program Run Time");
    pStrList->Add("Total Work Time");
    pStrList->Add("Total Stop Time");
    pStrList->Add("Total Error Time");
    pStrList->Add("MTBA(Between Action)"); //가동시간/에러횟수
    pStrList->Add("MTBF(Between Failures)");
    pStrList->Add("MTTR(To Repair)");
    pStrList->Add("Average UPH");
    pStrList->Add("Total Input Unit");
    pStrList->Add("Total Output Unit");
    pStrList->Add("Total Reject Unit");
    pStrList->Add("Total Error Counts");

    m_nPdtDataCnt = pStrList->Count;
    int nPitch = PdtDataPanel->Height/(m_nPdtDataCnt+1.3);

   	for(int i=0; i<m_nPdtDataCnt ; i++) {
        m_pLbl[i] = new TLabel(this);
        m_pLbl[i]->Parent           = PdtDataPanel;
        m_pLbl[i]->AutoSize         = false;
        m_pLbl[i]->Left 	        = PdtDataPanel->Left+25;
        m_pLbl[i]->Top              = (PdtDataPanel->Top+nPitch)+(nPitch*i);
        m_pLbl[i]->Width            = 180;
        m_pLbl[i]->Font->Size       = 10;
        m_pLbl[i]->Font->Style      = TFontStyles()<<fsBold;
        m_pLbl[i]->Caption          = pStrList->Strings[i];

        m_pPnl[i] = new TPanel(this);
        m_pPnl[i]->Parent           = PdtDataPanel;
        m_pPnl[i]->Color            = clWhite;
        m_pPnl[i]->Left             = m_pLbl[i]->Left+m_pLbl[i]->Width+20;
        m_pPnl[i]->Top 	            = m_pLbl[i]->Top;
        m_pPnl[i]->Width            = 280;
        m_pPnl[i]->Height           = 30;
        m_pPnl[i]->Font->Style      = TFontStyles()<<fsBold<<fsItalic;
        //m_pPnl[i]->Caption          = pStrList->Strings[i];

        m_pBitBtn[i] = new TBitBtn(this);
        m_pBitBtn[i]->Parent        = PdtDataPanel;
        m_pBitBtn[i]->Left          = m_pPnl[i]->Left+m_pPnl[i]->Width+20;
        m_pBitBtn[i]->Top 	        = m_pLbl[i]->Top;
        m_pBitBtn[i]->Width         = 150;
        m_pBitBtn[i]->Height        = 30;
        m_pBitBtn[i]->Kind          = bkCancel;
        m_pBitBtn[i]->ModalResult   = mrNone;
        m_pBitBtn[i]->Caption       = "Reset";
        m_pBitBtn[i]->Tag           = i;
        m_pBitBtn[i]->Font->Style   = TFontStyles()<<fsBold;
        m_pBitBtn[i]->OnClick       = DataResetBitBtnClick;
    }

    delete pStrList;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::FormShow(TObject *Sender)
{
    SysLogStartDatePicker->Date = Date();
    SysLogEndDatePicker->Date = Date();
    SysLogPage->ActivePageIndex = 0;
    DataViewPage->ActivePageIndex = 0;
    GraphLeftSizePanel->Width = 52;//ErrGraph->MarginLeft;
    GraphRightSizePanel->Width = 24;//ErrGraph->MarginRight;
    TickTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    TickTimer->Enabled = false;
    if(m_pErrCnt != NULL)
        delete[] m_pErrCnt;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::SysLogDataMerge(TDateTime StartDate, TDateTime EndDate)
{
    Screen->Cursor = crHourGlass;

    TStringList *pFileList = new TStringList;
    TStringList *pLogList = new TStringList;

    TSearchRec sr;
    try {
        if(FindFirst(SYSLOG_FILE_PATH+"EventLog\\*.Log", faAnyFile, sr) == 0) {
            do {
                if(sr.Name != "." && sr.Name != ".." && sr.Attr != faDirectory) {
                    sr.Name = sr.Name.SubString(1, sr.Name.Pos(".Log")-1);
                    pFileList->Add(sr.Name);
                }
            }
            while(FindNext(sr) == 0);
        }
    }
    __finally
    {
        FindClose(sr);
    }

    m_pErrCnt = new int[Ext.m_pLngList[STR_ERR]->Count];
    memset(m_pErrCnt, NULL, sizeof(int)*Ext.m_pLngList[STR_ERR]->Count);

    pFileList->Sort();
    SysLogListBox->Clear();
    for(int i=0; i<pFileList->Count ; i++) {
        if(pFileList->Strings[i] != "") {
            int nYear = StrToInt(pFileList->Strings[i].SubString(1,4));
            int nMonth = StrToInt(pFileList->Strings[i].SubString(6,2));
            int nDay = StrToInt(pFileList->Strings[i].SubString(9,2));
            AnsiString sDate = EncodeDate(nYear, nMonth, nDay);
            if(StrToDate(sDate) >= StartDate-1 && StrToDate(sDate) <= EndDate) {
                AnsiString sLogFile = SYSLOG_FILE_PATH+"EventLog\\"+pFileList->Strings[i]+".Log";
                if(FileExists(sLogFile)) {
                    pLogList->Clear();
                    pLogList->LoadFromFile(sLogFile);
                    for(int j=0; j<pLogList->Count; j++) {
                        if(!pLogList->Strings[j].IsEmpty()) {
                            SysLogListBox->Items->Add(pLogList->Strings[j]);
                            if(pLogList->Strings[j].SubString(1,1) == "!") {
                                AnsiString sCode = pLogList->Strings[j];
                                int nIdx = sCode.Pos("CODE[")+5;
                                int nCnt = sCode.Pos("]-")-nIdx;
                                sCode = sCode.SubString(nIdx,nCnt);
                                if(!sCode.IsEmpty()) {
                                    if( StrToInt(sCode) > 1 ) {
                                        m_pErrCnt[StrToInt(sCode)-1]++;;
                                    }
                                }


                            }
                        }
                    }
                }
            }
        }
    }

    SysLogListBox->Items->Add("*****************************************************************************");
    for(int i=0; i<Ext.m_pLngList[STR_ERR]->Count; i++) {
        if(m_pErrCnt[i] > 0) {
            AnsiString sStr, sTmp;
            sStr = Ext.m_pLngList[STR_ERR]->Strings[i];
            sStr = sStr.Delete(1, sStr.Pos("<<")+1);
            sTmp = "CODE["+IntToStr(i+1)+"]-"+sStr.SubString(1, sStr.Pos(">>")-1);
            SysLogListBox->Items->Add(sTmp+"@Total:"+IntToStr(m_pErrCnt[i])+"@");
        }
    }

    ErrScrollBar->Max = Ext.m_pLngList[STR_ERR]->Count-1;
    ErrScrollBar->Position = ErrScrollBar->Max/2;

    int nMax = 0;
    for(int i=0; i<Ext.m_pLngList[STR_ERR]->Count; i++) {
        if(nMax < m_pErrCnt[i])
            nMax = m_pErrCnt[i];
    }
    ErrGraph->LeftAxis->Automatic = false;
    ErrGraph->LeftAxis->Minimum = 0;
    ErrGraph->LeftAxis->Maximum = nMax;

    ErrGraph->BottomAxis->Automatic = false;
    ErrGraph->BottomAxis->Minimum = 0;
    ErrGraph->BottomAxis->Maximum = 20;    

    delete pFileList;
    delete pLogList;

    Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::BitBtnClick(TObject *Sender)
{
    TBitBtn *ptr = dynamic_cast<TBitBtn *>(Sender);

    if(ptr == SysLogSearchBtn)
        SysLogDataMerge(SysLogStartDatePicker->Date, SysLogEndDatePicker->Date);
    else if(ptr == SysLogTextFileBtn) {
        if(SysLogListBox->Items->Count > 0) {
            if(TextFileSaveDlg->Execute()) {
                AnsiString sTxtFile = "c:\\"+DateToStr(SysLogStartDatePicker->Date)+"to"+DateToStr(SysLogEndDatePicker->Date)+".txt";
                TextFileSaveDlg->FileName = sTxtFile;
                SysLogListBox->Items->SaveToFile(TextFileSaveDlg->FileName);
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::SysLogListBoxDrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
     AnsiString sLog = SysLogListBox->Items->Strings[Index];
     if(sLog.SubString(1,1) == "!")
         SysLogListBox->Canvas->Font->Color = clRed;
     else SysLogListBox->Canvas->Font->Color = clBlack;
     SysLogListBox->Canvas->TextOut(Rect.Left, Rect.Top, sLog);
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::ErrGraphMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(X < ErrGraph->ChartRect.Left || X > ErrGraph->ChartRect.Right) {
        ErrViewPanel->Caption = "";
        return;
    }

    int nIdxWidth = (ErrGraph->ChartRect.Right - ErrGraph->ChartRect.Left)/(ErrGraph->BottomAxis->Maximum+1);
    int nIdx = ((X-ErrGraph->ChartRect.Left)/nIdxWidth+ErrScrollBar->Position);

    AnsiString sStr, sTmp;
    if(nIdx >= Ext.m_pLngList[STR_ERR]->Count)
        return;
    sStr = Ext.m_pLngList[STR_ERR]->Strings[nIdx];
    sStr = sStr.Delete(1, sStr.Pos("<<")+1);
    sTmp = "CODE["+IntToStr(nIdx+1)+"]-"+sStr.SubString(1, sStr.Pos(">>")-1);
    ErrViewPanel->Caption = sTmp;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::ErrScrollBarChange(TObject *Sender)
{
    ErrGraph->Series[0]->Clear();

    for(int i=0;i<20;i++) {
        if(ErrScrollBar->Position+i < Ext.m_pLngList[STR_ERR]->Count) {
            ErrGraph->Series[0]->Add(m_pErrCnt[ErrScrollBar->Position+i],
                IntToStr(ErrScrollBar->Position+i+1), ErrGraph->Series[0]->SeriesColor);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::DataResetBitBtnClick(TObject *Sender)
{
    TBitBtn *pBtn = dynamic_cast<TBitBtn *>(Sender);

    if(pBtn->Tag >= 0 && pBtn->Tag < TTL_RUN) {
        Ext.TtlPgsTime(pBtn->Tag, false, true);
        if(pBtn->Tag == TM_PGM) {
            run.nStartClock[pBtn->Tag] = ::GetTickCount();
            run.bRun[pBtn->Tag] = true;
        }
    }
    else run.nData[pBtn->Tag] = 0;
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::TickTimerTimer(TObject *Sender)
{
    for(int i=0; i<TTL_RUN; i++)
        m_pPnl[i]->Caption = AnsiString(run.chData[i]);
}
//---------------------------------------------------------------------------





