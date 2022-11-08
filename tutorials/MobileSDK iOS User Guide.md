# Mobile SDK User Guide for iOS
Version Number: **$SDK_VERSION$**
<br>
Revision Date: **November 08, 2022**

## Mobile SDK overview

The SPiDR/Kandy Link Mobile Software Development Kit (SDK) defines a library implementation supporting SPiDR platform features like registration, notification, call management, instant message, presence management, and WebRTC on iOS. You can use this library implementation to integrate SPiDR/Kandy Link services and WebRTC into your native mobile applications to create new, innovative user experiences.

The Mobile SDK has the following characteristics:

* supports REST over HTTP/HTTPS for integration with the presentation layer of SPiDR/Kandy Link
* supports WebSocket for notification
* built and distributed as a standard library structure for easy use in mobile applications
* most features are implemented based on factory and singleton design patterns
* classes contain a prefix "SM" ("SPiDR Mobile") to prevent conflicts with developer classes
* access to REST APIs provided by Ribbon's Kandy platform

See [Appendix A: High-level Mobile SDK structure](#appendix-a-high-level-mobile-sdk-structure) for a high-level view of the Mobile SDK and its sub-modules.

The Mobile SDK for iOS is compatible with iOS 9.x-12.x and has been tested on iPhone 4S, 5, 5C, 5S, 6, 6+, 6S, 6S+, 7, 7+, 8, 8+, X, iPad mini, iPad 4, and iPad Air. The SDK supports IPv6 for iOS.

### What's in this document?

This document provides help getting started developing your mobile application using the Mobile SDK for iOS. This guide contains:

* Steps to create your Xcode project using the Mobile SDK
* Sample code to illustrate common tasks

### Before you start developing your application

The following items need to be complete prior to beginning work on your application:

* Your Xcode development environment is set up and ready for new projects.
* You know the IP address and port of the SPiDR/Kandy Link server.

<div class="page-break" />

## Get Started

### Installation

This section contains the required steps for beginning your mobile application development and an example of using the Mobile SDK in Xcode 10.x.


1. Open the Xcode application.
2. Click Create a new Xcode project.
3. Click Application, located under the iOS heading in the left-side panel.
4. Click Single View Application for your project template.

![alt text](images/get_started_1.png "")

5. Click Next.
6. Type your project details and click Next.
7. Select a location for your project and click Create.
8. Select one of the installation methods below

#### Cocoapods
1. Add below pods to your Podfile (If you dont have any Podfile, visit this link to install cocoapods: https://guides.cocoapods.org/using/using-cocoapods.html)

```ruby
...

target 'YOUR_TARGET_NAME' do
    pod 'KandyLinkMobileSDK', '~> $SDK_VERSION$ '
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['ENABLE_BITCODE'] = 'NO'
    end
  end
end

...
```

2. Go to project folder via command line and run "pod install" command and wait for cocoapods to finish installation of MobileSDK, WebRTC frameworks and their dependencies

If you have a trouble with getting latest version of Kandy Link Mobile SDK plaese run these suggested commands [here](https://gist.github.com/mbinna/4202236) in project directory where Podfile is located.

#### Swift Package Manager Installation
1. File >Add Package Dependency
2. ![alt text](images/get_started_6.png "")
3. Add https://github.com/Kandy-IO/kandy-link-ios-sdk.git
4. ![alt text](images/get_started_7.png "")
5. Select "Branch" with "master"

#### Manual Installation
**IMPORTANT:** This installation section applies to **Kandy Link iOS SDK** versions prior to v5.17.0. If you are using a more recent version, follow the instructions [here](?id=manual-installation-after-v5170).

Before those steps you need to download **Kandy Link iOS SDK** framework file from [this link](https://raw.githubusercontent.com/Kandy-IO/kandy-link-ios-sdk/$SDK_VERSION$/dist/MobileSDK_$SDK_VERSION$.zip).

1. Navigate to Build Phases and scroll down to Link binary with libraries.
2. Add MobileSDK.framework under Link binary with libraries.
3. Add WebRTC.framework under the **Embedded Binaries** section in **General** tab on Project Settings. Select **Copy items if needed**.

![alt text](images/get_started_2.png "")

4. Add the following iOS SDK frameworks to your application:

* AvFoundation.framework
* SystemConfiguration.framework
* GLKit.framework
* VideoToolbox.framework
* AudioToolbox.framework
* PushKit.framework
* libc++.tbd
* libicucore.tbd
* libz.tbd

5. Mobile SDK doesn't support bitcode, under the "Build Settings" search for "Bitcode", and change "Enable Bitcode" option to NO.

![alt text](images/get_started_3.png "")

6. "-ObjC" flag should be added to "Other Linker Flags" options under the "Build Settings".

![alt text](images/get_started_4.png "")

### Manual Installation (After v5.17.0)
Support for XCFramework has been added to **Kandy Link iOS SDK** with the v5.17.0 release. You can install **Kandy Link iOS SDK** as XCFramework by following the steps below. (More information about XCFramework, see [link](https://help.apple.com/xcode/mac/11.4/#/dev6f6ac218b)).

First of all, you must have the **Kandy Link iOS SDK** XCFramework file for installation. You can download from [this link](https://raw.githubusercontent.com/Kandy-IO/kandy-link-ios-sdk/$SDK_VERSION$/dist/MobileSDK_$SDK_VERSION$.zip).

1. Go to project settings and navigate to **General**.
2. Add **MobileSDK.xcframework** and **WebRTC.xcframework** under **Framework, Libraries, and Embedded Content** section.

![Adding MobileSDK XCFramework to Project](images/get_started_5.png "")

3. Add the following iOS SDK frameworks to your application:

* AvFoundation.framework
* SystemConfiguration.framework
* GLKit.framework
* VideoToolbox.framework
* AudioToolbox.framework
* PushKit.framework
* libc++.tbd
* libicucore.tbd
* libz.tbd

4. Mobile SDK doesn't support bitcode, under the "Build Settings" search for "Bitcode", and change "Enable Bitcode" option to NO.

![alt text](images/get_started_3.png "")

5. "-ObjC" flag should be added to "Other Linker Flags" options under the "Build Settings".

![alt text](images/get_started_4.png "")

### Post Installation Steps

1. Add usage descriptions for both camera and microphone access should be added to application's Info.plist file.

```tag
<key>NSCameraUsageDescription</key>
<string>Your camera usage description message should be added here like this.</string>
<key>NSMicrophoneUsageDescription</key>
<string>Your microphone usage description message should be added here like this.</string>
```

### Enable background processing

The application must support background processing while on an active call, allowing SDK to process WebSocket operations even after the user presses the Home button, the Sleep/Wake button, or if another application is launched.

To enable background processing, add the "UIBackgroundModes" key to your app's **Info.plist** file. Set the value of this key to an array that includes the **voip** string.

![alt text](images/features_1.png "")

You can now use the Mobile SDK in your code implementation.

<div class="page-break"></div>

### Set application configuration

First, you must access and modify the Configuration utility to update attributes such as REST server IP or Port. The Mobile SDK receives data from the Configuration utility, and the third-party mobile application (third-party app) must provide necessary data to the Configuration utility. Example for basic configuration that needs Mobile SDK to work is shown in next page.

To see all available configurations, see [Appendix D: Detailed Configurations](#appendix-d-detailed-configurations)

<div class="page-break"></div>

###### Example: Accessing and updating Configuration

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

- (void) manageConfiguration
{
    //access SMConfiguration instance
    SMConfiguration * configuration =  [SMConfiguration getInstance];

    //after gathering the Configuration
    //a property X can be accessed as
    //configuration.X --> getter
    //configuration.X = --> setter

    //set minimum Configuration values
    //user name for authorization
    configuration.userName = @"username";
    //password for authorization
    configuration.password = @"password";
    //server IP value for SPiDR/Kandy Link
    configuration.restServerIP = @"$SUBSCRIPTIONFQDN$";
    //server port value for SPiDR/Kandy Link
    configuration.restServerPort = @"443";
    //logger implementation defined by application
    configuration.logger = self;

    //IP used in websocket connection creation.
    // If not provided, Rest Server IP will be used
    configuration.webSocketServerIP = @"$WEBSOCKETFQDN$";
    //port used in websocket connection creation
    configuration.webSocketServerPort = @"443";

    // add ICE Server
    SMICEServers * servers = [[SMICEServers alloc] init];
    [servers addICEServer:@"$TURNSERVER1$"];
    [servers addICEServer:@"$STUNSERVER1$"];
    [servers addICEServer:@"$TURNSERVER2$"];
    [servers addICEServer:@"$STUNSERVER2$"];
    [configuration setICEServers:servers];
}
```

#### ** Swift Code **

```swift
import MobileSDK

func manageConfiguration() {
    //access SMConfiguration instance
    let configuration = SMConfiguration.getInstance()

    //after gathering the Configuration
    //a property X can be accessed as
    //configuration.X --> getter
    //configuration.X = --> setter

    //set minimum Configuration values
    //user name for authorization
    configuration.userName = "username"
    //password for authorization
    configuration.password = "password"
    //server IP value for SPiDR/Kandy Link
    configuration.restServerIP = "$SUBSCRIPTIONFQDN$"
    //server port value for SPiDR/Kandy Link
    configuration.restServerPort = "443"
    //logger implementation defined by application
    configuration.logger = self

    //IP used in websocket connection creation
    // If not provided, Rest Server IP will be used
    configuration.webSocketServerIP  = "$WEBSOCKETFQDN$"
    //port used in websocket connection creation
    configuration.webSocketServerPort  = "443"

    // add ICE Server
    let servers = SMICEServers()
    iceServers.addICEServer("$TURNSERVER1$")
    iceServers.addICEServer("$STUNSERVER1$")
    iceServers.addICEServer("$TURNSERVER2$")
    iceServers.addICEServer("$STUNSERVER2$")
    configuration.iceServers = servers
}
```
<!-- tabs:end -->

### Setup logging functionality

Logging provides a way to trace process execution. The Log Manager is defined to handle logging requests made by the Mobile SDK. The Log Manager does not process the logging messages, rather it receives logging message requests and delivers them to the logger defined in the Configuration utility (logger is initially "null"; you must set an object which conforms to LoggingInterface methods in the Configuration utility).

###### Example: Define logger

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#define CONSOLE_LOG_PATH [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0] stringByAppendingPathComponent:@"consoleLog.ndjson"]

@interface ExampleLogger : NSObject <SMLoggingDelegate>

@end

@implementation ExampleLogger
    NSFileHandle *myFileHandle;
    - (id)init
    {
        self = [super init];
        if (self) {
            SMConfiguration * configuration = [SMConfiguration getInstance];
            configuration.logLevel = TRACE;
            configuration.logger = self;
            [self initLogFile];
        }
        return self;
    }

    - (void) initLogFile {
        if(myFileHandle) [myFileHandle closeFile];

    if(![[NSFileManager defaultManager] fileExistsAtPath:CONSOLE_LOG_PATH]){
        [@"" writeToFile:CONSOLE_LOG_PATH atomically:YES encoding:NSUTF8StringEncoding error:nil];
        myFileHandle = [NSFileHandle fileHandleForUpdatingAtPath:CONSOLE_LOG_PATH];
        NSString *logStr = [NSString stringWithFormat:@"NDJson Log File Path: %@", CONSOLE_LOG_PATH];
        // if the log file is first created we need to set true because should not insert a new blank line for the first message
        [self writeLogToFile:logStr isCreateFirst:YES];
    }else {
        myFileHandle = [NSFileHandle fileHandleForUpdatingAtPath:CONSOLE_LOG_PATH];
    }
  }

    -(void)log:(SMLogLevel)logLevel withLogContext:(NSString *)logContext withMethodName:(SEL) methodName withMessage:(NSString*)logMessage{
        NSString *methodStr = NSStringFromSelector(methodName);

        NSString *msg =[NSString stringWithFormat:@"[%@] <%@-%@>: %@",levelStr, logContext, methodStr, logMessage];
       [self writeLogToFile:msg isCreateFirst:NO];
       NSLog(@"%@", msg);                                                  
    }
        
   /// Description Writes log line to log file
   /// @param logLine Log line to write
   /// @param isCreatingLogFile  Flag indicating that file should be creating at first to prevent adding line break at top of file
   -(void) writeLogToFile:(NSString *)logLine isCreatingLogFile:(BOOL)isCreateFirst  {
       NSString *logStrFormater = [self convertLogToNDJSONLog:logLine isCreatingLogFile:isCreateFirst];
       [myFileHandle seekToEndOfFile];
       [myFileHandle writeData:[logStrFormater dataUsingEncoding:NSUTF8StringEncoding]];
  }


   /// This function converts standart log line to NDJSON log format. This is useful when we need to debug for support.
   /// @param logLine Log line to write
   /// @param isCreatingLogFile  Flag indicating that file should be creating at first to prevent adding line break at top of file
   -(NSString *)convertLogToNDJSONLog:(NSString *)logLine isCreatingLogFile:(BOOL)isCreateFirst  {
       NSString *dateStr = [NSDateFormatter localizedStringFromDate:[NSDate date]
                                                       dateStyle:NSDateFormatterShortStyle
                                                       timeStyle:NSDateFormatterMediumStyle];
    
       NSString *logStr = [NSString stringWithFormat:@"[%@]: %@", dateStr, logLine];
    
       NSMutableDictionary *dictionaryForLog = [[NSMutableDictionary alloc] init];
       [dictionaryForLog setObject:logStr forKey:@"line"];
    
       NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dictionaryForLog options:0 error:nil];
       NSString *myString = [[NSString alloc] initWithData: jsonData  encoding:NSUTF8StringEncoding];
       NSString *logStrFormater = [NSString stringWithFormat:@"\n%@", myString];
       if (isCreateFirst) {
        logStrFormater = [NSString stringWithFormat:@"%@", myString];
       }
       return logStrFormater;
  }
    
@end
```

#### ** Swift Code **

```swift
class ExampleLogger : NSObject, SMLoggingDelegate {
    private var handler: FileHandle?
    private override init() {
        super.init()
        let conf = SMConfiguration.getInstance()
        conf.logLevel = .trace
        conf.logger = self
        self.initLogFile()
    }
    private func initLogFile() {
        let destPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
        let fullDestPath = NSURL(fileURLWithPath: destPath).appendingPathComponent("ExampleLogger.ndjson")
        let fullDestPathString = fullDestPath!.path
        if !FileManager.default.fileExists(atPath: fullDestPathString) {
            do {
                try "".write(toFile: fullDestPathString, atomically: true, encoding: String.Encoding.utf8)
                let logStr ="Log File Path: " + fullDestPath];
                // if the log file is first created we need to set true because should not insert a new blank line for the first message
                self.writeLogToFile(logStr, true);
            } catch {
                NSLog("Can't write to file to device directory - Error: \(error.localizedDescription)")
            }
        }
        handler = FileHandle.init(forUpdatingAtPath: fullDestPathString)
    }


    func log(_ logLevel: SMLogLevel, withLogContext logContext: String, withMethodName methodName: Selector?, withMessage logMessage: String) {
        let dateStr = DateFormatter.localizedString(from: Date(), dateStyle: .short, timeStyle: .medium)
        let logString = "\(dateStr) : \(logContext) - \(logMessage)"
        print(logString)
        self.writeLogToFile(logString, false)      
    }


     /// Description Writes log line to log file
     /// @param logLine Log line to write
     /// @param isCreatingLogFile  Flag indicating that file should be creating at first to prevent adding line break at top of file
     func writeLogToFile(logLine: String, isCreatingLogFile:Bool) 
        if let logData = self.convertLogToNDJSONLog(logLine, isCreatingLogFile){
            handler?.write(logData)
        }
   }
   
   /// This function converts standart log line to NDJSON log format. This is useful when we need to debug for support.
   /// @param logLine Log line to write
   /// @param isCreatingLogFile  Flag indicating that file should be creating at first to prevent adding line break at top of file
   func convertLogToNDJSONLog(logLine: String, isCreateFirst:Bool) -> String {
        let dictionaryForLog = ["line" : logLine]
        let jsonData = try! JSONSerialization.data(withJSONObject: dictionaryForLog)
        let jsonString = NSString(data: jsonData, encoding: String.Encoding.utf8.rawValue)
	let logData = jsonString.data(using: String.Encoding.utf8)
	 if isCreateFirst {
              return logData
          } else {
             return "\n" + logData
          }
   }

}
```
<!-- tabs:end -->

###### Example: Initialize logger

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) initializeAndUseLogger
{
    SMConfiguration * configuration = [SMConfiguration getInstance];
    ExampleLogger    * exampleLogger    = [[ExampleLogger alloc] init];
    NSLog(@"logger is initialized");
}
```

#### ** Swift Code **

```swift
func initializeAndUseLogger() {
    let configuration = SMConfiguration.getInstance()
    let exampleLogger = ExampleLogger()

    NSLog("Logger is initialized")
}
```
<!-- tabs:end -->
##### Log Levels
###### Trace_WebRTC
The application developer should use this level to view all webrtc and SDK logs.
###### Trace
This is really fine-grained information. When you're at this level, you're basically looking to capture every detail you possibly can about the application's behavior. Think of this level as the method you should use for all the logging you will do while tracking a specific problem and most likely get rid of it once you find the problem.

App developer should use this level to view all messages on the sdk side. The logs coming from this level will lead to the solution of the SDK error. However, it should be noted that webrtc logs will not be displayed at this level.
###### Info
Info messages correspond to normal application behavior. They provide the skeleton of what happened. A service started or stopped. The notification engine started, you got a new message or network status changed. Think of it as all the messages you'd like to see in the log when creating call for example, or in other words - anything that might help you resolve or at least identify a problem without looking in the source code.

Logs at this level can either solve the problem or have ideas to solve the problem, but this is not guaranteed. It contains less information than the trace level.However, it should be noted that webrtc logs will not be displayed at this level.
###### Warning
Use this log level to indicate that you might have a problem and that you've detected an unusual situation. Maybe you were trying to invoke a service and it failed a couple of times before connecting on an automatic retry or you were trying to start a service which already running. It's unexpected and unusual, but no real harm done, and it's not known whether the issue will persist or recur. The application can tolerate warning messages, but they should always be justified and examined.

This level can be use to see errors and warnings from Sdk. Developer can view where the error is, but may not be able to find root cause of an error.Webrtc logs will not be displayed at this level
###### Error
An error is a serious issue and represents the failure of something important going on in your application. No system can tolerate items logged on this level. Maybe you've got something like dropped WebSocket connections or the inability to access a service.

This level can be use to see only errors from Sdk. Developer can view where the error is, but may not be able to find root cause of an error.Webrtc logs will not be displayed at this level


<div class="page-break"></div>

## Registration Service

MobileSDK should be registered to SPiDR/Kandy Link before using any other services.

**Note:** The Configuration parameters must be set before using registration service

### Register the client

 Use the `registerToServer` method to register the client to the server with the values set in configuration. After the client is registered, the notification state will be changed to "CONNECTED". The client will try to stay in "CONNECTED" states until the client is unregistered.

The `SMRegistrationApplicationDelegate` should be set to receive registration service notifications.

The registration service renews registration according to the expiration time with the help of SPiDR/Kandy Link's ping messages. The `getExpirationTime` method may be called after successful registration to retrieve the expiration time (in seconds) for registration.

<div class="page-break"></div>

###### Example: Registering to SPiDR/Kandy Link

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface RegistrationController () <SMRegistrationApplicationDelegate>
@end

@implementation RegistrationController

- (void) registerExample {
    SMRegistrationService *regService = [[SMServiceProvider getInstance] getRegistrationService];
    //Get registration service notifications
    [regService setRegistrationApplicationDelegate:self];

    [regService registerToServer:3600
               completionHandler:^(SMMobileError *error) {
        if(error){
            //Handle registration error
            return;
        }

        //Handle registration success

        //Developer can get expiration time, which is gathered from registration response
        NSInteger expirationTime = [regService getExpirationTime];
    }];
}

- (void)  registrationDropped:(SMMobileError*) error
{ 
    //Handle registration dropped
}

- (void) notificationStateChanged:(SMNotificationStates)notificationState
{
    //Handle notification state changes
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

class RegistrationController: NSObject, SMRegistrationApplicationDelegate {

    func registerExample() {
        let regService = SMServiceProvider.getInstance().getRegistrationService()
        regService.registrationApplicationDelegate = self
        regService.register(expirationTime: 3600) { (error) in
            if let error = error {
                // Handle registration error
                return
            }

            // Handle registration success
            // Developer can get expiration time, which is gathered from registration response
            let expirationTime = regService.getExpirationTime()
        }
    }

    func registrationDropped(_ error: SMMobileError) {
        //Handle registration dropped
    }

    func notificationStateChanged(_ notificationState: SMNotificationStates) {
        //Handle notification state changes
    }

}
```
<!-- tabs:end -->

### Register the client with HMAC Token

 MobileSDK can register to SPiDR/Kandy Link server with a valid HMAC Token obtained from SPiDR/Kandy Link. You can get information on how to get HMAC Token, see [here](#appendix-e-obtaining-a-hmac-token).

 Use the `registerToServer` method to register the client to the server with the values set in configuration. After the client is registered, the notification state will be changed to "CONNECTED". The client will try to stay in "CONNECTED" states until the client is unregistered. After registering with HMAC Token, in case the notification state is "DISCONNECTED", you must obtain a new HMAC token to register again. Because the obtained HMAC Tokens are disposable.

The `SMRegistrationApplicationDelegate` should be set to receive registration service notifications.

The registration service renews registration according to the expiration time with the help of SPiDR/Kandy Link's ping messages. The `getExpirationTime` method may be called after successful registration to retrieve the expiration time (in seconds) for registration.

<div class="page-break"></div>

###### Example: Registering to SPiDR/Kandy Link with HMAC Token

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface RegistrationController () <SMRegistrationApplicationDelegate>
@end

@implementation RegistrationController

- (void) registerExample {
    SMRegistrationService *regService = [[SMServiceProvider getInstance] getRegistrationService];
    NSString *token = @"dV85NzEyNzcxMjI5NkBpbnN0YXByYWN0LmV0aXNhbGF0LmFlOkluc3RhQDIwMjA"; // Sample HMAC token

    //Get registration service notifications
    [regService setRegistrationApplicationDelegate:self];

    [regService registerToServer:3600 hmacToken:token completionHandler:^(SMMobileError *error) {
        if(error){
            //Handle registration error
            return;
        }

        //Handle registration success

        //Developer can get expiration time, which is gathered from registration response
        NSInteger expirationTime = [regService getExpirationTime];
    }];
}

- (void)  registrationDropped:(SMMobileError*) error
{ 
    //Handle registration dropped
}

- (void) notificationStateChanged:(SMNotificationStates)notificationState
{
    //Handle notification state changes
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

class RegistrationController: NSObject, SMRegistrationApplicationDelegate {

    func registerExample() {
        let regService = SMServiceProvider.getInstance().getRegistrationService()
        let token = "dV85NzEyNzcxMjI5NkBpbnN0YXByYWN0LmV0aXNhbGF0LmFlOkluc3RhQDIwMjA" // Sample HMAC token

        regService.registrationApplicationDelegate = self
        regService.register(toServer: , HMACToken: token) { (error) in
            if let error = error {
                // Handle registration error
                return
            }

            // Handle registration success
            // Developer can get expiration time, which is gathered from registration response
            let expirationTime = regService.getExpirationTime()
        }
    }

    func registrationDropped(_ error: SMMobileError) {
    	//Handle registration dropped
    }

    func notificationStateChanged(_ notificationState: SMNotificationStates) {
        //Handle notification state changes
    }

}
```
<!-- tabs:end -->

<div class="page-break"></div>

### Unregister the client

To stop receiving events from SPiDR/Kandy Link, client should be unregistered. When unregistration is successful, the notification state will be changed to "DISCONNECTED".

###### Example: Unregistering from SPiDR/Kandy Link

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface RegistrationController () <SMRegistrationApplicationDelegate>
@end

@implementation RegistrationController

- (void) unregisterExample {
    SMRegistrationService *regService = [[SMServiceProvider getInstance] getRegistrationService];
    //Service types used in registration

    [regService unRegisterFromServerWithHandler:^(SMMobileError *error) {
        if(error){
            //Handle unregistration error
            return;
        }

        //Handle unregistration success
    }];
}

- (void) notificationStateChanged:(SMNotificationStates)notificationState
{
    //Handle notification state changes
}
@end
```

#### ** Swift Code **

```swift
import MobileSDK

class RegistrationController: NSObject, SMRegistrationApplicationDelegate {

    func unregisterExample() {
        let regService = SMServiceProvider.getInstance().getRegistrationService()
        regService.unRegisterFromServer { (error) in
            if let error = error {
                // Handle unregistration error
                return
            }

            // Handle unregistration success
        }
    }

    func notificationStateChanged(_ notificationState: SMNotificationStates) {
        //Handle notification state changes
    }

}
```
<!-- tabs:end -->

<div class="page-break"></div>

### Register the client with AuthName

If client wants to register with using "AuthName", `authName` property in `SMConfiguration` should be set before registration.

###### Example: Registering with using Authname

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMRegistrationService *regService = [[SMServiceProvider getInstance] getRegistrationService];

//Set AuthName
SMConfiguration.getInstance().authName = @"AuthName";
SMConfiguration.getInstance().userName = @"username";
SMConfiguration.getInstance().password = @"password";

//Get registration service notifications
[regService setRegistrationApplicationDelegate:self];

[regService registerToServer:3600
           completionHandler:^(SMMobileError *error) {
    if(error){
        //Handle registration error
        return;
    }

    //Handle registration success
}];
```

#### ** Swift Code **

```swift
let regService = SMServiceProvider.getInstance().getRegistrationService()

//Set AuthName
SMConfiguration.getInstance().authName = "AuthName"
SMConfiguration.getInstance().userName = "username"
SMConfiguration.getInstance().password = "password"

regService.registrationApplicationDelegate = self
regService.register(expirationTime: 3600) { (error) in
    if let error = error {
        // Handle registration error
        return
    }

    // Handle registration success
    // Developer can get expiration time, which is gathered from registration response
    let expirationTime = regService.getExpirationTime()
}
```
<!-- tabs:end -->

<div class="page-break" />

## Call Service

### Basic Usage of Call Service

Create outgoing calls by providing the target contact address and related UI views for video display, or receive incoming calls from another user.

#### Listen Call Service notifications

To receive incoming calls and event notifications of call service, `SMCallApplicationDelegate` should be implemented by calling `setCallApplication:`.

Incoming calls pass to the third-party app by the notification mechanism. Both incoming and outgoing calls can be manipulated with methods such as mute/unmute and start/stop video.

###### Example: Setting Call Application Delegate

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface CallController () <SMRegistrationApplicationDelegate, SMCallApplicationDelegate>
@end

@implementation CallController

- (void) registrationStateChanged:(SMRegistrationStates)registrationState {
    if (registrationState == REGISTERED) {
        [[[SMServiceProvider getInstance] getCallService] setCallApplication:self];
    }
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

class CallController: NSObject, SMRegistrationApplicationDelegate, SMCallApplicationDelegate {

    func registrationStateChanged(_ registrationState: SMRegistrationStates) {
        if registrationState == .registered {
            SMServiceProvider.getInstance().getCallService().setCallApplication(self)
        }
    }

}
```
<!-- tabs:end -->

#### Add STUN/TURN servers

SPiDR/Kandy Link provides TURN server support for media relay between two WebRTC endpoints in core version 3.0 and later. The ICEServers property in the SMConfiguration class is used to store the ICE servers list; more than one ICEServer can exist in this property.

##### Add SPiDR's (Kandy Link) TURN server

After registration, the Mobile SDK gets default credentials from SPiDR/Kandy Link for the TURN servers and updates the defaultICEUsername and defaultICEPassword configuration properties. The list of ICEServers and their credentials are added to the PeerConnection when creating a call.

The following code sample will request TURN server credentials from SPiDR/Kandy Link and update the configuration instance.

**Note:** If your SPiDR/Kandy Link core version does not have TURN Server support, adding a TURN server without a username and password will cause the registration request to fail.

###### Example: Adding STUN/TURN server

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMICEServers *servers = [[SMICEServers alloc] init];
[servers addICEServer:@"$TURNSERVER1$"];
[servers addICEServer:@"$STUNSERVER1$"];
[servers addICEServer:@"$TURNSERVER2$"];
[servers addICEServer:@"$STUNSERVER2$"];
[[SMConfiguration getInstance] setICEServers:servers];
```

#### ** Swift Code **

```swift
var servers = SMIceServers()
servers.addICEServer("$TURNSERVER1$")
servers.addICEServer("$STUNSERVER1$")
servers.addICEServer("$TURNSERVER2$")
servers.addICEServer("$STUNSERVER2$")
SMConfiguration.getInstance().iceServers = servers
```
<!-- tabs:end -->

##### Add an external TURN/STUN server

You also have the option of using external TURN/STUN servers while establishing calls rather than SPiDR's (Kandy Link) TURN server(s). The ICEServers property will store the address and username/password for the server(s).

Use the addICEServer:username:password: method of the ICEServers object to define credentials.

###### Example: Add a STUN server

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMICEServers *servers = [[SMICEServers alloc] init];
[servers addICEServer:@"$STUNSERVER1$"];
[[SMConfiguration getInstance] setICEServers:servers];
// or
SMICEServers *servers = [[SMConfiguration getInstance] SMICEServers];
[servers addICEServer:@"$STUNSERVER1$"];
```

#### ** Swift Code **

```swift
var servers = SMIceServers()
servers.addICEServer("$STUNSERVER1$")
SMConfiguration.getInstance().iceServers = servers
// or
SMConfiguration.getInstance().iceServers?.addICEServer("$STUNSERVER1$")
```
<!-- tabs:end -->

<div class="page-break"></div>

###### Example: Add a TURN server

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMICEServers *servers = [[SMConfiguration getInstance] SMICEServers];
//to use UDP transport
[servers addICEServer:@"$TURNSERVER1$" username:@"username" password:@"password"];
//to use TCP transport
[servers addICEServer:@"$TURNSERVER2$" username:@"username" password:@"password"];
//to use TLS transport
[servers addICEServer:@"$TURNSERVER2$" username:@"username" password:@"password"];
```

#### ** Swift Code **

```swift
var servers = SMConfiguration.getInstance().iceServers
//to use UDP transport
servers.addICEServer("$TURNSERVER1$", username: "username" password: "password")
//to use TCP transport
servers.addICEServer("$TURNSERVER2$", username: "username" password: "password")
//to use TLS transport
servers.addICEServer("$TURNSERVER2$", username: "username" password: "password")
```
<!-- tabs:end -->

###### Example: Get the server(s)

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMICEServers *iceServers = [[SMConfiguration getInstance] SMICEServers];

//credentials may also be updated directly
NSArray  *serversArray = [iceServers servers];
NSString *urlOfFirst  = serversArray.firstObject.url;
NSString *userOfFirst = serversArray.firstObject.username;
NSString *passOfFirst = serversArray.firstObject.password;
```

#### ** Swift Code **

```swift
var iceServers = SMConfiguration.getInstance().iceServers!

//credentials may also be updated directly
let serversArray = iceServers.servers()
let urlOfFirst  = serversArray.first?.url
let userOfFirst = serversArray.first?.username
let passOfFirst = serversArray.first?.password
```
<!-- tabs:end -->

If a server URL is entered multiple times, the last username and password will be used for the specified server. To remove a server, you must dispose the existing one and create a new instance, defining necessary servers again.

<div class="page-break"></div>

#### Make an outgoing call

Use the `createOutgoingCall` functionality to place audio only or audio/video calls. The MobileSDK also supports establishing calls with only one m line (audio only) or with two m lines (audio and video or one sendrecv/sendonly audio and one recvonly video m line). The number of m lines in the response should match the number of m lines in the initial offer.

###### Example: Establishing an outgoing call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) callExample
{
    SMUriAddress *calleeAddress = [[SMUriAddress alloc] initWithPrimaryContact:@"user@domain"];
    UIView * localVideoView;  //make an assignment
    UIView * remoteVideoView; //make an assignment

    [[[SMServiceProvider getInstance] getCallService] createOutGoingCall:self
              andTerminator:calleeAddress
              completion:^(id<SMOutgoingCallDelegate> call, SMMobileError *error) {
        [call setLocalVideoView:self.localView];
        [call setRemoteVideoView:self.remoteView];
        //To create an audio and video call:
        [call establishCall:YES];
        //OR To create audio only call with two m lines which can be
        //answered with video directly, use:
        [call establishCall:NO];
        //OR To create an audio only call with only one m line, use:
        [call establishAudioCall];
    }];
}

// protocol SMCallApplicationDelegate must be conformed by classes which use the call service.
//  this class implements the protocol SMCallApplicationDelegate
- (void) establishCallSucceeded:(id<SMOutgoingCallDelegate>) call
{
    //called when establish call process succeeds
}

- (void) establishCallFailed:(id<SMOutgoingCallDelegate>) call withError:(SMMobileError *) error
{
    //called when establish call process fails
}
```

#### ** Swift Code **

```swift
func callExample() {
    let calleeAddress = SMUriAddress(username: "user", withDomain: "domain")
    var localVideoView: UIView!  //make an assignment
    var remoteVideoView: UIView! //make an assignment

    SMServiceProvider.getInstance().getCallService().createOutGoingCall(self,
                                    andTerminator: calleeAddress) { (call, error) in
        call.localVideoView = localView
        call.remoteVideoView = remoteView
        //To create an audio and video call:
        call.establishCall(true)
        //OR To create audio only call with two m lines which can be
        //answered directly, use:
        call.establishCall(false)
        //OR To create an audio only call with only one m line, use:
        call.establishAudioCall()
    }
}

// protocol SMCallApplicationDelegate must be conformed by classes which use the call service.
//  this class implements the protocol SMCallApplicationDelegate
func establishCallSucceeded(_ call: SMOutgoingCallDelegate) {
    //called when establish call process succeeds
}

func establishCallFailed(_ call: SMOutgoingCallDelegate, withError error: SMMobileError) {
    //called when establish call process fails
}
```
<!-- tabs:end -->

#### Receive an incoming call

When incoming call received from SPiDR/Kandy Link, `SMCallApplicationDelegate` will be notified via `incomingCall` method. Incoming call can be accepted, rejected, ignored or forwarded to another user. When call is ignored, delegate will not be notified about that call anymore. If incoming call will be accepted, `localVideoView` and `remoteVideoView` should be assigned to related views.

<div class="page-break"></div>

###### Example: Accepting incoming call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface CallController () <SMCallApplicationDelegate>
@end

@implementation CallController

//prepare UI elements
UIView * localVideoView;
UIView * remoteVideoView;

//method implementation based on SMCallApplicationDelegate protocol
//called when an incoming call notification (type = call) is received
- (void) incomingCall:(id<SMIncomingCallDelegate>)call {
    //assign UI elements
    [call setLocalVideoView:localVideoView];
    [call setRemoteVideoView:remoteVideoView];

    //If you want to check if the call has a video m line:
    if([call canReceiveVideo]) {
        //If call has video m line and you want to answer with video:
        [call acceptCall:YES];
        //OR if you want to answer with audio only:
        [call acceptCall:NO];
    } else {
        //If call has only one m line, the call will be answered with audio only
        [call acceptCall:NO];
    }
}

- (void) acceptCallSucceed:(id<SMIncomingCallDelegate>)call
{
    //called when establish call process succeeds
}

- (void) acceptCallFailed:(id<SMIncomingCallDelegate>)call withError:(SMMobileError *)error
{
    //called when establish call process fails
}
@end
```

#### ** Swift Code **

```swift
import MobileSDK

class CallController: NSObject, SMCallApplicationDelegate {

    //prepare UI elements
    var localVideoView: UIView!
    var remoteVideoView: UIView!

    //method implementation based on SMCallApplicationDelegate protocol
    //called when an incoming call notification (type = call) is received
    func incomingCall(_ call: SMIncomingCallDelegate) {
        //assign UI elements
        call.localVideoView = self.localVideoView
        call.remoteVideoView = self.remoteVideoView

        //If you want to check if the call has a video m line:
        if call.canReceiveVideo() {
            //If call has video m line and you want to answer with video:
            call.acceptCall(true)
        //OR if you want to answer with audio only:
            call.acceptCall(false)
        } else {
            //If call has only one m line, the call will be answered with audio only
            call.acceptCall(false)
        }
    }

    func acceptCallSucceed(_ call: SMCallDelegate) {
        //called when establish call process succeeds
    }

    func acceptCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
        //called when establish call process fails
    }
}
```
<!-- tabs:end -->

<div class="page-break"></div>

###### Example: Rejecting and ignoring the incoming call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface CallController () <SMCallApplicationDelegate>
@end

@implementation CallController

//method implementation based on SMCallApplicationDelegate protocol
//called when an incoming call notification (type = call) is received
- (void) incomingCall:(id<SMIncomingCallDelegate>)call {
    // To reject the call
    [call rejectCall];

    // To ignore the call
    [call ignoreCall];
}

- (void) rejectCallSucceed:(id<SMIncomingCallDelegate>)call
{
    //called when reject call succeeds
}

- (void) rejectCallFailed:(id<SMIncomingCallDelegate>)call withError:(SMMobileError *)error
{
    //called when reject call fails
}

- (void) ignoreCallSucceed:(id<SMIncomingCallDelegate>)call
{
    //called when ignore call succeeds
}

- (void) ignoreCallFailed:(id<SMIncomingCallDelegate>)call withError:(SMMobileError *)error
{
    //called when ignore call fails
}
@end
```

#### ** Swift Code **

```swift
import MobileSDK

class CallController: NSObject, SMCallApplicationDelegate {

    //method implementation based on SMCallApplicationDelegate protocol
    //called when an incoming call notification (type = call) is received
    func incomingCall(_ call: SMIncomingCallDelegate) {
        // To reject the call
        call.rejectCall()

        // To ignore the call
        call.ignoreCall()
    }

    func rejectCallSucceed(_ call: SMCallDelegate) {
        //called when reject call succeeds
    }

    func rejectCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
        //called when reject call fails
    }

    func ignoreCallSucceed(_ call: SMCallDelegate) {
        //called when ignore call succeeds
    }

    func ignoreCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
        //called when ignore call fails
    }
}
```
<!-- tabs:end -->

###### Example: Forwarding the incoming call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface CallController () <SMCallApplicationDelegate>
@end

@implementation CallController

//method implementation based on SMCallApplicationDelegate protocol
//called when an incoming call notification (type = call) is received
- (void) incomingCall:(id<SMIncomingCallDelegate>)call {

    // To forward the call

    SMUriAddress *newAddress = [[SMUriAddress alloc] initWithUsername:@"username" withDomain:@"domain"];
    [call forwardCall:newAddress];
}

- (void) forwardCallSucceed:(id<SMIncomingCallDelegate>)call
{
    //called when forward call succeeds
}

- (void) forwardCallFailed:(id<SMIncomingCallDelegate>)call withError:(SMMobileError *)error
{
    //called when forward call fails
}
@end
```

#### ** Swift Code **

```swift
import MobileSDK

class CallController: NSObject, SMCallApplicationDelegate {

    //method implementation based on SMCallApplicationDelegate protocol
    //called when an incoming call notification (type = call) is received
    func incomingCall(_ call: SMIncomingCallDelegate) {

        // To forward the call

        let newAddress = SMUriAddress(username: "username", withDomain: "domain")
        call.forwardCall(newAddress)

    }

    func forwardCallSucceed(_ call: SMCallDelegate) {
        //called when forward call succeeds
    }

    func forwardCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
        //called when forward call fails
    }

}
```
<!-- tabs:end -->

#### End the call

Use the End Call functionality to stop the current call. Call can be ended with or without reason.

**Note:**  End Call is applicable to established or answered incoming/outgoing calls and to outgoing calls which are in ringing state. To end the incoming call when ringing state, use `rejectCall`.

<div class="page-break"></div>

###### Example: Ending a call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) endCallExample {
    [call endCall]; //ends the call without reason
    //the result of the endCall operation will be delivered by call back methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) endCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"End Call succeeded");
}

- (void) endCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"End Call  failed");
}
```

#### ** Swift Code **

```swift
func endCallExample() {
    call.endCall() //ends the call without reason
    //the result of the endCall operation will be delivered by call back methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func endCallSucceeded(_ call: SMCallDelegate) {
    NSLog("End Call succeeded")
}

func endCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("End Call failed")
}
```
<!-- tabs:end -->

#### End call with reason

Applications can use the `endCallWithReason` API to send the end call reason to SPiDR/Kandy Link, then SPiDR/Kandy Link will send message with the reason to the remote user. The remote user gets the reason using the `callStatusChanged` API.
If the call end reason string length exceeds the character limitation defined in SPiDR/Kandy Link Core, then SPiDR/Kandy Link Core will not send the excess characters.

<div class="page-break"></div>

###### Example: End call with reason

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
[call endCallWithReason: @"Example end reason"]; // ends the call with reason
```

#### ** Swift Code **

```swift
call.endCall(withReason: "Reason") // ends the call with reason
```
<!-- tabs:end -->

###### Example: Receiving end call notification with reason

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
// When remote peer ends the call, the SDK informs the application with callback
- (void) callStatusChanged:(id<SMCallDelegate>) call withState: (SMCallState *) callState
{
    if(callState.type == ENDED)
    {
        NSLog(@"Remote peer ended the call");
        NSLog(@"%@", (callState.reason) ? callState.reason : "Reason not provided")
        // Perform required actions when remote peer ends the call.
    }
}
```

#### ** Swift Code **

```swift
// When remote peer ends the call, the SDK informs the application with callback
func callStatusChanged(_ call: SMCallDelegate, with callState: SMCallState) {
    if(callState.type == .ended) {
        NSLog("Remote peer ended the call")
        NSLog("\((callState.reason != nil) ? callState.reason : "Reason not provided")")
        // Perform required actions when remote peer ends the call.
    }
}
```
<!-- tabs:end -->

#### Supported call end reasons

When an endCall notification is received from SPiDR/Kandy Link, the Mobile SDK forwards the status code (statusCode) and status reason (reasonText) to the application layer, informing the user why the call has ended.

Mobile SDK-specific status codes and reasons sent to the application layer include:

```
("reason":"Reason not provided","statusCode":"9900")
("reason":"Ended by local user","statusCode":"9901")
```

"Reason not provided" (9900) returns in two situations:

* When endCall notification does not provide reasonText and/or statusCode information in sessionParams.
* When an unhandled notification like Ringing or Dialing is received.

The following Mobile SDK-call specific status codes are mapped to CALLSTATES_ENDED in SMCallState.h:

| statusCode | Definition               | Description                           |
|------------|--------------------------|---------------------------------------|
| 9900       | STATUS_CODE_NOT_PROVIDED | Remote party ended the call normally  |
| 9901       | ENDED_BY_LOCAL           | Local user ended the call normally    |
| 9902       | REJECTED_BY_LOCAL           | Local user rejected the call    |
| 9903       | IGNORED_BY_LOCAL           | Local user ignored the call    |
| 9904       | RESPONDED_FROM_ANOTHER_DEVICE           | Call answered from another device    |
| 9905       | SESSION_COMPLETED           | Transfer completed, transferer left the call    |
| 9906       | ENDED_BY_ERROR           | Call ended due to error    |
| 9907       | ENDED_BY_UNREGISTER           | Call ended due to unregistration    |
| 9908       | CALL_FORWARDED           | Local user forwarded the call    |

Other SIP-specific sessionParam statusCode values mapped to CALLSTATES_ENDED (e.g. statusCode 480, equivalent to previous NOT_AVAILABLE) are forwarded directly to the application layer.

<div class="page-break"></div>

##### SMCallState class fields

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
@property (nonatomic, readonly) SMCallStates type;
@property (strong, nonatomic, readonly) NSString *reason;
@property (nonatomic, readonly)  NSInteger statusCode;
```

#### ** Swift Code **

```swift
open var type: SMCallStates { get }
open var reason: String! { get }
open var statusCode: Int { get }
```
<!-- tabs:end -->

<div class="page-break"></div>

###### Example: Getting call end reason

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) callStatusChanged:(id<SMCallDelegate>) call withState: (SMCallState *) callState;
{
    switch (callState.type)
    {
    case CALLSTATES_ENDED:
        NSLog(@"Call is ended because of reason %@ with code %d"
        , callState.reason, callState.statusCode);
        switch (callState.statusCode)
        {
        case 404:
            NSLog(@"Callee does not exist");
            break;
        case 480:
            NSLog(@"Callee is offline");
            break;
        case 487:
            NSLog(@"Callee did not answer");
            break;
        case 603:
            NSLog(@"Callee rejected the call");
            break;
        case STATUS_CODE_NOT_PROVIDED:
            NSLog(@"Call end reason is not provided");
            break;
        case ENDED_BY_LOCAL:
            NSLog(@"Caller ended the call normally");
            break;
        default:
            break;
        }
        break;
    case CALLSTATES_IN_CALL:
        NSLog(@"Call establishment is successful");
        break;
    case CALLSTATES_RINGING:
        NSLog(@"Callee is ringing now");
        break;
    default:
        break;
    }
}
```

#### ** Swift Code **

```swift
func callStatusChanged(_ call: SMCallDelegate, with callState: SMCallState) {
    switch (callState.type) {
    case .ended:
        NSLog("Call is ended because of reason \(callState.reason) with code \(callState.statusCode)")
        switch (callState.statusCode) {
        case 404:
            NSLog("Callee does not exist")
        case 480:
            NSLog("Callee is offline")
        case 487:
            NSLog("Callee did not answer")
        case 603:
            NSLog("Callee rejected the call")
        case Int(STATUS_CODE_NOT_PROVIDED):
            NSLog("Call end reason is not provided")
        case Int(ENDED_BY_LOCAL):
            NSLog("Caller ended the call normally")
        default:
            break
    }
    case .inCall:
        NSLog("Call establishment is successful")
    case .ringing:
        NSLog("Callee is ringing now")
    default:
        break
    }
}
```
<!-- tabs:end -->

#### Get active call list

Use the following API to get a pointer to the list of active call objects (i.e. `id<CallDelegate>`). Any changes in the call objects affect objects of the returned list.

###### Example: Getting active calls

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
@protocol SMCallServiceDelegate <NSObject>

- (NSArray *) getActiveCalls;
NSArray *callList = [[[SMServiceProvider getInstance]getCallService]getActiveCalls];
```

#### ** Swift Code **

```swift
let callList = SMServiceProvider.getInstance().getCallService().getActiveCalls()
```
<!-- tabs:end -->

#### Mid-Call operations

While in the established or accepted call, mid-call operations can be called such as Mute-Unmute/Hold-Unhold/Video Start-Stop, Adhoc conference/3­-way call and transfer operations.

See [Appendix B: Call state transitions](#appendix-b-call-state-transitions), for which operations are allowed respect to state of the call.

<div class="page-break"></div>

##### Mute/Unmute Call

To stop sending audio from the microphone, mute method can be called. Until unmuting the call, participants cannot hear the voice from the device.

###### Example: Mute/unmute the call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) muteUnmuteExample
{
    [call mute]; //mutes the call
    [call unMute]; //Unmutes the call
    //the result of the mute/unmute operations will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) muteCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Mute succeeded");
}

- (void) muteCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Mute failed");
}

- (void) unMuteCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Unmute succeeded");
}

- (void) unMuteCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Unmute failed");
}
```

#### ** Swift Code **

```swift
func muteUnmuteExample() {
    call.mute() //mutes the call
    call.unMute() //Unmutes the call
    //the result of the mute/unmute operations will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func muteCallSucceed(_ call: SMCallDelegate) {
    NSLog("Mute succeeded")
}

func muteCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Mute failed")
}

func unMuteCallSucceed(_ call: SMCallDelegate) {
    NSLog("Unmute succeeded")
}

func unMuteCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Unmute failed")
}
```
<!-- tabs:end -->

<div class="page-break"></div>

##### Video Start/Stop on a Call

To start/stop sending video from the camera, video start/stop method can be called. Note that, these operations take some time, thus listening operation results from `SMCallApplicationDelegate`, and acting accordingly is recommended.

###### Example: Video Start/Stop

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) videoStartStopExample
{
    [call videoStart]; //Starts the video stream of the local peer
    [call videoStop]; //Stops the video stream of the local peer
    //the result will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) videoStartSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Video Start succeeded");
}

- (void) videoStartFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Video Start failed");
}

- (void) videoStopSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Video Stop succeeded");
}

- (void) videoStopFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Video Stop failed");
}
```

#### ** Swift Code **

```swift
func videoStartStopExample() {
    call.videoStart() //Starts the video stream of the local peer
    call.videoStop() //Stops the video stream of the local peer
    //the result will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func videoStartSucceeded(_ call: SMCallDelegate) {
    NSLog("Video Start succeeded")
}

func videoStartFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Video Start failed")
}

func videoStopSucceeded(_ call: SMCallDelegate) {
    NSLog("Video Stop succeeded")
}

func videoStopFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Video Stop failed")
}
```
<!-- tabs:end -->

<div class="page-break"></div>

##### Video mute/UnMute Call

Video Mute API disables the video track in a video call and stops sending the video frame to the remote side. A black screen appears instead of a local video view until the video track is enabled again using the video unMute API.

###### Example: Video mute/UnMute the call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) videoMuteUnMuteExample
{
    [call videoUnMute]; //unMute the video track 
    [call videoMute]; //mute the video track 
    //the result of the mute/unMute operations will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) videoUnMuteSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Video unMute succeeded");
}

- (void) videoUnMuteFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Video unMute failed");
}

- (void) videoMuteSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Video Mute succeeded");
}

- (void) videoMuteFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Video Mute failed");
}
```

#### ** Swift Code **

```swift
func videoMuteUnMuteExample() {
    call.videoUnMute() //unMute the video track  
    call.videoMute() //mute the video track  the call
    //the result of the mute/unMute operations will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func videoUnMuteSucceed(_ call: SMCallDelegate) {
    NSLog("Video unMute succeeded")
}

func videoUnMuteFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Video unMute failed")
}

func videoMuteSucceed(_ call: SMCallDelegate) {
    NSLog("Video Mute succeeded")
}

func videoMuteFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Video Mute failed")
}
```
<!-- tabs:end -->

<div class="page-break"></div>

##### Hold/Unhold Call and Double Hold

While in a call, a participant may be placed on hold by calling `holdCall` method. When operation succeeds, media transfer between participants stops, and call state will change to `ON_HOLD` state. Remote participant will see this call session in `REMOTELY_HELD` state.

To resume to the call, `unholdCall` method should be called. Note that, these operations take some time, thus listening operation results from `SMCallApplicationDelegate`, and acting accordingly is recommended.

Users may also place one another on hold at the same time (Double Hold). The following scenario illustrates a double hold with call states in parenthesis:
1. User A and User B are in an active call (`IN_CALL`).
2. A places B on hold (A is `ON_HOLD`, B is `REMOTELY_HELD`).
3. B places A on hold (`ON_DOUBLE_HOLD`).
4. A retrieves the call (A is `REMOTELY_HELD`, B is `ON_HOLD`).
5. B retrieves the call, and A and B are in an active call again (`IN_CALL`).
For more information about call states, see [Appendix B: Call state transitions](#appendix-b-call-state-transitions).

<div class="page-break"></div>

###### Example: Hold/unhold the call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) holdUnholdExample
{
    [call hold]; //holds the call
    // If call in REMOTELY_HELD state, will be ON_DOUBLE_HOLD

    [call unHold]; //unholds the call
    //the result will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) holdCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Hold succeeded");
}

- (void) holdCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Hold failed");
}

- (void) unHoldCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Unhold succeeded");
}

- (void) unHoldCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Unhold failed");
}
```

#### ** Swift Code **

```swift
func holdUnholdExample() {
    call.hold() //Holds the call
    // If call in remotelyHeld state, will be onDoubleHold

    call.unHold() //Unholds the call
    //the result will be delivered by callback methods
}

//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func holdCallSucceed(_ call: SMCallDelegate) {
    NSLog("Hold succeeded")
}

func holdCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Hold failed")
}

func unHoldCallSucceed(_ call: SMCallDelegate) {
    NSLog("UnHold succeeded")
}

func unHoldCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("UnHold failed")
}
```
<!-- tabs:end -->

<div class="page-break"></div>

###### Example: Hold/unhold callback information

When remote peer holds the call, call status will be changed accordingly.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
- (void) callStatusChanged:(id<SMCallDelegate>) call withState: (SMCallState *) callState;
{
    if(callState == REMOTELY_HELD)
    {
        NSLog(@"Remote peer held the call");
        // Perform required actions when remote peer hold the call.
    }
    // If previous state was REMOTELY_HELD and changed to IN_CALL
    else if(callState == IN_CALL)
    {
        NSLog(@"Remote peer unheld the call");
        // Perform required actions when remote peer unholds the call.
    } else if (callState == ON_DOUBLE_HOLD)
    {
        NSLog(@"Both parties are in hold state");
    }
}
```

#### ** Swift Code **

```swift
//current class implements SMCallApplicationDelegate protocol
//current class instance is used as call application delegate in call service
func callStatusChanged(_ call: SMCallDelegate, with callState: SMCallState) {
    if(callState.type == .remotelyHeld) {
        NSLog("Remote peer held the call")
        // Perform required actions when remote peer hold the call.
    }
    // If previous state was REMOTELY_HELD and changed to IN_CALL
    else if(callState.type == .inCall) {
        NSLog("Remote peer unheld the call")
        // Perform required actions when remote peer unholds the call.
    }
    else if (callState.type == .onDoubleHold) {
        NSLog("Both parties are in hold state")
    }
}
```
<!-- tabs:end -->

##### Adhoc conference/3-way call

Two different calls can be combined into a three-way call (ad-hoc conference). Each user's video and audio is combined as a single stream through a media server. When the three users are on the newly created call, the two previous calls end. Users must be subscribed to the Call service during registration to use this feature.

###### Example: Merging two calls into Adhoc Conferencing/3-way call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) threeWayCallExample :(id<SMCallDelegate>)call1 withCall:(id<SMCallDelegate>)call2
{
    //both calls (call1 and call2) should be on HOLD state before the join operation

    [[[SMServiceProvider getInstance] getCallService] createThreeWayCall:self
                                                             firstCallId:[call1 getCallId]
                                                            secondCallId:[call2 getCallId]
                                                              completion:^(id<SMOutgoingCallDelegate> mergedCall, SMMobileError *error)
        {
            if(error)
                NSLog(@"Error occurred");
            else {
                // Three-way call created successfully
                [mergedCall establishAudioCall];
                //the result of the operation will be delivered by call back methods
        }
    }];
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
- (void) joinSucceeded:(id<SMCallDelegate>)call
{
    NSLog(@"Join successful");
}

- (void) joinFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Join failed");
}

```

#### ** Swift Code **

```swift
func threeWayCallExample(call1: SMCallDelegate, call2: SMCallDelegate) {
    //both calls (call1 and call2) should be on HOLD state before the join operation

    SMServiceProver.getInstance().getCallService().createThreeWayCall(self, firstCallId: call1.getCallId(),
                                                                      secondCallId: call2.getCallId()) { (mergedCall, error) in
        if error != nil {
            NSLog("Error occurred")
        } else {
            // Three-way call created successfully
            mergedCall!.establishAudioCall()
            //the result of the operation will be delivered by call back methods
        }

    }
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
func joinSucceeded(_ call: SMCallDelegate) {
    NSLog("Join successful")
}

func joinFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Join failed")
}
```
<!-- tabs:end -->

##### Blind transfer

Use the `transferCall` method to initiate a blind transfer to another user. If a call is in an `In Call` state, the Mobile SDK will first hold the call, then send a transfer request to the server. Calls may also be transferred if they are in `Hold`, `Remotely held`, or `Double hold` call states.
The Mobile SDK does not have any configuration for the transfer call media type; it is determined by the server. For example, audio-only calls will continue as audio-only, but the server will decide whether transferred video calls continue as audio+video or audio-only.
The Mobile SDK will provide a callback to the application layer to advise whether the transfer succeeded or failed. The party who initiated the transfer exits from the call when the transfer is complete.

When call is transferred, transfferer will leave the call.

<div class="page-break"></div>

###### Example: Blind transfer

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) blindTransferExample :(id<SMCallDelegate>)call
{
    SMUriAddress *newAddress = [[SMUriAddress alloc] initWithUsername:@"username" withDomain:@"domain"];
    [call transferCall:newAddress];
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
- (void) transferCallSucceed:(id<SMCallDelegate>)call
{
    NSLog(@"Transfer successful");
}

- (void) transferCallFailed:(id<SMCallDelegate>)call withError:(SMMobileError *) error
{
    NSLog(@"Transfer failed");
}

```

#### ** Swift Code **

```swift
func blindTransferExample(call: SMCallDelegate) {
    let newAddress = SMUriAddress(username: "username", withDomain: "domain")
    call.transferCall(newAddress)
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
func transferCallSucceed(_ call: SMCallDelegate) {
    NSLog("Transfer successful")
}

func transferCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Transfer failed")
}
```
<!-- tabs:end -->

When the transfer target receives the call notification, they may use the getCallerAddress method to receive the name of the person being transferred to them. Once the transfer target accepts the call, the transferee may use the getCalleeAddress method to get the name of the person to whom they were transferred.

##### Consultative Transfer

Use `consultativeTransfer` method for transferring current call to the transfer target given with another call session in a consultative transfer manner. Transferrer should be participant of both calls in order to make consultative transfer.

When call is transferred, transferrer will leave the calls.

###### Example: Consultative transfer

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) consultativeTransferExample :(id<SMCallDelegate>)call withTarget:(id<SMCallDelegate>)target
{
    //both calls (call and target) should be on HOLD state before the transfer operation
    [call consultativeTransfer:target];
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
func transferCallSucceed(_ call: SMCallDelegate) {
    NSLog("Transfer successful")
}

func transferCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Transfer failed")
}
```

#### ** Swift Code **

```swift
func consultativeTransferExample(call: SMCallDelegate, transfer: SMCallDelegate) {
    //both calls (call and target) should be on HOLD state before the join operation
    call.consultativeTransfer(transfer)
}

// protocol SMCallApplicationDelegate must be conformed by classes which uses the call service.
//  this class implements the protocol SMCallApplicationDelegate
func transferCallSucceed(_ call: SMCallDelegate) {
    NSLog("Transfer successful")
}

func transferCallFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Transfer failed")
}
```
<!-- tabs:end -->

#### Available Codecs

To get available codec list, getAvailableCodecs method can be called. The codec type can be customized with a parameter to the getAvailableCodecs method. But only Video type is allowed for now.

<!-- tabs:start -->

#### ** Swift Code **

```swift

call.getAvailableCodecs(SMCodecType.videoCodec)
```

#### ** Objective-C Code **

```objectivec

[call getAvailableCodecs:VIDEO_CODEC];
```
<!-- tabs:end -->

#### Change default camera position (front or back)

New calls are started using the default camera device (front or back). The default is set to the front camera (AVCaptureDevicePositionFront), however, you can also change the default for new calls.

Call the SMConfiguration class with property "cameraPosition" to change the default camera device. "cameraPosition" uses the enum values provided in the iOS AVCaptureDevice class. The available cameraPosition values include:

* AVCaptureDevicePositionUnspecified = 0
* AVCaptureDevicePositionBack = 1
* AVCaptureDevicePositionFront = 2

###### Example: Change camera device default

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
// Sets the default camera position mode
// see AVCaptureDevicePosition

@property (nonatomic) AVCaptureDevicePosition cameraPosition;
```

#### ** Swift Code **

```swift
// Sets the default camera position mode
// see AVCaptureDevicePosition

open var cameraPosition: AVCaptureDevice.Position
```
<!-- tabs:end -->

#### Change camera orientation

Smartphones can change the screen view to portrait or landscape based on how the user is holding their device. There are two different video camera orientation settings—device orientation and application orientation—with three different handling options. The three handling options are:


* CAMERA_ORIENTATION_USES_NONE :Local video orientation does not change when the user rotates their device.Only the displayed video changes towards the camera.After the video call establish if the camera is in a vertical(portrait) angle, the local video orientation will be in a vertical position, and if the camera is in a horizontal(landscape) angle, the local video orientation will be in a horizontal position and local video orientation will no longer change.

* CAMERA_ORIENTATION_USES_DEVICE : Only Local video view orientation changes when the user rotates their device , remote video orientation doesn't change on the device used.

* CAMERA_ORIENTATION_USES_STATUS_BAR : Local and Remote video views orientation change according to the application interface orientation.With this option,UIApplicationInterface will force video view orientation according to status bar position.

**Note:** The default option is set to `CAMERA_ORIENTATION_USES_DEVICE:`.
 
To change local video view orientation manually, call rotateCameraOrientationToPosition. The following values are supported:

* UIDeviceOrientationPortrait
* UIDeviceOrientationPortraitUpsideDown
* UIDeviceOrientationLandscapeLeft
* UIDeviceOrientationLandscapeRight

<div class="page-break"></div>

###### Example: Configure camera orientation for incoming and outgoing video

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
@implementation CallViewController

// configuration can be changed any time before starting call
- (void)viewDidLoad
{
    [super viewDidLoad];
    [SMConfiguration getInstance].orientationMode = CAMERA_ORIENTATION_USES_DEVICE;
}

// to change camera orientation to landscape mode, you can define a method //like this
- (void)changeOrientationToLanscape
{
    [[[SMServiceProvider getInstance] getCallService]
    rotateCameraWithOrientation:UIDeviceOrientationLandscapeLeft];
}
@end
```

#### ** Swift Code **

```swift
class CallViewController: UIViewController

    // configuration can be changed any time before starting call
    func viewDidLoad() {
        super.viewDidLoad()
        SMConfiguration.getInstance().orientationMode = .device
    }

    // to change camera orientation to landscape mode, you can define a method //like this
    func changeOrientationToLanscape() {
        SMServiceProvider.getInstance().getCallService().rotateCamera(with: UIDeviceOrientation.landscapeLeft)
    }

}
```
<!-- tabs:end -->

#### Change local video resolution or camera position

Users can set local video resolution and switch between front and back cameras at any time during the call; there are no call state constraints. The value of AVCaptureDevicePosition and AVCaptureSessionPreset enums are provided by iOS.

###### Example: Changing video resolution and camera position

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
-(void) changeVideoResolutionAndPosition {

    [currentCall setCaptureDevice:AVCaptureDevicePositionFront
              withVideoResolution:AVCaptureSessionPreset1280x720
                completionHandler:^(SMMobileError *error) {

        if (!error && error.code == ERROR_VALIDATION) {
            NSLog(@"video resolution cannot be set, error explanation : %@"
            , error.description);
        }

        if (!error && error.code == ERROR_CAMERA_ACCESS) {
            NSLog(@"setting capture device position failed, error explanation : %@"
            , error.description);
        }
    }];
}
```

#### ** Swift Code **

```swift
func changeVideoResolutionAndPosition() {

    currentCall.setCaptureDevice(.front, withVideoResolution:AVCaptureSession.Preset.hd1280x720.rawValue) { (error) in
        if (error != nil && error.code == SMErrorTypes.validation.rawValue) {
            NSLog("video resolution cannot be set, error explanation : \(error.description)")
        }

        if (error != nil && error.code == SMErrorTypes.cameraAccess.rawValue) {
            NSLog("setting capture device position failed, error explanation : \(error.description)")
        }
    }
}
```
<!-- tabs:end -->

#### Send DTMF (Dual-Tone Multi-Frequency) signals

The Mobile SDK supports sending Dual-Tone Multi-Frequency (DTMF) signals to an Interactive Voice Response (IVR) system via the SPiDR/Kandy Link Media Broker. This allows callers to enter passcodes on active or ringing calls. Available keys for tones include 0-9, *, #, A, B, C, and D, as outlined in RFC 4733. When remote party does't suport out-of-band DTMF, the API method will return false.

**Note:** This feature only provides the functionality for sending DTMF signals. It does not include the functionality for getting keypad input or for playing key press volume.

##### API definition for sending DTMF

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
@protocol SMCallDelegate <NSObject>

// other method definitions on SMCallDelegate

/**
* @brief Inserts Dual Tone Multi Frequency Signal to sending queue and returns the success
* @param tone character value of DTMF tone. Can only be 0,1...,9,*,#,a,b,c,d,A,B,C,D;
* @return YES if tone can be successfully inserted to queue otherwise NO
* @since 3.0.1
*/
- (BOOL) sendDTMF:(char)tone;

// other method definitions on SMCallDelegate

@end
```

#### ** Swift Code **

```swift
protocol SMCallDelegate: NSObjectProtocol {

// other method definitions on SMCallDelegate

/**
* @brief Inserts Dual Tone Multi Frequency Signal to sending queue and returns the success
* @param tone character value of DTMF tone. Can only be 0,1...,9,*,#,a,b,c,d,A,B,C,D;
* @return YES if tone can be successfully inserted to queue otherwise NO
* @since 3.0.1
*/
public func sendDTMF(_ tone: Int8) -> Bool

// other method definitions on SMCallDelegate

}
```
<!-- tabs:end -->

###### Example: Sending DTMF

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) sendDTMFExampleWithCall: (id<SMCallDelegate>) call andTone: (char) tone {
    [call sendDTMF:tone];
}
```

#### ** Swift Code **

```swift
func sendDTMFExampleWithCall(call: SMCallDelegate, andTone: String) {
// Convert String to UTF8, then signed 8-bit integer
    if let key = andTone.utf8.first {
        call.sendDTMF(Int8(key))
    }
}
```
<!-- tabs:end -->

#### Get media attributes

The application is notified of audio/video state, capture device position, and aspect ratio changes by the mediaAttributesChanged method. The getMediaAttributes method is used to retrieve the current media attributes. The following shows an example using the getMediaAttributes method and an example notification following an aspect ratio change.

**Note:** As of release 4.0.1, the MediaState class is renamed as MediaAttributes, and the mediaStateChanged method is renamed as mediaAttributesChanged.

###### Example: Using the getMediaAttributes method

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMMediaAttributes *currentMediaAttributes = [call getMediaAttributes];
BOOL localVideo = currentMediaAttributes.localVideo;
BOOL localAudio = currentMediaAttributes.localAudio;
BOOL remoteVideo = currentMediaAttributes.remoteVideo;
float remoteVideoAspectRatio = currentMediaAttributes.remoteVideoAspectRatio;
float localVideoAspectRatio = currentMediaAttributes.localVideoAspectRatio;
```
#### ** Swift Code **

```swift
let currentMediaAttributes = call.getMediaAttributes()
let localVideo = currentMediaAttributes.localVideo
let localAudio = currentMediaAttributes.localAudio
let remoteVideo = currentMediaAttributes.remoteVideo
let remoteVideoAspectRatio = currentMediaAttributes.remoteVideoAspectRatio
let localVideoAspectRatio = currentMediaAttributes.localVideoAspectRatio
```
<!-- tabs:end -->

###### Example: Getting remote and local aspect ratios

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) mediaAttributesChanged:(id<SMCallDelegate>)call withMediaAttributes:(SMMediaAttributes *)mediaAttributes
{
    float remoteVideoAspectRatio = mediaAttributes.remoteVideoAspectRatio;
    float localVideoAspectRatio = mediaAttributes.localVideoAspectRatio;
}
```

#### ** Swift Code **

```swift
func mediaAttributesChanged(_ call: SMCallDelegate, with mediaAttributes: SMMediaAttributes) {
    let remoteVideoAspectRatio = mediaAttributes.remoteVideoAspectRatio
    let localVideoAspectRatio = mediaAttributes.localVideoAspectRatio
}
```
<!-- tabs:end -->

The aspect ratio value is provided as the width/height of the video. For example, if the video resolution is:

* 360x640 (9:16), the aspect ratio will be 0.56
* 480x640 (3:4), the aspect ratio will be 0.75

**Note:** If the application does not provide any view to the MobileSDK, the MobileSDK will not provide any aspect ratio notification to the application.

<div class="page-break"></div>

### Advanced Usage of Call Service

#### Configure audio session

iOS applications use an instance of the AVAudioSession class for audio-related operations, determining how the application will behave with relation to audio; for example, whether your application will silence audio when the screen locks or whether audio will continue playing. Since the instance is a singleton object that sets the audio context for the application, every object in the application uses the same instance for audio changes.

The SMConfiguration class has a new variable called "audioSessionConfiguration", which is an object of the SMAudioSessionConfiguration class. You must set audioSessionConfiguration to ensure WebRTC does not override your requested audio session configuration.

**Note:** WebRTC reverts to its default audio session configuration when the call state is "on_hold" or "ended", but WebRTC will reapply your preferred configuration when the call state changes from "on_hold" to "in_call" or when you start a new call.

The SMAudioSessionConfiguration class contains three properties used to define the behaviors: Mode, Category, and Category Options. The default values for all properties are nil, which means that if values are not set, WebRTC will use its default audio session configuration. Invalid values for these properties may cause issues for the WebRTC audio session. The list that follows contains the acceptable values for each property. Refer to the Apple developer documentation for AVAudioSession for more information about the values.

**Mode:**

* AVAudioSessionModeDefault
* AVAudioSessionModeVoiceChat
* AVAudioSessionModeGameChat
* AVAudioSessionModeVideoRecording
* AVAudioSessionModeMeasurement
* AVAudioSessionModeMoviePlayback
* AVAudioSessionModeVideoChat
* AVAudioSessionModeSpokenAudio

**Category:**

* AVAudioSessionCategoryAmbient
* AVAudioSessionCategorySoloAmbient
* AVAudioSessionCategoryPlayback
* AVAudioSessionCategoryRecord
* AVAudioSessionCategoryPlayAndRecord
* AVAudioSessionCategoryAudioProcessing
* AVAudioSessionCategoryMultiRoute

**Category Options:**

* AVAudioSessionCategoryOptionMixWithOthers
* AVAudioSessionCategoryOptionDuckOthers
* AVAudioSessionCategoryOptionAllowBluetooth
* AVAudioSessionCategoryOptionDefaultToSpeaker
* AVAudioSessionCategoryOptionInterruptSpokenAudioAndMixWithOthers

The following example shows configuring and setting the audio session for a video call using the default speaker. Set the audio session before creating the call.

**Note**: For voice calls, recommended Audio Session Mode is `AVAudioSessionModeVoiceChat`, and `AVAudioSessionModeVideoChat` for video calls.

**Advice**: In order to not have a problem with AudioSession, we recommend to implement AudioSessionConfiguration into the `reportNewIncomingCall` function for CallKit integration.

###### Example: Configuring and setting the audio session

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMAudioSessionConfiguration *audioSessionConfig = [[SMAudioSessionConfiguration alloc] init];

audioSessionConfig.mode = AVAudioSessionModeVoiceChat;
audioSessionConfig.category = AVAudioSessionCategoryPlayAndRecord;
audioSessionConfig.categoryOptions = AVAudioSessionCategoryOptionDefaultToSpeaker;

//Set WebRTC audio session configuration
[[SMConfiguration getInstance] setAudioSessionConfiguration:audioSessionConfig];
```

#### ** Swift Code **

```swift
let audioSessionConfig = SMAudioSessionConfiguration()

audioSessionConfig.mode = AVAudioSessionModeVoiceChat
audioSessionConfig.category = AVAudioSessionCategoryPlayAndRecord
audioSessionConfig.categoryOptions = AVAudioSessionCategoryOptions.defaultToSpeaker

//Set WebRTC audio session configuration
SMConfiguration.getInstance().audioSessionConfiguration = audioSessionConfig
```
<!-- tabs:end -->

#### Configure WebRTC audio session

**Note:** Use that configuration only for complex use-cases e.g. CallKit integration, otherwise these configurations shouldn't need to change.

Use the `useManualAudio` and `voipAudioEnabled` properties to set WebRTC audio session configuration. The following describes audio session behavior based on the property values:

* `useManualAudio`

    * **YES:** WebRTC does not automatically initialize the audio unit when an audio track is ready for playout or recording and instead calls `setVoipAudioEnabled`.

    * **NO (Default):** WebRTC initializes the audio unit when an audio track is ready for playout or recording.

* `voipAudioEnabled`

    * **YES:** WebRTC initializes and starts the audio unit when needed (e.g. establishing an audio connection).

    * **NO (Default):** If the audio unit used by WebRTC is active, the MobileSDK stops and uninitializes the audio unit.

**Note:** `voipAudioEnabled` is only effective if `useManualAudio` is YES.

###### Example: Setting WebRTC audio session configuration

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
[[[SMServiceProvider getInstance] getCallService] setUseManualAudio:YES];
[[[SMServiceProvider getInstance] getCallService] setVoipAudioEnabled:YES];
```

#### ** Swift Code **

```swift
SMServiceProvider.getInstance().getCallService().useManualAudio = true
SMServiceProvider.getInstance().getCallService().isVoipAudioEnabled = true
```
<!-- tabs:end -->

#### Send custom parameters for a call

If desired, custom SIP Headers can be send while initiating call and/or during the mid-call events. Parameters should contain key-value pairs that are provisioned by the backend.

###### Example: Sending Custom Parameters while establishing call

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) startCallWithTerminator:(SMUriAddress *)term videoEnabled:(BOOL)videoEnabled
{
    [[[SMServiceProvider getInstance]  getCallService] createOutGoingCall:self
                                                            andTerminator:targetAddress
                                                            completion:^(id<SMOutgoingCallDelegate> call, SMMobileError *error) {

        if (!error) {
            NSDictionary *headers = @{@"key":@"value"};
            [call establishCall:videoEnabled withCustomParameters:headers];
        }
    }];
}
```

#### ** Swift Code **

```swift
func startCallWithTerminator(term: SMUriAddress, videoEnabled:Bool) {
    SMServiceProvider.getInstance().getCallService().createOutGoingCall(self, andTerminator:targetAddress) { (call, error) in
        if error == nil {
            let headers = ["key":"value"]
            call.establishCall(videoEnabled, withCustomParameters:headers)
        }
}
```
<!-- tabs:end -->

###### Example: Setting Custom Parameters during the call

Custom Parameters can be set during the call, and they will send when next mid-call event occurs.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) setParametersToCall:(id<SMOutgoingCallDelegate>)call parameters:(NSDictionary *)customParameters
{
    [call setCustomParameters:parameters];
}
```

#### ** Swift Code **

```swift
func setParametersToCall(call: SMOutgoingCallDelegate, parameters:[String:String]) {
    call.setCustomParameters(parameters)
}
```
<!-- tabs:end -->

###### Example: Sending Custom Parameters during the call

After setting custom parameters, instead of waiting next mid-call event, custom parameters can sent by `sendCustomParameters` method.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) sendParametersToCall:(id<SMOutgoingCallDelegate>)call parameters:(NSDictionary *)customParameters
{
    [call sendCustomParameters:parameters];
}
```

#### ** Swift Code **

```swift
func sendParametersToCall(call: SMOutgoingCallDelegate, parameters:[String:String]) {
    call.sendCustomParameters(parameters)
}
```
<!-- tabs:end -->


###### Example: Receiving Custom Parameters during an incoming call

Custom Parameters can be retrieved and used during incoming call


<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) incomingCall:(id<SMIncomingCallDelegate>)call
{
      NSDictionary *_Nullable sipHeaders = [NSDictionary dictionary];
      sipHeaders = [call getCustomSIPHeaders]; 
}
```

#### ** Swift Code **

```swift
func incomingCall(call: SMIncomingCallDelegate) {
            let sipHeaders : Dictionary<String, String>?
            sipHeaders = call.getCustomSIPHeaders
        }
```

<!-- tabs:end -->

#### Set ICE options

The Configuration class has an "iceOption" attribute used to determine the ICE behavior. The following are the available ICE options:

* ICE_TRICKLE: Trickle ICE completes signaling without waiting for candidate collection. Clients send candidates to one another as they’re discovered (after the call signaling is complete and the call is established). This provides faster call setup times but may cause media delays.

* ICE_VANILLA: The default value. The clients must collect and send all candidates before initializing signaling. This process, in addition to the particular network configuration and the number of interfaces in the clients’ devices, can cause call setup delays.

If the "ICE_TRICKLE" option is selected, the "ICECollectionTimeout" value is not used. If the call ends before all ICE candidates are collected, the MobileSDK does not listen to the TURN/STUN server since the peer connection is closed.

<hr/>
<h5>WARNING</h5>
Both parties must support Trickle ICE; Half Trickle is not supported in this implementation. If one party does not support Trickle ICE, signaling may be completed, but the Vanilla ICE client cannot receive ICE candidates sent by the other party. This state should be handled by the developer either by checking the RTCP statistics or waiting for the user to end the call. The MobileSDK will not end the call.
<hr/>

###### Example: Setting ICE options

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
[[SMConfiguration getInstance] setICEOption : ICE_TRICKLE];
```

#### ** Swift Code **

```swift
SMConfiguration.getInstance().iceOption = .trickle
```
<!-- tabs:end -->

#### Ringing feedback

If the receiving party prefers the information that it has successfully received the call, it can notify the calling party by the `ringingFeedbackOption` method.

Possible values of the ringingFeedbackOption configuration parameter are APP, SERVER and AUTO.

When ringingFeedbackOption is SERVER, SPiDR/Kandy Link sends the Ringing notification to the caller immediately after sending the callStart notification to the callee.

When ringingFeedbackOption is APP, Ringing Feedback is reponsibility of application.

The option selected during registration, cannot be changed after registration.

* APP: The application side should manage the ringing feedback operations

* SERVER: Server based ringing feedback.

* AUTO: Auto ringing feedback mechanism by SDK.

<div class="page-break"></div>

###### Example: Setting ringing feedback feature

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
// The application side should manage the ringing feedback operations
[[SMConfiguration getInstance] setRingingFeedbackOption:APP];
// Server based ringing feedback.
[[SMConfiguration getInstance] setRingingFeedbackOption:SERVER];
// Auto ringing feedback mechanism by SDK.
[[SMConfiguration getInstance] setRingingFeedbackOption:AUTO];
//User can register now
```

#### ** Swift Code **

```swift
// The application side should manage the ringing feedback operations
SMConfiguration.getInstance().ringingFeedbackOption = .app
// Server based ringing feedback.
SMConfiguration.getInstance().ringingFeedbackOption = .server
// Auto ringing feedback mechanism by SDK.
SMConfiguration.getInstance().ringingFeedbackOption = .auto
//User can register now
```
<!-- tabs:end -->

###### Example: Sending ringing feedback

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) incomingCall:(id<SMIncomingCallDelegate>)call
{
    [call sendRingingFeedback];
    // Perform actions related to the incoming call
}

- (void) sendRingingFeedbackSucceed:(id<SMIncomingCallDelegate>)call
{
    NSLog(@"Send ringing feedback succeeded");
}
- (void) sendRingingFeedbackFailed:(id<SMIncomingCallDelegate>)call withError:(SMMobileError *)error{
    NSLog(@"Send ringing feedback failed");
}
```

#### ** Swift Code **

```swift
func incomingCall(_ call: SMIncomingCallDelegate) {
    call.sendRingingFeedback()
}

func sendRingingFeedbackSucceed(_ call: SMCallDelegate) {
    NSLog("Send ringing feedback succeeded")
}

func sendRingingFeedbackFailed(_ call: SMCallDelegate, withError error: SMMobileError) {
    NSLog("Send ringing feedback failed")
}
```
<!-- tabs:end -->

#### Early media

The Mobile SDK supports early media (for example, hearing a ringing tone or an announcement from the network instead of a local ringing tone before a call is established) and transitions to call state SESSION_PROGRESS after receiving the 183 Session Progress notification. See [Appendix B: Call state transitions](#appendix-b-call-state-transitions) for call state diagrams.

<div class="page-break"></div>

###### Example: Call in early media

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMCallStates callState;
…
callState = CALLSTATES_UNKNOWN;
…
- (void) callStatusChanged:(id<SMCallDelegate>) call withState: (SMCallState *) callState;
{
    switch (callState.type)
    {
    case CALLSTATES_SESSION_PROGRESS:
        NSLog(@"Call is in early media state");
        break;
    case CALLSTATES_RINGING:
        if (callState == CALLSTATES_SESSION_PROGRESS)
        {
            NSLog(@"Ignoring ringing state");
            return;
        }
        NSLog(@"Call is in ringing state");
        break;
    …

    default:
        break;
    }
    callState = callState.type;
}
```

#### ** Swift Code **

```swift
var callState: SMCallStates!
…
callState = .unknown
…
func callStatusChanged(_ call: SMCallDelegate, with callState: SMCallState) {
    switch (callState.type) {
    case .sessionProgress:
        NSLog("Call is in early media state")
    case .ringing:
        if (callState == .sessionProgress) {
            NSLog("Ignoring ringing state")
            return
        }
        NSLog("Call is in ringing state")
    …
    default:
        break
    }
}
```
<!-- tabs:end -->

#### Set codec priority

The Configuration class has a variable "preferredCodecSet", which is an instance of the SMCodecSet class. To use only a subset of the available codecs or to change the default priority, the "audioCodecs" and "videoCodecs" arrays of preferredCodecSet must be set. Codecs should be listed in order of priority (i.e. first codec listed is first priority).

If you do not add any codecs to the preferredCodecSet variable, Mobile SDK will use the WebRTC default behavior for codec preference.

If you create the preferredCodecSet variable with a default constructor, the Mobile SDK uses the default codecs in the following priority order:

* Audio Codecs: $AUDIO_CODECS$
* Video Codecs: $VIDEO_CODECS$

###### Example: Setting codec priority

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
$CODEC_EXAMPLE_OBJC$
```

#### ** Swift Code **

```swift
$CODEC_EXAMPLE_SWIFT$
```
<!-- tabs:end -->

#### Replace codec payload number

Using "CodecToReplace" feature of Mobile SDK, applications can manipulate the codec payload numbers in SDP. For this feature to work, these codecs and their payload numbers should be set before the call operation started (before the call creation or call answer).

Note that, it is strongly recommended **not** to use this API during an ongoing call operation (e.g. mid-call events). A configuration change will affect the ongoing call and this may cause unstable WebRTC behavior.

For the replacing codec payload number feature, the MobileSDK user have to create an instance of the CodecToReplace model class and set the codecDefinition (the definition of the codec that can be seen on the rtpmap in SDP, e.g. "telephone-event/8000" or "opus/48000/2") and payloadNumber (e.g. "101" or "96" etc.) parameters. After creation of CodecToReplace object(s), they should be set to Mobile SDK through `setcodecPayloadTypeSet` API on `Configuration` class.

After the Mobile SDK user set the codecPayloadTypeSet configuration, all of the local offer call SDPs will be generated with the specified codec payload numbers and there will be no modification done on remote SDPs and local answer SDPs.

<hr/>
<h5>NOTE</h5>
<ul>
  <li>If this configuration is not set, the SDK will keep the default WebRTC behavior and there will be no modification on the codec payload numbers on the SDP.</li>
  <li>The SDK user should not set the same payload number to different codecs in the same media line (e.g. telephone-event and opus codecs must not have the same payload number), it causes WebRTC layer to behave unpredictable and calls may fail. But it is okay to set the same payload number to codecs that are in the different media lines (e.g. opus and VP8 codecs can have the same payload number).
  <br />
  If one of the codec numbers which is set through this configuration conflicts with number of another codec that WebRTC created, SDK will swap payload numbers of these two codecs to recover from the unpredictable behavior described above.</li>
  <li>As described in RFC5761, dynamic RTP payload types should be chosen from the range 96-127. Otherwise, this could cause an unstable WebRTC behavior.</li>
</ul>
<hr/>

###### Example: Replace codec payload number

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
NSMutableArray<SMCodecToReplace *> *codecsToReplace = [[NSMutableArray alloc] init];

[codecsToReplace addObject: [SMCodecToReplace createWithCodecDefinition:@"telephone-event/48000" andPayloadNumber:@"101"]];
[codecsToReplace addObject: [SMCodecToReplace createWithCodecDefinition:@"opus/48000/2" andPayloadNumber:@"114"]];
[codecsToReplace addObject: [SMCodecToReplace createWithCodecDefinition:@"VP8/90000" andPayloadNumber:@"115"]];

NSDictionary *customProperties = [NSDictionary dictionaryWithObjectsAndKeys: @"42e029", @"profile-level-id", @"1", @"packetization-mode", nil];
[codecsToReplace addObject: [SMCodecToReplace createWithCodecDefinition:@"H264/90000" payloadNumber:@"120" andCustomProperties:customProperties]];

[[SMConfiguration getInstance] setCodecPayloadTypeSet:codecsToReplace];
```

#### ** Swift Code **

```swift
var codecsToReplace: NSMutableArray = NSMutableArray()

codecsToReplace.addObject(SMCodecToReplace.create(codecdefinition: "telephone-event/48000", andPayloadNumber: "101"))
codecsToReplace.addObject(SMCodecToReplace.create(codecdefinition: "opus/48000/2", andPayloadNumber: "114"))
codecsToReplace.addObject(SMCodecToReplace.create(codecdefinition: "VP8/90000", andPayloadNumber: "115"))

var customProperties: [NSObject : AnyObject] = NSDictionary(objectsAndKeys: "42e029","profile-level-id","1","packetization-mode",nil)
codecsToReplace.addObject(SMCodecToReplace.create(codecdefinition: "H264/90000", payloadNumber: "120", andCustomProperties: customProperties))

SMConfiguration.getInstance().codecPayloadTypeSet = codecsToReplace
```
<!-- tabs:end -->

###### Example: Effect of the Codec Payload Number Change on Sample SDPs

Let’s assume the audio and video media lines of original SDP are given as follows:

```
…
m=audio 9 RTP/SAVPF 111 103 9 102 0 8 105 13 110 113 126
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:audio
a=extmap:1 urn:ietf:params:rtp-hdrext:ssrc-audio-level
a=sendrecv
a=rtcp-mux
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:111 opus/48000/2
a=rtcp-fb:111 transport-cc
a=fmtp:111 minptime=10;useinbandfec=1
a=rtpmap:103 ISAC/16000
a=rtpmap:9 G722/8000
a=rtpmap:102 ILBC/8000
a=rtpmap:0 PCMU/8000
a=rtpmap:8 PCMA/8000
a=rtpmap:105 CN/16000
a=rtpmap:13 CN/8000
a=rtpmap:110 telephone-event/48000
a=rtpmap:113 telephone-event/16000
a=rtpmap:126 telephone-event/8000
…
m=video 9 RTP/SAVPF 96 97 98 99 100 101 127 125 104 124 106
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:video
a=extmap:2 urn:ietf:params:rtp-hdrext:toffset
a=extmap:3 http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time
a=extmap:4 urn:3gpp:video-orientation
a=extmap:5 http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01
a=extmap:6 http://www.webrtc.org/experiments/rtp-hdrext/playout-delay
a=extmap:7 http://www.webrtc.org/experiments/rtp-hdrext/video-content-type
a=extmap:8 http://www.webrtc.org/experiments/rtp-hdrext/video-timing
a=extmap:10 http://tools.ietf.org/html/draft-ietf-avtext-framemarking-07
a=sendrecv
a=rtcp-mux
a=rtcp-rsize
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:96 H264/90000
a=rtcp-fb:96 goog-remb
a=rtcp-fb:96 transport-cc
a=rtcp-fb:96 ccm fir
a=rtcp-fb:96 nack
a=rtcp-fb:96 nack pli
a=fmtp:96 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=640c29
a=rtpmap:97 rtx/90000
a=fmtp:97 apt=96
a=rtpmap:98 H264/90000
a=rtcp-fb:98 goog-remb
a=rtcp-fb:98 transport-cc
a=rtcp-fb:98 ccm fir
a=rtcp-fb:98 nack
a=rtcp-fb:98 nack pli
a=fmtp:98 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=42e029
a=rtpmap:99 rtx/90000
a=fmtp:99 apt=98
a=rtpmap:100 VP8/90000
a=rtcp-fb:100 goog-remb
a=rtcp-fb:100 transport-cc
a=rtcp-fb:100 ccm fir
a=rtcp-fb:100 nack
a=rtcp-fb:100 nack pli
a=rtpmap:101 rtx/90000
a=fmtp:101 apt=100
a=rtpmap:127 VP9/90000
a=rtcp-fb:127 goog-remb
a=rtcp-fb:127 transport-cc
a=rtcp-fb:127 ccm fir
a=rtcp-fb:127 nack
a=rtcp-fb:127 nack pli
a=rtpmap:125 rtx/90000
a=fmtp:125 apt=127
a=rtpmap:104 red/90000
a=rtpmap:124 rtx/90000
a=fmtp:124 apt=104
a=rtpmap:106 ulpfec/90000
…
```

 * A simple replacement as <"opus/48000/2", "114"> and <"telephone-event/48000", "101"> :

```
…
m=audio 9 RTP/SAVPF 114 103 9 102 0 8 105 13 101 113 126
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:audio
a=extmap:1 urn:ietf:params:rtp-hdrext:ssrc-audio-level
a=sendrecv
a=rtcp-mux
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:114 opus/48000/2
a=rtcp-fb:114 transport-cc
a=fmtp:114 minptime=10;useinbandfec=1
a=rtpmap:103 ISAC/16000
a=rtpmap:9 G722/8000
a=rtpmap:102 ILBC/8000
a=rtpmap:0 PCMU/8000
a=rtpmap:8 PCMA/8000
a=rtpmap:105 CN/16000
a=rtpmap:13 CN/8000
a=rtpmap:101 telephone-event/48000
a=rtpmap:113 telephone-event/16000
a=rtpmap:126 telephone-event/8000
…
m=video 9 RTP/SAVPF 96 97 98 99 100 101 127 125 104 124 106
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:video
a=extmap:2 urn:ietf:params:rtp-hdrext:toffset
a=extmap:3 http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time
a=extmap:4 urn:3gpp:video-orientation
a=extmap:5 http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01
a=extmap:6 http://www.webrtc.org/experiments/rtp-hdrext/playout-delay
a=extmap:7 http://www.webrtc.org/experiments/rtp-hdrext/video-content-type
a=extmap:8 http://www.webrtc.org/experiments/rtp-hdrext/video-timing
a=extmap:10 http://tools.ietf.org/html/draft-ietf-avtext-framemarking-07
a=sendrecv
a=rtcp-mux
a=rtcp-rsize
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:96 H264/90000
a=rtcp-fb:96 goog-remb
a=rtcp-fb:96 transport-cc
a=rtcp-fb:96 ccm fir
a=rtcp-fb:96 nack
a=rtcp-fb:96 nack pli
a=fmtp:96 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=640c29
a=rtpmap:97 rtx/90000
a=fmtp:97 apt=96
a=rtpmap:98 H264/90000
a=rtcp-fb:98 goog-remb
a=rtcp-fb:98 transport-cc
a=rtcp-fb:98 ccm fir
a=rtcp-fb:98 nack
a=rtcp-fb:98 nack pli
a=fmtp:98 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=42e029
a=rtpmap:99 rtx/90000
a=fmtp:99 apt=98
a=rtpmap:100 VP8/90000
a=rtcp-fb:100 goog-remb
a=rtcp-fb:100 transport-cc
a=rtcp-fb:100 ccm fir
a=rtcp-fb:100 nack
a=rtcp-fb:100 nack pli
a=rtpmap:101 rtx/90000
a=fmtp:101 apt=100
a=rtpmap:127 VP9/90000
a=rtcp-fb:127 goog-remb
a=rtcp-fb:127 transport-cc
a=rtcp-fb:127 ccm fir
a=rtcp-fb:127 nack
a=rtcp-fb:127 nack pli
a=rtpmap:125 rtx/90000
a=fmtp:125 apt=127
a=rtpmap:104 red/90000
a=rtpmap:124 rtx/90000
a=fmtp:124 apt=104
a=rtpmap:106 ulpfec/90000
…
```

 * For H264, there are 2 codecs with the same description, so another property should be introduced for comparison in order to define which one to replace. So replacement should be defined as <"H264/90000", "126", "profile-level-id=42e029">:

```
…
m=audio 9 RTP/SAVPF 111 103 9 102 0 8 105 13 110 113 126
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:audio
a=extmap:1 urn:ietf:params:rtp-hdrext:ssrc-audio-level
a=sendrecv
a=rtcp-mux
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:111 opus/48000/2
a=rtcp-fb:111 transport-cc
a=fmtp:111 minptime=10;useinbandfec=1
a=rtpmap:103 ISAC/16000
a=rtpmap:9 G722/8000
a=rtpmap:102 ILBC/8000
a=rtpmap:0 PCMU/8000
a=rtpmap:8 PCMA/8000
a=rtpmap:105 CN/16000
a=rtpmap:13 CN/8000
a=rtpmap:110 telephone-event/48000
a=rtpmap:113 telephone-event/16000
a=rtpmap:126 telephone-event/8000
…
m=video 9 RTP/SAVPF 96 97 126 99 100 101 127 125 104 124 106
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:video
a=extmap:2 urn:ietf:params:rtp-hdrext:toffset
a=extmap:3 http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time
a=extmap:4 urn:3gpp:video-orientation
a=extmap:5 http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01
a=extmap:6 http://www.webrtc.org/experiments/rtp-hdrext/playout-delay
a=extmap:7 http://www.webrtc.org/experiments/rtp-hdrext/video-content-type
a=extmap:8 http://www.webrtc.org/experiments/rtp-hdrext/video-timing
a=extmap:10 http://tools.ietf.org/html/draft-ietf-avtext-framemarking-07
a=sendrecv
a=rtcp-mux
a=rtcp-rsize
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:96 H264/90000
a=rtcp-fb:96 goog-remb
a=rtcp-fb:96 transport-cc
a=rtcp-fb:96 ccm fir
a=rtcp-fb:96 nack
a=rtcp-fb:96 nack pli
a=fmtp:96 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=640c29
a=rtpmap:97 rtx/90000
a=fmtp:97 apt=96
a=rtpmap:126 H264/90000
a=rtcp-fb:126 goog-remb
a=rtcp-fb:126 transport-cc
a=rtcp-fb:126 ccm fir
a=rtcp-fb:126 nack
a=rtcp-fb:126 nack pli
a=fmtp:126 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=42e029
a=rtpmap:99 rtx/90000
a=fmtp:99 apt=126
a=rtpmap:100 VP8/90000
a=rtcp-fb:100 goog-remb
a=rtcp-fb:100 transport-cc
a=rtcp-fb:100 ccm fir
a=rtcp-fb:100 nack
a=rtcp-fb:100 nack pli
a=rtpmap:101 rtx/90000
a=fmtp:101 apt=100
a=rtpmap:127 VP9/90000
a=rtcp-fb:127 goog-remb
a=rtcp-fb:127 transport-cc
a=rtcp-fb:127 ccm fir
a=rtcp-fb:127 nack
a=rtcp-fb:127 nack pli
a=rtpmap:125 rtx/90000
a=fmtp:125 apt=127
a=rtpmap:104 red/90000
a=rtpmap:124 rtx/90000
a=fmtp:124 apt=104
a=rtpmap:106 ulpfec/90000
```

 * If <"opus/48000/2", "105"> provided through this configuration, there will be a conflict with "CN/16000" in the original SDP. In this case Mobile SDK will swap the payload numbers of these codecs as follows:

```
…
m=audio 9 RTP/SAVPF 105 103 9 102 0 8 111 13 110 113 126
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:audio
a=extmap:1 urn:ietf:params:rtp-hdrext:ssrc-audio-level
a=sendrecv
a=rtcp-mux
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:105 opus/48000/2
a=rtcp-fb:105 transport-cc
a=fmtp:105 minptime=10;useinbandfec=1
a=rtpmap:103 ISAC/16000
a=rtpmap:9 G722/8000
a=rtpmap:102 ILBC/8000
a=rtpmap:0 PCMU/8000
a=rtpmap:8 PCMA/8000
a=rtpmap:111 CN/16000
a=rtpmap:13 CN/8000
a=rtpmap:110 telephone-event/48000
a=rtpmap:113 telephone-event/16000
a=rtpmap:126 telephone-event/8000
…
m=video 9 RTP/SAVPF 96 97 98 99 100 101 127 125 104 124 106
c=IN IP4 127.0.0.1
a=rtcp:9 IN IP4 0.0.0.0
a=ice-ufrag:cCs7
a=ice-pwd:GeKDhmK0uPScU9b+nXmpV7by
a=ice-options:trickle renomination
a=mid:video
a=extmap:2 urn:ietf:params:rtp-hdrext:toffset
a=extmap:3 http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time
a=extmap:4 urn:3gpp:video-orientation
a=extmap:5 http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01
a=extmap:6 http://www.webrtc.org/experiments/rtp-hdrext/playout-delay
a=extmap:7 http://www.webrtc.org/experiments/rtp-hdrext/video-content-type
a=extmap:8 http://www.webrtc.org/experiments/rtp-hdrext/video-timing
a=extmap:10 http://tools.ietf.org/html/draft-ietf-avtext-framemarking-07
a=sendrecv
a=rtcp-mux
a=rtcp-rsize
a=crypto:1 AES_CM_128_HMAC_SHA1_80 inline:FmJG3viNo+YcpGzfAEAPxtXP3vsFYPyBpy4UMuF5
a=rtpmap:96 H264/90000
a=rtcp-fb:96 goog-remb
a=rtcp-fb:96 transport-cc
a=rtcp-fb:96 ccm fir
a=rtcp-fb:96 nack
a=rtcp-fb:96 nack pli
a=fmtp:96 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=640c29
a=rtpmap:97 rtx/90000
a=fmtp:97 apt=96
a=rtpmap:98 H264/90000
a=rtcp-fb:98 goog-remb
a=rtcp-fb:98 transport-cc
a=rtcp-fb:98 ccm fir
a=rtcp-fb:98 nack
a=rtcp-fb:98 nack pli
a=fmtp:98 level-asymmetry-allowed=1;packetization-mode=1;profile-level-id=42e029
a=rtpmap:99 rtx/90000
a=fmtp:99 apt=98
a=rtpmap:100 VP8/90000
a=rtcp-fb:100 goog-remb
a=rtcp-fb:100 transport-cc
a=rtcp-fb:100 ccm fir
a=rtcp-fb:100 nack
a=rtcp-fb:100 nack pli
a=rtpmap:101 rtx/90000
a=fmtp:101 apt=100
a=rtpmap:127 VP9/90000
a=rtcp-fb:127 goog-remb
a=rtcp-fb:127 transport-cc
a=rtcp-fb:127 ccm fir
a=rtcp-fb:127 nack
a=rtcp-fb:127 nack pli
a=rtpmap:125 rtx/90000
a=fmtp:125 apt=127
a=rtpmap:104 red/90000
a=rtpmap:124 rtx/90000
a=fmtp:124 apt=104
a=rtpmap:106 ulpfec/90000
…
```

#### Bandwidth limitation

Mobile SDK users will be able to limit bandwidth for the media received in audio/video call. Setting the configuration will inform the other peer about this bandwidth limitation and ask it to favor this limit when sending audio/video media to Mobile SDK. Audio and Video bandwidth limit values can be set separately using the SMCallReceiveBandwidthLimit class. The important thing for Mobile SDK users is this parameter is global and user can set this once according to the platform restriction.

<hr/>
<h5>NOTE</h5>
Once this configuration is set on SMConfiguration object, it will apply for all of the outgoing and incoming calls from that point on. When an outgoing call or an incoming call starts, the bandwidth limit values read from this configuration and will be fixed to those values throughout the call session. If the configuration setting is changed on SMConfiguration object, ongoing call sessions will not be affected by this change, only new sessions that are created will use the new bandwidth limit.
<hr/>

###### Example: Bandwidth limitation

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMCallReceiveBandwidthLimit *callReceiveBandwidthLimit =
     [[SMCallReceiveBandwidthLimit alloc] initWithVideoReceiveBandwidth:1000 withAudioReceiveBandwidth:300];

[[SMConfiguration getInstance] setReceiveBandwidthLimit: callReceiveBandwidthLimit];
```

#### ** Swift Code **

```swift
let callReceiveBandwidthLimit = SMCallReceiveBandwidthLimit(videoReceiveBandwidth: 1000, withAudioReceiveBandwidth: 300)

SMConfiguration.getInstance().receiveBandwidthLimit = callReceiveBandwidthLimit
```
<!-- tabs:end -->

###### Example: Effect of the Bandwidth Limit on Sample SDP

```
…
o=- 1173675450103298446 2 IN IP4 127.0.0.1
s=-
.
.
m=audio 39631 UDP/TLS/RTP/SAVPF 111 103 104 9 102 0 8 106 105 13 110 112 113 126
c=IN IP4 10.254.16.184
b=AS:300
b=TIAS:300000
.
.
m=video 33898 UDP/TLS/RTP/SAVPF 96 97 98 99 100 101 127 124 125
c=IN IP4 10.254.16.184
b=AS:1000
b=TIAS:1000000
.
.
…
```

###### Example: Bandwidth limitation only for video

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMCallReceiveBandwidthLimit *callReceiveBandwidthLimit = [[SMCallReceiveBandwidthLimit alloc] init];
callReceiveBandwidthLimit.videoReceiveBandwidth = 1000;

[[SMConfiguration getInstance] setReceiveBandwidthLimit: callReceiveBandwidthLimit];
```

#### ** Swift Code **

```swift
let callReceiveBandwidthLimit = SMCallReceiveBandwidthLimit()
callReceiveBandwidthLimit.videoReceiveBandwidth = 1000

SMConfiguration.getInstance().receiveBandwidthLimit = callReceiveBandwidthLimit
```
<!-- tabs:end -->

###### Example: Effect of the Bandwidth Limit only for video on Sample SDP

```
…
o=- 1173675450103298446 2 IN IP4 127.0.0.1
s=-
.
.
m=audio 39631 UDP/TLS/RTP/SAVPF 111 103 104 9 102 0 8 106 105 13 110 112 113 126
c=IN IP4 10.254.16.184
.
.
m=video 33898 UDP/TLS/RTP/SAVPF 96 97 98 99 100 101 127 124 125
c=IN IP4 10.254.16.184
b=AS:1000
b=TIAS:1000000
.
.
…
```

#### Control audio bandwidth

<hr/>
<h5>WARNING</h5>
Bandwidth limitation setting for audio bandwidth which is explained in previous section and controlling audio bandwidth using the feature in this section are features which configure the bandwidth preferences for audio media stream. Using both features at the same time may cause unexpected behavior.
<hr/>

Applications can modify five audio codec properties to control audio bandwidth. The MaxPlaybackRate, MaxAverageBitrate, Discontinuous Transmission (DTX), and Forward Error Correction (FEC) properties apply to the Opus audio codec. The fifth property, packetization time (ptime), affects all audio codecs. Refer to RFC 7587 for descriptions, acceptable values, and recommended values for the audio codec properties.

Set your application to use the WebRTC default set or the Mobile SDK preferred set; the application can change properties within either set. If the values of any property exceed the acceptable values identified in RFC 7587, the Mobile SDK ignores the value and uses the default configuration for that property. The following table shows the property values for the WebRTC default set and the Mobile SDK preferred set as well as the RFC 7587–defined acceptable values.

###### WebRTC default settings, MobileSDK preferred default settings, and acceptable values

|  | WebRTC default | Mobile SDK preferred | Acceptable values |
|----|----|----|----|
| MaxPlaybackRate | 24000  | 16000  | 8000-48000  |
| MaxAverageBitRate | 40000  | 20000  | 6000-510000  |
| DTX | Disabled  | Enabled  | true or false  |
| FEC | Enabled  | Enabled  | true or false  |
| Ptime | 20  | 60  | 3, 5, 10, 20, 40, 60...120<br><br>​(2.5*n round up to next full integer)  |

The following adjustments decrease bandwidth usage:

* Decreasing MaxPlaybackRate
* Decreasing MaxAverageBitRate
* Enabling DTX
* Disabling FEC (**Note:** Disabling FEC does not greatly reduce bandwidth usage. Therefore, the Mobile SDK preferred set enables FEC by default.)
* Increasing Ptime

The application can modify audio bandwidth usage in all call states (before and during calls). When the application modifies audio bandwidth during a call, the properties change after the Mobile SDK sends a call update to the remote side (e.g. a user holds the call).

The following shows different audio bandwidth usage configuration examples. If a codec property value is not specified, the application uses the default value for the configured set. If the application does not perform any audio bandwidth usage configuration or sets the configuration as null, the Mobile SDK uses the WebRTC default set.

###### Example: Use the Mobile SDK preferred set

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMAudioCodecConfiguration *config = [SMAudioCodecConfiguration
configurationWithMobileSDKPreferredSet];
[[SMConfiguration getInstance] setAudioCodecConfigurations:config];
```
#### ** Swift Code **

```swift
let config = SMAudioCodecConfiguration.withMobileSDKPreferredSet()
SMConfiguration.getInstance().audioCodecConfigurations = config
```
<!-- tabs:end -->

###### Example: Use the Mobile SDK preferred set with changes

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMAudioCodecConfiguration *config = [SMAudioCodecConfiguration
configurationWithMobileSDKPreferredSet];
[config setOpusMaxAverageBitRate:25000];
[config setOpusMaxPlaybackRate:24000];
[[SMConfiguration getInstance] setAudioCodecConfigurations: config];
```

#### ** Swift Code **

```swift
let config = .SMAudioCodecConfiguration.withMobileSDKPreferredSet()
config.opusMaxAverageBitRate = 25000
config.opusMaxPlaybackRate = 24000
SMConfiguration.getInstance().audioCodecConfigurations = config
```
<!-- tabs:end -->

###### Example: Use the WebRTC default set with changes

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
SMAudioCodecConfiguration *config = [SMAudioCodecConfiguration
configurationWithWebRTCDefaultSet];
[config setOpusMaxAverageBitRate:25000];
[config setOpusMaxPlaybackRate:24000];
[config setPtime:60];
[config setOpusDtx:YES];
[config setOpusFec:YES];
[[SMConfiguration getInstance] setAudioCodecConfigurations: config];
```

#### ** Swift Code **

```swift
let config = SMAudioCodecConfiguration.withWebRTCDefaultSet()!
config.opusMaxAverageBitRate = 25000
config.opusMaxPlaybackRate = 24000
config.ptime = 60
config.opusDtx = true
config.opusFec = true
SMConfiguration.getInstance().audioCodecConfigurations = config
```
<!-- tabs:end -->

#### Receive internal error notifications

Applications can listen for internal error notifications between the Mobile SDK and SPiDR/Kandy Link using the `internalErrorDidOccur` callback method in the `SMRegistrationApplicationDelegate`. The error message includes the error reason and the component on which the error occurred. The following shows the possible internal error causes and their associated component tag values

| Error Case         | Component Tag                                                   |
|--------------------|---------------------------------------------------------------|
| Audit request fail             | AuditRequest                        |
| Ice candidate update fail            | ICECandidateUpdateRequest                        |
| Renew registration fail             | RenewRegistrationRequest                        |
| Gone notification fail             | GoneNotificationRequest                        |
| Internal respond call update request fail (glare condition)            | RespondCallUpdateRequest                        |

###### Example: Implementing internal error notifications

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
-(void) internalErrorDidOccur:(SMMobileError*) error{
    NSLog(@"internalErrorDidOccur, errorCode:%ld ,errorMessage:%@",(long)[error code],[error description]);
}
```

#### ** Swift Code **

```swift
func internalErrorDidOccur(_ error: SMMobileError) {
    print("internalErrorDidOccur, errorCode: \(error.code), errorMessage: \(error.description)")
}
```
<!-- tabs:end -->

#### Get additional information about a call

Use the `callAdditionalInfoChanged` callback method in `SMCallApplicationDelegate` to determine when particular actions occurred on a specific call. Use this data to learn information such as the time from when a call was created until the time a REST request was sent. The additional info map includes the fields:

| Field  | Description                                                   |
|--------|---------------------------------------------------------------|
| action | The primary category of information                           |
| type   | The "action" sub-category                                     |
| callId | The identifier for the related call, which is different than the call session id. This id is either randomly generated by the Mobile SDK or set by the user. <br><br> **Note:** The call identifier is obtained using the "getId" method rather than the "getCallId" method (which would return the call session identifier)  |
| time   | Occurrence time (epoch in milliseconds)                       |

###### Example: Listening call additional info changes

```
{
    "action": "callMetric",
    "type": "callRestSent",
    "callId": "7E60066C-C7F3-438A-95B1-DDE8634E1072",
    "time": "1455701052999"
}
```

The following list shows each available "action" category and its "type" sub-category:

* **iceTimeout:** Includes types for ICE collection timeout (assuming "2x" is the timeout configuration and "t" is when the ICE process ended)
    * **iceNormal:** Time when the ICE collection process ended normally (period of t<x)
    * **iceOneRelay:** Time when the ICE collection process was interrupted by a timeout with at least one (audio and video) relay candidate (period of x<t<2x)
    * **iceNoRelay:** Time when the ICE collection process was interrupted by a timeout without a relay candidate (period of t=2x)
* **callMetric:** Includes types for call setup time measurements
    * **callCreate:** Time of the establishCall start (for Outgoing calls) or of the acceptCall start (for Incoming calls)
    * **incomingCall:** Time an incoming call event was received
    * **callRestSent:** Time when the REST request was sent following creating/accepting a call
    * **callRinging:** Time when the ringing notification was received for an outgoing call
    * **callAnswerReceived:** Time when the answer notification was received for an outgoing call
* **iceState:** Includes types for ICE state change
    * **iceConnected:** Time when the ICE media channel was established on WebRTC
    * **iceDisconnected:** Time when the ICE media channel failed on WebRTC
* **ipChange:** Includes types of IP change while in an active call
    * **ipChangeStarted:** Time when the IP change event started
    * **ipChangeEnded:** Time when the IP change event finished

<div class="page-break"></div>

###### Example: Listening call additional info changes

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
- (void) callAdditionalInfoChanged:(id<SMCallDelegate>)call
withDictionary:(NSDictionary*)detailedInfo
{
    NSString * callid = [call getCallId];
    NSString * type = detailedInfo[@"type"];
    long time = [detailedInfo[@"time"] longValue];

    if ([type isEqualToString:@"callCreate"] || [type isEqualToString:@"incomingCall"]) {
        callCreateTime = time;
    }

    long delay = time - callCreateTime;
    [logManager log:TRACE withLogContext:TAG withMethodName:_cmd withMessage:[NSString
    stringWithFormat:@"Time from creating call until %@ is %ld for callid %@", type, delay, callid]];
    [logManager log:TRACE withLogContext:TAG withMethodName:_cmd withMessage:[NSString
    stringWithFormat:@"Detailed info is %@", detailedInfo]];
}
```

#### ** Swift Code **

```swift
func callAdditionalInfoChanged(_ call: SMCallDelegate, with detailedInfo: [AnyHashable : Any]) {
    let callid = call.id()
    let type = detailedInfo["type"]
    let time = Int([detailedInfo[@"time"])

if (type == "callCreate" || type == "incomingCall") {
    callCreateTime = time;
}

let delay = time - callCreateTime;
    NSLog("Time from creating call until \(type) is \(delay) for callid \(callid)", type, delay, callid)
    NSLog("Detailed info is \(detailedInfo)")
}
```
<!-- tabs:end -->

<div class="page-break"></div>

#### Retrieve audio and video RTP/RTCP statistics

The Mobile SDK can retrieve audio and video RTP/RTCP statistics providing information including:

* Number of packets lost
* Number of packets sent/received
* Number of bytes sent/received
* Call Jitter received
* RTT (round trip delay)
* Local/Remote network addresses and ports
* Audio/Video codec names

**Note:** The Mobile SDK does not keep the statistics after the call ends.It is application developer's responsibility to keep them. Since the statistics could be too long to log due to character limitation, it is adviced to write them to a file instead of logging for further usage. You can use the following class to see how to write it to a file :

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec

#import "DemoRTPLogger.h"
#import "DemoLogger.h"
#define MAX_CALL_LENGTH 5

@interface DemoRTPLogger(){
    
    NSFileHandle *myHandle;
    /**
      Example Data Structure of callStatistics
        [
         [
          "callId1",
            [
              STATISTICS_DICTIONARY,
              STATISTICS_DICTIONARY,
              STATISTICS_DICTIONARY,
              ....
            ]
         ],
         [
          "callId2",
            [
              STATISTICS_DICTIONARY,
              STATISTICS_DICTIONARY,
              STATISTICS_DICTIONARY,
              ....
            ]
         ],
         ....
        ]
     */
    NSMutableArray<id> *callStatistics;
}

@end

@implementation DemoRTPLogger

__strong static id _instance = nil;


+(instancetype)getInstance{
    @synchronized (self) {
        if(!_instance){
            _instance = [[self alloc]init];
        };
    }
    return _instance;
}
- (id)init
{
    self = [super init];
    if (self) {
        [self initLogFile];
    }
    return self;
}

- (void) initLogFile{
    if(myHandle) [myHandle closeFile];
    
    if(![[NSFileManager defaultManager] fileExistsAtPath:CONSOLE_RTP_LOG_PATH])
        [@"" writeToFile:CONSOLE_RTP_LOG_PATH atomically:YES encoding:NSUTF8StringEncoding error:nil];
    
    SPLog(@"Log File Path: %@", CONSOLE_RTP_LOG_PATH);
    myHandle = [NSFileHandle fileHandleForUpdatingAtPath:CONSOLE_RTP_LOG_PATH];
    NSData *json = [myHandle readDataToEndOfFile];
    callStatistics = [[NSMutableArray alloc] init];
    if (json.length > 0) {
        [self mapCallStatisticsArrayFromJson:json];
    }
}

- (void) mapCallStatisticsArrayFromJson:(NSData *) jsonData {
    NSError *jsonError;
    id json = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingAllowFragments error:&jsonError];
    if(jsonError) return;
    for (id x in json) [callStatistics addObject:x];
}

-(BOOL) checkIsNewCallWithCallId:(NSString *) callId {
    for (NSMutableArray *x in callStatistics) {
        NSString *tmpId = (NSString *) x.firstObject;
        if([callId isEqualToString:tmpId]) return NO;
    }
    return YES;
}

- (void) saveStatisticsWithCallId:(NSString *)callId andStatistics:(NSString *)stats {
    
    if([self checkIsNewCallWithCallId:callId]) {
        if (callStatistics.count == MAX_CALL_LENGTH) [callStatistics removeObjectAtIndex:0];
        [callStatistics addObject: [NSMutableArray arrayWithObjects:callId, [NSMutableArray array], nil]];
    }
    
    NSError *statsError;
    NSDictionary *statsDict = [NSJSONSerialization
                          JSONObjectWithData: [stats dataUsingEncoding:NSUTF8StringEncoding]
                          options:NSJSONReadingMutableContainers
                          error:&statsError];
    [callStatistics.lastObject[1] addObject: statsDict];
}

- (void) writeLogToFile {
    NSError *statsError;
    NSData *data = [NSJSONSerialization dataWithJSONObject:callStatistics options:kNilOptions error:&statsError];
    [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] writeToFile:CONSOLE_RTP_LOG_PATH atomically:YES encoding:NSUTF8StringEncoding error:nil];
    SPLog(@"RTPStatistics has been wrote file");
}
-(void)clearLogs{
    [@"" writeToFile:CONSOLE_RTP_LOG_PATH atomically:YES encoding:NSUTF8StringEncoding error:nil];
    [self initLogFile];
    SPLog(@"RTP Logs Cleaned");
}
-(void)closeFile{
    [myHandle closeFile];
}

@end
```

#### ** Swift Code **

```swift
struct StatsModel {
    var callId:String
    var stats:[Any]
}

class CallStatistics: NSObject {
    
    public static let sharedInstance = CallStatistics()
    private var handler: FileHandle?
    private var callStatistics:[StatsModel] = []
    
    override init() {
        super.init()
        initLogFile()
    }
    
    private func initLogFile() {
        let fullDestPathString = getLogFilePath()
        if !FileManager.default.fileExists(atPath: fullDestPathString) {
            do {
                try "".write(toFile: fullDestPathString, atomically: true, encoding: String.Encoding.utf8)
            } catch {
                logWith("Can't write to file to device directory - Error: \(error.localizedDescription)")
            }
        }
        handler = FileHandle.init(forUpdatingAtPath: fullDestPathString)
        let json = handler!.readDataToEndOfFile()
        if json.count > 0 {
            self.mapCallStatisticsArrayFromJson(json)
        }
    }
    
    func mapCallStatisticsArrayFromJson(_ jsonData:Data) {
        let json = try! JSONSerialization.jsonObject(with: jsonData, options:.allowFragments) as! [[Any]]
        for x:[Any] in json {
            callStatistics.append(StatsModel(callId: x[0] as! String, stats: x[1] as! [Any]))
        }
       
    }

    func checkIsNewCall(_ callId:String!) -> Bool {
        for x in callStatistics {
            if (callId == x.callId) {return false}
         }
        return true
    }

    func saveStatistics(_ callId:String, stats:String!) {
        if self.checkIsNewCall(callId) {
            if callStatistics.count == 5 {
                callStatistics.remove(at: 0)
            }
            callStatistics.append(StatsModel(callId: callId, stats: []))
        }
        let statsDict = try! JSONSerialization.jsonObject(with: stats.data(using: .utf8)!, options: .mutableContainers) as! NSDictionary
        let lastIndex = callStatistics.count - 1
        callStatistics[lastIndex].stats.append(statsDict)
    }
    
    func createJsonArray() -> [Any] {
        var jsonArray:[Any] = []
        for statsModel in callStatistics {
            jsonArray.append([statsModel.callId,statsModel.stats])
        }
        return jsonArray;
    }
    
    func getLogFilePath() -> String {
        let destPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
        let fullDestPath = NSURL(fileURLWithPath: destPath).appendingPathComponent("CallStatistics.log")
        return fullDestPath!.path
    }

    func writeLogToFile() {
        let data = try! JSONSerialization.data(withJSONObject: createJsonArray(), options: .fragmentsAllowed)
        let jsonString:String! = String(data:data, encoding:.utf8)
        do {
            try jsonString.write(toFile: getLogFilePath(), atomically:true, encoding: String.Encoding.utf8)
        } catch {
            logWith("Can't write to file to device directory - Error: \(error.localizedDescription)")
        }
        logWith("RTPStatistics has been wrote file")
    }
    
    func clearLogs() {
        do {
            try "".write(toFile: getLogFilePath(), atomically: true, encoding: String.Encoding.utf8)
        } catch {
            logWith("Can't write to file to device directory - Error: \(error.localizedDescription)")
        }
        callStatistics = []
        initLogFile()
        logWith("RTP Logs Cleaned")
    }
}
```
<!-- tabs:end -->


Use the "getRTPStatistics" method in an Call object to retrieve a string in the JSON format containing RTP/RTCP statistics. The JSON-String includes objects of the RTCStatsReport class—a class which stores statistic details. This class has the following public variables:

 * timestamp -- Indicates the time at which the sample was taken for this statistics object.
 * type      -- Indicates the type of statistics the object contains. Types are listed below.
 * id        -- Uniquely identifies the object.


 ```javascript
type {
    "codec",            
    "inbound-rtp",
    "outbound-rtp",
    "remote-inbound-rtp",
    "remote-outbound-rtp",
    "media-source",
    "csrc",
    "peer-connection",
    "data-channel",
    "stream",
    "track",
    "transceiver",
    "sender",
    "receiver",
    "transport",
    "sctp-transport",
    "candidate-pair",
    "local-candidate",
    "remote-candidate",
    "certificate",
    "ice-server"
}
```

<hr/>
<h5>WARNING</h5>
If there is a bandwidth or CPU limitation, WebRTC will decrease video resolution and FPS values automatically. The Mobile SDK does not inform the application of the automatic change; the application must check the values using the getRTPStatistics method.
<hr/>

###### Example: Retrieving statistics

It is recommended to call this method every 10 seconds as long as call continues.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
 [call getRTPStatistics:^(NSString * _Nullable statistics) {
            if ([call getCallState].type != CALLSTATES_ENDED && call != nil){
                [[CallStatistics getInstance] saveStatisticsWithCallId:call.sessionId andStatistics:statistics];
            } else {
                [[CallStatistics getInstance] writeLogToFile];
            }
    }];
```

#### ** Swift Code **

```swift
     call.getRTPStatistics { (stat) in
            if (call.getCallState().type != .ended && (call != nil)) {
                CallStatistics.sharedInstance.saveStatistics(call.id, stats: stat)
            } else {
                CallStatistics.sharedInstance.writeLogToFile()
            }
        }
```
<!-- tabs:end -->

<div class="page-break"></div>

#### Use External Video Source

The MobileSDK allows streaming external video sources instead of the default device camera while during the call.

The MobileSDK supports [CVImageBufferRef](https://developer.apple.com/documentation/corevideo/cvimagebufferref) which is a reference to a [Core Video](https://developer.apple.com/documentation/corevideo) image buffer.

The following API should be used for external video source.

#### ** Objective-C Code **

```objectivec

/**
 * @brief Enums that handle VideoSourceType in SDK.
 * MobileSDK supports multiple video source types. CAMERA is the default video source type.
 * Alternatively, applications can select EXTERNAL_VIDEO and insert video frames as their desire.
 * If EXTERNAL_VIDEO is chosen as the video source type, application must provide frames by using setExternalVideoSource API.
 *
 * @since 6.4.0
*/

@property (nonatomic) SMVideoSourceTypes videoSourceType;

```
<!-- tabs:end -->

SMVideoSourceType is an enum with the following two parameters.

```objectivec

typedef NS_ENUM(NSInteger, SMVideoSourceTypes) {

    CAMERA NS_SWIFT_NAME(camera),

    EXTERNAL_VIDEO NS_SWIFT_NAME(externalVideo),

};

```
<!-- tabs:end -->

To use an external video stream, it is necessary to call the setExternalVideoSource API after setting setVideoSourceType to EXTERNAL_VIDEO.

When the setExternalVideoSource API is called when this type is not EXTERNAL_VIDEO, MobileSDK will print a log message to the developers and will not set the external video.

#### ** Objective-C Code **

```objectivec
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
- (void) setExternalVideoSource:(CVImageBufferRef)imageBuffer;
```
<!-- tabs:end -->

**Note:** The application must call setExternalVideoSource API on every frame.


###### Example: Use external video source

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec

@property id<SMCallDelegate> call;

CVImageBufferRef *sampleImage;

  
// Set Video Source Type to ExternalVideo to inform SDK video source.
[call setVideoSourceType:EXTERNAL_VIDEO];


- (void) startExternalVideo:(CVImageBufferRef)imageBuffer {
    // Assuming that application call this function for each frame
  [call setExternalVideoSource:sampleImage];
}

```

#### ** Swift Code **

```swift

var call: SMCallDelegate
var sampleImage: CVImageBufferRef

  
// Set Video Source Type to ExternalVideo to inform SDK video source.
call.setVideoSourceType = .externalVideo

func startExternalVideo(CVImageBufferRef: sampleImage
    // Assuming that application call this function for each frame
  call.setExternalVideoSource(CVImageBufferRef: sampleImage)
}

```

<!-- tabs:end -->

**Note:** Creating video stream objects from RTSP URL is explained in the Appendices F section.

## Push Service

<hr/>
<h5>WARNING</h5>
In order to use the push service, please contact your Ribbon channel account manager as it requires a pre-provisioning process.
<hr/>


When SPiDR/Kandy Link server cannot reach to the device using websocket channel, message will be sent through APNS if implemented. Using the mobile push mechanism, communication between SPiDR/Kandy Link server  and the device can be maintained even while the application is not awake or in the case of websocket connection failure. In order to register device to the push channel and pass the message to the Mobile SDK, see [**Registering Device for Push Notifications**](#registering-device-for-push-notifications) and [**Receiving Push Notifications**](#receiving-push-notifications) sections.

Starting April 30, 2020, all iPhone apps submitted to the App Store must be built with the iOS 13 SDK or later. This restricts how VoIP Push can be used. Therefore Mobile SDK support both VoIP([PushKit](https://developer.apple.com/documentation/pushkit)) and Standard([UserNotifications](https://developer.apple.com/documentation/usernotifications)) Push in order to support Call and, Gone notifications. `PushKit` notifications can wake up or launch your app and wait for app to inform `CallKit` about incoming call, which provides VoIP app developers to present incoming VoIP calls like native GSM/CDMA incoming call. With iOS 13 SDK built app it is mandatory to inform `CallKit` when app receives a VoIP push. Failure to do so, iOS 13 will kill the app and after a couple of failures iOS 13 will block the app from receiving any further VoIP push notifications which means incoming calls will be blocked but outgoing calls can still be made while application is open.

For more information and restrictions about using VoIP notifications, please refer [Responding to VoIP notifications](https://developer.apple.com/documentation/pushkit/responding_to_voip_notifications_from_pushkit).

## Registering Application For Push Services

Application should be registered with its bundle ID first to be able to receive push notifications from SPiDR/Kandy Link server. Necessary information for registration step for iOS applications are listed below, please contact with system administrator and share them when needed.

-   Application Bundle ID
-   APNS "Auth Key" in `p8` format. (Can be found in Apple Developer Account Page - Certificates, Identifiers & Profiles)
-   Key ID (ID of the APNs key)
-   Team ID (Can be found in Apple Developer Account Page - Membership)

## Registering Device for Push Notifications

In order to receive **VoIP push notifications**, `PushKit` framework should be implemented correctly. For more information please refer [PushKit](https://developer.apple.com/documentation/pushkit). Please note that in order to receive silent `gone` notifications which are related to call subscription expiration, standard notifications should also be implemented. This means that even if you have a call-only app, you need to use standard notifications if you want to keep track of call subscription expiration.

Open the `AppDelegate` file of the project and add `import PushKit`. Note that `AppDelegate` should conform `PKPushRegistryDelegate` protocol.

In order to receive **Standard push notifications** which will enable receiving gone notifications, `UserNotifications` framework should be implemented correctly. For more information please refer [UserNotifications](https://developer.apple.com/documentation/usernotifications).

In order to register and for VoIP and Standard push, open the `AppDelegate` file of the project and `import UserNotifications and PushKit.` Then, add the code below to the `application(:didFinishLaunchingWithOptions:)`. Note that `AppDelegate` should conform `PKPushRegistryDelegate and` `UNUserNotificationCenterDelegate` protocol.

Please note that VoIP Push registration does not require user confirmation but UserNotifications require user confirmation. For more information please refer [Asking Permission to Use Notifications](https://developer.apple.com/documentation/usernotifications/asking_permission_to_use_notifications).

Registrations should be performed every time when app has launched. Do not cache the tokens. If the device token hasn't changed, registering with `APNs` and returning the token happens quickly.

Registration can be done in two steps.

1. Registering for tokens via iOS APIs.

2. After iOS API invokes the callbacks, send tokens for subscription. Please refer to [Push Service Subscription](#push-service-subscription) for more information.

###### Example: Registering for tokens from iOS APIs

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec    
...
#import <PushKit/PushKit.h> 
#import <UserNotifications/UserNotifications.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate>
...
@end

@implementation AppDelegate {
    PKPushRegistry *registry;
}
...

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    ...
    //Register for VoIP Pushes
    [self registerVoipPushNotification];
    //Request And Register for Standard Push (UserNotifications)
    [self registerStandardPushNotification];
    ...
    return YES;
}

- (void)registerVoipPushNotification {
    registry = [[PKPushRegistry alloc] initWithQueue: dispatch_get_main_queue()];
    [registry setDelegate:self];
    [registry setDesiredPushTypes:[NSSet setWithObject:PKPushTypeVoIP]];
}

- (void)registerStandardPushNotification {
    [[UNUserNotificationCenter currentNotificationCenter] setDelegate:self];
    //Request user authorization.
    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:(UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge) completionHandler:^(BOOL granted, NSError * _Nullable error) {
        if (granted == YES) {
            //User granted permission for local notifications.
        }
    }];
    //Register for Standard Push Notifications.
    dispatch_async(dispatch_get_main_queue(), ^{
        [[UIApplication sharedApplication] registerForRemoteNotifications];
    });  
}

...
@end
```

#### ** Swift Code **

```swift
...
import PushKit
import UserNotifications

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate {
    
    ...
 
    var pushRegistry : PKPushRegistry!

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        ...
        //Register for VoIP Pushes
        registerForVoIPNotifications()
        //Request And Register for Standard Push (UserNotifications)
        requestAndRegisterForPushNotifications()
        ...
        return true
    }
 
    func registerForVoIPNotifications() {
        pushRegistry = PKPushRegistry(queue: DispatchQueue.main)
        pushRegistry.delegate = self 
        pushRegistry.desiredPushTypes = [PKPushType.voIP]
    }
 
    func requestAndRegisterForPushNotifications() {
        UNUserNotificationCenter.current().delegate = self 
        //Request user authorization.
        UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound]) { granted, error in
            if granted {
                //User granted permission for local notifications.  
            }
        }
        //Register for Standard Push Notifications.
        DispatchQueue.main.async {
            UIApplication.shared.registerForRemoteNotifications()
        }
    }
 
    ...
}
```
<!-- tabs:end -->

### Push Service Subscription

When device is registered to the APNS, `PKPushRegistryDelegate` and `UNUserNotificationCenterDelegate` will inform through delegate methods and gives push tokens which later will be used by SPiDR/Kandy Link server in order to send notifications. This token should be sent to SPiDR/Kandy Link server, later on when Mobile SDK subscribes to services, user will also subscribe to push channels of the services. Please note that, VoIP token and Standard token can not be used interchangeably.

To be able to receive push notifications, applications must subscribe to push channels by using the  `subscribeToPushNotifications`  API of the  `SMPushService`. Fail and success calls will be transmitted through the completion block. If the registration is successful, a  `subscriptionID`  will be returned which can be used to update or remove the push subscription.

**Note:**  The  `pushServiceURL`  configuration must be set on client before using the service.

###### Example: Push Service Subscription

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <PushKit/PushKit.h> 
#import <UserNotifications/UserNotifications.h>
#import <MobileSDK/MobileSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate>
...
@end
 
@implementation AppDelegate {
    NSData *voipPushToken;
    NSData *standardPushToken;
}
...
  
- (void) application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken{
    // Get Device token.
    standardPushToken = deviceToken;
    //Inform Server for token
    [self sendTokensToServer];
}

- (void)pushRegistry:(nonnull PKPushRegistry *)registry didUpdatePushCredentials:(nonnull PKPushCredentials *)pushCredentials forType:(nonnull PKPushType)type {
    // Get Device token.
    voipPushToken = pushCredentials.token;
    //Inform Server for token
    [self sendTokensToServer];
}

-(void)sendTokensToServer {
    if(voipPushToken != nil && standardPushToken != nil) {
        SMPushService *pushService = [[SMServiceProvider getInstance] getPushService];
        NSString *realm = @"default";

        // pushServerURL configuration must be set before using the push subscription API
        [pushService subscribeToPushNotificationsWithStandardPushToken:standardPushToken
                                              andVoipPushToken:voipPushToken
                                                      andRealm:realm
                                             completionHandler:^(NSString * _Nullable subscriptionID, SMMobileError * _Nullable error) {
            if (error) {
                   // handle error case
            }
            if (subscriptionID) {
                // save this subscriptionID to use later
            }
        }];
    }
}
...
@end
```

#### ** Swift Code **

```swift
...
import PushKit
import UserNotifications
import MobileSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate {
    ...
    var voipPushToken : Data?
    var standardPushToken : Data?
 
    func pushRegistry(_ registry: PKPushRegistry, didUpdate pushCredentials: PKPushCredentials, for type: PKPushType) {
        // Get Device token.
        voipPushToken = pushCredentials.token

        //Inform Server for token
        sendTokensToServer()    
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        // Get Device token.
        standardPushToken = deviceToken
    
        //Inform Server for token
        sendTokensToServer()
    }

    func sendTokensToServer() {
        if let standardToken = standardPushToken, let voipToken = voipPushToken 
        {
            let pushService: SMPushService? = SMServiceProvider.getInstance().getPushService()
            let realm = "default"
    
            // pushServerURL configuration must be set before using the push subscription API
            pushService?.subscribeToPushNotifications(withStandardPushToken: standardPushToken,
                                              andVoipPushToken: voipPushToken,
                                              andRealm: realm) {
                   subscriptionID, error in
                if error != nil {
                    // handle error case
                }
                if subscriptionID != nil {
                    // save this subscriptionID to use later
                }
            } 
        }
    }
    ...
}
```
<!-- tabs:end -->

### Updating Push Subscription

iOS can update the push credentials (a.k.a device token) in some cases. The new credentials must be updated on the push server, so that the Mobile SDK can continue receiving push notifications.

###### Example: Updating Push Service Subscription

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface PushModule ()
@end

@implementation PushModule

- (void) updatePushSubscriptionWithStandardPushToken:(nonnull NSData*)standardToken
                                    andVoipPushToken:(nonnull NSData*)voipToken
                                   andSubscriptionID:(nonnull NSString*)subscriptionID {

    SMPushService *pushService = [[SMServiceProvider getInstance] getPushService];
    
    // pushServerURL configuration must be set before using the push subscription API
    [pushService updatePushSubscriptionWithStandardPushToken:standardToken andVoipPushToken:voipToken
                                           andSubscriptionID:subscriptionID
                                           completionHandler:^(SMMobileError * _Nullable error) {
        if (error) {
            // handle error case          
        }
    }];
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

class PushModule {
     func updatePushSubscription(standardToken: Data, voipToken: Data, subscriptionID: String) {

        let pushService: SMPushService? = SMServiceProvider.getInstance().getPushService()

        // pushServerURL configuration must be set before using the push subscription API
        pushService?.updatePushSubscription(withStandardPushToken: standardToken,
                                            andVoipPushToken: voipToken,
                                            andSubscriptionID: subscriptionID) { error in
            if error != nil {
                // handle error case
            }
        }
    }
}
```
<!-- tabs:end -->

### Removing Push Subscription

In order to stop receiving push notifications, app should remove the push subscription. Otherwise, app will continue to receive push notifications until the application removed from the device.

###### Example: Removing Push Service Subscription

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface PushModule ()
@end

@implementation PushModule

- (void) removePushSubscription:(nonnull NSString *)pushSubscriptionID {

    SMPushService *pushService = [[SMServiceProvider getInstance] getPushService];

    // pushServerURL configuration must be set before using the push subscription API
    [pushService unsubscribeFromPushNotificationsWithSubscriptionID:subscriptionID
                                                  completionHandler:^(SMMobileError * _Nullable error) {
        if (error) {
            // handle error case
        }
    }];
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

class PushModule {
    func removePushSubscription(_ pushSubscriptionID: String) {

        let pushService: SMPushService? = SMServiceProvider.getInstance().getPushService()

        // pushServerURL configuration must be set before using the push subscription API
        pushService.unsubscribeFromPushNotifications(withSubscriptionID: subscriptionID, completionHandler: { error in
            if error != nil {
                // handle error case
            }
        })
    }
}
```
<!-- tabs:end -->

## Receiving Push Notifications

### VoIP Push Notification Callback

If VoIP push registration is completed successfully and subscribed to push channels with the correct device push token, device now should receive VoIP push notifications for incoming calls.

When device receives VoIP push notification, `PKPushRegistryDelegate` informs its delegate via `pushRegistry(:didReceiveIncomingPushWith:for:)` which is available for iOS10 devices, and `pushRegistry(:didReceiveIncomingPushWith:for:completion:)` for iOS11 and later devices. Because very similar implementation will be done for both methods, creating new method and executing operations inside on that method is recommended. With Xcode11 compiled app it has been mandatory to inform `CallKit`. For more information please refer [pushRegistry](https://developer.apple.com/documentation/pushkit/pkpushregistrydelegate/2875784-pushregistry). Informing CallKit with appropriate Caller ID and Caller Name requires parsing the incoming VoIP push Notification. Mobile SDK provide API for parsing notification which is shown in below code.

Please note that in order to inject push payload, app should wait until Mobile SDK has been subscribed and connected.  

###### Example: VoIP Push Notification Callback

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
...
#import <PushKit/PushKit.h> 
#import <MobileSDK/MobileSDK.h>
  
@interface AppDelegate : UIResponder <UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate>
...
@end
  
@implementation AppDelegate
...
 
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 11000
- (void)pushRegistry:(PKPushRegistry *)registry didReceiveIncomingPushWithPayload:(PKPushPayload *)payload forType:(PKPushType)type withCompletionHandler:(void (^)(void))completion {
    [self sendPushMessageWithPayload:payload completion:completion];
}
#else
- (void)pushRegistry:(PKPushRegistry *)registry didReceiveIncomingPushWithPayload:(PKPushPayload *)payload forType:(PKPushType)type {
    [self sendPushMessageWithPayload:payload completion:nil];
}
#endif
    
- (void)sendPushMessageWithPayload: (PKPushPayload *)payload completion:(void (^)(void))completion {
    
    //Parsing push notification
    SMPushService *pushService = [[SMServiceProvider getInstance] getPushService];
    SMCKInfo *callKitInfo = [pushService parsePushNotification:payload.dictionaryPayload];
    if (!callKitInfo.error) {
        //Inform CallKit about the incoming call with callKitInfo.callUUID and callKitInfo.callerDisplayInfo
        // CXProvider reportNewIncomingCall(with:update:completion:)
        //Failure to inform CallKit a couple of times and iOS 13 will block app from receiving VoIP push.
        
        //Inject push payload after SDK has been subscribed and connected.
        if ([[[SMServiceProvider getInstance] getRegistrationService] getRegistrationState] == REGISTERED) {
            id notificationCompletion = ^(SMMobileError * _Nullable error) {
                if (error)
                    // handle the error
                if (completion)
                    completion();
            };   
            [pushService injectPushMessage:pushData completionHandler:notificationCompletion];
        } else {
            // note: set your configurations before registration
            [[[SMServiceProvider getInstance] getRegistrationService]
             registerToServer:3600 completionHandler:^(SMMobileError *error) {
                
                if(error) {
                    // handle the error
                }
                else {
                    [pushService injectPushMessage:pushData completionHandler:notificationCompletion];
                }
            }]];
        }
    } else {
        //Inform CallKit about the failed incoming call.
        // 1- CXProvider reportNewIncomingCall(with:update:completion:)
        // 2- CXProvider reportCall(with:endedAt:reason:) with reason CXCallEndedReason.failed
        //Failure to inform CallKit a couple of times and iOS 13 will block app from receiving VoIP push.
    }
}
...
@end
```

#### ** Swift Code **

```swift
...
import MobileSDK
import PushKit
...

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate {

    // Will be invoked when VoIP push notification is received.
    @available(iOS, introduced: 10, deprecated: 11)
    func pushRegistry(_ registry: PKPushRegistry, didReceiveIncomingPushWith payload: PKPushPayload, for type: PKPushType) {
        // Push Notification is received. Inform the SDK.
        self.sendPushMessage(payload: payload, completion: nil)
    }
    
    @available(iOS 11, *)
    func pushRegistry(_ registry: PKPushRegistry, didReceiveIncomingPushWith payload: PKPushPayload, for type: PKPushType, completion: @escaping () -> Void) {
        // Push Notification is received. Inform the SDK.
        self.sendPushMessage(payload: payload, completion: completion)
    }
    
    func sendPushMessage(payload: PKPushPayload, completion: (()->())?) {
        //Parsing push notification
        let pushService = SMServiceProvider.getInstance().getPushService()
        var callKitInfo = pushService.parsePushNotification(payload.dictionaryPayload)
        if (callKitInfo.error == nil) {
            //Inform CallKit about the incoming call with callKitInfo.callUUID and callKitInfo.callerDisplayInfo 
            // CXProvider reportNewIncomingCall(with:update:completion:) 
            //Failure to inform CallKit a couple of times and iOS 13 will block app from receiving VoIP push.
            if SMServiceProvider.getInstance().getRegistrationService().getRegistrationState() == .registered {
                pushService.injectPushMessage(pushData, completionHandler: notificationCompletion)
            } else {
                // note: set your configurations before registration
                SMServiceProvider.getInstance().getRegistrationService().register(toServer: [SMServiceTypes.getCallService()], expirationTime: 3600, completionHandler: { error in
                    if error != nil {
                        // handle the error
                    } else {
                        let notificationCompletion = { error in
                            if error != nil {
                            // handle the error
                            }

                            if completion != nil {
                                completion()
                            }
                        }
                        pushService.injectPushMessage(pushData, completionHandler: notificationCompletion)
                    }
                })
            }
        } else {
            //Inform CallKit about the failed incoming call.
            // 1- CXProvider reportNewIncomingCall(with:update:completion:)
            // 2- CXProvider reportCall(with:endedAt:reason:) with reason CXCallEndedReason.failed
            //Failure to inform CallKit a couple of times and iOS 13 will block app from receiving VoIP push.
        }
    }

    ...
}
```
<!-- tabs:end -->

### Standard Push Notification Callback

###### Warning

We highly suggested that call applications use only CallKit for an incoming call. Using custom incoming call screens is discouraged.

Also we SDK generates uniq UUID for any call. We suggest the applications use that ID to report calls to the CallKit. Both pushParser and Incoming Call Delegate has this UUID parameter.

##### Sample Usage

###### Push Usage

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
...
#import <PushKit/PushKit.h> 
#import <MobileSDK/MobileSDK.h>
  
NSObject *callKitInfo = [pushService parsePushNotification:pushMessage];
 [provider reportNewIncomingCallWithUUID:callKitInfo.callUUID update:update completion:^(NSError * _Nullable error){ 
// Maintain UI
}]
...
@end
```

#### ** Swift Code **

```swift
...
import MobileSDK
import PushKit
...

var callKitInfo:NSObject = pushService.parsePushNotification(NSDictionary:pushMessage)
provider.reportNewIncomingCallWithUUID:callKitInfo.callUUID update:update completion:^(NSError * _Nullable error){ 
// Maintain UI
}
```
<!-- tabs:end -->

###### Incoming Call Delegate Usage 

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
...
#import <PushKit/PushKit.h> 
#import <MobileSDK/MobileSDK.h>
  
-(void) incomingCall:(id<SMIncomingCallDelegate>)call
{
NSUUID *callUUID = [[NSUUID alloc] initWithUUIDString:call.Id];
[provider reportNewIncomingCallWithUUID:callUUID update:update completion:^(NSError * _Nullable error){ 
// Maintain UI
}
}]
...
@end
```

#### ** Swift Code **

```swift
...
import MobileSDK
import PushKit
...



func incomingCall:(id<SMIncomingCallDelegate>)call{
var callUUID: NSUUID = call.id
provider.reportNewIncomingCallWithUUID:callUUID update:update completion:^(NSError * _Nullable error){ 
// Maintain UI
   }
}
```
<!-- tabs:end -->

If Standard push registration is completed successfully and subscribed to push channels with the correct device push token, device now should receive Standard push notifications. Standard push notifications are special type silent `Gone` notifications. Silent notifications are low priority and needs to be handled by app. Silent notifications which will not provide any alert on iOS device to end-user, include subscription cancellation messages. Silent notifications needs to handled by implementing `application(_:didReceiveRemoteNotification:fetchCompletionHandler:)`. 

For more information please refer [background notifications](https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/pushing_background_updates_to_your_app?language=objc).

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
 ...
#import <MobileSDK/MobileSDK.h>
#import <UserNotifications/UserNotifications.h> 
  
@interface AppDelegate : UIResponder <UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate>
...
@end
  
@implementation AppDelegate 
...
// Will be invoked when a silent notification comes.
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    //Implement necessary business logic like deleting user subscription or re-subscribe.
    completionHandler(UIBackgroundFetchResultNewData);
}
...
@end
```

#### ** Swift Code **

```swift
...
import MobileSDK
import UserNotifications
...

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, PKPushRegistryDelegate, UNUserNotificationCenterDelegate {
    ...
    // Will be invoked when a silent notification comes. 
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        //Implement necessary business logic like deleting user subscription or re-subscribe.
        completionHandler(.newData)
    }
    ...
}
```
<!-- tabs:end -->

### Handling Push Subscription Events

Push subscription can be removed from the server side by the system admin. In this case client will receive a notification which indicates that the push subscription is invalidated. In order to handle this notification, app should conform to `SMPushSubscriptionDelegate` by implementing `pushSubscriptionInvalidated` and this delegate should be registered to `SMPushService`by using `pushSubscriptionDelegate`.

**Note:**  If the  `pushSubscriptionInvalidated`  notification received, Mobile SDK will just inform the application layer via this delegate method. Application side will be responsible of the remaining logic (i.e. it can try to re-subscribe to push notifications).

###### Example: Implementing PushSubscriptionDelegate

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

@interface PushModule ()
@end

@implementation PushModule <SMPushSubscriptionDelegate>

__strong static PushModule *_instance;

+ (PushModule *) sharedInstance{
    @synchronized(_instance) {
        if(!_instance){
            _instance = [[self alloc] init];
            [[[SMServiceProvider getInstance] getPushService] setPushSubscriptionDelegate:_instance];
        }
        return _instance;
    }
}

#pragma mark SMPushSubscriptionDelegate methods

- (void) pushSubscriptionInvalidated:(NSString *)subscriptionID {
    //  push subscription which has given subscriptionID is invalidated by the server,
    // client needs to re-subscribe to push channel. No more push notifications will be received
    // until client subscribes to push service again.
}

@end
```

#### ** Swift Code **

```swift
import MobileSDK

var _instance: PushModule?

class PushModule<SMPushSubscriptionDelegate> {
    class func sharedInstance() -> PushModule? {
        let lockQueue = DispatchQueue(label: "_instance")
        lockQueue.sync {
            if _instance == nil {
                _instance = self.init()
                SMServiceProvider.getInstance().getPushService().pushSubscriptionDelegate = _instance
            }
            return _instance
        }
    }

// MARK: SMPushSubscriptionDelegate methods
    func pushSubscriptionInvalidated(_ subscriptionID: String?) {
        //  push subscription which has given subscriptionID is invalidated by the server,
        // client needs to re-subscribe to push channel. No more push notifications will be received
        // until client subscribes to push service again.
    }
}
```
<!-- tabs:end -->

<div class="page-break"></div>

## Public Request Service

Sending requests via Kandylink with the parameters given in the appropriate format.

### Fetch API

Kandylink needs three parameters to use this API.

* **RequestInfo:** RequestInfo includes the information required in the request's body to be sent
* **ResourceURL:** ResourceURL is the information of which endpoint the request will be sent to
* **MethodType:** MethodType defines which REST method type will use (Get, Put, Post, Delete)

###### Example: Sending Public Request 

```objectivec
#import <MobileSDK/MobileSDK.h>

NSString * serviceURL = @"/example";
NSDictionary *requestInfo = @{@"test":@"123",@"name":"surname"} ;

    [[[SMServiceProvider getInstance] getPublicRequestService] fetch:serviceURL withMethodType:POST withRequestInfo:requestInfo completionHandler:^(NSDictionary * _Nullable fetchResponse, SMMobileError * _Nullable error) {
        if (error){
            //Handle error
            SPLog(@"Got Error in FetchResponse : %@",error);

        }else{
            // Handle fetch response and parsing dictionary
            SPLog(@"FetchResponse : %@", fetchResponse);
        }
    }];

```
```swift
import MobileSDK

let serviceURL = "/example"
let requestInfo = [
    "test": "123",
    "name": "surname"
]

SMServiceProvider.getInstance().getPublicRequestService().fetch(serviceURL, withMethodType: POST, withRequestInfo: requestInfo) { fetchResponse, error in
    if let error = error {
        //Handle error
        SPLog("Got Error in FetchResponse : %@", error)
    }else{
        // Handle fetch response and parsing dictionary
        SPLog(@"FetchResponse : %@", fetchResponse)
    }
}

```



## Appendices

### Appendix A: High-level Mobile SDK structure

The following image illustrates the high-level Mobile SDK structure and its sub-modules.

![alt text](images/appendix_a_1.png "")

<div class="page-break" />

### Appendix B: Call state transitions

The following diagram and table describe call state transitions and the methods available for each call state.

The Mobile SDK allows only one active request per call. Additional requests will be rejected if a request is already being processed. End Call requests are the exception and may be triggered at any time.

Unacceptable invocations from the application will also be rejected to prevent the application from crashing. Incorrect notification sequences will be disabled.

The call state becomes INITIAL after the call object is created. The call state becomes ENDED after the call is disposed.

#### Incoming call state transitions

![alt text](images/appendix_b_1.png "")

<div class="page-break" />

###### Method availability

| Call State       | Available methods                                                |
|------------------|------------------------------------------------------------------|
| INITIAL          | Automatically changes state                                   |
| RINGING          | accept / ignore / reject                                                         |
| ANSWERING          | endCall                                                         |
| IN_CALL          | videoStart / videoStop / mute / unmute / hold / switchCamera / transfer / merge / endCall  |
| ON_HOLD    | unhold / transfer / consultativeTransfer / merge / endCall                          |
| ON_DOUBLE_HOLD    | unhold / transfer / merge / endCall                          |
| REMOTELY_HELD    | videoStart / videoStop / mute / unmute / hold / merge / switchCamera / endCall  |
| ENDED            | No operation is allowed                                          |


#### Outgoing call state transitions

![alt text](images/appendix_b_2.png "")

<div class="page-break" />

###### Method availability

| Call State       | Available methods                                                |
|------------------|------------------------------------------------------------------|
| INITIAL          | establish                                                        |
| DIALING          | endCall                                                          |
| SESSION_PROGRESS | endCall                                                          |
| RINGING          | endCall                                                         |
| IN_CALL          | videoStart / videoStop / mute / unmute / hold / switchCamera / transfer / merge / endCall  |
| ON_HOLD    | unhold / transfer / consultativeTransfer / merge / endCall                          |
| ON_DOUBLE_HOLD    | unhold / transfer / merge / endCall                          |
| REMOTELY_HELD    | videoStart / videoStop / mute / unmute / hold / switchCamera / merge / endCall  |
| ENDED            | No operation is allowed                                          |

<div class="page-break" />

### Appendix C: Performance management

The following impacts should be considered when managing your mobile application's performance:

* The default video codec defined by the WebRTC code base is VP8. VP8 may have performance issues on the iOS platform, resulting in high CPU usage, increased battery usage, and a heat increase on devices with less surface area for cooling. Alternative solutions to eliminate or lessen the impact of this behavior include:

  * Using another codec (for example, H264 provides better CPU performance)

  * Using lower video resolution and fps (frame per second) in video calls

* Cellular network connectivity is directly related to the transmission level of data and therefore can impact the quality and the performance of audio/video calls. The WebRTC code base attempts to adjust network transmission capacity, but it is still possible to observe low video resolution and freezing videos while using cellular network connectivity.

<div class="page-break" />

### Appendix D: Detailed Configurations

This section contains usage of all configurations that Mobile SDK provides.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>

- (void) manageConfiguration
{
    //access SMConfiguration instance
    SMConfiguration * configuration =  [SMConfiguration getInstance];

    //set minimum Configuration values
    //user name for authorization
    configuration.userName = @"username";
    //password for authorization
    configuration.password = @"password";
    //server IP value for SPiDR/Kandy Link
    configuration.restServerIP = @"$SUBSCRIPTIONFQDN$";
    //server port value for SPiDR/Kandy Link
    configuration.restServerPort = @"443";
    //logger implementation defined by application
    configuration.logger = nil;

    //IP used in websocket connection creation
    configuration.webSocketServerIP = @"$WEBSOCKETFQDN$";
    //port used in websocket connection creation
    configuration.webSocketServerPort = @"443";

    //SPiDR TURN server in WebRTC's peer connection
    SMICEServers *iceServers = [[SMICEServers alloc] init];
    [servers addICEServer:@"$TURNSERVER1$"];
    [servers addICEServer:@"$TURNSERVER2$"];
    [servers addICEServer:@"$STUNSERVER1$"];
    [servers addICEServer:@"$STUNSERVER2$"];

    configuration.ICEServers = iceServers;

    //Integer value in seconds to limit the ICE collection duration. Default is 0 (no timeout)
    configuration.ICECollectionTimeout = 4;

    //Set one of the ice candidate negotiation types (ICE_VANILLA or ICE_TRICKLE)
    //The default is ICE_VANILLA
    configuration.iceOption = ICE_TRICKLE;

    //Set supported call features (ringing feedback)
    //SPiDR server must support this feature
    configuration.ringingFeedbackOption = CLIENT;

    //Configure WebRTC audio sessions
    SMAudioSessionConfiguration *audioSessionConfig = [[SMAudioSessionConfiguration alloc] init];
    audioSessionConfig.mode = AVAudioSessionModeVideoChat;
    audioSessionConfig.category = AVAudioSessionCategoryPlayAndRecord;
    audioSessionConfig.categoryOptions = AVAudioSessionCategoryOptionDefaultToSpeaker;

    //Set WebRTC audio session configuration
    configuration.audioSessionConfiguration = audioSessionConfig;

    // Audit Configuration. Default value is 30 secs.
    configuration.auditFrequency = 30;
}
```

#### ** Swift Code **

```swift
import MobileSDK

func manageConfiguration() {
    //access SMConfiguration instance
    let configuration = SMConfiguration.getInstance()

    //set minimum Configuration values
    //user name for authorization
    configuration.userName = "username"
    //password for authorization
    configuration.password = "password"
    //server IP value for SPiDR/Kandy Link
    configuration.restServerIP = "$SUBSCRIPTIONFQDN$"
    //server port value for SPiDR/Kandy Link
    configuration.restServerPort = "443"
    //logger implementation defined by application
    configuration.logger = self

    //IP used in websocket connection creation
    configuration.webSocketServerIP  = "$WEBSOCKETFQDN$"
    //port used in websocket connection creation
    configuration.webSocketServerPort  = "443"

    //SPiDR TURN server in WebRTC's peer connection
    let iceServers = SMICEServers()
    iceServers.addICEServer("$TURNSERVER1$")
    iceServers.addICEServer("$TURNSERVER2$")
    iceServers.addICEServer("$STUNSERVER1$")
    iceServers.addICEServer("$STUNSERVER2$")

    configuration.iceServers = iceServers;

    //Integer value in seconds to limit the ICE collection duration. Default is 0 (no timeout)
    configuration.iceCollectionTimeout = 4

    //Set one of the ice candidate negotiation types (ICE_VANILLA or ICE_TRICKLE)
    //The default is ICE_VANILLA
    configuration.iceOption = .trickle;

    //Set supported call features (ringing feedback)
    //SPiDR server must support this feature
    configuration.ringingFeedbackOption = CLIENT;

    //Configure WebRTC audio sessions
    let audioSessionConfig = SMAudioSessionConfiguration()
    audioSessionConfig.mode = AVAudioSessionModeVideoChat
    audioSessionConfig.category = AVAudioSessionCategoryPlayAndRecord
    audioSessionConfig.categoryOptions = AVAudioSessionCategoryOption.defaultToSpeaker

    //Set WebRTC audio session configuration
    configuration.audioSessionConfiguration = audioSessionConfig

    // Audit Configuration. Default value is 30 secs.
    configuration.auditFrequency = 30;
}
```
<!-- tabs:end -->

<div class="page-break" />

### Appendix E: Obtaining a HMAC Token

HMAC Token is a token that allows you to register on the SPiDR/Kandy Link server. This section contains information about how to obtain a HMAC Token from SPiDR/Kandy Link server. In order to obtain HMAC token, the user to receive HMAC token must have the necessary settings made on the Kandy Link web portal. The adapter and authentication scheme key values obtained as a result of the settings made on the portal will be used to obtain the HMAC token. 

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import "CryptoUtils.h"

- (void) obtainHMACToken
{
    // Sample required variables
    NSString *server = @"lab.kandy.io";
    NSString *user = @"joedoey@kandy.io";
    NSString *adapter = @"SampleAdapter";
    NSString *schemeKey = @"SampleSchemeKey";

    NSData *requestBody = [createRequestBodyWithUser: user];

    // Create a HMAC key with request body and scheme key
    NSString *hmacKey = [hmacSHA1forData:requestBody withKey:schemeKey];

    // Create the URL to send the REST request
    NSURL* url = [NSURL URLWithString:[NSString stringWithFormat:@"https://%@/rest/version/1/application/%@/authenticationToken",server,adapter]];

    // Create the request object
    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:url cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:15.0];
    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [request setValue:hmac forHTTPHeaderField:@"hmac"]; // Add the HMAC key to request as a header.
    [request setHTTPBody:jsonData];

    // Execute the REST request
    [NSURLConnection sendAsynchronousRequest:request queue:[[NSOperationQueue alloc] init] completionHandler:^(NSURLResponse* response,NSData* data,NSError* error)
     {
        if (error!=nil) {
            NSLog(@"Retrieving token from server is failed. Error: %@",error);
            // Handle the error
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            
            if (httpResponse.statusCode != 201) {
                NSError *error = [NSError
                                  errorWithDomain:@"KandyIO"
                                  code:1
                                  userInfo:@{
                                      NSLocalizedDescriptionKey:[NSString stringWithFormat:@"Fail response returned from server. Response code: %ld",(long)httpResponse.statusCode]
                                  }];
                // Handle the error
            } else {
                NSDictionary *resultsDictionary = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:&error];
                NSDictionary *responseBody = [resultsDictionary objectForKey:@"authenticationTokenResponse"];
                NSString *token = [responseBody objectForKey:@"token"];
                
                NSLog(@"Retrieving token from server successfully. Token: %@", token);
                
                // Use the generated token as you wish
            }
        }
     }];
}

- (NSData*) createRequestBodyWithUser:(NSString *)user {
    
    // Split the user address
    NSString *subscriberId = [[user componentsSeparatedByString:@"@"] firstObject]; // joedoey
    NSString *organizationId = [[user componentsSeparatedByString:@"@"] lastObject]; // kandy.io

    // Create request body
    // Request body format:
    // {
    //    "authenticationTokenRequest":
    //        {
    //            "subscriberId":"joedoey",
    //            "organizationId":"kandy.io"
    //        }
    //  }
    NSDictionary *subscriberDict = @{ @"subscriberId": subscriberId, @"organizationId": organizationId };
    NSDictionary *tokenRequestDict = @{ @"authenticationTokenRequest": subscriberDict };

    // Serialize the request body dictionary as JSON.
    NSError *error;
    NSData *requestBody = [NSJSONSerialization dataWithJSONObject:tokenRequestDict options:nil error: &error];

    if (error) {
        // Handle the error
    }

    return requestBody;
}

// Encrypts the given data using the HMAC SHA1 algorithm
// See about HMAC SHA1, [CCHMAC Documentation](https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/CCHmac.3cc.html)
- (NSString*) hmacSHA1forData:(NSData*)data withKey:(NSString *)key {
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData *hMacOut = [NSMutableData dataWithLength:CC_SHA1_DIGEST_LENGTH];

    CCHmac(kCCHmacAlgSHA1, keyData.bytes, keyData.length, data.bytes, data.length, hMacOut.mutableBytes);

    NSString *hexString = @"";
    if (data) {
        uint8_t *dataPointer = (uint8_t *)(hMacOut.bytes);
        for (int i = 0; i < CC_SHA1_DIGEST_LENGTH; i++) {
            hexString = [hexString stringByAppendingFormat:@"%02x", dataPointer[i]];
        }
    }

    return hexString;
}
```

#### ** Swift Code **

```swift
import CryptoUtils

func obtainHMACToken() {
    // Sample required variables
    let server = "lab.kandy.io"
    let user = "joedoey@kandy.io"
    let adapter = "SampleAdapter"
    let schemeKey = "SampleSchemeKey"

    let requestBody = createRequestBody(user)

    // Create a HMAC key with request body and scheme key
    let hmacKey = hmacSHA1forData(requestBody, withKey: schemeKey)

    // Create the URL to send the REST request
    let url = URL(string: "https://\(server)/rest/version/1/application/\(adapter)/authenticationToken")

    // Create the request object
    let request = NSMutableURLRequest(url: url, cachePolicy: .useProtocolCachePolicy, timeoutInterval: 15.0)
    request.httpMethod = "POST"
    request.setValue("application/json", forHTTPHeaderField: "Content-Type")
    request.setValue(hmac, forHTTPHeaderField: "hmac") // Add the HMAC key to request as a header.
    request.httpBody = jsonData

    // Execute the REST request
    NSURLConnection.sendAsynchronousRequest(request, queue: OperationQueue(), completionHandler: { response, data, error in
        
        if let error = error {
            print("Retrieving token from server is failed. Error: \(error)")
            // Handle the error
        } else {
            let httpResponse = response as? HTTPURLResponse

            if httpResponse.statusCode != 201 {
                let error = NSError(domain: "SPiDRMobile", code: 1, userInfo: [
                    NSLocalizedDescriptionKey: String(format: "Fail response returned from server. Response code: %ld", httpResponse.statusCode)
                ])
                // Handle the error
            } else {
                var resultsDictionary: [AnyHashable : Any]? = nil
                do {
                    resultsDictionary = try JSONSerialization.jsonObject(with: data, options: .mutableLeaves) as? [AnyHashable : Any]
                } catch {
                    // Handle the error
                }
                let responseBody = resultsDictionary?["authenticationTokenResponse"] as? [AnyHashable : Any]
                let token = responseBody?["token"] as? String

                print("Retrieving token from server successfully. Token: \(token ?? "null token")")

                // Use the generated token as you wish
            }
        }
    })
}

func createRequestBody(_ user: String) -> Data? {

    // Split the user address
    let subscriberId = user.components(separatedBy: "@").first // joedoey
    let organizationId = user.components(separatedBy: "@").last // kandy.io
    
    // Create request body
    // Request body format:
    // {
    //    "authenticationTokenRequest":
    //        {
    //            "subscriberId":"joedoey",
    //            "organizationId":"kandy.io"
    //        }
    //  }
    let subscriberDict = [
        "subscriberId": subscriberId,
        "organizationId": organizationId
    ]
    let tokenRequestDict = [
        "authenticationTokenRequest": subscriberDict
    ]

    // Serialize the request body dictionary as JSON.
    var requestBody: Data? = nil
    do {
        requestBody = try JSONSerialization.data(withJSONObject: tokenRequestDict, options: nil)
    } catch {
        // Handle the error
    }

    return requestBody
}

// Encrypts the given data using the HMAC SHA1 algorithm
// See about HMAC SHA1, https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/CCHmac.3cc.html
func hmacSHA1forData(_ data: Data, withKey key: String) -> String {
    let keyData = key.data(using: .utf8)
    var hMacOut = Data(length: CC_SHA1_DIGEST_LENGTH)

    CCHmac(kCCHmacAlgSHA1, keyData.bytes, keyData.length, data.bytes, data.length, hMacOut.mutableBytes)

    var hexString = ""
    if data {
        let dataPointer = UnsafePointer<UInt8>(UInt8(hMacOut.bytes))
        for i in 0..<CC_SHA1_DIGEST_LENGTH {
            hexString = hexString + String(format: "%02x", dataPointer[i])
        }
    }

    return hexString
}

```
<!-- tabs:end -->

<div class="page-break" />

### Appendix F: Obtaining a CVImageBufferRef object

CVImageBufferRef is a kind of buffer type which is provided by CoreVideo framework on iOS. This section contains information on how to get CVImageBufferRef object with RTSP URL. We need a decoder architecture to get frames from RTSP stream. There are several frameworks that can do it such as Gstreamer, FFmpeg, Live555, EasyRTSP, etc.

These frameworks are using their own decoding structure, but in general, they are all the same. The logic is to get an RTSP URL and decode NAL units inside this stream, and the NAL unit converting process is the same for all. 

In order to use EasyRTSP, the following frameworks should be added to the project.

* VideoToolBox.framework
* CoreMedia.framework
* SystemConfiguration.framework
* MediaPlayer.framework
* Foundation.framework
* Security.framework
* libswresample.a
* libc++.tbd
* libavfilter.a
* libz.tbd
* libavdevice.a
* libavformat.a
* libswscale.a
* libiconv.tbd
* libbz2.tbd
* libEasyRTSPClient.a
* libavutil.a
* libavcodec.a

EasyRTSP is used in the example below.

<!-- tabs:start -->

#### ** Objective-C Code **

```objectivec
#import <MobileSDK/MobileSDK.h>
#import "PlayerDataReader.h"
#import "HWVideoDecoder.h"

 PlayerDataReader *decoder;
 SMCallDelegate *call;

- (void) getVideoStream {
    EasyRTSP_Activate("EasyPlayer key is free!");
    [PlayerDataReader startUp]; 
    decoder = [[PlayerDataReader alloc] initWithUrl:@"Your RTSP URL"];
    decoder.useHWDecoder = YES; 
    decoder.transportMode = EASY_RTP_OVER_TCP; 
    decoder.sendOption = YES; 
    [decoder start];
}

// Starts external video stream
[call setVideoSourceType:EXTERNAL_VIDEO];
[self getVideoStream];
decoder.videoFrameOutputBlock = ^(CVImageBufferRef *imageBuffer) {
        [call setExternalVideoSource:*imageBuffer];
    };

```

#### ** Swift Code **

```swift
import MobileSDK

var decoder: PlayerDataReader
var call: SMCallDelegate

func getVideoStream() {
 EasyRTSP_Activate("EasyPlayer key is free!")
 PlayerDataReader.startUp;
 decoder = PlayerDataReader(initWithUrl: "rtsp://171.25.232.18/jibxjyTXkaG2DYRXGrBIZ3rGeFT0Si")
 decoder.useHWDecoder = true
 decoder.transportMode = EASY_RTP_OVER_TCP
 decoder.sendOption = true
 decoder.start
}

// Starts external video stream
call.videoSourceType = .externalVideo
self.getVideoStream()
decoder.videoFrameOutputBlock = ^(CVImageBufferRef *imageBuffer) {
        call.setExternalVideoSource(CVImageBufferRef: imageBuffer)
    }


```
<!-- tabs:end -->

<div class="page-break" />
