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

/**
 * @brief SMCallReceiveBandwidthLimit class can be used for setting
 * limitation to receive bandwidth.
 *
 * @since 4.6.1
 */
@interface SMCallReceiveBandwidthLimit : NSObject

/**
 * audioReceiveBandwidth
 */
@property (nonatomic, strong) NSNumber * audioReceiveBandwidth;

/**
 * videoReceiveBandwidth
 */
@property (nonatomic, strong) NSNumber * videoReceiveBandwidth;

/**
 * Constructor method for SMCallReceiveBandwidthLimit.
 *
 * @param audioReceiveBandwidthLimit preferred audio bandwidth limit
 * @param videoReceiveBandwidthLimit preferred video bandwidth limit
 *
 * @return SMCallReceiveBandwidthLimit instance
 *
 * @since 4.6.1
 */
- (id) initWithAudioReceiveBandwidthLimit:(NSNumber *) audioReceiveBandwidthLimit withVideoReceiveBandwidthLimit:(NSNumber *) videoReceiveBandwidthLimit;

@end
