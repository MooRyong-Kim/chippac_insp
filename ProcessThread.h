//---------------------------------------------------------------------------
#ifndef ProcessThreadH
#define ProcessThreadH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
//---------------------------------------------------------------------------
class TProcessThread : public TThread
{
private:
protected:
	void __fastcall Execute();
    void __fastcall Update();
public:
	__fastcall TProcessThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
