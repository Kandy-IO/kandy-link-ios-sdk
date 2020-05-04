/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.6.0
 *
 */

/**
 * @brief enum class for Presence Notes
 *
 * - PRESENCE_AWAY
 * - PRESENCE_UNKNOWN
 * - PRESENCE_OUT_TO_LUNCH
 * - PRESENCE_BUSY
 * - PRESENCE_ON_VACATION
 * - PRESENCE_ON_THE_PHONE
 *
 * @since 2.0.0
 */
typedef NS_ENUM(NSInteger, SMPresenceActivityType) {
    /** Away */
    PRESENCE_AWAY NS_SWIFT_NAME(away),
    
    //PRESENCE_IDLE,
    
    //PRESENCE_OTHER,
    
    /** Unknown */
    PRESENCE_UNKNOWN NS_SWIFT_NAME(unknown),
    
    /** Out to lunch */
    PRESENCE_OUT_TO_LUNCH NS_SWIFT_NAME(outToLunch),
    
    /** Busy */
    PRESENCE_BUSY NS_SWIFT_NAME(busy),
    
    /** On vacation*/
    PRESENCE_ON_VACATION NS_SWIFT_NAME(onVacation),
    
    //PRESENCE_BE_RIGHT_BACK,
    
    /** On the phone */
    PRESENCE_ON_THE_PHONE NS_SWIFT_NAME(onPhone),
    
    //PRESENCE_ACTIVE,
    
    //PRESENCE_INACTIVE
};

