/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.24.0
 *
 */

/**
 * @brief enum class that specifies processing policy for slow-start events
 *
 * - AudioOnly
 * - AudioVideo
 *
 * @since 4.5.4
 */
typedef NS_ENUM(NSInteger, SMSlowStartCallPolicy) {
    /**
     * @brief  Processes slow-start events by supporting only audio.
     */
    AudioOnly NS_SWIFT_NAME(audioOnly),
    
    /**
     * @brief  Processes slow-start events by supporting audio and video.
     */
    AudioVideo NS_SWIFT_NAME(audioVideo)
};
