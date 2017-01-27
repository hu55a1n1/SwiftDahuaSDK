/*************************************************************************
 ** 版权保留(C), 2001-2013, 浙江大华技术股份有限公司.
 ** 版权所有.
 **
 ** $Id$
 **
 ** 功能描述   : Proxy Client C适配层
 **
 ** 修改历史     : 2013年12月23日 zhu_long Modification
*************************************************************************/

#ifndef _DAHUA_P2P_DEFS_H_
#define _DAHUA_P2P_DEFS_H_

//#ifndef __INCLUDE_DAHUA_TOU_DEFS_H__
//#define __INCLUDE_DAHUA_TOU_DEFS_H__

// WIN32 Dynamic Link Library
#ifdef _MSC_VER

#ifdef TOU_DLL_BUILD
#define  TOU_API _declspec(dllexport)
#elif defined TOU_DLL_USE
#define  TOU_API _declspec(dllimport)
#else
#define TOU_API
#endif

#else //_MSC_VER

#define TOU_API

#endif //_MSC_VER



#ifdef  __cplusplus

namespace Dahua{
    namespace Tou{
        
#ifndef DISALLOW_ASSIGN
#define DISALLOW_ASSIGN(TypeName) \
void operator=(const TypeName&)
#endif
        
// A macro to disallow the evil copy constructor and operator= functions
// This should be used in the private: declarations for a class
#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName)    \
TypeName(const TypeName&);                    \
DISALLOW_ASSIGN(TypeName)
#endif
        
// Alternative, less-accurate legacy name.
#ifndef DISALLOW_EVIL_CONSTRUCTORS
#define DISALLOW_EVIL_CONSTRUCTORS(TypeName) \
DISALLOW_COPY_AND_ASSIGN(TypeName)
#endif
        
// A macro to disallow all the implicit constructors, namely the
// default constructor, copy constructor and operator= functions.
//
// This should be used in the private: declarations for a class
// that wants to prevent anyone from instantiating it. This is
// especially useful for classes containing only static methods.
#ifndef DISALLOW_IMPLICIT_CONSTRUCTORS
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
TypeName();                                    \
DISALLOW_EVIL_CONSTRUCTORS(TypeName)
#endif
        
    }//Tou
}//Dahua

#endif //__cplusplus

//#endif  //__INCLUDE_DAHUA_TOU_DEFS_H__


#ifdef WIN32
typedef unsigned __int64 UINT64;
#else
typedef unsigned long long UINT64;
#endif

#ifdef  __cplusplus
extern "C" {
#endif

///\brief 代理状态
typedef enum
{
    DHProxyStateUnauthorized,           ///< 服务认证失败（序列号非法、密钥错误）
    DHProxyStateForbidden,              ///< 服务禁止登陆（设备ID重复、服务器拒绝）
    DHProxyStateOffline,                ///< 服务离线
    DHProxyStateOnline,                 ///< 服务在线
} DHProxyClientProxyState;

///\brief P2P通道状态
typedef enum
{
    DHP2PChannelStateInit,              ///< P2P通道初始化中
    DHP2PChannelStateActive,            ///< P2P通道已连通
    DHP2PChannelStateNonExist,          ///< P2P通道不存在
	DHP2PChannelStateUnauthorized,      ///< P2P通道鉴权失败
} DHProxyClientP2PChannelState;

///\brief 映射端口速率统计
typedef struct
{
    UINT64               recvBytes;     ///< 总接收字节KB
    UINT64               sendBytes;     ///< 总发送字节KB

    double               curRecvRate;   ///< 当前接收速率Kb/s
    double               curSendRate;   ///< 当前发送速率Kb/s

    double               lostRate;      ///< 丢包率
    double               liveTime;      ///< 通道活动时间(秒S)
} DHProxyClientMapPortRate;

///\brief 远程代理信息
typedef struct
{
    char                remoteId[64];      ///< 服务器ID
    char                remoteIp[64];      ///< 远程代理IP
    int                 remotePort;        ///< 远程代理端口
} DHProxyClientRemotePortInfo;

typedef enum
{
    DHP2POptionPortGuess,                 ///< 端口猜测选项 参数值: 0 关闭 1 开启
    DHP2POptionSetMTU,                    ///< MTU选项	  参数值: 整数值
    DHP2POptionUPNP,                      ///< UPNP选项	  参数值: 0 关闭 1 开启
    DHP2POptionRelay,                     ///< Relay选项  参数值: 0 不支持中转 1 支持中转
}DHProxyOption;

///\brief 句柄
typedef void*	ProxyClientHandler;

#ifdef  __cplusplus
}
#endif

#endif /* _DAHUA_P2P_DEFS_H_ */
