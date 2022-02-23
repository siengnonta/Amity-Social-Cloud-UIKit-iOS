//
//  AmityUserNotificationModule.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 10/3/2564 BE.
//  Copyright © 2564 BE amity. All rights reserved.
//

#import <AmitySDK/AmityRoleFilter.h>

typedef NS_ENUM(NSUInteger, AmityNotificationModuleType) {
    AmityNotificationModuleTypeChat = 1,
    AmityNotificationModuleTypeVideoStreaming,
    AmityNotificationModuleTypeSocial
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserNotificationModule : NSObject

@property (nonatomic, assign) AmityNotificationModuleType moduleType;
@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) AmityRoleFilter * _Nullable roleFilter;

/**
 Initializes module for push notification settings.
 
 @param isEnabled Whether or not the user would like to receive push notifications on the particular module.
 @param roleFilter (optional) A filter for determining which user role that the user would like to receive notification from. If nil provided, skip updating roles.
 */
- (instancetype)initWithModuleType:(AmityNotificationModuleType)moduleType
                         isEnabled:(BOOL)isEnabled
                        roleFilter:(nullable AmityRoleFilter *)roleFilter;

@end

NS_ASSUME_NONNULL_END
