//
//  AmityCommentEditor.h
//  AmitySDK
//
//  Created by Michael Abadi on 04/06/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityComment.h>

@class AmityMessage;
@class AmityMentioneesBuilder;

/**
   A editor encapsulates methods for managing comment.
 */
@interface AmityCommentEditor : NSObject

/**
   The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The comment identifier associated with the instance.
 */
@property (nonnull, strong, readonly, nonatomic) NSString *commentId;

/**
   Designated intializer.
   @param client A valid context instance.
   @param commentId A valid commentId which must be edited
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                             commentId:(nonnull NSString *)commentId NS_DESIGNATED_INITIALIZER;

/**
   Edits the text of the comment.
   @param text The new text
   @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
      completion:(AmityRequestCompletion _Nullable)completion;

/**
 Edits the text of the comment.
   @param text The new text
   @param metadata The metadata for the comment, it can contain information about mentions
   @param mentionees The mentiones in the comment
   @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
        metadata:(nullable NSDictionary<NSString *, id> *)metadata
      mentionees:(nullable AmityMentioneesBuilder *)mentionees
      completion:(AmityRequestCompletion _Nullable)completion;

/**
   Block call of `init` and `new` because this object cannot be created directly.
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

