Pod::Spec.new do |s|
    s.name              = 'KandyLinkMobileSDK'
    s.version           = '5.16.0'
    s.summary           = 'Kandy Link MobileSDK Framework'
    s.homepage          = 'https://github.com/Kandy-IO/kandy-link-ios-sdk'
    s.license 		    = { :type => 'MIT', :file => 'mit-license.txt'}
    s.author            = { 'Name' => 'cpaassdk@netas.com.tr' }
    s.platform          = :ios
    s.source            = { :git => 'https://github.com/Kandy-IO/kandy-link-ios-sdk.git', :tag => '5.16.0'}
    s.dependency  'KandyWebRTC'
    s.ios.deployment_target   = '10.0'
    s.library = ['c++','icucore','z']
    s.ios.frameworks = ['AVFoundation','SystemConfiguration','GLKit','VideoToolbox','AudioToolbox','PushKit']
    s.vendored_frameworks = ['MobileSDK.framework', 'WebRTC.framework']
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.pod_target_xcconfig = {
        'ENABLE_BITCODE' => 'NO',
        'OTHER_LDFLAGS' => '$(inherited) -framework WebRTC -ObjC',
        'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',
        'FRAMEWORK_SEARCH_PATHS' => '$(inherited)',
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
   }
end