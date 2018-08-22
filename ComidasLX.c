#include <windows.h>
#include <stdio.h>
#define _COMIDASLX_LOADER_C_
#include "Comidaslx.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef struct{
    char *name;
    FARPROC* ptr;
}LIB_FUNCT;

static HINSTANCE hLibrary=NULL;

BOOL COMILX_LoadDll(void)
{
	LIB_FUNCT Func[] = {
						{"COMILX_LoadDevice", 	(FARPROC*)&COMILX_LoadDevice},
						{"COMILX_UnloadDevice", 	(FARPROC*)&COMILX_UnloadDevice},
						{"COMILX_GetResources", 	(FARPROC*)&COMILX_GetResources},
						{"COMILX_WriteMemPortDW", 	(FARPROC*)&COMILX_WriteMemPortDW},
						{"COMILX_ReadMemPortDW", 	(FARPROC*)&COMILX_ReadMemPortDW},
						{"COMILX_Outpdw", 	(FARPROC*)&COMILX_Outpdw},
						{"COMILX_Inpdw", 	(FARPROC*)&COMILX_Inpdw},
						{"COMILX_GetAvailDevList", 	(FARPROC*)&COMILX_GetAvailDevList},
						{"COMILX_GetDevInfo", 	(FARPROC*)&COMILX_GetDevInfo},
						{"COMILX_Write8402", 	(FARPROC*)&COMILX_Write8402},
						{"COMILX_WriteEEPR", 	(FARPROC*)&COMILX_WriteEEPR},
						{"COMILX_ReadEEPR", 	(FARPROC*)&COMILX_ReadEEPR},
						{"COMILX_SetComiBus", 	(FARPROC*)&COMILX_SetComiBus},
						{"COMILX_AD_SetInputType", 	(FARPROC*)&COMILX_AD_SetInputType},
						{"COMILX_AD_SetRange", 	(FARPROC*)&COMILX_AD_SetRange},
						{"COMILX_AD_GetDigit", 	(FARPROC*)&COMILX_AD_GetDigit},
						{"COMILX_AD_GetVolt", 	(FARPROC*)&COMILX_AD_GetVolt},
						{"COMILX_US1_Start", 	(FARPROC*)&COMILX_US1_Start},
						{"COMILX_US1_Stop", 	(FARPROC*)&COMILX_US1_Stop},
						{"COMILX_US1_ChangeScanFreq", 	(FARPROC*)&COMILX_US1_ChangeScanFreq},
						{"COMILX_US1_ResetCount", 	(FARPROC*)&COMILX_US1_ResetCount},
						{"COMILX_US1_GetBuffer", 	(FARPROC*)&COMILX_US1_GetBuffer},
						{"COMILX_US1_CurCount", 	(FARPROC*)&COMILX_US1_CurCount},
						{"COMILX_US1_SBPos", 	(FARPROC*)&COMILX_US1_SBPos},
						{"COMILX_US1_ReleaseBuf", 	(FARPROC*)&COMILX_US1_ReleaseBuf},
						{"COMILX_US1_RetrvOne", 	(FARPROC*)&COMILX_US1_RetrvOne},
						{"COMILX_US1_RetrvChannel", 	(FARPROC*)&COMILX_US1_RetrvChannel},
						{"COMILX_US1_RetrvBlock", 	(FARPROC*)&COMILX_US1_RetrvBlock},
						{"COMILX_US2_SetTriggerEvent", 	(FARPROC*)&COMILX_US2_SetTriggerEvent},
						{"COMILX_US2_Start", 	(FARPROC*)&COMILX_US2_Start},
						{"COMILX_US2_Resume", 	(FARPROC*)&COMILX_US2_Resume},
						{"COMILX_US2_ChangeScanFreq", 	(FARPROC*)&COMILX_US2_ChangeScanFreq},
						{"COMILX_US2_Stop", 	(FARPROC*)&COMILX_US2_Stop},
						{"COMILX_US2_GetBuffer", 	(FARPROC*)&COMILX_US2_GetBuffer},
						{"COMILX_US2_ReleaseBuf", 	(FARPROC*)&COMILX_US2_ReleaseBuf},
						{"COMILX_US2_DmaCount", 	(FARPROC*)&COMILX_US2_DmaCount},
						{"COMILX_US2_IsBufFull", 	(FARPROC*)&COMILX_US2_IsBufFull},
						{"COMILX_US2_RetrvChannel", 	(FARPROC*)&COMILX_US2_RetrvChannel},
						{"COMILX_DIO_SetUsage", 	(FARPROC*)&COMILX_DIO_SetUsage},
						{"COMILX_DIO_GetUsage", 	(FARPROC*)&COMILX_DIO_GetUsage},
						{"COMILX_DI_GetOne", 	(FARPROC*)&COMILX_DI_GetOne},
						{"COMILX_DI_GetAll", 	(FARPROC*)&COMILX_DI_GetAll},
						{"COMILX_DI_GetAllEx", 	(FARPROC*)&COMILX_DI_GetAllEx},
						{"COMILX_DO_PutOne", 	(FARPROC*)&COMILX_DO_PutOne},
						{"COMILX_DO_PutAll", 	(FARPROC*)&COMILX_DO_PutAll},
						{"COMILX_DO_PutAllEx", 	(FARPROC*)&COMILX_DO_PutAllEx},
						{"COMILX_DO_GetOne", 	(FARPROC*)&COMILX_DO_GetOne},
						{"COMILX_DO_GetAll", 	(FARPROC*)&COMILX_DO_GetAll},
						{"COMILX_DO_GetAllEx", 	(FARPROC*)&COMILX_DO_GetAllEx},
						{"COMILX_SDIO_InitComm", 	(FARPROC*)&COMILX_SDIO_InitComm},
						{"COMILX_SDIO_CheckModule", 	(FARPROC*)&COMILX_SDIO_CheckModule},
						{"COMILX_SDIO_SetDioUsage", 	(FARPROC*)&COMILX_SDIO_SetDioUsage},
						{"COMILX_SDIO_ReadLowByte", 	(FARPROC*)&COMILX_SDIO_ReadLowByte},
						{"COMILX_SDIO_ReadHighByte", 	(FARPROC*)&COMILX_SDIO_ReadHighByte},
						{"COMILX_SDIO_WriteLowByte", 	(FARPROC*)&COMILX_SDIO_WriteLowByte},
						{"COMILX_SDIO_WriteHighByte", 	(FARPROC*)&COMILX_SDIO_WriteHighByte},
						{"COMILX_DA_Out", 	(FARPROC*)&COMILX_DA_Out},
						{"COMILX_WFM_Start", 	(FARPROC*)&COMILX_WFM_Start},
						{"COMILX_WFM_Reload", 	(FARPROC*)&COMILX_WFM_Reload},
						{"COMILX_WFM_RateChange", 	(FARPROC*)&COMILX_WFM_RateChange},
						{"COMILX_WFM_GetCurPos", 	(FARPROC*)&COMILX_WFM_GetCurPos},
						{"COMILX_WFM_GetCurLoops", 	(FARPROC*)&COMILX_WFM_GetCurLoops},
						{"COMILX_WFM_Stop", 	(FARPROC*)&COMILX_WFM_Stop},
						{"COMILX_ReadCounter32", 	(FARPROC*)&COMILX_ReadCounter32},
						{"COMILX_ClearCounter32", 	(FARPROC*)&COMILX_ClearCounter32},
						{"COMILX_MC_Reset", 	(FARPROC*)&COMILX_MC_Reset},
						{"COMILX_MC_ServoOn", 	(FARPROC*)&COMILX_MC_ServoOn},
						{"COMILX_MC_GetServoOn", 	(FARPROC*)&COMILX_MC_GetServoOn},
						{"COMILX_MC_SetBlockingMode", 	(FARPROC*)&COMILX_MC_SetBlockingMode},
						{"COMILX_MC_SetWindowHandle", 	(FARPROC*)&COMILX_MC_SetWindowHandle},
						{"COMILX_MC_SetOutputMode", 	(FARPROC*)&COMILX_MC_SetOutputMode},
						{"COMILX_MC_GetOutputMode", 	(FARPROC*)&COMILX_MC_GetOutputMode},
						{"COMILX_MC_SetInputMode", 	(FARPROC*)&COMILX_MC_SetInputMode},
						{"COMILX_MC_GetInputMode", 	(FARPROC*)&COMILX_MC_GetInputMode},
						{"COMILX_MC_SetSpeedRange", 	(FARPROC*)&COMILX_MC_SetSpeedRange},
						{"COMILX_MC_GetSpeedRange", 	(FARPROC*)&COMILX_MC_GetSpeedRange},
						{"COMILX_MC_SetUnitDistance", 	(FARPROC*)&COMILX_MC_SetUnitDistance},
						{"COMILX_MC_GetUnitDistance", 	(FARPROC*)&COMILX_MC_GetUnitDistance},
						{"COMILX_MC_SetUnitSpeed", 	(FARPROC*)&COMILX_MC_SetUnitSpeed},
						{"COMILX_MC_GetUnitSpeed", 	(FARPROC*)&COMILX_MC_GetUnitSpeed},
						{"COMILX_MC_SetInOutRatio", 	(FARPROC*)&COMILX_MC_SetInOutRatio},						
						{"COMILX_MC_SetSpeedMode", 	(FARPROC*)&COMILX_MC_SetSpeedMode},
						{"COMILX_MC_SetSpeed", 	(FARPROC*)&COMILX_MC_SetSpeed},
						{"COMILX_MC_SetAccel", 	(FARPROC*)&COMILX_MC_SetAccel},
						{"COMILX_MC_SetScurve", 	(FARPROC*)&COMILX_MC_SetScurve},
						{"COMILX_MC_StartVMove", 	(FARPROC*)&COMILX_MC_StartVMove},
						{"COMILX_MC_StartMove", 	(FARPROC*)&COMILX_MC_StartMove},
						{"COMILX_MC_Move", 	(FARPROC*)&COMILX_MC_Move},
						{"COMILX_MC_StartMoveTo", 	(FARPROC*)&COMILX_MC_StartMoveTo},
						{"COMILX_MC_MoveTo", 	(FARPROC*)&COMILX_MC_MoveTo},
						{"COMILX_MC_Stop", 	(FARPROC*)&COMILX_MC_Stop},
						{"COMILX_MC_EmgStop", 	(FARPROC*)&COMILX_MC_EmgStop},
						{"COMILX_MC_Done", 	(FARPROC*)&COMILX_MC_Done},
						{"COMILX_MC_StartVMoveAll", 	(FARPROC*)&COMILX_MC_StartVMoveAll},
						{"COMILX_MC_StartMoveAll", 	(FARPROC*)&COMILX_MC_StartMoveAll},
						{"COMILX_MC_MoveAll", 	(FARPROC*)&COMILX_MC_MoveAll},
						{"COMILX_MC_StartMoveToAll", 	(FARPROC*)&COMILX_MC_StartMoveToAll},
						{"COMILX_MC_MoveToAll", 	(FARPROC*)&COMILX_MC_MoveToAll},
						{"COMILX_MC_StopAll", 	(FARPROC*)&COMILX_MC_StopAll},
						{"COMILX_MC_EmgStopAll", 	(FARPROC*)&COMILX_MC_EmgStopAll},
						{"COMILX_MC_AllDone", 	(FARPROC*)&COMILX_MC_AllDone},
						{"COMILX_MC_MapAxes", 	(FARPROC*)&COMILX_MC_MapAxes},
						{"COMILX_MC_SetSpeedModeMx", 	(FARPROC*)&COMILX_MC_SetSpeedModeMx},
						{"COMILX_MC_SetSpeedMx", 	(FARPROC*)&COMILX_MC_SetSpeedMx},
						{"COMILX_MC_StartLine", 	(FARPROC*)&COMILX_MC_StartLine},
						{"COMILX_MC_Line", 	(FARPROC*)&COMILX_MC_Line},
						{"COMILX_MC_StartLineTo", 	(FARPROC*)&COMILX_MC_StartLineTo},
						{"COMILX_MC_LineTo", 	(FARPROC*)&COMILX_MC_LineTo},
						{"COMILX_MC_StartArc_a", 	(FARPROC*)&COMILX_MC_StartArc_a},
						{"COMILX_MC_Arc_a", 	(FARPROC*)&COMILX_MC_Arc_a},
						{"COMILX_MC_StartArc_p", 	(FARPROC*)&COMILX_MC_StartArc_p},
						{"COMILX_MC_Arc_p", 	(FARPROC*)&COMILX_MC_Arc_p},
						{"COMILX_MC_StartArcTo_a", 	(FARPROC*)&COMILX_MC_StartArcTo_a},
						{"COMILX_MC_ArcTo_a", 	(FARPROC*)&COMILX_MC_ArcTo_a},
						{"COMILX_MC_StartArcTo_p", 	(FARPROC*)&COMILX_MC_StartArcTo_p},
						{"COMILX_MC_ArcTo_p", 	(FARPROC*)&COMILX_MC_ArcTo_p},
						{"COMILX_MC_CompleteArc", 	(FARPROC*)&COMILX_MC_CompleteArc},
						{"COMILX_MC_MxDone", 	(FARPROC*)&COMILX_MC_MxDone},
						{"COMILX_MC_BuildSpline", 	(FARPROC*)&COMILX_MC_BuildSpline},
						{"COMILX_MC_DeleteSpline", 	(FARPROC*)&COMILX_MC_DeleteSpline},
						{"COMILX_MC_StartHelical", 	(FARPROC*)&COMILX_MC_StartHelical},
						{"COMILX_MC_AbortHelical", 	(FARPROC*)&COMILX_MC_AbortHelical},
						{"COMILX_MC_OverrideSpeedSet", 	(FARPROC*)&COMILX_MC_OverrideSpeedSet},
						{"COMILX_MC_OverrideSpeedSetAll", 	(FARPROC*)&COMILX_MC_OverrideSpeedSetAll},
						{"COMILX_MC_OverrideMove", 	(FARPROC*)&COMILX_MC_OverrideMove},
						{"COMILX_MC_OverrideMoveTo", 	(FARPROC*)&COMILX_MC_OverrideMoveTo},
						{"COMILX_MC_SetHomeConfig", 	(FARPROC*)&COMILX_MC_SetHomeConfig},
						{"COMILX_MC_HomeMove", 	(FARPROC*)&COMILX_MC_HomeMove},
						{"COMILX_MC_StartVMoveEx", 	(FARPROC*)&COMILX_MC_StartVMoveEx},
						{"COMILX_MC_StartMoveEx", 	(FARPROC*)&COMILX_MC_StartMoveEx},
						{"COMILX_MC_SetPulserInputMode", 	(FARPROC*)&COMILX_MC_SetPulserInputMode},
						{"COMILX_MC_PulserHomeMove", 	(FARPROC*)&COMILX_MC_PulserHomeMove},
						{"COMILX_MC_StartPulserVMove", 	(FARPROC*)&COMILX_MC_StartPulserVMove},
						{"COMILX_MC_StartPulserMove", 	(FARPROC*)&COMILX_MC_StartPulserMove},
						{"COMILX_MC_PulserMove", 	(FARPROC*)&COMILX_MC_PulserMove},
						{"COMILX_MC_StartPulserMoveTo", 	(FARPROC*)&COMILX_MC_StartPulserMoveTo},
						{"COMILX_MC_PulserMoveTo", 	(FARPROC*)&COMILX_MC_PulserMoveTo},
						{"COMILX_MC_SetListMotionAxes", 	(FARPROC*)&COMILX_MC_SetListMotionAxes},
						{"COMILX_MC_BeginList", 	(FARPROC*)&COMILX_MC_BeginList},
						{"COMILX_MC_EndList", 	(FARPROC*)&COMILX_MC_EndList},
						{"COMILX_MC_StartListMotion", 	(FARPROC*)&COMILX_MC_StartListMotion},
						{"COMILX_MC_AbortListMotion", 	(FARPROC*)&COMILX_MC_AbortListMotion},
						{"COMILX_MC_CheckListMotionDone", 	(FARPROC*)&COMILX_MC_CheckListMotionDone},
						{"COMILX_MC_ResetAxis", 	(FARPROC*)&COMILX_MC_ResetAxis},
						{"COMILX_MC_GetCurSpeed", 	(FARPROC*)&COMILX_MC_GetCurSpeed},
						{"COMILX_MC_EnableActSpdChk", 	(FARPROC*)&COMILX_MC_EnableActSpdChk},
						{"COMILX_MC_DisableActSpdChk", 	(FARPROC*)&COMILX_MC_DisableActSpdChk},
						{"COMILX_MC_GetActualSpeed", 	(FARPROC*)&COMILX_MC_GetActualSpeed},
						{"COMILX_MC_GetPosition_A", 	(FARPROC*)&COMILX_MC_GetPosition_A},
						{"COMILX_MC_SetPosition_A", 	(FARPROC*)&COMILX_MC_SetPosition_A},
						{"COMILX_MC_GetPosition_C", 	(FARPROC*)&COMILX_MC_GetPosition_C},
						{"COMILX_MC_SetPosition_C", 	(FARPROC*)&COMILX_MC_SetPosition_C},
						{"COMILX_MC_GetCount_A", 	(FARPROC*)&COMILX_MC_GetCount_A},
						{"COMILX_MC_SetCount_A", 	(FARPROC*)&COMILX_MC_SetCount_A},
						{"COMILX_MC_GetCount_C", 	(FARPROC*)&COMILX_MC_GetCount_C},
						{"COMILX_MC_SetCount_C", 	(FARPROC*)&COMILX_MC_SetCount_C},
						{"COMILX_MC_GetCount_D", 	(FARPROC*)&COMILX_MC_GetCount_D},
						{"COMILX_MC_SetCount_D", 	(FARPROC*)&COMILX_MC_SetCount_D},
						{"COMILX_MC_GetCount_G", 	(FARPROC*)&COMILX_MC_GetCount_G},
						{"COMILX_MC_SetCount_G", 	(FARPROC*)&COMILX_MC_SetCount_G},
						{"COMILX_MC_GetCount_R", 	(FARPROC*)&COMILX_MC_GetCount_R},
						{"COMILX_MC_SetCount_R", 	(FARPROC*)&COMILX_MC_SetCount_R},
						{"COMILX_MC_ReadLatchCounter", 	(FARPROC*)&COMILX_MC_ReadLatchCounter},
						{"COMILX_MC_GetLatchState", 	(FARPROC*)&COMILX_MC_GetLatchState},
						{"COMILX_MC_GetMotionStatus", 	(FARPROC*)&COMILX_MC_GetMotionStatus},
						{"COMILX_MC_GetMioStatus", 	(FARPROC*)&COMILX_MC_GetMioStatus},
						{"COMILX_MC_SetFilterLogic", 	(FARPROC*)&COMILX_MC_SetFilterLogic},
						{"COMILX_MC_SetPE", 	(FARPROC*)&COMILX_MC_SetPE},
						{"COMILX_MC_SetELL", 	(FARPROC*)&COMILX_MC_SetELL},
						{"COMILX_MC_SetMioCfgALM", 	(FARPROC*)&COMILX_MC_SetMioCfgALM},
						{"COMILX_MC_GetMioCfgALM", 	(FARPROC*)&COMILX_MC_GetMioCfgALM},
						{"COMILX_MC_SetMioCfgEL", 	(FARPROC*)&COMILX_MC_SetMioCfgEL},
						{"COMILX_MC_GetMioCfgEL", 	(FARPROC*)&COMILX_MC_GetMioCfgEL},
						{"COMILX_MC_SetMioCfgINP", 	(FARPROC*)&COMILX_MC_SetMioCfgINP},
						{"COMILX_MC_GetMioCfgINP", 	(FARPROC*)&COMILX_MC_GetMioCfgINP},
						{"COMILX_MC_SetMioCfgERC", 	(FARPROC*)&COMILX_MC_SetMioCfgERC},
						{"COMILX_MC_GetMioCfgERC", 	(FARPROC*)&COMILX_MC_GetMioCfgERC},
						{"COMILX_MC_SetMioCfgSD", 	(FARPROC*)&COMILX_MC_SetMioCfgSD},
						{"COMILX_MC_GetMioCfgSD", 	(FARPROC*)&COMILX_MC_GetMioCfgSD},
						{"COMILX_MC_SetMioCfgDR", 	(FARPROC*)&COMILX_MC_SetMioCfgDR},
						{"COMILX_MC_GetMioCfgDR", 	(FARPROC*)&COMILX_MC_GetMioCfgDR},
						{"COMILX_MC_SetMioCfgCLR", 	(FARPROC*)&COMILX_MC_SetMioCfgCLR},
						{"COMILX_MC_GetMioCfgCLR", 	(FARPROC*)&COMILX_MC_GetMioCfgCLR},
						{"COMILX_MC_SetMioCfgCMP", 	(FARPROC*)&COMILX_MC_SetMioCfgCMP},
						{"COMILX_MC_GetMioCfgCMP", 	(FARPROC*)&COMILX_MC_GetMioCfgCMP},
						{"COMILX_MC_SetMioCfgLTC", 	(FARPROC*)&COMILX_MC_SetMioCfgLTC},
						{"COMILX_MC_GetMioCfgLTC", 	(FARPROC*)&COMILX_MC_GetMioCfgLTC},
						{"COMILX_MC_SetMioCfgSTA", 	(FARPROC*)&COMILX_MC_SetMioCfgSTA},
						{"COMILX_MC_SetMioCfgSTP", 	(FARPROC*)&COMILX_MC_SetMioCfgSTP},
						{"COMILX_MC_SetSoftLimit", 	(FARPROC*)&COMILX_MC_SetSoftLimit},
						{"COMILX_MC_EnableSoftLimit", 	(FARPROC*)&COMILX_MC_EnableSoftLimit},
						{"COMILX_MC_DisableSoftLimit", 	(FARPROC*)&COMILX_MC_DisableSoftLimit},
						{"COMILX_MC_SetErrorCompare", 	(FARPROC*)&COMILX_MC_SetErrorCompare},
						{"COMILX_MC_SetTriggerCompare", 	(FARPROC*)&COMILX_MC_SetTriggerCompare},
						{"COMILX_MC_RegTableCCMP", 	(FARPROC*)&COMILX_MC_RegTableCCMP},
						{"COMILX_MC_BuildTableCCMP", 	(FARPROC*)&COMILX_MC_BuildTableCCMP},
						{"COMILX_MC_StartCCMP", 	(FARPROC*)&COMILX_MC_StartCCMP},
						{"COMILX_MC_StopCCMP", 	(FARPROC*)&COMILX_MC_StopCCMP},
						{"COMILX_MC_CmpTrgIx_SetMap", 	(FARPROC*)&COMILX_MC_CmpTrgIx_SetMap},
						{"COMILX_MC_CmpTrgIx_GetMap", 	(FARPROC*)&COMILX_MC_CmpTrgIx_GetMap},
						{"COMILX_MC_CmpTrgIx_SetCfg", 	(FARPROC*)&COMILX_MC_CmpTrgIx_SetCfg},
						{"COMILX_MC_CmpTrgIx_GetCfg", 	(FARPROC*)&COMILX_MC_CmpTrgIx_GetCfg},
						{"COMILX_MC_CmpTrgIx_Start", 	(FARPROC*)&COMILX_MC_CmpTrgIx_Start},
						{"COMILX_MC_CmpTrgIx_Stop", 	(FARPROC*)&COMILX_MC_CmpTrgIx_Stop},
						{"COMILX_MC_CmpTrgIx_GetState", 	(FARPROC*)&COMILX_MC_CmpTrgIx_GetState},
						{"COMILX_MC_MaskInterrupt", 	(FARPROC*)&COMILX_MC_MaskInterrupt},
						{"COMILX_MC_EnableInterrupt", 	(FARPROC*)&COMILX_MC_EnableInterrupt},
						{"COMILX_MC_DisableInterrupt", 	(FARPROC*)&COMILX_MC_DisableInterrupt},
						{"COMILX_MC_GetAxisIntState", 	(FARPROC*)&COMILX_MC_GetAxisIntState},
						{"COMILX_MC_GetIntStatus", 	(FARPROC*)&COMILX_MC_GetIntStatus},
						{"COMILX_MC_ReadMainSpace", 	(FARPROC*)&COMILX_MC_ReadMainSpace},
						{"COMILX_MC_WriteMainSpace", 	(FARPROC*)&COMILX_MC_WriteMainSpace},
						{"COMILX_MC_ReadRegister", 	(FARPROC*)&COMILX_MC_ReadRegister},
						{"COMILX_MC_WriteRegister", 	(FARPROC*)&COMILX_MC_WriteRegister},
						// Newly Added Functions (V3.1.0.0) //
						{"COMILX_MC_GetFilterLogic", 	(FARPROC*)&COMILX_MC_GetFilterLogic},
						{"COMILX_MC_GetPE", 	(FARPROC*)&COMILX_MC_GetPE},
						{"COMILX_MC_GetELL", 	(FARPROC*)&COMILX_MC_GetELL},
						{"COMILX_MC_HomeMoveAuto", 	(FARPROC*)&COMILX_MC_HomeMoveAuto},
						{"COMILX_MC_HomeMoveAutoAll", 	(FARPROC*)&COMILX_MC_HomeMoveAutoAll},
						{"COMILX_MC_SetSpeedMx2", 	(FARPROC*)&COMILX_MC_SetSpeedMx2},
						{"COMILX_MC_PutIntSTA", 	(FARPROC*)&COMILX_MC_PutIntSTA},
						{"COMILX_MC_SetSyncMode", 	(FARPROC*)&COMILX_MC_SetSyncMode},
						{"COMILX_MC_SetHelOnceSpeed", 	(FARPROC*)&COMILX_MC_SetHelOnceSpeed},
						{"COMILX_MC_StartHelOnce", 	(FARPROC*)&COMILX_MC_StartHelOnce},
						{"COMILX_MC_HelOnce", 	(FARPROC*)&COMILX_MC_HelOnce},
						{"COMILX_MC_LmCurSequence", 	(FARPROC*)&COMILX_MC_LmCurSequence},
						{"COMILX_MC_GetHomeConfig", 	(FARPROC*)&COMILX_MC_GetHomeConfig},
						{"COMILX_MC_SetOutputMask", 	(FARPROC*)&COMILX_MC_SetOutputMask},
						{"COMILX_MC_GetOutputMask", 	(FARPROC*)&COMILX_MC_GetOutputMask},
						{"COMILX_MC_InitFromFile", 	(FARPROC*)&COMILX_MC_InitFromFile},
						{"COMILX_MC_GetInOutRatio", 	(FARPROC*)&COMILX_MC_GetInOutRatio},
						{"COMILX_MC_GetMioCfgSTA", 	(FARPROC*)&COMILX_MC_GetMioCfgSTA},
						{"COMILX_MC_GetMioCfgSTP", 	(FARPROC*)&COMILX_MC_GetMioCfgSTP},
						{"COMILX_MC_GetSoftLimit", 	(FARPROC*)&COMILX_MC_GetSoftLimit},
						{"COMILX_MC_GetEnableSoftLimit", 	(FARPROC*)&COMILX_MC_GetEnableSoftLimit},
						{"COMILX_MC_GetDeviceVer", 	(FARPROC*)&COMILX_MC_GetDeviceVer},
						{"COMILX_MC_ReadAllRegs", 	(FARPROC*)&COMILX_MC_ReadAllRegs},
						{"COMILX_MC_ErcOut", 	(FARPROC*)&COMILX_MC_ErcOut},
						{"COMILX_MC_ErcReset", 	(FARPROC*)&COMILX_MC_ErcReset},
						{"COMILX_MC_SetCorrection", 	(FARPROC*)&COMILX_MC_SetCorrection},
						{"COMILX_MC_SetMioProperty", 	(FARPROC*)&COMILX_MC_SetMioProperty},
						{"COMILX_MC_GetMioProperty", 	(FARPROC*)&COMILX_MC_GetMioProperty},
						{"COMILX_EnableDebugLog", 	(FARPROC*)&COMILX_EnableDebugLog},
						{"COMILX_LastError", 	(FARPROC*)&COMILX_LastError},
						{"COMILX_ErrorString", 	(FARPROC*)&COMILX_ErrorString},
						{"COMILX_GetDeviceThreadCount", 	(FARPROC*)&COMILX_GetDeviceThreadCount},
						{NULL, NULL}
					   };
	LIB_FUNCT *f;
	
	if((hLibrary = LoadLibrary ("ComidasLX.dll")) == NULL)
    	return FALSE;
	
	f = &Func[0];
	while(f->ptr != NULL)
	{
		*(f->ptr) = GetProcAddress ((HMODULE)hLibrary, f->name);
		if(*(f->ptr) == NULL){
			printf("Failed to load \"%s\" Function", f->name);
		}
		f++;
	}
	return TRUE;
}

void COMILX_UnloadDll(void)
{
	if(hLibrary){
		FreeLibrary(hLibrary);
		hLibrary = NULL;
	}
}

#ifdef __cplusplus
}
#endif

