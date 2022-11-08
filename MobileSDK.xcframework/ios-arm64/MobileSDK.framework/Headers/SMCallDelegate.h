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
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "SMCallTypes.h"
#import "SMCodecType.h"
#import "SMVideoSourceTypes.h"


@class SMCallState;
@class SMUriAddress;
@class SMMediaAttributes;
@class SMMobileError;

/**
 * @brief Call related resources
 * @since 2.0.0
 */
@protocol SMCallDelegate <NSObject>

/**
 * @brief Address of the user who starts call
 * @since 2.0.0
 */
@property (strong, nonatomic, nonnull) SMUriAddress * callerAddress;

/**
 * @brief Address of the user who is being called
 * @since 2.0.0
 */
@property (strong, nonatomic, nonnull) SMUriAddress * calleeAddress;

/**
 * @brief Name of the user who starts call
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString * callerName;

/**
 * @brief Name of the user who receives the call
 * @since 4.5.9
 */
@property (strong, nonatomic, nullable) NSString * calleeName;

/**
 * @brief Holds video view which retrieved from local camera
 * Should be linked with GUI object which is a UIView
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) UIView * localVideoView;

/**
 * @brief Holds video view which received from remote participant of call
 * Should be linked with GUI object which is a UIView
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) UIView * remoteVideoView;

/**
 * @brief Perform end operation on the call.
 * @since 2.0.0
 */
- (void) endCall;

/**
 * @brief Perform end operation with end reason on the call.
 *
 * @param reason reason which specifies why call ended (Reason text character size shouldn't be larger than 600)
 *
 * @since 4.4.1
 */
- (void) endCallWithReason:(NSString * _Nullable)reason;

/**
 * @brief Puts the speaker (microphone) into (in) mute
 * @since 2.0.0
 */
- (void) mute;

/**
 * @brief Resumes the speaker
 * @since 2.0.0
 */
- (void) unMute;

/**
 * @brief Starts the local video unmute
 * The video unmute for the active call.
 * The call should be a video call and it should be disabled previously. Otherwise, SDK will return an error
 * @since 6.6.0
 */
- (void) videoUnMute;

/**
 * @brief Stops the local video track
 * The video mute for the active call.
 * The call should be a video call and it should be enabled previously. Otherwise, SDK will return an error
 * @since 6.6.0
 */
- (void) videoMute;

/**
 * @brief Stops the video for the call
 * @since 2.0.0
 */
- (void) videoStop;

/**
 * @brief Starts the video for the call
 * @since 2.0.0
 */
- (void) videoStart;

/**
 * @brief Perform hold operation on this call
 * @since 2.0.0
 */
- (void) holdCall;

/**
 * @brief Perform un-hold (resume) operation on this call
 * @since 2.0.0
 */
- (void) unHoldCall;

/**
 * @brief Sends the given custom SIP headers to SPiDR server.
 *
 * @param customParameters key-value pairs of custom SIP headers to send
 * @since 4.5.0
 */
- (void) sendCustomParameters:(NSDictionary * _Nullable)customParameters;

/**
 * @brief Sets given custom SIP Headers as custom parameters to call in order to send them in all mid-call event requests.
 *
 * @param customParameters key-value pairs of custom SIP headers to send
 * @since 4.5.0
 */
- (void) setCustomParameters:(NSDictionary * _Nullable)customParameters;

/**
 * @brief Gets custom SIP Headers which are set to the Call as custom parameters to call in order to send them in all mid-call event requests.
 *
 * @return customParameters key-value pairs of custom SIP headers to send
 * @since 4.5.0
 */

- (NSDictionary * _Nullable) getCustomParameters;

/**
 * @brief Method used by the application to transfer this call to another endpoint.
 *
 * @param newAddress address of the endpoint to replace this endpoint in the call
 * @since 2.0.0
 */
- (void) transferCall: (SMUriAddress * _Nonnull) newAddress;

/**
 * @brief Transfers the current call to the transfer target given with another call session in a consultative transfer manner.
 *
 * @param call other call session as transfer target
 * @since 4.5.1
 */
- (void) consultativeTransfer: (id<SMCallDelegate> _Nonnull) call;

/**
 * @brief Inserts Dual Tone Multi Frequency Signal to sending queue and returns the success
 * @param tone character value of DTMF tone. Can only be 0,1...,9,*,#,a,b,c,d,A,B,C,D;
 * @return YES if tone can be successfully inserted to queue otherwise NO
 * @since 3.0.1
 */
- (BOOL) sendDTMF:(char)tone;

/**
 * @brief Sets device capture and video resolution to specified position and resolution of the related call. If nil resolution value is provided then resotion value in configuration will be used. If resolution in configuration is set to nil default VGA (640x480) value will be set.
 *
 * If a resolution value is not suitable to camera session then camera will not be changed and handler will be triggered with an error
 *
 * @param position AVCaptureDevicePosition of the camera which will be used
 * @param videoResolution that intended to resolution
 * @param handler that returns error
 * @since 2.0.0
 * @modified 4.0.2
 */
- (void) setCaptureDevice:(AVCaptureDevicePosition)position withVideoResolution:(NSString * _Nonnull)videoResolution completionHandler: (void (^_Nullable)(SMMobileError * _Nullable error)) handler;

/**
 * @brief Allow applications to set image buffers as external video source.
 *
 * SDK can transmit any image to remote peer if application uses this API.
 * Applications that want to use this API should set setVideoSourceType to EXTERNAL_VIDEO
 *
 * @param imageBuffer will be converted to RTCVideoFrame
 * @param handler that returns error
 * @since 6.4.0
*/
- (void) setExternalVideoSource:(CVImageBufferRef _Nullable )imageBuffer completionHandler: (void (^_Nullable)(SMMobileError * _Nullable error)) handler;
;

/**
 * @brief Returns callId that related with SIP session id
 * For the outgoing call, this value is not set until establish call is succeeded
 * @return callId unique identifier of call that related SIP session
 * @since 2.0.0
 */
- (nonnull NSString *) getCallId;

/**
 * @brief Retrieve state of the call.
 * @return CallStates state of the call
 * @since 2.0.0
*/
- (nonnull SMCallState *) getCallState;

/**
 * @brief Retrieve media attributes of the call.
 * @return MediaAttributes attributes of the call's media
 * @since 2.0.0
 * @modified 4.0.1
 */
- (nonnull SMMediaAttributes *) getMediaAttributes;

/**
 * @brief Tests if the call is in muted state
 * @return YES if call is muted otherwise NO
 * @since 2.0.0
 */
- (BOOL) isMute;

/**
 * @brief Indicates remote side can send video or not. Local side can receive video if he wishes.
 * It is determined by Remote Session Description direction as follows
 * 
 * <table>
 * <tr>
 *    <td></td>
 *    <td>sendrecv</td>
 *    <td>sendonly</td>
 *    <td>recvonly</td>
 *    <td>inactive</td>
 * </tr>
 * <tr>
 *    <td>Values</td>
 *    <td>true</td>
 *    <td>true</td>
 *    <td>false</td>
 *    <td>false</td>
 * </tr>
 * </table>
 *
 * @return BOOL
 * @since 2.0.0
 */
- (BOOL) canReceiveVideo;

/**
 * @brief Indicates remote side can receive video or not. Local side can send video if he wishes.
 * It is determined by Remote Session Description direction as follows
 *
 * <table>
 * <tr>
 *    <td></td>
 *    <td>sendrecv</td>
 *    <td>sendonly</td>
 *    <td>recvonly</td>
 *    <td>inactive</td>
 * </tr>
 * <tr>
 *    <td>Values</td>
 *    <td>true</td>
 *    <td>false</td>
 *    <td>true</td>
 *    <td>false</td>
 * </tr>
 * </table>
 *
 * @return BOOL
 * @since 2.0.0
 */
- (BOOL) canSendVideo;

/**
 * @brief Gets last camera position set. If camera is not active last active camera position will be returned.
 *
 * @return AVCaptureDevicePosition position of the current active camera
 * @since 2.0.0
 */
- (AVCaptureDevicePosition) getActiveCamera;

/**
 * @brief Gets last camera resolution set. Value can return nil if method is called before camera allocation.
 *
 * @return NSString camera resolution of the current active camera
 * @see AVCaptureSessionPreset
 *
 * @since 4.0.2
 */
- (nullable NSString *) getCameraResolution;

/**
 * @brief Gets RTP/RTP Statistics for related call
 *
 * @param completion Completion Block
 *
 * @return array which contains RTP/RTCP Statistics as JSON formatted String
 *
 * @since 3.1.4
 */
- (void) getRTPStatistics:(void (^_Nonnull)(NSString * _Nullable statistics))completion;

/**
 * @brief Gets id value of call
 *
 * @return Id which is not related with Spidr Session Id
 *
 * @since 4.2.1.1
 */
- (nonnull NSString *) Id;

/**
 * @brief Returns the list of available and supported codecs
 *
 * @param codecType  the codec type
 * @return the list of available codecs
 * @since 5.17.0
*/
- (NSArray<NSDictionary *> *) getAvailableCodecs:(SMCodecType)codecType;

/**
 * @brief Allows applications to set VideoSourceTypes.
 *
 * MobileSDK supports multiple video source types. CAMERA is the default video source type.
 * Alternatively, applications can select EXTERNAL_VIDEO and insert video frames as their desire.
 * If EXTERNAL_VIDEO is chosen as the video source type, application must provide frames by using setExternalVideoSource API.
 *
 * @since 6.4.0
 * @param videoSourceType videoSourceType enum
 */
- (void) setVideoSourceType:(SMVideoSourceTypes) videoSourceType;


@end
