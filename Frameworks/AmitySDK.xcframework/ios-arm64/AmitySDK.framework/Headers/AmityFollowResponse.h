//
//  AmityFollowResponse.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 2/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <AmitySDK/AmityFollowRelationship.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityFollowResponse : NSObject

@property (nonnull, strong, readonly, nonatomic) NSString *sourceUserId;
@property (nonnull, strong, readonly, nonatomic) NSString *targetUserId;
@property (assign, readonly, nonatomic) enum AmityFollowStatus status;

@end

NS_ASSUME_NONNULL_END
