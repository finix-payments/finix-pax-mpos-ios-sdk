/*
 * ******************************************************************************
 * COPYRIGHT
 *               PAX TECHNOLOGY, Inc. PROPRIETARY INFORMATION
 *   This software is supplied under the terms of a license agreement or
 *   nondisclosure agreement with PAX  Technology, Inc. and may not be copied
 *   or disclosed except in accordance with the terms in that agreement.
 *
 *      Copyright (C) 2017 PAX Technology, Inc. All rights reserved.
 * ******************************************************************************
 */

#ifndef __SL_SMART_LANDING_H
#define __SL_SMART_LANDING_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef void (*SL_PFUN_DOWNLOAD_CB) 
(
	/*
	* name of component task file
	*/
	char *componentName,

	/*
	* total size of component task file, unit byte
	*/
	int totalSize,

	/*
	* downloaded size of component task file, unit byte
	*/
	int downloadedSize,

	/*
	* code for download status
	* 0: is downloading — current file
	* 1: dowload succeeded — current file
	* 2: download succeeded — all files
	*-2: download failed — need to report
	*-3: download failed — can retry
	*-4: download failed — platform error
	*-1: download failed — other error
	*/
	int code,

	/*
	* message for download status
	*/
	char *message
);

typedef enum
{
	SL_COMM_LAN = 0x01,
	SL_COMM_WIFI,
	SL_COMM_MODEM,
	SL_COMM_GPRS_OR_CDMA,
	SL_COMM_SERIAL_PORT
} SL_COMM_MODE;

typedef enum
{ 
	SL_LOG_TRACE = 0X00,
	SL_LOG_DEBUG,
	SL_LOG_INFO,
	SL_LOG_WARN,
	SL_LOG_ERROR,
	SL_LOG_OFF
} SL_LOG_LEVEL;

typedef struct
{
	/*
	* terminal id, used to activate the terminal
	*/
	char tid[64];

	struct
	{
		/*
		* domain name of SmartLanding Platform
		*/
		char hostName[64];

		/*
		* port of SmartLanding Platform, is usually 6370
		*/
		int port;
	} server;

	struct
	{
		/*
		* communication mode
		*/
		SL_COMM_MODE mode;

		/*
		* Timeout of network communication, including dns and connect, send, recv of SSL. Pay 
		* attention to the 3 reconnection mechanism of the network communication in the SDK, 
		* the actual effect of timeout is multiplied by 3. In addition, the real effect of 
		* timeout also depends on whether the DNS API and SSL library of the terminal OS support 
		* setting timeout.
		*/
		int timeout;
	} comm;

	struct
	{
		/*
		* callback function for downloading task files
		*/
		SL_PFUN_DOWNLOAD_CB callback;

		/*
		* maximum number of retries to download task files
		*/
		int retryMax;
	} download;

	/*
	* log level
	*/
	SL_LOG_LEVEL logLevel;

	/*
	* Maximum buffer size of task list, unit KB. It is related to the task list size of the install 
	* task package in PAXSTORE, generally a component task occupies 1K. If the memory space of the 
	* terminal is sufficien, such as Prolin, it is recommended to set it to 16, otherwise set to 5 
	* to 10.
	*/
	int maxTaskSize;

	/*
	* Maximum buff size of an tcp package, unit KB. The maximum upper limit is 16, smaller values 
	* will affect the speed of downloading task files. If the memory space of the terminal is 
	* sufficien, such as Prolin, set to 16, if the memory resources are limited, such as Runthos, 
	* set to 8 empirically.
	*/
	int maxTcpReqSize;
} SL_Param;

/***************************************************************************************************************
 * Function:    SL_GetVer
 * Description: Get the SDK version
 * Input:       None
 * Output:      out: the SDK version, such as "2.0.0", buffer length must >= 16
 * Return:      None
 * Notice:      None
***************************************************************************************************************/
void SL_GetVer(char *out);

/***************************************************************************************************************
 * Function:    SL_Init
 * Description: Init the SDK, must be fist called when using the SDK
 * Input:       param: parameters for initialization
 * Output:      None
 * Return:      0: success
 *             -1: fail
 * Notice:      “SL_Init” is usually called only once, unless the parameters change
***************************************************************************************************************/
int SL_Init(SL_Param *param);

/***************************************************************************************************************
 * Function:    SL_Sync
 * Description: Synchronize the task from SmartLanding Platform, including querying the task, downloading task 
 *              files if the task type is install
 * Input:       None
 * Output:      None
 * Return:      0: no task — PAXSTORE has no task
 *              1: uninstall — PAXSTORE pushed an uninstall task
 *              2: rki — PAXSTORE pushed a rki task
 *              3: install and is downloading — PAXSTORE pushed an install task and the SDK is downloading task 
 *                 files — only for the terminal supports multithreading
 *              4: install — a) and starts downloading — PAXSTORE pushed an install task and the SDK starts 
 *                              downloading task files — for the terminal supports multithreading
 *                           b) and downloading finished — PAXSTORE pushed an install task and the SDK has 
 *                              finished downloading task files — for the terminal does not support multithreading
 *              5: task already exists — the last synchronized task has not been handled, do “SL_Handle” first
 *            -99: need tid — the terminal is not activated in PAXSTORE
 *           -100: lock — SmartLanding Platform is not accessible at the current time
 *             -1: fail
 * Notice:      The Prolin system terminal supports multithreading, the Monitor system terminal does not support 
 *              multithreading, and the Runthos system terminal is considered not to support multithreading while 
 *              using Smartlanding SDK.
 *              When “SL_Sync()” returns 3, Smartlanding SDK has created a sub thread to download task files, which 
 *              is in progress asynchrony. You need to use the callback function “SL_PFUN_DOWNLOAD_CB” to track 
 *              the download progress.
 *              When “SL_Sync()” returns 4, download task files has ended, and the download may succeed or fail. 
 *              You need to use the function “SL_PFUN_DOWNLOAD_CB” to get the download result.
***************************************************************************************************************/
int SL_Sync();

/***************************************************************************************************************
 * Function:    SL_Stop
 * Description: Stop downloading while the SDK is downloading task files — only for the terminal supports 
 *              multithreading
 * Input:       None
 * Output:      None
 * Return:      0: success
 *             -1: fail
 * Notice:      None
***************************************************************************************************************/
int SL_Stop();

/***************************************************************************************************************
 * Function:    SL_Handle
 * Description: Handle synchronized task, including performing install, uninstall or RKI task, and then reporting 
 *              task results to SmartLanding Platform, usually is used after “SL_Sync”
 * Input:       None
 * Output:      None
 * Return:      0: no task — there is no synchronized task to handle
 *              1: is downloading — the SDK is downloading task files, please wait — correspond to last “SL_Sync” 
 *                 returned 4 and the asynchronous download is still in progress — just for the terminal supports 
 *                 multithreading
 *              2: download incomplete — the SDK download task files stopped or failed, use “SL_Sync” to continue 
 *                 or retry the download — usually occurred in these scenarios: called “SL_Stop” while downloading; 
 *                 power off while downloading; a network error occurred but can retry while downloading and so on
 *              3: perform task success and report success
 *              4: perform task fail and report success
 *             -1: fail
 * Notice:     None
***************************************************************************************************************/
int SL_Handle();

/***************************************************************************************************************
 * Function:    SL_GetErrCode
 * Description: When the SDK API return -1, use “SL_GetErrCode” to get specific error code
 * Input:       None
 * Output:      code: error code, range is -1000 to -9999
 * Return:      None
 * Notice:      None
***************************************************************************************************************/
void SL_GetErrCode(int *code);

/***************************************************************************************************************
 * Function:    SL_GetErrMsg
 * Description: When the SDK API return -1, use “SL_GetErrMsg” to get specific error message
 * Input:       None
 * Output:      out: error message, buffer length must >= 256
 * Return:      None
 * Notice:      None
***************************************************************************************************************/
void SL_GetErrMsg(char *out);

#ifdef __cplusplus
}
#endif
#endif // __SL_SMART_LANDING_H
