//
//  netsdk-objcpp.m
//  ACC
//
//  Created by Shoaib Ahmed on 8/21/16.
//  Copyright © 2016 Kindows Tech Solutions. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import "netsdk-objcpp.h"
#import "lib/Eng_netsdk.h"

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

