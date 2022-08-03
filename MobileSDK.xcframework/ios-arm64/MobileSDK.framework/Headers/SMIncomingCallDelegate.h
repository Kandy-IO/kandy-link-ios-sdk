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
#import "SMCallDelegate.h"

/**
 * @brief Call object, which is used for incoming calls.
 * @since 2.0.0
 */
@protocol SMIncomingCallDelegate <SMCallDelegate>

/**
 * @brief Gets custom SIP headers which comes from incoming call notification.
 * @return NSDictionary which contains custom SIP headers if exist
 * @since 4.4.5
 * @updated 5.0.0
 */
- (NSDictionary *)getCustomSIPHeaders;

/**
 * @brief Indicates if the call can be rejected or not
 * @return YES if the call can be rejected otherwise returns NO
 * @since 2.0.0
 */
- (BOOL) canReject;

/**
 * @brief Accepts the incoming call
 * @param isVideoEnabled indicates if video is allowed or not
 * @since 2.0.0
 */
- (void) acceptCall: (BOOL)isVideoEnabled;

/**
 * @brief Accepts the incoming call and sends the given custom SIP headers to SPiDR server.
 * @param isVideoEnabled indicates if video is allowed or not
 * @param customParameters key-value pairs of custom SIP headers to send
 * @since 4.5.0
 */
- (void) acceptCall: (BOOL)isVideoEnabled withCustomParameters:(NSDictionary *) customParameters;

/**
 * @brief Ignores the incoming call
 * @since 2.0.0
 */
- (void) ignoreCall;

/**
 * @brief Rejects the incoming call
 * @since 2.0.0
 */
- (void) rejectCall;

/**
 * @brief Forwards incoming call
 * @since 2.0.0
 */
- (void) forwardCall:(SMUriAddress*)address;

/**
 * @brief Sets Id value of Incoming call
 *
 * @param Id Indicates custom identifier  which is not related with Spidr Session Id
 *
 * @since 4.2.1.1
 */
- (void) setId:(NSString *)Id;

/**
 * @brief Sends the ringing feedback to SPiDR. Needs to be called if Ringing feedback enabled.
 * @since 4.3.2
 */
- (void) sendRingingFeedback;



@end
