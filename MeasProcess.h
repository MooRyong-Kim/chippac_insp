//---------------------------------------------------------------------------

#ifndef MeasProcessH
#define MeasProcessH
//---------------------------------------------------------------------------
#include "ConstDefine.h"
class TMeasProcess
{
private:
    Coord __fastcall GetPosFromCharData(char *chData);
protected:
public:
    bool m_bDone;
    __fastcall TMeasProcess();
    __fastcall ~TMeasProcess();
    void __fastcall MainProcess();
    int m_nGetUnitHgtDataPNo;
    void __fastcall GetUnitHgtDataStart();
    void __fastcall GetUnitHgtDataProcess();
};
extern TMeasProcess Meas;
#endif












































