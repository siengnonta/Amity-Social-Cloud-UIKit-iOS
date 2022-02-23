//
//  AmityFollowInfo.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 2/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <AmitySDK/AmityUserFollowCount.h>
#import <AmitySDK/AmityFollowResponse.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserFollowInfo : NSObject

@property (nonnull, strong, readonly, nonatomic) NSString *targetUserId;
@property (readonly, nonatomic) enum AmityFollowStatus status;
@property (readonly, nonatomic) int followersCount;
@property (readonly, nonatomic) int followingCount;

@end

NS_ASSUME_NONNULL_END
