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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Class for getting service names for registration
 * @since 2.0.0
 */
@interface SMServiceTypes : NSObject

/**
 * Retrive name of the call service to registration
 * @return name of the call Service
 * @since 2.0.0
 */
+(NSString *) getCallService;

/**
 * Retrive name of the callMe service to registration
 * @return name of the callMe service
 * @since 2.0.0
 */
+(NSString *) getCallMeService;
@end

NS_ASSUME_NONNULL_END
