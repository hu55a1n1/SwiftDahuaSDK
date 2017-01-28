//
//  DahuaClient.swift
//  Swift-DahuaSDK-demo
//
//  Created by Shoaib Ahmed on 1/26/17.
//  Copyright © 2017 Kindows Tech Solutions. All rights reserved.
//

//import Foundation

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
    
}


