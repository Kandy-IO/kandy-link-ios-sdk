# Change Log

Kandy Link iOS SDK change log.

- This project adheres to [Semantic Versioning](http://semver.org/).
- This change log follows [keepachangelog.com](http://keepachangelog.com/) recommendations.

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
