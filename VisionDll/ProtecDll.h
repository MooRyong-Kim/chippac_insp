#pragma once

#include "stdafx.h"  //Borland ������ �ּ�ó��

#define EXPORT_API extern "C" __declspec(dllimport)

//ShowMode
#define SHOWMODE_SETUP		1
#define SHOWMODE_RUN		2

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//���α׷� ����
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvInitialize(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom); 
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//���α׷� ����
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvCloseVisionMainDlg();
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision Window �̵�
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvMoveDlg(long nWndPoLeft, long nWndPoTop, long nWndPoRight, long nWndPoBottom);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Setup Mode/ Run Mode ��ȯ
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
//��˻� �ǽ� ��. 1. Reset, 2. _pvReInspection, 3. _pvSWTrigger, 2.3.���� �ݺ�.
//++++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvReInspection(int nCamIndex, int nDVIndex);
//++++++++++++++++++++++++++++++++++++++++++++++++++

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//���� �˻� ���� �� ������
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSignal_Reset(int nCamIndex);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision ���°� Rum Mode����Setup Mode ���� �˷���. Run ���� ���� ��ȯ
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API bool _pvRequestIsRunReady();
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Job Chagne�� Job ���ϸ��� �����ָ� Vision���� �ش� ƼĪ ���� �ε�
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API bool _pvJobChange(int nCamIndex, char *chJobName);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Insp Index �Ǵ� Insp Mode ����. 
//Run Mode�� �ش� �Լ� �ݵ�� ȣ�� �� Trigger ������ �˻� �ǽ� ��.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvInspChange(int nCamIndex, int nInspIndex, int nInspMode);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//��� ���¸� Vision�� �˷���
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvMachineState(bool bIsRun);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Motion Calibraition�� ����.
//Setupmode�� Teach Calibration Dlg�� ����, Calibration Teaching ��
//Run ��忡�� 
//Cam Index, X�� �̵��� �Ÿ�. Y�� �̵��� �Ÿ��� �ְ�, ���� �ش� �Լ��� ȣ�� �� 
//Motor�� Vision ȭ�� ���� ��->��� �̵��� �Ÿ���ŭ �̵��ϰ�, ��-�Ϸ� �̵��� �Ÿ���ŭ �̵� �Ѵ�.
//CalibrationDB Dlg�� ������ Ȯ���� ���� �����Ѵ�.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCalibration(int nCamIndex, double dRealDistanceX, double dRealDistanceY);
//////////////////////////////////////////////////////////////////////////

EXPORT_API void _pvSetMotionSetting(int nCamIndex, int nInspMode);
EXPORT_API void _pvSetMotionSettingOff(int nCamIndex, int nInspMode);

//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision���� Handler�� Data�� �ѱ�ų�, �̺�Ʈ �߻��� ���� �Լ�
//��� ���� ���� ���α׷��� ������.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallResult(int nCamIndex, int(*pResultCall)(char *chInspResult, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision���� Handler�� Data�� �ѱ�ų�, �̺�Ʈ �߻��� ���� �Լ�
//�ӵ��� ������ �ϱ� ���� ���� Vision Shot�� ���� �ǽ� �ϰ�, ��� ó���� ���߿� ó�� �� ��� Trigger�� ���� shot�� �Ϸ� �ߴ��� �˷���
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallGrabEnd(int nCamIndex, int(*pGrabEndCall)(LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Vision ȭ�鿡�� Live ���� �϶� Motion ��ư�� ������ ȭ���� Ŭ���ϸ� �ش� ��ġ�� Center�� �̵��Ѵ�.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallMotionMoving(int nCamIndex, void(*pMotionMovingCall)(double dXAxisValue, double dYAxisValue, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Light Controller ���� Motion Board �� DA�� Light ��� ������ ���� ���.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallLightOn(int nCamIndex, void(*pLightOnCall)(int nLightChannel, int nOn, LPVOID pParam), LPVOID pWnd);
EXPORT_API void _pvSetCallLightValue(int nCamIndex, void(*pLightValueCall)(int nLightChannel, int nValue, LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Rum Mode�� �Ѿ� �� ��� Vision���� Handler�� ���� JobName�� ��û�Ѵ�.
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSetCallRequestJobName(int nCamIndex, bool(*pRequestJobNameCall)(LPVOID pParam), LPVOID pWnd);
//////////////////////////////////////////////////////////////////////////
//[10/29/2014 LWB]+++++++++++++++++++++++++++++++
//Software Trigger
//+++++++++++++++++++++++++++++++++++++++++++++++++
EXPORT_API void _pvSWTrigger(int nCamIndex);
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//ƼĪ�Ϸ�� ƼĪ ������ �ִٴ� �����Ͽ�
//�˻縦 ���ؼ��� ������ ���� ������ ��ģ��.
//1. _pvShowMode(SHOWMODE_RUN);
//2. _pvInspChange(0, 0, 0);
//3. _pvSWTrigger(0);
//4. Call �Լ� _TestGrabEnd1()���� Event ������, Grab �Ϸ� �Ǿ��ٴ� ��ȣ�̹Ƿ�, ����_pvSWTrigger(0);�� ������.
//5. ��� ���� Call �Լ� TestResult1(char *chInspResult, LPVOID pParam)�Լ����� �޴´�.
//6. ��� Data�� ������ ����.
//		���;����;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;ShotIndex, Pos X, Pos Y;
//		���� ��ŭ ShotIndex, Pos X, Pos Y;������ �迭�� �̾�����.
//		��� ���� 
//		0: Good
//		1: NG
//		2: Error
//////////////////////////////////////////////////////////////////////////

