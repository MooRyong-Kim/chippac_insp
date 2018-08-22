
#ifndef _CREVIS_FNIO_DEF_H
#define _CREVIS_FNIO_DEF_H

extern "C"{
//
// Type define
//
typedef	long	FNIO_ERROR;					
typedef	long	FNIO_VALUE;
typedef	char*	FNIO_STRING;
typedef	void*	FNIO_HANDLE;					
typedef	void*	FNIO_POINTER;
#define			FNIO_CALLTYPE __stdcall

//
// Default value define
//
#define			FNIO_DEFAULT_VALUE					0
#define			FNIO_ENABLE							1
#define			FNIO_DISENABLE						0	
#define			FNIO_EXECUTE						1
#define			FNIO_ABORT							0
#define			FNIO_DEFAULT_RESPONSE_TIMEOUT		3000
#define			FNIO_DEFAULT_DEVICE_UPDATE_TIMEOUT	5000
#define			FNIO_DEFAULT_CONNECT_TIMEOUT		5000
#define			FNIO_DEFAULT_UPDATE_FREQUENCY		50
	
//
//Device Type Define
//
#define MODBUS_TCP				0
#define MODBUS_PORT_NUMBER		502

//
// Device infomation structure
//
typedef struct tagDEVICEINFOMODBUSTCP2
{
	unsigned char	IpAddress[4];
} DEVICEINFOMODBUSTCP2;

//
// Commands
//
typedef enum FnioSystemCommand							
{							
	SYS_VERSION						= 0x00000001,			
	SYS_VENDOR_NAME					= 0x00000002,	
	SYS_CONNECTION_TIMEOUT			= 0x00000005,			
	SYS_DEVICE_NUM					= 0x00000006,	
} FNIO_SYS_CMD;	

typedef enum FnioDeviceCommand							
{
	// Device Identification
	DEV_PRODUCT_CODE				= 0x00001002,
	DEV_FIRMWARE_VERSION			= 0x00001003,
	DEV_PROCDUCT_NAME				= 0x00001005,
	DEV_FIRMWARE_RELEASE_DATE		= 0x00001007,
	// Device Time Controls
	DEV_WATCHDOC_TIME				= 0x00002000,
	DEV_IO_UPDATE_TIME				= 0x00002004,
	DEV_MAIN_LOOP_TIME				= 0x00002005,
	// Device Translayer Controls
	DEV_IP_ADDRESS					= 0x00003007,
	DEV_SUBNET_MASK					= 0x00003008,
	DEV_GATEWAY						= 0x00003009,
	DEV_MAC_ID						= 0x0000300A,
	// Device Informations
	DEV_EXPANSION_SLOT_NUMBER		= 0x00004009,
	DEV_ACTIVE_SLOT_NUMBER			= 0x0000400A,
	DEV_INACTIVE_SLOT_NUMBER		= 0x0000400B,
	DEV_INPUT_PROCESS_IMAGE_MODE	= 0x0000400D,
	DEV_OUTPUT_PROCESS_IMAGE_MODE	= 0x0000400E,
	DEV_INACTIVE_SLOT_LIST			= 0x0000400F,
	DEV_ACTIVE_SLOT_LIST			= 0x00004010,
	DEV_ALARM_SLOT_LIST				= 0x00004011,
	DEV_DEVICE_BUS_STATUS			= 0x00004012,
	DEV_INPUT_IMAGE_SIZE			= 0x00007000,
	DEV_OUTPUT_IMAGE_SIZE			= 0x00007001,	
	// Device Configurations
	DEV_RECONNECT_TIMEOUT			= 0x00009000,
	DEV_RESPONSE_TIMEOUT			= 0x00009001,
	DEV_UPDATE_FREQUENCY			= 0x00009002,
	DEV_AUTO_CONNECTION				= 0x00009003,

} FNIO_DEV_CMD;

typedef enum FnioIoModuleCommand							
{
	IO_INPUT_BIT_SIZE				= 0x0000A008,
	IO_OUTPUT_BIT_SIZE				= 0x0000A009,
	IO_ST_NUMBER					= 0x0000A00E,
	IO_MODULE_DESCRIPTION			= 0x0000A00F,
	IO_CONFIGURATION_PARAMETER_SIZE = 0x0000A010,
	IO_CONFIGURATION_PARAMETER		= 0x0000A011,
	IO_FIRMWARE_VERSION				= 0x0000A017,
} FNIO_IO_CMD;

typedef enum FnioDataInformation
{
	DATA_ACCESS_MODE				= 0x00012000,
	DATA_TYPE						= 0x00012001,
	DATA_MIN						= 0x00012003,
	DATA_MAX						= 0x00012004,
	DATA_INC						= 0x00012005,
	DATA_VALUE						= 0x00012006,
} FNIO_DATA_INFO;

typedef enum FnioAccessMode				
{				
	READ_ONLY						= 0x00013000,
	WRITE_ONLY						= 0x00013001,
	READ_WRITE						= 0x00013002,
	NOT_IMPLEMENT					= 0x00013003,
} FNIO_ACCESS_MODE;				

//
// Deta types
//
typedef enum FnioDataType							
{							
	DATATYPE_UNKNOWN				= 0x00021000,			
	DATATYPE_STRING 				= 0x00021001,			
	DATATYPE_INT8					= 0x00021002,			
	DATATYPE_UINT8  				= 0x00021003,			
	DATATYPE_INT16  				= 0x00021004,			
	DATATYPE_UINT16   				= 0x00021005,			
	DATATYPE_INT32      			= 0x00021006,			
	DATATYPE_UINT32  				= 0x00021007,			
	DATATYPE_INT64       			= 0x00021008,			
	DATATYPE_UINT64					= 0x00021009,			
	DATATYPE_FLOAT32         		= 0x0002100A,			
	DATATYPE_FLOAT64    			= 0x0002100B,			
	DATATYPE_HANDLE    				= 0x0002100C,			
} FNIO_DATATYPE;	

//
// Error types
//
typedef enum FnioErrorType							
{		
	FNIO_ERROR_SUCCESS        				= 0,
	FNIO_ERROR_DEVICE_CONNECT_FAIL   		= -1,
	FNIO_ERROR_MAX_CONNECTION_EXCEEDED		= -2,
	FNIO_ERROR_ILLEGAL_DEVICE_TYPE			= -3,
	FNIO_ERROR_SYSTEM_ALREADY_INIT  		= -4,
	FNIO_ERROR_SYSTEM_ALLOC_FAIL   			= -5,
	FNIO_ERROR_SYSTEM_NOT_EXIST   			= -6,
	FNIO_ERROR_SYSTEM_CHECK_FAIL    		= -7,
	FNIO_ERROR_WRITE_ONLY_COMMAND   		= -8,
	FNIO_ERROR_READ_ONLY_COMMAND    		= -9,
	FNIO_ERROR_NOT_DEFINE_COMMAND   		= -10,
	FNIO_ERROR_NOT_SUPPORT_COMMAND   		= -11,
	FNIO_ERROR_DUPLICATE_CONNECT   			= -12,
	FNIO_ERROR_DEVICEINFO_ALLOC_FAIL  		= -13,
	FNIO_ERROR_DEVICE_ALLOC_FAIL   			= -14,
	FNIO_ERROR_UNKNOWN_MODEL		 		= -15,
	FNIO_ERROR_BUFFERSIZE_SMALL    			= -16,
	FNIO_ERROR_DEVICE_INDEX_EXCESS   		= -17,
	FNIO_ERROR_NOT_EXECUTE     				= -18,
	FNIO_ERROR_DEVICE_CHECK_FAIL    		= -19,
	FNIO_ERROR_PORT_ALLOC_FAIL 				= -20,
	FNIO_ERROR_IO_MODULE_ALLOC_FAIL  		= -21,
	FNIO_ERROR_BUFFER_ALLOC_FAIL   			= -22,
	FNIO_ERROR_NULL_BUFFER     				= -23,
	FNIO_ERROR_LIST_INDEX_EXCESS    		= -24,
	FNIO_ERROR_SLOT_CHECK_FAIL    			= -25,
	FNIO_ERROR_NOT_DEFINE_DATAINFO   		= -26,
	FNIO_ERROR_NOT_SUPPORT_DATAINFO   		= -27,
	FNIO_ERROR_NOT_DEFINE_EVENT				= -28,
	FNIO_ERROR_NOT_AVAILABLE_PORT			= -29,
	FNIO_ERROR_INVALID_IMAGE_ADDRESS  		= -30,
	FNIO_ERROR_INVALID_IMAGE_LENGHT  		= -31,
	FNIO_ERROR_INVALID_BIT_INDEX  			= -32,
	// Device protocol errors 
	FNIO_ERROR_ILLEGAL_FUNCTION				= 1,
	FNIO_ERROR_ILLEGAL_DATA_ADDRESS			= 2,
	FNIO_ERROR_ILLEGAL_DATA_VALUE			= 3,
	FNIO_ERROR_SLAVE_DEVICE_FAILURE			= 4,
	FNIO_ERROR_ACKNOWLEDGE					= 5,
	FNIO_ERROR_SLAVE_DEVICE_BUSY			= 6,
	FNIO_ERROR_MEMORY_PARITY_ERROR			= 8,
	FNIO_ERROR_GATEWAY_PATH_UNAVAILABLE		= 10,
	FNIO_ERROR_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND = 11,
	FNIO_ERROR_UNKNOW						= 14,
	FNIO_ERROR_ILLEGAL_TRANSACTION_ID		= 15,
	FNIO_ERROR_TRANSACTION_TIMEOUT			= 16,
	FNIO_ERROR_ILLEGAL_PROTOCOL_TYPE		= 19,			
	FNIO_ERROR_NETWORK_IS_BUSY				= 20,	
	FNIO_ERROR_NETWORK_ERROR				= 21,
	FNIO_ERROR_ILLEGAL_PROTOCAL_ID			= 22,
	FNIO_ERROR_ILLEGAL_UNIT_ID				= 23,
} FNIO_ERROR_TYPE;

//
// System functions
//
FNIO_ERROR	FNIO_CALLTYPE	LibInitSystem			(FNIO_HANDLE* phSystem);
FNIO_ERROR	FNIO_CALLTYPE	LibFreeSystem			(FNIO_HANDLE hSystem);
FNIO_ERROR	FNIO_CALLTYPE	LibGetLastError			(FNIO_ERROR* pErrorCode, FNIO_STRING pErrText, FNIO_VALUE* pSize);	
FNIO_ERROR  FNIO_CALLTYPE	SysGetParam				(FNIO_HANDLE hSystem, FNIO_SYS_CMD Cmd, FNIO_DATA_INFO Info, FNIO_POINTER pData, FNIO_VALUE* pDataSize);
FNIO_ERROR  FNIO_CALLTYPE	SysSetParam				(FNIO_HANDLE hSystem, FNIO_SYS_CMD Cmd, FNIO_POINTER pData, FNIO_VALUE* pDataSize);

//
// Device functions
//
FNIO_ERROR	FNIO_CALLTYPE	DevOpenDevice			(FNIO_HANDLE hSystem, FNIO_POINTER pDeviceInfo, FNIO_VALUE DeviceType, FNIO_HANDLE *phDevice);
FNIO_ERROR	FNIO_CALLTYPE	DevCloseDevice			(FNIO_HANDLE hDevice);
FNIO_ERROR  FNIO_CALLTYPE	DevGetParam				(FNIO_HANDLE hDevice, FNIO_DEV_CMD Cmd, FNIO_DATA_INFO Info, FNIO_POINTER pData, FNIO_VALUE* pDataSize);
FNIO_ERROR  FNIO_CALLTYPE	DevSetParam				(FNIO_HANDLE hDevice, FNIO_DEV_CMD Cmd, FNIO_POINTER pData, FNIO_VALUE* pDataSize);
FNIO_ERROR  FNIO_CALLTYPE	DevIoUpdateStart		(FNIO_HANDLE hDevice);
FNIO_ERROR  FNIO_CALLTYPE	DevIoUpdateStop			(FNIO_HANDLE hDevice);
FNIO_ERROR	FNIO_CALLTYPE	DevReadInputImage		(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_POINTER pBuffer, FNIO_VALUE Len);
FNIO_ERROR	FNIO_CALLTYPE	DevReadOutputImage		(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_POINTER pBuffer, FNIO_VALUE Len);
FNIO_ERROR	FNIO_CALLTYPE	DevWriteOutputImage		(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_POINTER pBuffer, FNIO_VALUE Len);
FNIO_ERROR	FNIO_CALLTYPE	DevReadInputImageBit	(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_VALUE BitIndex, FNIO_VALUE* pBitData);
FNIO_ERROR	FNIO_CALLTYPE	DevReadOutputImageBit	(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_VALUE BitIndex, FNIO_VALUE* pBitData);
FNIO_ERROR	FNIO_CALLTYPE	DevWriteOutputImageBit	(FNIO_HANDLE hDevice, FNIO_VALUE Addr, FNIO_VALUE BitIndex, FNIO_VALUE BitData);

//
// IoModule functions
//
FNIO_ERROR	FNIO_CALLTYPE	IoGetIoModule			(FNIO_HANDLE hDevice, FNIO_VALUE SlotIndex, FNIO_HANDLE* phSlot);
FNIO_ERROR	FNIO_CALLTYPE	IoGetParam				(FNIO_HANDLE hSlot, FNIO_IO_CMD Cmd, FNIO_DATA_INFO Info, FNIO_POINTER pData, FNIO_VALUE* pDataSize);
FNIO_ERROR  FNIO_CALLTYPE	IoSetParam				(FNIO_HANDLE hSlot, FNIO_IO_CMD Cmd, FNIO_POINTER pData, FNIO_VALUE* pDataSize);


///////////////////////////////////////////////////////////////////////////////////////////////
//
// Old interface (Ver0.3.0.9)
//
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////
//	Using OpenDevice 
typedef struct tagDEVICEINFOMODBUSTCP
{
	unsigned char	IpAddress[4];
	int				PortNum;
	unsigned int	InputSize;
	unsigned int	OutputSize;
} DEVICEINFOMODBUSTCP;
/////////////////////////////////////////

// Modbus Response Code ------------------------------------------------------------------------
#define NORMAL_RESPONSE								0
#define CONNECTION_FAIL								-1
#define MAX_CONNECTION_EXCEEDED						-2
#define ILLEGAL_DEVICE_TYPE							-3

#define ILLEGAL_FUNCTION							1	
#define ILLEGAL_DATA_ADDRESS						2	
#define ILLEGAL_DATA_VALUE							3	
#define SLAVE_DEVICE_FAILURE						4	
#define ACKNOWLEDGE									5	
#define SLAVE_DEVICE_BUSY							6	
#define MEMORY_PARITY_ERROR							8	
#define GATEWAY_PATH_UNAVAILABLE					10	
#define GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND		11	

#define ILLEGAL_RESPONSE							14	
#define ILLEGAL_TRANSACTION_ID						15	
#define TIMEOUT_RESPONSE							16	
#define NOT_CONNECT									17	
#define ILLEGAL_HANDLE								18	
#define ILLEGAL_PROTOCOL_TYPE						19	
#define NETWORK_IS_BUSY								20	

int	__stdcall	InitSystem();
int	__stdcall	FreeSystem();
int	__stdcall	OpenDevice(unsigned int *pDevice, void* pOpenDevInfo, int DeviceType);
int	__stdcall	CloseDevice(unsigned int hDevice);
int	__stdcall	ReadInputByteData(unsigned int hDevice, unsigned short addr, unsigned char *buffer, unsigned short len);
int	__stdcall	ReadOutputByteData(unsigned int hDevice, unsigned short addr, unsigned char *buffer, unsigned short len);
int	__stdcall	WriteOutputByteData(unsigned int hDevice, unsigned short addr, unsigned char *buffer, unsigned short len);
int	__stdcall	ReadDeviceStatus(unsigned int hDevice, unsigned char *statusdata);

}

#endif