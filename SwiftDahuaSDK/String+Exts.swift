//
//  String+Exts.swift
//  ACC
//
//  Created by Shoaib Ahmed on 5/16/16.
//  Copyright © 2016 Kindows Tech Solutions. All rights reserved.
//

import Foundation

extension String {

    var unsafeMutablePointerInt8: UnsafeMutablePointer<Int8> {
        let cs = (self as NSString).utf8String
        return UnsafeMutablePointer<Int8>(mutating: cs!)
    }

}
