
#ifndef DHNETSDK_H
#define DHNETSDK_H

#include "../dahua-defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** Interface Definition 
 ***********************************************************************/

// SDK Initialization 
CLIENT_API BOOL CALL_METHOD CLIENT_Init(fDisConnect cbDisConnect, LDWORD dwUser);

// SDK exit and clear
CLIENT_API void CALL_METHOD CLIENT_Cleanup();

//------------------------------------------------------------------------

// Set re-connection callback function after disconnection. Internal SDK  auto connect again after disconnection 
CLIENT_API void CALL_METHOD CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, LDWORD dwUser);

// Dynamic sub-set link disconnected callback function, the current monitoring and playback equipment SVR is a short connection
CLIENT_API void CALL_METHOD CLIENT_SetSubconnCallBack(fSubDisConnect cbSubDisConnect, LDWORD dwUser);

// Return the function execution failure code
CLIENT_API DWORD CALL_METHOD CLIENT_GetLastError(void);

// Set device connection timeout value and trial times 
CLIENT_API void CALL_METHOD CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);

// Set log in network environment 
CLIENT_API void CALL_METHOD CLIENT_SetNetworkParam(NET_PARAM *pNetParam);

// Get SDK version information 
CLIENT_API DWORD CALL_METHOD CLIENT_GetSDKVersion();

//------------------------------------------------------------------------

// Register to the device 
CLIENT_API LLONG CALL_METHOD CLIENT_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Expension interfacenSpecCap =0 is login under TCP mode, nSpecCap =2 is login with active registeration, nSpecCap =3 is login under multicast mode,
//			 nSpecCap =4 is login under UDP mode, nSpecCap =6 is login with main connection,nSpecCap =7 is SSL encription
//			  ,nSpecCap =8 is Chengdu Jiafa login
//			 nSpecCap=9 is login in to remote device, enter void* pCapParam as remote device name
//          nSpecCap = 12 is login under LDAP mode
//          nSpecCap = 13 is login under AD mode
//           nSpecCap = 14 is Radius login 
//             nSpecCap = 15 is Socks5 login??now void* pCapParam fill in Socks5 server IP&&port&&ServerName&&ServerPassword string
//             nSpecCap = 16 is proxy login??now void* pCapParam fill in SOCKET value
//             nSpecCap = 19 is web privatepenestrating login
//             nSpecCap = 20 mobile phone client login
CLIENT_API LLONG CALL_METHOD CLIENT_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Login extension interface
CLIENT_API LLONG CALL_METHOD CLIENT_LoginEx2(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, EM_LOGIN_SPAC_CAP_TYPE emSpecCap, void* pCapParam, LPNET_DEVICEINFO_Ex lpDeviceInfo, int *error = 0);

// Asynchronism login device 
// nSpecCap = 0 TCP login,nSpecCap = 6 only main connect login
// nSpecCap = 19 is private penestrating login
CLIENT_API LLONG CALL_METHOD CLIENT_StartLogin(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, fHaveLogin cbLogin, LDWORD dwUser);

// Only when CLIENT_StartLogin () callback errors for 11 when asynchronous log in using the interface to continue
CLIENT_API LLONG CALL_METHOD CLIENT_StartLoginEx(NET_IN_STARTLOGINEX* pInParam, NET_OUT_STARTLOGINEX* pOutParam);

// stop login
CLIENT_API BOOL CALL_METHOD CLIENT_StopLogin(LLONG lLoginID);

CLIENT_API BOOL CALL_METHOD CLIENT_StopLoginEx(LLONG lLoginID);

// Log out the device 
CLIENT_API BOOL CALL_METHOD CLIENT_Logout(LLONG lLoginID);


//------------------------------------------------------------------------

// Begin real-time monitor 
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlay(LLONG lLoginID, int nChannelID, HWND hWnd);

// Begin real-time monitor--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlayEx(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType = DH_RType_Realplay);

//start real-time monitor
CLIENT_API LLONG CALL_METHOD CLIENT_StartRealPlay(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType, fRealDataCallBackEx cbRealData, fRealPlayDisConnect cbDisconnect, LDWORD dwUser, DWORD dwWaitTime = 10000);

// Multiple-window preview 
CLIENT_API LLONG CALL_METHOD CLIENT_MultiPlay(LLONG lLoginID, HWND hWnd);

// Stop multiple-window preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopMultiPlay(LLONG lMultiHandle);

// Snapshot;hPlayHandle is monitor or playback handle
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePicture(LLONG hPlayHandle, const char *pchPicFileName);
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePictureEx(LLONG hPlayHandle, const char *pchPicFileName, NET_CAPTURE_FORMATS eFormat);

// Set real-time monitor data callback 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBack(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser);

// Set real-time monitor data callback--extensive 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBackEx(LLONG lRealHandle, fRealDataCallBackEx cbRealData, LDWORD dwUser, DWORD dwFlag);

// Set video fluency
CLIENT_API BOOL	CALL_METHOD CLIENT_AdjustFluency(LLONG lRealHandle, int nLevel);

// Save data as file
CLIENT_API BOOL CALL_METHOD CLIENT_SaveRealData(LLONG lRealHandle, const char *pchFileName);

// Stop saving data as file 
CLIENT_API BOOL CALL_METHOD CLIENT_StopSaveRealData(LLONG lRealHandle);

// Set video property
CLIENT_API BOOL CALL_METHOD CLIENT_ClientSetVideoEffect(LLONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// Get video property 
CLIENT_API BOOL CALL_METHOD CLIENT_ClientGetVideoEffect(LLONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// Set screen overlay callback 
CLIENT_API void CALL_METHOD CLIENT_RigisterDrawFun(fDrawCallBack cbDraw, LDWORD dwUser);

// Open audio 
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSound(LLONG hPlayHandle);

// Set volume;lPlayHandle is monitor handle or playabck handle 
CLIENT_API BOOL CALL_METHOD CLIENT_SetVolume(LLONG lPlayHandle, int nVolume);

// If use HD iamge internal adjustment strategy??enable by default. This strategy is used, when quick play x4 and higher, only play 1 frame, When disable, play every frame. 
CLIENT_API BOOL CALL_METHOD CLIENT_PlayEnableLargePicAdjustment(LLONG lPlayHandle, BOOL bEnable);

// Stop audio 
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSound();

// Stop real-time preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlay(LLONG lRealHandle);

// stop real-time preview-extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlayEx(LLONG lRealHandle);

//------------------------------------------------------------------------

// general PTZ control
CLIENT_API BOOL CALL_METHOD CLIENT_PTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// Private PTZ control 
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop,void* param4=NULL);

//  private PTZ control extensive port. support 3D intelligent position
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControlEx(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

// private PTZ control expansion port ??support 3D quick positioning, Fish eye 
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControlEx2(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop , void* param4 = NULL);

//------------------------------------------------------------------------
// query record state everyday in the month
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordStatus(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmMonth, char* pchCardid, LPNET_RECORD_STATUS pRecordStatus, int waittime=1000);

// Search whether there is recorded file in specified period
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);

// Search all recorded file sin the specified periods
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// Async search period all record files
CLIENT_API BOOL CALL_METHOD CLIENT_StartQueryRecordFile(LLONG lLoginID, NET_IN_START_QUERY_RECORDFILE *pInParam, NET_OUT_START_QUERY_RECORDFILE *pOutParam);

// search first 16 records
CLIENT_API BOOL CALL_METHOD CLIENT_QuickQueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);


// Query the first record time 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryFurthestRecordTime(LLONG lLoginID, int nRecordFileType, char *pchCardid, NET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// Begin searching recorded file
CLIENT_API LLONG	CALL_METHOD CLIENT_FindFile(LLONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPNET_TIME time_start, LPNET_TIME time_end, BOOL bTime, int waittime);

// Search recorded file 
CLIENT_API int	CALL_METHOD CLIENT_FindNextFile(LLONG lFindHandle,LPNET_RECORDFILE_INFO lpFindData);

// Stop searching recorded file 
CLIENT_API BOOL CALL_METHOD CLIENT_FindClose(LLONG lFindHandle);

// Playback in file 
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// Playback in file--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFileEx(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// playback in file - disconnect callback
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByRecordFile(LLONG lLoginID,  LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
															 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
															 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
															 fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//Playback in file--Drop frame playback (not enough bandwidth can be used)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
																   fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
																   fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

// Playback in time
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser);

// Playback in time--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTimeEx(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
													 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
													 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);
													 
// Playback by time, support playback by direction compare to the old version
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTimeEx2(LLONG lLoginID, int nChannelID, 
                        NET_IN_PLAY_BACK_BY_TIME_INFO *pstNetIn, NET_OUT_PLAY_BACK_BY_TIME_INFO *pstNetOut);

// playback in time--disconnect callback
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByTime(LLONG lLoginID, int nChannelID, 
													   LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
													   fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser,
													   fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
													   fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//Playback in time--Drop frame playback (not enough bandwidth can be used)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
															 fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
															 fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

//playback by synopsis file
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackBySynopsisFile(LLONG lLoginID, 
															LPNET_SYNOPSISFILE_INFO lpRecordFile, 
															HWND hWnd, 
															fDownLoadPosCallBack cbDownLoadPos,
															LDWORD dwPosUser, 
															fDataCallBack fDownLoadDataCallBack,
															LDWORD dwDataUser,
															LDWORD dwUser);

// multi-channel preview palyabck
CLIENT_API LLONG CALL_METHOD CLIENT_MultiPlayBack(LLONG lLoginID, NET_MULTI_PLAYBACK_PARAM *pParam);

// position record playback initial point
CLIENT_API BOOL CALL_METHOD CLIENT_SeekPlayBack(LLONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// Pause or restore file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_PausePlayBack(LLONG lPlayHandle, BOOL bPause);

// Fast playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_FastPlayBack(LLONG lPlayHandle);

// Slow playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_SlowPlayBack(LLONG lPlayHandle);

// Step playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_StepPlayBack(LLONG lPlayHandle, BOOL bStop);

// Control playback direction--Forward or Backward playback
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControlDirection(LLONG lPlayHandle, BOOL bBackward);

// Set playback frame rate 
CLIENT_API BOOL CALL_METHOD CLIENT_SetFramePlayBack(LLONG lPlayHandle, int framerate);

// Get playback frame rate
CLIENT_API BOOL CALL_METHOD CLIENT_GetFramePlayBack(LLONG lPlayHandle, int *fileframerate, int *playframerate);

// Restore ordinary playback
CLIENT_API BOOL CALL_METHOD CLIENT_NormalPlayBack(LLONG lPlayHandle);

// smart search play back
CLIENT_API BOOL CALL_METHOD CLIENT_SmartSearchPlayBack(LLONG lPlayHandle, LPIntelligentSearchPlay lpPlayBackParam);

// Get playback OSD time 
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlayBackOsdTime(LLONG lPlayHandle, LPNET_TIME lpOsdTime, LPNET_TIME lpStartTime, LPNET_TIME lpEndTime);

// Stop file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_StopPlayBack(LLONG lPlayHandle);

// Download recorded file 
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByRecordFile(LLONG lLoginID,LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// Download video files - extension
// sSavedFileName Is not null, video data written to the corresponding file path; fDownLoadDataCallBack Is not null, video data through the callback function returns 
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByRecordFileEx(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, 
                                                           fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData, 
                                                           fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, void* pReserved = NULL);

// Download file by time 
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, fTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData);

// Through the time to download the video - extension
// sSavedFileName Is not null, video data written to the corresponding file path; fDownLoadDataCallBack Is not null, video data through the callback function returns
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByTimeEx(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, 
                                                     fTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData, 
                                                     fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, void* pReserved = NULL);

// Search record download process 
CLIENT_API BOOL CALL_METHOD CLIENT_GetDownloadPos(LLONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// Stop record download 
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownload(LLONG lFileHandle);

//partial enlarged
CLIENT_API BOOL CALL_METHOD CLIENT_SetDisplayRegion(LLONG lPlayHandle,DWORD nRegionNum, DH_DISPLAYRREGION *pSrcRect, HWND hDestWnd, BOOL bEnable);

// start to search record file frame info
CLIENT_API BOOL    CALL_METHOD CLIENT_FindFrameInfo(LLONG lLoginID, NET_IN_FIND_FRAMEINFO_PRAM *pInParam, NET_OUT_FIND_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// search record file frame info, search by specified info item
CLIENT_API BOOL    CALL_METHOD CLIENT_FindNextFrameInfo(LLONG lFindHandle, NET_IN_FINDNEXT_FRAMEINFO_PRAM *pInParam, NET_OUT_FINDNEXT_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// end record file search
CLIENT_API BOOL CALL_METHOD CLIENT_FindFrameInfoClose(LLONG lFindHandle);

//------------------------------------------------------------------------

// Set alarm callback function 
CLIENT_API void CALL_METHOD CLIENT_SetDVRMessCallBack(fMessCallBack cbMessage,LDWORD dwUser);

CLIENT_API void CALL_METHOD CLIENT_SetDVRMessCallBackEx1(fMessCallBackEx1 cbMessage,LDWORD dwUser);


// subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StartListen(LLONG lLoginID);

// subscribe alarm---extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StartListenEx(LLONG lLoginID);

// Stop subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StopListen(LLONG lLoginID);

// alarm reset
CLIENT_API BOOL CALL_METHOD CLIENT_AlarmReset(LLONG lLoginID, DWORD dwAlarmType, int nChannel, void* pReserved = NULL, int nWaitTime = 1000);

//------------------------------------------------------------------------

// actively registration function. enable service. nTimeout is invalid. 
CLIENT_API LLONG CALL_METHOD CLIENT_ListenServer(char* ip, WORD port, int nTimeout, fServiceCallBack cbListen, LDWORD dwUserData);

// stop service
CLIENT_API BOOL CALL_METHOD CLIENT_StopListenServer(LLONG lServerHandle);

// Respond the registration requestion from the device 
CLIENT_API BOOL CALL_METHOD CLIENT_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// Alarm upload function. Enable service. dwTimeOut paramter is invalid 
CLIENT_API LLONG CALL_METHOD CLIENT_StartService(WORD wPort, char *pIp = NULL, fServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, LDWORD dwUserData = 0);

// Stop service 
CLIENT_API BOOL CALL_METHOD CLIENT_StopService(LLONG lHandle);

//------------------------------------------------------------------------

// Set audio talk mode(client-end mode or server mode)
CLIENT_API BOOL CALL_METHOD CLIENT_SetDeviceMode(LLONG lLoginID, EM_USEDEV_MODE emType, void* pValue);

// Enable audio talk 
CLIENT_API LLONG CALL_METHOD CLIENT_StartTalkEx(LLONG lLoginID, pfAudioDataCallBack pfcb, LDWORD dwUser);

// Begin PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStart();

// Stop PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStop();


// start PC record(to CLIENT_RecordStart()extend)
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStartEx(LLONG lLoginID);

// end PC record(to CLIENT_RecordStop() extend)
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStopEx(LLONG lLoginID);


// Send out audio data to the device 
CLIENT_API LONG CALL_METHOD CLIENT_TalkSendData(LLONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// Decode audio data 
CLIENT_API void CALL_METHOD CLIENT_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);
CLIENT_API BOOL CALL_METHOD CLIENT_AudioDecEx(LLONG lTalkHandle, char *pAudioDataBuf, DWORD dwBufSize);

// Set audio talk volume
CLIENT_API BOOL CALL_METHOD CLIENT_SetAudioClientVolume(LLONG lTalkHandle, WORD wVolume);

// Stop audio talk 
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalkEx(LLONG lTalkHandle);

// add device into broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastAddDev(LLONG lLoginID);

// Remove device from the broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastDelDev(LLONG lLoginID);

// audio encode-initialization(specified standard format, private format)
CLIENT_API int  CALL_METHOD CLIENT_InitAudioEncode(DH_AUDIO_FORMAT aft);

// Audio encode--data encode
CLIENT_API int	CALL_METHOD	CLIENT_AudioEncode(LLONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// audio encode--complete and then exit
CLIENT_API int	CALL_METHOD	CLIENT_ReleaseAudioEncode();

//------------------------------------------------------------------------

// Search device log
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLog(LLONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// Search device log page by page.
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceLog(LLONG lLoginID, QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// search device log item
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevLogCount(LLONG lLoginID, NET_IN_GETCOUNT_LOG_PARAM *pInParam, NET_OUT_GETCOUNT_LOG_PARAM* pOutParam , int waittime=3000);

// Search channel record status 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// Search channel extra record status (the returned byte number was equal to the channel number, every byte instruct the respond channel's state,0-stop,1-manual,2-schedule)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryExtraRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, void *pReserved, int waittime=1000);

// Search device status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevState(LLONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// query remote device state,when nType = DH_DEVSTATE_ALARM_FRONTDISCONNECT,the number form 1.
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRemotDevState(LLONG lLoginID, int nType, int nChannelID, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// Search system capacity information 
CLIENT_API BOOL CALL_METHOD CLIENT_QuerySystemInfo(LLONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// New Search system capacity information(by Json)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNewSystemInfo(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1000);

// Get channel bit stream 
CLIENT_API LONG CALL_METHOD CLIENT_GetStatiscFlux(LLONG lLoginID, LLONG lPlayHandle);

// Get PTZ information 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetPtzOptAttr(LLONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

// search device info
CLIENT_API BOOL  CALL_METHOD CLIENT_QueryDevInfo(LLONG lLoginID, int nQueryType, void* pInBuf, void* pOutBuf, void *pReserved = NULL , int nWaitTime = 1000);
//------------------------------------------------------------------------

// Reboot device 
CLIENT_API BOOL CALL_METHOD CLIENT_RebootDev(LLONG lLoginID);

// Shut down devic e
CLIENT_API BOOL CALL_METHOD CLIENT_ShutDownDev(LLONG lLoginID);

// Device control 
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDevice(LLONG lLoginID, CtrlType type, void *param, int waittime = 1000);

// Set channel record status 
CLIENT_API BOOL CALL_METHOD CLIENT_SetupRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// set channel extra record status
CLIENT_API BOOL CALL_METHOD CLIENT_SetupExtraRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen, void* pReserved);

// Search IO status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryIOControlState(LLONG lLoginID, DH_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO control 
CLIENT_API BOOL CALL_METHOD CLIENT_IOControl(LLONG lLoginID, DH_IOTYPE emType, void *pState, int maxlen);

// Compulsive I frame
CLIENT_API BOOL CALL_METHOD CLIENT_MakeKeyFrame(LLONG lLoginID, int nChannelID, int nSubChannel=0);

// public agency registration
typedef void (CALLBACK *fConnectMessCallBack)(LLONG lConnectHandle, NET_CLOUDSERVICE_CONNECT_RESULT* pConnectResult, void* pReserved, LDWORD dwUser);

CLIENT_API LLONG CALL_METHOD CLIENT_ConnectCloudService(LLONG lLoginID, NET_CLOUDSERVICE_CONNECT_PARAM* pConnectParm, fConnectMessCallBack pConnectMessCB, LDWORD dwUser, void* pReserved);
//------------------------------------------------------------------------

// Search user information 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfo(LLONG lLoginID, USER_MANAGE_INFO *info, int waittime=1000);

// Search user information--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoEx(LLONG lLoginID, USER_MANAGE_INFO_EX *info, int waittime=1000);

// Search device info--Max supports device of 64-ch
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoNew(LLONG lLoginID, USER_MANAGE_INFO_NEW *info, void* pReserved, int waittime = 1000);
// Device operation user 
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfo(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// Device operation user--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoEx(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// User operates the device--Max supports device of 64-ch
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoNew(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, void* pReserved, int waittime = 1000);

//------------------------------------------------------------------------

// Create transparent COM channel ,TransComType: high 2 bytes represent the serial number,low 2 bytes of serail type,type 0: serial,1:485
CLIENT_API LLONG CALL_METHOD CLIENT_CreateTransComChannel(LLONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fTransComCallBack cbTransCom, LDWORD dwUser);

// Transparent COM send out data 
CLIENT_API BOOL CALL_METHOD CLIENT_SendTransComData(LLONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// Release transparent COM channel 
CLIENT_API BOOL CALL_METHOD CLIENT_DestroyTransComChannel(LLONG lTransComChannel);

// Query the status of a transparent serial port
CLIENT_API BOOL CALL_METHOD CLIENT_QueryTransComParams(LLONG lLoginID, int TransComType, DH_COMM_STATE* pCommState, int nWaitTime = 500);

//------------------------------------------------------------------------

// Begin upgrading device program 
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgrade(LLONG lLoginID, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// Begin upgrading device program--extensive
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgradeEx(LLONG lLoginID, EM_UPGRADE_TYPE emType, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// Send out data
CLIENT_API BOOL CALL_METHOD CLIENT_SendUpgrade(LLONG lUpgradeID);

// Stop upgrading device program 
CLIENT_API BOOL CALL_METHOD CLIENT_StopUpgrade(LLONG lUpgradeID);

//------------------------------------------------------------------------

// Search configuration information 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// Set configuration information 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// New configuration interface, Search configuration information(using Json protocol, see configuration SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_GetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// New configuration interface, Set configuration information(using Json protocol, see configuration SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_SetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// Delete configuration interface(Json format)
CLIENT_API BOOL CALL_METHOD CLIENT_DeleteDevConfig(LLONG lLoginID, NET_IN_DELETECFG* pInParam, NET_OUT_DELETECFG* pOutParam, int waittime=500);

// Get the configuration member name interface(Json format)
CLIENT_API BOOL CALL_METHOD CLIENT_GetMemberNames(LLONG lLoginID, NET_IN_MEMBERNAME* pInParam, NET_OUT_MEMBERNAME* pOutParam, int waittime=500);

// get net card info
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNetStat(LLONG lLoginID , EM_NET_QUERY_TYPE emType , void *lpInParam , int nInParamLen , void *lpOutParam , int nOutParamLen , int *pError = NULL , int nWaitTime=1000);

//------------------------------------------------------------------------

// Search device channel name 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryChannelName(LLONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// Set device channel name
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelName(LLONG lLoginID,char *pbuf, int nbuflen);

// Set device channel character overlay 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelOsdString(LLONG lLoginID, int nChannelNo, DH_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// Search device current time
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime, int waittime=1000);

// Set device current time
CLIENT_API BOOL CALL_METHOD CLIENT_SetupDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime);

// Set device max bit stream
CLIENT_API BOOL CALL_METHOD CLIENT_SetMaxFlux(LLONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// Import configuration file 
CLIENT_API LLONG CALL_METHOD CLIENT_ImportConfigFile(LLONG lLoginID, char *szFileName, fDownLoadPosCallBack cbUploadPos, LDWORD dwUserData, DWORD param=0);

// Stop importing configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopImportCfgFile(LLONG lImportHandle);

// Exporting configuration file
CLIENT_API LLONG CALL_METHOD CLIENT_ExportConfigFile(LLONG lLoginID, DH_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// top exporting configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopExportCfgFile(LLONG lExportHandle);

//------------------------------------------------------------------------

// Search device IP in DDBS by device name or device serial number
CLIENT_API BOOL CALL_METHOD CLIENT_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// Search IPC,NVS and etc in LAN 
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime, char* szLocalIp=NULL);

// asynchronism search IPC, NVS and etc in LAN
CLIENT_API LLONG CALL_METHOD CLIENT_StartSearchDevices(fSearchDevicesCB cbSearchDevices, void* pUserData, char* szLocalIp=NULL);

// stop asynchronism search IPC, NVS and etc in LAN
CLIENT_API BOOL CALL_METHOD CLIENT_StopSearchDevices(LLONG lSearchHandle);

// modify Device ip
CLIENT_API BOOL CALL_METHOD CLIENT_ModifyDevice(DEVICE_NET_INFO_EX *pDevNetInfo, DWORD dwWaitTime, int *iError = NULL, char* szLocalIp = NULL, void *reserved = NULL);

// search device ip cross VLAN
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevicesByIPs(DEVICE_IP_SEARCH_INFO* pIpSearchInfo, fSearchDevicesCB cbSearchDevices, LDWORD dwUserData, char* szLocalIp, DWORD dwWaitTime);
//------------------------------------------------------------------------

// Platform embedded interface
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// control focus 
//	dwFocusCommand = 0 focus adjucy
//	dwFocusCommand = 1continuous focus adjustment
//	dwFocusCommand = 2 auto adjust ,adjust to the best position,nFocus and nZoominvalid
CLIENT_API BOOL CALL_METHOD CLIENT_FocusControl(LLONG lLoginID, int nChannelID, DWORD dwFocusCommand, double nFocus, double nZoom, void *reserved = NULL, int waittime=500);

///////////////////////////////Mobile DVR interface///////////////////////////////

// Set snapshot callback function 
CLIENT_API void CALL_METHOD CLIENT_SetSnapRevCallBack(fSnapRev OnSnapRevMessage, LDWORD dwUser);

// Snapshot request
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPicture(LLONG lLoginID, SNAP_PARAMS par);

// Snapshot request--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPictureEx(LLONG lLoginID, SNAP_PARAMS *par, int *reserved = 0);

// Set GPS subscription callback function 
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBack(fGPSRev OnGPSMessage, LDWORD dwUser);

// Set GPS subscription callback function - extensive
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBackEX(fGPSRevEx OnGPSMessage, LDWORD dwUser);

// GPS message subscription 
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPS (LLONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);

// Set GPS subscription of temperature and humidity callback function
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSTHCallBack(fGPSTempHumidityRev OnGPSMessage, LDWORD dwUser);

// GPS subscription of temperature and humidity
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPSTempHumidity (LLONG lLoginID, BOOL bStart,	int InterTime, void* Reserved);

//GPS log query
CLIENT_API BOOL CALL_METHOD CLIENT_QueryGPSLog(LLONG lLoginID,QUERY_GPS_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, BOOL *bContinue, int waittime);

// subscription task
CLIENT_API BOOL CALL_METHOD CLIENT_AttachMission(LLONG lLoginID, NET_IN_ATTACH_MISSION_PARAM *pInParam, NET_OUT_ATTACH_MISSION_PARAM *pOutParam, int nWaitTime);

// cancen subscription
CLIENT_API BOOL CALL_METHOD CLIENT_DetachMission(LLONG lAttachHandle);

// vehicle emergency alarm confirm
CLIENT_API BOOL CALL_METHOD CLIENT_BusConfirmEvent(LLONG lLoginID, const NET_IN_BUS_CONFIRM_EVENT* pInParam, NET_OUT_BUS_CONFIRM_EVENT* pOutParam, int nWaitTime = 3000);

//////////////////////////////NVD interface//////////////////////////////

// Query decoder information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderInfo(LLONG lLoginID, LPDEV_DECODER_INFO lpDecInfo, int waittime=1000);

// Query decoder TV information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTVInfo(LLONG lLoginID, int nMonitorID, LPDEV_DECODER_TV lpMonitorInfo, int waittime=1000);

// Query decoder channel information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecEncoderInfo(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, int waittime=1000);

// Set decoder TV enable
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecTVOutEnable(LLONG lLoginID, BYTE *pDecTVOutEnable, int nBufLen, int waittime=1000);

// set decoder tip layout enable, channel number start at 0
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecLayOutEnable(LLONG lLoginID, BYTE bDecLayOutEnable, int nChannel, int waittime=1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetDecLayOutEnable(LLONG lLoginID, BYTE *pDecLayOutEnable, int nChannel, int waittime=1000);
//------------------------------------------------------------------------

// Set up asynchronous callback function
CLIENT_API BOOL CALL_METHOD CLIENT_SetOperateCallBack(LLONG lLoginID, fMessDataCallBack cbMessData, LDWORD dwUser);

// Control decoder TV screen partition,Interface is asynchronous
CLIENT_API LLONG CALL_METHOD CLIENT_CtrlDecTVScreen(LLONG lLoginID, int nMonitorID, BOOL bEnable, int nSplitType, BYTE *pEncoderChannel, int nBufLen, void* userdata=NULL);

// Switch decoder TV screen,Interface is asynchronous
// According to nMonitorID(TV ID) nWndID(Screen ID) Convert to nDecoderID(decoder channel) formula:nEncoderID nMonitorID*nSplitNum(Partition number)+nWndID
CLIENT_API LLONG CALL_METHOD CLIENT_SwitchDecTVEncoder(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, void* userdata=NULL);

//------------------------------------------------------------------------

// Add combination of screen
CLIENT_API int CALL_METHOD CLIENT_AddTourCombin(LLONG lLoginID, int nMonitorID, int nSplitType, BYTE *pEncoderChannnel, int nBufLen, int waittime=1000);

// Delete combination of screen
CLIENT_API BOOL CALL_METHOD CLIENT_DelTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int waittime=1000);

// Modify combination of screen
CLIENT_API BOOL CALL_METHOD CLIENT_SetTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int nSplitType, BYTE *pEncoderChannel, int nBufLen, int waittime=1000);

// Query combination of screen,nCombinID: 0??32
CLIENT_API BOOL CALL_METHOD CLIENT_QueryTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, LPDEC_COMBIN_INFO lpDecCombinInfo, int waittime=1000);

// Set up tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// Query tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// Query the current flux information of decoding channel
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecChannelFlux(LLONG lLoginID, int nDecoderID, LPDEV_DECCHANNEL_STATE lpChannelStateInfo, int waittime=1000);

// control decoder tour operation
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecoderTour(LLONG lLoginID, int nMonitorID, DEC_CTRL_TOUR_TYPE emActionParam, int waittime = 1000);
//------------------------------------------------------------------------

typedef void (CALLBACK *fDecPlayBackPosCallBack)(LLONG lLoginID, int nEncoderID, DWORD dwTotalSize, DWORD dwPlaySize, LDWORD dwUser);

// Set the playback progress callback function
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecPlaybackPos(LLONG lLoginID, fDecPlayBackPosCallBack cbPlaybackPos, LDWORD dwUser);

// Decoder TV screen playback,Interface is asynchronous
CLIENT_API LLONG CALL_METHOD CLIENT_DecTVPlayback(LLONG lLoginID, int nDecoderID, DEC_PLAYBACK_MODE emPlaybackMode, LPVOID lpInBuffer, DWORD dwInBufferSize, void* userdata=NULL);

// Control TV screen playback
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecPlayback(LLONG lLoginID, int nDecoderID, DEC_CTRL_PLAYBACK_TYPE emCtrlType, int nValue, int waittime=1000);

///////////////////////////////intelligent device interface///////////////////////////////

// real load picture of intelligent analysis 
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPicture(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

// real load picture of intelligent analysis(expand interface: 'bNeedPicFile == true' instruct load picture file, 'bNeedPicFile == false' instruct not load picture file ) 
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPictureEx(LLONG lLoginID, int nChannelID, 
													 DWORD dwAlarmType, 
													 BOOL bNeedPicFile, 
													 fAnalyzerDataCallBack cbAnalyzerData, 
													 LDWORD dwUser, 
													 void* Reserved);

// stop load picture of intelligent analysis
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadPic(LLONG lAnalyzerHandle);

// Confirm if picture upload is complete??picture
// This port better not be in the same thread with  CLIENT_RealLoadPictureEx/CLIENT_RealLoadPicture ??s call function??otherwise will cause jam??and must call in another thread
CLIENT_API BOOL CALL_METHOD CLIENT_SnapManagerConfirmUpload(LLONG lLoginID, const NET_IN_SNAP_MANAGER_CONFIRM_UPLOAD* pstInParam, NET_OUT_SNAP_MANAGER_CONFIRM_UPLOAD* pstOutParam, int waittime=1000);

// Search according to the criteria
CLIENT_API LLONG	CALL_METHOD CLIENT_FindFileEx(LLONG lLoginID, EM_FILE_QUERY_TYPE emType, void* pQueryCondition, void *reserved, int waittime=1000);	

// Search file:nFilecount:the searched amount. The return value is media file amount. The search in the specified time completed if return <nFilecount.
CLIENT_API int	CALL_METHOD CLIENT_FindNextFileEx(LLONG lFindHandle, int nFilecount, void* pMediaFileInfo, int maxlen, void *reserved, int waittime=1000);

// End the file search
CLIENT_API BOOL CALL_METHOD CLIENT_FindCloseEx(LLONG lFindHandle);

// get matched search filter file total
CLIENT_API BOOL CALL_METHOD CLIENT_GetTotalFileCount(LLONG lFindHandle, int* pTotalCount, void *reserved, int waittime=1000);

// set search jump filter
CLIENT_API BOOL CALL_METHOD CLIENT_SetFindingJumpOption(LLONG lFindHandle, NET_FINDING_JUMP_OPTION_INFO* pOption, void *reserved, int waittime=1000);

// Download the specified intelligent analytics data-image
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadMediaFile(LLONG lLoginID,EM_FILE_QUERY_TYPE emType, void* lpMediaFileInfo, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData,  void *reserved);

// Stop downloading the data
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownloadMediaFile(LLONG lFileHandle);

// batch download file
CLIENT_API BOOL CALL_METHOD CLIENT_DownLoadMultiFile(LLONG lLoginID, NET_IN_DOWNLOAD_MULTI_FILE *pstInParam, NET_OUT_DOWNLOAD_MULTI_FILE *pstOutParam, int waittime=1000);

// stop download
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadMultiFile(LLONG lDownLoadHandle);

// download picture of intelligent analysis when being off line
CLIENT_API LLONG CALL_METHOD CLIENT_LoadOffLineFile(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, LPNET_TIME_EX lpStartTime, LPNET_TIME_EX lpEndTime, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

//Pause IVS data download(bPause=TRUE, it is to stop download , bPause=FALSE , it is to resume download.)
CLIENT_API BOOL CALL_METHOD CLIENT_PauseLoadPic(LLONG lLoadHadle, BOOL bPause);

// traffic snap--snapshot by network
CLIENT_API BOOL CALL_METHOD CLIENT_TrafficSnapByNetwork(LLONG lLoginID, int nChannelID, NET_IN_SNAPSHOT* pstInParam, NET_OUT_SNAPSHOT* pstOutParam);
// start traffic flux state
// traffic control --forced the red light
CLIENT_API BOOL CALL_METHOD CLIENT_TrafficForceLightState(LLONG lLoginID, int nChannelID, NET_IN_FORCELIGHTSTATE* pstInParamg, NET_OUT_FORCELIGHTSTATE* pstOutParam, int waittime=1000);

//  balck/white list operation
CLIENT_API BOOL CALL_METHOD CLIENT_OperateTrafficList(LLONG lLoginID ,  NET_IN_OPERATE_TRAFFIC_LIST_RECORD* pstInParam , NET_OUT_OPERATE_TRAFFIC_LIST_RECORD *pstOutParam = NULL ,  int waittime = 1000);

// start traffic flux state
CLIENT_API LLONG CALL_METHOD CLIENT_StartTrafficFluxStat(LLONG lLoginID, NET_IN_TRAFFICFLUXSTAT* pstInParam,NET_OUT_TRAFFICFLUXSTAT* pstOutParam);

// stop traffic flux state
CLIENT_API BOOL CALL_METHOD CLIENT_StopTrafficFluxStat(LLONG lFluxStatHandle);

// start find flux state
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindFluxStat(LLONG lLoginID, NET_IN_TRAFFICSTARTFINDSTAT* pstInParam, NET_OUT_TRAFFICSTARTFINDSTAT* pstOutParam);

// do find flux state
CLIENT_API int	CALL_METHOD CLIENT_DoFindFluxStat(LLONG lFindHandle, NET_IN_TRAFFICDOFINDSTAT* pstInParam,NET_OUT_TRAFFICDOFINDSTAT* pstOutParam);

// stop find flux state
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindFluxStat(LLONG lFindHandle);
// start find number state
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindNumberStat(LLONG lLoginID, NET_IN_FINDNUMBERSTAT* pstInParam, NET_OUT_FINDNUMBERSTAT* pstOutParam);

// do find number state
CLIENT_API int	CALL_METHOD CLIENT_DoFindNumberStat(LLONG lFindHandle, NET_IN_DOFINDNUMBERSTAT* pstInParam, NET_OUT_DOFINDNUMBERSTAT* pstOutParam);

// stop find number state
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindNumberStat(LLONG lFindHandle);

// Call of the analysis device method
CLIENT_API BOOL CALL_METHOD CLIENT_OperateVideoAnalyseDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// Access to video analysis object
CLIENT_API BOOL CALL_METHOD CLIENT_VideoAnalyseGetTemplateImage(LLONG lLoginID, const NET_IN_VIDEOANALYSE_GETTEMPLATEIMAGE* pstInParam, NET_OUT_VIDEOANALYSE_GETTEMPLATEIMAGE* pstOutParam, int nWaitTime=1000);

// Set the video analysis object
CLIENT_API BOOL CALL_METHOD CLIENT_VideoAnalyseSetTemplateImage(LLONG lLoginID, const NET_IN_VIDEOANALYSE_SETTEMPLATEIMAGE* pstInParam, NET_OUT_VIDEOANALYSE_SETTEMPLATEIMAGE* pstOutParam, int nWaitTime=1000);

// serial device method call
CLIENT_API BOOL CALL_METHOD CLIENT_OperateCommDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// Intelligent track speed dome control port.
CLIENT_API BOOL CALL_METHOD CLIENT_ControlIntelliTracker(LLONG lLoginID, NET_IN_CONTROL_INTELLITRACKER* pstInParam, NET_OUT_CONTROL_INTELLITRACKER* pstOutParam);

// master-slave device method,look for CLIENT_OperateMasterSlaveDevice
CLIENT_API BOOL CALL_METHOD CLIENT_OperateMasterSlaveDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// video splicing method call
CLIENT_API BOOL CALL_METHOD CLIENT_OperateVideoJoin(LLONG lLoginID, NET_VIDEOJOIN_OPERATE_TYPE emType, void* pstInParam, void* pstOutParam, int nWaitTime);

////////////////////////////////  Video analysis /////////////////////////////////
// Real-time get video analysis result 
CLIENT_API BOOL CALL_METHOD CLIENT_StartVideoDiagnosis(LLONG lLoginID, NET_IN_VIDEODIAGNOSIS *pstInParam, NET_OUT_VIDEODIAGNOSIS *pstOutParam);

// Stop video analysis result report
CLIENT_API BOOL CALL_METHOD CLIENT_StopVideoDiagnosis(LLONG hDiagnosisHandle);

// Start video analysis result search
CLIENT_API BOOL CALL_METHOD CLIENT_StartFindDiagnosisResult(LLONG lLoginID, NET_IN_FIND_DIAGNOSIS* pstInParam, NET_OUT_FIND_DIAGNOSIS* pstOutParam);

// Get video analysis result info
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindDiagnosisResult(LLONG hFindHandle,NET_IN_DIAGNOSIS_INFO* pstInParam, NET_OUT_DIAGNOSIS_INFO* pstOutParam);

// End video analysis result search
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindDiagnosis(LLONG hFindHandle);

// enable real time disgnosis plan
CLIENT_API BOOL CALL_METHOD CLIENT_StartRealTimeProject(LLONG lLoginID,NET_IN_START_RT_PROJECT_INFO* pstInParam, NET_OUT_START_RT_PROJECT_INFO* pstOutParam, int nWaitTime);

// stop real time diagnosis plan
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealTimeProject(LLONG lLoginID,NET_IN_STOP_RT_PROJECT_INFO* pstInParam, NET_OUT_STOP_RT_PROJECT_INFO* pstOutParam, int nWaitTime);

// get parking space status
CLIENT_API BOOL CALL_METHOD CLIENT_GetParkingSpaceStatus(LLONG lLoginID, NET_IN_GET_PARKINGSPACE_STATUS* pstInParam, NET_OUT_GET_PARKINGSPACE_STATUS* pstOutParam);

// attach parking space data
CLIENT_API LLONG CALL_METHOD CLIENT_AttachParkingSpaceData(LLONG lLoginID, NET_IN_ATTACH_PARKINGSPACE* pstInParam, NET_OUT_ATTACH_PARKINGSPACE* pstOutParam);

// detach parking space data
CLIENT_API BOOL CALL_METHOD CLIENT_DetachParkingSpaceData(NET_IN_DETACH_PARKINGSPACE* pstInParam, NET_OUT_DETACH_PARKINGSPACE* pstOutParam);

// Subscribed to the car information
CLIENT_API LLONG CALL_METHOD CLIENT_AttachCarPassInfo(LLONG lLoginID, NET_IN_ATTACH_CAR_PASS_INFO* pstInParam, NET_OUT_ATTACH_CAR_PASS_INFO* pstOutParam , int nWaitTime);

// Unsubscribe car information lCarPassInfoHandle is CLIENT_AttachCarPassInfo returns a handle 
CLIENT_API BOOL CALL_METHOD CLIENT_DetachCarPassInfo(LLONG lCarPassInfoHandle);

// order specific lane info 
CLIENT_API LLONG CALL_METHOD CLIENT_AttachLanesState(LLONG lLoginID, NET_IN_ATTACH_LANES_STATE* pstInParam, NET_OUT_ATTACH_LANES_STATE* pstOutParam, int nWaitTime);

// cancel order of specific lane info lLanesStateHandle is CLIENT_AttachLanesStatereturn handle
CLIENT_API BOOL CALL_METHOD CLIENT_DetachLanesState(LLONG lLanesStateHandle);

// get car port light status
CLIENT_API BOOL CALL_METHOD CLIENT_GetCarPortLightStatus(LLONG lLoginID, NET_IN_GET_CARPORTLIGHT_STATUS* pstInParam, NET_OUT_GET_CARPORTLIGHT_STATUS* pstOutParam, int waittime=1000);

// ser car port light status
CLIENT_API BOOL CALL_METHOD CLIENT_SetCarPortLightStatus(LLONG lLoginID, NET_IN_SET_CARPORTLIGHT_STATUS* pstInParam, NET_OUT_SET_CARPORTLIGHT_STATUS* pstOutParam, int waittime=1000);

// subscribe intelligent analysis porogress?¡§for video analysis source is record file??
CLIENT_API BOOL CALL_METHOD CLIENT_AttachVideoAnalyseState(LLONG lLoginID, NET_IN_ATTACH_VIDEOANALYSE_STATE* pstInParam, NET_OUT_ATTACH_VIDEOANALYSE_STATE* pstOutParam, int nWaittime=1000);

// stop subscription
CLIENT_API BOOL CALL_METHOD CLIENT_DetachVideoAnalyseState(LLONG lAttachHandle);

// ?????¡ã???¨¨¡À?????¡Á???
CLIENT_API LLONG CALL_METHOD CLIENT_AttachTalkState(LLONG lLoginID, NET_IN_ATTACH_TALK_STATE* pstInParam, NET_OUT_ATTACH_TALK_STATE* pstOutParam, int nWaitTime = 1000);

// ?????????¡ã???¨¨¡À?????¡Á???, lAttachHandle??CLIENT_AttachTalkState????????¡À¨²
CLIENT_API BOOL CALL_METHOD CLIENT_DetachTalkState(LLONG lAttachHandle);

////////////////////////////////synopsis video' interface////////////////////////////////

// add video synopsis task
CLIENT_API BOOL CALL_METHOD CLIENT_AddVideoSynopsisTask(LLONG lLoginID,	NET_IN_ADD_VIDEOSYNOPSIS* pstInParam, NET_OUT_ADD_VIDEOSYNOPSIS* pstOutParam);

// pause video synopsis task
CLIENT_API BOOL CALL_METHOD CLIENT_PauseVideoSynopsisTask(LLONG lLoginID, NET_IN_PAUSE_VIDEOSYNOPSIS* pstInParam);

// remove video synopsis task
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveVideoSynopsisTask(LLONG lLoginID, NET_IN_REMOVE_VIDEOSYNOPSIS* pstInParam);

// subscibe real load object data
CLIENT_API BOOL CALL_METHOD CLIENT_RealLoadObjectData(LLONG lLoginID, NET_IN_REALLOAD_OBJECTDATA* pstInParam, NET_OUT_REALLOAD_OBJECTDATA* pstOutParam);

// stop load object data
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadObjectData(LLONG lRealLoadHandle, NET_IN_STOPLOAD_OBJECTDATA* pstInParam);

// subscribe real synopsis progress state
CLIENT_API BOOL CALL_METHOD CLIENT_RealLoadSynopsisState(LLONG lLoginID, NET_IN_REALLAOD_SYNOPSISSTATE* pstInParam, NET_OUT_REALLOAD_SYNOPSISSTATE* pstOutParam);

// stop subscribe real synopsis progress state
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadSynopsisState(LLONG lRealLoadHandle, NET_IN_STOPLOAD_SYNOPSISSTATE* pstInParam);

// query real synopsis video state
CLIENT_API BOOL CALL_METHOD CLIENT_QueryVideoSynopsisInfo(LLONG lLoginID, NET_IN_QUERY_VIDEOSYNOPSIS* pstInParam, NET_OUT_QUERY_VIDEOSYNOPSIS* pstuOutParam);

// according to the query criteria query synopsis file
CLIENT_API BOOL	CALL_METHOD CLIENT_FindSynopsisFile(LLONG lLoginID, NET_IN_FIND_SYNOPSISFILE *pstInParam, NET_OUT_FIND_SYNOPSISFILE *pstOutParam);	

// query synopsis file
CLIENT_API BOOL	CALL_METHOD CLIENT_FindNextSynopsisFile(LLONG lFindHandle, NET_IN_FINDNEXT_SYNOPSISFILE *pstInParam, NET_OUT_FINDNEXT_SYNOPSISFILE *pstOutParam);

// close query synopsis file
CLIENT_API BOOL CALL_METHOD CLIENT_SynopsisFindClose(LLONG lFindHandle);

// download synosis file
CLIENT_API BOOL CALL_METHOD CLIENT_DownLoadSynosisFile(LLONG lLoginID, NET_IN_DOWNLOAD_SYNOPSISFILE *pstInParam, NET_OUT_DOWNLOAD_SYNOPSISFILE *pstOutParam);

// stop load synosis file
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadSynosisFile(LLONG lDownLoadHandle);

// according to the path to the file request video service,generate the file information
CLIENT_API BOOL	CALL_METHOD	CLIENT_SetFilePathInfo(LLONG lLoginID, NET_IN_SET_FILEPATHINFO* pstInParam);

// attach add file state
CLIENT_API LLONG CALL_METHOD CLIENT_AttachAddFileState(LLONG lLoginID, const NET_IN_ADDFILE_STATE* pstInParam, NET_OUT_ADDFILE_STATE *pstOutParam, int nWaitTime = 1000);

// cancel attach add file state,  CLIENT_AttacAddFileState return lAttachHandle
CLIENT_API LLONG CALL_METHOD CLIENT_DetachAddFileState(LLONG lAttachHandle);

/////////////////////////////////face recognition port/////////////////////////////////////////
// face recognition database info operation?¡§including add and delete??
CLIENT_API BOOL CALL_METHOD CLIENT_OperateFaceRecognitionDB(LLONG lLoginID, const NET_IN_OPERATE_FACERECONGNITIONDB* pstInParam, NET_OUT_OPERATE_FACERECONGNITIONDB *pstOutParam, int nWaitTime = 1000);

// by filter search face recognition result 
CLIENT_API BOOL CALL_METHOD CLIENT_StartFindFaceRecognition(LLONG lLoginID, const NET_IN_STARTFIND_FACERECONGNITION* pstInParam, NET_OUT_STARTFIND_FACERECONGNITION *pstOutParam, int nWaitTime = 1000);

// search face recognition result:nFilecount: need search item,  return value is media file item  return value<nFilecount then corresponding period file search complete(search max of 20 records each time)
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindFaceRecognition(const NET_IN_DOFIND_FACERECONGNITION* pstInParam, NET_OUT_DOFIND_FACERECONGNITION *pstOutParam, int nWaitTime = 1000);

// end search
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindFaceRecognition(LLONG lFindHandle);

// face recognition(input one big graph??input big graph detected face picture)
CLIENT_API BOOL CALL_METHOD CLIENT_DetectFace(LLONG lLoginID, const NET_IN_DETECT_FACE* pstInParam, NET_OUT_DETECT_FACE *pstOutParam, int nWaitTime = 1000);

// face recognition staff group operation?¡§including add, modify and delete??
CLIENT_API BOOL CALL_METHOD CLIENT_OperateFaceRecognitionGroup(LLONG lLoginID, const NET_IN_OPERATE_FACERECONGNITION_GROUP* pstInParam, NET_OUT_OPERATE_FACERECONGNITION_GROUP *pstOutParam, int nWaitTime = 1000);

// search face recognition staff group info 
CLIENT_API BOOL CALL_METHOD CLIENT_FindGroupInfo(LLONG lLoginID, const NET_IN_FIND_GROUP_INFO* pstInParam, NET_OUT_FIND_GROUP_INFO *pstOutParam, int nWaitTime = 1000);

// arm channel staff group info 
CLIENT_API BOOL CALL_METHOD CLIENT_SetGroupInfoForChannel(LLONG lLoginID, const NET_IN_SET_GROUPINFO_FOR_CHANNEL* pstInParam, NET_OUT_SET_GROUPINFO_FOR_CHANNEL *pstOutParam, int nWaitTime = 1000);

// set picture information
CLIENT_API BOOL CALL_METHOD CLIENT_FaceRecognitionSetSearchImageInfo(LLONG lLoginID, const NET_IN_FACE_RECOGNITION_SET_SEARCH_IMAGE_INFO* pstInParam, NET_OUT_FACE_RECOGNITION_SET_SEARCH_IMAGE_INFO *pstOutParam, int nWaitTime = 1000);
//////////////////////////////// burn the upload interface /////////////////////////////////

// open burning session, return to burning session handle
CLIENT_API LLONG CALL_METHOD CLIENT_StartBurnSession(LLONG lLoginID, const NET_IN_START_BURN_SESSION* pstInParam, NET_OUT_START_BURN_SESSION *pstOutParam, int nWaitTime);

// close burning session
CLIENT_API BOOL CALL_METHOD CLIENT_StopBurnSession(LLONG lBurnSession);

// start burning
CLIENT_API BOOL CALL_METHOD CLIENT_StartBurn(LLONG lBurnSession, const NET_IN_START_BURN* pstInParam, NET_OUT_START_BURN *pstOutParam, int nWaitTime);

// stop burning
CLIENT_API BOOL CALL_METHOD CLIENT_StopBurn(LLONG lBurnSession);

// pause/recover burning
CLIENT_API BOOL CALL_METHOD CLIENT_PauseBurn(LLONG lBurnSession, BOOL bPause);

// key mark
CLIENT_API BOOL CALL_METHOD CLIENT_BurnMarkTag(LLONG lBurnSession, const NET_IN_BURN_MARK_TAG* pstInParam, NET_OUT_BURN_MARK_TAG *pstOutParam, int nWaitTime);

// change disk
CLIENT_API BOOL CALL_METHOD CLIENT_BurnChangeDisk(LLONG lBurnSession, const NET_IN_BURN_CHANGE_DISK* pstInParam, NET_OUT_BURN_CHANGE_DISK *pstOutParam, int nWaitTime);

// get burning status
CLIENT_API BOOL CALL_METHOD CLIENT_BurnGetState(LLONG lBurnSession, const NET_IN_BURN_GET_STATE* pstInParam, NET_OUT_BURN_GET_STATE *pstOutParam, int nWaitTime);

// attach burn state
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnState(LLONG lLoginID, const NET_IN_ATTACH_STATE* pstInParam, NET_OUT_ATTACH_STATE *pstOutParam, int nWaitTime = 1000);

// cancel listening burning status??lAttachHandle is CLIENT_AttachBurnState return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnState(LLONG lAttachHandle);

// start burn upload
CLIENT_API LLONG CALL_METHOD CLIENT_StartUploadFileBurned(LLONG lLoginID, const NET_IN_FILEBURNED_START* pstInParam, NET_OUT_FILEBURNED_START *pstOutParam, int nWaitTime = 1000);

// send file burned,CLIENT_StartUploadFileBurned return lUploadHandle
CLIENT_API BOOL	CALL_METHOD	CLIENT_SendFileBurned(LLONG lUploadHandle);

// stop upload 
CLIENT_API BOOL	CALL_METHOD	CLIENT_StopUploadFileBurned(LLONG lUploadHandle);

// listening burning parity status
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnCheckState(LLONG lLoginID, const NET_IN_ATTACH_BURN_CHECK* pstInParam, NET_OUT_ATTACH_BURN_CHECK* pstOutParam, int nWaitTime = 1000);

// cancle attach burn state,CLIENT_DetachBurnCheckState return lAttachHandle
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnCheckState(LLONG lAttachHandle);

// subscribe burning case info
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnCase(LLONG lLoginID, const NET_IN_ATTACH_BURN_CASE* pInParam, NET_OUT_ATTACH_BURN_CASE* pOutParam, int nWaitTime);

// cancel subscribe burning case info??lAttachHandle is CLIENT_AttachBurnCase return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnCase(LLONG lAttachHandle);

//////////////////////////////// logical device /////////////////////////////////////////

// attach camerastate
CLIENT_API LLONG CALL_METHOD CLIENT_AttachCameraState(LLONG lLoginID, const NET_IN_CAMERASTATE* pstInParam, NET_OUT_CAMERASTATE *pstOutParam, int nWaitTime = 3000);

// detach camera state,CLIENT_AttachCameraState return lAttachHandle
CLIENT_API BOOL	CALL_METHOD	CLIENT_DetachCameraState(LLONG lAttachHandle);

//get all valid display source
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixGetCameras(LLONG lLoginID, const DH_IN_MATRIX_GET_CAMERAS* pInParam, DH_OUT_MATRIX_GET_CAMERAS* pOutParam, int nWaitTime = 1000);

// add logical device
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixAddCameras(LLONG lLoginID, const DH_IN_ADD_LOGIC_DEVICE_CAMERA* pInParam, DH_OUT_ADD_LOGIC_DEVICE_CAMERA* pOutParam, int nWaitTime = 1000);
////////////////////////////////  Matrix interface /////////////////////////////////

// Search product definition
CLIENT_API BOOL CALL_METHOD CLIENT_QueryProductionDefinition(LLONG lLoginID, DH_PRODUCTION_DEFNITION* pstuProdDef, int nWaitTime = 1000);

// Search matri sub card info
CLIENT_API BOOL CALL_METHOD CLIENT_QueryMatrixCardInfo(LLONG lLoginID, DH_MATRIX_CARD_LIST* pstuCardList, int nWaitTime = 1000);

// Search system status
CLIENT_API BOOL CALL_METHOD	CLIENT_QuerySystemStatus(LLONG lLoginID, DH_SYSTEM_STATUS* pstuStatus, int nWaitTime = 1000);

// Search split mode
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitCaps(LLONG lLoginID, int nChannel, DH_SPLIT_CAPS* pstuCaps, int nWaitTime = 1000);

// Search/set display source 
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitSource(LLONG lLoginID, int nChannel, int nWindow, DH_SPLIT_SOURCE* pstuSplitSrc, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitSource(LLONG lLoginID, int nChannel, int nWindow, const DH_SPLIT_SOURCE* pstuSplitSrc, int nSrcCount, int nWaitTime = 1000);
// set display source, support output parameter
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitSourceEx(LLONG lLoginID, const NET_IN_SET_SPLIT_SOURCE* pInparam, NET_OUT_SET_SPLIT_SOURCE* pOutParam, int nWaitTime = 1000);

// Search/set split mode
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitMode(LLONG lLoginID, int nChannel, DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitMode(LLONG lLoginID, int nChannel, const DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);

// Search split group amount
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitGroupCount(LLONG lLoginID, int nChannel, DH_SPLIT_MODE emSplitMode, int* pnGroupCount, int nWaitTime = 1000);

// Search video output capability
CLIENT_API BOOL CALL_METHOD CLIENT_GetVideoOutCaps(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_CAPS* pstuCaps, int nWaitTime = 1000);

// Set video output option
CLIENT_API BOOL CALL_METHOD CLIENT_SetVideoOutOption(LLONG lLoginID, int nChannel, const DH_VIDEO_OUT_OPT* pstuVideoOut, int nWaitTime = 1000);

// Search the current window of video input channel
CLIENT_API BOOL CALL_METHOD CLIENT_QueryVideoOutWindows(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_WINDOW* pstuWnds, int nMaxWndCount, int* pnRetWndCount, int nWaitTime = 1000);

// set windown position
CLIENT_API BOOL CALL_METHOD	CLIENT_SetSplitWindowRect(LLONG lLoginID, const DH_IN_SPLIT_SET_RECT* pInParam, DH_OUT_SPLIT_SET_RECT* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL	CALL_METHOD	CLIENT_GetSplitWindowRect(LLONG lLoginID, const DH_IN_SPLIT_GET_RECT* pInParam, DH_OUT_SPLIT_GET_RECT* pOutParam, int nWaitTime = 1000);

// open or close window
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSplitWindow(LLONG lLoginID, const DH_IN_SPLIT_OPEN_WINDOW* pInParam, DH_OUT_SPLIT_OPEN_WINDOW* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSplitWindow(LLONG lLoginID, const DH_IN_SPLIT_CLOSE_WINDOW* pInParam, DH_OUT_SPLIT_CLOSE_WINDOW* pOutParam, int nWaitTime = 1000);

// set window order
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitTopWindow(LLONG lLoginID, const DH_IN_SPLIT_SET_TOP_WINDOW* pInParam, DH_OUT_SPLIT_SET_TOP_WINDOW* pOutParam, int nWaitTime = 1000);

// get windows info
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitWindowsInfo(LLONG lLoginID, const DH_IN_SPLIT_GET_WINDOWS* pInParam, DH_OUT_SPLIT_GET_WINDOWS* pOutParam, int nWaitTime = 1000);

// load or save collection
CLIENT_API BOOL CALL_METHOD	CLIENT_LoadSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_LOAD_COLLECTION* pInParam, DH_OUT_SPLIT_LOAD_COLLECTION* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD	CLIENT_SaveSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_SAVE_COLLECTION* pInParam, DH_OUT_SPLIT_SAVE_COLLECTION* pOutParam, int nWaitTime = 1000);

// get collection info
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitCollections(LLONG lLoginID, const DH_IN_SPLIT_GET_COLLECTIONS* pInParam, DH_OUT_SPLIT_GET_COLLECTIONS* pOutParam, int nWaitTime = 1000);

// rename collection
CLIENT_API BOOL	CALL_METHOD CLIENT_RenameSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_RENAME_COLLECTION* pInParam, DH_OUT_SPLIT_RENAME_COLLECTION* pOutParam, int nWaitTime = 1000);

// delete collection
CLIENT_API BOOL CALL_METHOD CLIENT_DeleteSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_DELETE_COLLECTION* pInParam, DH_OUT_SPLIT_DELETE_COLLECTION* pOutParam, int nWaitTime = 1000);

// decode policy
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecodePolicy(LLONG lLoginID, const DH_IN_SET_DEC_POLICY* pInParam, DH_OUT_SET_DEC_POLICY* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetDecodePolicy(LLONG lLoginID, const DH_IN_GET_DEC_POLICY* pInParam, DH_OUT_GET_DEC_POLICY* pOutParam, int nWaitTime = 1000);

// mode of audio output
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitAudioOuput(LLONG lLoginID, const DH_IN_SET_AUDIO_OUTPUT* pInParam, DH_OUT_SET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitAudioOuput(LLONG lLoginID, const DH_IN_GET_AUDIO_OUTPUT* pInParam, DH_OUT_GET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);

// set display source
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSetCameras(LLONG lLoginID, const DH_IN_MATRIX_SET_CAMERAS* pInParam, DH_OUT_MATRIX_SET_CAMERAS* pOutParam, int nWaitTime = 1000);

// get video in ability
CLIENT_API BOOL CALL_METHOD CLIENT_GetVideoInCaps(LLONG lLoginID, const DH_IN_GET_VIDEO_IN_CAPS* pInParam, DH_OUT_GET_VIDEO_IN_CAPS* pOutParam, int nWaitTime = 1000);

// get mode of video out
CLIENT_API BOOL CALL_METHOD CLIENT_EnumVideoOutModes(LLONG lLoginID, const DH_IN_ENUM_VIDEO_OUT_MODES* pInParam, DH_OUT_ENUM_VIDEO_OUT_MODES* pOutParam, int nWaitTime = 1000);

// get or set splite output OSD info
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitOSD(LLONG lLoginID, const DH_IN_SPLIT_GET_OSD* pInParam, DH_OUT_SPLIT_GET_OSD* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitOSD(LLONG lLoginID, const DH_IN_SPLIT_SET_OSD* pInParam, DH_OUT_SPLIT_SET_OSD* pOutParam, int nWaitTime = 1000);

// set window tour display source
CLIENT_API BOOL CALL_METHOD CLIENT_SetTourSource(LLONG lLoginID, const NET_IN_SET_TOUR_SOURCE* pInParam, NET_OUT_SET_TOUR_SOURCE* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetTourSource(LLONG lLoginID, const NET_IN_GET_TOUR_SOURCE* pInParam, NET_OUT_GET_TOUR_SOURCE* pOutParam, int nWaitTime);

// order tour status 
CLIENT_API LLONG CALL_METHOD CLIENT_AttachSplitTour(LLONG lLoginID, const NET_IN_ATTACH_SPLIT_TOUR* pInParam, NET_OUT_ATTACH_SPLIT_TOUR* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_DetachSplitTour(LLONG lAttachHandle);

// low matrix switch
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSwitch(LLONG lLoginID, const NET_IN_MATRIX_SWITCH* pInParam, NET_OUT_MATRIX_SWITCH* pOutParam, int nWaitTime);

// set display source, support multiple window at same time
CLIENT_API BOOL CALL_METHOD CLIENT_SplitSetMultiSource(LLONG lLoginID, const NET_IN_SPLIT_SET_MULTI_SOURCE* pInParam, NET_OUT_SPLIT_SET_MULTI_SOURCE* pOutParam, int nWaitTime);

// video split operation
CLIENT_API BOOL CALL_METHOD CLIENT_OperateSplit(LLONG lLoginID, NET_SPLIT_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);

// split window  play operation
CLIENT_API BOOL CALL_METHOD CLIENT_OperateSplitPlayer(LLONG lLoginID, NET_PLAYER_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);
//////////////////////////////////// monitor wall control //////////////////////////////////////

// power control 
CLIENT_API BOOL CALL_METHOD CLIENT_PowerControl(LLONG lLoginID, const DH_IN_WM_POWER_CTRL* pInParam, DH_OUT_WM_POWER_CTRL* pOutParam, int nWaitTime = 1000);

// get or set mode of display 
CLIENT_API BOOL CALL_METHOD CLIENT_SetDisplayMode(LLONG lLoginID, const DH_IN_WM_SET_DISPLAY_MODE* pInParam, DH_OUT_WM_SET_DISPLAY_MODE* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetDisplayMode(LLONG lLoginID, const DH_IN_WM_GET_DISPLAY_MODE* pInParam, DH_OUT_WM_GET_DISPLAY_MODE* pOutParam, int nWaitTime = 1000);

// load or save plan
CLIENT_API BOOL CALL_METHOD	CLIENT_LoadMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_LOAD_COLLECTION* pInParam, DH_OUT_WM_LOAD_COLLECTION* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD	CLIENT_SaveMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_SAVE_COLLECTION* pInParam, DH_OUT_WM_SAVE_COLLECTION* pOutParam, int nWaitTime = 1000);

// get plan of monitor wall
CLIENT_API BOOL CALL_METHOD CLIENT_GetMonitorWallCollections(LLONG lLoginID, const DH_IN_WM_GET_COLLECTIONS* pInParam, DH_OUT_WM_GET_COLLECTIONS* pOutParam, int nWaitTime = 1000);

// rename monitor wall's plan
CLIENT_API BOOL	CALL_METHOD CLIENT_RenameMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_RENAME_COLLECTION* pInParam, DH_OUT_WM_RENAME_COLLECTION* pOutParam, int nWaitTime = 1000);

// get or set scene of monitor wall 
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetScene(LLONG lLoginID, const DH_IN_MONITORWALL_GET_SCENE* pInParam, DH_OUT_MONITORWALL_GET_SCENE* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetScene(LLONG lLoginID, const DH_IN_MONITORWALL_SET_SCENE* pInParam, DH_OUT_MONITORWALL_SET_SCENE* pOutParam, int nWaitTime = 1000);

// get attribute caps of monitor wall
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetAttributeCaps(LLONG lLoginID, const DH_IN_MONITORWALL_GET_ARRT_CAPS* pInParam, DH_OUT_MONITORWALL_GET_ARRT_CAPS* pOutParam, int nWaitTime = 1000);

// auto adjust of monitor wall
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallAutoAdjust(LLONG lLoginID, const DH_IN_MONITORWALL_AUTO_ADJUST* pInParam, DH_OUT_MONITORWALL_AUTO_ADJUST* pOutParam, int nWaitTime = 1000);

// set attribute of monitor wall 
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetAttribute(LLONG lLoginID, const DH_IN_MONITORWALL_SET_ATTR* pInParam, DH_OUT_MONITORWALL_SET_ATTR* pOutParam, int nWaitTime = 1000);

// set mode of backlight
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetBackLight(LLONG lLoginID, const DH_IN_MONITORWALL_SET_BACK_LIGHT* pInParam, DH_OUT_MONITORWALL_SET_BACK_LIGHT* pOutParam, int nWaitTime = 1000);

// search/set screen on/off plan
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetPowerSchedule(LLONG lLoginID, const NET_IN_MW_GET_POWER_SCHEDULE* pInParam, NET_OUT_MW_GET_POWER_SCHEDULE* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetPowerSchedule(LLONG lLoginID, const NET_IN_MW_SET_POWER_SCHEDULE* pInParam, NET_OUT_MW_SET_POWER_SCHEDULE* pOutParam, int nWaitTime);

// search/set screen control parameter
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetScrnCtrlParam(LLONG lLoginID, const NET_IN_MW_GET_SCRN_CTRL_PARAM* pInParam, NET_OUT_MW_GET_SCRN_CTRL_PARAM* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetScrnCtrlParam(LLONG lLoginID, const NET_IN_MW_SET_SCRN_CTRL_PARAM* pInParam, NET_OUT_MW_SET_SCRN_CTRL_PARAM* pOutParam, int nWaitTime);

// search/set screen and window background color
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetBackgroudColor(LLONG lLoginID, const NET_IN_MW_GET_BACKGROUDND_COLOR* pInParam, NET_OUT_MW_GET_BACKGROUDND_COLOR* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetBackgroudColor(LLONG lLoginID, const NET_IN_MW_SET_BACKGROUD_COLOR* pInParam, NET_OUT_MW_SET_BACKGROUD_COLOR* pOutParam, int nWaitTime);

// order scheme tour status 
CLIENT_API LLONG CALL_METHOD CLIENT_MonitorWallAttachTour(LLONG lLoginID, const NET_IN_WM_ATTACH_TOUR* pInParam, NET_OUT_WM_ATTACH_TOUR* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallDetachTour(LLONG lAttachHandle);

// operate Monitor Wall
CLIENT_API BOOL CALL_METHOD CLIENT_OperateMonitorWall(LLONG lLoginID, NET_MONITORWALL_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);

///////////////////////////////// directory management /////////////////////////////////////////

// add nodes
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationAddNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_ADD_NODES* pInParam, DH_OUT_ORGANIZATION_ADD_NODES* pOutParam, int nWaitTime = 1000);

// delete nodes
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationDeleteNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_DELETE_NODES* pInParam, DH_OUT_ORGANIZATION_DELETE_NODES* pOutParam, int nWaitTime = 1000);

// get info of nodes
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationGetNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_GET_NODES* pInParam, DH_OUT_ORGANIZATION_GET_NODES* pOutParam, int nWaitTime = 1000);

//set node
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationSetNode(LLONG lLoginID, const DH_IN_ORGANIZATION_SET_NODE* pInParam, DH_OUT_ORGANIZATION_SET_NODE* pOutParam, int nWaitTime = 1000);


//////////////////////////////// network caught /////////////////////////////////

// start caught
CLIENT_API LLONG CALL_METHOD CLIENT_StartSniffer(LLONG lLoginID, const DH_IN_START_SNIFFER* pInParam, DH_OUT_START_SNIFFER* pOutParam, int nWaitTime = 1000);

// stop caught
CLIENT_API BOOL CALL_METHOD CLIENT_StopSniffer(LLONG lLoginID, LLONG lSnifferID);

// get caught state
CLIENT_API BOOL CALL_METHOD CLIENT_GetSnifferInfo(LLONG lLoginID, const DH_IN_GET_SNIFFER_INFO* pInParam, DH_OUT_GET_SNIFFER_INFO* pOutParam, int nWaitTime = 1000);

//////////////////////////////// Play Library Related Port /////////////////////////////////

//Snapshot JPEG
CLIENT_API BOOL CALL_METHOD  CLIENT_GetPicJPEG(LLONG lPlayHandle, BYTE* pJpegBuf, DWORD dwBufSize,DWORD *pJpegSize,int quality);


//////////////////////////////// manage remote file /////////////////////////////////

// create file
CLIENT_API BOOL CALL_METHOD CLIENT_CreateRemoteFile(LLONG lLoginID, const DH_IN_CREATE_REMOTE_FILE* pInParam, DH_OUT_CREATE_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// remove file
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveRemoteFiles(LLONG lLoginID, const DH_IN_REMOVE_REMOTE_FILES* pInParam, DH_OUT_REMOVE_REMOTE_FILES* pOutParam, int nWaitTime = 1000);

// rename
CLIENT_API BOOL CALL_METHOD CLIENT_RenameRemoteFile(LLONG lLoginID, const DH_IN_RENAME_REMOTE_FILE* pInParam, DH_OUT_RENAME_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// display files and subdirectories in a directory
CLIENT_API BOOL CALL_METHOD CLIENT_ListRemoteFile(LLONG lLoginID, const DH_IN_LIST_REMOTE_FILE* pInParam, DH_OUT_LIST_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// sybcgribize fule upload
CLIENT_API BOOL CALL_METHOD CLIENT_UploadRemoteFile(LLONG lLoginID, const DH_IN_UPLOAD_REMOTE_FILE* pInParam, DH_OUT_UPLOAD_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// remote project, play audio file on device end
CLIENT_API BOOL CALL_METHOD CLIENT_PlayAudioFile(LLONG lLoginID, const NET_IN_PLAY_AUDIO_FILE* pInParam, NET_OUT_PLAY_AUDIO_FILE* pOutParam, int nWaitTime = 1000);

// file download, only for small file
CLIENT_API BOOL CALL_METHOD CLIENT_DownloadRemoteFile(LLONG lLoginID, const DH_IN_DOWNLOAD_REMOTE_FILE* pInParam, DH_OUT_DOWNLOAD_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// set file property
CLIENT_API BOOL CALL_METHOD CLIENT_SetFileAttribute(LLONG lLoginID, const DH_IN_SET_FILEATTRIBUTE* pInParam, DH_OUT_SET_FILEATTRIBUTE* pOutParam, int nWaitTime = 1000);

////////////////////////////////// manage storage device ////////////////////////////////////////

// Get ISCSI target list
CLIENT_API BOOL CALL_METHOD	CLIENT_GetISCSITargets(LLONG lLoginID, const DH_IN_ISCSI_TARGETS* pInParam, DH_OUT_ISCSI_TARGETS* pOutParam, int nWaitTime = 1000);

CLIENT_API BOOL CALL_METHOD CLIENT_GetBitmap(LLONG lLoginID , const DH_IN_BITMAP* pInParam, DH_OUT_BITMAP* pOutParam, int nWaitTime = 1000);

// Get storage device name list
CLIENT_API BOOL CALL_METHOD	CLIENT_GetStorageDeviceNames(LLONG lLoginID, DH_STORAGE_DEVICE_NAME* pstuNames, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);

// Get storage device info
CLIENT_API BOOL CALL_METHOD	CLIENT_GetStorageDeviceInfo(LLONG lLoginID, const char* pszDevName, DH_STORAGE_DEVICE* pDevice, int nWaitTime = 1000);

// subscribe record file update info
CLIENT_API LLONG CALL_METHOD CLIENT_AttachRecordInfo(LLONG lLoginID, const NET_IN_ATTACH_RECORD_INFO* pInParam, NET_OUT_ATTACH_RECORD_INFO* pOutParam, int nWaitTime = 1000);

// cancel subscribe record file update info??lAttachHandle is CLIENT_AttachRecordInfo return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachRecordInfo(LLONG lAttachHandle);

// subscribe writing in remote torage info status
CLIENT_API LLONG CALL_METHOD CLIENT_NetStorageAttachWriteInfo(LLONG lLoginID, const NET_IN_STORAGE_ATTACH_WRITE_INFO* pInParam, NET_OUT_STORAGE_ATTACH_WRITE_INFO* pOutParam, int nWaitTime);

// cancel writing in remote device info??lAttachHandle is CLIENT_NetStorageAttachWriteInfo?? return value
CLIENT_API BOOL CALL_METHOD CLIENT_NetStorageDetachWriteInfo(LLONG lAttachHandle);

// search remote storage wiring in info status
CLIENT_API BOOL CALL_METHOD CLIENT_NetStorageGetWriteInfo(LLONG lLoginID, const NET_IN_STORAGE_GET_WRITE_INFO* pInParam, NET_OUT_STORAGE_GET_WRITE_INFO* pOutParam, int nWaitTime);

// RAID operation, different operation type corresponding different structures 
CLIENT_API BOOL CALL_METHOD CLIENT_OperateRaid(LLONG lLoginID, NET_RAID_OPERATE_TYPE emType, void* pInBuf, void* pOutBuf, int nWaitTime);

/////////////////////////////////// cascade device ///////////////////////////////////////

// search cascade video
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSearch(LLONG lLoginID, const DH_IN_MATRIX_SEARCH* pInParam, DH_OUT_MATRIX_SEARCH* pOutParam, int nWaitTime = 1000);

// get cascade tree
CLIENT_API BOOL CALL_METHOD CLIENT_GetMatrixTree(LLONG lLoginID, const DH_IN_GET_MATRIX_TREE* pInParam, DH_OUT_GET_MATRIX_TREE* pOutParam, int nWaitTime = 1000);

// get superior cascade device list info
CLIENT_API BOOL CALL_METHOD CLIENT_GetSuperiorMatrixList(LLONG lLoginID, const DH_IN_GET_SUPERIOR_MATRIX_LIST* pInParam, DH_OUT_GET_SUPERIOR_MATRIX_LIST* pOutParam, int nWaitTime = 1000);

/************************************************************************/
/*							backup record comes back                    */
/************************************************************************/

// start record backup restore
CLIENT_API LLONG CALL_METHOD CLIENT_StartRecordBackupRestore(LLONG lLoginID);

// stop record backup restore
CLIENT_API void CALL_METHOD CLIENT_StopRecordBackupRestore(LLONG lRestoreID);

// add record backup restore task
CLIENT_API BOOL CALL_METHOD CLIENT_AddRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_ADD_REC_BAK_RST_TASK* pInParam, int nWaitTime = 1000);

// remove record backup restore task
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_REMOVE_REC_BAK_RST_TASK* pInParam, int nWaitTime = 1000);

// get record backup restore task
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_QUERY_REC_BAK_RST_TASK* pInParam, DH_OUT_QUERY_REC_BAK_RST_TASK* pOutParam, int nWaitTime = 1000);

//////////////////////////////// Encode Manager  ////////////////////////////////
// judicial burn in plan parameter coding
CLIENT_API BOOL CALL_METHOD CLIENT_GetEncodePlan(LLONG lLoginID, const DH_IN_GET_ENCODE_PLAN* pInParam, DH_OUT_GET_ENCODE_PLAN* pOutParam, int nWaitTime = 1000);

/************************************************************************/
/*                           database record operation                         */
/************************************************************************/
// by search filter search record
CLIENT_API BOOL    CALL_METHOD CLIENT_FindRecord(LLONG lLoginID, NET_IN_FIND_RECORD_PARAM* pInParam, NET_OUT_FIND_RECORD_PARAM* pOutParam, int waittime=1000);    

// search record :nFilecount: need search items,  return value as media file items  return value<nFilecountas corresponding period file search complete
CLIENT_API int    CALL_METHOD CLIENT_FindNextRecord(NET_IN_FIND_NEXT_RECORD_PARAM* pInParam, NET_OUT_FIND_NEXT_RECORD_PARAM* pOutParam, int waittime=1000);

// search record items
CLIENT_API BOOL    CALL_METHOD CLIENT_QueryRecordCount(NET_IN_QUEYT_RECORD_COUNT_PARAM* pInParam, NET_OUT_QUEYT_RECORD_COUNT_PARAM* pOutParam, int waittime=1000);

// end record search
CLIENT_API BOOL CALL_METHOD CLIENT_FindRecordClose(LLONG lFindHandle);

/************************************************************************/
/*                            PTZ metadata port subcribe                */
/************************************************************************/
// subscribe PTZ metadata port
CLIENT_API LLONG CALL_METHOD CLIENT_AttachPTZStatusProc(LLONG lLoginID, NET_IN_PTZ_STATUS_PROC *pstuInPtzStatusProc,  NET_OUT_PTZ_STATUS_PROC *pstuOutPtzStatusProc, int nWaitTime = 3000);

// stop subscribe PTZ metadata port??lAttachHandle is CLIENT_AttachPTZStatusProc return value
CLIENT_API BOOL    CALL_METHOD    CLIENT_DetachPTZStatusProc(LLONG lAttachHandle);

/************************************************************************/
/*                            PTZ visual domain subcribe                */
/************************************************************************/
// subscribe PTZ visual domain
CLIENT_API LLONG CALL_METHOD CLIENT_AttachViewRangeState(LLONG lLoginID, NET_IN_VIEW_RANGE_STATE *pstuInViewRange, NET_OUT_VIEW_RANGE_STATE *pstuOutViewRange, int nWaitTime = 3000);

// stop subscribe PTZ visual domain??lAttachHandle is CLIENT_AttachViewRangeState return value
CLIENT_API BOOL    CALL_METHOD    CLIENT_DetachViewRangeState(LLONG lAttachHandle);

/************************************************************************/
/*                            BUS order                                 */
/************************************************************************/
// order Bus status
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBusState(LLONG lLoginID, NET_IN_BUS_ATTACH *pstuInBus, NET_OUT_BUS_ATTACH *pstuOutBus, int nWaitTime = 3000);

// stop order Bus status??lAttachHandle is CLIENT_AttachBusState return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBusState(LLONG lAttachHandle);

/************************************************************************/
/*                            analog alarm channel data subcribe        */
/************************************************************************/

// subscribe analog alarm channel data
CLIENT_API LLONG CALL_METHOD CLIENT_AttachAnalogAlarmData(LLONG lLoginID, const NET_IN_ANALOGALARM_DATA* pInParam, NET_OUT_ANALOGALARM_DATA* pOutParam, int nWaitTime);

// stop subscribe analog alarm channel data
CLIENT_API BOOL CALL_METHOD CLIENT_DetachAnalogAlarmData(LLONG lAttachHandle);

/************************************************************************/
/*               record  change port order              */
/************************************************************************/

// order record  change port 
CLIENT_API LLONG CALL_METHOD CLIENT_AttachRecordUpdater(LLONG lLoginID, const NET_IN_RECORDUPDATER_DATA* pInParam, NET_OUT_RECORDUPDATER_DATA* pOutParam, int nWaitTime);

// stoporder record  change port 
CLIENT_API BOOL CALL_METHOD CLIENT_DetachRecordUpdater(LLONG lAttachHandle);

////////////////////////////Special Version Interface///////////////////////////////
// open log function
CLIENT_API BOOL CALL_METHOD CLIENT_LogOpen(LOG_SET_PRINT_INFO *pstLogPrintInfo);

// close log function
CLIENT_API BOOL CALL_METHOD CLIENT_LogClose();

// Search device log--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogEx(LLONG lLoginID, DH_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);

// Start query log(support BSC only)
CLIENT_API LLONG CALL_METHOD CLIENT_StartQueryLog(LLONG lLoginID, const NET_IN_START_QUERYLOG* pInParam, NET_OUT_START_QUERYLOG* pOutParam, int nWaitTime);

// Query next log(support BSC only)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNextLog(LLONG lLogID, NET_IN_QUERYNEXTLOG* pInParam, NET_OUT_QUERYNEXTLOG* pOutParam, int nWaitTime);

// Stop query log(support BSC only)
CLIENT_API BOOL CALL_METHOD CLIENT_StopQueryLog(LLONG lLogID);

// Active registered redirect function,establish directed connections
CLIENT_API LONG CALL_METHOD CLIENT_ControlConnectServer(LLONG lLoginID, char* RegServerIP, WORD RegServerPort, int TimeOut=3000);

// Establish active registered connection
CLIENT_API BOOL CALL_METHOD CLIENT_ControlRegisterServer(LLONG lLoginID, LONG ConnectionID, int waittime=1000);

// Disconnected directional connection
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDisconnectRegServer(LLONG lLoginID, LONG ConnectionID);

// Query active registered server information
CLIENT_API BOOL CALL_METHOD CLIENT_QueryControlRegServerInfo(LLONG lLoginID, LPDEV_SERVER_AUTOREGISTER lpRegServerInfo, int waittime=2000);

// Upload file
CLIENT_API LLONG CALL_METHOD CLIENT_FileTransmit(LLONG lLoginID, int nTransType, char* szInBuf, int nInBufLen, fTransFileCallBack cbTransFile, LDWORD dwUserData, int waittime);

// web info trasmit
CLIENT_API BOOL  CALL_METHOD CLIENT_TransmitInfoForWeb(LLONG lLoginID, char* szInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize, void* pExtData, int waittime=500);

// watermark verify for picture *nResult = 0-means no verify *nResult = 1-means has verify
CLIENT_API BOOL  CALL_METHOD CLIENT_WatermarkVerifyForPicture(char* szFilePath, int* nResult, void* pReserved);

// multi realplay
CLIENT_API BOOL  CALL_METHOD CLIENT_MultiRealPlay(LLONG lLoginID, DHDEV_IN_MULTIPLAY_PARAM* pInBuf, int nInBufLen, DHDEV_OUT_MULTIPLAY_PARAM* pOutBuf, int nOutBufLen, int* pRetLen);
 
// stop multi realplay
CLIENT_API BOOL  CALL_METHOD CLIENT_StopMultiRealPlay(LLONG* lRealHandles, int nNumOfHandles);

// when hwnd != null,set playback yuv data callback 
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlaybackYUVCallBack(LLONG lPlayHandle, fYUVDataCallBack cYUVData, LDWORD dwUser);

// get web configuration
CLIENT_API BOOL CALL_METHOD CLIENT_GetNewDevConfigForWeb(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// set configuration for web
CLIENT_API BOOL CALL_METHOD CLIENT_SetNewDevConfigForWeb(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// create port mapping
CLIENT_API int CALL_METHOD CLIENT_CreateOneTunnel(LPOSN_IN_CREATE_TUNNEL_PARAM pInParam, LPOSN_OUT_CREATE_TUNNEL_PARAM pOutParam, int waittime=1000);

// delete port mapping
CLIENT_API int CALL_METHOD CLIENT_DestroyOneTunnel(LPOSN_IN_DESTROY_TUNNEL_PARAM pInParam);

// set play strategy parameter, only valid for real time
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayMethod(LLONG lRealHandle, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

// close device auto registration link
CLIENT_API BOOL CALL_METHOD CLIENT_CloseRegConnect(LLONG lHandle, char *pIp, WORD wPort, void *pParam);

// by file playback??attached device IP, proxy use only
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFileProxy(LLONG lLoginID, NET_IN_PLAYBACK_BYFILE_PROXY* pInParam, NET_OUT_PLAYBACK_BYFILE_PROXY* pOutParam);

// by time playback??attached device IP, proxy use only
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTimeProxy(LLONG lLoginID, NET_IN_PLAYBACK_BYTIME_PROXY* pInParam, NET_OUT_PLAYBACK_BYTIME_PROXY* pOutParam);

// Import configuration file (JSON) pSendBuf: To send data, the user allocates memory, nSendBufLen: The length of the sent, reserved: retention parameter
CLIENT_API BOOL CALL_METHOD CLIENT_ImportConfigFileJson(LLONG lLoginID, char *pSendBuf, int nSendBufLen, void* reserved=NULL, int nWaitTime=3000);
// Export the configuration file (JSON) pOutBuffer: Receive buffer, The user allocates memory, maxlen: Receive buffer length, nRetlen: The actual length derived, reserved: retention parameter
CLIENT_API BOOL CALL_METHOD CLIENT_ExportConfigFileJson(LLONG lLoginID, char *pOutBuffer, int maxlen, int *nRetlen, void* reserved=NULL, int nWaitTime=3000);

//////Shanghai BUS//////

#ifdef SHANGHAIBUS
// serial data switch port,async get data
CLIENT_API LLONG CALL_METHOD CLIENT_ExChangeData(LLONG lLoginId, NET_IN_EXCHANGEDATA* pInParam, NET_OUT_EXCHANGEDATA* pOutParam, int nWaittime = 5000);

// listen CAN bus data
CLIENT_API LLONG CALL_METHOD CLIENT_AttachCAN(LLONG lLoginID, const NET_IN_ATTACH_CAN* pstInParam, NET_OUT_ATTACH_CAN* pstOutParam, int nWaitTime = 3000);

// cancel listen CAN bus data??lAttachHandle is CLIENT_AttachCAN return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachCAN(LLONG lAttachHandle);

// Send CAN BUS data
CLIENT_API BOOL CALL_METHOD CLIENT_SendCAN(LLONG lLoginID, const NET_IN_SEND_CAN* pstInParam, NET_OUT_SEND_CAN* pstOutParam, int nWaitTime = 3000);

// listen transparent serial data
CLIENT_API LLONG CALL_METHOD CLIENT_AttachDevComm(LLONG lLoginID, const NET_IN_ATTACH_DEVCOMM* pstInParam, NET_OUT_ATTACH_DEVCOMM* pstOutParam, int nWaitTime = 3000);

// cancel listen transparent serial data??lAttachHandle is CLIENT_AttachDevComm return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachDevComm(LLONG lAttachHandle);

#endif

// RPC capacity search
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRpcMethod(LLONG lLoginID, const char* pszMethod, BOOL* pResult, int nWaitTime);

//////////////////////////////////////////////////////////////////////////
// Public transport business relevant interface
//////////////////////////////////////////////////////////////////////////

// check bus route
CLIENT_API BOOL CALL_METHOD CLIENT_CheckBusLine(LLONG lLoginID, const NET_IN_CHECK_BUS_LINE* pstInParam, NET_OUT_CHECK_BUS_LINE* pstOutParam, int nWaitTime = 5000);

// send bus route info
CLIENT_API BOOL CALL_METHOD CLIENT_DispatchBusLineInfo(LLONG lLoginID, const NET_IN_DISPATCH_BUS_LINE_INFO* pstInParam, NET_OUT_DISPATCH_BUS_LINE_INFO* pstOutParam, int nWaitTime = 5000);

// vehicle operation dispatch 
CLIENT_API BOOL CALL_METHOD CLIENT_BusSchedule(LLONG lLoginID, const NET_IN_BUS_SCHEDULE_INFO* pstInParam, NET_OUT_BUS_SCHEDULE_INFO* pstOutParam, int nWaitTime = 5000);

// Issued by the vehicle scheduling plan
CLIENT_API BOOL CALL_METHOD CLIENT_DispatchWorkPlan(LLONG lLoginID, const NET_IN_BUS_DISPATCH_WORK_PLAN* pstInParam, NET_OUT_BUS_DISPATCH_WORK_PLAN* pstOutParam, int nWaitTime);

CLIENT_API BOOL CALL_METHOD CLIENT_AddMission(LLONG lLoginID, const NET_IN_ADD_MISSION* pstInParam, NET_OUT_ADD_MISSION* pstOutParam, int nWaitTime = 3000);

// Start car pass record search
CLIENT_API LLONG CALL_METHOD CLIENT_ParkingControlStartFind(LLONG lLoginID, NET_IN_PARKING_CONTROL_START_FIND_PARAM* pInParam, NET_OUT_PARKING_CONTROL_START_FIND_PARAM* pOutParam, int waittime);

// Get car pass record
CLIENT_API BOOL CALL_METHOD CLIENT_ParkingControlDoFind(LLONG lFindeHandle, NET_IN_PARKING_CONTROL_DO_FIND_PARAM* pInParam, NET_OUT_PARKING_CONTROL_DO_FIND_PARAM* pOutParam, int waittime);

// End car pass record search
CLIENT_API BOOL CALL_METHOD CLIENT_ParkingControlStopFind(LLONG lFindHandle);

// Car pass record order
CLIENT_API LLONG CALL_METHOD CLIENT_ParkingControlAttachRecord(LLONG lLoginID, const NET_IN_PARKING_CONTROL_PARAM* pInParam, NET_OUT_PARKING_CONTROL_PARAM* pOutParam, int nWaitTime);

// Cancel car pass record order
CLIENT_API BOOL CALL_METHOD CLIENT_ParkingControlDetachRecord(LLONG lAttachHandle);

// order monitor spot info
CLIENT_API LLONG CALL_METHOD CLIENT_SCADAAttachInfo(LLONG lLoginID, const NET_IN_SCADA_ATTACH_INFO* pInParam, NET_OUT_SCADA_ATTACH_INFO* pOutParam, int nWaitTime);

// cancel monitor spot info order
CLIENT_API BOOL CALL_METHOD CLIENT_SCADADetachInfo(LLONG lAttachHandle);

// scada get threshold
CLIENT_API BOOL CALL_METHOD CLIENT_SCADAGetThreshold(LLONG lLoginID, const NET_IN_SCADA_GET_THRESHOLD* pInParam, NET_OUT_SCADA_GET_THRESHOLD* pOutParam, int nWaitTime);

// scada set threshold
CLIENT_API BOOL CALL_METHOD CLIENT_SCADASetThreshold(LLONG lLoginID, const NET_IN_SCADA_SET_THRESHOLD* pInParam, NET_OUT_SCADA_SET_THRESHOLD* pOutParam, int nWaitTime);

// scada start find history info
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindSCADA(LLONG lLoginID, const NET_IN_SCADA_START_FIND* pInParam, NET_OUT_SCADA_START_FIND* pOutParam, int nWaitTime);

// scada do find history info
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindSCADA(LLONG lFindHandle, const NET_IN_SCADA_DO_FIND* pInParam, NET_OUT_SCADA_DO_FIND* pOutParam, int nWaitTime);

// scada stop find history info
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindSCADA(LLONG lFindHandle);

// scada attach alarm event
CLIENT_API LLONG CALL_METHOD CLIENT_SCADAAlarmAttachInfo(LLONG lLoginID, const NET_IN_SCADA_ALARM_ATTACH_INFO* pInParam, NET_OUT_SCADA_ALARM_ATTACH_INFO* pOutParam, int nWaitTime = 3000);

// scada detach alarm event
CLIENT_API BOOL CALL_METHOD CLIENT_SCADAAlarmDetachInfo(LLONG lAttachHandle);

// scada set point info
CLIENT_API BOOL CALL_METHOD CLIENT_SCADASetInfo(LLONG lLoginID, const NET_IN_SCADA_POINT_SET_INFO_LIST* pInParam, NET_OUT_SCADA_POINT_SET_INFO_LIST* pOutParam, int nWaitTime = 3000);

//////////////////////////////////////////////////////////////////////////

// Order wireless code info port
CLIENT_API LLONG CALL_METHOD CLIENT_AttachLowRateWPAN(LLONG lLoginID, const NET_IN_ATTACH_LOWRATEWPAN* pstInParam, NET_OUT_ATTACH_LOWRATEWPAN* pstOutParam, int nWaitTime = 3000);

// Cancel order wireless info port??lAttachHandle is CLIENT_AttachLowRateWPAN return value
CLIENT_API BOOL CALL_METHOD CLIENT_DetachLowRateWPAN(LLONG lAttachHandle);

//Get play library port used to decode and display in preview, close resource type of gotten port,it will affect normal operaton
CLIENT_API LONG CALL_METHOD CLIENT_GetRealPlayPort(LLONG lRealPlayHandle);

// Get play library port used to decode and display in preview, close resource type of gotten port,it will affect normal operaton
CLIENT_API LONG CALL_METHOD  CLIENT_GetPlayBackPort(LLONG lPlayBackHandle);

// Parking state subscription
CLIENT_API LLONG CALL_METHOD CLIENT_ParkingControlAttachParkInfo(LLONG lLoginID, const NET_IN_PARK_INFO_PARAM* pInParam, NET_OUT_PARK_INFO_PARAM* pOutParam, int nWaitTime);

// Cancel the parking state subscription
CLIENT_API BOOL CALL_METHOD CLIENT_ParkingControlDetachParkInfo(LLONG lAttachHandle);

// Subscribe to the video phone status information
CLIENT_API LLONG CALL_METHOD CLIENT_AttachVTPCallState(LLONG lLoginID, const NET_IN_VTP_CALL_STATE_ATTACH* pInParam, NET_OUT_VTP_CALL_STATE_ATTACH* pOutParam, int nWaitTime);

// Unsubscribe video phone status information
CLIENT_API BOOL CALL_METHOD CLIENT_DetachVTPCallState(LLONG lCallStateHandle);

// set mobile push notification, use RegisterID to identify the config info
CLIENT_API BOOL CALL_METHOD CLIENT_SetMobilePushNotify(LLONG lLoginID, const NET_MOBILE_PUSH_NOTIFY *pstuCfg, int *nError, int *nRestart, int nWaitTime = 1000);

// delete mobile push notification, use RegisterID to identify the config info
CLIENT_API BOOL CALL_METHOD CLIENT_DelMobilePushNotify(LLONG lLoginID, const NET_MOBILE_PUSH_NOTIFY_DEL *pstuIn, NET_OUT_DELETECFG* pstuOut, int nWaitTime = 1000);

// set mobile push notification config, use RegisterID+AppID to identify the info
CLIENT_API BOOL CALL_METHOD CLIENT_SetMobilePushNotifyCfg(LLONG lLoginID, const NET_MOBILE_PUSH_NOTIFY_CFG *pstuCfg, int *nError, int *nRestart, int nWaitTime = 1000);

// delete mobile push notification config, use RegisterID+AppID to identify the info
CLIENT_API BOOL CALL_METHOD CLIENT_DelMobilePushNotifyCfg(LLONG lLoginID, const NET_MOBILE_PUSH_NOTIFY_CFG_DEL *pstuIn, NET_OUT_DELETECFG* pstuOut, int nWaitTime = 1000);

// Net applications
CLIENT_API BOOL CALL_METHOD CLIENT_RPC_NetApp(LLONG lLoginID, EM_RPC_NETAPP_TYPE emType, const void* pstuIn, void* pstuOut, int nWaitTime = 1000);

// Set optimize mode
CLIENT_API BOOL CALL_METHOD CLIENT_SetOptimizeMode(EM_OPTIMIZE_TYPE emType, void *pParam);
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Cancelled Interface/////////////////////////////////

// Search system server setup. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// Set system server setup. This interface is invalid now please use  CLIENT_SetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_SetupConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// This interface is invalid now. 
CLIENT_API BOOL CALL_METHOD CLIENT_Reset(LLONG lLoginID, BOOL bReset);

// Search COM protocol. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryComProtocol(LLONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// Begin audio talk. This interface is invalid now. Please use  CLIENT_StartTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StartTalk(LLONG lRealHandle, BOOL bCustomSend=false);

// Stop audio talk. This interface is invalid now , please use  CLIENT_StopTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalk(LLONG lRealHandle);

// Send out self-defined audio talk data. This interface is invalid now, please use  CLIENT_TalkSendData
CLIENT_API BOOL CALL_METHOD CLIENT_SendTalkData_Custom(LLONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// Set real-time preview buffer size
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayerBufNumber(LLONG lRealHandle, DWORD dwBufNum);

// Download file by time
CLIENT_API BOOL CALL_METHOD CLIENT_GetFileByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, char *sSavedFileName);

// Network playback control 
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControl(LLONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// Search device working status .This interface is invalid now, please use  CLIENT_QueryDevState
CLIENT_API BOOL CALL_METHOD CLIENT_GetDEVWorkState(LLONG lLoginID, LPNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// Asynchronism search device log 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogCallback(LLONG lLoginID, fLogDataCallBack cbLogData, LDWORD dwUser);

    
#ifdef __cplusplus
}
#endif

#endif // DHNETSDK_H



