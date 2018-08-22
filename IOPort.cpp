//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "IOPort.h"
#include "Extern.h"
#include "Msg.h"
#include "DataClass.h"
#include "Maint.h"
#include "Main.h"
#include "Comidas.h"
#include "MotionBase.h"
#include "WorkProcess.h"
#include "Debug.h"
#include "WorkSetup.h"
#include "SecsGem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TIOPort IO;
//---------------------------------------------------------------------------
__fastcall TIOPort::TIOPort()
{
    m_pEnumList[IO_IN] = new TStringList();
    m_pEnumList[IO_OUT] = new TStringList();
}
//---------------------------------------------------------------------------
__fastcall TIOPort::~TIOPort()
{
    FreeIOBoard();

    delete m_pEnumList[IO_IN];
    delete m_pEnumList[IO_OUT];
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::GetHdl(int nPort, HANDLE *hBd, int *nCh)
{
    if(sys.fac.bNoMachine) return false;
    if(m_hBd[nPort/48] == NULL) return false;
    *hBd = m_hBd[nPort/48];
    *nCh = nPort%48;
    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::InitIOBoard()
{
    m_hBd[0] = m_hBd[1] = NULL;
    if(sys.fac.bNoMachine) return false;

    if(!COMI_LoadDll()) {
        Application->MessageBox("Can't I/O DLL load failure.", "Error", MB_OK);
        m_hBd[0] = m_hBd[1] = NULL;
        return false;
    }

    m_hBd[0] = COMI_LoadDevice(COMI_SD414, 0);
    if(m_hBd[0] == INVALID_HANDLE_VALUE) {
        Application->MessageBox("Can't load I/O control device#1.", "Error", MB_OK);
        m_hBd[0] = NULL;
        return false;
    }

    if(sys.fac.nEquipType == VTYPE_2RAIL || sys.fac.bNoUseFnIo) {
        m_hBd[1] = COMI_LoadDevice(COMI_SD414, 1);
        if(m_hBd[1] == INVALID_HANDLE_VALUE) {
            Application->MessageBox("Can't load I/O control device#2.", "Error", MB_OK);
            m_hBd[1] = NULL;
            return false;
        }
    }

    On(SRVPWR);
    On(SRVENA);
    On(MAINAIR);
    IO.On(INSPPCBSENSON);
    Off(FIMSMMRDYTOPRE);
    Off(FIMSMMRDYTOPOST);
    Off(RIMSMMRDYTOPRE);
    Off(RIMSMMRDYTOPOST);

    if(sys.fac.nEquipType == HTYPE_1RAIL && !sys.fac.bNoUseFnIo)
        FnIoOpenDevice();

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::DisplayFnIoErr()
{
	FNIO_VALUE err_code, size = 256;
    AnsiString sErr;
	LibGetLastError(&err_code, sErr.c_str(), &size);
	sErr.printf("Error code : 0x%X\n%s", err_code, sErr.c_str());
    Application->MessageBox(sErr.c_str(), "Network I/O Error", MB_OK);
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::FnIoOpenDevice()
{
    m_hFnIoSys = m_hFnIoDev = NULL;

	//Crevis IO Init
	FNIO_VALUE err = LibInitSystem(&m_hFnIoSys);
   	if(err != FNIO_ERROR_SUCCESS) {
        DisplayFnIoErr();
        return false;
    }

	try {
		DEVICEINFOMODBUSTCP2	Devinfo;
		// Set the ip address of to open device.
		// This example is assumed that ip address is 192.168.0.201.
  		Devinfo.IpAddress[0] = 10;	Devinfo.IpAddress[1] = 10;
    	Devinfo.IpAddress[2] = 0;   Devinfo.IpAddress[3] = 161;

		// Open device
		if(DevOpenDevice(m_hFnIoSys, (FNIO_POINTER)&Devinfo, MODBUS_TCP, &m_hFnIoDev) != FNIO_ERROR_SUCCESS)
            throw err;
	}
	catch(...)
	{
        DisplayFnIoErr();
		LibFreeSystem(m_hFnIoSys);
		return false;
    }

	if(m_hFnIoDev == NULL)
	{
		LibFreeSystem(m_hFnIoSys);
		return false;
	}

	// Set the IO data update frequency to maximum speed.
	FNIO_VALUE	val, size;
	val = 10;	//0 ms
	size = sizeof(val);
	DevSetParam(m_hFnIoDev, DEV_UPDATE_FREQUENCY, &val, &size);
	// Set the response timeout to 1 second.
	val = 1000;	//0 ms
	size = sizeof(val);
	DevSetParam(m_hFnIoDev, DEV_RESPONSE_TIMEOUT, &val, &size);

    DevIoUpdateStart(m_hFnIoDev);

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::FreeIOBoard()
{
    if(!sys.fac.bDebugMode) {
        Off(SRVPWR);
        Off(SRVENA);
    }

    if(!In(finspblkvac) || In(fcvyinspdct)) {
        IO.Off(CLAMPON);
        IO.Off(FINSPBLKVAC);
        Sleep(500);
        IO.Off(FINSPBLKUP);
    }
    if(sys.fac.nEquipType == VTYPE_2RAIL) {
        IO.Off(RINSPBLKVAC);
        Sleep(300);
        IO.Off(RINSPBLKUP);
    }

    try {
        if(m_hBd[0] != NULL) COMI_UnloadDevice(m_hBd[0]);
        if(m_hBd[1] != NULL) COMI_UnloadDevice(m_hBd[1]);

        COMI_UnloadDll();

        //Lan Io
        if(sys.fac.nEquipType == HTYPE_1RAIL && sys.fac.bNoUseFnIo) {
            if(m_hFnIoDev != NULL) {
                DevIoUpdateStop(m_hFnIoDev);
	            DevCloseDevice(m_hFnIoDev);
            }
            if(m_hFnIoSys != NULL)
            	LibFreeSystem(m_hFnIoSys);
        }
    } catch(...) {}
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::ReadAndDecodeFromIOFile()
{
    TStringList *pList = new TStringList();

    AnsiString sIoFileName =  ExtractFilePath(Application->ExeName);
    sIoFileName+=(sys.fac.nEquipType==HTYPE_1RAIL?"ZeusInspS_IO.tio":"ZeusInspD_IO.tio");
    pList->LoadFromFile(sIoFileName);

    m_pEnumList[IO_IN]->Clear();
    m_pEnumList[IO_OUT]->Clear();
    int nInCnt = 0;
    int nOutCnt = 0;
    for(int i=0; i<pList->Count; i++) {
        if(pList->Strings[i].AnsiPos("//")) continue;
        if(pList->Strings[i].AnsiPos("INPUT")) {
        	sscanf(pList->Strings[i].c_str() , "%s  %d  %d  %c  %d  %s",
                &io_Fmt[IO_IN][nInCnt].chIO, &io_Fmt[IO_IN][nInCnt].nPort, &io_Fmt[IO_IN][nInCnt].nGroup,
                &io_Fmt[IO_IN][io_Fmt[IO_IN][nInCnt].nPort].chLevel,
                &io_Fmt[IO_IN][nInCnt].nAddress, &io_Fmt[IO_IN][nInCnt].chEnum);
            m_pEnumList[IO_IN]->Add(io_Fmt[IO_IN][nInCnt].chEnum);
            EnumMap[IO_IN][m_pEnumList[IO_IN]->Strings[nInCnt]] = io_Fmt[IO_IN][nInCnt].nPort;//nInCnt;
            int nIdx = pList->Strings[i].LastDelimiter("@");
            if(nIdx > 0) {
                AnsiString sName = pList->Strings[i].SubString(nIdx+1, pList->Strings[i].Length());
                strcpy(io_Fmt[IO_IN][nInCnt].chName, sName.c_str());
            }
            NameMap[IO_IN][AnsiString(io_Fmt[IO_IN][nInCnt].chName)] = io_Fmt[IO_IN][nInCnt].nPort;//nInCnt;
            nInCnt++;
        }
        else if(pList->Strings[i].AnsiPos("OUTPUT")) {
        	sscanf(pList->Strings[i].c_str() , "%s  %d  %d  %c  %d  %s",
                &io_Fmt[IO_OUT][nOutCnt].chIO, &io_Fmt[IO_OUT][nOutCnt].nPort, &io_Fmt[IO_OUT][nOutCnt].nGroup,
                &io_Fmt[IO_OUT][io_Fmt[IO_OUT][nOutCnt].nPort].chLevel,
                &io_Fmt[IO_OUT][nOutCnt].nAddress, &io_Fmt[IO_OUT][nOutCnt].chEnum);
            m_pEnumList[IO_OUT]->Add(AnsiString(io_Fmt[IO_OUT][nOutCnt].chEnum));
            EnumMap[IO_OUT][m_pEnumList[IO_OUT]->Strings[nOutCnt]] = io_Fmt[IO_OUT][nOutCnt].nPort;//nOutCnt;
            int nIdx = pList->Strings[i].LastDelimiter("@");
            if(nIdx > 0) {
                AnsiString sName = pList->Strings[i].SubString(nIdx+1, pList->Strings[i].Length());
                strcpy(io_Fmt[IO_OUT][nOutCnt].chName, sName.c_str());
            }
            NameMap[IO_OUT][AnsiString(io_Fmt[IO_OUT][nOutCnt].chName)] = io_Fmt[IO_OUT][nOutCnt].nPort;//nOutCnt;
            nOutCnt++;
        }
    }

    delete pList;
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::In(int nPort)
{
/*
    if(sys.fac.bNoMachine) {
        if(nPort == EnumMap[IO_IN][roll1zonedct])
            return DebugForm->Roll1DctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][roll2zonedct])
            return DebugForm->Roll2DctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][roll3zonedct])
            return DebugForm->Roll3DctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][inspzonedct])
            return DebugForm->InspZoneDctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][ulgripmgzgood] || nPort == EnumMap[IO_IN][ulmgzgripon])
            return DebugForm->MgzGripGoodChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][ulstprdct])
            return DebugForm->UlCvyStprDctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][rejstprdct])
            return DebugForm->RejCvyStprDctChkBox->Checked;
        else if(nPort == EnumMap[IO_IN][inspcomp])
            return DebugForm->InspRdyOkChkBox->Checked;
        return true;
    }*/
    if(sys.fac.bNoUseUnloader && nPort == EnumMap[IO_IN][ulemgsw])
        return false;

    if(sys.fac.nEquipType == HTYPE_1RAIL && !sys.fac.bNoUseFnIo && nPort >= FN_IO)
        return FnIn(nPort);

    HANDLE hBd; int nCh;
    if(!GetHdl(nPort, &hBd, &nCh)) return false;

    bool bIn = COMI_DI_GetOne(hBd, nCh);
    return (io_Fmt[IO_IN][nPort].chLevel=='A'?bIn:!bIn);
}
bool __fastcall TIOPort::In(AnsiString sPort, bool bName)
{
    if(!bName && m_pEnumList[IO_IN]->IndexOf(sPort) == -1)
        return false;

    if(sys.fac.bNoUseRearRail) {
        //if(sPort == rulpushbwd || sPort == rulpushup)
        //    return true;
        if(sPort.AnsiPos("rcvy") || sPort.AnsiPos("rul"))
            return false;
    }

    int nPort = (bName?NameMap[IO_IN][sPort]:EnumMap[IO_IN][sPort]);
    return In(nPort);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::SetBit(int nPort)
{
    if(sys.fac.nEquipType == HTYPE_1RAIL && !sys.fac.bNoUseFnIo && nPort >= FN_IO) {
        FnSetBit(nPort);
        return;
    }

    HANDLE hBd; int nCh;
    if(!GetHdl(nPort, &hBd, &nCh)) return;

    COMI_DO_PutOne(hBd, nCh, io_Fmt[IO_OUT][nPort].chLevel=='A'?1:0);
}
void __fastcall TIOPort::SetBit(AnsiString sPort, bool bName)
{
    int nPort = (bName?NameMap[IO_OUT][sPort]:EnumMap[IO_OUT][sPort]);
    SetBit(nPort);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::ResetBit(int nPort)
{
    if(sys.fac.nEquipType == HTYPE_1RAIL && !sys.fac.bNoUseFnIo && nPort >= FN_IO)
        return FnResetBit(nPort);

    HANDLE hBd; int nCh;
    if(!GetHdl(nPort, &hBd, &nCh)) return;

    COMI_DO_PutOne(hBd, nCh, io_Fmt[IO_OUT][nPort].chLevel=='A'?0:1);
}
void __fastcall TIOPort::ResetBit(AnsiString sPort, bool bName)
{
    int nPort = (bName?NameMap[IO_OUT][sPort]:EnumMap[IO_OUT][sPort]);
    ResetBit(nPort);
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::GetOut(int nPort)
{
    if(sys.fac.nEquipType == HTYPE_1RAIL && !sys.fac.bNoUseFnIo && nPort >= FN_IO)
        return FnGetOut(nPort);

    HANDLE hBd; int nCh;
    if(!GetHdl(nPort, &hBd, &nCh)) return false;

    bool bOut = COMI_DO_GetOne(hBd, nCh);
    return (io_Fmt[IO_OUT][nPort].chLevel=='A'?bOut:!bOut);
}
bool __fastcall TIOPort::GetOut(AnsiString sPort, bool bName)
{
    int nPort = (bName?NameMap[IO_OUT][sPort]:EnumMap[IO_OUT][sPort]);
    return GetOut(nPort);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::On(AnsiString sPort, bool bName)
{
    if(sPort.IsEmpty()) return;

    if(bName)
        sPort = m_pEnumList[IO_OUT]->Strings[NameMap[IO_OUT][sPort]];

    if(sPort == FINSPBLKVAC)
        ResetBit(FINSPBLKBLOW);
    else if(sPort == FINSPCVYFWD) {
        ResetBit(FINSPCVYDIR);
        SetBit(FINSPCVYRUN);
        return;
    }
    else if(sPort == FINSPCVYBWD || sPort == FINSPCVYDIR) {
        SetBit(FINSPCVYDIR);
        SetBit(FINSPCVYRUN);
        return;
    }
    else if(sPort == RINSPBLKVAC)
        ResetBit(RINSPBLKBLOW);
    else if(sPort == RINSPCVYFWD) {
        ResetBit(RINSPCVYDIR);
        SetBit(RINSPCVYRUN);
        return;
    }
    else if(sPort == RINSPCVYBWD || sPort == RINSPCVYDIR) {
        SetBit(RINSPCVYDIR);
        SetBit(RINSPCVYRUN);
        return;
    }

    else if(sPort == UVCVYFWD) {
        ResetBit(UVCVYDIR);
        SetBit(UVCVYRUN);
        return;
    }
    else if(sPort == UVCVYBWD || sPort == UVCVYDIR) {
        SetBit(UVCVYDIR);
        SetBit(UVCVYRUN);
        return;
    }
    else if(sPort == ULLDCVYFWD) {
        ResetBit(ULLDCVYDIR);
        SetBit(ULLDCVYRUN);
        return;
    }
    else if(sPort == ULLDCVYBWD || sPort == ULLDCVYDIR) {
        SetBit(ULLDCVYDIR);
        SetBit(ULLDCVYRUN);
        return;
    }
    else if(sPort == ULUDCVYFWD) {      //2017.02.21 sjh 11:00:08
        ResetBit(ULUDCVYDIR);
        SetBit(ULUDCVYRUN);
        return;
    }
    else if(sPort == ULUDCVYBWD || sPort == ULUDCVYDIR) {
        SetBit(ULUDCVYDIR);
        SetBit(ULUDCVYRUN);
        return;
    }
    else if(sPort == ULMGZGRIP) {
        SetBit(ULMGZGRIP);
        ResetBit(ULMGZGRIPOFF);
        return;
    }
    else if(sPort == FINSPBLKUP) {
        if(sys.eng.bUseClamp)
            IO.Off(CLAMPON);
    }

    if(m_pEnumList[IO_OUT]->IndexOf(sPort) == -1)
        return;

    SetBit(sPort);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::Off(AnsiString sPort, bool bName)
{
    if(bName)
        sPort = m_pEnumList[IO_OUT]->Strings[NameMap[IO_OUT][sPort]];

    if(sPort == FINSPCVYFWD || sPort == FINSPCVYBWD || sPort == FINSPCVYDIR) {
        ResetBit(FINSPCVYDIR);
        ResetBit(FINSPCVYRUN);
        return;
    }
    else if(sPort == RINSPCVYFWD || sPort == RINSPCVYBWD || sPort == RINSPCVYDIR) {
        ResetBit(RINSPCVYDIR);
        ResetBit(RINSPCVYRUN);
        return;
    }
    else if(sPort == UVCVYFWD || sPort == UVCVYBWD || sPort == UVCVYDIR) {
        ResetBit(UVCVYDIR);
        ResetBit(UVCVYRUN);
        return;
    }
    else if(sPort == ULLDCVYFWD || sPort == ULLDCVYBWD || sPort == ULLDCVYDIR) {
        ResetBit(ULLDCVYDIR);
        ResetBit(ULLDCVYRUN);
        return;
    }
    else if(sPort == ULUDCVYFWD || sPort == ULUDCVYBWD || sPort == ULUDCVYDIR) {    //2017.02.21 sjh 18:47:54
        ResetBit(ULUDCVYDIR);
        ResetBit(ULUDCVYRUN);
        return;
    }
    else if(sPort == ULMGZGRIP) {
        ResetBit(ULMGZGRIP);
        SetBit(ULMGZGRIPOFF);
        return;
    }
    else if(sPort == FINSPBLKUP) {
        if(sys.eng.bUseClamp)
            IO.Off(CLAMPON);
    }

    if(m_pEnumList[IO_OUT]->IndexOf(sPort) == -1)
        return;

    ResetBit(sPort);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::TowerLampProcess()
{
    if(MaintForm->Visible)
        return;

    int nNum = m_nCrntTwrSetNum;

    if(sys.eng.twr[nNum].nGrnLight == FLASH &&
        Ext.CheckDelay(TwrClk.tGrnFlash, sys.eng.twr[nNum].nGrnFlashIntvl)) {
        if(GetOut(TWRGRN))
            Off(TWRGRN);
        else On(TWRGRN);
        TwrClk.tGrnFlash = clock();
    }

    if(sys.eng.twr[nNum].nYlwLight == FLASH &&
        Ext.CheckDelay(TwrClk.tYlwFlash, sys.eng.twr[nNum].nYlwFlashIntvl)) {
        if(GetOut(TWRYLW))
            Off(TWRYLW);
        else On(TWRYLW);
        TwrClk.tYlwFlash = clock();
    }

    if(sys.eng.twr[nNum].nRedLight == FLASH &&
        Ext.CheckDelay(TwrClk.tRedFlash, sys.eng.twr[nNum].nRedFlashIntvl)) {
        if(GetOut(TWRRED))
            Off(TWRRED);
        else On(TWRRED);
        TwrClk.tRedFlash = clock();
    }

    static bool bBuzz;
    if(sys.eng.twr[nNum].bUseBuzz) {
        if(sys.eng.twr[nNum].bBuzzAutoOff) {
            if(Ext.CheckDelay(TwrClk.tBuzzOn, sys.eng.twr[nNum].nBuzzOnTime*1000))
                Off(BUZZ);
            else {
                if(Ext.CheckDelay(TwrClk.tBuzzTick, bBuzz?500:15)) {
                    if(!bBuzz) {
                        Off(BUZZ);
                        TwrClk.tBuzzTick = clock();
                        bBuzz = true;
                    } else {
                        On(BUZZ);
                        TwrClk.tBuzzTick = clock();
                        bBuzz = false;
                    }
                }
            }
        } else {
            if(MsgDlg->Visible) {
                if(Ext.CheckDelay(TwrClk.tBuzzTick, bBuzz?500:15)) {
                    if(!bBuzz) {
                        Off(BUZZ);
                        TwrClk.tBuzzTick = clock();
                        bBuzz = true;
                    } else {
                        On(BUZZ);
                        TwrClk.tBuzzTick = clock();
                        bBuzz = false;
                    }
                }
            }
            else Off(BUZZ);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::SetTowerLamp(int nNum, bool bSecsGem)
{
    switch(sys.eng.twr[nNum].nGrnLight) {
    case OFF:   Off(TWRGRN); break;
    case ON:    On(TWRGRN);
    case FLASH: TwrClk.tGrnFlash = clock();
    }

    switch(sys.eng.twr[nNum].nYlwLight) {
    case OFF:   Off(TWRYLW); break;
    case ON:    On(TWRYLW);
    case FLASH: TwrClk.tYlwFlash = clock();
    }

    switch(sys.eng.twr[nNum].nRedLight) {
    case OFF:   Off(TWRRED); break;
    case ON:    On(TWRRED);
    case FLASH: TwrClk.tRedFlash = clock();
    }

    if(sys.eng.twr[nNum].bUseBuzz) {
        On(BUZZ);
        if(sys.eng.twr[nNum].bBuzzAutoOff)
            TwrClk.tBuzzOn = clock();
    }
    else Off(BUZZ);

    m_nCrntTwrSetNum = nNum;

    //if(bSecsGem)
        //SecsGemForm->SendCEID(C_PROCESS_STATE_CHG);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::FnSetBit(int nPort)
{
    if(sys.fac.nEquipType != HTYPE_1RAIL || sys.fac.bNoUseFnIo)
        return;

    nPort-=FN_IO;

    DevWriteOutputImageBit(m_hFnIoDev, nPort/8, nPort%8,
        io_Fmt[IO_OUT][FN_IO+nPort].chLevel=='A'?true:false);
}
//---------------------------------------------------------------------------
void __fastcall TIOPort::FnResetBit(int nPort)
{
    if(sys.fac.nEquipType != HTYPE_1RAIL || sys.fac.bNoUseFnIo)
        return;

    nPort-=FN_IO;

    DevWriteOutputImageBit(m_hFnIoDev, nPort/8, nPort%8,
        io_Fmt[IO_OUT][FN_IO+nPort].chLevel=='A'?false:true);
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::FnGetOut(int nPort)
{
    if(sys.fac.nEquipType != HTYPE_1RAIL || sys.fac.bNoUseFnIo)
        return false;

    nPort-=FN_IO;

   	FNIO_VALUE	bitData;

    DevReadOutputImageBit(m_hFnIoDev, nPort/8, nPort%8, &bitData);

    return (io_Fmt[IO_OUT][FN_IO+nPort].chLevel=='A'?bitData:!bitData);;
}
//---------------------------------------------------------------------------
bool __fastcall TIOPort::FnIn(int nPort)
{
    if(sys.fac.nEquipType != HTYPE_1RAIL || sys.fac.bNoUseFnIo)
        return false;

    nPort-=FN_IO;

    FNIO_VALUE	bitData;

    DevReadInputImageBit(m_hFnIoDev, nPort/8, nPort%8, &bitData);

    return (io_Fmt[IO_IN][FN_IO+nPort].chLevel=='A'?bitData:!bitData);
}
//---------------------------------------------------------------------------



