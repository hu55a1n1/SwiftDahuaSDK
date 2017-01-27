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

// Mark: Client API
BOOL CALL_METHOD CLIENT_Init_(fDisConnect cbDisConnect, LDWORD dwUser);

void CALL_METHOD CLIENT_Cleanup_();

LLONG CALL_METHOD CLIENT_Login_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error);

LLONG CALL_METHOD CLIENT_LoginEx_(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error);
    
// Log out the device
BOOL CALL_METHOD CLIENT_Logout_(LLONG lLoginID);

BOOL CALL_METHOD CLIENT_GetDevConfig_(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime);


// Mark: P2P API
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
    

#ifdef __cplusplus
}
#endif

#endif /* netsdk_objcpp_h */
