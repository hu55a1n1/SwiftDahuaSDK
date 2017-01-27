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

#ifndef _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_
#define _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_

#include "../dahua-p2p-defs.h"

#ifdef  __cplusplus
extern "C" {
#endif    
    
///\breif 初始化
///\param[in]       svraddr  服务器IP(暂不支持域名)
///\param[in]       svrport  服务器端口
///\param[in]       passwd   密钥
///\return 0失败/其他，client句柄
TOU_API ProxyClientHandler DHProxyClientInit(const char* svrip, int svrport, const char* passwd);

///\breif 释放资源
///\param[in]       handler  实际client句柄
TOU_API void DHProxyClientRelease(ProxyClientHandler handler);

///\brief 通过远程代理打开映射
///\param[in]       handler  实际client句柄
///\param[in]       deviceId    远程代理ID
///\param[in]       targetPort  目标端口
///\param[in,out]   localPort   本地映射端口,为0由内部随机分配一个端口
///\return 0成功/-1失败
TOU_API int DHProxyClientAddPort(ProxyClientHandler handler,
		const char* deviceId, int targetPort, int *localPort);

///\brief 删除一个映射
///\param[in]   handler  实际client句柄
///\param[in]   port 本地映射端口
///\return 0成功/-1失败
TOU_API int DHProxyClientDelPort(ProxyClientHandler handler, int port);

///\brief 查询映射端口速率
///\param[in]   handler  实际client句柄
///\param[in]   port 本地映射端口
///\param[out]  rate 当前映射速率
///\return 0成功/-1失败
TOU_API int DHProxyClientQueryRate(ProxyClientHandler handler,
		int port, DHProxyClientMapPortRate *rate);

///\brief 查询映射端口的P2P通道状态
///\param[in]   handler  实际client句柄
///\param[in]   port 本地映射端口
///\param[out]  state 当前映射端口状态， @see DHProxyClientP2PChannelState
///\return 0成功/-1失败
TOU_API int DHProxyClientChannelstate(ProxyClientHandler handler, int port, int *state);

///\brief 获取当前代理客户端状态
///\param[in]   handler  实际client句柄
///\param[out] 	state  当前代理客户端状态, @see DHProxyClientProxyState
///\return 0成功/-1失败
TOU_API int DHProxyClientState(ProxyClientHandler handler, int *state);

///\brief 查询远程代理服务器的状态
///\param[in]   handler  实际client句柄
///\param[in]   deviceId 远程代理ID
///\param[out] 	state 当前代理服务器状态, @see DHProxyClientProxyState
///\return 0成功/-1失败
TOU_API int DHProxyClientServerState(ProxyClientHandler handler, const char* deviceId, int *state);

///\brief 查询远程代理服务器的信息
///\param[in]   handler  实际client句柄
///\param[in]   port  本地隐射端口
///\param[out]  info  远程代理服务器信息, @see DHProxyClientRemotePortInfo
///\return 0成功/-1失败
TOU_API int DHProxyClientQueryRemoetInfo(ProxyClientHandler handler, int port, DHProxyClientRemotePortInfo *info);

///\breif 初始化
///\param[in]       svraddr  服务器IP(暂不支持域名)
///\param[in]       svrport  服务器端口
///\param[in]       passwd   密钥
///\param[in]       username   用户名
///\return 0失败/其他，client句柄
TOU_API ProxyClientHandler DHProxyClientInitWtihName(const char* svrip, int svrport, const char* passwd, const char* username);

///\brief 设置Proxy选项
///\param[in]   handler  实际client句柄
///\param[in] option ProxyOption枚举
///\param[in] value 设置参数值
///\return 0 成功; -1 失败
///\note value设置 @see ProxyOption
TOU_API	int DHProxySetOption(ProxyClientHandler handler, DHProxyOption option, int value);

///\brief 获取对应option的值
///\param[in] handler  实际client句柄
///\param[in] option ProxyOption枚举
///\return 返回设置的参数值: -1 失败; >=0 option的值 
TOU_API int DHProxyGetOption(ProxyClientHandler handler, DHProxyOption option);

#ifdef  __cplusplus
}
#endif

#endif /* _DAHUA_P2P_PROXY_CLIENT_CWRAP_H_ */
