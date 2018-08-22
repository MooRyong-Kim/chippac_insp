//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SecsGem.h"
#include "Main.h"
#include "WorkProcess.h"
#include "RunChk.h"
#include "WorkSetup.h"
#include "Extern.h"
#include "Main.h"
#include "InitProcess.h"
#include "Prepare.h"
#include "IOPort.h"
#include "DataClass.h"
#include "MotionBase.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LMDBaseControl"
#pragma link "LMDBaseGraphicControl"
#pragma link "LMDBaseLabel"
#pragma link "LMDCustomGlyphLabel"
#pragma link "LMDCustomImageList"
#pragma link "LMDGlyphLabel"
#pragma link "LMDImageList"
#pragma resource "*.dfm"
TSecsGemForm *SecsGemForm;
//---------------------------------------------------------------------------
__fastcall TSecsGemForm::TSecsGemForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::FormCreate(TObject *Sender)
{
    Left=(Screen->Width-Width)/2;
    Top=(Screen->Height-Height)/2;
    LogListBox->Align = alClient;

    ForceDirectories(SYSLOG_FILE_PATH+"\\System");

    StartProductionTime = Now();
    EndProductionTime = Now();
    m_nHostConnected = HOST_DISCONNECT;

    StartGem();
    for(int i=0; i<MAX_CEID; i++)
        SECSGEM_isEnabledEventReport[i] = true;
    for(int i=0; i<Ext.m_pLngList[STR_ALID]->Count; i++)
        SECSGEM_isEnabledAlarmReport[i] = true;
    SendEvent(C_POWER_ON, false);
    SvidTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::FormShow(TObject *Sender)
{
    SecsGemIpEdit->Text = AnsiString(sys.fac.chSecsGemIp);
    SecsGemPortEdit->Text = IntToStr(sys.fac.nSecsGemPort);
    //m_MachineNo->Text = IntToStr(SystemConfig.External.MCNo);
    //m_HeadNo->Text = IntToStr(SystemConfig.External.HeadNo);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::FormDestroy(TObject *Sender)
{
    SvidTimer->Enabled = false;
    SendEvent(C_POWER_OFF, false);
    StopGem("Program Exit");
    AddLog("Program Terminate.");
    if(gem != NULL) {
        delete gem;
        gem = NULL;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::StartGem()
{
    gem = new TEZGEM(MainForm);

    gem->OnConnected            = gemConnected;
    gem->OnDisconnected         = gemDisconnected;
    gem->OnDateTimeSetRequest   = gemDateTimeSetRequest;
    gem->OnEstablishCommRequest = gemEstablishCommRequest;
    gem->OnCommEstablished      = gemCommEstablished;
    gem->OnOnlineRequest        = gemOnlineRequest;
    gem->OnOfflineRequest       = gemOfflineRequest;
    gem->OnOnlineLocal          = gemOnlineLocal;
    gem->OnOnlineRemote         = gemOnlineRemote;
    gem->OnTerminalMessageMulti = gemTerminalMessageMulti;
    gem->OnTerminalMessageSingle= gemTerminalMessageSingle;
    gem->OnSecsMsgIn            = gemSecsMsgIn;
    gem->OnSecsMsgOut           = gemSecsMsgOut;
    gem->OnMsgRequested         = gemMsgRequested;
    gem->OnNewEquipConst        = gemNewEquipConst;

    // gem ocx 세팅
    WideString name = "mkud100";
    WideString ver = MainForm->VersionLbl->Caption;
    gem->SetModelName(name);
    gem->SetSoftwareRev(ver);

    if(FileExists("EzGem.cfg"))
        gem->SetConfigFile(WideString("EzGem.cfg"));
    else {
        gem->HostMode = false;
        gem->PassiveMode = false;
        gem->DeviceID = 0;
        gem->IP = AnsiString(sys.fac.chSecsGemIp);
        gem->Port = sys.fac.nSecsGemPort;
        gem->T3 = 30;
        gem->T5 = 5;
        gem->T6 = 20;
        gem->T7 = 5;
        gem->T8 = 6;
        gem->LinkTestInterval = 30;
        gem->Retry = 3;
        // gem log 세팅
        gem->SetLogFile(WideString(SYSLOG_FILE_PATH+"SecsGem\\SecsGem.txt").c_bstr(), TRUE);
        gem->SetLogRetention(30);
    }

    // gem auto reply 막기 (사용자 정의 메세지셋 사용, gemMsgRequested 이벤트 참고)
    gem->DisableAutoReply(1, 15);/* REQUEST OFFLINE */
    gem->DisableAutoReply(1, 17);/* REQUEST ONLINE */
	//gem->DisableAutoReply(2, 41);
    gem->DisableAutoReply(5, 3);
    gem->DisableAutoReply(7, 3);
    gem->DisableAutoReply(7, 5);
    gem->DisableAutoReply(7, 17);
    gem->DisableAutoReply(7, 19);
    gem->DisableAutoReply(7, 25);
    gem->DisableAutoReply(14, 2);

    while(1) {
        if(AddID() || !AddID()) // AddID가 성공하면 빠져나감
            break;
        WaitForSingleObject((void *)this->Handle, 1000);
    }

    // 데이터 초기 세팅
    tmpSvid = mapSvid;
    SetECID();
    SetSVID(true);

    int resultStart = gem->Start();
    if(resultStart < 0) {// gem  start 실패시 로그 처리
        AddLog("Failed to SECS/GEM start : " + AnsiString(resultStart));
        m_nHostConnected = HOST_DISCONNECT;
    } else {
        AddLog("SECS/GEM Start...");
        gem->EnableCommunication();
        m_nHostConnected = HOST_WAITING;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::StopGem(AnsiString strReason)
{
    gem->DisableCommunication();
    gem->Stop();
    AddLog("SECS/GEM Stop : " + strReason);
    m_nHostConnected = HOST_DISCONNECT;
}
//---------------------------------------------------------------------------
bool __fastcall TSecsGemForm::AddID()
{
    static bool bMapSvidInit = false;
    AnsiString path;
    TStringList *strList = new TStringList();

    try {
        if(!FileExists("EzGemID_mkud100.txt")) return false;
        strList->Clear();
        strList->LoadFromFile("EzGemID_mkud100.txt");
        //mapSvid.clear();

        for(int i=0; i<strList->Count; i++) {
            if(strList->Strings[i].AnsiPos("***") || strList->Strings[i].IsEmpty())
                continue;

            if(strList->Strings[i].Pos("RCMD")) {
                AnsiString sRCMD = strList->Strings[i].Delete(1, 5);
                gem->AddRemoteCommand(WideString(sRCMD));
                continue;
            }

            int nTabPos = strList->Strings[i].Pos("\t");
            AnsiString idStr = strList->Strings[i].SubString(1, nTabPos-1);

            int id;
            try {
                id = idStr.ToInt();
            }
            catch(...) {
                ShowMessage("AddID() Tab Error"+strList->Strings[i]);
            }

            if(id > 0 && id < 1000) {// alarm Id
                int ID, pos;
                WideString name, dscr = "";

                pos = strList->Strings[i].Pos("\t");
                ID  = strList->Strings[i].SubString(1, pos-1).ToInt();
                name= strList->Strings[i].SubString(pos+1, strList->Strings[i].Length()-pos);

                gem->AddAlarmID(ID, name.c_bstr(), dscr.c_bstr());
            }
            else if(id > 1000 && id < 2000) {// event id
                int ID, pos;
                WideString name, dscr = "";

                pos = strList->Strings[i].Pos("\t");
                ID  = strList->Strings[i].SubString(1, pos-1).ToInt();
                name= strList->Strings[i].SubString(pos+1, strList->Strings[i].Length()-pos);

                gem->AddCEID(ID, name, dscr);
            }
            else if(id > 2000 && id < 3000) {// svid
                int pos1, pos2, id;
                WideString tmpStr, name, type, unit = "";

                pos1 = strList->Strings[i].Pos("\t");
                tmpStr = strList->Strings[i].SubString(pos1+1, strList->Strings[i].Length()-pos1+1);
                pos2 = tmpStr.Pos("\t");

                id = strList->Strings[i].SubString(1, pos1-1).ToInt();
                name = strList->Strings[i].SubString(pos1+1, pos2-1);
                type = WideString(strList->Strings[i].SubString(pos1+pos2+1, strList->Strings[i].Length()-pos2-pos1));

                gem->AddSVID(id, name, type, unit);

                if(!bMapSvidInit)
                    mapSvid.insert(make_pair(id, "")); //Svid 넘버를 map에 저장
            }
            else if(id > 3000 && id < 4000) {// ecid
                int pos1, pos2, id;
                WideString name, unit = "", dataFormat = "", tmpStr;

                pos1 = strList->Strings[i].Pos("\t");
                tmpStr = strList->Strings[i].SubString(pos1+1, strList->Strings[i].Length()-pos1+1);
                pos2 = tmpStr.Pos("\t");

                id = strList->Strings[i].SubString(1, pos1-1).ToInt();
                name= strList->Strings[i].SubString(pos1+1, pos2-1);
                dataFormat = strList->Strings[i].SubString(pos1+pos2+1, strList->Strings[i].Length()-pos2-pos1);

                gem->AddECID(id, name, unit, dataFormat);
            }
        }
        delete strList;
        strList = NULL;

        bMapSvidInit = true;

        return true; // Add 성공
    } catch(...) {
        if(strList != NULL) {// Add 실패시 데이터 날리기
            delete strList;
            strList = NULL;
        }
        mapSvid.clear();

        return false; // Add 실패시 리턴
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::SetECID()
{
    gem->SetEquipConstValue(3001, WideString(AnsiString(1)));
    gem->SetEquipConstValue(3002, WideString(AnsiString(sys.fac.nSecsGemPort)));
    gem->SetEquipConstValue(3003, WideString(AnsiString(sys.fac.chSecsGemIp)));
    gem->SetEquipConstValue(3004, WideString(AnsiString(30)));
    gem->SetEquipConstValue(3005, WideString(AnsiString(5)));
    gem->SetEquipConstValue(3006, WideString(AnsiString(20)));
    gem->SetEquipConstValue(3007, WideString(AnsiString(5)));
    gem->SetEquipConstValue(3008, WideString(AnsiString(6)));
    gem->SetEquipConstValue(3009, WideString(AnsiString(30)));
    gem->SetEquipConstValue(3010, WideString(AnsiString(3)));
    gem->SetEquipConstValue(3011, WideString(AnsiString(0)));
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::SetSVID(bool bInit)
{
    try
    {
        if(!mapSvid.empty())
        {
            map<int, AnsiString>::iterator iter = mapSvid.begin();
            map<int, AnsiString>::iterator jter = tmpSvid.begin();

            for ( ; iter != mapSvid.end(); ++iter, ++jter)
            {
                if(jter == tmpSvid.end())
                    break;

                // 이전 데이터와 비교하여 같으면 continue
                if(!bInit && iter->second == jter->second)
                    continue;

                WideString tmp = iter->second;
                gem->SetCurrentStatusValue(iter->first, tmp.c_bstr()); // gem ocx에 업데이트
            }

            // tmp값 갱신
            tmpSvid = mapSvid;
        }
    }
    catch(...)
    {
    }
}
//---------------------------------------------------------------------------
void TSecsGemForm::RefreshSVID ()
{
    BYTE PrevControlState = SECSGEM_SVID.ControlState;
    BYTE PrevProcessState = SECSGEM_SVID.ProcessState;
    SECSGEM_SVID.CommState            = 7; // Communicating
    if(OnlineBtn->Down) {
        if(AllowRemoteBtn->Down)
            SECSGEM_SVID.ControlState = ONLINE_REMOTE; // On Line, Remote
        else SECSGEM_SVID.ControlState= ONLINE_LOCAL; // On Line, Local
    } else  SECSGEM_SVID.ControlState = EQP_OFF_LINE; // Off Line
    if(PrevControlState != SECSGEM_SVID.ControlState)
        SECSGEM_SVID.PrevControlState = PrevControlState;
    if(MainForm->ProductPanel->Visible) {
        if(Chk.m_bMainErrEvent) SECSGEM_SVID.ProcessState = 3; // Error
        else {
            if(Work.m_nStatus != RSTOP) SECSGEM_SVID.ProcessState = 1; // Run
            else if(m_bCycleStopDone) SECSGEM_SVID.ProcessState = 4; // Idle
            else SECSGEM_SVID.ProcessState = 2; // Stop
        }
    } else {
        if(WorkSetupForm->TickTimer->Enabled) SECSGEM_SVID.ProcessState = 5; // Programming
        else SECSGEM_SVID.ProcessState = 4; // Idle
    }
    if(PrevProcessState != SECSGEM_SVID.ProcessState)
        SECSGEM_SVID.PrevProcessState= PrevProcessState;
    SECSGEM_SVID.CurrentPPID          = Ext.GetFileName(run.chMdlFile);
    SECSGEM_SVID.CycleTime            = (lot.nUph == 0?0.:StrToFloat(3600.0/lot.nUph));
    SECSGEM_SVID.TotalCount           = run.nData[TTL_OUT]+run.nData[TTL_REJ];
    SECSGEM_SVID.ProductCount         = run.nData[TTL_OUT];
    SECSGEM_SVID.RejectCount          = run.nData[TTL_REJ];
    SECSGEM_SVID.UPH                  = lot.nUph;
    SECSGEM_SVID.OperatorID           = PrepareForm->OperNameEdit->Text;
    SECSGEM_SVID.DeviceName           = Ext.GetFileName(run.chMdlFile);
    SECSGEM_SVID.LotID                = PrepareForm->LotNumEdit->Text;
    SECSGEM_SVID.MainAirStatus        = IO.In(mainairgood);
    SECSGEM_SVID.MachineInialized     = Init.m_bDone;
    SECSGEM_SVID.EQLifeTime           = CnvDateTime(run.nData[TM_PGM]/1000);
    SECSGEM_SVID.EQRunTime            = CnvDateTime(run.nData[TM_RUN]/1000);
    SECSGEM_SVID.EQStopTime           = CnvDateTime(run.nData[TM_STOP]/1000);
    SECSGEM_SVID.EQErrorTime          = CnvDateTime(run.nData[TM_ERR]/1000);
    SECSGEM_SVID.EQMTBA               = CnvDateTime(run.nData[MTBA]/1000);
    SECSGEM_SVID.ProductStartTime     = StartProductionTime.FormatString("yyyymmddhhnnss");
    SECSGEM_SVID.ProductEndTime       = EndProductionTime.FormatString("yyyymmddhhnnss");
}

void TSecsGemForm::SendSVID ()
{
    AnsiString SVIDList="";

    mapSvid[2001] = IntToStr(SECSGEM_SVID.CommState);
    mapSvid[2002] = IntToStr(SECSGEM_SVID.ControlState);
    mapSvid[2003] = IntToStr(SECSGEM_SVID.PrevControlState);
    mapSvid[2004] = IntToStr(SECSGEM_SVID.ProcessState);
    mapSvid[2005] = IntToStr(SECSGEM_SVID.PrevProcessState);
    mapSvid[2006] = AnsiString(SECSGEM_SVID.CurrentPPID);
    mapSvid[2007] = FloatToStrF(SECSGEM_SVID.CycleTime,ffFixed,7,1);
    mapSvid[2008] = IntToStr(SECSGEM_SVID.TotalCount);
    mapSvid[2009] = IntToStr(SECSGEM_SVID.ProductCount);
    mapSvid[2010] = IntToStr(SECSGEM_SVID.RejectCount);
    mapSvid[2011] = FloatToStrF(SECSGEM_SVID.UPH,ffFixed,7,1);
    mapSvid[2012] = AnsiString(SECSGEM_SVID.OperatorID);
    mapSvid[2013] = AnsiString(SECSGEM_SVID.DeviceName);
    mapSvid[2014] = AnsiString(SECSGEM_SVID.LotID);
    mapSvid[2015] = IntToStr(SECSGEM_SVID.MainAirStatus);
    mapSvid[2016] = IntToStr(SECSGEM_SVID.MachineInialized);
    mapSvid[2017] = AnsiString(SECSGEM_SVID.EQLifeTime);
    mapSvid[2018] = AnsiString(SECSGEM_SVID.EQRunTime);
    mapSvid[2019] = AnsiString(SECSGEM_SVID.EQStopTime);
    mapSvid[2020] = AnsiString(SECSGEM_SVID.EQErrorTime);
    mapSvid[2021] = AnsiString(SECSGEM_SVID.EQMTBA);
    mapSvid[2022] = AnsiString(SECSGEM_SVID.ProductStartTime);
    mapSvid[2023] = AnsiString(SECSGEM_SVID.ProductEndTime);
    mapSvid[2064] = FormatDateTime("yyyymmddhhnnss", m_dtLotEndTime);

    SetSVID();
}
//---------------------------------------------------------------------------
AnsiString TSecsGemForm::CnvDateTime (long TimeSec)
{
    AnsiString strP;

    int Year = TimeSec/31536000;
    int Month = (TimeSec%31536000)/2592000;
    int Day = ((TimeSec%31536000)%2592000)/86400;
    int Hour = (((TimeSec%31536000)%2592000)%86400)/3600;
    int Min = ((((TimeSec%31536000)%2592000)%86400)%3600)/60;
    int Sec = ((((TimeSec%31536000)%2592000)%86400)%3600)%60;
    strP.sprintf ("%04d%02d%02d%02d%02d%02d", Year, Month, Day, Hour, Min, Sec);
    return strP;
}
//---------------------------------------------------------------------------
int TSecsGemForm::GetAlCD (int AlCode, bool isSetAlarm)
{
    int AL_BIT = (isSetAlarm)?0x80:0;
    switch (AlCode) {
            case 2: case 3: case 4: return AL_BIT | 1;
            case 1: case 5: case 8: case 101: case 102: case 103:
            case 104: case 105: case 106: case 107: case 108: case 109: case 110:
            case 111: case 112: case 113: case 114: case 115: case 116: case 117:
            case 118: case 119: case 120: case 121: case 122: case 123: case 124:
            case 125: case 126: return AL_BIT | 3;
            default : return AL_BIT | 4;
    }
}
//---------------------------------------------------------------------------
void TSecsGemForm::AddLog(AnsiString sMsg)
{
    TListBox *p = LogListBox;

    TDateTime CurTime = Now();
    unsigned short hour, min, sec, msec;
    unsigned short year, month, day;
    CurTime.DecodeTime (&hour, &min, &sec, &msec);
    CurTime.DecodeDate(&year, &month, &day);
    AnsiString TimeToString;
    TimeToString.sprintf("%02d:%02d, %02d:%02d:%02d.%03d(ms)", month, day, hour, min, sec, msec);
    AnsiString strP;
    strP.sprintf ("[%s] %s", TimeToString, sMsg);
    p->Items->Add(strP);
    if(p->Items->Count > 200)
        p->Items->Delete(0);
    SendMessage(p->Handle, WM_VSCROLL, SB_BOTTOM, 0);

    AnsiString sLogFile = SYSLOG_FILE_PATH+"\\System\\"+Now().FormatString("yyyymmdd")+".txt";
    FILE *fp = fopen(sLogFile.c_str(), "at");
    fseek(fp,0,2); //Search End of
    fprintf(fp, "%s \r\n", strP.c_str());
    fclose(fp);
}
//---------------------------------------------------------------------------
AnsiString TSecsGemForm::GetDateTimeString (TDateTime td)
{
    unsigned short year, month, day;
    unsigned short hour, min, sec, msec;

    td.DecodeDate(&year, &month, &day);
    td.DecodeTime(&hour, &min, &sec, &msec);

    AnsiString strP;
    strP.sprintf("%04d%02d%02d%02d%02d%02d",
                year, month, day, hour, min, sec);
    return strP;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::MsgSendBtnClick(TObject *Sender)
{
    if(!OnlineBtn->Down) return;

    short tid = 0;

    if(gem != NULL) {
        long lMsgId = gem->CreateMsg(10, 1, TRUE);
        gem->OpenListItem(lMsgId);
        gem->AddBinaryItem(lMsgId, &tid, 1);
        gem->AddAsciiItem(lMsgId, WideString(SendMsgMemo->Text), SendMsgMemo->Text.Length());
        gem->CloseListItem(lMsgId);
        gem->SendMsg(lMsgId);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::SvidTimerTimer(TObject *Sender)
{
    if(!sys.fac.bUseSecsGem) {
        StopGem("No Use SecsGem");
        return;
    }

    if(!m_nHostConnected) {
        if(!OnlineBtn->Down) {
            SECSGEM_SVID.ControlState = EQP_OFF_LINE;
        } else {
            if(sys.fac.bUseSecsGem)
                StartGem();
        }
        return;
    }
    RefreshSVID ();
    SendSVID ();
    SvidTimer->Interval = 15000;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::OnlineBtnClick(TObject *Sender)
{
    static bool isProcess = false;
    if(isProcess || !sys.fac.bUseSecsGem) return;
    isProcess = true;
    OnlineBtn->Caption = (OnlineBtn->Down)?"ON LINE":"OFF LINE";
    if(OnlineBtn->Down) {
        if(!m_nHostConnected) {
            SvidTimer->Enabled=false;
            StartGem();
            SvidTimer->Enabled=true;
            isProcess = false;
            return;
        }
        SendEvent(C_LOCAL, false);
    } else {
        SendEvent(C_OFFLINE, false);
    }
    isProcess = false;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::m_CloseClick(TObject *Sender)
{
    Hide();
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::MsgClearBtnClick(TObject *Sender)
{
    RcvMsgMemo->Clear();
    SendEvent(C_TERMINAL_MSG_ACK, false);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::m_IPChangeClick(TObject *Sender)
{
    if(!SecsGemIpEdit->Text.IsEmpty()) {
        strcpy(sys.fac.chSecsGemIp , SecsGemIpEdit->Text.c_str());
        sys.fac.nSecsGemPort  = SecsGemPortEdit->Text.ToIntDef(5050);
        StopGem("IP Change");
        
        Data.SaveConfigData(true);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::AllowRemoteBtnClick(TObject *Sender)
{
    RefreshSVID();
    SendSVID ();
    if(AllowRemoteBtn->Down)
        SendEvent(C_REMOTE, false);
    else SendEvent(C_LOCAL, false);
}
//---------------------------------------------------------------------------
// return value : zip name
AnsiString  TSecsGemForm::ZipPrgFiles(AnsiString FileID)
{
    //AnsiString zipName = MODEL_FILE_PATH + FileID + ".zip";
    AnsiString zipName = MAIN_PATH+"data\\"+FileID+".zip";

    AddLog ("[Compressed file and uploaded] Full name="+zipName);
    if(FileExists(zipName)) DeleteFile(zipName);

    /*
    Zip->ZipFileName = zipName;
    Zip->Verbose = true;

    // Add as many filespecs as we want to:
    // (MS-DOS Wildcards are OK)
    Zip->FSpecArgs->Add(MODEL_FILE_PATH + FileID +".wrk");

    Zip->AddOptions = Zip->AddOptions << AddHiddenFiles;
    Zip->AddOptions = Zip->AddOptions >> AddEncrypt; // no password
    Zip->Add();
    */

    return zipName;
}
//---------------------------------------------------------------------------
int  TSecsGemForm::UnzipPrgFiles(AnsiString FullName)
{
    // extract key name
    AnsiString zipName = FullName; // prgID.SubString(1,prgID.Length()-4) + ".zip";

    if(!FileExists(zipName))
        return -1;

    /*
    Zip->ZipFileName = zipName;
    Zip->Verbose = true;

    // We can specify as many filespecs as we want to extract:
    // (MS-DOS Wildcards are OK)
    Zip->FSpecArgs->Add("*.*");

    Zip->ExtrOptions = Zip->ExtrOptions << ExtrOverWrite;

    int nRtn = Zip->Extract();

    AnsiString sFileName = Ext.GetFileName(FullName);

    return nRtn;
    */
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::EventTimerTimer(TObject *Sender)
{
    Button1->Visible = sys.fac.bDebugMode;
    Button2->Visible = sys.fac.bDebugMode;
    Button3->Visible = sys.fac.bDebugMode;
    Button4->Visible = sys.fac.bDebugMode;

    HostConnectedLed->ImageIndex = m_nHostConnected;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::SendEvent(int nCEID, bool bSVID)
{
    if(!sys.fac.bUseSecsGem) return;

    if(bSVID) {
        RefreshSVID();
        SendSVID ();
    }
    gem->SendEventReport(nCEID);
}
//---------------------------------------------------------------------------
int __fastcall TSecsGemForm::GetBinaryItem(AnsiString body, short* pList)
{
    int itemCnt = 0;
    AnsiString tmpStr = body;

    AnsiString hexStr = "";
    for (int i=1; i<=tmpStr.Length(); i++)
    {
        hexStr += tmpStr[i];
        if((i & 0x1) == 0) // i % 2 == 0
        {
            *pList = HexToInt(hexStr).ToInt();

            pList++;
            hexStr = "";
            itemCnt++;
        }
    }
    return itemCnt;
}
// ---------------------------------------------------------------------
AnsiString __fastcall TSecsGemForm::HexToInt(AnsiString str)
{
    AnsiString temp;
    int index = 1;
    int tmpCharInt = 0;
    int tmpResult = 0;
    for (int Length=str.Length(); Length>0; Length--,index++)
    {
        temp = str.SubString(index,1);
        if      (temp.LowerCase() == "a") temp = 10;
        else if(temp.LowerCase() == "b") temp = 11;
        else if(temp.LowerCase() == "c") temp = 12;
        else if(temp.LowerCase() == "d") temp = 13;
        else if(temp.LowerCase() == "e") temp = 14;
        else if(temp.LowerCase() == "f") temp = 15;

        if(Length != 1)
            tmpCharInt = temp*(pow(16,(Length-1)));
        else
            tmpCharInt = temp*1;
        tmpResult += tmpCharInt;
    }
    return AnsiString(tmpResult);
}
// ---------------------------------------------------------------------
void __fastcall TSecsGemForm::SendALCD(bool bSet, AnsiString sErrMsg)
{
    if(sys.fac.bUseSecsGem) {
        static clock_t tTick;
        static AnsiString sSaveMsg;

        if(abs(clock()-tTick) < 100 || sSaveMsg == sErrMsg)
            return;

        int ErrorCode = -1;
        for(int i=0; i<Ext.m_pLngList[STR_ALID]->Count; i++) {
            if(Ext.m_pLngList[STR_ALID]->Strings[i].AnsiCompare(sErrMsg) == 0) {
                ErrorCode = i;
                break;
            }
        }
        if(ErrorCode > -1) {
            if(SECSGEM_isEnabledAlarmReport[ErrorCode]) {
                int nALCD = GetAlCD(ErrorCode, bSet);
                int nALID = ErrorCode;
                gem->SendAlarmReport(nALID, nALCD);
            }
        }

        tTick = clock();
        sSaveMsg = sErrMsg;

        SendEvent(bSet?C_ALARM_SET:C_ALARM_CLEAR);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::WorkDataToTextFile(AnsiString sFileName)
{
    if(sFileName.IsEmpty())
        sFileName = MAIN_PATH+"data\\"+Ext.GetFileName(run.chMdlFile)+".txt";

    FILE *fp = fopen(sFileName.c_str(), "w+t");

    for(int i=0; i<2; i++) {
        AnsiString sPkr = (i==0?"AT_HD1_":"AT_HD2_");
        /*
        fprintf(fp, "%sUnit_Number_X=%d\n", sPkr.c_str(), mdl.pkr[i].nRowCnt0);
        fprintf(fp, "%sUnit_Number_Y=%d\n", sPkr.c_str(), mdl.pkr[i].nColCnt0);
        fprintf(fp, "%sBlock_Number_X=%d\n", sPkr.c_str(), mdl.pkr[i].nBlockXCnt);
        fprintf(fp, "%sBlock_Number_Y=%d\n", sPkr.c_str(), mdl.pkr[i].nBlockYCnt);

        fprintf(fp, "%sUnit_Pitch_X=%.3f\n", sPkr.c_str(), mdl.prs.dRowPitch);
        fprintf(fp, "%sUnit_Pitch_Y=%.3f\n", sPkr.c_str(), mdl.prs.dColPitch);
        fprintf(fp, "%sBlock_Pitch_X=%.3f\n", sPkr.c_str(), mdl.prs.dBlockXPitch);
        fprintf(fp, "%sBlock_Pitch_Y=%.3f\n", sPkr.c_str(), mdl.prs.dBlockYPitch);

        fprintf(fp, "%sUse_Pick_Up_Waiting_Height=%s\n", sPkr.c_str(), mdl.prs.bUsePickUpWait?"Enable":"Disable");
        fprintf(fp, "%sPick_Up_Waiting_Height=%.3f\n", sPkr.c_str(), mdl.prs.dPickUpWaitHgt);

        fprintf(fp, "%sPick_Up_Waiting_Time=%d\n", sPkr.c_str(), mdl.prs.nPickUpWaitTime);
        fprintf(fp, "%sPick_Up_Viberation_Length=%d\n", sPkr.c_str(), mdl.prs.nVibLenght);
        fprintf(fp, "%sUse_Pick_Up_Air_Blower=%s\n", sPkr.c_str(), mdl.prs.bAirBlower?"Enable":"Disable");

        fprintf(fp, "%sAttach_Force=%.1f\n", sPkr.c_str(), mdl.prs.dAtchForce);
        fprintf(fp, "%sAttach_Max_Alarm_Force=%.1f\n", sPkr.c_str(), mdl.prs.dMaxForce);
        fprintf(fp, "%sAttach_Min_Alarm_Force=%.1f\n", sPkr.c_str(), mdl.prs.dMinForce);

        fprintf(fp, "%sUse_Lid_Height_Inspection=%s\n", sPkr.c_str(), mdl.prs.bHgtInsp?"Enable":"Disable");
        fprintf(fp, "%sLid_Flatness_Detection_Value=%.3f\n", sPkr.c_str(), mdl.prs.dHgtInspDev);
        fprintf(fp, "%sDouble_Lid_Detection_Thickness=%.3f\n", sPkr.c_str(), mdl.prs.dDoubleLidDct);

        fprintf(fp, "%sPick_Up_Speed=%d\n", sPkr.c_str(), mdl.prs.nPickUpSpd);
        fprintf(fp, "%sPick_Up_Acceleration_Time=%d\n", sPkr.c_str(), mdl.prs.nPickUpAcc);

        fprintf(fp, "%sPad_Heater_Temperature=%d\n", sPkr.c_str(), mdl.prs.nHtrTemp[i]);
        fprintf(fp, "%sBlock_Heater_Temperature=%d\n", sPkr.c_str(), mdl.prs.nHtrTemp[i+2]);
        fprintf(fp, "%sBlock_Cure_Time=%d\n", sPkr.c_str(), mdl.prs.nCureTime[i+2]);

        fprintf(fp, "%sUse_Pin1_Mark_Inspection=%s\n", sPkr.c_str(), mdl.prs.bChambInsp?"Enable":"Disable");
        fprintf(fp, "%sUse_Pin1_Position_Detection=%.3f\n", sPkr.c_str(), mdl.prs.dHolePosDeviation);
        fprintf(fp, "%sUse_Pin1_Hole_Size_Detection=%.3f\n", sPkr.c_str(), mdl.prs.dHoleSizeDeviation);

        fprintf(fp, "%sUse_Elevator_Down_Pick_Up=%s\n", sPkr.c_str(), mdl.prs.bElevDownPickUp?"Enable":"Disable");
        fprintf(fp, "%sElevator_Down_Delay=%d\n", sPkr.c_str(), mdl.prs.nElevDownDly);

        fprintf(fp, "%sConveyor_Width=%.3f\n", sPkr.c_str(), mdl.prs.dCvyWidth);

        fprintf(fp, "%sPressing_Speed=%.1f\n", sPkr.c_str(), mdl.prs.dPressingSpd);
        fprintf(fp, "%sPressing_Delay_Time=%d\n", sPkr.c_str(), mdl.prs.nAtchDly);
        fprintf(fp, "%sUnloading_Slot_Interval=%d\n", sPkr.c_str(), mdl.prs.nUlSlotTerm);
        fprintf(fp, "%sUnloading_Position_Select=%d\n", sPkr.c_str(), mdl.prs.nUlPosSel);

        fprintf(fp, "%sAttach_Offset_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].ofstAtch.x);
        fprintf(fp, "%sAttach_Offset_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].ofstAtch.y);
        fprintf(fp, "%sAttach_Offset_Angle=%.3f\n", sPkr.c_str(), mdl.pkr[i].ofstAtch.r);
        fprintf(fp, "%sFiducia1_Position_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posFid[0].x);
        fprintf(fp, "%sFiducia1_Position_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posFid[0].y);
        fprintf(fp, "%sFiducia2_Position_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posFid[1].x);
        fprintf(fp, "%sFiducia2_Position_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posFid[1].y);
        fprintf(fp, "%sPress_Distance=%.3f\n", sPkr.c_str(), mdl.pkr[i].dPrsDist);
        for(int j=0; j<4; j++) {
            fprintf(fp, "%sPick_Up_Position%dX=%.3f\n", sPkr.c_str(), j+1, mdl.pkr[i].posPickUp[j].x);
            fprintf(fp, "%sPick_Up_Position%dY=%.3f\n", sPkr.c_str(), j+1, mdl.pkr[i].posPickUp[j].y);
        }
        for(int j=0; j<3; j++)
            fprintf(fp, "%sTop_Fiducial1_Vision_Light%d=%d\n", sPkr.c_str(), j+1, mdl.pkr[i].nVsnLight[0][j]);
        for(int j=0; j<3; j++)
            fprintf(fp, "%sTop_Fiducial2_Vision_Light%d=%d\n", sPkr.c_str(), j+1, mdl.pkr[i].nVsnLight[1][j]);
        for(int j=0; j<3; j++)
            fprintf(fp, "%sBottom_Vision_Light%d=%d\n", sPkr.c_str(), j+1, mdl.pkr[i].nVsnLight[2][j]);
        fprintf(fp, "%sDispenser_Inspection_Position_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posDispInsp.x);
        fprintf(fp, "%sDispenser_Inspection_Position_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posDispInsp.y);
        fprintf(fp, "%sLid_Orientation_Hole_Size_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].crdHoleSize.x);
        fprintf(fp, "%sLid_Orientation_Hole_Size_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].crdHoleSize.y);
        fprintf(fp, "%sPick_Up_Postion_By_Camera_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posPickUpByCam.x);
        fprintf(fp, "%sPick_Up_Postion_By_Camera_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posPickUpByCam.y);
        fprintf(fp, "%sLid_Height_Inspection_Point_Number=%d\n", sPkr.c_str(), mdl.pkr[i].nHgtInspPtNum);
        for(int j=0; j<mdl.pkr[i].nHgtInspPtNum; j++) {
            AnsiString sTemp = AnsiString(mdl.pkr[i].chHgtInspPt[j]);
            sTemp = sTemp.Delete(sTemp.AnsiPos(",")+1,1);
            fprintf(fp, "%sLid_Height_Inspection_Position=%s\n", sPkr.c_str(), sTemp.c_str());
        }
        for(int j=0; j<mdl.pkr[i].nRowCnt*mdl.pkr[i].nColCnt; j++) {
            for(int k=0; k<mdl.pkr[i].nHgtInspPtNum; k++) {
                fprintf(fp, "%sLid_Height_Default_Data=%.3f\n", sPkr.c_str(), mdl.pkr[i].dUnitHgtData[j][k]);
            }
        }
        fprintf(fp, "%sUse_Dispenser_Inspection_Camera_Align=%s\n", sPkr.c_str(), mdl.pkr[i].bDispInspCamAlign?"Enable":"Disable");
        fprintf(fp, "%sDispenser_Inspection_Align_Reference_Position_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posDispRef.x);
        fprintf(fp, "%sDispenser_Inspection_Align_Reference_Position_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posDispRef.y);
        fprintf(fp, "%sAttach_Height_Check_Mode=%d_\n", sPkr.c_str(), mdl.pkr[i].nAtchHgtChkMode);

        fprintf(fp, "%sAttach_Height_Check_Position_X=%.3f\n", sPkr.c_str(), mdl.pkr[i].posLsrAtchHgt.x);
        fprintf(fp, "%sAttach_Height_Check_Position_Y=%.3f\n", sPkr.c_str(), mdl.pkr[i].posLsrAtchHgt.y);
        */
    }

   fclose(fp);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::LogListBoxDblClick(TObject *Sender)
{
    if(MessageBox(NULL, AnsiString("Do you want to delete the log?").c_str(),
        AnsiString("Question.").c_str(), MB_OKCANCEL|MB_ICONQUESTION) == ID_OK) {
        LogListBox->Clear();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::OpenLogFolderBtnClick(TObject *Sender)
{
    HWND hwnd = NULL;
    LPCTSTR lpOperation = "open";
    LPCTSTR lpFile = NULL;
    LPCTSTR lpParameters = NULL;
    LPCTSTR lpDirectory = AnsiString(SYSLOG_FILE_PATH+"SecsGem\\").c_str();
    int nShowCmd = SW_SHOWDEFAULT;

    ShellExecute(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemConnected(TObject *Sender)
{
    AddLog("--------------------------------------------------");
    AddLog("Host connected");
    m_nHostConnected = HOST_CONNECT;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemDisconnected(TObject *Sender)
{
    AddLog("Host disconnected");
    AddLog("--------------------------------------------------");
    m_nHostConnected = HOST_DISCONNECT;
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemDateTimeSetRequest(TObject *Sender, long lMsgId, BSTR strNewDateTime)
{
    gem->AcceptAndSetNewDateTime(lMsgId,strNewDateTime);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemEstablishCommRequest(TObject *Sender, long lMsgId)
{
    gem->AcceptEstablishCommRequest(lMsgId);
    gem->GoOnlineRemote();
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemCommEstablished(TObject *Sender)
{
    //gem->AcceptEstablishCommRequest(lMsgId);
    gem->GoOnlineRemote();
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemOnlineRequest(TObject *Sender, long lMsgId)
{
	gem->AcceptOnlineRequest(lMsgId);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemOfflineRequest(TObject *Sender, long lMsgId)
{
    gem->AcceptOnlineRequest(lMsgId);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemOnlineLocal(TObject *Sender)
{
    gem->GoOnlineLocal();
    mapSvid[2003] = IntToStr(4);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemOnlineRemote(TObject *Sender)
{
    gem->GoOnlineRemote();
    mapSvid[2003] = IntToStr(5);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemTerminalMessageMulti(TObject *Sender,
      long lMsgId, short nCode, short nCount)
{
    RcvMsgMemo->Clear();

    for(int i=0; i<nCount; i++) {
        AnsiString sTerminalMsg = gem->GetTerminalMessageMulti(lMsgId, i);
        RcvMsgMemo->Lines->Add(sTerminalMsg);
    }

    gem->AcceptTerminalMessage(lMsgId);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemTerminalMessageSingle(TObject *Sender,
      long lMsgId, BSTR strCommand, short nParamCount)
{
    RcvMsgMemo->Clear();
    RcvMsgMemo->Lines->Add(strCommand);

    gem->AcceptTerminalMessage(lMsgId);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::SendTerminalMsg(AnsiString txt)
{
try {
    short tid = 0;

    if(gem != NULL) {
        long lMsgId = gem->CreateMsg(10, 1, TRUE);
        gem->OpenListItem(lMsgId);
        gem->AddBinaryItem(lMsgId, &tid, 1);
        gem->AddAsciiItem(lMsgId, WideString(txt), txt.Length());
        gem->CloseListItem(lMsgId);
        gem->SendMsg(lMsgId);
    }
} catch(...) {}
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemSecsMsgIn(TObject *Sender, short nStream, short nFunction, short nWbit, long lSysByte)
{
    // 로그용
    AnsiString logTxt = "R : ";
    logTxt += "S" + IntToStr(nStream) + "F" + IntToStr(nFunction);
    AddLog(logTxt);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemSecsMsgOut(TObject *Sender, short nStream, short nFunction, short nWbit, long lSysByte)
{
    // 로그용
    AnsiString logTxt = "S : ";
    logTxt += "S" + IntToStr(nStream) + "F" + IntToStr(nFunction);
    AddLog(logTxt);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemRemoteCommand(TObject *Sender,
      long lMsgId, BSTR strCommand, short nParamCount)
{
//m_gem.DenyRemoteCommand(lMsgId, strCommand, NAK);
// (거부시) NAK CODE는 아래와 같습니다.
//  -1 = CANNOT PERFORM NOW
//  -2 = PARAMETER IS INVALID
//  -3 = ALREADY IN DESIRED CONDITION
//  -4 = UNABLE TO PERFORM, INTERNAL ERROR OCCURRED
// REMOTE COMMAND를 받아들일때는 아래와 같이 처리합니다.
//m_gem.AcceptRemoteCommand(lMsgId, strCommand, ACK);
// (허용시) ACK CODE는 아래와 같습니다.
// 0 = ACKNOWLEDGE, COMMAND PERFORMED
// 1 = ACKNOWLEDGE, COMMAND WILL BE PERFORMED SOON

    AnsiString sRCmd, sCpName[100], sCpVal[100];
    int nParmCnt = (nParamCount>100?100:nParamCount);
    sRCmd = AnsiString(strCommand);

    for(int i=0; i<nParmCnt; i++) {
        sCpName[i] = gem->GetRemoteCommandParamName(lMsgId, strCommand, i);
        sCpVal[i] = gem->GetRemoteCommandParamValue(lMsgId, strCommand, i);
    }

    if(sRCmd == "GOLOCAL") {
        if(!AllowRemoteBtn->Down)
            gem->DenyRemoteCommand(lMsgId, strCommand, -3);
        else {
            AllowRemoteBtn->Down = false;
            AllowRemoteBtnClick(NULL);
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        }
    }
    else if(sRCmd == "GOREMOTE") {
        if(AllowRemoteBtn->Down)
            gem->DenyRemoteCommand(lMsgId, strCommand, -3);
        else {
            AllowRemoteBtn->Down = true;
            AllowRemoteBtnClick(NULL);
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        }
    }
    else if(sRCmd == "START") {
        if(Work.m_nStatus == RSTOP) {
            MainForm->PanelClick(MainForm->StartPanel);
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        }
        else gem->DenyRemoteCommand(lMsgId, strCommand, -3);
    }
    else if(sRCmd == "STOP" ) {
        if(Work.m_nStatus != RSTOP) {
            MainForm->PanelClick(MainForm->StopPanel);
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        }
        else gem->DenyRemoteCommand(lMsgId, strCommand, -3);
    }
    else if(sRCmd == "ALARM") {
        Chk.ViewAlarm("Host CMD: "+sCpName[0]);
        gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
    }
    else if(sRCmd == "PPSELECT") {
        AnsiString sRecipeID = MODEL_FILE_PATH+sCpName[0]+".wrk";

        if(Work.m_nStatus != RSTOP || !AnsiString(run.chMdlFile).IsEmpty())
            gem->DenyRemoteCommand(lMsgId, strCommand, -1);
        else {
            if(!FileExists(sRecipeID)) {
                gem->DenyRemoteCommand(lMsgId, strCommand, -2);
            } else {
                for(int i=0; i<nParmCnt; i++) {
                    if(sCpName[i]=="LOTID" && !sCpVal[i].IsEmpty())
                        PrepareForm->LotNumEdit->Text = sCpVal[i];
                    else if(sCpName[i]=="USERDATA")
                        SECSGEM_SVID.UserData = sCpVal[i];

                }
                Data.LoadModelData(sRecipeID, true);
                if(WorkSetupForm->Visible)
                    WorkSetupForm->VarToComponent();
                gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
            }
        }
    }
    else if(sRCmd == "LOTIDCHANGE") {
        AnsiString LotID = sCpName[0];
        if(Work.m_nStatus != RSTOP)
            gem->DenyRemoteCommand(lMsgId, strCommand, -3);
        else {
            PrepareForm->LotNumEdit->Text = LotID;
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        }
    }
    else if(sRCmd == "NEWLOT") {
        AnsiString LotID = sCpName[0];
        if(Work.m_nStatus != RSTOP) {
            gem->DenyRemoteCommand(lMsgId, strCommand, -3);
        } else {
            PrepareForm->LotNumEdit->Text = LotID;
            lot.nInPcbCnt = 0;
            lot.nOutPcbCnt = 0;
            lot.nUph = 0;
            gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
            Ext.CimLogAdd("New lot has been set by host..");
        }
    }
    else if(sRCmd == "LOTSTART") {
        AnsiString LotID="", Strips="";
        for(int i=0; i<nParmCnt; i++) {
            if(sCpName[i] != "LOTID" && sCpName[i] != "STRIPS") {
                gem->DenyRemoteCommand(lMsgId, strCommand, -2);
                return;
            }
            if(sCpVal[i].Length() < 1) {
                gem->DenyRemoteCommand(lMsgId, strCommand, -2);
                return;
            }
            if(sCpName[i]=="LOTID") LotID = sCpVal[i];
            else if(sCpName[i]=="STRIPS") Strips = sCpVal[i];
        }
        gem->AcceptRemoteCommand(lMsgId, strCommand, 0);
        m_bLotEndTime = true;
        m_nLotStrip = StrToInt(Strips);
        Work.m_nOutStripCnt = 0;
        RefreshSVID();
        SendSVID();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemMsgRequested(TObject *Sender, long lMsgId) // 사용자 정의 메세지셋
{
    short nStream, nFunction, nReply;
    long lMsgLength;

    gem->GetMsgInfo(lMsgId, &nStream, &nFunction, &nReply, &lMsgLength);
    AnsiString sysByte = gem->GetSystemByte(lMsgId);

    if(nStream == 1 && nFunction == 1) {// Are you there request
        AnsiString MDLN = MODEL_TYPE;
        AnsiString SOFTREV = MainForm->VersionLbl->Caption;
        gem->CreateReplyMsg(lMsgId);
        gem->OpenListItem(lMsgId);
        gem->AddAsciiItem(lMsgId, WideString(MDLN), MDLN.Length());
        gem->AddAsciiItem(lMsgId, WideString(SOFTREV), SOFTREV.Length());
        gem->CloseListItem(lMsgId);
        gem->SendMsg(lMsgId);
    }
    else if(nStream == 1 && nFunction == 2) {// Are you there ack
        gem->CreateReplyMsg(lMsgId);
        gem->SendMsg(lMsgId);
    }
    else if(nStream == 1 && nFunction == 15) {// Request OFF-LINE
        short boolValue = (!OnlineBtn->Down?0x02:0x00);
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(lMsgId);
        if(OnlineBtn->Down) {
            OnlineBtn->Down = false;
            SendEvent(C_OFFLINE);
        }
    }
    else if(nStream == 1 && nFunction == 17) {// Request ON-LINE
        short boolValue = (OnlineBtn->Down?0x02:0x00);
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(replyMsgId);
        if(!OnlineBtn->Down) {
            OnlineBtn->Down = true;
            SendEvent(C_LOCAL);
        }
    }
    else if(nStream == 2 && nFunction == 33) {//Define Report
        short boolValue = 0x00;
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(replyMsgId);
    }
    else if(nStream == 2 && nFunction == 35) {//Link Event Report
        short boolValue = 0x00;
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(replyMsgId);
    }
    else if(nStream == 2 && nFunction == 37) {//Event report Enable/Disable
        short nCEED; long nCEID;
        gem->GetListItemOpen(lMsgId);
        gem->GetBinaryItem(lMsgId, &nCEED);
        bool bCEED = ((nCEED&0x80)==0x80?true:false);
            int nParmCnt = gem->GetListItemOpen(lMsgId);
            for(int i=0; i<MAX_CEID&&i<nParmCnt; i++) {
                if(nParmCnt == 0)
                    SECSGEM_isEnabledEventReport[i] = bCEED;
                else gem->GetU2Item(lMsgId, &nCEID);
                SECSGEM_isEnabledEventReport[nCEID-START_CEID] = bCEED;
            }
            gem->GetListItemClose(lMsgId);
        gem->GetListItemClose(lMsgId);

        short boolValue = 0x00;
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(replyMsgId);
    }
	else if(nStream == 2 && nFunction == 41) {//Host Command Send
        return;
	}
    else if(nStream == 5 && nFunction == 3) {// Enable/Disable Alarm Send
        short nALED; long nALID;
        gem->GetListItemOpen(lMsgId);
        gem->GetBinaryItem(lMsgId, &nALED);
        gem->GetU2Item(lMsgId, &nALID);
        bool bALED = ((nALED&0x80)==0x80?true:false);
        if(nALID == 0) {
            for(int i=0; i<Ext.m_pLngList[STR_ALID]->Count; i++)
                SECSGEM_isEnabledAlarmReport[i] = bALED;
        }
        else SECSGEM_isEnabledAlarmReport[nALID] = bALED;
        gem->GetListItemClose(lMsgId);
        //reply
        short boolValue = 0x00;
        long replyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->AddBinaryItem(replyMsgId, &boolValue, 1);
        gem->SendMsg(replyMsgId);
    }
    /*
    else if(MsgID=="S5F5") {// List Alarm Data
        SendAlarmList (RcvMsg, false);
    }
    else if(MsgID=="S5F7") {// List Enable Alarm Data
        SendAlarmList (RcvMsg, true);
    }
    else if(MsgID=="S6F12") {// Event Report Ack
        // (No need response)
    }
    else if(MsgID=="S6F23") {// Request spool data send
        // For Future Coding
    }*/
// -----------------------------------------------------------------------------
// Process Program Load Inquire  (Program download enable ask)
// -----------------------------------------------------------------------------
    else if(nStream == 7 && nFunction == 1) {//Process Program Load Inquire (PPI)
        double downLen;
        gem->GetListItemOpen(lMsgId);
        AnsiString downName = gem->GetAsciiItemString(lMsgId);
        gem->GetU4Item(lMsgId, &downLen);
        gem->GetListItemClose(lMsgId);

        downName = MODEL_FILE_PATH+downName+".wrk";

        if(nReply) {
            //정상적으로 로드 했다면
            short boolValue = 0x00;
            if(Work.m_nStatus != RSTOP)   boolValue = 0x04;
            else if(FileExists(downName)) boolValue = 0x01;

            long replyMsgId = gem->CreateReplyMsg(lMsgId);
            gem->AddBinaryItem(replyMsgId, &boolValue, 1);
            gem->SendMsg(replyMsgId);
        }
    }
    else if(nStream == 7 && nFunction == 3) {//Process Program Load Send (PPS)
        short boolValue = 0x00;
        gem->GetListItemOpen(lMsgId);
        AnsiString sFileName = gem->GetAsciiItemString(lMsgId);
        if(sFileName == "")
            boolValue = 0x04;
        else {
            sFileName = MODEL_FILE_PATH+sFileName+".wrk";
            gem->GetFileBinaryItem(lMsgId, WideString(sFileName));
        }
        gem->GetListItemClose(lMsgId);

        if(!FileExists(sFileName)) {
            boolValue = 0x07;
            AddLog("S7F3, recipe file copy fail.");
        } else {
            AddLog("S7F3, recipe file copy success.");
        }

        if(boolValue != 0x00) {// 문제 발생시
            long lReplyMsgId = gem->CreateReplyMsg(lMsgId);
            gem->AddBinaryItem(lReplyMsgId, &boolValue, 1);
            gem->SendMsg(lReplyMsgId);
        }
    }
    else if(nStream == 7 && nFunction == 5) {//Process Program Request (PPR)
        gem->GetListItemOpen(lMsgId);
        AnsiString sPPID = gem->GetAsciiItemString(lMsgId);
        gem->GetListItemClose(lMsgId);

        WideString wPPID = sPPID;
        long lReplyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->OpenListItem(lReplyMsgId);
        gem->AddAsciiItem(lReplyMsgId, wPPID, wPPID.Length());
        gem->AddFileBinaryItem(lReplyMsgId, WideString(MODEL_FILE_PATH+sPPID+".wrk"));
        gem->CloseListItem(lReplyMsgId);
        gem->SendMsg(lReplyMsgId);
    }
    else if(nStream == 7 && nFunction == 17) {//Delete Process Program Send (DPS)
        int nParmCnt = gem->GetListItemOpen(lMsgId);
        short boolValue = 0x00;
        if(nParmCnt == 0) {//delete all
            Ext.DeleteAllFile(MODEL_FILE_PATH);
        } else {
            for(int i=0; i<nParmCnt; i++) {
                AnsiString sPPID = gem->GetAsciiItemString(lMsgId);
                Ext.DeleteAllFile(MODEL_FILE_PATH, sPPID+".wrk");
                //DeleteFile(MODEL_FILE_PATH+sPPID+".wrk");
                if(!FileExists(MODEL_FILE_PATH+sPPID+".wrk"))
                    boolValue = 0x04;
            }
        }
        gem->GetListItemClose(lMsgId);

        if(nReply) {
            long replyMsgId = gem->CreateReplyMsg(lMsgId);
            gem->AddBinaryItem(replyMsgId, &boolValue, 1);
            gem->SendMsg(replyMsgId);
        }
    }
    else if(nStream == 7 && nFunction == 19) {//Current EPPD Request
        TStringList *pFileList = new TStringList;
        Ext.GetDirFile(pFileList, MODEL_FILE_PATH);

        long lReplyMsgId = gem->CreateReplyMsg(lMsgId);
        gem->OpenListItem(lReplyMsgId);
        for(int i=0; i<pFileList->Count; i++)
            gem->AddAsciiItem(lReplyMsgId, WideString(pFileList->Strings[i]), pFileList->Strings[i].Length());
        gem->CloseListItem(lReplyMsgId);
        gem->SendMsg(lReplyMsgId);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemNewEquipConst(TObject *Sender, long lMsgId, short nCount) // set ECID to machine
{
try {
    for (int i=0;i<nCount;i++)
    {
        int nECID = gem->GetNewEquipConst(lMsgId, i);
        AnsiString strTmp = gem->GetNewEquipConstValue(lMsgId, i);
        switch (nECID)
        {
            case CONNECTION_MODE:
                gem->PassiveMode = strTmp.ToIntDef(0);
                break;
            case PORT_NUMBER:
                gem->Port = strTmp.ToIntDef(7000);
                break;
            case REMOTE_IP_ADDRESS:
                gem->IP = strTmp;
                break;
            case T3:
                gem->T3 = strTmp.ToIntDef(30);
                break;
            case T5:
                gem->T5 = strTmp.ToIntDef(5);
                break;
            case T6:
                gem->T6 = strTmp.ToIntDef(10);
                break;
            case T7:
                gem->T7 = strTmp.ToIntDef(5);
                break;
            case T8:
                gem->T8 = strTmp.ToIntDef(6);
                break;
            case LINK_TEST_INTERVAL:
                gem->LinkTestInterval = strTmp.ToIntDef(30);
                break;
            case RETRY_LIMIT:
                gem->Retry = strTmp.ToIntDef(3);
                break;
            case DEVICE_ID:
                gem->DeviceID = strTmp.ToIntDef(0);
                break;
        }
        gem->SetEquipConstValue(nECID, WideString(strTmp));
    }
    SetECID();

    gem->AcceptNewEquipConst(lMsgId);
} catch(...) {}
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::AlarmSet(int nALCD, int nALID)
{
    gem->SendAlarmReport(nALID, nALCD);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemProcessProgramLoadInquire(TObject *Sender,
      long lMsgId, BSTR strPPID, long lLength)
{
    ShowMessage(strPPID);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemProcessProgramRequested(TObject *Sender,
      BSTR PPID)
{
    ShowMessage(PPID);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemProcessProgramSending(TObject *Sender,
      BSTR PPID)
{
    ShowMessage(PPID);
}
//---------------------------------------------------------------------------
void __fastcall TSecsGemForm::gemFormattedPPReceived(TObject *Sender,
      BSTR PPID, short nCommCodeCount, short nParamCount)
{
    ShowMessage(PPID);
}
//---------------------------------------------------------------------------

