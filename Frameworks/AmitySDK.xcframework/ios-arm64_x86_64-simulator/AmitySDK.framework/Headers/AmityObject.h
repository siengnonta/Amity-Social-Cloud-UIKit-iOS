//
//  AmitySDKRequest.h
//  AmitySDK
//
//  Created by amity on 2/21/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityEnums.h>
#import <Foundation/Foundation.h>

@class AmityObject;
@class AmityNotificationToken;


NS_ASSUME_NONNULL_BEGIN

/**
   Proxy for an object.
 */
__attribute__((objc_subclassing_restricted))
@interface AmityObject <__covariant ObjectType> : NSObject

/// Current object data status.
@property (nonatomic) AmityDataStatus dataStatus;

/// Current local object data status.
@property (nonatomic) AmityLoadingStatus loadingStatus;

/// Direct access to this object.
@property (nullable, readonly, nonatomic) ObjectType object;

/**
   @abstract Adds a block to observe changes in the proxied object.
   @discussion Observers can be notified when the object is available. In case the object doesn't exist, or was unavailable, an error will be passed.
   @param block The block to execute when the request result has changed.
   @return AmityNotificationToken object that should be retained to continue to observe.
 */
- (nonnull AmityNotificationToken *)observeWithBlock:(void (^)(AmityObject<ObjectType> * _Nonnull object, NSError * _Nullable error))block;

/**
   @abstract Adds a block to observe a change in the proxy exactly once.
   @discussion Observers can be notified when the object is available. In case the object doesn't exist or was unavailable an error will be passed.
   @param block The block to execute exactly once when the request result has changed.
   @return AmityNotificationToken object that should be retained to continue to observe.
 */
- (nonnull AmityNotificationToken *)observeOnceWithBlock:(void (^)(AmityObject<ObjectType> * _Nonnull object, NSError * _Nullable error))block;

/**
   Block call of `init` and `new` because AmityObject cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
