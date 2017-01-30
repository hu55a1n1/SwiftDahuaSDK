//
//  DahuaP2P.swift
//  SwiftDahuaSDK
//
//  Created by Shoaib Ahmed on 1/27/17.
//  Copyright © 2017 Shoaib Ahmed. All rights reserved.
//


public class DahuaP2P {
    
    // Mark: vars
    let client: ProxyClientHandler?
    
    
    required public init(serverIp: String, serverPort: Int, serverSecret: String) {
        client = DHProxyClientInit_(serverIp.unsafeMutablePointerInt8, Int32(serverPort), serverSecret.unsafeMutablePointerInt8)
    }
    
    deinit {
        guard (client != nil) else {
            return
        }
        DHProxyClientRelease_(client!)
    }
    
    
    // Mark: public methods
    public func connect(deviceId: String, devicePort: Int, triesServerChk: Int = 5, triesDeviceChk: Int = 5, triesPortChk: Int = 5,
                 cbClientOnline: (() -> Void)? = nil, cbDeviceOnline: (() -> Void)? = nil) -> (isSuccess: Bool, localPort: Int?) {
        if !isClientOnline(tries: 5) {
            return (false, nil)
        }
        cbClientOnline?()
        
        if !isDeviceOnline(deviceId: deviceId, tries: 5) {
            return (false, nil)
        }
        cbDeviceOnline?()
        
        return addClientPort(deviceId: deviceId, devicePort: devicePort, tries: 5)
    }
    
    public func disconnect(localPort: Int) -> Bool {
        if (DHProxyClientDelPort_(client, Int32(localPort)) != 0) {
            return false
        }
        return true
    }
    
    
    // Mark: private methods
    func isClientOnline(tries: Int, tryInterval: UInt32 = 1) -> Bool
    {
        var state: DHProxyClientProxyState = DHProxyStateUnauthorized
        var isOnline = false
        
        for _ in stride(from: tries, to: 0, by: -1) {
            if (DHProxyClientState_(client, &state) >= 0) {
                if state == DHProxyStateOnline {
                    isOnline = true
                    break
                }
            }
            sleep(tryInterval)
        }
        return isOnline
    }
    
    func isDeviceOnline(deviceId: String, tries: Int, tryInterval: UInt32 = 1) -> Bool
    {
        var state: DHProxyClientProxyState = DHProxyStateUnauthorized
        var isOnline = false
        
        for _ in stride(from: tries, to: 0, by: -1) {
            if (DHProxyClientServerState_(client, deviceId, &state) >= 0) {
                if state == DHProxyStateOnline {
                    isOnline = true
                    break
                }
            }
            sleep(tryInterval)
        }
        return isOnline
    }
    
    func addClientPort(deviceId: String, devicePort: Int, tries: Int, tryInterval1: UInt32 = 1, tryInterval2: UInt32 = 5) -> (isSuccess: Bool, localPort: Int?) {
        var isAcquiredLocalPort = false
        var localPort: Int32 = 0
        var _tries = tries
        
        while !isAcquiredLocalPort && (_tries != 0) {
            _tries -= 1
       
            DHProxyClientAddPort_(client, deviceId.unsafeMutablePointerInt8, Int32(devicePort), &localPort)

            while (_tries != 0) {
                _tries -= 1

                var cstate: DHProxyClientP2PChannelState = DHP2PChannelStateUnauthorized
                if DHProxyClientChannelstate_(client, localPort, &cstate) < 0 {
                    break;
                }
                
                if cstate == DHP2PChannelStateActive {
                    isAcquiredLocalPort = true
                    break;
                }
                
                sleep(tryInterval2)
            }
            
            sleep(tryInterval1)
        }
        
        return (isAcquiredLocalPort, Int(localPort))
    }
    
}


