/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.17.0
 *
 */

#import <Foundation/Foundation.h>

/**
 * @brief Calllog service delegate
 * @since 2.0.0
 */
@protocol SMCallLogServiceDelegate <NSObject>

/**
 * This method removes the call log.
 * @param calllogId NString
 * @since 2.0.0
 */
- (void) remove:(NSString *)calllogId;

/**
 * Remove all call logs
 * @since 2.0.0
 */
- (void) removeAll;

/**
 * This method returns call logs with beginning the given startIndex to the count size .
 * @param startIndex int
 * @param count int
 * @return CallLogEntry NSMutableArray
 * @since 2.0.0
 */
- (NSMutableArray *) retrieve:(int)startIndex andCount:(int)count;

/**
 * This method returns all call logs
 * @return NSMutableArray CallLogEntry
 * @since 2.0.0
 */
- (NSMutableArray *) retrieveAll;
@end
