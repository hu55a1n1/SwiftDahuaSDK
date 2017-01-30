//
//  DahuaVideoView.swift
//  SwiftDahuaSDKDemo
//
//  Created by Shoaib Ahmed on 1/28/17.
//  Copyright © 2017 Shoaib Ahmed. All rights reserved.
//

import UIKit

open class DahuaVideoView: UIView {

    // DO NOT comment this!!!
    // or only the lower-left corner of frame will be drawed
    override open func draw(_ rect: CGRect) {
        
    }
 
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        prepareView()
    }
    
    required public init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        prepareView()
    }
    
    override open class var layerClass: Swift.AnyClass {
        get {
            return CAEAGLLayer.self
        }
    }
    
    func prepareView() {
//        backgroundColor = UIColor.lightGray
        let eagLayer: CAEAGLLayer = self.layer as! CAEAGLLayer
        eagLayer.isOpaque = true
        eagLayer.drawableProperties = [kEAGLDrawablePropertyRetainedBacking: false, kEAGLDrawablePropertyColorFormat: kEAGLColorFormatRGBA8]
        customizeView()
    }
    
    open func customizeView() {
        // Override to customize from base class
    }
    
}
