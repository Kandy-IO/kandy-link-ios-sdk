# Change Log

Kandy Link iOS SDK change log.

- This project adheres to [Semantic Versioning](http://semver.org/).
- This change log follows [keepachangelog.com](http://keepachangelog.com/) recommendations.

## 6.8.1 - 2022-08-11
### Fixed
- Custom SIP headers return bug is fixing. `KAE-1455`

## 6.8.0 - 2022-31-10

### Added
- Added c flags to not create selector stubs, which is a feature that comes with Xcode 14. `KAE-1347`
- Registration Service and Notification Manager refactored. `KAE-1351`

### Fixed
- iOS 16 WebSocket crash fixed with changing NSURLNetworkServiceType which is not depracated. `KAE-1367`
- Rollback operation crash fixed. `KAE-1453`

## 6.7.0 - 2022-3-10

### Added
- Push parser implemented. `KAE-1349`

### Fixed
- Invalid custom parameter parsing bug is fixing. `KAE-1366`
- SDK Will restart ICE when failed state received. `KAE-1263`

## 6.6.0 - 2022-31-08

### Added
- Video mute/unMute API. `KAE-1338`

## 6.5.0 - 2022-02-08

### Fixed
- Local Video corrupted stream fixed. `KAE-1278`

## 6.4.0 - 2022-28-06
    
### Added
- Streaming from external video sources support added. `KAE-1278`

### Removed
- The SDK no longer will not operate the re-register operation when it receive gone notification. `KAE-1258`

### Changed
- Input parameters of `ringingFeedbackOption` changed as below; `KAE-1267`
    - CLIENT to APP
    - NONE to AUTO

## 6.3.0 - 2022-27-05

## 6.2.0 - 2022-25-04
- Swift Package Manager support added.

## 6.1.0 - 2022-28-03

## 6.0.0 - 2022-28-02

### Added
- Upgrading WebRTC to M97. `KAE-1153`
    - With the M97 upgrade, WebRTC backward compatibility is broken, so there might be problem with Cisco and Transfer calls.
### Fixed
- Null sdpFormat crash is fixed `KAE-1070`
- Call state after consultative transfer is fixed `KAE-1014` `KAE-1020`

## 5.24.0 - 2022-03-01

### Added 
- Public Request API. `KAE-1165`

## 5.23.0 - 2021-03-11

### Removed
- `setRingingFeedbackEnabled(boolean ringingFeedbackEnabled)` was removed.
- `isRingingFeedbackEnabled()` was removed.

### Known Issues

- Build issues on systems using Apple Silicon M1 chip.

## 5.22.0 - 2021-09-27

### Known Issues

- Build issues on systems using Apple Silicon M1 chip.

## 5.21.0 - 2021-08-16

### Fixed
- Duplicate symbols issue on manuel SDK installation is fixed. `KAE-1048`

## 5.20.0 - 2021-06-29

### Added
- Remote video scaling type change support added.

## 5.19.0 - 2021-06-01

### Added
- Authentication with hmac token support added.

## 5.18.0 - 2021-04-26

### Removed
- BlackBerry Dynamics Support was removed.

## 5.17.0 - 2021-03-26

### Added
- XCFramework support was added
- `(NSArray<NSDictionary *> *) getAvailableCodecs:(SMCodecType)codecType` added to SMCallDelegate class in order to get available codec attributes.

## 5.16.0 - 2021-02-26

### Removed
- `registerToServer:(nonnull NSArray<NSString *> *)serviceTypes expirationTime:(NSInteger) expirationTime completionHandler:(void (^_Nullable)(SMMobileError * _Nullable error))completionBlock` is removed.

### Fixed
- Use Manual Audio Mode automatically turns on after ended call issue is fixed. `KAE-940`

## 5.15.0 - 2021-02-04

### Deprecated
- `isRingingFeedbackEnabled` and `setRingingFeedbackEnabled` added to Configuration class methods are deprecated and will be removed in future releases. Instead `ringingFeedbackOptions` and `setRingingFeedbackOptions` should be used. 

### Fixed
- WebRTC video orientation parameter should sync with Call Service video orientation is fixed. `KAE-916`

## 5.14.0 - 2020-12-30

### Deprecated
- `registerToServer:(nonnull NSArray<NSString *> *)serviceTypes expirationTime:(NSInteger) expirationTime completionHandler:(void (^_Nullable)(SMMobileError * _Nullable error))completionBlock` API in the SMRegistrationService will be deprecated in the version 5.16.0. But a new `registerToServer:(NSInteger)expirationTime completionHandler:(void (^_Nullable)(SMMobileError * _Nullable))completionBlock` is introduced. Therefore developers should take the necessary action. `KAE-806`

- `DTLS`, `securedWSProtocol`, `requestProtocolHttp`, `kandyVersion`, `kandyToken`, `deviceId`, `deviceNativeId`, `sendKandyTokenInRestHeader`,`subscriptionLocalization`,`stateChangesHandler`, `connectionType`, `auditEnable`, `supportedCallFeautes`, `notificationType` parameters removed from SMConfiguration class. `KAE-869`

### Added
- `isRingingFeedbackEnabled` and `setRingingFeedbackEnabled` added to SMConfiguration class in order to set and/or check ringing feedback feature.
- `registerToServer:(NSInteger)expirationTime completionHandler:(void (^_Nullable)(SMMobileError * _Nullable))completionBlock` API added to SMRegistrationService. `KAE-806`

### Renamed
- `replaceCodecSet` parameter renamed as `codecPayloadTypeSet` in SMConfiguration class. `KAE-869`

### Fixed
- The status of the call still display Remotely Held after unhold on caller issue is fixed. `KAE-884`

## 5.13.0 - 2020-12-02

### Fixed
- Default DTLS setting is set to false is fixed. `KAE-882`

## 5.12.0 - 2020-11-04

## 5.11.0 - 2020-10-05

### Changed
- Return type of `SMCall.getRTPStatistics` was changed as `NSString`

### Fixed
- Xcode 12 support was added

## 5.10.0 - 2020-08-28

## 5.9.0 - 2020-07-22

## 5.8.0 - 2020-07-03

## 5.7.0 - 2020-06-12

## 5.6.0 - 2020-05-04

### Fixed
- After Session Complete notification the end call DELETE request must be sent. `KAE-669`

## 5.5.0 - 2020-03-30

### Added
- New PushService parse api for CallKit was implemented `KAE-605`

## 5.4.0 - 2020-03-02

### Added
- Adding configuration property for control TCP keep alive `KAE-571`
- New PushService subscribe api was implemented `KAE-521`

## 5.3.0 - 2020-01-09

### Added
- Call forward feature `KAE-81`

### Fixed
- Background thread was trying to access UI thread is fixed. `KAE-580`


## 5.2.0 - 2019-11-29

### Added
- WebRTC stack upgraded to version M78 `KAE-508`
- Custom Kandy Agent HTTP Header is implemented `KAE-524`

## 5.1.0 - 2019-11-04


## 5.0.0 - 2019-10-03

### Added
- Unified Plan Support `KAE-428`
- Mobile SDK Distribution on CocoaPods `KAE-426`
- Support Custom SIP headers in Incoming Call `KAE-446`


## 4.6.1.1 - 2019-08-05

### Fixed
- VoiceActivityDetection is disabled on WebRTC layer `KAE-415`
- A fix provided for setting Push URL without a port number  `KAE-479`


## 4.6.1 - 2019-07-05

### Added
- Bandwidth limitation feature implemented `KAE-64`

### Fixed
- A fix provided for race condition case during WebRTC audio module creation when a second call session is being initiated. `KAE-435`
- A fix provided for 3-way call fail when early notification is received. `KAE-421`


## 4.6.0 - 2019-06-01

### Added
- PushService for CPaaS push notifications support. `KAE-350`

### Changed
- EventService is renamed as PushService. Its method `receiveNotification` which passes push notifications to Mobile SDK is replaced with `injectPushMessage`. `KAE-350`

### Fixed
- HTTP 4xx and 5xx responses are coded with a new error code and reported with MobileError. `KAE-288`


## 4.5.9 - 2019-05-02
