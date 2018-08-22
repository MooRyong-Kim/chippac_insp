//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Prepare.h"
#include "DataClass.h"
#include "WorkProcess.h"
#include "MotionBase.h"
#include "Msg.h"
#include "Main.h"
#include "IOPort.h"
#include "Extern.h"
#include "DataView.h"
#include "SecsGem.h"
#include "SubmapViwer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseEdit"
#pragma link "LMDControl"
#pragma link "LMDCustomBevelPanel"
#pragma link "LMDCustomControl"
#pragma link "LMDCustomEdit"
#pragma link "LMDCustomExtSpinEdit"
#pragma link "LMDCustomMaskEdit"
#pragma link "LMDCustomPanel"
#pragma link "LMDSpinEdit"
#pragma resource "*.dfm"
TPrepareForm *PrepareForm;
//---------------------------------------------------------------------------
__fastcall TPrepareForm::TPrepareForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::FormCreate(TObject *Sender)
{
    OpenDlg->InitialDir = MODEL_FILE_PATH;
    PreparePageCtrl->TabWidth = (PreparePageCtrl->Width/PreparePageCtrl->PageCount)-12;

    //LdMgzStartSlotSpinEdit->MaxValue = sys.eng.nLdMgzSlotNum;
    LotStartTimeLbl->Caption = "";
    LotEndTimeLbl->Caption = "";

    m_bLotChange = false;
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::FormShow(TObject *Sender)
{
    PreparePageCtrl->ActivePageIndex = 0;
    UlMgzSpinEdit->MaxValue = MAX_MGZ;    
    UlMgzSlotSpinEdit->MaxValue = mdl.ul.nMgzSlotNum;
    UlRejSlotSpinEdit->MaxValue = mdl.ul.nMgzSlotNum;

    TickTimer->Enabled = true;
    IO.SetTowerLamp(TWR_IDLE);

    OperNameEdit->Text = AnsiString(lot.chOprName);
    LotNumEdit->Text = AnsiString(lot.chLotNo);
    UnitReseveSpinEdit->Value = lot.nSetPcbCnt;
    InputPcbCntEdit->Text = IntToStr(lot.nInPcbCnt);
    OutputPcbCntEdit->Text = IntToStr(lot.nOutPcbCnt);

    MB.GetMgzSlotNum(sys.fac.nEquipType==HTYPE_1RAIL?UZ:UL, lot.nUlMgz, lot.nUlSlot);

    UlMgzSpinEdit->Value = lot.nUlMgz;
    UlMgzSlotSpinEdit->Value = lot.nUlSlot;

    lot.nUlRejSlot = 0;
    for(int m=0; m<MAX_MGZ; m++) {
        for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
            if(m==mdl.ul.nRejMgzSel && Work.m_bUlEmptySlot[s])
                lot.nUlRejSlot++;
        }
    }
    UlRejSlotSpinEdit->Value = lot.nUlRejSlot;

    LotStartTimeLbl->Caption = DateTimeToStr(lot.dtStartTime);
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    TickTimer->Enabled = false;
    IO.SetTowerLamp(TWR_IDLE);
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::BitBtnClick(TObject *Sender)
{
    TBitBtn *ptr = dynamic_cast<TBitBtn *>(Sender);

    if(ptr == CloseBtn)
        PrepareForm->Close();
    else if(ptr == WorkFileOpenBtn) {
        if(OpenDlg->Execute()) {
            Data.LoadModelData(OpenDlg->FileName, true, true);
            if(!(AnsiString(run.chMdlFile).IsEmpty())) {
                if(MsgDlg->ShowBox("LOT Data Input?", MMB_YESNO|MMI_HELP, 0) == MID_YES)
                    PreparePageCtrl->ActivePageIndex = 1;
                else BitBtnClick(LOTChgBtn);
            }
        }
    }
    else if(ptr == WorkFileDelBtn) {
        if(AnsiString(run.chMdlFile).IsEmpty())
            return;
        if(MsgDlg->ShowBox("Work File Delete?", MMB_YESNO|MMI_WARNING, 0) == MID_YES) {
            Ext.DeleteAllFile(MODEL_FILE_PATH, Ext.GetFileName(run.chMdlFile));
            AnsiString(run.chMdlFile) = "";
        }
    }
    else if(ptr == GoToWorkBtn) {
        if(AnsiString(run.chMdlFile).IsEmpty()) {
            MsgDlg->ShowBox("Work File Not Loaded.");
            return;
        }
        if(!MB.InitCheck())
            return;
        IO.SetTowerLamp(TWR_IDLE);
        PrepareForm->Close();
    }
    else if(ptr == DataViewBtn) {
        DataViewForm->ShowModal();
    }
    else if(ptr == LOTChgBtn) {
        LotDataChange();
        SecsGemForm->SendEvent(C_START_NEW_LOT);
    }
    else if(ptr == SubmapViewBtn) {
        FormSubMapViewer->Show();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::TickTimerTimer(TObject *Sender)
{
    if(!(AnsiString(run.chMdlFile).IsEmpty()))
        LOTChgBtn->Enabled = true;
    else LOTChgBtn->Enabled = false;

    WorkFileEdit->Text = AnsiString(run.chMdlFile);

    InputPcbCntEdit->Text = InputPcbCntEdit->Text.sprintf("%06d", lot.nInPcbCnt);
    OutputPcbCntEdit->Text = OutputPcbCntEdit->Text.sprintf("%06d", lot.nOutPcbCnt);

    UlMgzSpinEdit->Visible = (sys.fac.nEquipType==VTYPE_2RAIL);

    if(lot.nOutPcbCnt < lot.nSetPcbCnt)
        LotEndTimeLbl->Caption = DateTimeToStr(Now());
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::PreparePageCtrlChanging(TObject *Sender,
      bool &AllowChange)
{
    AllowChange = CloseBtn->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::LotDataChange()
{
    for(int s=0; s<mdl.ul.nMgzSlotNum*MAX_MGZ; s++)
        Work.m_bUlEmptySlot[s] = true;

    strcpy(lot.chOprName, OperNameEdit->Text.c_str());
    strcpy(lot.chLotNo, LotNumEdit->Text.c_str());
    lot.nSetPcbCnt = UnitReseveSpinEdit->Value;

    lot.nInPcbCnt = 0;
    lot.nOutPcbCnt = 0;
    lot.nUlMgz = 0;
    lot.nUlSlot = 0;
    lot.nUlRejSlot = 0;

    lot.dtStartTime = Now();
    lot.dtEndTime = Now();

    UlMgzSpinEdit->Value = lot.nUlMgz;
    UlMgzSlotSpinEdit->Value = lot.nUlSlot;
    UlRejSlotSpinEdit->Value = lot.nUlRejSlot;

    LotStartTimeLbl->Caption = DateTimeToStr(lot.dtStartTime);
    LotEndTimeLbl->Caption = DateTimeToStr(lot.dtEndTime);

    Work.m_bLotChgStart = true;
    PreparePageCtrl->ActivePageIndex = 0;
    Ext.SysLogAdd("LOT Change.");
    m_bLotChange = true;
}
//---------------------------------------------------------------------------
void __fastcall TPrepareForm::UlGoodMgzRstBtnClick(TObject *Sender)
{
    TButton *pBtn = dynamic_cast<TButton*>(Sender);

    if(pBtn == UlGoodMgzRstBtn) {
        int nCnt = 0;
        for(int m=0; m<MAX_MGZ; m++) {
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++) {
                if(sys.fac.nEquipType == HTYPE_1RAIL) {
                    Work.m_bUlEmptySlot[s] = (s+1>=UlMgzSlotSpinEdit->Value);
                } else {
                    if(!mdl.ul.bUseRejMgz || m!=mdl.ul.nRejMgzSel) {
                        Work.m_bUlEmptySlot[nCnt] = (mdl.ul.bUseMgz[m] && (nCnt+1 >=
                            ((UlMgzSpinEdit->Value-1)*mdl.ul.nMgzSlotNum)+(UlMgzSlotSpinEdit->Value) ));
                    }
                    nCnt++;
                }
            }
        }
        m_bUlDataReset = !IO.In(ulgripmgzgood);
    }
    else if(pBtn == UlRejMgzRstBtn) {
        int nCnt = 0;
        for(int m=0; m<MAX_MGZ; m++) {
            for(int s=0; s<mdl.ul.nMgzSlotNum; s++)
                Work.m_bUlEmptySlot[s] = (m==mdl.ul.nRejMgzSel && s+1>=UlRejSlotSpinEdit->Value);
        }
        nCnt++;
    }
}
//---------------------------------------------------------------------------



