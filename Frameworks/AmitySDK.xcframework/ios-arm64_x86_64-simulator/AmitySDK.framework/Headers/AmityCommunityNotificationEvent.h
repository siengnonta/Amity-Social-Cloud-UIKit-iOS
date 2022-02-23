//
//  EkoCommunityNotificationEventModel.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 3/3/2564 BE.
//  Copyright © 2564 BE amity. All rights reserved.
//

#import <AmitySDK/AmityRoleFilter.h>

typedef NS_ENUM(NSUInteger, AmityCommunityNotificationEventType) {
    AmityCommunityNotificationEventTypePostCreated = 1,
    AmityCommunityNotificationEventTypePostReacted,
    AmityCommunityNotificationEventTypeCommentCreated,
    AmityCommunityNotificationEventTypeCommentReplied,
    AmityCommunityNotificationEventTypeCommentReacted
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityNotificationEvent : NSObject

@property (nonatomic, strong) NSString *eventName;
@property (nonatomic, assign) AmityCommunityNotificationEventType eventType;
@property (nonatomic, assign) BOOL isNetworkEnabled;
@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) AmityRoleFilter * _Nullable roleFilter;

- (instancetype)initWithEventType:(AmityCommunityNotificationEventType)eventType
                        isEnabled:(BOOL)isEnabled
                       roleFilter:(nullable AmityRoleFilter *)roleFilter;

@end

NS_ASSUME_NONNULL_END
