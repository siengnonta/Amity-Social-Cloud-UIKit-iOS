//
//  AmityChannelUpdateBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 9/29/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityImageData.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityChannel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Builder to update the channel. All methods are optional.
 */
@interface AmityChannelUpdateBuilder : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Default initializer. Do not initialize this class yourself.
 */
- (instancetype)initWithChannelId:(NSString *)channelId NS_DESIGNATED_INITIALIZER;

/**
 Sets display name for channel. Default value is nil.
 */
- (void)setDisplayName:(NSString *)displayName;

/**
 Sets medata for the channel. Default is empty dictionary.
 */
- (void)setMetadata:(NSDictionary<NSString *, id> *)metaData;

/**
 Sets avatar info for this channel. Use AmityFileRepository to upload image and set the AmityImageData
 instance that you get in response over here. To remove the avatar, pass nil.
 */
- (void)setAvatar:(nullable AmityImageData *)avatarData;

/**
 Sets tags for channel. Default is empty array
 */
- (void)setTags:(NSArray<NSString *> *)tags;

// Disable default initializer
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
