//
//  AmityMentionees.h
//  AmitySDK
//
//  Created by Hamlet on 08.09.21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityUser.h>

NS_ASSUME_NONNULL_BEGIN

/**
   This class represents information about mention type and array of userIds if type is not channel.
 */
@interface AmityMentionees : NSObject

/**
   The type of mention. Type can be user or channel
 */
@property (nonatomic) AmityMessageMentionType type;

/**
   The users who were mentioned in the message. The property is nil If type is channel
 */
@property (nullable, nonatomic) NSArray<AmityUser *> *users;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
