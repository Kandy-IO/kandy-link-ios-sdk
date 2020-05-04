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

#import <Foundation/Foundation.h>

@protocol SMCallDelegate;

/**
 * Call object, which is used for outgoing calls.
 *
 * @since 2.0.0
 */
@protocol SMOutgoingCallDelegate <SMCallDelegate>

/**
 * Starts call establishment on created outgoing call
 * 
 * @param isVideoEnabled indicates video is enabled or not in the call
 * @since 2.0.0
 */
- (void) establishCall :(BOOL) isVideoEnabled;

/**
 * Establishes an outgoing call with single audio m-line. The related call backs are done through the
 * application listener interface instance defined in the call service.
 *
 * @since 3.0.5
 */
- (void) establishAudioCall;

/**
 * Establishes an outgoing call with custom parameters dictionary
 *
 * @param videoEnabled indicates local video sending is enabled or not
 * @param customParameters indicates custom call properties like emergency etc.
 *
 * @since 4.3.1
 */
- (void) establishCall:(BOOL)isVideoEnabled withCustomParameters:(NSDictionary *)customParameters;

/**
 * Establishes an audio only outgoing call with custom parameters dictionary
 *
 * @param customParameters indicates custom call properties like emergency etc.
 *
 * @since 4.3.1
 */
- (void) establishAudioCallWithCustomParameters:(NSDictionary *)customParameters;
@end
