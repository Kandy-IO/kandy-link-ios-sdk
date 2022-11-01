/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.8.0
 *
 */

/**
 * @brief Codec types for the supported codecs of WebRTC
 * - VIDEO_CODEC
 * @since 5.17.0
 */
typedef NS_ENUM(NSInteger, SMCodecType) {
    
    /** Video type that represents video codecs */
    VIDEO_CODEC NS_SWIFT_NAME(videoCodec),
    
    /// Audio type that represents audio codecs
    //AUDIO NS_SWIFT_NAME(audio)
    
    /// All type that represents both codecs video and audio
    //ALL NS_SWIFT_NAME(all)
};
