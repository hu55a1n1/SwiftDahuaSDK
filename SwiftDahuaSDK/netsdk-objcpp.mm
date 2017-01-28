//
//  netsdk-objcpp.m
//  ACC
//
//  Created by Shoaib Ahmed on 8/21/16.
//  Copyright © 2016 Kindows Tech Solutions. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import "netsdk-objcpp.h"
#import "include/Eng_netsdk.h"
#import "include/ProxyClientCWrap.h"
#import "include/play.h"

#pragma mark - Client API
BOOL CALL_METHOD CLIENT_Init_(fDisConnect cbDisConnect, LDWORD dwUser) {
    return CLIENT_Init(cbDisConnect, dwUser);
}

void CALL_METHOD CLIENT_Cleanup_() {
    return CLIENT_Cleanup();
}

LLONG CALL_METHOD CLIENT_Login_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0) {
    return CLIENT_Login(pchDVRIP, wDVRPort, pchUserName, pchPassword, lpDeviceInfo, error);
}

LLONG CALL_METHOD CLIENT_LoginEx_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0) {
    return CLIENT_LoginEx(pchDVRIP, wDVRPort, pchUserName, pchPassword, nSpecCap, pCapParam, lpDeviceInfo, error);
}

BOOL CALL_METHOD CLIENT_Logout_(LLONG lLoginID) {
    return CLIENT_Logout(lLoginID);
}

BOOL CALL_METHOD CLIENT_GetDevConfig_(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500) {
    return CLIENT_GetDevConfig(lLoginID, dwCommand, lChannel, lpOutBuffer, dwOutBufferSize, lpBytesReturned, waittime);
}

#pragma mark Client Realplay API
LLONG CALL_METHOD CLIENT_RealPlayEx_(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType = DH_RType_Realplay) {
    return CLIENT_RealPlayEx(lLoginID, nChannelID, hWnd, rType);
}

BOOL CALL_METHOD CLIENT_StopRealPlay_(LLONG lRealHandle) {
    return CLIENT_StopRealPlay(lRealHandle);
}

BOOL CALL_METHOD CLIENT_SetRealDataCallBack_(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser) {
    return CLIENT_SetRealDataCallBack(lRealHandle, cbRealData, dwUser);
}



#pragma mark - P2P API
TOU_API ProxyClientHandler DHProxyClientInit_(const char* svrip, int svrport, const char* passwd) {
    return DHProxyClientInit(svrip, svrport, passwd);
}

TOU_API void DHProxyClientRelease_(ProxyClientHandler handler) {
    return DHProxyClientRelease(handler);
}

TOU_API int DHProxyClientAddPort_(ProxyClientHandler handler,
                                  const char* deviceId, int targetPort, int *localPort) {
    return DHProxyClientAddPort(handler, deviceId, targetPort, localPort);
}

TOU_API int DHProxyClientDelPort_(ProxyClientHandler handler, int port) {
    return DHProxyClientDelPort(handler, port);
}

TOU_API int DHProxyClientQueryRate_(ProxyClientHandler handler,
                                    int port, DHProxyClientMapPortRate *rate) {
    return DHProxyClientQueryRate(handler, port, rate);
}

TOU_API int DHProxyClientChannelstate_(ProxyClientHandler handler, int port, DHProxyClientP2PChannelState *state) {
    return DHProxyClientChannelstate(handler, port, (int *)state);
}

TOU_API int DHProxyClientState_(ProxyClientHandler handler, DHProxyClientProxyState *state) {
    return DHProxyClientState(handler, (int *)state);
}

TOU_API int DHProxyClientServerState_(ProxyClientHandler handler, const char* deviceId, DHProxyClientProxyState *state) {
    return DHProxyClientServerState(handler, deviceId, (int *)state);
}

TOU_API int DHProxyClientQueryRemoetInfo_(ProxyClientHandler handler, int port, DHProxyClientRemotePortInfo *info) {
    return DHProxyClientQueryRemoetInfo(handler, port, info);
}

TOU_API ProxyClientHandler DHProxyClientInitWtihName_(const char* svrip, int svrport, const char* passwd, const char* username) {
    return DHProxyClientInitWtihName(svrip, svrport, passwd, username);
}

TOU_API	int DHProxySetOption_(ProxyClientHandler handler, DHProxyOption option, int value) {
    return DHProxySetOption(handler, option, value);
}

TOU_API int DHProxyGetOption_(ProxyClientHandler handler, DHProxyOption option) {
    return DHProxyGetOption(handler, option);
}



#pragma mark - Play API
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream_(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize) {
    return PLAY_OpenStream(nPort, pFileHeadBuf, nSize, nBufPoolSize);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream_(LONG nPort) {
    return PLAY_CloseStream(nPort);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_Play_(LONG nPort, HWND hWnd) {
    return PLAY_Play(nPort, hWnd);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_Stop_(LONG nPort) {
    return PLAY_Stop(nPort);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_InputData_(LONG nPort,PBYTE pBuf,DWORD nSize) {
    return PLAY_InputData(nPort, pBuf, nSize);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare_(LONG nPort) {
    return PLAY_PlaySoundShare(nPort);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare_(LONG nPort) {
    return PLAY_StopSoundShare(nPort);
}

PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound_() {
    return PLAY_StopSound();
}

PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort_(LONG *plPort) {
    return PLAY_GetFreePort(plPort);
}


