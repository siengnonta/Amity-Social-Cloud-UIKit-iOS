//
//  AmityChannelNotificationsManager.h
//  AmitySDK
//
//  Created by Federico Zanetello on 6/5/19.
//  Copyright © 2019 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>

@class AmityChannelNotificationSettings;

/**
   @abstract Responsible to manage the channel level push notification settings.
 */
@interface AmityChannelNotificationsManager : NSObject

typedef void (^AmityChannelNotificationSettingsCompletion)(AmityChannelNotificationSettings * _Nullable notificationModel, NSError * _Nullable error);

/**
   @abstract Enables the channel level push notification setting.
   @note This setting will take effect on every device used by the user.

   @param completion A block executed when the request has completed.
 */
- (void)enableWithCompletion:(nullable AmityRequestCompletion)completion;

/**
   @abstract Disables the channel level push notification setting.
   @note This setting will take effect on every device used by the user.

   @param completion A block executed when the request has completed.
 */
- (void)disableWithCompletion:(nullable AmityRequestCompletion)completion;

/**
   @abstract Retrieve the current channel level push notification state.
   @note This setting is per user, not per device.

   @param completion A block executed when the request has completed.
 */
- (void)getSettingsWithCompletion:(nonnull AmityChannelNotificationSettingsCompletion)completion NS_SWIFT_NAME(getSettings(completion:));

/**
   Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end
