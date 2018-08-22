//---------------------------------------------------------------------------

#ifndef InitProcessH
#define InitProcessH
//---------------------------------------------------------------------------
#include "ConstDefine.h"
class TInitProcess
{
private:
protected:
public:
    int m_nHomePNo[AXES];
    bool m_bHomeDone[AXES];
    int m_nInitPNo;
    int m_nStatus;
    bool m_bDone;
    bool m_bAuto;
    __fastcall TInitProcess();
    __fastcall ~TInitProcess();
    void __fastcall HomeProcess(int nAxis);
    void __fastcall MainProcess();
    void __fastcall InitProcess();
    void __fastcall Start();
    void __fastcall Stop();
    void __fastcall AddInitMsg(AnsiString sMsg);
    void __fastcall IndivisualHomeStart(int nAxis);
};
extern TInitProcess Init;
#endif
