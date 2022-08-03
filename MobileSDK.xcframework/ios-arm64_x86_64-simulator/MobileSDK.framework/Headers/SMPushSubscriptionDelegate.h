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

@protocol SMPushSubscriptionDelegate <NSObject>

/**
 * This method invoked when the push subscription is invalidated by backend.
 *
 * @param subscriptionID subscription ID of the invalidated push channel
 *
 * @since 4.6.0
 */
- (void) pushSubscriptionInvalidated:(nonnull NSString *)subscriptionID;

@end
