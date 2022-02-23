//
//  AmityCommunityCreationDataBuilder.h
//  AmitySDK
//
//  Created by Michael Abadi on 07/07/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityImageData.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityCreationDataBuilder : NSObject <AmityCommunityBuilder>

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
 Sets the current user ids
 */
- (void)setUserIds:(NSArray<NSString *> *)userIds;

/**
 Sets the current metadata
 */
- (void)setMetadata:(NSDictionary<NSString *, id> *)metadata;

/**
 Sets the community avatar
 */
- (void)setAvatar:(nonnull AmityImageData *)image;

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

