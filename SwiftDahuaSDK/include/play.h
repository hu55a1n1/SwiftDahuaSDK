/************************************************************************/
/* dhplay   °æ±¾:  3.34			                                    */
/************************************************************************/

#ifndef _DHPLAY_H
#define _DHPLAY_H

#include "../dahua-play-defs.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
/************************************************************************/
/* ½Ó¿Ú		                                                            */
/************************************************************************/

//------------------------------------------------------------------------
// º¯Êý: PLAY_OpenFile
// ÃèÊö: ´ò¿ª²¥·ÅÎÄ¼þ£¬ÓÃÓÚÔÚ²¥·ÅÎÄ¼þÖ®Ç°µ÷ÓÃ. ÎÄ¼þ²»ÄÜ³¬¹ý4G»òÐ¡ÓÚ4K
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,ÎÄ¼þÃû
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenFile(LONG nPort,LPSTR sFileName);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CloseFile
// ÃèÊö: ¹Ø±ÕÎÄ¼þ, ÔÚPLAY_Stopºóµ÷ÓÃ
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseFile(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OpenStream
// ÃèÊö: ´ò¿ªÁ÷²¥·Å
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFileHeadBuf,Ä¿Ç°²»Ê¹ÓÃ,ÌîNULL.
//		 nSize,Ä¿Ç°²»ÊÊÓÃ,Ìî0.
//		 nBufPoolSize,ÉèÖÃ²¥·ÅÆ÷ÖÐ´æ·ÅÊý¾ÝÁ÷µÄ»º³åÇø´óÐ¡.
//			·¶Î§ÊÇ[SOURCE_BUF_MIN,SOURCE_BUF_MAX].Ò»°ãÉèÎª900*1024£¬Èç¹ûÊý
//			¾ÝËÍ¹ýÀ´Ïà¶Ô¾ùÔÈ,¿Éµ÷Ð¡¸ÃÖµ,Èç¹ûÊý¾Ý´«Êä²»¾ùÔÈ,¿ÉÔö´ó¸ÃÖµ.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CloseStream
// ÃèÊö: ¹Ø±ÕÁ÷
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStream(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Play
// ÃèÊö: ¿ªÊ¼²¥·Å.Èç¹ûÒÑ¾­²¥·Å,¸Ä±äµ±Ç°²¥·Å×´Ì¬ÎªÕý³£ËÙ¶È²¥·Å.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 hWnd,²¥·Å´°¿Ú¾ä±ú
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Play(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Stop
// ÃèÊö: Í£Ö¹²¥·Å
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Stop(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_InputData
// ÃèÊö: ÊäÈëÊý¾ÝÁ÷,PLAY_PlayÖ®ºóÊ¹ÓÃ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBuf,»º³åÇøµØÖ·
//		 nSize,»º³åÇø´óÐ¡
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.ÈçÊ§°Ü,Ò»°ãÊÇ»º³åÇøÒÑÂú,ÓÃ»§¿ÉÔÝÍ£
//			ÊäÈë£¬Ò»¶ÎÊ±¼äÖ®ºóÔÙÊäÈëÁ÷£¬È·±£²¥·Å¿â²»¶ªÊ§Êý¾Ý¡£
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Pause
// ÃèÊö: ÔÝÍ£»òÕß»Ö¸´²¥·Å
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nPause,TRUEÔÝÍ£,FLASE»Ö¸´
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Pause(LONG nPort,DWORD nPause);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Fast
// ÃèÊö: ²¥·ÅËÙ¶È·ÖÎª¾Å¼¶,²¥·ÅËÙ¶È·Ö±ðÎªÃ¿Ãë²¥·Å1,3,6,12,25,50,75,100,125Ö¡
//		 Í¼Ïñ.Ã¿´Îµ÷ÓÃ²¥·ÅËÙ¶ÈÌáÉýÒ»¼¶,×î¶àµ÷ÓÃ4´Î,Òª»Ö¸´Õý³£²¥·Åµ÷ÓÃ
//		 PLAY_Play,´Óµ±Ç°Î»ÖÃ¿ªÊ¼Õý³£²¥·Å.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Fast(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Slow
// ÃèÊö: Ã¿´Îµ÷ÓÃ²¥·ÅËÙ¶È½µÒ»¼¶,×î¶àµ÷ÓÃ4´Î,Òª»Ö¸´Õý³£²¥·Åµ÷ÓÃPLAY_Play.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Slow(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OneByOne
// ÃèÊö: µ¥èå²¥·Å,Òª»Ö¸´Õý³£²¥·Åµ÷ÓÃPLAY_ Play.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOne(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayPos
// ÃèÊö: ÉèÖÃÎÄ¼þ²¥·ÅÖ¸ÕëµÄÏà¶ÔÎ»ÖÃ(°Ù·Ö±È)
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 fRelativePos,ÎÄ¼þ³¤¶ÈµÄ°Ù·Ö±È
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPos(LONG nPort,float fRelativePos);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayDirection
// ÃèÊö: ÉèÖÃ²¥·Å·½Ïò
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 emDirection,²¥·Å·½Ïò£º0£¬ÏòÇ°£¬1£¬Ïòºó
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayDirection(LONG nPort, DWORD emDirection);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPlayPos
// ÃèÊö: »ñÈ¡ÎÄ¼þ²¥·ÅÖ¸ÕëµÄÏà¶ÔÎ»ÖÃ(°Ù·Ö±È)
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: float,ÎÄ¼þ³¤¶ÈµÄÏà¶ÔÎ»ÖÃ,·¶Î§0-100%
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetPlayPos(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileEndMsg
// ÃèÊö: ÉèÖÃÎÄ¼þ½áÊøÊ±Òª·¢ËÍµÄÏûÏ¢
// ²ÎÊý: nPort,¶Ë¿ÚºÅ
//       hWnd,ÏûÏ¢·¢ËÍ´°¿Ú
//       nMsg,ÓÃ»§×Ô¶¨ÒåµÄÊäÈëµÄÏûÏ¢£¬µ±²¥·Åµ½ÎÄ¼þ½áÊøÊ±ÓÃ»§ÔÚhWnd´°¿Ú¹ý³ÌÖÐ
//			ÊÕµ½Õâ¸öÏûÏ¢¡£´ËÏûÏ¢ÖÐµÄwParam»òÕßlParam¶¼¿ÉÒÔ»ñµÃnPortµÄÖµ.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetVolume
// ÃèÊö: ÉèÖÃÒôÁ¿,ÉèÖÃµÄÒôÁ¿ÊÇÖ¸Éù¿¨Êä³öµÄÒôÁ¿,»áÓ°ÏìÆäËûµÄÉùÒôÓ¦ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nVolume,ÒôÁ¿µÄÖµ,·¶Î§[0,0xFFFF]
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVolume(LONG nPort,WORD nVolume);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopSound
// ÃèÊö: ¹Ø±Õ¶ÀÕ¼·½Ê½ÉùÒô
// ²ÎÊý: 
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSound();

//------------------------------------------------------------------------
// º¯Êý: PLAY_PlaySound
// ÃèÊö: ¶ÀÕ¼·½Ê½´ò¿ªÉùÒô,Í¬Ò»Ê±¿ÌÖ»ÄÜÓÐÒ»Â·ÉùÒô,Èç¹ûÏÖÔÚÒÑ¾­ÓÐÉùÒô´ò¿ª£¬Ôò
//		 ×Ô¶¯¹Ø±ÕÔ­À´ÒÑ¾­´ò¿ªµÄÉùÒô.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySound(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetFileTime
// ÃèÊö: »ñÈ¡ÎÄ¼þ×ÜÊ±¼ä
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: ÎÄ¼þ×ÜµÄÊ±¼ä³¤¶ÈÖµ,µ¥Î»Ãë.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTime(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPlayedTime
// ÃèÊö: »ñÈ¡µ±Ç°ÎÄ¼þ²¥·ÅÊ±¼ä
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: ÎÄ¼þµ±Ç°²¥·ÅµÄÊ±¼ä,µ¥Î»Ãë
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTime(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPlayedFrames
// ÃèÊö: »ñÈ¡ÒÑ²¥·ÅµÄèåÊý
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: ÒÑ¾­½âÂëµÄÊÓÆµÖ¡Êý
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedFrames(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDecodeCallBack
// ÃèÊö: ÉèÖÃ½âÂë»Øµ÷,Ìæ»»²¥·ÅÆ÷ÖÐµÄÏÔÊ¾²¿·Ö,ÓÉÓÃ»§×Ô¼º¿ØÖÆÏÔÊ¾,¸Ãº¯ÊýÔÚ
//			PLAY_PlayÖ®Ç°µ÷ÓÃ,ÔÚPLAY_StopÊ±×Ô¶¯Ê§Ð§,ÏÂ´Îµ÷ÓÃPLAY_PlayÖ®Ç°
//			ÐèÒªÖØÐÂÉèÖÃ.½âÂë²¿·Ö²»¿ØÖÆËÙ¶È,Ö»ÒªÓÃ»§´Ó»Øµ÷º¯ÊýÖÐ·µ»Ø,½âÂëÆ÷
//			¾Í»á½âÂëÏÂÒ»²¿·ÖÊý¾Ý.ÊÊÓÃÓÚÖ»½âÂë²»ÏÔÊ¾µÄÇéÐÎ¡£
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 cbDec,½âÂë»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL.»Øµ÷º¯Êý²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pFrameDecodeInfo,½âÂëºóµÄÒôÊÓÆµÊý¾Ý
//			pFrameInfo,Í¼ÏñºÍÉùÒôÐÅÏ¢,Çë²Î¼ûFRAME_INFO½á¹¹Ìå
//			pUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBDecode)(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDisplayCallBack
// ÃèÊö: ÉèÖÃÊÓÆµ×¥Í¼»Øµ÷º¯Êý.Èç¹ûÒªÍ£Ö¹»Øµ÷,¿ÉÒÔ°Ñ»Øµ÷º¯ÊýÖ¸ÕëÉèÎªNULL,¸Ã
//			º¯Êý¿ÉÒÔÔÚÈÎºÎÊ±ºòµ÷ÓÃ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DisplayCBFun,×¥Í¼»Øµ÷º¯Êý,¿ÉÒÔÎªNULL,Æä²ÎÊýº¬ÒåÈçÏÂ
//			nPort,Í¨µÀºÅ
//			pBuf,·µ»ØÍ¼ÏñÊý¾Ý
//			nSize,·µ»ØÍ¼ÏñÊý¾Ý´óÐ¡
//			nWidth,»­Ãæ¿í,µ¥Î»ÏñËØ
//			nHeight,»­Ãæ¸ß
//			nStamp,Ê±±êÐÅÏ¢£¬µ¥Î»ºÁÃë
//			nType,Êý¾ÝÀàÐÍ,T_RGB32,T_UYVY,Ïê¼ûºê¶¨ÒåËµÃ÷
//			nReceaved,¶ÔÓ¦ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDisplayCBFun)(LONG nPort,char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nStamp,LONG nType, void* pReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayCallBack(LONG nPort, fDisplayCBFun DisplayCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ConvertToBmpFile
// ÃèÊö: Í¼Ïñ¸ñÊ½×ªÎªBMP¸ñÊ½.
// ²ÎÊý: pBuf,Í¼ÏñÊý¾ÝÖ¸Õë
//		 nSize,Í¼ÏñÊý¾Ý´óÐ¡
//		 nWidth,Í¼Ïñ¿í¶È
//		 nHeight,Í¼Ïñ¸ß¶È
//		 nType,Êý¾ÝÀàÐÍ.T_RGB32,T_UYVYµÈ.
//		 sFileName,Òª±£´æµÄÎÄ¼þÃû.×îºÃÒÔBMP×÷ÎªÎÄ¼þÀ©Õ¹Ãû.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ConvertToJpegFile
// ÃèÊö: Í¼Ïñ¸ñÊ½×ªÎªJPEG¸ñÊ½.
// ²ÎÊý: pYUVBuf,Í¼ÏñÊý¾ÝÖ¸Õë
//		 nWidth,Í¼Ïñ¿í¶È
//		 nHeight,Í¼Ïñ¸ß¶È
//		 YUVtype,YUVÊý¾ÝÀàÐÍ,ÈçT_YV12,T_UYVY
//		 quality,Í¼Æ¬Ñ¹ËõÖÊÁ¿,·¶Î§(0, 100].
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetFileTotalFrames
// ÃèÊö: »ñÈ¡ÎÄ¼þ×ÜÖ¡Êý
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: DWORD,ÎÄ¼þÖÐµÄ×ÜÖ¡Êý
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileTotalFrames(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetCurrentFrameRate
// ÃèÊö: »ñÈ¡µ±Ç°Ö¡ÂÊ
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: DWORD,µ±Ç°ÂëÁ÷ÖÐ±àÂëÊ±µÄÖ¡ÂÊÖµ
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameRate(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPlayedTimeEx
// ÃèÊö: »ñÈ¡ÎÄ¼þµ±Ç°²¥·ÅÊ±¼ä
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: DWORD,ÎÄ¼þµ±Ç°²¥·ÅµÄÊ±¼ä,µ¥Î»ºÁÃë.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetPlayedTimeEx(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayedTimeEx
// ÃèÊö: ÉèÖÃÎÄ¼þµ±Ç°²¥·ÅÊ±¼ä.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nTime,ÉèÖÃÎÄ¼þ²¥·ÅÎ»ÖÃµ½Ö¸¶¨Ê±¼ä,µ¥Î»ºÁÃë.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedTimeEx(LONG nPort,DWORD nTime);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetCurrentFrameNum
// ÃèÊö: »ñÈ¡µ±Ç°²¥·ÅµÄÖ¡ÐòºÅ,PLAY_GetPlayedFramesÊÇ×Ü¹²½âÂëµÄÖ¡Êý.Èç¹ûÎÄ¼þ
//			²¥·ÅÎ»ÖÃ²»±»¸Ä±ä£¬ÄÇÃ´ÕâÁ½¸öº¯ÊýµÄ·µ»ØÖµÓ¦¸Ã·Ç³£½Ó½ü£¬³ý·ÇÂëÁ÷¶ª
//			Ê§Êý¾Ý.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: µ±Ç°²¥·ÅµÄÖ¡ÐòºÅ.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetCurrentFrameNum(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetStreamOpenMode
// ÃèÊö: ÉèÖÃÁ÷²¥·ÅÄ£Ê½,±ØÐëÔÚ²¥·ÅÖ®Ç°ÉèÖÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nMode,STREAME_REALTIMEÊµÊ±Ä£Ê½(Ä¬ÈÏ);STREAME_FILEÎÄ¼þÄ£Ê½.ÊµÊ±Ä£
//			Ê½,ÊÊºÏ²¥·ÅÍøÂçÊµÊ±Êý¾Ý;ÎÄ¼þÄ£Ê½,ÊÊºÏÓÃ»§°ÑÎÄ¼þÊý¾ÝÓÃÁ÷·½Ê½ÊäÈë.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetStreamOpenMode(LONG nPort,DWORD nMode);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetSdkVersion
// ÃèÊö: »ñÈ¡²¥·Å¿âSDK°æ±¾ºÅ,´Î°æ±¾ºÅºÍ²¹¶¡ºÅ
// ²ÎÊý: 
// ·µ»Ø: DWORD,¸ß16Î»±íÊ¾µ±Ç°µÄÖ÷°æ±¾ºÅ;9~16Î»±íÊ¾´Î°æ±¾ºÅ;1~8Î»±íÊ¾´Î²¹¶¡ºÅ;
//			Èç:·µ»ØÖµ0x00030107±íÊ¾:Ö÷°æ±¾ºÅÊÇ3,´Î°æ±¾ºÅÊÇ1,²¹¶¡ºÅÊÇ7.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSdkVersion();

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetLastError
// ÃèÊö: »ñÈ¡´íÎóÂë
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: DWORD,»ñµÃµ±Ç°´íÎóµÄ´íÎóÂë.Çë²Î¼û´íÎóÂëºê¶¨Òå.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetLastError(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_RefreshPlay
// ÃèÊö: Ë¢ÐÂÏÔÊ¾.µ±ÓÃ»§ÔÝÍ£Ê±Èç¹ûË¢ÐÂÁË´°¿Ú,Ôò´°¿ÚÖÐµÄÍ¼ÏñÒòÎªË¢ÐÂ¶øÏûÊ§,
//			´ËÊ±µ÷ÓÃÕâ¸ö½Ó¿Ú¿ÉÒÔÖØÐÂ°ÑÍ¼ÏñÏÔÊ¾³öÀ´.Ö»ÓÐÔÚÔÝÍ£ºÍµ¥Ö¡²¥·ÅÊ±²Å
//			Ö´ÐÐ,ÆäËüÇé¿ö»áÖ±½Ó·µ»Ø.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlay(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPictureSize
// ÃèÊö: »ñÈ¡Ô­Ê¼Í¼Ïñ´óÐ¡,¸ù¾Ý´Ë´óÐ¡À´ÉèÖÃÏÔÊ¾´°¿ÚµÄÇøÓò,¿ÉÒÔ²»ÓÃÏÔ¿¨×öËõ·Å
//			¹¤×÷,¶ÔÓÚÄÇÐ©²»Ö§³ÖÓ²¼þËõ·ÅµÄÏÔ¿¨À´Ëµ·Ç³£ÓÐÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pWidth,Êä³ö²ÎÊý,·µ»ØÍ¼Æ¬¿í¶È
//		 pHeight,Êä³ö²ÎÊý,·µ»ØÍ¼Æ¬¸ß¶È
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPicQuality
// ÃèÊö: ÉèÖÃÍ¼ÏñÖÊÁ¿,µ±ÉèÖÃ³É¸ßÖÊÁ¿Ê±»­ÃæÐ§¹ûºÃ,µ«CPUÀûÓÃÂÊ¸ß.ÔÚÖ§³Ö¶àÂ·²¥·ÅÊ±£¬
//			¿ÉÒÔÉèÎªµÍÖÊÁ¿,ÒÔ½µµÍCPUÀûÓÃÂÊ.µ±Ä³Â··Å´ó²¥·ÅÊ±½«¸ÃÂ·ÉèÖÃ³É¸ßÖÊÁ¿£¬
//			ÒÔ´ïµ½ºÃµÄ»­ÃæÐ§¹û.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 bHighQuality,ÎªTRUE(1)Ê±Í¼Ïñ¸ßÖÊÁ¿,ÎªFALSE(0)Ê±µÍÖÊÁ¿(Ä¬ÈÏÖµ).
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPicQuality(LONG nPort,BOOL bHighQuality);

//------------------------------------------------------------------------
// º¯Êý: PLAY_PlaySoundShare
// ÃèÊö: ÒÔ¹²Ïí·½Ê½²¥·ÅÉùÒô,²¥·Å±¾Â·ÉùÒô¶ø²»È¥¹Ø±ÕÆäËûÂ·µÄÉùÒô.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PlaySoundShare(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopSoundShare
// ÃèÊö: ¹Ø±ÕÉùÒô(¹²Ïí·½Ê½).ÔÚÍ¬Ò»¸ö½ø³ÌÖÐ,ËùÓÐÍ¨µÀ±ØÐëÊ¹ÓÃÏàÍ¬µÄ·½Ê½²¥·Å»ò¹Ø±ÕÉùÒô.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopSoundShare(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetStreamOpenMode
// ÃèÊö: »ñÈ¡Á÷²¥·ÅÄ£Ê½
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: LONG,STREAME_REALTIME»òSTREAME_FILE.
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetStreamOpenMode(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetVolume
// ÃèÊö: »ñÈ¡ÒôÁ¿,ÕâÀïµÄÒôÁ¿ÊÇÖ¸Éù¿¨Êä³öµÄÒôÁ¿.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: WORD,ÒôÁ¿Öµ
//------------------------------------------------------------------------
PLAYSDK_API WORD CALLMETHOD PLAY_GetVolume(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPictureQuality
// ÃèÊö: »ñÈ¡Í¼ÏñÖÊÁ¿
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 bHighQuality,Êä³ö²ÎÊý,TRUE±íÊ¾¸ßÖÊÁ¿,FALSE±íÊ¾µÍÖÊÁ¿.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPictureQuality(LONG nPort,BOOL *bHighQuality);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetSourceBufferRemain
// ÃèÊö: »ñÈ¡Á÷²¥·ÅÄ£Ê½ÏÂÔ´»º³åÇøÊ£ÓàÊý¾Ý´óÐ¡
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: DWORD,µ±Ç°Ô´»º³åµÄ´óÐ¡µ¥Î»BYTE(×Ö½Ú).
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetSourceBufferRemain(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ResetSourceBuffer
// ÃèÊö: Çå¿ÕÁ÷²¥·ÅÄ£Ê½ÏÂÔ´»º³åÇøµÄÊ£ÓàÊý¾Ý
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBuffer(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OneByOneBack
// ÃèÊö: µ¥Ö¡»ØÍË,´Ë½Ó¿ÚÖ»Ö§³ÖÎÄ¼þ²¥·Å,±ØÐëÔÚÎÄ¼þË÷ÒýÉú³ÉÖ®ºó²ÅÄÜµ÷ÓÃ.Ã¿µ÷
//			ÓÃÒ»´Îµ¹ÍËÒ»Ö¡
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OneByOneBack(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetCurrentFrameNum
// ÃèÊö: ÉèÖÃÎÄ¼þµ±Ç°Ö¡²¥·ÅÖ¡ºÅ,´Ëº¯Êý±ØÐëÔÚÎÄ¼þË÷ÒýÉú³ÉÖ®ºó²ÅÄÜµ÷ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nFrameNum,Ö¡ÐòºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetKeyFramePos
// ÃèÊö: ²éÕÒÖ¸¶¨Î»ÖÃÖ®Ç°µÄ¹Ø¼üÖ¡Î»ÖÃ,Í¼Ïñ½âÂë±ØÐë´Ó¹Ø¼üÖ¡¿ªÊ¼£¬Èç¹ûÓÃ»§±£´æ
//			µÄÎÄ¼þ²»ÊÇ´Ó¹Ø¼üÖ¡¿ªÊ¼µÄ,ÄÇÃ´µ¹ÏÂÒ»¸ö¹Ø¼üÖ¡Ö®Ç°µÄÊý¾Ý»á±»ºöÂÔ.Èç
//			¹ûÓÃ»§Òª½ØÈ¡ÎÄ¼þÖÐµÄÒ»¶ÎÊý¾Ý,ÔòÓ¦¸Ã¿¼ÂÇ´Ó¹Ø¼üÖ¡¿ªÊ¼½ØÈ¡.½áÊøÎ»ÖÃ
//			Ôò¹ØÏµ²»´ó,×î¶à¶ªÊ§3Ö¡Êý¾Ý.ÔÚÎÄ¼þË÷Òý½¨Á¢ÍêÈ«µÄÇ°ÌáÏÂ,Óë
//			PLAY_GetNextKeyFramePosÁªºÏÊ¹ÓÃ,¿ÉÒÔÓÃÀ´ÊµÏÖ¼ô¼­Â¼ÏñÎÄ¼þ,¼ô¼­¾«¶È
//			Óë¹Ø¼üÖ¡¼ä¸ôÓÐ¹Ø.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nValue,µ±Ç°Î»ÖÃ,¿ÉÒÔÊÇÊ±¼ä»òÖ¡ºÅ,ÀàÐÍÓÉnTypeÖ¸¶¨.
//		 nType,Ö¸¶¨nValueµÄÀàÐÍ.Èç¹ûnTypeÊÇBY_FRAMENUM,ÔònValue±íÊ¾Ö¡ºÅ;
//			Èç¹ûnTypeÊÇBY_FRAMTIME,ÔònValue±íÊ¾Ê±¼ä,µ¥Î»ms.
//		 pFramePos,²éÕÒµ½µÄ¹Ø¼üÖ¡µÄÎÄ¼þÎ»ÖÃÐÅÏ¢½á¹¹Ö¸Õë,Ïê¼ûPFRAME_POS.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetNextKeyFramePos
// ÃèÊö: ²éÕÒÖ¸¶¨Î»ÖÃÖ®ºóµÄ¹Ø¼üÖ¡Î»ÖÃ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nValue,µ±Ç°Î»ÖÃ,¿ÉÒÔÊÇÊ±¼ä»òÖ¡ºÅ,ÀàÐÍÓÉnTypeÖ¸¶¨.
//		 nType,Ö¸¶¨nValueµÄÀàÐÍ.Èç¹ûnTypeÊÇBY_FRAMENUM,ÔònValue±íÊ¾Ö¡ºÅ;
//			Èç¹ûnTypeÊÇBY_FRAMTIME,ÔònValue±íÊ¾Ê±¼ä,µ¥Î»ms.
//		 pFramePos,²éÕÒµ½µÄ¹Ø¼üÖ¡µÄÎÄ¼þÎ»ÖÃÐÅÏ¢½á¹¹Ö¸Õë,Ïê¼ûPFRAME_POS.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDecCBStream
// ÃèÊö: ÉèÖÃ½âÂë»Øµ÷Á÷ÀàÐÍ,ÔÚPLAY_PlayÖ®Ç°µ÷ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nStream,1 ÊÓÆµÁ÷;2 ÒôÆµÁ÷;3 ¸´ºÏÁ÷.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCBStream(LONG nPort,DWORD nStream);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDisplayRegion
// ÃèÊö: ÉèÖÃ»òÔö¼ÓÏÔÊ¾ÇøÓò,¿ÉÒÔ×ö¾Ö²¿·Å´óÏÔÊ¾.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ,0~(MAX_DISPLAY_WND-1),Èç¹ûÎª0,Ôò½«ÉèÖÃµÄÇøÓòÏÔÊ¾ÔÚÖ÷´°¿ÚÖÐ.
//		 pSrcRect,¾Ö²¿ÏÔÊ¾ÇøÓò
//		 hDestWnd,ÏÔÊ¾´°¿Ú¾ä±ú
//		 bEnable,´ò¿ª(ÉèÖÃ)»ò¹Ø±ÕÏÔÊ¾ÇøÓò
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayRegion(LONG nPort,DWORD nRegionNum, DISPLAYRECT *pSrcRect, HWND hDestWnd, BOOL bEnable);


//------------------------------------------------------------------------
// º¯Êý: PLAY_GetRefValue
// ÃèÊö: »ñÈ¡ÎÄ¼þË÷Òý,ÒÔ±ãÏÂ´Î´ò¿ªÍ¬Ò»¸öÎÄ¼þÊ±Ö±½ÓÊ¹ÓÃÕâ¸öÐÅÏ¢.±ØÐëÔÚË÷Òý½¨³Éºó²ÅÄÜ»ñµÃÐÅÏ¢.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBuffer,Ë÷ÒýÐÅÏ¢
//		 pSize,ÊäÈëpBufferµÄ´óÐ¡,Êä³öË÷ÒýÐÅÏ¢´óÐ¡.¿ÉÒÔÔÚµÚÒ»´ÎÖ¸¶¨pSize=0,pBuffer=NULL,´Ó
//			pSizeµÄ·µ»ØÖµ»ñµÃÐèÒªµÄ»º³åÇø´óÐ¡.È»ºó·ÖÅä×ã¹»µÄ»º³å,ÔÙµ÷ÓÃÒ»´Î.	 
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetRefValue
// ÃèÊö: ÉèÖÃÎÄ¼þË÷Òý,Ë÷ÒýÐÅÏ¢¼°Æä³¤¶È±ØÐë×¼È·.Èç¹ûÒÑ¾­ÓÐÁËÎÄ¼þË÷ÒýÐÅÏ¢,¿ÉÒÔ
//			²»ÔÙµ÷ÓÃÉú³ÉË÷ÒýµÄ»Øµ÷º¯ÊýPLAY_SetFileRefCallBackEx,Ö±½ÓÊäÈëË÷ÒýÐÅÏ¢.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBuffer,Ë÷ÒýÐÅÏ¢
//		 nSize,Ë÷ÒýÐÅÏ¢µÄ³¤¶È
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_RigisterDrawFun
// ÃèÊö: ×¢²áÒ»¸ö»Øµ÷º¯Êý,»ñµÃµ±Ç°±íÃæµÄdevice context,Äã¿ÉÒÔÔÚÕâ¸öDCÉÏ»­Í¼(»òÎÄ×Ö),
//			¾ÍºÃÏñÔÚ´°¿ÚµÄ¿Í»§ÇøDCÉÏ»æÍ¼,µ«Õâ¸öDC²»ÊÇ´°¿Ú¿Í»§ÇøµÄDC,¶øÊÇDirectDrawÀï
//			µÄOff-Screen±íÃæµÄDC.×¢Òâ,Èç¹ûÊÇÊ¹ÓÃoverlay±íÃæ,Õâ¸ö½Ó¿ÚÎÞÐ§,¿ÉÒÔÖ±½ÓÔÚ
//			´°¿ÚÉÏ»æÍ¼,Ö»Òª²»ÊÇÍ¸Ã÷É«¾Í²»»á±»¸²¸Ç.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DrawFun,»­Í¼»Øµ÷º¯Êý,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			hDc,OffScreen±íÃæÉè±¸ÉÏÏÂÎÄ.
//			pUserData,ÓÃ»§Êý¾Ý,¾ÍÊÇÉÏÃæÊäÈëµÄÓÃ»§Êý¾Ý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFun)(LONG nPort,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFun(LONG nPort, fDrawCBFun DrawCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ResetBuffer
// ÃèÊö: Çå¿ÕÖ¸¶¨»º³åÇøµÄÊ£ÓàÊý¾Ý
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nBufType,ÈçÏÂ:
//			BUF_VIDEO_SRC 1 ÊÓÆµÔ´»º³å
//			BUF_AUDIO_SRC 2 ÒôÆµÔ´»º³å
//			BUF_VIDEO_RENDER 3 ½âÂëºóÊÓÆµÊý¾Ý»º³å
//			BUF_AUDIO_RENDER 4 ½âÂëºóÒôÆµÊý¾Ý»º³å
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetBuffer(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetBufferValue
// ÃèÊö: »ñÈ¡Ö¸¶¨»º³åÇøµÄ´óÐ¡
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nBufType,ÈçÏÂ:
//			BUF_VIDEO_SRC 1 ÊÓÆµÔ´»º³å
//			BUF_AUDIO_SRC 2 ÒôÆµÔ´»º³å
//			BUF_VIDEO_RENDER 3 ½âÂëºóÊÓÆµÊý¾Ý»º³å
//			BUF_AUDIO_RENDER 4 ½âÂëºóÒôÆµÊý¾Ý»º³å
// ·µ»Ø: DWORD,¸ù¾Ý²»Í¬²ÎÊý·µ»Ø»º³åÇøÖµ,Ô´»º³åÇø·µ»Øbyte,½âÂëºó»º³åÇø·µ»ØÖ¡Êý.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetBufferValue(LONG nPort,DWORD nBufType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_AdjustWaveAudio
// ÃèÊö: µ÷ÕûWAVE²¨ÐÎ,¿ÉÒÔ¸Ä±äÉùÒôµÄ´óÐ¡.ËüºÍPLAY_SetVolumeµÄ²»Í¬ÔÚÓÚ,ËüÊÇµ÷Õû
//			ÉùÒôÊý¾Ý,Ö»¶Ô¸ÃÂ·Æä×÷ÓÃ,¶øPLAY_SetVolumeÊÇµ÷ÕûÉù¿¨ÒôÁ¿,¶ÔÕû¸öÏµÍ³Æð×÷ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nCoefficient,µ÷ÕûµÄ²ÎÊý,·¶Î§´ÓMIN_WAVE_COEFµ½MAX_WAVE_COEF,0ÊÇ²»µ÷Õû
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustWaveAudio(LONG nPort,LONG nCoefficient);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetAudioCallBack
// ÃèÊö: ÒôÆµ½âÂëºóµÄWAVEÊý¾Ý»Øµ÷.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 funAudio,ÒôÆµ½âÂë»Øµ÷º¯Êý,Æä²ÎÊýº¬ÒåÈçÏÂ
//			nPort,Í¨µÀºÅ
//			pAudioBuf,wave¸ñÊ½ÒôÆµÊý¾Ý
//			nSize,ÒôÆµÊý¾Ý³¤¶È
//			nStamp,Ê±±ê(ms)
//			nType,ÒôÆµÀàÐÍT_AUDIO16, ²ÉÑùÂÊ8000£¬µ¥ÉùµÀ£¬Ã¿¸ö²ÉÑùµã16Î»±íÊ¾
//			pUserData,ÓÃ»§×Ô¶¨ÒåÊý¾Ý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK * fAudioCBFun)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioCallBack(LONG nPort, fAudioCBFun AudioCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetEncTypeChangeCallBack
// ÃèÊö: ÉèÖÃÍ¼Ïñ·Ö±æÂÊ¸Ä±äÍ¨Öª»Øµ÷,´ò¿ªÎÄ¼þÇ°Ê¹ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 funEncChange,»Øµ÷º¯Êý
//			nPort,Í¨µÀºÅ
//			pUserData,ÓÃ»§×Ô¶¨ÒåÊý¾Ý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void(CALLBACK *fEncChangeCBFun)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCBFun EncChangeCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetColor
// ÃèÊö: ÉèÖÃÊÓÆµ²ÎÊý
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nRegionNum,ÏÔÊ¾ÇøÓò,²Î¿¼PLAY_SetDisplayRegion;Èç¹ûÖ»ÓÐÒ»¸öÏÔÊ¾ÇøÓò(Í¨³£Çé¿ö)ÉèÎª0.
//		 nBrightness,ÁÁ¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 nContrast,¶Ô±È¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 nSaturation,±¥ºÍ¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 nHue,É«µ÷,Ä¬ÈÏ64;·¶Î§0-128.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetColor
// ÃèÊö: »ñÈ¡ÊÓÆµ²ÎÊý
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nRegionNum,ÏÔÊ¾ÇøÓò,²Î¿¼PLAY_SetDisplayRegion;Èç¹ûÖ»ÓÐÒ»¸öÏÔÊ¾ÇøÓò(Í¨³£Çé¿ö)ÉèÎª0.
//		 pBrightness,ÁÁ¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 pContrast,¶Ô±È¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 pSaturation,±¥ºÍ¶È,Ä¬ÈÏ64;·¶Î§0-128.
//		 pHue,É«µ÷,Ä¬ÈÏ64;·¶Î§0-128.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetEncChangeMsg
// ÃèÊö: ÉèÖÃ·Ö±æÂÊ¸Ä±äÍ¨ÖªÏûÏ¢
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 hWnd,ÏûÏ¢·¢ËÍµÄ´°¿Ú
//		 nMsg,ÓÃ»§ÊäÈëµÄÏûÏ¢,µ±½âÂëÊ±±àÂë¸ñÊ½·¢Éú¸Ä±äÊ±ÓÃ»§ÔÚhWnd´°¿Ú¹ý³ÌÖÐÊÕµ½Õâ¸öÏûÏ¢.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetEncChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CatchPic
// ÃèÊö: ×¥Í¼,½«BMPÍ¼Æ¬±£´æÎªÖ¸¶¨µÄÎÄ¼þ.PLAY_SetDisplayCallBackÉèÖÃµÄÊÓÆµÊý
//			¾Ý»Øµ÷º¯Êý,Ö»ÓÐÔÚÓÐÊÓÆµÊý¾Ý½âÂë³öÀ´Ê±²Åµ÷ÓÃ,²¢ÓÉÓÃ»§´¦ÀíÊÓÆµÊý
//			¾Ý(Èç×¥Í¼),Èç¹û²»¶ÏÓÐ½âÂëµÄÊý¾Ý,¾Í²»¶Ïµ÷ÓÃÕâ¸ö»Øµ÷º¯Êý.¶øPLAY_
//			CatchPicÒ»´ÎÖ»×¥Ò»·ùÍ¼,²¢ÄÜÔÚÔÝÍ£ºÍµ¥Ö¡²¥·ÅÊ±ÊµÏÖ×¥Í¼.½¨Òé:Èç¹û
//			ÓÃ»§ÏëÊµÏÖ×¥Í¼(Ò»´Î×¥Ò»·ùÍ¼),µ÷ÓÃPLAY_CatchPic,¶øÈç¹ûÏëµÃµ½Ò»¶Î
//			Ê±¼äÄÚµÄÊÓÆµÊý¾Ý,µ÷ÓÃPLAY_SetDisplayCallBack.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,ÎÄ¼þÃû³Æ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPic(LONG nPort,char* sFileName) ;

//------------------------------------------------------------------------
// º¯Êý: PLAY_CatchPicEx
// ÃèÊö: PLAY_CatchPicµÄÀ©Õ¹½Ó¿Ú,ÓÃ·¨Çë²ÎÏêPLAY_CatchPic.¿ÉÖ¸¶¨Í¼Æ¬¸ñÊ½
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,ÎÄ¼þÃû³Æ
//		 ePicfomat,Í¼Æ¬¸ñÊ½,¼ûtPicFormats.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchPicEx(LONG nPort,char* sFileName,tPicFormats ePicfomat);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileEndCallBack
// ÃèÊö: ÉèÖÃÎÄ¼þ½áÊø»Øµ÷
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFileEnd,»Øµ÷º¯ÊýÖ¸Õë,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileEndCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileEndCallBack(LONG nPort, fpFileEndCBFun pFileEndCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartDataRecord
// ÃèÊö: ¿ªÊ¼Á÷Êý¾ÝÂ¼Ïñ,Ö»¶ÔÁ÷Ä£Ê½ÓÐÓÃ,ÔÚPLAY_PlayÖ®ºóµ÷ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,Â¼ÏñÎÄ¼þÃû,Èç¹ûÎÄ¼þÃûÖÐÓÐ²»´æÔÚµÄÎÄ¼þ¼Ð,¾Í´´½¨¸ÃÎÄ¼þ¼Ð.
//		 idataType,0±íÊ¾Ô­Ê¼ÊÓÆµÁ÷;1±íÊ¾×ª»»³ÉAVI¸ñÊ½;2±íÊ¾×ª»»³ÉASF¸ñÊ½;3·Ö¶Î±£´æÎÄ¼þ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecord(LONG nPort, char *sFileName, int idataType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_WriteData
// ÃèÊö: ±£´æÔ­Ê¼ÂëÁ÷
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBuf,Á÷Êý¾Ý
//		 nSize,´óÐ¡
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_WriteData(LONG nPort, PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopDataRecord
// ÃèÊö: Í£Ö¹Á÷Êý¾ÝÂ¼Ïñ
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDataRecord(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlaySpeed
// ÃèÊö: ¸Ä±äÍ¼Ïñ²¥·ÅµÄËÙ¶È,
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 fCoff,²¥·ÅËÙ¶È,·¶Î§[1/64~64.0],Ð¡ÓÚ1±íÊ¾Âý·Å£¬´óÓÚ1±íÊ¾Õý·Å.
//			   µ±²¥·ÅËÙ¶È½Ï¿ìÊ±¿ÉÄÜ»á³éÖ¡²¥·Å.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlaySpeed(LONG nPort, float fCoff);

//------------------------------------------------------------------------
// º¯Êý: PLAY_QueryInfo
// ÃèÊö: Ä¿Ç°ÊµÏÖÁË¶Ôµ±Ç°Ê±¼äºÍÖ¡ÂÊÐÅÏ¢µÄ²éÑ¯.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 cmdType,Ö¸¶¨×´Ì¬²éÑ¯Ö¸Áî,ÈçÏÂ
//			PLAY_CMD_GetTime   »ñÈ¡±àÂëÖÐÊ±¼äÐÅÏ¢,µ¥Î»ms.
//			PLAY_CMD_GetFileRate  »ñÈ¡Ö¡ÂÊÐÅÏ¢
//			PLAY_CMD_GetMediaInfo  »ñÈ¡Ã½ÌåÐÅÏ¢,ÐÅÏ¢½á¹¹Îª MEDIA_INFO
//		 buf,´æ·ÅÐÅÏ¢µÄ»º³å
//		 buflen,»º³å³¤¶È
//		 returnlen,»ñÈ¡µÄÐÅÏ¢µÄÓÐÐ§Êý¾Ý³¤¶È
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryInfo(LONG nPort , int cmdType, char* buf, int buflen, int* returnlen);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OpenAudioRecord
// ÃèÊö: ´ò¿ªÒôÆµ²É¼¯¹¦ÄÜ.
// ²ÎÊý: pProc,ÒôÆµ²É¼¯Êý¾Ý»Øµ÷Ö¸Õë,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			pDataBuffer,»Øµ÷Êý¾ÝÖ¸Õë
//			DataLength,»Øµ÷Êý¾Ý³¤¶È
//			pUserData,ÓÃ»§Êý¾Ý
//		 nBitsPerSample,±íÊ¾Ã¿¸ö²ÉÑùËùÐèÒªµÄÎ»Êý
//		 nSamplesPerSec,²ÉÑùÂÊ
//		 nLength,Êý¾Ý»º³åµÄ³¤¶È
//		 nReserved,±£Áô
//		 pUserData,ÓÃ»§×Ô¶¨ÒåÊý¾Ý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *pCallFunction)(LPBYTE pDataBuffer, DWORD DataLength, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenAudioRecord(pCallFunction pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nReserved, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CloseAudioRecord
// ÃèÊö: ¹Ø±ÕÒôÆµ²É¼¯¹¦ÄÜ
// ²ÎÊý: 
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseAudioRecord();

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetWaterMarkCallBack
// ÃèÊö: ÉèÖÃË®Ó¡Êý¾Ý»Øµ÷¡£×¢Òâ£ºË®Ó¡Ð£Ñé»Øµ÷ÉèÖÃºó½«²»»á½øÐÐ½âÂëÏÔÊ¾
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFunc,Ë®Ó¡ÐÅÏ¢»ñÈ¡»Øµ÷º¯Êý,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			buf,Ë®Ó¡Êý¾ÝbufferÖ¸Õë
//			key,Çø·Ö²»Í¬Ë®Ó¡ÐÅÏ¢
//			len,»º³åµÄ×î´ó³¤¶È
//			reallen,»º³åµÄÊµ¼Ê³¤¶È
//			type,ÊýÖµ·¶Î§[0,3],º¬ÒåÈçÏÂ
//				0  IÖ¡Ö¡Êý¾ÝË®Ó¡ÐÅÏ¢
//				1  Ö¡Ë®Ó¡
//				2  Ë®Ó¡Ð£Ñé 
//				3  ÖÇÄÜ·ÖÎöÖ¡
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý 
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFunc)(char* buf, LONG key, LONG len, LONG reallen, LONG type, void* pUserData);	
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CreateFile
// ÃèÊö: ´ò¿ªÎÄ¼þ²¢×Ô¶¯·ÖÅäÍ¨µÀºÅ
// ²ÎÊý: sFileName,ÎÄ¼þÃû
// ·µ»Ø: DWORD,Ê§°Ü·µ»Ø0,·ñÔò·µ»ØÍ¨µÀºÅ.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateFile(LPSTR sFileName);

//------------------------------------------------------------------------
// º¯Êý: PLAY_DestroyFile
// ÃèÊö: ¹Ø±Õ²¥·ÅÎÄ¼þ²¢ÊÍ·Å×Ô¶¯·ÖÅäµÄÍ¨µÀºÅ.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyFile(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CreateStream
// ÃèÊö: ´ò¿ªÁ÷½Ó¿Ú²¢×Ô¶¯·ÖÅäÍ¨µÀºÅ
// ²ÎÊý: nBufPoolSize,ÖÃ²¥·ÅÆ÷ÖÐ´æ·ÅÊý¾ÝÁ÷µÄ»º³åÇø´óÐ¡,·¶Î§ÊÇ[SOURCE_BUF_MIN,SOURCE_BUF_MAX].
// ·µ»Ø: DWORD,Ê§°Ü·µ»Ø0,·ñÔò·µ»ØÍ¨µÀºÅ.
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_CreateStream(DWORD nBufPoolSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_DestroyStream
// ÃèÊö: ¹Ø±ÕÊý¾ÝÁ÷,²¢ÊÍ·Å×Ô¶¯·ÖÅäµÄÍ¨µÀºÅ.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DestroyStream(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetFreePort
// ÃèÊö: »ñÈ¡¿ÕÏÐÍ¨µÀºÅ,ÉÏÏÞÎª501.ÓëPLAY_ReleasePortÆ¥¶ÔÊ¹ÓÃ.
// ²ÎÊý: plPort,Êä³ö²ÎÊý,·µ»Ø»ñÈ¡µÄÍ¨µÀºÅ.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetFreePort(LONG *plPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ReleasePort
// ÃèÊö: ÊÍ·ÅÍ¨µÀºÅ,ÓëPLAY_RealsePortÆ¥¶ÔÊ¹ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ReleasePort(LONG lPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_VerticalSyncEnable
// ÃèÊö: ´¹Ö±Í¬²½ÏÔÊ¾¿ª¹Ø.´Ë½Ó¿ÚÐèÔÚPLAY_PlayÖ®ºóµ÷ÓÃ,ÖØÐÂ²¥·ÅÊ±ÐèÖØÐÂÉèÖÃ.
//			ÔÚ²¥·Å¶¯Ì¬Í¼Ïñ³öÏÖ¶Ï²ãÊ±,¿ÉÒÔÊ¹ÓÃ´Ë½Ó¿Ú´ò¿ª´¹Ö±Í¬²½¹¦ÄÜ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 bEnable,TRUE´ò¿ª´¹Ö±Í¬²½;FALSE¹Ø±Õ´¹Ö±Í¬²½.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API	BOOL CALLMETHOD PLAY_VerticalSyncEnable(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPicBMP
// ÃèÊö: ×¥È¡BMPÍ¼Ïñ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBmpBuf,´æ·ÅBMPÍ¼ÏñÊý¾ÝµÄ»º³åµØÖ·,ÓÉÓÃ»§·ÖÅä,²»µÃÐ¡ÓÚbmp Í¼Ïñ´óÐ¡,
//			ÍÆ¼ö´óÐ¡:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			ÆäÖÐwºÍh·Ö±ðÎªÍ¼Ïñ¿í¸ß.
//		 dwBufSize,»º³åÇø´óÐ¡
//		 pBmpSize,»ñÈ¡µ½µÄÊµ¼Êbmp Í¼Ïñ´óÐ¡
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPicBMPEx
// ÃèÊö: ×¥È¡BMPÍ¼Ïñ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBmpBuf,´æ·ÅBMPÍ¼ÏñÊý¾ÝµÄ»º³åµØÖ·,ÓÉÓÃ»§·ÖÅä,²»µÃÐ¡ÓÚbmp Í¼Ïñ´óÐ¡,
//			ÍÆ¼ö´óÐ¡:sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+w*h*4,
//			ÆäÖÐwºÍh·Ö±ðÎªÍ¼Ïñ¿í¸ß.
//		 dwBufSize,»º³åÇø´óÐ¡
//		 pBmpSize,»ñÈ¡µ½µÄÊµ¼Êbmp Í¼Ïñ´óÐ¡
//		 nWidth,Ö¸¶¨µÄbmpµÄ¿í
//		 nHeight,Ö¸¶¨µÄbmpµÄ¸ß
//		 nRgbType,Ö¸¶¨RGB¸ñÊ½ 0£ºRGB32;1£ºRGB24;
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPicJPEG
// ÃèÊö: ×¥È¡JPEGÍ¼Ïñ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pJpegBuf,´æ·ÅJPEGÍ¼ÏñÊý¾ÝµÄ»º³åµØÖ·,ÓÉÓÃ»§·ÖÅä,²»µÃÐ¡ÓÚJPEGÍ¼Ïñ´óÐ¡,
//			ÍÆ¼ö´óÐ¡:w*h*3/2,ÆäÖÐwºÍh·Ö±ðÎªÍ¼Ïñ¿í¸ß.
//		 dwBufSize,»º³åÇø´óÐ¡.
//		 pJpegSize,»ñÈ¡µ½µÄÊµ¼ÊJPEGÍ¼Ïñ´óÐ¡.
//		 quality,JPEGÍ¼ÏñµÄÑ¹ËõÖÊÁ¿,È¡Öµ·¶Î§Îª(0,100].
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetPicTIFF
// ÃèÊö: ×¥È¡TIFFÍ¼Ïñ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pTiffBuf,´æ·ÅTIFFÍ¼ÏñÊý¾ÝµÄ»º³åµØÖ·,ÓÉÓÃ»§·ÖÅä,²»µÃÐ¡ÓÚtiffÍ¼Ïñ´óÐ¡,
//			ÍÆ¼ö´óÐ¡:w*h*3+1024,
//			ÆäÖÐwºÍh·Ö±ðÎªÍ¼Ïñ¿í¸ß.
//		 dwBufSize,»º³åÇø´óÐ¡
//		 pTiffSize,»ñÈ¡µ½µÄÊµ¼ÊTIFFÍ¼Ïñ´óÐ¡
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetPicTIFF(LONG nPort, PBYTE pTiffBuf, DWORD dwBufSize, DWORD* pTiffSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetVisibleDecodeCallBack
// ÃèÊö: ½âÂë»Øµ÷.ÓëPLAY_SetDecodeCallBack»ù±¾ÏàÍ¬,²»Í¬µÄÊÇ½âÂë»Øµ÷µÄÍ¬Ê±¿ÉÒÔ
//			ÏÔÊ¾ÊÓÆµ,½¨Òé²»ÒªÔÚ»Øµ÷º¯ÊýÀïÃæ×ö³¤Ê±¼äµÄÂß¼­´¦Àí,ÒÔÃâÔö¼ÓÏÔÊ¾µÄÑÓÊ±.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 cbDec,½âÂë»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL.»Øµ÷º¯Êý²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pFrameDecodeInfo,½âÂëºóµÄÒôÊÓÆµÊý¾Ý
//			pFrameInfo,Í¼ÏñºÍÉùÒôÐÅÏ¢,Çë²Î¼ûFRAME_INFO½á¹¹Ìå
//			pUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecodeCallBack(LONG nPort, fCBDecode cbDec, void* pUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_RigisterDrawFunEx
// ÃèÊö: ×¢²áÒ»¸ö»Øµ÷º¯Êý,»ñµÃµ±Ç°±íÃæµÄÉÏÏÂÎÄ(HDC),Õâ¸öDC²»ÊÇ´°¿Ú¿Í»§ÇøµÄDC,
//			¶øÊÇDirectDrawÀïµÄOff-Screen±íÃæµÄDC.×¢Òâ.Èç¹ûÊÇÊ¹ÓÃoverlay±íÃæ,
//			Õâ¸ö½Ó¿ÚÎÞÐ§,overlay·½Ê½¿ÉÒÔÖ±½ÓÔÚ´°¿ÚÉÏ»æÍ¼,Ö»Òª²»ÊÇÍ¸Ã÷É«¾Í²»»á±»¸²¸Ç.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nReginNum,ÏÔÊ¾ÇøÓòÐòºÅ,·¶Î§[0,(MAX_DISPLAY_WND-1)].Èç¹ûnRegionNumÎª0,
//			Ôò½«ÉèÖÃµÄÇøÓòÏÔÊ¾ÔÚÖ÷´°¿ÚÖÐ.
//		 DrawFunEx,»­Í¼»Øµ÷º¯Êý,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			hDc,Off-Screen±íÃæµÄÉè±¸ÉÏÏÂÎÄ(DC)
//			pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDrawCBFunEx)(LONG nPort,LONG nReginNum,HDC hDc, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_RigisterDrawFunEx(LONG nPort, LONG nReginNum, fDrawCBFunEx DrawFunEx, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CatchResizePic
// ÃèÊö: ×¥Í¼,¿ÉÑ¡Ôñ¸ñÊ½²¢Ö¸¶¨¿í¸ß.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,ÎÄ¼þÃû³Æ
//		 lTargetWidth,Ö¸¶¨µÄÍ¼Ïñ¿í¶È
//		 lTargetHeight,Ö¸¶¨µÄÍ¼Ïñ¸ß¶È
//		 ePicfomat,Í¼Æ¬¸ñÊ½,Ïê¼ûtPicFomats
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetRealFrameBitRate
// ÃèÊö: »ñÈ¡ÊÓÆµÊµÊ±ÂëÂÊ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pBitRate,Êä³ö²ÎÊý,·µ»ØÊÓÆµÂëÂÊ.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);


//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileRefCallBackEx
// ÃèÊö: ÉèÖÃ½¨Á¢Ë÷Òý»Øµ÷,ÒÔ·µ»ØË÷Òý´´½¨Çé¿ö.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFileRefDoneEx,»Øµ÷º¯ÊýÖ¸Õë,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			bIndexCreated,Ë÷Òý´´½¨±êÖ¾,TRUEË÷Òý´´½¨³É¹¦;FALSEÊ§°Ü.
//			pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK *fpFileRefDoneCBFunEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBackEx(LONG nPort, fpFileRefDoneCBFunEx pFileRefDoneCBFunEx, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartAVIConvert
// ÃèÊö: ¿ªÊ¼AVI×ª»»²¢ÉèÖÃAVI×ª»»×´Ì¬»Øµ÷.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pAVIFunc,»Øµ÷º¯Êý,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			lMediaChangeType,AVI_MEDIACHANGE_FRAMERATE±íÊ¾Ö¡ÂÊ¸Ä±ä;AVI_MEDIACHANGE_RESOLUTION±íÊ¾·Ö±æÂÊ¸Ä±ä
//			lUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
//			pbIfContinue,TRUE¼ÌÐø×ª»»;FALSE Í£Ö¹×ª»»
//			sNewFileName,Èç¹û¼ÌÐø×ª»»,ÐÂµÄÂ¼ÏñÎÄ¼þÃû
//		 lUser,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* AVIConvertCallback)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pbIfContinue, char *sNewFileName);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIConvert(LONG nPort, char *sFileName, AVIConvertCallback pAVIFunc, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopAVIConvert
// ÃèÊö: Í£Ö¹AVI×ª»».
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIConvert(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetWaterMarkCallBackEx
// ÃèÊö: ÉèÖÃË®Ó¡Êý¾Ý»Øµ÷¡£×¢Òâ£ºË®Ó¡Ð£Ñé»Øµ÷ÉèÖÃºó½«²»»á½øÐÐ½âÂëÏÔÊ¾
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFunc,º¯ÊýÖ¸Õë,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			buf,Ë®Ó¡Êý¾Ý»º³å
//			lTimeStamp,Ë®Ó¡µÄÊ±¼ä´Á
//			lInfoType,Ë®Ó¡ÐÅÏ¢ÀàÐÍ,ÓÐÈýÖÖÀàÐÍ,WATERMARK_DATA_TEXT,
//				WATERMARK_DATA_JPEG_BMP,WATERMARK_DATA_FRAMEDATA
//		 len,»º³åµÄ×î´ó³¤¶È
//		 reallen,»º³åµÄÊµ¼Ê³¤¶È
//		 lCheckResult,1Ã»ÓÐ´íÎó;2Ë®Ó¡´íÎó;3Ö¡Êý¾Ý´íÎó;4Ö¡ºÅ´íÎó
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef int (CALLBACK* GetWaterMarkInfoCallbackFuncEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetWaterMarkCallBackEx(LONG nPort, GetWaterMarkInfoCallbackFuncEx pFunc, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetAudioRecScaling
// ÃèÊö: ÉèÖÃÒôÆµ²É¼¯Êý¾ÝËõ·Å±ÈÀý
// ²ÎÊý: fRatio,Ëõ·Å±ÈÀý.´óÓÚ0Ð¡ÓÚ1ÎªÒôÆµËõÐ¡;1ÎªÔ­Ê¼ÒôÆµ;´óÓÚ1ÎªÒôÆµ·Å´ó.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRecScaling(float fRatio);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetAudioRecScaling
// ÃèÊö: »ñÈ¡ÒôÆµ²É¼¯Êý¾ÝËõ·Å±ÈÀý
// ²ÎÊý: pfRatio,Ëõ·Å±ÈÀý.´óÓÚ0Ð¡ÓÚ1ÎªÒôÆµËõÐ¡;1ÎªÔ­Ê¼ÒôÆµ;´óÓÚ1ÎªÒôÆµ·Å´ó.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRecScaling(float* pfRatio);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetAudioRenderScaling
// ÃèÊö: ÉèÖÃÒôÆµ½âÂëËõ·Å±ÈÀý
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 fRatio,Ëõ·Å±ÈÀý.´óÓÚ0Ð¡ÓÚ1ÎªÒôÆµËõÐ¡;1ÎªÔ­Ê¼ÒôÆµ;´óÓÚ1ÎªÒôÆµ·Å´ó.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetAudioRenderScaling(LONG nPort, float fRatio);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetAudioRenderScaling
// ÃèÊö: »ñÈ¡ÒôÆµ½âÂëËõ·Å±ÈÀý
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pfRatio,Ëõ·Å±ÈÀý.´óÓÚ0Ð¡ÓÚ1ÎªÒôÆµËõÐ¡;1ÎªÔ­Ê¼ÒôÆµ;´óÓÚ1ÎªÒôÆµ·Å´ó.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioRenderScaling(LONG nPort, float* pfRatio);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetRotateAngle
// ÃèÊö: Í¼Ïñ·­×ª
// ²ÎÊý: nrotateType,·­×ªÀàÐÍ,·¶Î§[0,3]. 0²»Ðý×ª;1Ðý×ª90¶È;2Ðý×ª180¶È;3Ðý×ª270¶È.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetRotateAngle(LONG nPort , int nrotateType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDelayTime
// ÃèÊö: ÉèÖÃÑÓ³ÙÊ±¼ä
// ²ÎÊý: nDelay,ÑÓ³ÙÊ±¼ä£¬»º³å¶àÉÙÊ±¼ä¿ªÊ¼²¥·Å£¬»º³åÐ¡ÓÚ´ËÖµ¿ªÊ¼ÉÔÎ¢Âý·Å
//       nThreshold,·§ÖµÊ±¼ä£¬µ½´ï·§Öµ¿ªÊ¼ÉÔÎ¢¿ì·Å
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayMethod
// ÃèÊö: ÉèÖÃ²¥·Å²ßÂÔ²ÎÊý£¬Ö»¶ÔÊµÊ±Á÷ÓÐÐ§
// ²ÎÊý: nStartTime,¿ªÊ¼²¥·ÅµÄÊ±¼ä
//       nSlowTime,¿ªÊ¼Âý·ÅµÄÊ±¼ä
//		 nFastTime,¿ªÊ¼¿ì·ÅµÄÊ±¼ä
//		 nFailedTime,³¬¹ý´ËÊ±¼äÍ¶µÝÊý¾ÝÊ§°Ü
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

//------------------------------------------------------------------------
// º¯Êý: PLAY_BackOne
// ÃèÊö: ÓëPLAY_OneByOneBackÖØ¸´£¬ÇëÊ¹ÓÃPLAY_OneByOneBack
// ²ÎÊý: 
// ·µ»Ø: 
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_BackOne(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDecCallBack(½¨ÒéÊ¹ÓÃPLAY_SetDecodeCallBack)
// ÃèÊö: ÉèÖÃ½âÂë»Øµ÷,Ìæ»»²¥·ÅÆ÷ÖÐµÄÏÔÊ¾²¿·Ö,ÓÉÓÃ»§×Ô¼º¿ØÖÆÏÔÊ¾,¸Ãº¯ÊýÔÚ
//			PLAY_PlayÖ®Ç°µ÷ÓÃ,ÔÚPLAY_StopÊ±×Ô¶¯Ê§Ð§,ÏÂ´Îµ÷ÓÃPLAY_PlayÖ®Ç°
//			ÐèÒªÖØÐÂÉèÖÃ.½âÂë²¿·Ö²»¿ØÖÆËÙ¶È,Ö»ÒªÓÃ»§´Ó»Øµ÷º¯ÊýÖÐ·µ»Ø,½âÂëÆ÷
//			¾Í»á½âÂëÏÂÒ»²¿·ÖÊý¾Ý.ÊÊÓÃÓÚÖ»½âÂë²»ÏÔÊ¾µÄÇéÐÎ¡£
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DecCBFun,½âÂë»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL.»Øµ÷º¯Êý²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pBuf,½âÂëºóµÄÒôÊÓÆµÊý¾Ý
//			nSize,½âÂëºóµÄÒôÊÓÆµÊý¾ÝpBufµÄ³¤¶È
//			pFrameInfo,Í¼ÏñºÍÉùÒôÐÅÏ¢,Çë²Î¼ûFRAME_INFO½á¹¹Ìå
//			nReserved1,±£Áô²ÎÊý
//			nReserved2,±£Áô²ÎÊý	
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved2);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBack(LONG nPort, fDecCBFun DecCBFun);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDecCallBackEx(½¨ÒéÊ¹ÓÃPLAY_SetDecodeCallBack)
// ÃèÊö: ÉèÖÃ½âÂë»Øµ÷,Ìæ»»²¥·ÅÆ÷ÖÐµÄÏÔÊ¾²¿·Ö,ÓÉÓÃ»§×Ô¼º¿ØÖÆÏÔÊ¾,¸Ãº¯ÊýÔÚ
//			PLAY_PlayÖ®Ç°µ÷ÓÃ,ÔÚPLAY_StopÊ±×Ô¶¯Ê§Ð§,ÏÂ´Îµ÷ÓÃPLAY_PlayÖ®Ç°
//			ÐèÒªÖØÐÂÉèÖÃ.½âÂë²¿·Ö²»¿ØÖÆËÙ¶È,Ö»ÒªÓÃ»§´Ó»Øµ÷º¯ÊýÖÐ·µ»Ø,½âÂëÆ÷
//			¾Í»á½âÂëÏÂÒ»²¿·ÖÊý¾Ý.ÊÊÓÃÓÚÖ»½âÂë²»ÏÔÊ¾µÄÇéÐÎ¡£
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DecCBFun,½âÂë»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL.»Øµ÷º¯Êý²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pBuf,½âÂëºóµÄÒôÊÓÆµÊý¾Ý
//			nSize,½âÂëºóµÄÒôÊÓÆµÊý¾ÝpBufµÄ³¤¶È
//			pFrameInfo,Í¼ÏñºÍÉùÒôÐÅÏ¢,Çë²Î¼ûFRAME_INFO½á¹¹Ìå
//			nReserved1,ÓÃ»§×Ô¶¨Òå²ÎÊý
//			nReserved2,±£Áô²ÎÊý	
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecCallBackEx(LONG nPort, fDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetVisibleDecCallBack(½¨ÒéÊ¹ÓÃPLAY_SetVisibleDecodeCallBack)
// ÃèÊö: ½âÂë»Øµ÷.ÓëPLAY_SetDecCallBackEx»ù±¾ÏàÍ¬,²»Í¬µÄÊÇ½âÂë»Øµ÷µÄÍ¬Ê±¿ÉÒÔ
//			ÏÔÊ¾ÊÓÆµ,½¨Òé²»ÒªÔÚ»Øµ÷º¯ÊýÀïÃæ×ö³¤Ê±¼äµÄÂß¼­´¦Àí,ÒÔÃâÔö¼ÓÏÔÊ¾µÄÑÓÊ±.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DecCBFun,»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pBuf,½âÂëºóµÄÒôÊÓÆµÊý¾Ý
//			nSize,Êý¾Ý³¤¶È
//			pFrameInfo,Ö¡ÐÅÏ¢,Ïê¼ûFRAME_INFO½á¹¹Ìå.
//			pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
//			pReserved1,±£Áô²ÎÊý.
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fVisibleDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO * pFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVisibleDecCallBack(LONG nPort, fVisibleDecCBFun DecCBFun, void* pUserData);


//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDisplayScale
// ÃèÊö: ÉèÖÃÏÔÊ¾±ÈÀý´óÐ¡£¬IOS×¨ÓÃÒÔ±ãÊÊÅä²»Í¬µÄ»úÐÍ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 fScale£¬ÏÔÊ¾±ÈÀý£¬Ä¬ÈÏÎª1.0
//		 nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ,0~(MAX_DISPLAY_WND-1),Èç¹ûÎª0,Ôò½«ÉèÖÃµÄÇøÓòÏÔÊ¾ÔÚÖ÷´°¿ÚÖÐ.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayScale(LONG nPort, float fScale, DWORD nRegionNum);


//------------------------------------------------------------------------
//	º¯ÊýÃû: PLAY_SetSecurityKey
//	ÃèÊö: ÉèÖÃaes½âÃÜÃÜÔ¿
//  ÊäÈë²ÎÊý:   nPort:		½âÂëÍ¨µÀ¡£
//				szKey:		ÃÜÔ¿µÄÖ¸Õë
//				nKeylen:	ÃÜÔ¿µÄ³¤¶È       
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSecurityKey(LONG nPort,const char* szKey,DWORD nKeylen);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartFisheye
// ÃèÊö: ¿ªÆôÊÓÆµÓãÑÛËã·¨¹¦ÄÜ£¬ÐèÒª°üº¬fisheye.dll¿â
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartFisheye(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OperateFisheyeParams
// ÃèÊö: ÉèÖÃ/»ñÈ¡ÓãÑÛ²ÎÊý
// ²ÎÊý: [in]nPort					:  Í¨µÀºÅ
//		 [in]operatetype			:  ²Ù×÷ÀàÐÍ
//       [in]pOptParam	    		:  ÓãÑÛ²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//-----------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OptFisheyeParams(LONG nPort, FISHEYE_OPERATETYPE operatetype, FISHEYE_OPTPARAM* pOptParam);

//------------------------------------------------------------------------
// º¯Êý: PLAY_FisheyeSecondRegion
// ÃèÊö: ÓÃÓÚ¸¡¶¯Ä£Ê½ÏÂ¿ªÆô»ò¹Ø±ÕµÚ¶þ¸öÓãÑÛ´°¿Ú
// ²ÎÊý: [in]nPort			: Í¨µÀºÅ
//		 [in]hDestWnd		: ÏÔÊ¾´°¿Ú¾ä±ú
//		 [in]pOptParam		: µÚ¶þ¸ö´°¿Ú¶ÔÓ¦µÄÓãÑÛ²ÎÊý
//		 [in]bEnable		: ´ò¿ª»ò¹Ø±ÕÏÔÊ¾ÇøÓò
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeSecondRegion(LONG nPort, HWND hDestWnd, FISHEYE_OPTPARAM* pOptParam, BOOL bEnable);

//------------------------------------------------------------------------
// º¯Êý: PLAY_FisheyeEptzUpdate
// ÃèÊö: ¿ªÆôeptz(µç×ÓÔÆÌ¨£©£¬½øÐÐËõ·ÅÒÆ¶¯
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//       [in/out]pEptzParam  :  µ÷½Ú²ÎÊý
//		 [in]bSecondRegion	 £º	ÊÇ·ñÎª¸¡¶¯Ä£Ê½ÏÂµÄµÚ¶þ¸ö´°¿Ú£¬1ÎªÕæ£¬Ä¬ÈÏÌî0
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeEptzUpdate(LONG nPort, FISHEYE_EPTZPARAM* pEptzParam, BOOL bSecondRegion);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopFisheye
// ÃèÊö: Í£Ö¹ÊÓÆµÓãÑÛËã·¨¹¦ÄÜ
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopFisheye(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFishEyeInfoCallBack
// ÃèÊö: ÉèÖÃ»ñÈ¡ÓãÑÛ»Øµ÷
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFishEyeInfoFun,»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//          byCorrectMode,½ÃÕýÄ£Ê½
//          wRadius,°ë¾¶
//          wCircleX,Ô²ÐÄºá×ø±ê
//          wCircleY,Ô²ÐÄ×Ý×ø±ê
//			widthRatio, ¿í±ÈÂÊ
//			heightRatio,¸ß±ÈÂÊ
//			gain, ÔöÒæ
//			denoiseLevel, ½µÔëµÈ¼¶
//			InstallStyle, ÓãÑÛ°²×°·½Ê½
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fCBFishEyeInfoFun)( 
	LONG nPort,
	BYTE byCorrectMode,
	WORD wRadius,
	WORD wCircleX,
	WORD wCircleY,
	UINT widthRatio,
	UINT heightRatio,
	BYTE gain,
	BYTE denoiseLevel,
	BYTE installStyle,
	void* pUserData );
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFishEyeInfoCallBack(
	LONG nPort, 
	fCBFishEyeInfoFun pFishEyeInfoFun, 
	void* pUserData );

    
    
// Extension API




/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_SetupPrepareTime
 *	Ä¿µÄ:				ÉèÖÃÔ¤Â¼µÄ»·¾³
 *   ÊäÈë²ÎÊý:           nPort:		½âÂëÍ¨µÀ¡£
 nTime:		Ô¤Â¼¶àÉÙÃë
 tmpDir:		ÁÙÊ±µÄÔ¤Â¼Ä¿Â¼
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦.
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_SetupPrepareTime(LONG nPort,int nTime,const char* tmpDirectory);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_StartPrepareRecord
 *	Ä¿µÄ:				¿ªÊ¼Ô¤Â¼
 *   ÊäÈë²ÎÊý:		     nPort:		½âÂëÍ¨µÀ¡£
 pFileName:	Â¼ÏñÎ»ÖÃ
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦.
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢:			2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_StartPrepareRecord(LONG nPort,const char* pFileName);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_StopPrepareRecord
 *	Ä¿µÄ:
 *   ÊäÈë²ÎÊý:			port:		½âÂëÍ¨µÀ¡£
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦.
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:		2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL	CALLMETHOD PLAY_StopPrepareRecord(LONG nPort);

//
//
#define IVSINFOTYPE_PRESETPOS		1
#define IVSINFOTYPE_MOTINTRKS		2
#define IVSINFOTYPE_MOTINTRKS_EX	3
#define IVSINFOTYPE_LIGHT			4
#define IVSINFOTYPE_RAWDATA			5
#define IVSINFOTYPE_TRACK			6
#define IVSINFOTYPE_MOTIONFRAME		9 /*¶¯Ì¬¼à²âÊý¾ÝÖ¡*/
#define PSIVS						240
/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_SetIVSCallBack
 *	Ä¿µÄ:
 *   ÊäÈë²ÎÊý:	        nPort:		½âÂëÍ¨µÀ
 pFunc:		ÉèÖÃ½âÂë»Øµ÷
 nUser:		ÉÏÏÂÎÄ£¬ÓÃÓÚ»Øµ÷»ØÀ´µÄ²ÎÊý
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *	°æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

typedef void (CALLMETHOD *GetIVSInfoCallbackFunc)(char* buf, LONG type, LONG len, LONG reallen, void* pReserved, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIVSCallBack(LONG nPort, GetIVSInfoCallbackFunc pFunc, void* pUserData);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_CatchResizePic
 *	Ä¿µÄ:				¸Ä±ä·Ö±æÂÊµÄ×¥Í¼
 *   ÊäÈë²ÎÊý:			nPort:		½âÂëÍ¨µÀ
 sFileName:	Í¼Æ¬µØÖ·.
 lTargetWidth & lTargetHeight: Í¼Æ¬µÄ¿í¸ú¸ß
 ePicfomat:	picture format (jpeg/bmp)	Í¼Æ¬µÄÀàÐÍ
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_CatchResizePic(LONG nPort, char* sFileName, LONG lTargetWidth, LONG lTargetHeight, tPicFormats ePicfomat);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_GetRealFrameBitRate
 *	Ä¿µÄ:				»ñÈ¡ÂëÂ
 *   ÊäÈë²ÎÊý:           nPort:		½âÂëÍ¨µÀ¡£
 *   Êä³ö²ÎÊý:	        pBitRate:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_GetRealFrameBitRate(LONG nPort, double* pBitRate);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_StartAVIResizeConvert
 *	Ä¿µÄ:				¸Ä±ä·Ö±æÂÊµÄAVI×ª»»
 *   ÊäÈë²ÎÊý:           nPort:		½âÂëÍ¨µÀ¡£
 sFileName:	AVIµÄÂ¼Ïñ´æ·ÅµØÖ·
 lWidth & lHeight:AVIµÄÂ¼ÏñµÄ¿í¸ú¸ß
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_StartAVIResizeConvert(LONG nPort, char *sFileName, LONG lWidth, LONG lHeight);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_StopAVIResizeConvert
 *	Ä¿µÄ:				½áÊøAVI×ª»»
 *   ÊäÈë²ÎÊý:           nPort:		½âÂëÍ¨µÀ¡£
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_StopAVIResizeConvert(LONG nPort);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_SetPandoraWaterMarkCallBack
 *	Ä¿µÄ:				ÎÞÐ§
 *   ÊäÈë²ÎÊý:
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/

PLAYSDK_API BOOL CALLMETHOD PLAY_SetPandoraWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);


/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_SetDigitalSignCallBack
 *	Ä¿µÄ:				ÉèÖÃÊý×ÖÇ©Ãû»Øµ÷.
 *   ÊäÈë²ÎÊý:           nPort:		½âÂëÍ¨µÀ¡£
 nFrameID:	Ö¡ÐòºÅ
 bSuccess:	Ð£ÑéÊÇ·ñÍ¨¹ý
 pUserData   ÓÃ»§Êý¾Ý
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *********************************************************************/
typedef void (CALLBACK* fCheckDigitalSignCB)(LONG nPort, int nFrameID, BOOL bSuccess, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDigitalSignCallBack(LONG nPort, fCheckDigitalSignCB pDigitalSignCB, void* pUserData);

/********************************************************************
 *	º¯ÊýÃû: 	    	PLAY_GetTimePicture
 *	Ä¿µÄ:				»ñµÃ¾ø¶ÔÊ±¼äµãÉÏÃæµÄÍ¼Æ¬
 *   ÊäÈë²ÎÊý:           filepath:	±£´æµÄÎÄ¼þÂ·¾¶
 time:		¾ø¶ÔÊ±¼ä
 DecCBFun:	ÉèÖÃ½øÈ¥µÄ½âÂë»Øµ÷
 user:		ÓÃ»§ÉÏÏÂÎÄ
 *   Êä³ö²ÎÊý:
 *   ·µ»ØÖµ:             TRUE:	³É¹¦
 FALSE:	Ê§°Ü
 *   ´´½¨Ê±¼ä:	        2012:12:21
 *   °æ±¾ÐÅÏ¢¼ÇÂ¼:	    2012/12/21:YeYamin:modify......
 *********************************************************************/
PLAYSDK_API BOOL CALLMETHOD PLAY_GetTimePicture(const char* filepath, struct tm* time, fDecCBFun fcbDec, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartFisheyeEx
// ÃèÊö: ÓãÇòÁª¶¯¹¦ÄÜÀ©Õ¹½Ó¿Ú£¬ÐèÒª°üº¬fisheye.dll MCL_FPTZ.dll¿â
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
//		 [in] startType:  ¿ªÆôÀàÐÍ£¬ 0Ö»¿ªÆôÓãÑÛÐ£Õý, 1Í¬Ê±¿ªÆôÁª¶¯ºÍÐ£Õý, 2Ö»¿ªÆôÓãÇòÁª¶¯Ëã·¨
//       [in] ptzChannelParam: ÓãÇòÁª¶¯³õÊ¼»¯Í¨µÀ²ÎÊý£¬startTypeÎª0Ê±£¬ptzChannelParamÌîNULL
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartFisheyeEx(LONG nPort, int startType, MHFPTZ_INITPARAM* ptzChannelParam);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFisheyeParams, ¼æÈÝ¾É°æ±¾ÓãÑÛ½Ó¿Ú
// ÃèÊö: ÉèÖÃÓãÑÛ²ÎÊý
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]nX				 :  ÓãÑÛÔ²ÐÄºá×ø±ê
//       [in]nY				 :  ÓãÑÛÔ²ÐÄ×Ý×ø±ê
//       [in]nRadius         :  ÓãÑÛ°ë¾¶
//       [in]nLensDirection  :  ¾µÍ··½Ïò
//       [in]mode            :  Í¼ÏñÏÔÊ¾Ä£Ê½
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFisheyeParams(LONG nPort, int nX, int nY, int nRadius, int nLensDirection, FISHSHOWMODES mode);

//------------------------------------------------------------------------
// º¯Êý: PLAY_FisheyeGetPosition, ¼æÈÝ¾É°æ±¾ÓãÑÛ½Ó¿Ú
// ÃèÊö: »ñµÃÄ¿±êÖÐÐÄ¶ÔÓ¦µç×ÓÔÆÌ¨µÄ½¹µãÎ»ÖÃ
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]row			 :  Ä¿±êÖÐÐÄËùÔÚÐÐ
//       [in]column			 :  Ä¿±êÖÐÐÄËùÔÚÁÐ
//		 [out]pX     		 :  Ä¿±êÖÐÐÄËù¶ÔÓ¦µç×ÓÔÆÌ¨µÄ½¹µãºá×ø±ê
//       [out]pY		     :  Ä¿±êÖÐÐÄËù¶ÔÓ¦µç×ÓÔÆÌ¨µÄ½¹µã×Ý×ø±ê
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_FisheyeGetPosition(LONG nPort, int row, int column, int *pX, int *pY);

//------------------------------------------------------------------------
// º¯Êý: PLAY_FisheyeEptzUpdate, ¼æÈÝ¾É°æ±¾ÓãÑÛ½Ó¿Ú
// ÃèÊö: ¿ªÆôeptz(µç×ÓÔÆÌ¨£©£¬½øÐÐËõ·ÅÒÆ¶¯
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in/out]pX			 :  eptz£¨µç×ÓÔÆÌ¨£©µÄ½¹µãºá×ø±ê
//       [in/out]pY			 :  eptzµÄ½¹µã×Ý×ø±ê
//		 [in/out]pHangle		 :  eptzµÄË®Æ½½Ç¶È·¶Î§(0-3600)
//       [in/out]pVangle		 :  eptzµÄ´¹Ö±½Ç¶È·¶Î§(0-900)
//       [in]ops             :  FISHEPTZOPTS½á¹¹Ìå,Îª0Ê±¶ÔÖ¸¶¨´°¿ÚÉèÖÃ½¹µã£¬Îª1±íÊ¾·Å´ó£¬2±íÊ¾ËõÐ¡£¬3±íÊ¾ÏòÉÏÒÆ¶¯£¬
//                              4±íÊ¾ÏòÏÂÒÆ¶¯£¬5±íÊ¾Ïò×óÒÆ¶¯£¬6±íÊ¾ÏòÓÒÒÆ¶¯£¬7±íÊ¾×Ô¶¯Ë³Ê±ÕëÐý×ª£¬8±íÊ¾×Ô¶¯ÄæÊ±ÕëÐý×ª
//								9±íÊ¾Í£Ö¹ÔÆÌ¨²Ù×÷£¬10±íÊ¾»ñÈ¡µ±Ç°ÔÆÌ¨´°¿ÚËùÔÚÎ»ÖÃ
//       [in]nWinNum         :  Òª½øÐÐeptzµÄ´°¿Ú±àºÅ£¬×óÉÏ½Çwin_numÎª1£¬´Ó×óµ½ÓÒµÝÔö
//       [in]nZoomStep       :  ·Å´óËõÐ¡µÄ²½³¤, ·¶Î§1-8
//       [in]nPtStep		 :  ÉÏÏÂ×óÓÒÒÆ¶¯µÄ²½³¤, ·¶Î§1-8
//		 [in]nRotateStep	 :  Ðý×ªµÄ²½³¤, ·¶Î§1-8
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OldFisheyeEptzUpdate(LONG nPort, int *pX, int *pY, int *pHAngle, int *pVAngle, FISHEPTZOPTS ops, int nWinNum,
                                                      int nZoomStep, int nPtStep, int nRotateStep);

/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromCoordinate
 * Ãè  Êö  : Ð£ÕýÍ¼ÏñºÍÔ´Í¼ÏñÖ®¼ä×ø±ê×ª»»
 * Êä  Èë  : - handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - x:ÐèÒª×ª»»µÄ×ø±ê
          y:ÐèÒª×ª»»µÄ×ø±ê
          winid:winid²ÎÊý£¬µ±flag=0£¬Õâ¸öÎªÊäÈë²ÎÊý  µ±flag=1£¬Õâ¸ö²ÎÊýÎªÊä³ö²ÎÊý
          u:×ª»»ºóµÄ×ø±ê
          v:×ª»»ºóµÄ×ø±ê
          flag£º0ÎªÐ£ÕýºóÍ¼Ïñ×ªÔ­Ê¼Í¼Ïñ×ø±ê£¬1±íÊ¾Ô­Ê¼Í¼Ïñ×ø±ê×ªÐ£ÕýºóÍ¼Ïñ×ø±ê
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinate(LONG nPort, int x, int y, int *winid, int *u, int *v, int flag);

/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromCoordinateFSTA(from source to adjust)
 * Ãè  Êö  : Ô´Í¼Ïñ×ø±ê×ªÐ£ÕýºóÍ¼Ïñ×ø±ê
 * Êä  Èë  : - handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - points:ÐèÒª×ª»»µÄÔ­Ê¼Í¼ÏñÉÏµÄ×ø±ê
          num:×ø±ê¸öÊý
          points_adjust:×ª»»ºóµÄ×ø±ê
          winid:×ª»»ºóµÄ×ø±ê¶ÔÓ¦µÄ´°¿Úid
          points_adjust_num    Êä³öµãµÄ¸öÊý
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *           other: ÕâÀïÈç¹û1¸öÔ­Ê¼Í¼ÏñÉÏµÄµã¶ÔÓ¦¶à¸ö×Ó´°¿ÚµÄµã£¬ÄÇÃ´Õâ¸öµã»áÓÐ¶à¸öpoints_adjuest
 Ã¿¸öpoints_adjust¶ÔÓ¦Ò»¸öwinid£»
 
 ±ÈÈç£¨10,10£© µãÊôÓÚ´°¿Ú1ºÍ´°¿Ú2,ÔÚ´°¿Ú1ÉÏµÄ¶ÔÓ¦×ø±êÊÇ£¨100,100£©£¬ÔÚ´°¿Ú2ÉÏµÄ
 ¶ÔÓ¦×ø±êÊÇ£¨1000,1000£©
 ÄÇÃ´	points_adjust[i].x = 100,		winid[i] = 1;
 points_adjust[i].y = 100,
 points_adjust[i+1].x = 1000,	winid[i+1] = 2;
 points_adjust[i+1].y = 1000,
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinateFSTA(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *winid, int *points_adjust_num);

/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromCoordinateFATS(from adjust to source)
 * Ãè  Êö  : Ð£ÕýºóÍ¼Ïñ×ø±ê×ªÔ´Í¼Ïñ×ø±ê
 * Êä  Èë  :	- handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - points:ÐèÒª×ª»»µÄÐ£ÕýºóÍ¼ÏñÉÏµÄ×ø±ê
          num:×ø±ê¸öÊý
          points_adjust:×ª»»ºóµÄ×ø±ê
          winid:ÐèÒª×ª»»µÄ×ø±êµÄ´°¿Úid
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromCoordinateFATS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int winid);

/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromLineFATS(from adjust to source)
 * Ãè  Êö  : Ð£ÕýºóÍ¼ÏñÕÛÏß×ªÔ´Í¼ÏñÇúÏß
 * Êä  Èë  :	- handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - points:ÐèÒª×ª»»µÄÐ£ÕýºóÍ¼ÏñÉÏÕÛÏßµãÐÅÏ¢
          num:µã¸öÊý
          points_adjust:×ª»»ºóµÄÇúÏßÐÅÏ¢
          winid:ÐèÒª×ª»»µÄ×ø±êµÄ´°¿Úid
          pOpt :ÅäÖÃÐÅÏ¢,µ÷ÓÃÕâ¸ö½Ó¿ÚÖ®Ç°ÏÈµ÷ÓÃFisheye_GetParam»ñÈ¡
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFATS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int winid, FISHEYE_OPTPARAM *pOpt);


/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromLineFSTA(from source to adjust)
 * Ãè  Êö  : Ô­Ê¼Í¼ÏñÕÛÏß×ªÐ£ÕýºóÍ¼ÏñÇúÏß
 * Êä  Èë  : - handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - points:ÐèÒª×ª»»µÄÔ­Ê¼Í¼ÏñÉÏµÄ×ø±ê
 num:×ø±ê¸öÊý
 points_adjust:×ª»»ºóµÄ×ø±ê
 winid:×ª»»ºóµÄ×ø±ê¶ÔÓ¦µÄ´°¿Úid
 points_adjust_num    Êä³öµãµÄ¸öÊý
 pOpt:ÅäÖÃÐÅÏ¢ µ÷ÓÃÕâ¸ö½Ó¿ÚÖ®Ç°ÏÈµ÷ÓÃFisheye_GetParam»ñÈ¡
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *other: ÕâÀïÈç¹û1¸öÔ­Ê¼Í¼ÏñÉÏµÄµã¶ÔÓ¦¶à¸ö×Ó´°¿ÚµÄµã£¬ÄÇÃ´Õâ¸öµã»áÓÐ¶à¸öpoints_adjuest
 Ã¿¸öpoints_adjust¶ÔÓ¦Ò»¸öwinid£»
 
 ±ÈÈç£¨10,10£© µãÊôÓÚ´°¿Ú1ºÍ´°¿Ú2,ÔÚ´°¿Ú1ÉÏµÄ¶ÔÓ¦×ø±êÊÇ£¨100,100£©£¬ÔÚ´°¿Ú2ÉÏµÄ
 ¶ÔÓ¦×ø±êÊÇ£¨1000,1000£©
 ÄÇÃ´	points_adjust[i].x = 100,		winid[i] = 1;
 points_adjust[i].y = 100,
 points_adjust[i+1].x = 1000,	winid[i+1] = 2;
 points_adjust[i+1].y = 1000,
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFSTA(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *winid, int *points_adjust_num, FISHEYE_OPTPARAM *pOpt);

/******************************************************************************
 *
 * º¯ÊýÃû  : PLAY_FishEyeTransFromLineFSTS(from source to source)
 * Ãè  Êö  : Ô­Ê¼Í¼ÏñÕÛÏß×ªÔ­Ê¼Í¼ÏñÇúÏß
 * Êä  Èë  : - handle: ÓãÑÛËã·¨ÊµÀý¾ä±ú
 - points:ÐèÒª×ª»»µÄÔ­Ê¼Í¼ÏñÉÏµÄ×ø±ê
 num:×ø±ê¸öÊý
 points_adjust:×ª»»ºóµÄ×ø±ê
 points_adjust_num    Êä³öµãµÄ¸öÊý
 pOpt:ÅäÖÃÐÅÏ¢ µ÷ÓÃÕâ¸ö½Ó¿ÚÖ®Ç°ÏÈµ÷ÓÃFisheye_GetParam»ñÈ¡
 * Êä  ³ö  : ÎÞ
 * ·µ»ØÖµ  : BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
 *******************************************************************************/
PLAYSDK_API BOOL PLAY_FishEyeTransFromLineFSTS(LONG nPort, FISHEYE_POINT2D *points, int num, FISHEYE_POINT2D *points_adjust, int *points_adjust_num, FISHEYE_OPTPARAM *pOpt);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartDeNoise
// ÃèÊö: ¿ªÆôÊÓÆµÈ¥ÔëËã·¨¹¦ÄÜ,ÐèÒª°üº¬3dnr.dll¿â
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDeNoise(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDeNoiseParams
// ÃèÊö: ÉèÖÃÊÓÆµÈ¥Ôë²ÎÊý
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]nTemporal		 :  Ê±ÓòÈ¥ÔëÇ¿¶È [0,32]
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDeNoiseParams(LONG nPort, int nTemporal);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopDeNoise
// ÃèÊö: Í£Ö¹ÊÓÆµÈ¥ÔëËã·¨¹¦ÄÜ
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDeNoise(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartDeHaze
// ÃèÊö: ¿ªÆôÊÓÆµÈ¥ÎíËã·¨¹¦ÄÜ£¬ÐèÒª°üº¬dehazing.dll¿â
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDeHaze(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDehazeParams
// ÃèÊö: ÉèÖÃÊÓÆµÈ¥Îí²ÎÊý
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]ALightValue	 :	Éè¶¨µÄ´óÆø¹âÇ¿µÄÖµ£¬·¶Î§0-255
//		 [in]AutoLightOn	 :  Ä¬ÈÏÎª1,´ú±í¿ªÆô×Ô¶¯Ñ°ÕÒ´óÆø¹âÇ¿£»0-¹Ø±Õ×Ô¶¯£¬¿ªÆôÊÖ¶¯
//       [in]AutoRun		 :	Ä¬ÈÏÎª1,´ú±íÒ»Ö±¿ªÆôÈ¥Îí¹¦ÄÜ£¬0-×Ô¶¯ÅÐ¶ÏÊÇ·ñÎíÌì²¢È¥Îí
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDehazeParams(LONG nPort, int ALightValue, int AutoLightOn, int AutoRun);

//------------------------------------------------------------------------
// º¯Êý: PLAY_STOPDeHaze
// ÃèÊö: Í£Ö¹ÊÓÆµÈ¥ÎíËã·¨¹¦ÄÜ
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopDeHaze(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartIVSE
// ÃèÊö: ¿ªÆôÊÓÆµÔöÇ¿Ëã·¨¹¦ÄÜ£¬ÐèÒª°üº¬IvseDll.dll¿â
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//
// ×¢Òâ£º´ËËã·¨´¦ÀíÊ±¼ä½Ï³¤£¬²»½¨Òé´¦Àí¸ßÇåÊÓÆµ
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartIVSE(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetIVSEParams
// ÃèÊö: ÉèÖÃÊÓÆµÔöÇ¿²ÎÊý£¬¿ÉÒÔ¶à´Îµ÷ÓÃÀ´×éºÏÊ¹ÓÃ¶àÖÖIVSE¿âµÄ¹¦ÄÜ
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]pIVSEParams	 :	IVSEPARAMS½á¹¹Ìå²ÎÊý
//		 [in]bEnable		 :  ¶ÔÓ¦ÓÚIVSEPARAMSÖÐµÄIVSEFUNCTYPE¹¦ÄÜÑ¡Ïî£¬Ê¹ÄÜ¿ª¹Ø
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIVSEParams(LONG nPort, IVSEPARAMS* pIVSEParams, BOOL bEnable);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopIVSE
// ÃèÊö: Í£Ö¹ÊÓÆµÔöÇ¿Ëã·¨¹¦ÄÜ
// ²ÎÊý: [in]nPort : Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopIVSE(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ConvertToBmpFile
// ÃèÊö: Í¼Ïñ¸ñÊ½×ªÎªBMP¸ñÊ½.
// ²ÎÊý: pBuf,Í¼ÏñÊý¾ÝÖ¸Õë
//		 nSize,Í¼ÏñÊý¾Ý´óÐ¡
//		 nWidth,Í¼Ïñ¿í¶È
//		 nHeight,Í¼Ïñ¸ß¶È
//		 nType,Êý¾ÝÀàÐÍ.T_RGB32,T_UYVYµÈ.
//		 sFileName,Òª±£´æµÄÎÄ¼þÃû.×îºÃÒÔBMP×÷ÎªÎÄ¼þÀ©Õ¹Ãû.
//       nBmpType, BMPÀàÐÍ£¬PIC_BMP_32±íÊ¾BMP32£¬ PIC_BMP_24±íÊ¾BMP24
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ConvertToBmpFileEx(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType, char *sFileName,int nBmpType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_EnableLargePicAdjustment
// ÃèÊö: ÊÇ·ñÆôÓÃ¸ßÇåÍ¼ÏñÄÚ²¿µ÷Õû²ßÂÔ£¬Ä¬ÈÏÆôÓÃ¡£¸Ã²ßÂÔÆôÓÃÊ±£¬ÔÚ¿ì·Å4±¶ËÙÒÔÉÏÊ±£¬Ö»²¥·ÅIÖ¡£¬²»ÆôÓÃÊ±£¬ÔòÃ¿Ö¡¶¼²¥·Å
// ²ÎÊý: [in]nPort           :  Í¨µÀºÅ
//		 [in]bEnable		 :  TRUE±íÊ¾ÆôÓÃ´Ë¹¦ÄÜ£¬FALSE±íÊ¾¹Ø±Õ´Ë¹¦ÄÜ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_EnableLargePicAdjustment(LONG nPort, BOOL bEnable);

//------------------------------------------------------------------------
// Í¬²½²¥·Å½Ó¿Ú
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// º¯Êý: PLAY_OpenPlayGroup
// ÃèÊö: ´ò¿ªÍ¬²½²¥·Å
// ²ÎÊý: ÎÞ
// ·µ»Ø: Í¬²½²¥·Å¿ØÖÆ¾ä±ú£¬ÔÚµ÷ÓÃÍ¬²½²¥·Å¿ØÖÆ½Ó¿ÚÊ±ÐèÒª´«Èë¸Ã¾ä±ú£¬·µ»ØNULL±íÊ¾Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API void* CALLMETHOD PLAY_OpenPlayGroup();

//------------------------------------------------------------------------
// º¯Êý: PLAY_AddToPlayGroup
// ÃèÊö: Ìí¼ÓÒ»Â·ÒÑ¾­´ú¿ªµÄÊÓÆµÖÁÍ¬²½²¥·ÅÖÐ
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//       nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AddToPlayGroup(void* hPlayGroup, LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_DelFromPlayGroup
// ÃèÊö: ´ÓÍ¬²½²¥·Å¶ÓÁÐÖÐÉ¾³ýÖ¸¶¨Í¨µÀºÅ
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//       nPort,Í¨µÀºÅ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_DelFromPlayGroup(void* hPlayGroup, LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayGroupDirection
// ÃèÊö: ´Óµ±Ç°Ê±¼äµãÕý·Å»òµ¹·Å
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//		 nDirection,²¥·Å·½Ïò£º0£¬ÏòÇ°£¬1£¬Ïòºó
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayGroupDirection(void* hPlayGroup, int nDirection);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayGroupSpeed
// ÃèÊö: ÉèÖÃ²¥·ÅËÙ¶È
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//		 fCoff,²¥·ÅËÙ¶È,·¶Î§[1/64~64.0],Ð¡ÓÚ1±íÊ¾Âý·Å£¬´óÓÚ1±íÊ¾Õý·Å.
//			   µ±²¥·ÅËÙ¶È½Ï¿ìÊ±¿ÉÄÜ»á³éÖ¡²¥·Å.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayGroupSpeed(void* hPlayGroup, float fSpeed);

//------------------------------------------------------------------------
// º¯Êý: PLAY_PausePlayGroup
// ÃèÊö: ÔÝÍ£»ò¼ÌÐø
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//		 bPause,TRUEÔÝÍ£,FLASE»Ö¸´
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_PausePlayGroup(void* hPlayGroup, BOOL bPause);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StepPlayGroup
// ÃèÊö: µ¥Ö¡²¥·Å
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StepPlayGroup(void* hPlayGroup);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StepPlayGroup
// ÃèÊö: ²ÉÓÃ¾ø¶ÔÊ±¼ä½øÐÐ¶¨Î»
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
//	     pstDateTime,¾ø¶ÔÊ±¼ä
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SeekPlayGroup(void* hPlayGroup, DATETIME_INFO* pstDateTime);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ClosePlayGroup
// ÃèÊö: ¹Ø±ÕÍ¬²½²¥·Å¿ØÖÆ
// ²ÎÊý: hPlayGroup,Í¬²½²¥·Å¾ä±ú£¬ÓÉPLAY_OpenPlayGroup·µ»Ø
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ClosePlayGroup(void* hPlayGroup);


//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileRefCallBack
// ÃèÊö: ÉèÖÃ½¨Á¢Ë÷Òý»Øµ÷,ÔÚÎÄ¼þ´ò¿ªÊ±Éú³ÉÎÄ¼þË÷Òý.Õâ¸ö¹ý³ÌºÄÊ±±È½Ï³¤,´óÔ¼
//			Ã¿Ãë´¦Àí40M×óÓÒµÄÊý¾Ý,ÒòÎª´ÓÓ²ÅÌ¶ÁÊý¾Ý±È½ÏÂý,½¨Á¢Ë÷ÒýµÄ¹ý³ÌÊÇÔÚ
//			ºóÌ¨Íê³É,ÐèÒªÊ¹ÓÃË÷ÒýµÄº¯ÊýÒªµÈ´ýÕâ¸ö¹ý³Ì½áÊø,ÆäËû½Ó¿Ú²»ÊÜÓ°Ïì.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pFileRefDone,»Øµ÷º¯ÊýÖ¸Õë,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData,ÓÃ»§×Ô¶¨Òå²ÎÊý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void(CALLBACK *fpFileRefDoneCBFun)(DWORD nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileRefCallBack(LONG nPort,
                                                    fpFileRefDoneCBFun pFileRefDoneCBFunc,
                                                    void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDemuxCallBack
// ÃèÊö: Ô´Êý¾Ý·ÖÎöÍêµÄÊý¾Ý»Øµ÷
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 DecCBFun,·ÖÎöÊý¾Ý»Øµ÷Ö¸Õë
//			nPort,Í¨µÀºÅ
//			pBuf,Êý¾ÝÖ¸Õë
//			nSize,Êý¾Ý³¤¶È
//			pParam,Ö¡ÐÅÏ¢  Ö¸ÏòDEMUX_INFOÕâ¸ö½á¹¹Ìå
//			nReserved,±£Áô
//			pUserData,ÓÃ»§×Ô¶¨ÒåÊý¾Ý
//		 pUserData,ÓÃ»§×Ô¶¨ÒåÊý¾Ý
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fDemuxDecCBFun)(LONG nPort,char * pBuf,	LONG nSize,void * pParam,void* pReserved, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDemuxCallBack(LONG nPort, fDemuxDecCBFun DecCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileDoneTimeCallBack
// ÃèÊö: ÎÄ¼þ¿ªÊ¼¡¢½áÊøÊ±¼ä»Øµ÷¡£·ÖÎö³öÎÄ¼þ¿ªÊ¼ºÍ½áÊøÊ±¼äºó»áµ÷ÓÃ¸Ã»Øµ÷¡£
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 fFileTimeDoneCBFun,»Øµ÷º¯ÊýÖ¸Õë,²»ÄÜÎªNULL,Æä²ÎÊýº¬ÒåÈçÏÂ:
//			nPort,Í¨µÀºÅ
//			nStartTime, ÎÄ¼þ¿ªÊ¼Ê±¼ä.×Ô1970Äê1ÔÂ1ÈÕ0µã0·Ö0ÃëµÄÃëÊý.
//			nEndTime, ÎÄ¼þ½áÊøÊ±¼ä.×Ô1970Äê1ÔÂ1ÈÕ0µã0·Ö0ÃëµÄÃëÊý.
//			pUserData, ÓÃ»§×Ô¶¨Òå²ÎÊý
//		 pUserData, ÓÃ»§×Ô¶¨Òå²ÎÊý.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fFileTimeDoneCBFun)(LONG nPort, DWORD nStarTime, DWORD nEndTime, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileTimeDoneCallBack(LONG nPort, fFileTimeDoneCBFun FileTimeCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetKeyFramePosByAbsoluteTime
// ÃèÊö: °´¾ø¶ÔÊ±¼ä²éÕÒÖ¸¶¨Î»ÖÃÖ®Ç°µÄ¹Ø¼üÖ¡Î»ÖÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 t,¾ø¶ÔÊ±¼ä,Ïê¼ûSYSTEMTIME.½öÓÃµ½ÄêÔÂÈÕÊ±·ÖÃë.×¢£ºÔÚÖ´ÐÐ³É¹¦ºó¸ÃÖµ´æ´¢Ëù·µ»ØIÖ¡µÄÊ±¼ä´Á
//		 framePos,²éÕÒµ½µÄ¹Ø¼üÖ¡µÄÎÄ¼þÎ»ÖÃÐÅÏ¢½á¹¹Ö¸Õë,Ïê¼ûPFRAME_POS.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* t, FRAME_POS* framePos);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetNextKeyFramePosByAbsoluteTime
// ÃèÊö: °´¾ø¶ÔÊ±¼ä²éÕÒÖ¸¶¨Î»ÖÃÖ®ºóµÄ¹Ø¼üÖ¡Î»ÖÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 t,¾ø¶ÔÊ±¼ä,Ïê¼ûSYSTEMTIME.½öÓÃµ½ÄêÔÂÈÕÊ±·ÖÃë.×¢£ºÔÚÖ´ÐÐ³É¹¦ºó¸ÃÖµ´æ´¢Ëù·µ»ØµÄIÖ¡µÄÊ±¼ä´Á
//		 framePos,²éÕÒµ½µÄ¹Ø¼üÖ¡µÄÎÄ¼þÎ»ÖÃÐÅÏ¢½á¹¹Ö¸Õë,Ïê¼ûPFRAME_POS.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_GetNextKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* t, FRAME_POS* framePos);

//------------------------------------------------------------------------
// º¯Êý: PLAY_QueryGroupPlayingTime
// ÃèÊö: ²éÑ¯µ±Ç°×éÖÐÕýÔÚ²¥·ÅµÄÊ±¼ä.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pDateTime,Ê±¼ä
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
PLAYSDK_API BOOL CALLMETHOD PLAY_QueryGroupPlayingTime(void* hPlayGroup,  DATETIME_INFO *pDateTime);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetAudioChannels
// ÃèÊö: »ñÈ¡ÒôÆµÍ¨µÀ×ÜÊý
// ²ÎÊý: nPort,Í¨µÀºÅ
//       pChannels, Êä³ö²ÎÊý£¬[0-255].
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioChannels(LONG nPort, DWORD* pChannels);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ChooseAudio
// ÃèÊö: Ñ¡ÔñÒôÆµÍ¨µÀ
// ²ÎÊý: nPort,Í¨µÀºÅ
//       nChannelID, ÒôÆµÍ¨µÀ´Ó0¿ªÊ¼.
//       bFlag,TRUE´ò¿ª,FALSE¹Ø±Õ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChooseAudio(LONG nPort, DWORD nChannelID, BOOL bFlag);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetAudioChooseState
// ÃèÊö: »ñÈ¡ÒôÆµÍ¨µÀ´ò¿ª¹Ø±Õ×´Ì¬
// ²ÎÊý: nPort,Í¨µÀºÅ
//       nChannelID, ÒôÆµÍ¨µÀ[0-255].
//       pFlag,TRUE´ò¿ª,FALSE¹Ø±Õ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetAudioChooseState(LONG nPort, DWORD nChannelID, BOOL* bFlag);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayedAbsTime
// ÃèÊö: °´¾ø¶ÔÊ±¼äÉèÖÃ²¥·ÅÊ±¼ä
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 pDateTime,¾ø¶ÔÊ±¼ä
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayedAbsTime(LONG nPort, DATETIME_INFO *pDateTime);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPlayPosByFileOffset
// ÃèÊö: °´ÎÄ¼þÆ«ÒÆÉèÖÃ²¥·ÅÎ»ÖÃ
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 nFileOffset,ÎÄ¼þÆ«ÒÆÎ»ÖÃ
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPlayPosByFileOffset(LONG nPort, UINT nFileOffset);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetCurrentFrameRateEx
// ÃèÊö: »ñµÃµ±Ç°Ö¡ÂÊ£¨Ð¡ÊýÐÎÊ½£©
// ²ÎÊý: nPort,Í¨µÀºÅ
// ·µ»Ø: float,µ±Ç°Ö¡Â
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetCurrentFrameRateEx(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_InitDDraw
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InitDDraw(HWND hWnd);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetCaps
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API int	CALLMETHOD PLAY_GetCaps();

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetFileHeadLength
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetFileHeadLength();

//------------------------------------------------------------------------
// º¯Êý: PLAY_RealeseDDraw
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RealeseDDraw();

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetDDrawDeviceTotalNums
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetDDrawDeviceTotalNums();

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDDrawDevice
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDDrawDevice(LONG nPort,DWORD nDeviceNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetDDrawDeviceInfo
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetDDrawDeviceInfo(DWORD nDeviceNum,LPSTR  lpDriverDescription,DWORD nDespLen,LPSTR lpDriverName ,DWORD nNameLen,LONG *hhMonitor);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetCapsEx
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API int	CALLMETHOD PLAY_GetCapsEx(DWORD nDDrawDeviceNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ThrowBFrameNum
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ThrowBFrameNum(LONG nPort,DWORD nNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_InitDDrawDevice
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL	CALLMETHOD PLAY_InitDDrawDevice();

//------------------------------------------------------------------------
// º¯Êý: PLAY_ReleaseDDrawDevice
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API void CALLMETHOD PLAY_ReleaseDDrawDevice();

//------------------------------------------------------------------------
// º¯Êý: PLAY_Back
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Back(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDDrawDeviceEx
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDDrawDeviceEx(LONG nPort,DWORD nRegionNum,DWORD nDeviceNum);


//------------------------------------------------------------------------
// º¯Êý: PLAY_SetOverlayMode
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§£¬overlayÄ£Ê½ÒÑ¾­¹ýÊ±
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);


//------------------------------------------------------------------------
// º¯Êý: PLAY_GetOverlayMode
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§£¬overlayÄ£Ê½ÒÑ¾­¹ýÊ±
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetOverlayMode(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetColorKey
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§£¬overlayÄ£Ê½ÒÑ¾­¹ýÊ±
//------------------------------------------------------------------------
PLAYSDK_API COLORREF CALLMETHOD PLAY_GetColorKey(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ChangeRate
// ÃèÊö: Ìæ´ú½Ó¿ÚPLAY_SetPlaySpeed
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChangeRate(LONG nPort, int rate);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetTimerType
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
PLAYSDK_API BOOL CALLMETHOD PLAY_SetTimerType(LONG nPort,DWORD nTimerType,DWORD nReserved);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetTimerType
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
PLAYSDK_API BOOL CALLMETHOD PLAY_GetTimerType(LONG nPort,DWORD *pTimerType,DWORD *pReserved);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetMDRange
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMDRange(LONG nPort,DISPLAYRECT* rc,DWORD nVauleBegin,DWORD nValueEnd,DWORD nType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetMDThreShold
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMDThreShold(LONG nPort, DWORD ThreShold);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetMDPosition
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetMDPosition(LONG nPort, DWORD Direction, DWORD nFrame, DWORD* MDValue);


//------------------------------------------------------------------------
// º¯Êý: PLAY_CutFileSegment
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
typedef void (CALLBACK *CutProgressFunc)(DWORD nPort, int iProgress, DWORD dwUser);
PLAYSDK_API BOOL CALLMETHOD PLAY_CutFileSegment(LONG nPort,
                                                LONG lBeginTime,
                                                LONG lEndTime,
                                                CutProgressFunc pFunc,
                                                char *sOutFilePath,
                                                DWORD dwUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetVideoPerTimer
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVideoPerTimer(int iVal);


//------------------------------------------------------------------------
// º¯Êý: PLAY_GetVideoPerTimer
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetVideoPerTimer(int* pVal);

//------------------------------------------------------------------------
// º¯Êý: PLAY_InputVideoData
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_InputAudioData
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetVerifyCallBack
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
typedef void (CALLBACK * fVerifyCBFun)(LONG nPort, FRAME_POS * pFilePos, DWORD bIsVideo, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, fVerifyCBFun VerifyFun, void* pUserData);


//------------------------------------------------------------------------
// º¯Êý: PLAY_SetSourceBufCallBack
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
typedef void (CALLBACK * fSourceBufCBFun)(LONG nPort,DWORD nBufSize, void* pUserData,void*pResvered);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetSourceBufCallBack(LONG nPort,
                                                      DWORD nThreShold,
                                                      fSourceBufCBFun SourceBufCBFun,
                                                      void* pUserData,
                                                      void *pReserved);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ResetSourceBufFlag
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ResetSourceBufFlag(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetPandoraWaterMarkCallBack
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetPandoraWaterMarkCallBack(LONG nPort, GetWaterMarkInfoCallbackFunc pFunc, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDisplayBuf
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayBuf(LONG nPort,DWORD nNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetDisplayBuf
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API DWORD CALLMETHOD PLAY_GetDisplayBuf(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDisplayType
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDisplayType(LONG nPort,LONG nType);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetDisplayType
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API LONG CALLMETHOD PLAY_GetDisplayType(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_RefreshPlayEx
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RefreshPlayEx(LONG nPort,DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OpenStreamEx
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OpenStreamEx(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CloseStreamEx
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CloseStreamEx(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_AdjustFluency
// ÃèÊö: ´Ë½Ó¿ÚÎÞÐ§
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_AdjustFluency(LONG nPort, int level);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SurfaceChange
// ÃèÊö: Android°æ±¾×¨ÓÃ£¬Surface½¨Á¢»ò±ä»¯Í¨Öª
// ²ÎÊý:
// ·µ»Ø:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SurfaceChange(LONG nPort, HWND hWnd);

//------------------------------------------------------------------------
// º¯Êý: PLAYER_SetFileInfoFrameCallback
// ÃèÊö: ÉèÖÃÎÄ¼þÐÅÏ¢Ö¡»Øµ÷º¯Êý
// ²ÎÊý:
// ·µ»Ø:
//------------------------------------------------------------------------
typedef int (CALLBACK* fOnFileInfoFrame)(LONG nPort, FILE_INFO_IMAGE* pFileInfoImage, FILE_INFO_FRAME* pFileInfoFrame, void* pUserParam);
PLAYSDK_API BOOL CALLMETHOD	PLAY_SetFileInfoFrameCallback(LONG nPort, fOnFileInfoFrame fFileInfoFrame, tPicFormats imageType, void* pUserParam);

//------------------------------------------------------------------------
// º¯Êý: PLAYER_SetAnalyzePositionCallback
// ÃèÊö: ÉèÖÃÎÄ¼þÐÅÏ¢Ö¡·ÖÎö½ø¶È»Øµ÷º¯Êý
// ²ÎÊý:
// ·µ»Ø:
//------------------------------------------------------------------------
typedef int (CALLBACK *fOnAnalyzePosition)(LONG nPort, DATETIME_INFO* pstDateTime, void* pUserParam);
PLAYSDK_API BOOL CALLMETHOD	PLAY_SetAnalyzePositionCallback(LONG nPort, fOnAnalyzePosition fAnalyzePosition, void* pUserParam);

//------------------------------------------------------------------------
// º¯Êý: PLAYER_StartFileFrameDetect
// ÃèÊö: ÐèÒªÔÚË÷Òý½¨Á¢Íê³ÉÖ®ºó£¬¿ªÊ¼ÎÄ¼þÐÅÏ¢Ö¡¼ì²â£¬ÊäÈëËÑË÷Ìõ¼þ
// ²ÎÊý:
// ·µ»Ø:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD	PLAY_StartFileFrameDetect(LONG nPort, FILE_INFO_FRAME_SEARCH* pFileInfoFrameSearch);

//------------------------------------------------------------------------
// º¯Êý: PLAYER_StopFileFrameDetect
// ÃèÊö: ÖÐÖ¹ËÑË÷
// ²ÎÊý:
// ·µ»Ø:
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD	PLAY_StopFileFrameDetect(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartEdgeEnhance
// ÃèÊö: ¿ªÆôÍ¼ÏñÈñ»¯´¦Àí
// ²ÎÊý: level	   -- ´¦ÀíµÈ¼¶,0-¹Ø±Õ,6-×îÇ¿,Ä¬ÈÏµÈ¼¶4
//		 algMode   -- Ëã·¨Ä£Ê½,Ô¤Áô½Ó¿Ú,Ä¿Ç°Ö»Ö§³Ö0
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartEdgeEnhance(LONG nPort, int level, int algMode);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopEdgeEnhance
// ÃèÊö: ¹Ø±ÕÍ¼ÏñÈñ»¯´¦Àí
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopEdgeEnhance(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartVideoStable
// ÃèÊö: ¿ªÆôÊÓÆµ·À¶¶
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StartVideoStable(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StopEdgeEnhance
// ÃèÊö: ¹Ø±ÕÊÓÆµ·À¶¶
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_StopVideoStable(LONG nPort);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Scale
// ÃèÊö: ÊÖ»ú°æ±¾Í¼ÏñËõ·Å
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       scale	Ëõ·Å±ÈÀý[1.0, 8.0]
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Scale(LONG nPort, float scale, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_Translate
// ÃèÊö: ÊÖ»ú°æ±¾Í¼ÏñÆ½ÒÆ
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       x	xÆ½ÒÆ×ø±ê£¬¾ø¶ÔÖµ
//	     y	yÆ½ÒÆ×ø±ê£¬¾ø¶ÔÖµ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_Translate(LONG nPort, float x, float y, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetIdentity
// ÃèÊö: ÊÖ»ú°æ±¾Í¼Ïñ¹éÒ»»¯£¬ÖØÖÃÆ½ÒÆ£¬Ëõ·Å²Ù×÷¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SetIdentity(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetScale
// ÃèÊö: ÊÖ»ú°æ±¾»ñÈ¡µ±Ç°Ëõ·ÅÖµ¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetScale(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetTranslateX
// ÃèÊö: ÊÖ»ú°æ±¾»ñÈ¡µ±Ç°xÖáÆ½ÒÆ×ø±ê¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetTranslateX(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetTranslateX
// ÃèÊö: ÊÖ»ú°æ±¾»ñÈ¡µ±Ç°yÖáÆ½ÒÆ×ø±ê¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API float CALLMETHOD PLAY_GetTranslateY(LONG nPort, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_CleanScreen
// ÃèÊö: ÊÖ»ú°æ±¾ÇåÆÁ¹¦ÄÜ
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_CleanScreen(LONG nPort, float red, float green, float blue, float alpha, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ViewResolutionChanged
// ÃèÊö: Android°æ±¾,SurfaceView´óÐ¡±ä»¯Ê±µ÷ÓÃ
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ViewResolutionChanged(LONG nPort, int nWidth, int nHeight, DWORD nRegionNum);

//------------------------------------------------------------------------
// º¯Êý: PLAY_StartDataRecordEx
// ÃèÊö: ¿ªÊ¼Á÷Êý¾ÝÂ¼Ïñ,Ö»¶ÔÁ÷Ä£Ê½ÓÐÓÃ,ÔÚPLAY_PlayÖ®ºóµ÷ÓÃ.
// ²ÎÊý: nPort,Í¨µÀºÅ
//		 sFileName,Â¼ÏñÎÄ¼þÃû,Èç¹ûÎÄ¼þÃûÖÐÓÐ²»´æÔÚµÄÎÄ¼þ¼Ð,¾Í´´½¨¸ÃÎÄ¼þ¼Ð.
//		 idataType,0±íÊ¾Ô­Ê¼ÊÓÆµÁ÷;1±íÊ¾×ª»»³ÉAVI¸ñÊ½;2±íÊ¾×ª»»³ÉASF¸ñÊ½;3·Ö¶Î±£´æÎÄ¼þ
//		 fListenter, »Øµ÷º¯Êý£¬¼àÌýÊý¾ÝÐ´¹ý³ÌÖÐ·¢Éú´íÎó.
// ·µ»Ø: BOOL,³É¹¦·µ»ØTRUE,Ê§°Ü·µ»ØFALSE.
//------------------------------------------------------------------------
typedef void (CALLBACK* fRecordErrorOccur)(LONG nPort, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_StartDataRecordEx(LONG nPort, char *sFileName, int idataType, fRecordErrorOccur fListenter, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetMultiFrameDecCallBack
// ÃèÊö: ¿ªÆô½âÂëÐÅÏ¢»Øµ÷£¬Õë¶ÔSVACÂëÁ÷ÖÐµÄÐ©¼à¿ØÐÅÏ¢¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nRegionNum,ÏÔÊ¾ÇøÓòÐòºÅ, ±£Áô¡£
//		 DecInfoCallBack, »Øµ÷º¯Êý
//		 pUser, ÓÃ»§»Øµ÷Êý¾Ý
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
typedef void (CALLBACK* fMultiFrameDecCallBack)(LONG nPort, LONG nStreamID, char* pData, LONG nLen,
FRAME_INFO* stFrameInfo, void* pUserData, LONG nReserved1);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMultiFrameDecCallBack(LONG nPort, fMultiFrameDecCallBack DecInfoCallBack, void* pUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetMultiFrameCallBack
// ÃèÊö: ¿ªÆô¶àÖ¡ÐÅÏ¢»Øµ÷£¬Ä¿Ç°Ö÷ÒªÕë¶ÔSVAC±àÂë£¬
//       SVC¹¦ÄÜÖÐ£¬Ò»·ÝÊý¾Ý´øÓÐ»ù±¾²ãºÍÔöÇ¿²ãÁ½·ÝÊý¾Ý
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       MultiFrameCallBack, »Øµ÷º¯Êý¡£
//       pUser  ÓÃ»§Êý¾Ý
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
typedef void (CALLBACK* fMultiFrameCallBack)(LONG nPort, LONG nStreamID, void* pUserData, LONG nReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMultiFrameCallBack(LONG nPort, fMultiFrameCallBack MultiFrameCallBack, void* pUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetDecInfoCallBack
// ÃèÊö: ¿ªÆô¶àÖ¡ÐÅÏ¢»Øµ÷£¬Õë¶ÔSVACÂëÁ÷
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nFrameID, Ñ¡Ôñ½øÐÐ²¥·ÅµÄÖ¡
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
typedef void (CALLBACK* fDecInfoCallBack)(LONG nPort, FRAME_DEC_EXT_INFO* pDecInfo, void* pUserData, LONG nReserved);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecInfoCallBack(LONG nPort, fDecInfoCallBack DecInfoCallBack, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_ChooseFrame
// ÃèÊö: Ñ¡ÔñÏÔÊ¾SVAC±àÂëSVCµÄ»ù±¾²ã»òÔöÇ¿²ã
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       nFrameID, ÒªÏÔÊ¾µÄ²ã(0: »ù±¾²ã£¬1: ÔöÇ¿²ã)
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_ChooseFrame(LONG nPort, LONG nFrameID);

//------------------------------------------------------------------------
// º¯Êý: PLAY_RenderPrivateData
// ÃèÊö: ÏÔÊ¾Ë½ÓÐÊý¾Ý£¬ÀýÈç¹æÔò¿ò£¬¹æÔò¿ò±¨¾¯£¬ÒÆ¶¯Õì²âµÈ
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
//       bTrue TRUE:´ò¿ª FALSE:¹Ø±Õ
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_RenderPrivateData(LONG nPort, BOOL bTrue, LONG nReserve);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SetFileIndexProgressCallBack
// ÃèÊö: ÉèÖÃË÷Òý´´½¨½ø¶È»Øµ÷
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
typedef void (CALLBACK* fIndexProgressCB)(LONG nPort, float fProgress, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetFileIndexProgressCallBack(LONG nPort, fIndexProgressCB IndexProgressCB, void* pUser);

//------------------------------------------------------------------------
// º¯Êý: PLAY_GetLastYUVFrame
// ÃèÊö: Ö÷¶¯»ñÈ¡ÉÏÒ»Ö¡¶ÔÓ¦µÄYUVÊý¾Ý
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_GetLastYUVFrame(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo);

//IOSÌØÊâÒªÇó£ºÄÚ´æ¼õÐ¡°æ±¾
PLAYSDK_API BOOL CALLMETHOD PLAY_SetMemMinimized(LONG nPort);

PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeThreadNum(LONG nPort, DWORD nNum);

//ÉèÖÃ½âÃÜÃÜÔ¿£¬SVAC½âÂëÊ¹ÓÃ
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDecodeKey(LONG nPort, const unsigned char *key, unsigned int key_len);

PLAYSDK_API BOOL CALLMETHOD PLAY_GetIRefValue(LONG nPort, BYTE *pBuffer, DWORD *pSize);

//------------------------------------------------------------------------
// º¯Êý: PLAY_OutsideRender
// ÃèÊö: nacl uiÏß³Ìµ÷ÓÃ´Ë½Ó¿Ú
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ²ÎÊý: nWidth  ´°¿Ú¿í
// ²ÎÊý: nHeight  ´°¿Ú¸ß
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_OutsideRender(LONG nPort, int nWidth, int nHeight);


typedef void (CALLBACK* fDoubleVisibleDecCBFun)(LONG nPort,char * pBuf, int nSize, int nWidth, int nHeight, 
char* pSecondBuf, int nSecondSize, int nSecondWidth, int nSecondHeight, void* pUserData);
PLAYSDK_API BOOL CALLMETHOD PLAY_SetDoubleVisibleDecCallBack(LONG nPort, fDoubleVisibleDecCBFun DataCBFun, void* pUserData);

//------------------------------------------------------------------------
// º¯Êý: PLAY_EnableAudioChannel
// ÃèÊö: ¿ØÖÆ×óÓÒÉùµÀÒôÆµ²¥·Å£¬½ö¶Ô×óÓÒÉùµÀÒôÆµÓÐÐ§¡£
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ²ÎÊý: nChnNum  ×óÓÒÍ¨µÀ£¬0-×óÍ¨µÀ£¬1-ÓÒÍ¨µÀ
// ²ÎÊý: bEnable  Ê¹ÄÜ TRUE-ÆôÓÃ£¬ FALSE-½ûÓÃ
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_EnableAudioChannel(LONG nPort, DWORD nChnNum, BOOL bEnable);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SplitProc
// ÃèÊö: yuv Æ´½ÓËã·¨£¬ÓÃÓÚ4k´óÆÁµÄÏÔÊ¾
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ²ÎÊý: nMode Ä£Ê½£¬0¶ÔÓ¦»ù±¾Ä£Ê½£¬1¶ÔÓ¦1+3Ä£Ê½£¬2¶ÔÓ¦1+5Ä£Ê½
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SplitProc(LONG nPort, int nMode);

//------------------------------------------------------------------------
// º¯Êý: PLAY_SplitProcUpdate
// ÃèÊö: yuv Æ´½ÓËã·¨£¬¸üÐÂÐèÒª·Å´óµÄ¾ØÐÎÎ»ÖÃ
// ²ÎÊý: nPort  ¶Ë¿ÚºÅ
// ²ÎÊý: pAreaRect ¾ØÐÎ×ø±êÊý×éµÄÆðÊ¼µØÖ·
//       Èç¹ûnModeÊÇ0£¬ÔòÓ¦ÎªNULL
//       Èç¹ûnModeÊÇ1£¬Ôò¸ÃÊý×éµÄ´óÐ¡Ó¦Îª3
//       Èç¹ûnModeÊÇ2£¬Ôò¸ÃÊý×éµÄ´óÐ¡Ó¦Îª5              | 
// ·µ»Ø: TRUE ³É¹¦ FALSE Ê§°Ü
//------------------------------------------------------------------------
PLAYSDK_API BOOL CALLMETHOD PLAY_SplitProcUpdate(LONG nPort, DISPLAYRECT* pAreaRect);
    
#ifdef	__cplusplus
}
#endif

#endif
