//
//  DahuaClient.swift
//  Swift-DahuaSDK-demo
//
//  Created by Shoaib Ahmed on 1/26/17.
//  Copyright © 2017 Kindows Tech Solutions. All rights reserved.
//

//import Foundation

class DahuaClient {
    
    var login_id: Int32?
    
    required init?() {
        if(!CLIENT_Init_(nil, 0)) {
            return nil
        }
    }
    
    deinit {
        CLIENT_Cleanup_()
    }
    
}
