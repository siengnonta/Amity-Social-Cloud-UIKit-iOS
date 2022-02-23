//
//  AmityMentionMapper.h
//  AmitySDK
//
//  Created by Hamlet on 09.08.21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityMention.h>

NS_ASSUME_NONNULL_BEGIN

/**
 AmityMentionMapper is a helper class, which helps:
 - to convert mentions from metadata if metadata contains information about mentions,
 - to convert metadata from array of AmityMention objects.
 */
@interface AmityMentionMapper : NSObject

/**
 Converts the metadata into the array of AmityMention if metadata contains information about mentions.
 
 @param metadata The metadata which supposed to contains information about mentions.
 @return array of AmityMention if metadata contains information about mentions.
 */
+ (nonnull NSArray<AmityMention*>*)mentionsFromMetadata:(nonnull NSDictionary<NSString *, id> *) metadata;

/**
 Converts the array of mentions into metadata.
 
 @param mentions The array of AmityMention.
 @return dictionary which contains the array of AmityMention
 */
+ (nonnull NSDictionary<NSString *, id> *)metadataFromMentions:(nonnull NSArray<AmityMention*>*) mentions;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
