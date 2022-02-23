//
//  AmityReactionRepository.h
//  AmitySDK
//
//  Created by Nishan Niraula on 7/30/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityReaction.h>
#import <AmitySDK/AmityCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityReactionRepository : NSObject

/**
 The client context used to create the instance
 */
@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Designated Initializer
 @param client A valid AmityClient instance
 */
- (instancetype) initWithClient: (AmityClient *)client;

/**
 Add reaction to the content.
 
 @param reaction: Name of the reaction
 @param referenceId: Id for the content. Example: postId for post, commentId for comment & so on.
 @param referenceType: Type of content. If you are adding reaction to post, reference type would be of type .post (swift) or AmityReactionReferenceTypePost (Objc)
 @param completion: Closure to be executed after this operation is complete.
 */
- (void)addReaction: (NSString *)reaction referenceId:(NSString *)contentId referenceType:(AmityReactionReferenceType)type completion: (AmityRequestCompletion _Nullable)completion;

/**
Remove reaction from the content.

@param reaction: Name of the reaction
@param referenceId: Id for the content. Example: postId for post, commentId for comment & so on.
@param referenceType: Type of content. If you are adding reaction to post, reference type would be of type .post (swift) or AmityReactionReferenceTypePost (Objc)
@param completion: Closure to be executed after this operation is complete.
*/
- (void)removeReaction: (NSString *)reaction referenceId:(NSString *)contentId referenceType:(AmityReactionReferenceType)type completion: (AmityRequestCompletion _Nullable)completion;

/**
 Get the collection of reactions for particular content for provided reaction name.
 
 @param id: Id of the post, comment or message
 @param referenceType: Type of content. If you are adding reaction to post, reference type would be of type .post (swift) or AmityReactionReferenceTypePost (Objc)
 @param reactionName: Name of the reaction. If reaction name is provided, it fetches all reactions which matches the reaction name. If reaction name is empty or nil, it fetches all reactions for particular content.
 @return AmityCollection of AmityReaction object. Observe the changes to get results.
 */
- (AmityCollection<AmityReaction *> *)getReactions:(NSString *)referenceId referenceType:(AmityReactionReferenceType)type reactionName:(nullable NSString *)reactionName;


// Disable object creation
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
