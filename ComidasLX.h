#ifndef __COMIDASLX_DLL_H_
#define __COMIDASLX_DLL_H_

#include "ComidasCommon.h"
#ifdef __cplusplus
extern "C"{
#endif

// Device ID definition // 
#define COMI_LX101	0xA101
#define COMI_LX102	0xA102
#define COMI_LX103	0xA103
#define COMI_LX201	0xA201
#define COMI_LX202	0xA202
#define COMI_LX203	0xA203
#define COMI_LX211	0xA211
#define COMI_LX212	0xA212
#define COMI_LX301	0xA301
#define COMI_LX401	0xA401
#define COMI_LX402	0xA402
#define COMI_LX501	0xA501
#define COMI_LX502	0xA502
#define COMI_LX504	0xA504
#define COMI_LX508	0xA508
#define COMI_LX534	0xA534
#define COMI_LX544	0xA544

#ifdef COMIDASLXDLL_EXPORTS
 #define COMIDAS_API __declspec(dllexport)
#else
 #ifdef _COMIDASLX_LOADER_C_
  #define EXTERN
 #else
  #define EXTERN extern
 #endif
 BOOL COMILX_LoadDll(void);
 void COMILX_UnloadDll(void);
 EXTERN HANDLE	(*COMILX_LoadDevice) (COMIDAS_DEVID deviceID, ULONG instance);
 EXTERN void	(*COMILX_UnloadDevice) (HANDLE hDevice);
 EXTERN void	(*COMILX_SetComiBus) (HANDLE hDevice, BOOL bEnable, BOOL bIsMaster);
 //___________ General A/D Functions _____________________________________________//
 EXTERN void	(*COMILX_AD_SetInputType) (HANDLE hDevice, int nInputMode);
 EXTERN BOOL	(*COMILX_AD_SetRange) (HANDLE hDevice, int ch, float vmin, float vmax);
 EXTERN int		(*COMILX_AD_GetDigit) (HANDLE hDevice, int ch);
 EXTERN float	(*COMILX_AD_GetVolt) (HANDLE hDevice, int ch);
 //___________ Unlimited A/D Scan for LX10x _____________________________________________//
 EXTERN long	(*COMILX_US1_Start) (HANDLE hDevice, int nNumChannel, int *pChanList,
			UINT dwScanFreq, UINT nBufSize, int nTrsMethod);
 EXTERN void	(*COMILX_US1_Stop) (HANDLE hDevice, BOOL bReleaseBuf);
 EXTERN long	(*COMILX_US1_ChangeScanFreq) (HANDLE hDevice, UINT dwScanFreq);
 EXTERN void	(*COMILX_US1_ResetCount) (HANDLE hDevice);
 EXTERN short*	(*COMILX_US1_GetBuffer) (HANDLE hDevice);
 EXTERN ULONG	(*COMILX_US1_CurCount) (HANDLE hDevice);
 EXTERN UINT	(*COMILX_US1_SBPos) (HANDLE hDevice, int chOrder, ULONG scanCount);
 EXTERN BOOL	(*COMILX_US1_ReleaseBuf) (HANDLE hDevice);
 EXTERN short	(*COMILX_US1_RetrvOne) (HANDLE hDevice, int chOrder, ULONG scanCount);
 EXTERN ULONG	(*COMILX_US1_RetrvChannel) (HANDLE hDevice, int chOrder, ULONG startCount, 
			int maxNumData, void *pDestBuf, TComiVarType VarType);
 EXTERN UINT	(*COMILX_US1_RetrvBlock) (HANDLE hDevice, UINT startCount, int maxNumScan, 
			void *pDestBuf, TComiVarType VarType);
 //___________ Unlimited A/D Scan for LX20x _____________________________________________//
 EXTERN void	(*COMILX_US2_SetTriggerEvent) (HANDLE hDevice, int nInputSource,
					int nEdgeType, int nTrgMode, float fAiRef, float fAiRefBand);
 EXTERN double	(*COMILX_US2_Start) (HANDLE hDevice, int nNumChannel, int *pChanList, UINT nScanFreq,
								   USHORT nBufSizeGain, BOOL bPauseAtBufFull);
 EXTERN void	(*COMILX_US2_Resume) (HANDLE hDevice);
 EXTERN double	(*COMILX_US2_ChangeScanFreq) (HANDLE hDevice, UINT dwScanFreq);
 EXTERN ULONG	(*COMILX_US2_DmaCount) (HANDLE hDevice);
 EXTERN BOOL	(*COMILX_US2_IsBufFull) (HANDLE hDevice);
 EXTERN short*	(*COMILX_US2_GetBuffer) (HANDLE hDevice, int chOrder);
 EXTERN ULONG	(*COMILX_US2_RetrvChannel) (HANDLE hDevice, int chOrder, ULONG startCount,
						int maxNumData, void *pDestBuf, TComiVarType VarType);
 EXTERN void	(*COMILX_US2_Stop) (HANDLE hDevice, BOOL bReleaseBuf);
 EXTERN BOOL	(*COMILX_US2_ReleaseBuf) (HANDLE hDevice);
 //___________ DIO Common __________________________________________________//
 EXTERN void	(*COMILX_DIO_SetUsage) (HANDLE hDevice, int usage);
 EXTERN int		(*COMILX_DIO_GetUsage) (HANDLE hDevice);
 //__________ D/I Functions ________________________________________________//
 EXTERN int		(*COMILX_DI_GetOne) (HANDLE hDevice, int ch);
 EXTERN DWORD	(*COMILX_DI_GetAll) (HANDLE hDevice);
 EXTERN DWORD	(*COMILX_DI_GetAllEx) (HANDLE hDevice, int nGroupIdx);
 //__________ D/O Functions ________________________________________________//
 EXTERN void	(*COMILX_DO_PutOne) (HANDLE hDevice, int ch, int status);
 EXTERN void	(*COMILX_DO_PutAll) (HANDLE hDevice, DWORD dwStatuses);
 EXTERN void	(*COMILX_DO_PutAllEx) (HANDLE hDevice, int nGroupIdx, DWORD dwStatuses);
 EXTERN DWORD	(*COMILX_DO_GetOne) (HANDLE hDevice, int ch);
 EXTERN DWORD	(*COMILX_DO_GetAll) (HANDLE hDevice);
 EXTERN DWORD	(*COMILX_DO_GetAllEx) (HANDLE hDevice, int nGroupIdx);
 //__________ Serial Digital Input/Output Functions ________________________//
 EXTERN BOOL	(*COMILX_SDIO_InitComm) (HANDLE hDevice);
 EXTERN BOOL	(*COMILX_SDIO_CheckModule) (HANDLE hDevice, int nModuleNo);
 EXTERN BOOL	(*COMILX_SDIO_SetDioUsage) (HANDLE hDevice, int nModuleNo, int nUsge);
 EXTERN BYTE	(*COMILX_SDIO_ReadLowByte) (HANDLE hDevice, int nModuleNo);
 EXTERN BYTE	(*COMILX_SDIO_ReadHighByte) (HANDLE hDevice, int nModuleNo);
 EXTERN USHORT	(*COMILX_SDIO_ReadWord) (HANDLE hDevice, int nModuleNo);
 EXTERN BOOL	(*COMILX_SDIO_WriteLowByte) (HANDLE hDevice, int nModuleNo, BYTE bValue);
 EXTERN BOOL	(*COMILX_SDIO_WriteHighByte) (HANDLE hDevice, int nModuleNo, BYTE bValue);
 EXTERN BOOL	(*COMILX_SDIO_WriteWord) (HANDLE hDevice, int nModuleNo, USHORT wWord);
 //__________ D/A Functions ________________________________________________//
 EXTERN BOOL	(*COMILX_DA_Out) (HANDLE hDevice, int ch, float volt);
 EXTERN long	(*COMILX_WFM_Start) (HANDLE hDevice, int ch, float *pDataBuffer, 
						UINT nNumData, UINT nPPS, int nMaxLoops);
 EXTERN BOOL	(*COMILX_WFM_Reload) (HANDLE hDevice, int ch, float *pDataBuffer, UINT nNumData);
 EXTERN long	(*COMILX_WFM_RateChange) (HANDLE hDevice, int ch, ULONG nPPS);
 EXTERN long	(*COMILX_WFM_GetCurPos) (HANDLE hDevice, int ch);
 EXTERN long	(*COMILX_WFM_GetCurLoops) (HANDLE hDevice, int ch);
 EXTERN void	(*COMILX_WFM_Stop) (HANDLE hDevice, int ch);

 //__________ Counter Functions ____________________________________________//
 EXTERN ULONG 	(*COMILX_ReadCounter32) (HANDLE hDevice, int ch);
 EXTERN void 	(*COMILX_ClearCounter32) (HANDLE hDevice, int ch);

 //__________ Motion/Control Functions ____________________________________________//
 // Initialize functions //
 EXTERN void (*COMILX_MC_Reset) (HANDLE hDevice);
 EXTERN void (*COMILX_MC_ServoOn) (HANDLE hDevice, int nChannel, BOOL bEnable);
 EXTERN int	 (*COMILX_MC_GetServoOn) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetBlockingMode) (HANDLE hDevice, BOOL bBlocking);
 EXTERN void (*COMILX_MC_SetWindowHandle) (HANDLE hDevice, ULONG hWnd);
 EXTERN void (*COMILX_MC_SetOutputMode) (HANDLE hDevice, int nChannel, int nOutputMode);
 EXTERN int	 (*COMILX_MC_GetOutputMode) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetInputMode) (HANDLE hDevice, int nChannel, int nInputMode, int nPulseLogic);
 EXTERN void (*COMILX_MC_GetInputMode) (HANDLE hDevice, int nChannel, int *pInputMode, int *pPulseLogic);
 EXTERN void (*COMILX_MC_SetSpeedRange) (HANDLE hDevice, int nChannel, double fMaxSpeed);
 EXTERN void (*COMILX_MC_GetSpeedRange) (HANDLE hDevice, int nChannel, double *fMinSpeed, double *fMaxSpeed);
 EXTERN void (*COMILX_MC_SetUnitDistance) (HANDLE hDevice, int nChannel, double fUnitDist);
 EXTERN double (*COMILX_MC_GetUnitDistance) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetUnitSpeed) (HANDLE hDevice, int nChannel, double fUnitSpeed);
 EXTERN double (*COMILX_MC_GetUnitSpeed) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetInOutRatio) (HANDLE hDevice, int nChannel, double fRatio);
 EXTERN void (*COMILX_MC_SetPosSrc) (HANDLE hDevice, int nChannel, int nSource);
 // Single Axis Motions //
 EXTERN void (*COMILX_MC_SetSpeedMode) (HANDLE hDevice, int nChannel, int nModeIndex);
 EXTERN void (*COMILX_MC_SetSpeed) (HANDLE hDevice, int nChannel, double fIniSpeed, double fWorkSpeed);
 EXTERN void (*COMILX_MC_SetAccel) (HANDLE hDevice, int nChannel, double fAccel, double fDecel);
 EXTERN void (*COMILX_MC_SetScurve) (HANDLE hDevice, int nChannel, double fSVacc, double fSVdec);
 EXTERN void (*COMILX_MC_StartVMove) (HANDLE hDevice, int nChannel, int nDirection);
 EXTERN void (*COMILX_MC_StartMove) (HANDLE hDevice, int nChannel, double fDistance);
 EXTERN void (*COMILX_MC_Move) (HANDLE hDevice, int nChannel, double fDistance);
 EXTERN void (*COMILX_MC_StartMoveTo) (HANDLE hDevice, int nChannel, double fPosition);
 EXTERN void (*COMILX_MC_MoveTo) (HANDLE hDevice, int nChannel, double fPosition);
 EXTERN void (*COMILX_MC_Stop) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_EmgStop) (HANDLE hDevice, int nChannel);
 EXTERN BOOL (*COMILX_MC_Done) (HANDLE hDevice, int nChannel);
 // Multi-Axes Motion //
 EXTERN void (*COMILX_MC_StartVMoveAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], int nDirList[]);
 EXTERN void (*COMILX_MC_StartMoveAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fDistList[]);
 EXTERN void (*COMILX_MC_MoveAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fDistList[]);
 EXTERN void (*COMILX_MC_StartMoveToAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fPosList[]);
 EXTERN void (*COMILX_MC_MoveToAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fPosList[]);
 EXTERN void (*COMILX_MC_StopAll) (HANDLE hDevice, int nNumAxis, int nAxisList[]);
 EXTERN void (*COMILX_MC_EmgStopAll) (HANDLE hDevice, int nNumAxis, int nAxisList[]);
 EXTERN BOOL (*COMILX_MC_AllDone) (HANDLE hDevice, int nNumAxis, int nAxisList[]);
 // Coordinated Motion //
 EXTERN BOOL (*COMILX_MC_MapAxes) (HANDLE hDevice, int nMapIndex, long bMapMask);
 EXTERN void (*COMILX_MC_SetSpeedModeMx) (HANDLE hDevice, int nMapIndex, int nModeIndex);
 EXTERN void (*COMILX_MC_SetSpeedMx) (HANDLE hDevice, int nMapIndex, double fSpeed, double fAccel);
 EXTERN void (*COMILX_MC_StartLine) (HANDLE hDevice, int nMapIndex, double fDistList[]);
 EXTERN void (*COMILX_MC_Line) (HANDLE hDevice, int nMapIndex, double fDistList[]);
 EXTERN void (*COMILX_MC_StartLineTo) (HANDLE hDevice, int nMapIndex, double fPosList[]);
 EXTERN void (*COMILX_MC_LineTo) (HANDLE hDevice, int nMapIndex, double fPosList[]);
 EXTERN void (*COMILX_MC_StartArc_a) (HANDLE hDevice, int nMapIndex, double fXCentOffset, double fYCentOffset, double fEndAngle);
 EXTERN void (*COMILX_MC_Arc_a) (HANDLE hDevice, int nMapIndex, double fXCentOffset, double fYCentOffset, double fEndAngle);
 EXTERN void (*COMILX_MC_StartArc_p) (HANDLE hDevice, int nMapIndex, double fXCentOffset, double fYCentOffset, double fXEndPointDist, double fYEndPointDist, int nDir);
 EXTERN void (*COMILX_MC_Arc_p) (HANDLE hDevice, int nMapIndex, double fXCentOffset, double fYCentOffset, double fXEndPointDist, double fYEndPointDist, int nDir);
 EXTERN void (*COMILX_MC_StartArcTo_a) (HANDLE hDevice, int nMapIndex, double fXCent, double fYCent, double fEndAngle);
 EXTERN void (*COMILX_MC_ArcTo_a) (HANDLE hDevice, int nMapIndex, double fXCent, double fYCent, double fEndAngle);
 EXTERN void (*COMILX_MC_StartArcTo_p) (HANDLE hDevice, int nMapIndex, double fXCent, double fYCent, double fXEndPos, double fYEndPos, int nDir);
 EXTERN void (*COMILX_MC_ArcTo_p) (HANDLE hDevice, int nMapIndex, double fXCent, double fYCent, double fXEndPos, double fYEndPos, int nDir);
 EXTERN void (*COMILX_MC_CompleteArc) (HANDLE hDevice, int nMapIndex);
 EXTERN BOOL (*COMILX_MC_MxDone) (HANDLE hDevice, int nMapIndex);
 // Spline Interpolation //
 EXTERN double* (*COMILX_MC_BuildSpline) (double fInPoints[], int nNumInPoints, int nNumOutPoints);
 EXTERN void (*COMILX_MC_DeleteSpline) (double *pSplineBuffer);
 // Helical Interpolation //
 EXTERN BOOL (*COMILX_MC_StartHelical) (HANDLE hDevice, THelicalUserInfo *pHelicalUserInfo);
 EXTERN BOOL (*COMILX_MC_AbortHelical) (HANDLE hDevice);

 // Overriding //
 EXTERN void (*COMILX_MC_OverrideSpeedSet) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_OverrideSpeedSetAll) (HANDLE hDevice, int nNumAxis, int nAxisList[]);
 EXTERN BOOL (*COMILX_MC_OverrideMove) (HANDLE hDevice, int nChannel, double fNewDistance);
 EXTERN BOOL (*COMILX_MC_OverrideMoveTo) (HANDLE hDevice, int nChannel, double fNewPosition);
 // Home Move //
 EXTERN void (*COMILX_MC_SetHomeConfig) (HANDLE hDevice, int nChannel, int nOrgMode, int nOrgLogic, int nEzCount, int nEzLogic, int nErcOut);
 EXTERN void (*COMILX_MC_HomeMove) (HANDLE hDevice, int nChannel, int nDirection, double fRvsVel);
 
 // External Switch Move //
 EXTERN void (*COMILX_MC_StartVMoveEx) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_StartMoveEx) (HANDLE hDevice, int nChannel, double fDistance);
 // Pulser Mode //
 EXTERN void (*COMILX_MC_SetPulserInputMode) (HANDLE hDevice, int nChannel, int nInputMode, BOOL bInverse);
 EXTERN void (*COMILX_MC_PulserHomeMove) (HANDLE hDevice, int nChannel, int nHomeType);
 EXTERN void (*COMILX_MC_StartPulserVMove) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_StartPulserMove) (HANDLE hDevice, int nChannel, double fDistance);
 EXTERN void (*COMILX_MC_PulserMove) (HANDLE hDevice, int nChannel, double fDistance);
 EXTERN void (*COMILX_MC_StartPulserMoveTo) (HANDLE hDevice, int nChannel, double fPosition);
 EXTERN void (*COMILX_MC_PulserMoveTo) (HANDLE hDevice, int nChannel, double fPosition);
 // List-Motion //
 EXTERN void (*COMILX_MC_SetListMotionAxes) (HANDLE hDevice, unsigned char bMapMask);
 EXTERN void (*COMILX_MC_BeginList) (HANDLE hDevice);
 EXTERN void (*COMILX_MC_EndList) (HANDLE hDevice);
 EXTERN void (*COMILX_MC_StartListMotion) (HANDLE hDevice);
 EXTERN void (*COMILX_MC_AbortListMotion) (HANDLE hDevice);
 EXTERN BOOL (*COMILX_MC_CheckListMotionDone) (HANDLE hDevice);
 // Reset //
 EXTERN void (*COMILX_MC_ResetAxis) (HANDLE hDevice, int nChannel);
 // Get/Set Status //
 EXTERN double (*COMILX_MC_GetCurSpeed) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_EnableActSpdChk) (HANDLE hDevice, long dwInterval);
 EXTERN void (*COMILX_MC_DisableActSpdChk) (HANDLE hDevice);
 EXTERN double (*COMILX_MC_GetActualSpeed) (HANDLE hDevice, int nChannel);
 EXTERN double (*COMILX_MC_GetPosition_A) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetPosition_A) (HANDLE hDevice, int nChannel, double fActualPos);
 EXTERN double (*COMILX_MC_GetPosition_C) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetPosition_C) (HANDLE hDevice, int nChannel, double fPosition);
 EXTERN long (*COMILX_MC_GetCount_A) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetCount_A) (HANDLE hDevice, int nChannel, long nCount);
 EXTERN long (*COMILX_MC_GetCount_C) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetCount_C) (HANDLE hDevice, int nChannel, long nCount);
 EXTERN long (*COMILX_MC_GetCount_D) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetCount_D) (HANDLE hDevice, int nChannel, long nCount);
 EXTERN long (*COMILX_MC_GetCount_G) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetCount_G) (HANDLE hDevice, int nChannel, long nCount);
 EXTERN long (*COMILX_MC_GetCount_R) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetCount_R) (HANDLE hDevice, int nChannel, long nCount);
 EXTERN long (*COMILX_MC_ReadLatchCounter) (HANDLE hDevice, int nChannel, int nCounter);
 EXTERN BOOL (*COMILX_MC_GetLatchState) (HANDLE hDevice, int nChannel);
 EXTERN int (*COMILX_MC_GetMotionStatus) (HANDLE hDevice, int nChannel);
 EXTERN int (*COMILX_MC_GetMioStatus) (HANDLE hDevice, int nChannel);
 // Set Config //
 EXTERN void (*COMILX_MC_SetFilterLogic) (HANDLE hDevice, int nChannel, BOOL bEnable);
 EXTERN void (*COMILX_MC_SetPE) (HANDLE hDevice, int nChannel, BOOL bEnable);
 EXTERN void (*COMILX_MC_SetELL) (HANDLE hDevice, int nChannel, int nLogic);
 EXTERN void (*COMILX_MC_SetMioCfgALM) (HANDLE hDevice, int nChannel, int nAlarmLogic, int nAlarmMode);
 EXTERN void (*COMILX_MC_GetMioCfgALM) (HANDLE hDevice, int nChannel, int *pAlarmLogic, int *pAlarmMode);
 EXTERN void (*COMILX_MC_SetMioCfgCLR) (HANDLE hDevice, int nChannel, int CntrSel, int nSignalType);
 EXTERN void (*COMILX_MC_GetMioCfgCLR) (HANDLE hDevice, int nChannel, int *pCntrSel, int *pnSignalType);
 EXTERN void (*COMILX_MC_SetMioCfgCMP) (HANDLE hDevice, int nChannel, ULONG nCmpPulseWidth, int nCmpLogic);
 EXTERN void (*COMILX_MC_GetMioCfgCMP) (HANDLE hDevice, int nChannel, ULONG *pnCmpPulseWidth, int *pnCmpLogic);
 EXTERN void (*COMILX_MC_SetMioCfgDR) (HANDLE hDevice, int nChannel, int nLogic);
 EXTERN void (*COMILX_MC_GetMioCfgDR) (HANDLE hDevice, int nChannel, int *pnLogic);
 EXTERN void (*COMILX_MC_SetMioCfgEL) (HANDLE hDevice, int nChannel, int nElMode);
 EXTERN void (*COMILX_MC_GetMioCfgEL) (HANDLE hDevice, int nChannel, int *pElMode);
 EXTERN void (*COMILX_MC_SetMioCfgERC) (HANDLE hDevice, int nChannel, int nErcLogic, int nErcOnTime);
 EXTERN void (*COMILX_MC_GetMioCfgERC) (HANDLE hDevice, int nChannel, int *pErcLogic, int *pErcOnTime);
 EXTERN void (*COMILX_MC_SetMioCfgLTC) (HANDLE hDevice, int nChannel, int nLtcLogic, int nLtc2Src);
 EXTERN void (*COMILX_MC_GetMioCfgLTC) (HANDLE hDevice, int nChannel, int *pnLtcLogic, int *pnLtc2Src);
 EXTERN void (*COMILX_MC_SetMioCfgINP) (HANDLE hDevice, int nChannel, BOOL bInpEnable, int nInpLogic);
 EXTERN void (*COMILX_MC_GetMioCfgINP) (HANDLE hDevice, int nChannel, BOOL *pInpEnable, int *pInpLogic);
 EXTERN void (*COMILX_MC_SetMioCfgSD) (HANDLE hDevice, int nChannel, BOOL bSdEnable, int nSdLogic, int nSdLatch, int nSdMode);
 EXTERN void (*COMILX_MC_GetMioCfgSD) (HANDLE hDevice, int nChannel, BOOL *pSdEnable, int *pSdLogic, int *pSdLatch, int *pSdMode);
 EXTERN void (*COMILX_MC_SetMioCfgSTA) (HANDLE hDevice, int nChannel, int nMode, int nInputType);
 EXTERN void (*COMILX_MC_SetMioCfgSTP) (HANDLE hDevice, int nChannel, int nMode);
 EXTERN void (*COMILX_MC_SetSoftLimit) (HANDLE hDevice, int nChannel, double fLimitP, double fLimitN);
 EXTERN void (*COMILX_MC_EnableSoftLimit) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_DisableSoftLimit) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_SetErrorCompare) (HANDLE hDevice, int nChannel, double fTol, int bEnable);
 EXTERN void (*COMILX_MC_SetGeneralCompare) (HANDLE hDevice, int nChannel, int nCmpSrc, int nCmpMethod, int nCmpAction, double fData);
 
 // Position Compare Output functions //
 EXTERN void (*COMILX_MC_SetTriggerCompare) (HANDLE hDevice, int nChannel, int nCmpSrc, int nCmpMethod, double fData);
 EXTERN BOOL (*COMILX_MC_RegTableCCMP) (HANDLE hDevice, int nChannel, double *pDataBuffer, int nNumData);
 EXTERN BOOL (*COMILX_MC_BuildTableCCMP) (HANDLE hDevice, int nChannel, double fStartData, double fInterval, int nNumData);
 EXTERN BOOL (*COMILX_MC_StartCCMP) (HANDLE hDevice, int nChannel, int nCmpSrc, int nCmpMethod);
 EXTERN BOOL (*COMILX_MC_StopCCMP) (HANDLE hDevice, int nChannel);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_SetMap) (HANDLE hDevice, int nMapIdx, int nAxis_X, int nAxis_Y, int nDoChan);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_GetMap) (HANDLE hDevice, int nMapIdx, int *pnAxis_X, int *pnAxis_Y, int *pnDoChan, int *pnIsValid);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_SetCfg) (HANDLE hDevice, int nMapIdx, int nCmpSrc_X, int nCmpSrc_Y);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_GetCfg) (HANDLE hDevice, int nMapIdx, int *pnCmpSrc_X, int *pnCmpSrc_Y);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_Start) (HANDLE hDevice, int nMapIdx, int anSelOutList[], double afCmpPosList[], int anCmpDirList[], int nListSize);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_Stop) (HANDLE hDevice, int nMapIdx);
 EXTERN BOOL (*COMILX_MC_CmpTrgIx_GetState) (HANDLE hDevice, int nMapIdx, int *nCmpOutCnt, int *nIsActive);

 // Interrupt ฐüทร //
 EXTERN void (*COMILX_MC_MaskInterrupt) (HANDLE hDevice, int nChannel, long dwMask);
 EXTERN void (*COMILX_MC_EnableInterrupt) (HANDLE hDevice, HANDLE hEvent);
 EXTERN void (*COMILX_MC_DisableInterrupt) (HANDLE hDevice);
 EXTERN BOOL (*COMILX_MC_GetAxisIntState) (HANDLE hDevice, int nChannel);
 EXTERN void (*COMILX_MC_GetIntStatus) (HANDLE hDevice, int nChannel, long *pErrorStatus, long *pEventStatus);

 // New Added Functions (V3.1.0.0) //
 EXTERN void (*COMILX_MC_SetSpeedMx2) (HANDLE hDevice, int nMapIndex, double fSpeed, double fAccel, double fDecel);
 EXTERN void (*COMILX_MC_PutIntSTA) (HANDLE hDevice, int ChanMask);
 EXTERN void (*COMILX_MC_SetSyncMode) (HANDLE hDevice, int nChannel, int nMode, int nRefChan, int nCond);
 EXTERN void (*COMILX_MC_HomeMoveAuto) (HANDLE hDevice, int nChannel, int nDirection, 
									  double fRvsVel, double fEscapeDist);
 EXTERN void (*COMILX_MC_HomeMoveAutoAll) (HANDLE hDevice, int nNumAxis, int nAxisList[], int nDirList[],
									double fRvsVelList[], double fEscapeDistList[]);
 EXTERN void (*COMILX_MC_SetHelOnceSpeed) (HANDLE hDevice, int nMaster, int nSpeedMode, double fSpeed, 
											double fAcc, double fDec);
 EXTERN double	(*COMILX_MC_StartHelOnce) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fCoordList[], double fArcAngle);
 EXTERN double	(*COMILX_MC_HelOnce) (HANDLE hDevice, int nNumAxis, int nAxisList[], double fCoordList[], double fArcAngle);
 EXTERN int		(*COMILX_MC_LmCurSequence) (HANDLE hDevice);
 EXTERN void	(*COMILX_MC_LmSetImmediacy) (HANDLE hDevice);
 EXTERN void	(*COMILX_MC_GetHomeConfig) (HANDLE hDevice, int nChannel, int *pnOrgMode, int *pnOrgLogic, int *pnEzCount, int *pnEzLogic, int *pnErcOut);
 EXTERN int		(*COMILX_MC_GetFilterLogic) (HANDLE hDevice, int nChannel, int *pbEnable);
 EXTERN BOOL	(*COMILX_MC_GetPE) (HANDLE hDevice, int nChannel, int *pbEnable);
 EXTERN int		(*COMILX_MC_GetELL) (HANDLE hDevice, int nChannel, int *pnLogic);;
 EXTERN void	(*COMILX_MC_SetOutputMask) (HANDLE hDevice, int nChannel, BOOL bMask);
 EXTERN BOOL	(*COMILX_MC_GetOutputMask) (HANDLE hDevice, int nChannel);
 EXTERN int		(*COMILX_MC_InitFromFile) (HANDLE hDevice, char *szFilePath);
 EXTERN double	(*COMILX_MC_GetInOutRatio) (HANDLE hDevice, int nChannel);
 EXTERN void	(*COMILX_MC_GetMioCfgSTA) (HANDLE hDevice, int nChannel, int *pnMode, int *pnInputType);
 EXTERN void	(*COMILX_MC_GetMioCfgSTP) (HANDLE hDevice, int nChannel, int *pnMode);
 EXTERN void	(*COMILX_MC_GetSoftLimit) (HANDLE hDevice, int nChannel, double *pfLimitP, double *pfLimitN);
 EXTERN BOOL	(*COMILX_MC_GetEnableSoftLimit) (HANDLE hDevice, int nChannel);
 EXTERN void	(*COMILX_MC_GetDeviceVer) (HANDLE hDevice, int *pnVerMajor, int *pnVerMinor);
 EXTERN int		(*COMILX_EnableDebugLog) (HANDLE hDevice, char *szLogFile, int nDebugLevel);
 EXTERN void	(*COMILX_MC_ReadAllRegs) (HANDLE hDevice, ULONG lRegArray[][60]);

 EXTERN void	(*COMILX_MC_ErcOut) (HANDLE hDevice, int nChannel);
 EXTERN void	(*COMILX_MC_ErcReset) (HANDLE hDevice, int nChannel);
 EXTERN BOOL	(*COMILX_MC_SetCorrection) (HANDLE hDevice, long nChannel, long CorrMode, double CorrAmount, double CorrVel, long CntrMask);

 EXTERN void	(*COMILX_MC_LmDoPutOne) (HANDLE hDevice, HANDLE hDoDevice, int nChannel, int nOutState);
 EXTERN void	(*COMILX_MC_LmDoPutMulti) (HANDLE hDevice, HANDLE hDoDevice, int nChannelGroup,
										int dwMask, int dwOutStatess);
 EXTERN void	(*COMILX_MC_LmDoPulseOne) (HANDLE hDevice, HANDLE hDoDevice, int nChannel, int nOutState, ULONG dwDueTime);
 EXTERN void	(*COMILX_MC_LmDoPulseMulti) (HANDLE hDevice, HANDLE hDoDevice, int nChannelGroup,
										int dwMask, int dwOutStatess, ULONG dwDueTime);

 // New Added Functions (V3.1.5.0) //
 EXTERN void	(*COMILX_MC_SetMioProperty) (HANDLE hDevice, int nChannel, long lPropId, long lPropVal);
 EXTERN void	(*COMILX_MC_GetMioProperty) (HANDLE hDevice, int nChannel, long lPropId, long *plPropVal);

 //__________ Utility Functions ____________________________________________//
 EXTERN int		(*COMILX_LastError) (void);
 EXTERN const char* (*COMILX_ErrorString) (int nErrCode);
 EXTERN BOOL	(*COMILX_GetAvailDevList) (TComiDevList *pDevList);
 EXTERN BOOL	(*COMILX_GetDevInfo) (HANDLE hDevice, TComiDevInfo *pDevInfo);
 EXTERN void 	(*COMILX_GetResources) (HANDLE hDevice, PULONG pdwIntVect, PULONG pdwIoPorts,
					 int nNumPorts, PULONG pdwMemPorts, int nNumMemPorts);
 EXTERN void	(*COMILX_WriteMemPortDW) (HANDLE hDevice, ULONG dwPortBase, ULONG nOffset, DWORD dwOutVal);
 EXTERN DWORD	(*COMILX_ReadMemPortDW) (HANDLE hDevice, ULONG dwPortBase, ULONG nOffset);
 EXTERN void	(*COMILX_Outpdw) (HANDLE hDevice, int CS_idx, ULONG nOffset, DWORD dwOutVal);
 EXTERN DWORD	(*COMILX_Inpdw) (HANDLE hDevice, int CS_idx, ULONG nOffset);
 EXTERN void	(*COMILX_Write8402) (HANDLE hDevice, int ch, int addr, int data);
 EXTERN void	(*COMILX_WriteEEPR) (HANDLE hDevice, int addr, int data);
 EXTERN int		(*COMILX_ReadEEPR) (HANDLE hDevice, int addr);
 EXTERN ULONG	(*COMILX_MC_ReadMainSpace) (HANDLE hDevice, int nChannel, int nAddr);
 EXTERN void	(*COMILX_MC_WriteMainSpace) (HANDLE hDevice, int nChannel, int nAddr, ULONG dwValue);
 EXTERN ULONG	(*COMILX_MC_ReadRegister) (HANDLE hDevice, int nChannel, int nRegister);
 EXTERN void	(*COMILX_MC_WriteRegister) (HANDLE hDevice, int nChannel, int nRegister, ULONG dwValue);
 EXTERN int		(*COMILX_GetDeviceThreadCount) (HANDLE hDevice);

#undef EXTERN
#endif

#ifdef __cplusplus
}
#endif

#endif
