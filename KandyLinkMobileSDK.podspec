Pod::Spec.new do |s|
    s.name              = 'KandyLinkMobileSDK'
    s.version           = '5.0.0'
    s.summary           = 'Kandy Link MobileSDK Framework'
    s.homepage          = 'https://github.com/Kandy-IO/kandy-link-ios-sdk'
    s.license 		      = { :type => 'MIT', :file => 'mit-license.txt'}
    s.author            = { 'Name' => 'cpaassdk@netas.com.tr' }
    s.platform          = :ios
    s.source            = { :git => 'https://github.com/Kandy-IO/kandy-link-ios-sdk.git', :tag => '5.0.0'}
    s.dependency 	      = 'KandyWebRTC'
    s.ios.deployment_target   = '9.0'
    s.ios.frameworks = ['AvFoundation','SystemConfiguration','GLKit','VideoToolbox','AudioToolbox','PushKit']
    s.library = ['c++','icucore','z']
    s.vendored_frameworks = ['MobileSDK.framework', 'WebRTC.framework']
    s.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
    	"OTHER_LDFLAGS" => '$(inherited) -framework WebRTC -ObjC',
    	"CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => 'YES',
    	"FRAMEWORK_SEARCH_PATHS" => '$(inherited) "${PODS_ROOT}/KLCPaaSWebRTC/Frameworks"'
   }



end
