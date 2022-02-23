//
//  AmityMessageEditor.h
//  AmitySDK
//
//  Created by amity on 2/19/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityObject.h>

@class AmityMessage;
@class AmityMentioneesBuilder;

/**
 A editor encapsulates methods for managing messages.
 */
@interface AmityMessageEditor : NSObject

/**
 The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
 The message Id associated with the instance.
 */
@property (nonnull, strong, readonly, nonatomic) NSString *messageId;

/**
 Designated intializer.
 @param client A valid context instance.
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                             messageId:(nonnull NSString *)messageId NS_DESIGNATED_INITIALIZER;

/**
 Edits the text message.
 @param text The new text
 @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
      completion:(AmityRequestCompletion _Nullable)completion;

/**
 Edits the text message.
 @param text The new text
 @param metadata The metadata for the message, it can contain information about mentions
 @param mentionees The mentiones in the message
 @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
        metadata:(nullable NSDictionary<NSString *, id> *)metadata
      mentionees:(nullable AmityMentioneesBuilder *)mentionees
      completion:(AmityRequestCompletion _Nullable)completion;

/**
 Edits the custom message.
 @param text The new custom message
 @param completion A block executed when the request has completed..
 */
- (void)editCustomMessage:(nonnull NSDictionary<NSString *, id> *)customMessage
               completion:(AmityRequestCompletion _Nullable)completion;

/**
 Sets the tags for the given message.
 
 As long as the user is a member of a channel, the user can set the tags to any
 message of that channel.
 
 @param tags An array of tags
 */
- (void)setTags:(nullable NSArray<NSString *> *)tags
     completion:(nullable AmityRequestCompletion)completion;

/**
 Block call of `init` and `new` because this object cannot be created directly.
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
