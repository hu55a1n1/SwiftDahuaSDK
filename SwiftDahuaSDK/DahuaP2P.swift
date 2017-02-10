//
//  DahuaP2P.swift
//  SwiftDahuaSDK
//
//  Created by Shoaib Ahmed on 1/27/17.
//  Copyright © 2017 Shoaib Ahmed. All rights reserved.
//


public protocol DahuaP2PDelegate {
    
    func clientFoundOnline() -> Void
    func deviceFoundOnline() -> Void
    
}

public class DahuaP2P {
    
    // Mark: vars
    let client: ProxyClientHandler?
    public var delegate: DahuaP2PDelegate?
    
    
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
    public func connect(deviceId: String, devicePort: Int, triesServerChk: Int = 500, triesDeviceChk: Int = 500, triesPortChk: Int = 500, every usecInterval: UInt32 = 100000) -> (isSuccess: Bool, localPort: Int?) {
        if !isClientOnline(tries: triesServerChk, every: usecInterval) {
            return (false, nil)
        }
        delegate?.clientFoundOnline()
        
        if !isDeviceOnline(deviceId: deviceId, tries: triesDeviceChk, every: usecInterval) {
            return (false, nil)
        }
        delegate?.deviceFoundOnline()
        
        return addClientPort(deviceId: deviceId, devicePort: devicePort, tries: triesPortChk, every: usecInterval)
    }
    
    public func disconnect(localPort: Int) -> Bool {
        if (DHProxyClientDelPort_(client, Int32(localPort)) != 0) {
            return false
        }
        return true
    }
    
    
    // Mark: private methods
    func isClientOnline(tries: Int, every usecInterval: UInt32 = 100000) -> Bool
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
            usleep(usecInterval)
        }
        return isOnline
    }
    
    func isDeviceOnline(deviceId: String, tries: Int, every usecInterval: UInt32 = 100000) -> Bool
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
            usleep(usecInterval)
        }
        return isOnline
    }
    
    func addClientPort(deviceId: String, devicePort: Int, tries: Int, every usecInterval: UInt32 = 100000) -> (isSuccess: Bool, localPort: Int?) {
        var isAcquiredLocalPort = false
        var localPort: Int32 = 0
        var _tries = tries
        
        while !isAcquiredLocalPort && (_tries != 0) {
            _tries -= 1
       
            DHProxyClientAddPort_(client, deviceId.unsafeMutablePointerInt8, Int32(devicePort), &localPort)
            usleep(usecInterval)
            
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
                
                usleep(usecInterval)
            }
        }
        
        return (isAcquiredLocalPort, Int(localPort))
    }
    
}


