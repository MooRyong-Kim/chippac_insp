//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "DataClass.h"
#include "Msg.h"
#include "Prepare.h"
#include "Extern.h"
#include "WorkSetup.h"
#include "Main.h"
#include "WorkSetup.h"
//#include "SecsGem.h"
#include "MotionBase.h"
#include "MeasProcess.h"
#include "IOPort.h"
#include "WorkProcess.h"
#include "ProtecDll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TDataClass Data;
SYSTEM_CONFIG sys, sysOld;
MODEL_DATA mdl, mdlOld;
LOT_DATA lot;
RUN_DATA run;
//---------------------------------------------------------------------------
__fastcall TDataClass::TDataClass()
{
}
//---------------------------------------------------------------------------
__fastcall TDataClass::~TDataClass()
{
}
//---------------------------------------------------------------------------
void __fastcall TDataClass::SaveConfigData(bool bProgress)
{
    if(sys.fac.bAlwaysSafetyOn) {
        sys.eng.bFrntDoorSafety = true;
        sys.eng.bUlBarSafety = true;
    }

    sys.sFileName = "";
    AnsiString sFileName = SYS_FILE_PATH+CFG_FILE_NAME;

    strcpy(sys.chID, DATA_ID.c_str());
    if(bProgress) {
        AnsiString sModifyTime = DateTimeToStr(Now());
        strcpy(sys.chModifyTime, sModifyTime.c_str());
    }

    FILE *fp;
    if((fp=fopen(sFileName.c_str(), "wb")) == NULL) {
        MsgDlg->ShowBox("System Config File Save Error.");
        return;
    }

    int nNum = 0;
    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&sys.chID, sizeof(sys.chID), 1, fp);
    fwrite(&sys.chModifyTime, sizeof(sys.chModifyTime), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&sys.opr, sizeof(sys.opr), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&sys.eng, sizeof(sys.eng), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&sys.fac, sizeof(sys.fac), 1, fp);

    fclose(fp);

    sys.sFileName = sFileName;

    if(bProgress)
        MsgDlg->ShowPgsDlg(100, "System Config Data Save...");

    sysOld = sys;
}
//---------------------------------------------------------------------------
void __fastcall TDataClass::LoadConfigData(AnsiString sFilePath)
{
    sys.sFileName = "";
    if(sFilePath.IsEmpty())
        sFilePath = SYS_FILE_PATH+CFG_FILE_NAME;

    if(!FileExists(sFilePath)) {
        if(MsgDlg == NULL)
            ShowMessage("System Config File Not Exists.");
        else MsgDlg->ShowBox("System Config File Not Exists.");
        return;
    }

    FILE *fp;
    if((fp=fopen(sFilePath.c_str(), "rb")) == NULL) {
        if(MsgDlg == NULL)
            ShowMessage("System Config File Open Error.");
        else MsgDlg->ShowBox("System Config File Open Error.");
        return;
    }

    int nNum = 0;
    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&sys.chID, sizeof(sys.chID), 1, fp);
    fread(&sys.chModifyTime, sizeof(sys.chModifyTime), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&sys.opr, sizeof(sys.opr), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&sys.eng, sizeof(sys.eng), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&sys.fac, sizeof(sys.fac), 1, fp);

    fclose(fp);

    if(strcmpi(sys.chID, DATA_ID.c_str()) != 0) {
        if(MsgDlg == NULL)
            ShowMessage("System Config File Open Error.");
        else MsgDlg->ShowBox("System Config File Open Error.");
        return;
    }

    sys.sFileName = sFilePath;

    if(sys.fac.bAlwaysSafetyOn) {
        sys.eng.bFrntDoorSafety = true;
        sys.eng.bUlBarSafety = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataClass::LoadModelData(AnsiString sFileName, bool bProgress, bool bCvyWidth)
{
    if(sFileName.IsEmpty())
        return;

    FILE *fp;
    if((fp=fopen(sFileName.c_str(), "rb")) == NULL) {
        MsgDlg->ShowBox("Model File Open Error.");
        return;
    }

    int nNum = 0;
    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&mdl.chID, sizeof(mdl.chID), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fread(&mdl.pcb, sizeof(mdl.pcb), 1, fp);

    fclose(fp);

    if(strcmpi(mdl.chID, DATA_ID.c_str()) != 0) {
        MsgDlg->ShowBox("Model File Open Error.");
        return;
    }

    m_bMdlFileOpening = true;

    //if(AnsiString(sys.run.chMdlFile) != sFileName)
    //    PrepareForm->LotDataChange();

    strcpy(run.chMdlFile, sFileName.c_str());

    if(bProgress)
        MsgDlg->ShowPgsDlg(100, "Model Data Loading...");

//    SecsGemForm->SendEvent(C_OPEN_FILE);

    m_bMdlFileOpening = false;

    LoaderFileCtrl(mdl.pcb.chLoaderFile, false, false);
    if(MainForm->m_bInitVision)
    {
        MainForm->TestRequestJobName();
        //kjseo 2015.01.21
        AnsiString str1 = Ext.GetFileName(run.chMdlFile);
        #ifdef PROTECDLL
            _pvJobChange(0, str1.c_str());
        #endif
    }

    MainForm->SendCommand("FILE:"+Ext.GetFileName(sFileName));
}
//---------------------------------------------------------------------------
void  __fastcall TDataClass::SaveModelData(AnsiString sFileName)
{
    if(sFileName.IsEmpty())
        return;

    strcpy(mdl.chID, DATA_ID.c_str());

    AnsiString sBakFile = ChangeFileExt(sFileName, ".bak");
    if(FileExists(sFileName)) {
        if(FileExists(sBakFile))
            DeleteFile(sBakFile);
        RenameFile(sFileName, sBakFile);
    }

    FILE *fp;
    if((fp=fopen(sFileName.c_str(), "wb")) == NULL) {
        MsgDlg->ShowBox("Model File Save Error.");
        return;
    }

    int nNum = 0;
    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&mdl.chID, sizeof(mdl.chID), 1, fp);

    fseek(fp, REC_SIZE*nNum++, SEEK_SET);
    fwrite(&mdl.pcb, sizeof(mdl.pcb), 1, fp);

    fclose(fp);

    //if(AnsiString(run.chMdlFile) != sFileName)
    //    PrepareForm->LotDataChange();

    strcpy(run.chMdlFile, sFileName.c_str());

    LoaderFileCtrl(mdl.pcb.chLoaderFile, false, false);

    MsgDlg->ShowPgsDlg(100, "Model Data Save...");

    MainForm->SendCommand("FILE:"+Ext.GetFileName(sFileName));
}
//---------------------------------------------------------------------------
void __fastcall TDataClass::SaveRunData()
{
    AnsiString sFilePath = SYS_FILE_PATH+RUN_FILE_NAME;

    FILE *fp;
    if((fp=fopen(sFilePath.c_str(), "wb")) == NULL)
        return;

    fwrite(&run, sizeof(run), 1, fp);
    fwrite(&lot, sizeof(lot), 1, fp);
    fclose(fp);
}
//---------------------------------------------------------------------------
void __fastcall TDataClass::LoadRunData()
{
    AnsiString sFilePath = SYS_FILE_PATH+RUN_FILE_NAME;

    FILE *fp;
    if((fp=fopen(sFilePath.c_str(), "rb")) == NULL)
        return;

    fread(&run, sizeof(run), 1, fp);
    fread(&lot, sizeof(lot), 1, fp);
    fclose(fp);
}
//---------------------------------------------------------------------------
bool __fastcall TDataClass::LoaderFileCtrl(AnsiString FileName, bool bSave, bool bSystem)
{
    if(FileName.IsEmpty()) return false;
    if(!FileExists(FileName)) {
        MsgDlg->ShowBox("Loader File Open Error.");
        return false;
    }
    int nFileHandle;
    if(bSave)
        nFileHandle=FileCreate(FileName);
    else nFileHandle=FileOpen(FileName,fmOpenReadWrite);

    if (nFileHandle==-1) {
        if(bSave) MsgDlg->ShowBox("Loader File Save Error.");
        else MsgDlg->ShowBox("Loader File Open Error.");
        return false;
    }
    if(bSystem) {
        if(bSave) {
            FileWrite(nFileHandle,&sys.ul,sizeof(sys.ul));
            if(FileName == mdl.pcb.chLoaderFile)
                mdl.ul = sys.ul;
        }
        else FileRead(nFileHandle,&sys.ul,sizeof(sys.ul));
    }
    else FileRead(nFileHandle,&mdl.ul,sizeof(mdl.ul));

    FileClose(nFileHandle);

    return true;
}
