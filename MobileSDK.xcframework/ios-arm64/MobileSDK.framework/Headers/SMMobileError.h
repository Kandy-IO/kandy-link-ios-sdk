/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.21.0
 *
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMErrorTypes.h"

#define MOBILE_ERROR_DOMAIN @"MobileErrorDomain"
#define SPIDR_ERROR_DOMAIN  @"SPiDRErrorDomain"

/**
 * @brief Defines the cause of an error
 *
 * @since 2.0.0
 **/
@interface SMMobileError : NSError

/**
 * Time(second) value for retrying erroneous action
 *
 * @since 3.0.5
 */
@property(nonatomic) CGFloat retryAfter;

/**
 * Creates an error message with specified description message
 * 
 * @param domain specific error domain of the object
 * @param code specific error code of the error
 * @param descriptionString specify error with this message string
 *
 * @return new MobileError object
 *
 * @since 2.0.0
 */
- (id)initWithDomain:(NSString *)domain code:(SMErrorTypes)code description:(NSString *) descriptionString ;

@end
