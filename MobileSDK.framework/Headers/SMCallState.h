/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.9.0
 *
 */

#import <Foundation/Foundation.h>
#import "SMCallTypes.h"

// Reason codes defined on MobileSDK
#define STATUS_CODE_NOT_PROVIDED 9900
#define ENDED_BY_LOCAL 9901
#define REJECTED_BY_LOCAL 9902
#define IGNORED_BY_LOCAL 9903
#define RESPONDED_FROM_ANOTHER_DEVICE 9904
#define SESSION_COMPLETED 9905
#define ENDED_BY_ERROR 9906
#define ENDED_BY_UNREGISTER 9907

NS_ASSUME_NONNULL_BEGIN

@interface SMCallState : NSObject

/**
 * @brief Enum type of CallState
 * @since 3.0.5
 */
@property (nonatomic, readonly) SMCallStates type;

/**
 * @brief Reason of state transition
 * @since 3.0.5
 */
@property (strong, nonatomic, readonly) NSString *reason;

/**
 * @brief HTTP status code
 * @since 3.0.5
 */
@property (nonatomic, readonly) NSInteger statusCode;

/**
 * Creates an CallState oject with specified type
 *
 * @param type of CallState
 * @return SMCallState object
 * @since 3.0.5
 */
- (id) initWithType:(SMCallStates) type;

/**
 * Creates an CallState oject with specified type and reson
 *
 * @param type of CallState
 * @param reason of CallState transition
 * @return SMCallState object
 * @since 3.0.5
 */
- (id) initWithType:(SMCallStates) type andReason:(NSString *) reason;

/**
 * Creates an CallState oject with specified type and reson and http code
 *
 * @param type of CallState
 * @param reason of CallState transition
 * @param statusCode HTTP code comes from SPiDR for state transition
 * @return SMCallState object
 * @since 3.0.5
 */
- (id) initWithType:(SMCallStates) type andReason:(NSString *) reason andStatusCode: (NSInteger) statusCode;

@end

NS_ASSUME_NONNULL_END
