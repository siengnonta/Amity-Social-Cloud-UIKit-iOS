//
//  AmityCommunityUpdateDataBuilder.h
//  AmitySDK
//
//  Created by Michael Abadi on 23/07/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityImageData.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityUpdateDataBuilder : NSObject <AmityCommunityBuilder>

/**
 Sets the current display name
 */
- (void)setDisplayName:(NSString *)displayName;

/**
 Sets the current description
 */
- (void)setCommunityDescription:(NSString *)communityDescription;

/**
Sets the current status public or not
*/
- (void)setIsPublic:(BOOL)isPublic;

/**
 Sets the current metadata
 */
- (void)setMetadata:(NSDictionary<NSString *, id> *)metadata;

/**
 Sets the community avatar, set nil if you want to remove it
 */
- (void)setAvatar:(nullable AmityImageData *)image;

/**
 Sets category id for community
 */
- (void)setCategoryIds:(nonnull NSArray<NSString *> *)categoryIds;

/**
 Sets the current status post review to enable or not
 */
- (void)isPostReviewEnabled:(BOOL)isPostReview;

@end

NS_ASSUME_NONNULL_END

