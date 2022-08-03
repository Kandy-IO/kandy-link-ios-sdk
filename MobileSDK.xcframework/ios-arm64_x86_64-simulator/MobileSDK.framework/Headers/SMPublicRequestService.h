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
 * @brief The variable type that will be used to REST query
 *
 * - POST
 * - GET
 * - PUT
 * - DELETE
 *
 * @since 5.24.0
 **/
typedef NS_ENUM(NSInteger, SMRestPublicMethodTypes) {
    
    POST NS_SWIFT_NAME(post),
    
    GET NS_SWIFT_NAME(get),
    
    PUT NS_SWIFT_NAME(put),
    
    DELETE NS_SWIFT_NAME(delete)
    
};

/**
 * @brief This class defines event types of PublicRequestService
 * @since 5.24.0
 */
@interface SMPublicRequestService : NSObject

/**
 * Static singleton instance method
 * @return \link RestManager \endlink
 */
+(id) getInstance;

/**
 * Sent REST request to server
 * Create a request with
 * @param resourceURL  endpoint of REST Request. This endpoint will generate a suitable suffix then add into REST request. Cannot be nullable.
 * @param methodType methodType which will use to send REST request. SMRestPublicMethodTypes supports POST, GET, PUT and DELETE method types for REST request. Cannot be nullable.
 * @param requestInfo request body in the REST request. RequestInfo can be required for any method type.
 * @param completion Request completion block will return response body and error if any.
 */
- (void)fetch:(NSString * _Nonnull)resourceURL withMethodType:(SMRestPublicMethodTypes )methodType withRequestInfo:( NSDictionary * _Nullable)requestInfo  completionHandler:(void (^_Nonnull)(NSDictionary * _Nullable fetchResponse, SMMobileError * _Nullable error))completionBlock;

NS_ASSUME_NONNULL_END

@end
