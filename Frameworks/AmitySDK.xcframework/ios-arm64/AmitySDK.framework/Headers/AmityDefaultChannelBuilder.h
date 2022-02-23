//
//  AmityDefaultChannelBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 8/19/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityChannel.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityImageData.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityDefaultChannelBuilder : NSObject <AmityChannelBuilderProtocol>

@property (nullable, strong, nonatomic) NSString *channelDisplayName;
@property (nullable, strong, nonatomic) NSDictionary<NSString *, id> *channelMetadata;
@property (nullable, strong, nonatomic) NSArray<NSString *> *channelTags;
@property (nullable, strong, nonatomic) NSString *channelId;
@property (nullable, strong, nonatomic) NSArray<NSString *> *channelUserIds;
@property (assign, nonatomic) AmityChannelType channelType;
@property (nullable, strong, nonatomic) AmityImageData *avatarData;

/**
 Sets id for the channel. Default value is nil.
 */
- (void)setId:(NSString *)channelId;

/**
 Sets display name for channel. Default value is nil.
 */
- (void)setDisplayName:(NSString *)displayName;

/**
 Sets medata for the channel. Default is empty dictionary.
 */
- (void)setMetadata:(NSDictionary<NSString *, id> *)metaData;

/**
 Sets tags for channel. Default is empty array
 */
- (void)setTags:(NSArray<NSString *> *)tags;

/**
 Sets userIds who are the member of this channel.
 */
- (void)setUserIds:(NSArray<NSString *> *)userIds;

/**
 Sets avatar info for this channel. Use AmityFileRepository to upload image and set the AmityImageData
 instance that you get in response over here.
 */
- (void)setAvatar:(AmityImageData *)avatarData;

@end

NS_ASSUME_NONNULL_END
