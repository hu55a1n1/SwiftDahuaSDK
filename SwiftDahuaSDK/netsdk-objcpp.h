//
//  netsdk-objcpp.h
//  ACC
//
//  Created by Shoaib Ahmed on 8/21/16.
//  Copyright © 2016 Kindows Tech Solutions. All rights reserved.
//

#ifndef netsdk_objcpp_h
#define netsdk_objcpp_h

#include "dahua-defs.h"
#include "dahua-p2p-defs.h"
#include "dahua-play-defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark - Client API
BOOL CALL_METHOD CLIENT_Init_(fDisConnect cbDisConnect, LDWORD dwUser);

void CALL_METHOD CLIENT_Cleanup_();

LLONG CALL_METHOD CLIENT_Login_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error);

LLONG CALL_METHOD CLIENT_LoginEx_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error);
    
BOOL CALL_METHOD CLIENT_Logout_(LLONG lLoginID);

BOOL CALL_METHOD CLIENT_GetDevConfig_(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime);

#pragma mark Client Realplay API
LLONG CALL_METHOD CLIENT_RealPlayEx_(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType);

BOOL CALL_METHOD CLIENT_StopRealPlay_(LLONG lRealHandle);

BOOL CALL_METHOD CLIENT_SetRealDataCallBack_(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser);
    

    
#pragma mark - P2P API
TOU_API ProxyClientHandler DHProxyClientInit_(const char* svrip, int svrport, const char* passwd);
    
TOU_API void DHProxyClientRelease_(ProxyClientHandler handler);
    
TOU_API int DHProxyClientAddPort_(ProxyClientHandler handler,
                                     const char* deviceId, int targetPort, int *localPort);
    
TOU_API int DHProxyClientDelPort_(ProxyClientHandler handler, int port);


TOU_API int DHProxyClientQueryRate_(ProxyClientHandler handler,
                                   int port, DHProxyClientMapPortRate *rate);

TOU_API int DHProxyClientChannelstate_(ProxyClientHandler handler, int port, DHProxyClientP2PChannelState *state);

TOU_API int DHProxyClientState_(ProxyClientHandler handler, DHProxyClientProxyState *state);

TOU_API int DHProxyClientServerState_(ProxyClientHandler handler, const char* deviceId, DHProxyClientProxyState *state);

TOU_API int DHProxyClientQueryRemoetInfo_(ProxyClientHandler handler, int port, DHProxyClientRemotePortInfo *info);

TOU_API ProxyClientHandler DHProxyClientInitWtihName_(const char* svrip, int svrport, const char* passwd, const char* username);

TOU_API	int DHProxySetOption_(ProxyClientHandler handler, DHProxyOption option, int value);

TOU_API int DHProxyGetOption_(ProxyClientHandler handler, DHProxyOption option);
    

    
#pragma mark - Play API
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream_(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
    
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream_(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_Play_(LONG nPort, HWND hWnd);
    
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop_(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_InputData_(LONG nPort,PBYTE pBuf,DWORD nSize);

PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare_(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare_(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound_();

PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort_(LONG *plPort);
    
    
#ifdef __cplusplus
}
#endif

#endif /* netsdk_objcpp_h */
