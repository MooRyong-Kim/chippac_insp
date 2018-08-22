#ifndef __COMIDAS_COMMON_H_
#define __COMIDAS_COMMON_H_

#ifdef __cplusplus
extern "C"{
#endif

/* Define scan method */
#define TRS_SINGLE 		0x1
#define TRS_BLOCK		0x2
#define TRS_BLOCK_EXT	0x3

/* Define DIO Usage - only for COMI_CP_401 Board */
#define DI_ONLY		0
#define DO_DI		1
#define DI_DO		2
#define DO_ONLY		3

/* define counter control values */
#define   COUNTER_LATCH      0  /* counter latch operation       */
#define   READ_LOAD_MSB      1  /* read/load MSB only            */
#define   READ_LOAD_LSB      2  /* read/load LSB only            */
#define   READ_LOAD_WORD     3  /* read/load LSB first, then MSB */

#define   BCD                1  /* BCD counter                */
#define   BINARY             0  /* Binary counter             */

#define   CMODE0             0  /* Interrupt on terminal count   */
#define   CMODE1             1  /* Programmable one shot         */
#define   CMODE2             2  /* Rate generator                */
#define   CMODE3             3  /* Square wave rate generator    */
#define   CMODE4             4  /* Software triggered strobe     */
#define   CMODE5             5  /* Hardware triggered strobe     */

/* Encoder Counter mode */
#define ENCODER_1X	0   /* 1채배 엔코더 모드 */
#define ENCODER_2X	1	/* 2채배 엔코더 모드 */
#define ENCODER_4X	2	/* 4채배 엔코더 모드 */

#define PG_INFINITE	0  /* PULSE GEN. Infinite mode */

#define AI_SINGLE 	1  /* Single Ended input */
#define AI_DIFF		0  /* Differential input */

enum {TS_NONE, TS_ANALOG, TS_DIGITAL};
enum {TE_POSITIVE, TE_NEGATIVE};
enum {TM_INITIAL, TM_MIDDLE};

//----- Definitions for Motion -------------------------------------------//
#define CMC_LIN_MODE1	0x00000000 // Linear interpolation mode 1 (4축보간만 가능)
#define CMC_LIN_MODE2	0x80000000 // Linear interpolation mode 2 (8축보간 가능, 동시에 여러개의 보간 실행 가능)
#define MAX_CmpTrgIx_MAP_ID		3	// 2축 보간 위치비교출력 맵의 최대값(0 ~ 3)

enum {CMC_DIR_N, CMC_DIR_P}; // Direction
enum {CMC_VMODE_C, CMC_VMODE_T, CMC_VMODE_S}; // Speed mode : Constant, Trapezoidal, S-curve //

typedef enum _TCmMioPropIdEx{
	cmMPID_EN_ARDP = 31 // Property id that enables automatic ramping down position setting functio
}TCmMioPropIdEx;

//------------------------------------------------------------------------//

typedef enum{VT_SHORT, VT_FLOAT, VT_DOUBLE}TComiVarType;
typedef USHORT COMIDAS_DEVID;

typedef struct{
	USHORT	wSubSysID;
	ULONG	nInstance;
	char	szDevName[20];
	UCHAR	bDevCaps; // 0bit-A/D, 1bit-D/A, 2bit-DIO, 3bit-Counter,
	UCHAR	nNumAdChan, nNumDaChan, nNumDiChan, nNumDoChan, nNumCntrChan;
}TComiDevInfo;

typedef struct{
	USHORT nNumDev;
	TComiDevInfo DevInfo[16];
}TComiDevList;

typedef struct{
	char szDate[13], szTime[10];  // Save start시의 날짜와 시간에 대한 스트링
	int nNumChan; // Scan 채널 수
	int nChanList[64]; // Scan 채널 리스트
	int dmin, dmax;
	float vmin[64], vmax[64]; // Scan시의 각 채널의 A/D range
	ULONG dwSavedScanCnt; // 저장된 총 Scan 수
}TScanFileHead;

typedef struct{
	float Ref, lim_h, lim_l;
	float Kp;
	float Td, Ti;
	int ch_ref, ch_ad, ch_da;
}TPidParams;

typedef struct _THelicalUserInfo{
	int c_map, z_axis; // Circualr interpolation axis map, Up/Down Axis
	double c_xcen, c_ycen; // Circular interpolation ceneter point
	int c_dir; // 원호보간의 회전 방향
	int c_num; // 원의 수(마자막 Arc 포함)
	double c_la; // Last angle
	double z_dist;
}THelicalUserInfo;

#define IsAdAvail(caps)		(caps & 0x01)
#define IsDaAvail(caps)		(caps & 0x02)
#define IsDioAvail(caps)	(caps & 0x04)
#define IsCntrAvail(caps)	(caps & 0x08)
#define IsPGenAvail(caps)	(caps & 0x10)

//************* Error codes *************************************//
#define ERR_INVALID_DEVICE_HANDLE	-270 // Invalid device handle is passed to a function
#define ERR_INVALID_FILE_PATH		-280
#define ERR_MEM_ALLOC_FAIL			-290 // Memory allocation fail
#define ERR_FILE_OPEN_FAIL			-300 // File open fail
#define ERR_FILE_CREATE_FAIL		-301 // File creation fail
#define ERR_ISR_CONNEC_FAIL			-310 // ISR registration fail
#define ERR_DIVIDE_BY_ZERO			-400 // Cause divide by zero error 
#define ERR_WORNG_NUM_DATA			-500 // Number of data is too small or too big
#define ERR_VER_MISMATCH			-600 // Version is not matched
#define ERR_MC_BASE					-3000 // Base error code value for motion errors
#define ERR_MC_COMP_FILE_OPEN_FAIL	(ERR_MC_BASE-1)		// position compensation table file open fail!
#define ERR_CMPIX_INVALID_MAP		-5180 // Interpolated position compare output map is not valid
#define ERR_CMPIX_INVALID_AXIS		-5182 // Axis setting is not valid for the specified interpolated position compare output map.
#define ERR_CMPIX_INVALID_DO_CHAN	-5184 // D/O channel setting is not valid for the specified interpolated position compare output map.
#define ERR_CMPIX_ALREADY_ACTIVE	-5186 // Specified Interpolated position compare output map is already active.
#define ERR_CMPIX_TABLE_EMPTY		-5188 // Interpolated position compare output table data is empty.

#ifdef __cplusplus
}
#endif

#endif
