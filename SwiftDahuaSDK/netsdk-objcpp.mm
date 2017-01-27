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

// Mark: Client API
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


// Mark: P2P API
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
