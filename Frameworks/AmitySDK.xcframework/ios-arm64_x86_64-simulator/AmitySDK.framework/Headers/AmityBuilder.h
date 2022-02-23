//
//  AmityBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 6/15/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityChannel.h>

@protocol AmityPostBuilder <NSObject>

/**
 Returns the JSON representation of the data object needed for post
 */
- (NSDictionary<NSString *, id> *)build;

/**
 Returns the JSON representation of the data object needed to update the post
 */
- (NSDictionary<NSString *, id> *)buildForPostUpdate;

@end

@protocol AmityCommunityBuilder <NSObject>

/**
 Returns the JSON representation of the data object needed for group
 */
- (NSDictionary<NSString *, id> *)build;

@end


@protocol AmityChannelBuilderProtocol

/**
 Channel type for the builder.
 */
@property (assign, nonatomic) AmityChannelType channelType;

/**
 Returns the JSON representation of the data object needed for channel
 */
- (NSDictionary<NSString *, id> *)build;

@end


@protocol AmityPollBuilder <NSObject>

/**
 Returns the JSON representation of the data object needed for poll
 */
- (NSDictionary<NSString *, id> *)build;

@end
