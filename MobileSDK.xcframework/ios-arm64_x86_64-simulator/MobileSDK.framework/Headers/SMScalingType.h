/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.1.0
 *
 */

/**
 * Enum class for local and remote video view scaling type
 *
 * @since 2.15.0
 */
typedef NS_ENUM(NSInteger, SMScalingType) {
    
    /// Scaling type is Aspect Ratio Fit
    SCALINGTYPE_ASPECT_RATIO_FIT NS_SWIFT_NAME(aspectRatioFit)                     = 1,
    
    /// Scaling type is Aspect Ratio Fit
    SCALINGTYPE_ASPECT_RATIO_FILL NS_SWIFT_NAME(aspectRatioFill)                   = 2
};

