//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MeasProcess.h"
#include "Jog.h"
#include <math.h>
#include <Math.hpp>
#include "MotionBase.h"
#include "Msg.h"
#include "RunChk.h"
#include "DataClass.h"
#include "SysSetup.h"
#include "WorkSetup.h"
#include "Extern.h"
#include "Main.h"
#include "IOPort.h"
#include "WorkProcess.h"
#include "FileCtrl.hpp"
#include "InitProcess.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TMeasProcess Meas;
//---------------------------------------------------------------------------
__fastcall TMeasProcess::TMeasProcess()
{
    m_bDone = true;
}
//---------------------------------------------------------------------------
__fastcall TMeasProcess::~TMeasProcess()
{
}
//---------------------------------------------------------------------------
void __fastcall TMeasProcess::MainProcess()
{
    m_bDone = true;

    GetUnitHgtDataProcess();
}
//---------------------------------------------------------------------------
void __fastcall TMeasProcess::GetUnitHgtDataStart()
{
}
//---------------------------------------------------------------------------
void __fastcall TMeasProcess::GetUnitHgtDataProcess()
{
}
//---------------------------------------------------------------------------
Coord __fastcall TMeasProcess::GetPosFromCharData(char *chData)
{
    AnsiString sPos;
    Coord dptMeasPos = {0., 0.};

    sPos = AnsiString(chData);
    if(sPos.IsEmpty())
        return dptMeasPos;

    sPos.Delete(1, 2);
    dptMeasPos.x = StrToFloat(sPos.SubString(1, sPos.AnsiPos(",")-1));
    sPos.Delete(1, sPos.AnsiPos(",")+3);
    dptMeasPos.y = StrToFloat(sPos.SubString(1, sPos.Length()));

    return dptMeasPos;
}
//---------------------------------------------------------------------------

