//
//  AmityClient.h
//  AmitySDK
//
//  Created by amity on 1/18/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityClientErrorDelegate.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUserNotificationsManager.h>
#import <AmitySDK/AmityMentionConfigurations.h>

@class AmityUser;
@class AmityUserUpdateBuilder;
@class AmityEndpoint;
@protocol AmityClientDelegate;

typedef void (^AmityRequestCompletion)(BOOL success, NSError * _Nullable error);
typedef void (^AmityPermissionCompletion)(BOOL hasPermission);
typedef NS_ENUM(NSInteger, AmityRegion);

/**
 @abstract SDK entry point.
 @discussion A valid context instance should be used to create other SDK resources.
 @warning An instance of `AmityClient` should be initiated with an Application key and be retained by the caller.
 */
__attribute__((objc_subclassing_restricted))
@interface AmityClient : NSObject

/**
 @abstract Connection status.
 @note This property supports KVO.
 */
@property (readonly, nonatomic) AmityConnectionStatus connectionStatus;

/**
 @abstract The Id of the current user.
 */
@property (nullable, readonly, nonatomic) NSString *currentUserId;

/**
 @abstract The current user object.
 */
@property (nullable, readonly, nonatomic) AmityObject<AmityUser *> *currentUser;

/**
 @abstract User Level Notification Management object.
 */
@property (nonnull, readonly, nonatomic) AmityUserNotificationsManager *notificationManager;

/**
 @abstract Mention configurations object.
 */
@property (nullable, readonly, nonatomic) AmityMentionConfigurations* mentionConfigurations;

/**
 @abstract The (optional) delegate to listen to async errors (force logout, bad sessions, ...).
 */
@property (nullable, weak, nonatomic) id<AmityClientErrorDelegate> clientErrorDelegate DEPRECATED_MSG_ATTRIBUTE("This property will be removed in the future. Please use `delegate` property instead.");

/// You can implement this delegate to listen to various sdk events
/// such as bad session, global ban, connection status changes etc.
@property (nullable, weak, nonatomic) id<AmityClientDelegate> delegate;

/**
 @abstract Creates an instance of `AmityClient` with provided API key. If you want to specify the region to which this sdk should connect to, please use `init(apiKey:_region:_)` method. By default, this method uses .global region configuration
 
 @param apiKey API key provided by Amity.
 @return A valid client instance or nil on invalid API key.
 */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey
                                     error:(NSError * _Nullable * _Nullable)error;

/**
 @abstract Creates an instance of `AmityClient` with provided api key & multi-region data center support.
 
 @param apiKey ApiKey provided by Amity
 @param region The region to which this sdk connects to.
 @return A valid client instance or nil on invalid Api key.
 */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey region:(AmityRegion)region error:(NSError * _Nullable * _Nullable)error;

/**
 @abstract Creates an instance of `AmityClient` with provided API Key. Use this method only if you need extra configuration. If you don't need extra configuration use `init(apiKey:_)` or `init(apiKey:_, region:_)` method instead.
 
 @param apiKey: API key provided by Amity
 @param endpoint: AmityEndpoint instance which provides configuration for various url
 
 @return A valid instance of AmityClient
  */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey endpoint:(nonnull AmityEndpoint *)endpoint error:(NSError * _Nullable * _Nullable)error;

/**
 @abstract Creates an instance of `AmityClient` with provided API Key.

 @note
 If the provided value for `httptUrl` & `socketUrl` is empty, then default value would be used. You can also use one of the
 regional endpoint provided in `AmityRegionalEndpoint` class.
 
 @param apiKey: API key provided by Amity.
 @param httpUrl: Custom url to be used as base url.
 @param socketUrl: Custom url to be used as base url.
 @return A valid instance of AmityClient
 */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey
                                   httpUrl:(nonnull NSString *)httpUrl
                                 socketUrl:(nonnull NSString *)socketUrl
                                     error:(NSError * _Nullable * _Nullable)error DEPRECATED_MSG_ATTRIBUTE("This method will be removed in future. Please use `init(apiKey:_, region:_)` or `init(apiKey:_, endpoint:_)` instead");

/**
 @abstract Creates an instance of `AmityClient` with provided API Key.
 
 @note
 The provided value for url would be used for both http & socket request. If the provided value for `url` is empty, then default value would be used.
 You can also use one of the regional endpoint provided in `AmityRegionalEndpoint` class.
 
 @param apiKey: API key provided by Amity
 @param url: Custom url to be used as base url for both http & socket request.
 @return A valid instance of AmityClient
  */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey
                                       url:(nonnull NSString *)url
                                     error:(NSError * _Nullable * _Nullable)error DEPRECATED_MSG_ATTRIBUTE("This method will be removed in future. Please use `init(apiKey:_, region:_)` or `init(apiKey:_, endpoint:_)` instead");

/// Connect the SDK to the server, and activate the current session with `userId`. The system will create a new user, if `userId` does not exist.
///
/// @note AmitySDK supports one user session at a time. If `userId` is different than the current session, the SDK automatically logout the current session before starting the new one. To properly logout, please use the counterpart `client.logout()`.
///
/// @note The SDK  provides local caches that are bound to the session. When the session is destroyed, the SDK also purge all local caches
///
/// @note If display name is nil, then user id would be set as display name. You can update it later using `updateUser:` method.
///
/// @note Error occurred in this method will not be delivered through `clientErrorDelegate`. Please observe it using completion handler instead.
///
/// @param userId Id of the user
/// @param displayName Display name of the user. If display name is nil or empty, user id would be used as display name.
/// @param authToken Extra authentication token to be used for secure device registration. This is optional. Please refer to our Authentication documentation for further details.
/// @param completion Completion handler to be called when device registration is successful or failed.
///
- (void)loginWithUserId:(nonnull NSString *)userId
            displayName:(nullable NSString *)displayName
              authToken:(nullable NSString *)authToken
             completion:(nullable AmityRequestCompletion)completion
NS_SWIFT_NAME(login(userId:displayName:authToken:completion:));

/**
 @abstract Disconnect from the server without logging out the user.
 
 @discussion This function does not destroy the current user session. The SDK connection can be resumed, by calling `.login(...)` with the current userId.
 */
- (void)disconnect;

/**
 @abstract Disconnect from the server, and destroys the current user session. The SDK will delete all the local caches. Once this method is called, the only way to re-establish connection is to call `login` method again.
 
 @discussion The SDK will disconnect from the server immediately, the operation happens synchronously on the client side.
 
 @discussion The SDK will unregister push notifications of this device.
 */
- (void)logout;

/**
 @abstract Register the current device (and the current logged-in user) to receive
 push notifications.
 @discussion You can call this method as many times as you'd like: the last call
 will always override any precedent state.
 As long as you call this function with a valid token, and after succesfully
 registering the SDK, you're guaranteed to receive only push notifications related
 to the current logged in user.
 Call `unregisterDeviceForPushNotificationForUserId:completion:` to stop receiving
 notifications for this user.
 Succesfully calling this method will override any precedent state: if this device
 was previously registered with a different user, the device will no more get any
 notification related to that user.
 @warning Once succesfully registered, this app will continue to receive
 notifications related to this user until the `unregisterDeviceForPushWithCompletion:`
 or another registration is made.
 @param deviceToken A globally unique token that identifies this device to Apple
 Push Notification service.
 @param completion A block executed when the request has successfully completed.
 */
- (void)registerDeviceForPushNotificationWithDeviceToken:(nonnull NSString *)deviceToken
                                              completion:(nullable AmityRequestCompletion)completion;

/**
 @abstract Unregister the current device to stop receiving any push notifications
 related to the given user userId. If no user is passed, the backend will remove
 any push notification token associated with this device.
 @discussion Call this method when you no longer wish to receive notifications for
 the previously registered user (for example when the user logs out).
 @warning Make sure that the completion block is called with success state, otherwise
 the Amity backend will keep sending push notifications related to the previous user.
 @param userId The userId of the user of which the SDK should no longer receive
 notifications.
 @param completion A block executed when the request has successfully completed.
 */
- (void)unregisterDeviceForPushNotificationForUserId:(nullable NSString *)userId
                                          completion:(nullable AmityRequestCompletion)completion;

/**
 Updates current user
 
 @param builder: Builder class which provides methods to update user information. Only set information which you want to update
 @param completion: Completion handler which gets called after update is success or failure.
 */
- (void)updateUser:(nonnull AmityUserUpdateBuilder *)builder completion:(nullable AmityRequestCompletion)completion;

/**
 Checks whether the current user has permission or not.
 
 @param permission: Permission to check
 */
- (void)hasPermission:(AmityPermission)permission completion:(nonnull AmityPermissionCompletion)completion ;

/**
 Checks whether the current user has permission inside particular channel. This method checks for permission in
 global level as well as channel level.
 
 @param permission: Permission to check
 @param channelId: Id of the channel to check for
 @return: True if permission is granted else returns False
 */
- (void)hasPermission:(AmityPermission)permission forChannel:(nonnull NSString *)channelId completion:(nonnull AmityPermissionCompletion)completion;

/**
 Checks whether the current user has permission inside particular channel. This method checks for permission in
 global level as well as channel level.
 
 @param permission: Permission to check
 @param community: Id of the community to check for
 @return: True if permission is granted else returns False
 */
- (void)hasPermission:(AmityPermission)permission forCommunity:(nonnull NSString *)communityId completion:(nonnull AmityPermissionCompletion)completion;

- (nullable NSDictionary<NSString *, id> *)sendCustomCommand:(nonnull NSString *)command;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
