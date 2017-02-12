//
//  DahuaClient.swift
//  Swift-DahuaSDK-demo
//
//  Created by Shoaib Ahmed on 1/26/17.
//  Copyright © 2017 Kindows Tech Solutions. All rights reserved.
//


public class DahuaClient {
    
    // Mark: vars
    public var loginId: Int?
    
    
    // Mark: Enums
    public enum SpecCap: Int {
        case local = 0
        case p2p = 19
    }
    
    
    required public init?() {
        if(!CLIENT_Init_(nil, 0)) {
            return nil
        }
    }
    
    deinit {
        CLIENT_Cleanup_()
    }
    
    
    // Mark: public methods
    
    // Don't access `deviceInfo` on failure
    public func login(specCap: SpecCap, ip: String, port: Int, username: String, password: String) -> (isSuccess: Bool, deviceInfo: NET_DEVICEINFO?, error: Int) {
        var nError: Int32 = 0
        var devInfo = NET_DEVICEINFO()

        loginId = CLIENT_LoginEx_(ip.unsafeMutablePointerInt8, UInt16(port), username.unsafeMutablePointerInt8, password.unsafeMutablePointerInt8, Int32(specCap.rawValue), nil, &devInfo, &nError)
        if (loginId == 0) {
            return (false, nil, Int(nError))
        }
        
        return (true, devInfo, Int(nError))
    }
    
    // Returns true even if not logged in
    public func logout() -> Bool {
        guard (loginId != nil) else {
            return true
        }
        return CLIENT_Logout_(loginId!)
    }
    
    public func getChannelConfig(for channel: Int, waittime: Int = 1000) -> DHDEV_CHANNEL_CFG? {
        var chInfo = DHDEV_CHANNEL_CFG()
        var bytesReturned: UInt32 = 0
        
        guard CLIENT_GetDevConfig_(loginId!,
                                   UInt32(DH_DEV_CHANNELCFG),
                                   Int32(channel),
                                   withUnsafeMutablePointer(to: &chInfo) {UnsafeMutableRawPointer($0)},
                                   UInt32(MemoryLayout<DHDEV_CHANNEL_CFG>.size),
                                   &bytesReturned, Int32(waittime))
            else {
                return nil
        }
        
        return chInfo
    }
    
}


extension DHDEV_CHANNEL_CFG {
    
    public var channelName: String {
        return stringFrom(int8sz32: szChannelName)
    }
    
    fileprivate func stringFrom(int8sz32 tuple: (Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8, Int8)) -> String {
        let arr: [unichar] = [unichar(tuple.0), unichar(tuple.1),
                              unichar(tuple.2), unichar(tuple.3),
                              unichar(tuple.4), unichar(tuple.5),
                              unichar(tuple.6), unichar(tuple.7),
                              unichar(tuple.8), unichar(tuple.9),
                              unichar(tuple.10), unichar(tuple.11),
                              unichar(tuple.12), unichar(tuple.13),
                              unichar(tuple.14), unichar(tuple.15),
                              unichar(tuple.16), unichar(tuple.17),
                              unichar(tuple.18), unichar(tuple.19),
                              unichar(tuple.20), unichar(tuple.21),
                              unichar(tuple.22), unichar(tuple.23),
                              unichar(tuple.24), unichar(tuple.25),
                              unichar(tuple.26), unichar(tuple.27),
                              unichar(tuple.28), unichar(tuple.29),
                              unichar(tuple.30), unichar(tuple.31)]
        
        let len = arr.reduce(0) { $1 != 0 ? $0 + 1 : $0 }
        return NSString(characters: arr, length: len) as String
    }
    
}

