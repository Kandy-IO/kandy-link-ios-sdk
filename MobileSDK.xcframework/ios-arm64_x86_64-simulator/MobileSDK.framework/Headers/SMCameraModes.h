/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.22.0
 *
 */

/**
 * @brief enum class for Camera Modes
 *
 * - CAMERA_ORIENTATION_USES_NONE,
 * - CAMERA_ORIENTATION_USES_DEVICE,
 * - CAMERA_ORIENTATION_USES_STATUS_BAR
 *
 * @since 2.0.0
 */

#ifndef MobileSDK_CameraModes_h
#define MobileSDK_CameraModes_h

typedef NS_ENUM(NSInteger, SMCameraOrientationMode) {
    
    /** CAMERA ORIENTATION USES NONE */
    CAMERA_ORIENTATION_USES_NONE NS_SWIFT_NAME(none),
    
    /** CAMERA ORIENTATION USES DEVICE */
    CAMERA_ORIENTATION_USES_DEVICE NS_SWIFT_NAME(device),
    
    /** CAMERA ORIENTATION USES STATUS BAR */
    CAMERA_ORIENTATION_USES_STATUS_BAR NS_SWIFT_NAME(statusBar)
};

#endif
