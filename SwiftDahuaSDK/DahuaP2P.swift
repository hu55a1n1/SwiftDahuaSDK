//
//  DahuaP2P.swift
//  SwiftDahuaSDK
//
//  Created by Shoaib Ahmed on 1/27/17.
//  Copyright © 2017 Shoaib Ahmed. All rights reserved.
//

//import Foundation

public class DahuaP2P {
    
    // Mark: vars
    let client: ProxyClientHandler?
    
    
    required public init(serverIp: String, serverPort: Int, serverSecret: String) {
        client = DHProxyClientInit_(serverIp.unsafeMutablePointerInt8, Int32(serverPort), serverSecret.unsafeMutablePointerInt8)
    }
    
//    convenience public init(serverIp: String, serverPort: Int, serverSecret: String, deviceId: String, devicePort: Int, tryCount: Int) {
//        self.init(serverIp: serverIp, serverPort: serverPort, serverSecret: serverSecret)
//        
//    }
    
    deinit {
        guard (client != nil) else {
            return
        }
        DHProxyClientRelease_(client!)
    }
    
    
    // Mark: public methods
    public func connect(deviceId: String, devicePort: Int, triesServerChk: Int = 5, triesDeviceChk: Int = 5, triesPortChk: Int = 5,
                 cbClientOnline: (() -> Void)? = nil, cbDeviceOnline: (() -> Void)? = nil) -> (isSuccess: Bool, local_port: Int?) {
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
    
    public func disconnect(local_port: Int) -> Bool {
        if (DHProxyClientDelPort_(client, Int32(local_port)) != 0) {
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
    
    func addClientPort(deviceId: String, devicePort: Int, tries: Int, tryInterval1: UInt32 = 1, tryInterval2: UInt32 = 5) -> (isSuccess: Bool, local_port: Int?) {
        var isAcquiredLocalPort = false
        var local_port: Int32 = 0
        var _tries = tries
        
        while !isAcquiredLocalPort && (_tries != 0) {
            _tries -= 1
       
            DHProxyClientAddPort_(client, deviceId.unsafeMutablePointerInt8, Int32(devicePort), &local_port)

            while (_tries != 0) {
                _tries -= 1

                var cstate: DHProxyClientP2PChannelState = DHP2PChannelStateUnauthorized
                if DHProxyClientChannelstate_(client, local_port, &cstate) < 0 {
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
        
        return (isAcquiredLocalPort, Int(local_port))
    }
    
}


