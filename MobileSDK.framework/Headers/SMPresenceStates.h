/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.10.0
 *
 */

/**
 * @brief enum class for Presence States
 *
 * - PRESENCE_ONLINE
 * - PRESENCE_OFFLINE
 *
 * @since 2.0.0
 */
typedef NS_ENUM(NSInteger, SMPresenceStates) {
    /** Online */
    PRESENCE_ONLINE NS_SWIFT_NAME(online),
    
    /** Offline */
    PRESENCE_OFFLINE NS_SWIFT_NAME(offline) 
};

