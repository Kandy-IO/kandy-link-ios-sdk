/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.16.0
 *
 */

#import <Foundation/Foundation.h>


@protocol SMPushSubscriptionDelegate;
@class SMMobileError;
@class SMNotificationMessage;
@class PKPushCredentials;


/**
* Contains informations about  incoming call by parsing the VOIP push notification.
* The datas in this class will be used to inform CallKit after receiving each voip notification
* - Since: 5.5.0
*/
@interface SMCKInfo: NSObject
 
/*
* Caller Display Information is for showing the caller info on CallKit Screen.
* In case of error this parameter will be nil
* - Returns: String
* - Since: 5.5.0
*/
@property (nonatomic) NSString* _Nullable callerDisplayInfo;

/*
* Unique Identifier for the incoming call. You should set this value to CallKit's UUID parameter while reporting.
* In case of error, this parameter will be nil
* - Returns: UUID
* - Since: 5.5.0
*/
@property (nonatomic) NSUUID * _Nullable callUUID;

/*
* In case of an error while parsing push notification.This parameter will be filled
* If there are no errors this parameter will be nil
* - Returns: SMMobileError
* - Since: 5.5.0
*/
@property (nonatomic) SMMobileError * _Nullable error;

@end



/**
 * Push Service enables push message and event injection to MobileSDK from Application layer
 *
 * @since 3.0.5
 * @updated 5.5.0
 **/
@interface SMPushService : NSObject

/**
 * @brief The delegate object that must be implemented to receive the callbacks.
 * @see SMPushSubscriptionDelegate
 *
 * @since 4.6.0
 */
@property(nonatomic, strong, nullable) id<SMPushSubscriptionDelegate> pushSubscriptionDelegate;

/**
 * This method registers application to push notifications channel.
 * Fail and success calls will be transmitted through the completion block.
 * If the registration is successful, a subscriptionID will be returned which can be used to update or remove the push subscription.
 *
 * @param standardPushToken standard push token generated by the apns
 * @param voipPushToken voip push token generated by the apns
 * @param realm realm of the push server
 * @param completionBlock block implementation that will be used to return success or fail
 *
 * @updated 5.4.0
 */
- (void) subscribeToPushNotificationsWithStandardPushToken:(nonnull NSData *)standardPushToken
                                          andVoipPushToken:(nonnull NSData *)voipPushToken
                                                andRealm:(nonnull NSString *)realm
                                       completionHandler:(void (^_Nonnull)(NSString * _Nullable subscriptionID, SMMobileError * _Nullable error))completionBlock;

/**
 * This method updates the push subscription with a new device tokens.
 *
 * @param standardPushToken standard push token generated by the apns
 * @param voipPushToken voip push token generated by the apns
 * @param subscriptionID unique ID assigned to the subscribed device by SPiDR/KL after the push subscription
 * @param completionBlock block implementation that will be used to return success or fail
 *
 * @updated 5.4.0
 */
- (void) updatePushSubscriptionWithStandardPushToken:(nonnull NSData *)standardPushToken
                                    andVoipPushToken:(nonnull NSData *)voipPushToken
                                 andSubscriptionID:(nonnull NSString *)subscriptionID
                                 completionHandler:(void (^_Nullable)(SMMobileError * _Nullable error))completionBlock;

/**
 * This method removes the push notification subscription.
 *
 * @param subscriptionID unique ID assigned to the subscribed device by SPiDR/KL after the push subscription
 * @param completionBlock block implementation that will be used to return success or fail
 *
 * @since 4.6.0
 */
- (void) unsubscribeFromPushNotificationsWithSubscriptionID:(nonnull NSString *)subscriptionID
                                          completionHandler:(void (^_Nullable)(SMMobileError * _Nullable error))completionBlock;

/**
 * Enables message passing to MobileSDK (messages can be sent via push notification, websocket or any different way)
 *
 * @param message payload dictionary for incoming notification
 * @param error json object parse error if exists
 * @param completionHandler returns error if any json object parse error exists or notification data is not related with the MobileSDK
 *
 * @since 3.0.5
 * @updated 4.6.0
 */
- (void) injectPushMessage:(nonnull NSDictionary *)message
         completionHandler:(void (^ _Nonnull)(SMMobileError * _Nullable error))completionHandler;

/*_Nullable*
 * Constructing is disallowed from API level.
 */
- (nullable id)init __attribute__((unavailable("init is not a supported initializer for this class.")));


/**
* Parses Incoming Call Voip Push Notification(PushKit) and returns the information neccesary to trigger CallKit
*
* @param pushMessage payload dictionary for incoming notification
* @return CallKit Information Object
* @since 5.5.0
*/
-(SMCKInfo *_Nonnull) parsePushNotification:(NSDictionary* _Nonnull)pushMessage;

@end
