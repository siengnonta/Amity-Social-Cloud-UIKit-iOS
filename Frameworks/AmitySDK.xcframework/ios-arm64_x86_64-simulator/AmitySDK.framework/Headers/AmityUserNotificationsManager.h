//
//  AmityUserNotificationsManager.h
//  AmitySDK
//
//  Created by Federico Zanetello on 6/5/19.
//  Copyright © 2019 amity. All rights reserved.
//

#import <AmitySDK/AmityUserNotificationSettings.h>

/**
 @abstract Responsible to manage the user level push notification settings.
 */
@interface AmityUserNotificationsManager : NSObject

typedef void (^AmityUserNotificationCompletion)(AmityUserNotificationSettings * _Nullable notificationModel, NSError * _Nullable error);

/**
 @abstract The completion block type.
 @discussion As these push notifications settings are per user and not per device,
 any request will go through the backend.
 
 @param success The outcome of the callback.
 @param error (optional) The error from the backend.
 */
typedef void (^AmityRequestCompletion)(BOOL success,
                                       NSError * _Nullable error);

/**
 @abstract Enable the user level push notification setting.
 @note This setting will take effect on every device used by the user.
 
 @param modules An array of modules that consishts of `chat`, `social` and `video-streaming`.
 @param completion A block executed when the request has completed.
 */
- (void)enableForModules:(nullable NSArray<AmityUserNotificationModule *> *)modules completion:(nullable AmityRequestCompletion)completion;

/**
 @abstract Disable the user level push notification setting.
 @note This setting will take effect on every device used by the user.
 
 @param completion A block executed when the request has completed.
 */
- (void)disableWithCompletion:(nullable AmityRequestCompletion)completion;

/**
 @abstract Retrieve the user level push notification state.
 @note This setting is per user, not per device.
 
 @param completion A block executed when the request has completed.
 */
- (void)getSettingsWithCompletion:(nullable AmityUserNotificationCompletion)completion;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end
