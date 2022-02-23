//
//  AmityFollowActor.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 17/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AmityClient.h"

typedef NS_ENUM(NSUInteger, AmityFollowActionType) {
    AmityFollowActionTypeFollow,
    AmityFollowActionTypeUnfollow,
    AmityFollowActionTypeAccept,
    AmityFollowActionTypeDecline
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityFollowActor : NSObject

@property (nonnull, strong, readonly, nonatomic) AmityClient *client;
@property (nonnull, strong, readonly, nonatomic) NSString *userId;
@property (assign, readonly, nonatomic) AmityFollowActionType actionType;

- (nonnull instancetype) initWithClient: (nonnull AmityClient *)client;

- (void)performOptimisticUpdateWithActionType:(AmityFollowActionType)actionType
                                       userId:(NSString *)userId
                                   completion:(nullable AmityFollowRequestCompletion)completion;

@end

NS_ASSUME_NONNULL_END
