//
//  AmityMention.h
//  AmitySDK
//
//  Created by Hamlet on 20.07.21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>

NS_ASSUME_NONNULL_BEGIN

/**
   This class represents information about mention type, position of the mention, length of the mention and userId if type is not channel.
 */
@interface AmityMention : NSObject

/**
   The type of mention. Type can be user or channel
 */
@property (nonatomic) AmityMessageMentionType type;

/**
   The index of mention started from "@" character.
 */
@property (assign, nonatomic) NSInteger index;

/**
   The length of the mention started from "@" character
 */
@property (assign, nonatomic) NSInteger length;

/**
   The userId who was mentioned in the message. There is no need to provide userId If type is channel
 */
@property (nullable, nonatomic) NSString *userId;

/**
 Creats new instance of AmityMention
 @param type The type of mention
 @param index The index of mention started from "@" character
 @param length The length of mention started from "@" character
 @param userId The userId who was mentioned in the message. There is no need to provide userId If type is channel
 */
- (instancetype)initWithType:(AmityMessageMentionType)type index:(NSInteger)index length:(NSInteger)length userId:(nullable NSString *)userId;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
