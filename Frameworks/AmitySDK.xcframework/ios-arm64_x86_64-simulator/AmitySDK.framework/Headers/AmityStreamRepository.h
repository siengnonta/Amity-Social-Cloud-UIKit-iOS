//
//  AmityStreamRepository.h
//  AmitySDK
//
//  Created by Nutchaphon Rewik on 22/9/2563 BE.
//  Copyright © 2563 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityCollection.h>

@class AmityStream;
@class AmityObject;
@class AmityClient;
@class AmityCollection;
@class AmityLiveStreamURLInfo;
@class AmityStreamNotificationsManager;
@class AmityImageData;

NS_ASSUME_NONNULL_BEGIN

@class AmityStreamCollectionQuery;

/// AmityStreamRepository manages stream objects
@interface AmityStreamRepository : NSObject

#pragma mark - Initializer

/// The context used to create the instance.
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/// Designated intializer.
/// @param client A valid context instance.
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client NS_DESIGNATED_INITIALIZER;

#pragma mark - Query

/// Get the collection of streams for the specified statuses..
- (AmityCollection<AmityStream *> *)getStreamsCollectionFormQuery:(AmityStreamCollectionQuery *)query NS_SWIFT_NAME(getStreamsCollection(from:));

/// Get a live object of stream, by id.
/// @param streamId The unique identifer of stream
- (AmityObject<AmityStream *> *)getStreamById:(nullable NSString *)streamId;

/// Create a new video stream.
- (void)createVideoStreamWithTitle:(nonnull NSString *)title
                       description:(nullable NSString *)description
                    thumbnailImage:(nullable AmityImageData *)thumbnailImage
                              meta:(nullable NSDictionary<NSString *, id> *)meta
                        completion:(void (^_Nonnull)(AmityStream * _Nullable, NSError * _Nullable))completion;

/// Send the request to update streaming status to ".ended", and dispose streaming url.
- (void)disposeStreamWithId:(NSString *)streamId
                 completion:(void (^_Nonnull)(AmityStream * _Nullable, NSError * _Nullable))completion;

/* Not used in this version.
/// @abstract User Level Notification Management object.
@property (nonnull, readonly, nonatomic) AmityStreamNotificationsManager *notificationManager;
 */

#pragma mark - Prevent default initializer

/// Block call of `init` and `new` because this object cannot be created directly
- (instancetype)init NS_UNAVAILABLE;

/// Block call of `init` and `new` because this object cannot be created directly
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
