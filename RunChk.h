//---------------------------------------------------------------------------

#ifndef RunChkH
#define RunChkH
//---------------------------------------------------------------------------
#include <time.h>
#include "ConstDefine.h"
class TRunChk
{
private:
protected:
public:
    bool m_bMainErrEvent;
    int m_nAlarmPart;
    AnsiString m_sErrMsg;
    __fastcall TRunChk();
    __fastcall ~TRunChk();
    void __fastcall ViewAlarm(AnsiString sErrMsg, int nAlarmPart=-1, AnsiString sIo="");
    bool __fastcall IsSensorSafety(int nAxis = -1);
    void __fastcall AutoRunSafety();
    bool __fastcall IsAxisSafety(int nAxis, bool bJogMove = false);
    void __fastcall MachineBtnProcess();
    bool __fastcall ServoCheck(int nAxis);
    void __fastcall SetAlarm(AnsiString sErrMsg, bool bMsgBoxBlink=false, int nAlarmPart=-1);
};
extern TRunChk Chk;
#endif
