/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.8.1
 *
 */

#import <Foundation/Foundation.h>
#import "SMCallTypes.h"

@class SMMobileError;
@class SMCallState;
@class SMMediaAttributes;

@protocol SMCallDelegate;
@protocol SMIncomingCallDelegate;
@protocol SMOutgoingCallDelegate;

/**
 * @brief Represents events of Call
 * This protocol must be conformed by classes which uses CallService
 * @since 2.0.0
 */
@protocol SMCallApplicationDelegate <NSObject>

NS_ASSUME_NONNULL_BEGIN

/**
 * This method is invoked when there is an IncomingCall
 * Used for informing the application about new call.
 * @param call reference of incoming call
 * @since 2.0.0
 */
- (void) incomingCall:(id<SMIncomingCallDelegate>) call;

/**
 * This is the call back method for any call state change on the CallDelegate.
 *
 * @param call which of state changed
 * @param callState
 * @since 2.0.0
 */
- (void) callStatusChanged:(id<SMCallDelegate>)call withState:(SMCallState*)callState;

/**
 * This method is invoked when a detailed call information is available that can be used on statistics
 *
 * @param call related call
 * @param detailedInfo additional info dictionary
 * @since 4.4.0
 */
- (void) callAdditionalInfoChanged:(id<SMCallDelegate>)call withDictionary:(NSDictionary*)detailedInfo;

/**
 * This is the call back method for any call's media attributes change on the CallDelegate.
 *
 * @param call which of media attributes changed
 * @param mediaAttributes
 * @since 2.0.0
 * @modified 4.0.1
 */
- (void) mediaAttributesChanged:(id<SMCallDelegate>)call withMediaAttributes:(SMMediaAttributes *) mediaAttributes;

/**
 * This method is invoked when establishCall has succeeded.
 * @param call performed establishment successfully
 * @see [OutgoingCallDelegate establishCall:]
 * @since 2.0.0
 */
- (void) establishCallSucceeded:(id<SMOutgoingCallDelegate>) call;

/**
 * This method is invoked when establishCall has failed.
 * @param call couldn't made outgoing call establisment
 * @param error definition of failure
 * @see [OutgoingCallDelegate establishCall:]
 * @since 2.0.0
 */
- (void) establishCallFailed:(id<SMOutgoingCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to accept an incoming call has succeeded.
 * @param call performed accepting successfully
 * @see [IncomingCallDelegate acceptCall:]
 * @since 2.0.0
 */
- (void) acceptCallSucceed:(id<SMIncomingCallDelegate>) call;

/**
 * Method invoked when attempt to accept an incoming call has failed.
 * @param call couldn't be accepted
 * @param error definition of failure
 * @see [IncomingCallDelegate acceptCall:]
 * @since 2.0.0
 */
- (void) acceptCallFailed:(id<SMIncomingCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to reject an incoming call has succeeded.
 * @param call performed reject successfully
 * @see [IncomingCallDelegate rejectCall]
 * @since 2.0.0
 */
- (void) rejectCallSuccedded:(id<SMIncomingCallDelegate>) call;

/**
 * Method invoked when attempt to reject an incoming call has failed.
 * @param call that couldn't be rejected
 * @param error definition of failure
 * @see IncomingCallDelegate rejectCall method
 * @since 2.0.0
 */
- (void) rejectCallFailed:(id<SMIncomingCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to ignore a call has succeeded.
 * @param call performed ignore successfully
 * @see [IncomingCallDelegate ignoreCall]
 * @since 2.0.0
 */
- (void) ignoreSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to ignore a call has failed.
 * @param call couldn't be ignored
 * @param error definition of failure
 * @see [IncomingCallDelegate ignoreCall]
 * @since 2.0.0
 */
- (void) ignoreFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to sendRingingFeedback an incoming call has succeeded.
 * @param call performed sendRingingFeedback successfully
 * @see [IncomingCallDelegate sendRingingFeedback]
 * @since 4.3.2
 *
 */
- (void) sendRingingFeedbackSucceed:(id<SMIncomingCallDelegate>) call;

/**
 * Method invoked when attempt to sendRingingFeedback an incoming call has failed.
 * @param call that coludn't send ringing feedback
 * @param error definition of failure
 * @see [IncomingCallDelegate sendRingingFeedback]
 * @since 4.3.2
 *
 */
- (void) sendRingingFeedbackFailed:(id<SMIncomingCallDelegate>) call withError:(SMMobileError *) error;

/**
 * This method is invoked when endCall has succeeded.
 * This is the call back method for the endCall request
 * @param call performed end successfully
 * @see [CallDelegate endCall]
 * @since 2.0.0
 */
- (void) endCallSucceeded:(id<SMCallDelegate>) call;

/**
 * This method is invoked when endCall has failed.
 * This is the call back method for the endCall request
 * @param call coudn't be ended
 * @param error definition of failure
 * @see [CallDelegate endCall]
 * @since 2.0.0
 */
- (void) endCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *)error ;

/**
 * Method invoked when attempt to mute a call has succeeded.
 * @param call performed mute successfully
 * @see [CallDelegate mute]
 * @since 2.0.0
 */
- (void) muteCallSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to mute a call has failed.
 * @param call coudn't be muted
 * @param error definition of failure
 * @see [CallDelegate mute]
 * @since 2.0.0
 */
- (void) muteCallFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to unmute a call has succeeded.
 * @param call performed unmute successfully
 * @see [CallDelegate unMute]
 * @since 2.0.0
 */
- (void) unMuteCallSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to unmute a call has failed.
 * @param call couldn't be unmuted
 * @param error definition of failure
 * @see [CallDelegate unMute]
 * @since 2.0.0
 */
- (void) unMuteCallFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to start video on a call has succeeded.
 * @param call performed start video start successfully
 * @see [CallDelegate videoStart]
 * @since 2.0.0
 */
- (void) videoStartSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to start video on a call has failed.
 * @param call coudn't start video
 * @param error definition of failure
 * @see [CallDelegate videoStart]
 * @since 2.0.0
 */
- (void) videoStartFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to stop video on a call has succeeded.
 * @param call performed stop video successfully
 * @see [CallDelegate videoStop]
 * @since 2.0.0
 */
- (void) videoStopSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to stop video on a call has failed.
 * @param call coudn't stop video
 * @param error definition of failure
 * @see [CallDelegate videoStop]
 * @since 2.0.0
 */
- (void) videoStopFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * The method that is called when an attempt to video unMute succeeded in a call.
 * @see [CallDelegate videoUnMute]
 * @since 6.6.0
 */
- (void) videoUnMuteSucceed:(id<SMCallDelegate>) call;

/**
 * The method that is called when an attempt to video unMute fails in a call.
 * @param error definition of failure
 * @see [CallDelegate videoUnMute]
 * @since 6.6.0
 */
- (void) videoUnMuteFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * The method that is called when an attempt to video mute succeeded in a call.
 * @see [CallDelegate videoMute]
 * @since 6.6.0
 */
- (void) videoMuteSucceed:(id<SMCallDelegate>) call;

/**
 * The method that is called when an attempt to video mute fails in a call.
 * @param error definition of failure
 * @see [CallDelegate videoMute]
 * @since 6.6.0
 */
- (void) videoMuteFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to hold a call has succeeded.
 * @param call performed hold successfully
 * @see [CallDelegate holdCall]
 * @since 2.0.0
 */
- (void) holdCallSucceed:(id<SMCallDelegate>)call;

/**
 * Method invoked when attempt to hold a call has failed.
 * @param call couldn't be holded
 * @param error definition of failure
 * @see [CallDelegate holdCall]
 * @since 2.0.0
 */
- (void) holdCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to unHold a call has succeded.
 * @param call performed unhold successfully
 * @see [CallDelegate unHoldCall]
 * @since 2.0.0
 */
- (void) unHoldCallSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to unHold a call has failed.
 * @param call couldn't be unholded
 * @param error definition of failure
 * @see [CallDelegate unHoldCall]
 * @since 2.0.0
 */
- (void) unHoldCallFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method is invoked when sending the custom SIP headers has succeeded.
 *
 * @param call the call which succeeded in sending custom SIP headers
 * @see [CallDelegate sendCustomParameters]
 * @since 4.5.0
 */
- (void) sendCustomParametersSuccess:(id<SMCallDelegate>) call;

/**
 * Method is invoked when sending the custom SIP headers has failed.
 *
 * @param call the call which failed in sending custom SIP headers
 * @param error related error
 * @see [CallDelegate sendCustomParameters]
 * @since 4.5.0
 */
- (void) sendCustomParametersFail:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method is invoked when attempt to join call with another call has succeeded.
 * @param call new created call after join
 * @since 2.0.0
 */
- (void) joinSucceeded:(id<SMCallDelegate>) call;

/**
 * Method is invoked when attempt to join call with another call has succeeded.
 * @param call coudn't made the join
 * @param error definition of failure
 * @since 2.0.0
 */
- (void) joinFailed:(id<SMCallDelegate>)call withError:(SMMobileError *)error ;

/**
 * Method invoked when attempt to transfer a call has succeeded.
 * @param call performed transfer call successfully
 * @see [CallDelegate transferCall:]
 * @since 2.0.0
 */
- (void) transferCallSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to transfer a call has failed.
 * @param call couldn't made transferring
 * @param error reason of the failure
 * @see [CallDelegate transferCall:]
 * @since 2.0.0
 */
- (void) transferCallFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

/**
 * Method invoked when attempt to forward a call has succeeded.
 * @param call performed forward call successfully
 * @see [CallDelegate transferCall:]
 * @since 2.0.0
 */
- (void) forwardCallSucceed:(id<SMCallDelegate>) call;

/**
 * Method invoked when attempt to forward a call has failed.
 * @param call couldn't made forward
 * @param error reason of the failure
 * @see [CallDelegate transferCall:]
 * @since 2.0.0
 */
- (void) forwardCallFailed:(id<SMCallDelegate>) call withError:(SMMobileError *)error;

NS_ASSUME_NONNULL_END

@end
