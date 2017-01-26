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

    
#ifdef __cplusplus
}
#endif

#endif /* netsdk_objcpp_h */
