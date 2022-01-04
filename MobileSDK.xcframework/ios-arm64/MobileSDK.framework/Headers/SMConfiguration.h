/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.24.0
 *
 */

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "SMCameraModes.h"
#import "SMICEOptions.h"
#import "SMSlowStartCallPolicy.h"
#import "SMLogType.h"
#import "SMConnectionType.h"
#import "SMLoggingDelegate.h"
#import "SMRingingFeedbackOptions.h"
#import "SMScalingType.h"

@class SMICEServers;
@class SMCodecSet;
@class SMAudioSessionConfiguration;
@class SMAudioCodecConfiguration;
@class SMCodecToReplace;
@class SMCallReceiveBandwidthLimit;

/**
 * @brief Utility class for configuration management.
 * @since 2.0.0
 **/
@interface SMConfiguration : NSObject

/**
 * Name value of the user.
 * @since 2.0.0
 *
 */
@property (nonatomic, strong) NSString * _Nullable userName;

/**
 *"Authorization Name" value of the user.
 * It must be set when username and authorizationName are different
 * Default value is nil
 *
 * @since 4.5.6
 */
@property (nonatomic, strong) NSString * _Nullable authorizationName;

/**
 * Password value of the user.
 * @since 2.0.0
 *
 */
@property (nonatomic, strong) NSString * _Nullable password;

/**
 * server port information of the baseUrl used for REST request.
 *
 * Default value is 443.
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) NSString * _Nullable restServerPort;

/**
 * server ip information of the baseUrl used for REST request.
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) NSString * _Nullable restServerIP;

/**
 * Sets the push server URL.
 *
 * @since 4.6.0
 */
@property(nonatomic, strong) NSURL * _Nullable pushServerURL;

/**
 * port information used in web socket connection creation.
 *
 * Default value is 443.
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) NSString * _Nullable webSocketServerPort;

/**
 * ip information used in web socket connection creation.
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) NSString * _Nullable webSocketServerIP;

/**
 * Web socket Self signed certificate file data. Can be fetched from a file or string
 * @code
 * NSString *cerPath = &#91;&#91;NSBundle mainBundle&#92; pathForResource:@"myOwnCertificate" ofType:@"der"&#92;;
 * &#91;&#91;Configuration getInstance] setWebSocketCertificate:&#91;&#91;NSData alloc&#92; initWithContentsOfFile:cerPath&#92;&#92;;
 * @endcode
 *
 * @since 3.0.3
 */
@property (nonatomic, strong) NSData* _Nullable webSocketCertificate;

/**
 * LoggingDelegate reference used by LogManager.
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) id<SMLoggingDelegate> _Nonnull logger;

/**
 * Sets the ice options as ICE_VANILLA or ICE_TRICKLE.
 * Default value is ICE_VANILLA
 * MobileSDK will have same behavior in older versions,
 * if “iceOption” is selected as Vanilla ICE or used default value.
 *
 * @since 4.1.0
 */
@property(nonatomic) SMICEOptions iceOption;

/**
 * ICEServers stores ICE servers array (including stun & turn).
 *
 * @since 3.0.3
 */
@property (nonatomic, strong) SMICEServers * _Nullable ICEServers;

/**
 * Default username of ICEServers.
 *
 * @since 3.0.3
 */
@property (nonatomic, strong) NSString * _Nullable defaultICEUsername;

/**
 * Default password of ICEServers.
 *
 * @since 3.0.3
 */
@property (nonatomic, strong) NSString * _Nullable defaultICEPassword;

/**
 * @brief Sets initial video resolution for video
 * Value should be one of the AVCaptureSessionPreset strings.
 *
 * If videoResolution value is to nil high resolution (720p) will be used by default.
 * @see AVCaptureSessionPreset
 *
 * @since 2.0.0
 * @modified 4.0.2
 */
@property (nonatomic, strong) NSString * _Nullable videoResolution;
/**
 *Configuration to set HTTP Connection header in rest request
 *Default value is true
 *true for Connection: keep alive
 *false for Connection:  close
 *
 *@since 5.4.0
 */
@property(nonatomic) BOOL httpPersistentConnection;
/**
 * Subscription expire time
 *
 * @since 2.0.0
 */
@property (nonatomic, strong) NSNumber * _Nullable subscriptionExpires;

/**
 * Server certificate to be used in HTTPS connection.Certificate must be .DER format
 * @code
 * NSString *cerPath = &#91;&#91;NSBundle mainBundle&#92; pathForResource:@"myOwnCertificate" ofType:@"der"&#92;;
 * &#91;&#91;Configuration getInstance] setWebSocketCertificate:&#91;&#91;NSData alloc&#92; initWithContentsOfFile:cerPath&#92;&#92;;
 * @endcode
 *
 * @since 2.0.0
 */
@property(nonatomic, strong) NSData * _Nullable serverCertificate;

/**
 * Sending audit message frequency (seconds)
 *
 * Default value is 30.
 *
 * @since 2.0.0
 */
@property(nonatomic) NSInteger auditFrequency;

/**
 * Forces to disable media transfer when media on hold is active. It helps to fix some
 * MOH issues on PSTN calls
 *
 * @since 4.5.5
 */
@property(nonatomic) BOOL forceDisableMediaOnHold;

/**
 * codecSet stores available codecs for audio and video.
 *
 * @since 3.0.5
 */
@property (nonatomic, strong) SMCodecSet * _Nullable preferredCodecSet;

/**
 * Sets codecPayloadTypeSet to modify payload numbers of audio and video codecs
 *
 * @since 4.5.8
 */
@property (nonatomic, strong) NSArray<SMCodecToReplace *> * _Nullable codecPayloadTypeSet;

/**
 * Sets the camera orientation type of video capturer. 
 * Video orientation can be changed according to application status bar orientation
 * or device orientation. Camera can be bind to this notifications or not to be bind
 * anything.
 *
 * @since 2.0.0
 */
@property(nonatomic) SMCameraOrientationMode orientationMode;

/**
 * Scaling type parameter for local and remote video views.
 *
 * @since 5.20.0
 */
@property(nonatomic) SMScalingType scalingType;

/**
 * Sets the default camera position mode
 * @see AVCaptureDevicePosition
 *
 * @since 3.0.1
 */
@property (nonatomic) AVCaptureDevicePosition cameraPosition;

/**
 * Sets fps value of the video source
 * If invalid value is set, it will cause no video on call
 * Default value is 30.
 *
 * @since 4.5.1.2
 */
@property (nonatomic) NSUInteger fps;


/**
 * Sets duration value of DTMF tones im ms
 * Default value is 600 and can be between 40 and 6000
 *
 * @since 5.0.0
 */
@property (nonatomic) NSUInteger dtmfToneDuration;

/**
 * Sets log level of Mobile SDK
 *
 * If not set, TRACE level is used as default.
 *
 * @see SMLogLevel
 *
 * @since 3.0.2
 */
@property (nonatomic) SMLogLevel logLevel;

/**
 * Specifies timeout value of ICE Collection
 * Default value is 10 and it means that waits 10 seconds for ice gathering.
 * if it is set as 0, it means that waits until ice gathering completion.
 *
 * @since 3.1.3
 * @modified 5.6.0
 */
@property (nonatomic) NSTimeInterval ICECollectionTimeout;

/**
 * Sets audio session configuration
 * @see AVAudioSession
 *
 * @since 4.2.0
 */
@property (nonatomic, strong) SMAudioSessionConfiguration * _Nullable audioSessionConfiguration;

/**
 * Sets the audio codec configurations. If parameter is null WebRTC defaults will be use.
 * Warning: This is advance usage if you don't have expertise on audio codecs, especially opus, don't use it.
 *
 * @param audioCodecConfigurations SMAudioCodecConfiguration object which will contains all audio codec configurations.
 *
 * @since 4.2.0
 */
@property (nonatomic, strong) SMAudioCodecConfiguration * _Nullable audioCodecConfigurations;

/**
 * Specifies accept type for Slow Start Incoming Calls.
 * Default value will be AudioSupported that means Slow Start Incoming Calls will be initiated by supporting only audio.
 *
 * @since 4.5.4
 */
@property(nonatomic) SMSlowStartCallPolicy slowStartCallPolicy;

/**
 * Bandwidth limit of receiving media
 *
 * @since 4.6.1
 */
@property (nonatomic, strong) SMCallReceiveBandwidthLimit * _Nullable receiveBandwidthLimit;

/**
* Push Notification Configuration Parameter
*
* @since 5.0.0
*/
@property (nonatomic) BOOL isPushEnabled;

/**
* Bearer Token Configuration Parameter
*
* @since 5.7.0
*/
@property (nonatomic) NSString * _Nullable bearerToken;


/**
* Websocket  Token  Authentication Configuration Parameter
*
* @since 5.7.0
*/
@property (nonatomic) BOOL websocketWithTokenAuthentication;


/**
 *Ringing feedback configuration parameter.
 *Default value is CLIENT.
 *
 *@since 5.15.0
 */
@property(nonatomic) SMRingingFeedbackOptions ringingFeedbackOption;

/**
 * This method returns (creates if necessary) singleton instance of Configuration class
 *
 * @return shared Configuration instance
 *
 * @since 2.0.0
 */
+ (nonnull SMConfiguration *)getInstance;


@end
