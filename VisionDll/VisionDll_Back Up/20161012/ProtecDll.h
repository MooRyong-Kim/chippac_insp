#pragma once

#include "stdafx.h"  //Borland 에서는 주석처리

#define EXPORT_API extern "C" __declspec(dllimport)

//ShowMode
#define SHOWMODE_SETUP		1
#define SHOWMODE_RUN		2

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//프로그램 실행
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvInitialize(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom); 
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//프로그램 종료
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvCloseVisionMainDlg();
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision Window 이동
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvMoveDlg(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Setup Mode/ Run Mode 전환
//SHOWMODE_SETUP	
//SHOWMODE_RUN	
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API bool	_pvShowMode(long nShowMode);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision Window Hide
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API int	_pvAllWindowHide();
//////////////////////////////////////////////////////////////////////////

//[11/14/2014 LSH]++++++++++++++++++++++++++++++++++
//재검사 실시 시. 1. Reset, 2. _pvReInspection, 3. _pvSWTrigger, 2.3.번을 반복.
//++++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvReInspection(int nCamIndex, int nDVIndex);
//++++++++++++++++++++++++++++++++++++++++++++++++++

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//비전 검사 시작 전 날려줌
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSignal_Reset(int nCamIndex);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision 상태가 Rum Mode인지Setup Mode 인지 알려줌. Run 인지 상태 반환
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API bool _pvRequestIsRunReady();
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Job Chagne시 Job 파일명을 보내주면 Vision에서 해당 티칭 파일 로드
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API bool _pvJobChange(int nCamIndex, char *chJobName);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Insp Index 또는 Insp Mode 설정. 
//Run Mode시 해당 함수 반드시 호출 후 Trigger 보내야 검사 실시 함.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvInspChange(int nCamIndex, int nInspIndex, int nInspMode);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//장비 상태를 Vision에 알려줌
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvMachineState(bool bIsRun);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Motion Calibraition을 위함.
//Setupmode의 Teach Calibration Dlg를 열고, Calibration Teaching 후
//Run 모드에서 
//Cam Index, X축 이동할 거리. Y축 이동할 거리를 넣고, 먼저 해당 함수를 호출 후 
//Motor를 Vision 화면 상의 좌->우로 이동할 거리만큼 이동하고, 상-하로 이동할 거리만큼 이동 한다.
//CalibrationDB Dlg가 나오면 확인을 눌러 저장한다.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCalibration(int nCamIndex, double dRealDistanceX, double dRealDistanceY);
//////////////////////////////////////////////////////////////////////////

EXPORT_API void _pvSetMotionSetting(int nCamIndex, int nInspMode);
EXPORT_API void _pvSetMotionSettingOff(int nCamIndex, int nInspMode);

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision에서 Handler에 Data를 넘기거나, 이벤트 발생을 위한 함수
//결과 값을 메인 프로그램에 보낸다.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallResult(int nCamIndex, int(*pResultCall)(char *chInspResult, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision에서 Handler에 Data를 넘기거나, 이벤트 발생을 위한 함수
//속도를 빠르게 하기 위해 여러 Vision Shot을 먼저 실시 하고, 결과 처리를 나중에 처리 할 경우 Trigger에 의해 shot을 완료 했는지 알려줌
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallGrabEnd(int nCamIndex, int(*pGrabEndCall)(LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision 화면에서 Live 상태 일때 Motion 버튼을 누르고 화면을 클릭하면 해당 위치가 Center로 이동한다.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallMotionMoving(int nCamIndex, void(*pMotionMovingCall)(double dXAxisValue, double dYAxisValue, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Light Controller 없이 Motion Board 등 DA로 Light 밝기 조정할 때만 사용.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallLightOn(int nCamIndex, void(*pLightOnCall)(int nLightChannel, int nOn, LPVOID pParam), LPVOID pWnd);
EXPORT_API void _pvSetCallLightValue(int nCamIndex, void(*pLightValueCall)(int nLightChannel, int nValue, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Rum Mode로 넘어 갈 경우 Vision에서 Handler에 현재 JobName을 요청한다.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallRequestJobName(int nCamIndex, bool(*pRequestJobNameCall)(LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Software Trigger
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSWTrigger(int nCamIndex);
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//티칭완료된 티칭 파일이 있다는 가정하에
//검사를 위해서는 다음과 같은 과정을 거친다.
//1. _pvShowMode(SHOWMODE_RUN);
//2. _pvInspChange(0, 0, 0);
//3. _pvSWTrigger(0);
//4. Call 함수 _TestGrabEnd1()에서 Event 받으면, Grab 완료 되었다는 신호이므로, 다음_pvSWTrigger(0);를 날린다.
//5. 결과 값은 Call 함수 TestResult1(char *chInspResult, LPVOID pParam)함수에서 받는다.
//6. 결과 Data는 다음과 같다.
//		결과;갯수;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;
//		갯수 만큼 ShotIndex, Pos X, Pos Y;형식의 배열이 이어진다.
//		결과 값은 
//		0: Good
//		1: NG
//		2: Error
//////////////////////////////////////////////////////////////////////////

