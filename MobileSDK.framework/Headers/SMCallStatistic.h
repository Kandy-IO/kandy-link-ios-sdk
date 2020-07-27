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

@interface SMCallStatistic : NSObject

@property(nonatomic, readonly) NSString* reportId;
@property(nonatomic, readonly) NSString* type;
@property(nonatomic, readonly) CFTimeInterval timestamp;
@property(nonatomic, readonly) NSArray* values; //NSArray of SMValue

@end

@interface SMValue : NSObject

@property(nonatomic, strong, readonly) NSString *key;
@property(nonatomic, strong, readonly) NSString *value;

@end
