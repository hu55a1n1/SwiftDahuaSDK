//
//  DahuaRealplay.swift
//  SwiftDahuaSDK
//
//  Created by Shoaib Ahmed on 1/28/17.
//  Copyright © 2017 Shoaib Ahmed. All rights reserved.
//


public class DahuaRealplay {
    
    var port: Int32
    let handle: Int
    public var isPlaying: Bool = false
    
    public init?(client: DahuaClient?, channel: Int, type: DH_RealPlayType = DH_RType_Realplay) {
        guard (client != nil) && (client!.loginId != nil) else {
            return nil
        }
        
        handle = CLIENT_RealPlayEx_(client!.loginId!, Int32(channel), nil, type)
        guard (handle != 0) else {
            return nil
        }
        
        var _port: Int32 = 0
        guard PLAY_GetFreePort_(&_port) else {
            CLIENT_StopRealPlay_(handle)
            return nil
        }
        
        port = _port
    }
    
    deinit {
        if isPlaying {
            stop()
        }
        PLAY_ReleasePort_(port)
        CLIENT_StopRealPlay_(handle)
    }
    
    public func play(window: DahuaVideoView) -> Bool {
        guard PLAY_OpenStream_(port, nil, 0, 300*1024) else {
            return false
        }
        
        guard PLAY_Play_(port, UnsafeMutableRawPointer(Unmanaged.passUnretained(window).toOpaque())) else {
            PLAY_CloseStream_(port)
            return false
        }

        guard PLAY_PlaySoundShare_(port) else {
            PLAY_CloseStream_(port)
            PLAY_Stop_(port)
            return false
        }
        
        CLIENT_SetRealDataCallBack_(handle, { (lRealHandle, dwDataType, pBuffer, dwBufSize, port) -> Void in
            PLAY_InputData_(Int32(port), pBuffer, dwBufSize)
            return
        }, Int(port))
        
        isPlaying = true
        return true
    }
    
    public func stop() -> Void {
        PLAY_StopSoundShare_(port)
        PLAY_Stop_(port)
        PLAY_CloseStream_(port)
        
        isPlaying = false
        return
    }
    
}
