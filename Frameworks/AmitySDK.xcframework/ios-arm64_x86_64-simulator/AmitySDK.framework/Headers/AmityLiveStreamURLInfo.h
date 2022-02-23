//
//  AmityLiveStreamURLInfo.h
//  AmitySDK
//
//  Created by Nutchaphon Rewik on 21/10/2563 BE.
//  Copyright © 2563 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// This class provides data of RTMP url.
///
/// The standard full url format can be found at `url` property.
///
/// For custom RTMP url formatting, please look into other properties in this class.
@interface AmityLiveStreamURLInfo : NSObject

/// The full RTMP url, that most RTMP players support.
@property (nonnull, strong, nonatomic) NSURL *url;

/// The origin in the url.
@property (nonnull, strong, nonatomic) NSString *origin;

/// The app name in the url.
@property (nonnull, strong, nonatomic) NSString *appName;

/// The stream name in the url.
@property (nonnull, strong, nonatomic) NSString *streamName;

/// The query parameters in the url.
@property (nonnull, strong, nonatomic) NSString *query;

+ (instancetype)makeFromWatcherUrlInfo:(NSDictionary<NSString *, id> *)watcherUrlInfo;

@end

NS_ASSUME_NONNULL_END
