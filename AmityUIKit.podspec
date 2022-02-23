Pod::Spec.new do |s|
    s.name         = "AmityUIKit"
    s.version      = "2.11.0"
    s.summary      = "A brief description of AmityUIKit project."
    s.description  = "An extended description of AmityUIKit project."
    s.homepage     = "https://github.com/EkoCommunications/EkoMessagingSDKUIKit"
    s.license = { :type => 'Copyright', :text => <<-LICENSE
                   Copyright 2020
                   Permission is granted to...
                  LICENSE
                }
    s.author             = { "$(git config user.name)" => "$(git config user.email)" }
    s.source       = { :git => "https://github.com/siengnonta/Amity-Social-Cloud-UIKit-iOS.git", :tag => "v#{s.version}" }
    s.vendored_frameworks = 'Frameworks/AmityUIKit.xcframework', 'Frameworks/AmitySDK.xcframework'
    s.platform = :ios
    s.swift_version = "5"
    s.ios.deployment_target  = '12.0'
    s.dependency 'Realm', '~> 10.21.1'
    
end
