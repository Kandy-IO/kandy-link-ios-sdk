/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.5.0
 *
 */

/**
 * @brief Utility class for LogType.
 *
 * @since 2.0.0
 **/

/**
 * Enum values for LogLevel
 *
 * ERROR --> events that will presumably lead the application to abort
 * WARNING --> potentially harmful situations
 * INFO --> informational messages that highlight the progress of the application at coarse-grained level
 * TRACE --> finer-grained informational events
 * TRACE_WEBRTC --> enables webrtc sensitive logging
 *
 * @since 2.0.0
 **/
typedef NS_ENUM(NSInteger, SMLogLevel) {
    
    /** Events that will presumably lead the application to abort */
    ERROR NS_SWIFT_NAME(error),
    
    /** Potentially harmful situations */
    WARNING NS_SWIFT_NAME(warning),
    
    /** Informational messages that highlight the progress of the application at coarse-grained level */
    INFO NS_SWIFT_NAME(info),
    
    /** Finer-grained informational events */
    TRACE NS_SWIFT_NAME(trace),
    
    /** Enables webrtc sensitive logging */
    TRACE_WEBRTC NS_SWIFT_NAME(traceWebRTC)
};
