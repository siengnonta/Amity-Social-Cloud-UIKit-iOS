//
//  AmityCommentRepository.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 5/20/20.
//  Copyright © 2020 amity. All rights reserved.
//

@import Foundation;
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityComment.h>
#import <AmitySDK/AmityReaction.h>
#import <AmitySDK/AmityMention.h>

@class AmityComment;
@class AmityMentioneesBuilder;

/**
 Repository provides access comments and collections.
 */
@interface AmityCommentRepository : NSObject

/**
 The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
 Designated intializer.
 
 @param client A valid context instance.
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a new comment. Comments are created locally and then synced with server. You can observe
 the `syncState` property of `AmityComment` to determine if server sync was successful or not.
 
 @param referenceId: The unique identifiers of id.
 @param referenceType: ReferenceType for comment
 @param parentId: The unique identifiers of the parent of the comment.
 @param text: The comment text.
 @return The AmityComment live object.
 */
- (nonnull AmityObject<AmityComment *> *)createCommentForReferenceId:(nonnull NSString *)referenceId
                                                        referenceType:(AmityCommentReferenceType)type
                                                             parentId:(nullable NSString *)parentId
                                                                 text:(nonnull NSString *)text;
/**
 Creates a new comment. Comments are created locally and then synced with server. You can observe
 the `syncState` property of `AmityComment` to determine if server sync was successful or not.
 
 @param referenceId: The unique identifiers of id.
 @param referenceType: ReferenceType for comment
 @param parentId: The unique identifiers of the parent of the comment.
 @param text: The comment text.
 @param metadata The metadata for the comment, it can contain information about mentions
 @param mentionees The mentiones in the comment
 @return The AmityComment live object.
 */
- (nonnull AmityObject<AmityComment *> *)createCommentForReferenceId:(nonnull NSString *)referenceId
                                                       referenceType:(AmityCommentReferenceType)type
                                                            parentId:(nullable NSString *)parentId
                                                                text:(nonnull NSString *)text
                                                            metadata:(nullable NSDictionary<NSString *, id> *)metadata
                                                          mentionees:(nonnull AmityMentioneesBuilder *)mentionees;

/**
 @abstract Fetches collection of comments for particular post/content.
 
 @discussion:
 You can also fetch comment thread. i.e all the comments under particular comment.
 To do that set `filterByParentId` to true and pass the parent comment id in
 `parentId`. If `filterByParentId` is true but no `parentId` is present,then the
 collection will return all comments without a parent.
 
 @remarks:
 When `orderBy` is set to:
 
 - `.ascending`, we will fetch the first (oldest) comments
 in chronological order: ABC first, then the next page etc.
 
 - `.descending`, we will fetch the last (newest) comments
 in reverse-chronological order: ZYX first, then the previous page etc.
 
 It's up to the developer to call the right `loadNext`/`loadPrevious` page in
 the returned collection based on the `orderBy` value:
 
 @note when asking for more comments, based on the orderBy preference,
 you'll need to ask for the next page (if the order is `.ascending`) or the
 previous page (if the reverse is `.descending`).
 
 @param referenceId: The id of the post/content that you want to fetch comment for.
 @param referenceType: The reference type for this comment. Use .content as reference type if you are querying comments for external content else use .post.
 @param filterByParentId: Set this to true if you want to fetch comment thread
 @param parentId: The id of the parent comment.
 @param queryOption: Enum to fetch only deleted comments, not deleted comments or both.
 @param orderBy: Whether we'd like the collection in chronological order or not.
 @param includeDeleted: Boolean whether this collection should fetch comments along with deleted comments
 @return The comments collection.
 */
- (nonnull AmityCollection<AmityComment *> *)getCommentsWithReferenceId:(nonnull NSString *)referenceId
                                                          referenceType:(AmityCommentReferenceType)type
                                                       filterByParentId:(BOOL)filterByParentId
                                                               parentId:(nullable NSString *)parentId
                                                                orderBy:(AmityOrderBy)orderOption
                                                         includeDeleted:(BOOL)includeDeletedComments;

/**
 Returns single latest comment for given referenceId
 
 @param referenceId: The id of the post/content that you want to fetch latest comment
 @param referenceType: Reference type for this comment. Use .content as reference type if you are querying comments for external content else use .post
 @param includeReplies: Boolean to indicate whether to include comment replies in latest comment or not. Set it to true If you want to fetch only latest parent comment.
 */
- (nonnull AmityObject<AmityComment *> *)getLatestCommentWithReferenceId:(nonnull NSString *)referenceId
                                                           referenceType:(AmityCommentReferenceType)referenceType
                                                          includeReplies:(BOOL)includeReplies;

/**
 Get all of the reactions on the specific comment.
 @param commentId Id of particular comment
 @return The `AmityReaction` live collection.
 */
- (nonnull AmityCollection<AmityReaction *> *)getReactions:(nonnull NSString *)commentId;

/**
 Deletes the comment.
 
 @param commentId: Id of the comment to delete
 @param hardDelete: If this flag is true, the SDK will delete comment from the database, instead of setting `isDeleted` flag.
 @param completion  A block executed when the request has completed.
 @note After the object is hard deleted, all the references point to the object will be invalidated. You can check this via @code object.isInvalidated @endcode
 An attempt to access the invalidated object will result in crash. If your app keep the reference to hard deleted objects, please make sure you check against object validity.
 */
- (void)deleteCommentWithId:(nonnull NSString *)commentId hardDelete:(BOOL)hardDelete completion:(nullable AmityRequestCompletion)completion
NS_SWIFT_NAME(deleteComment(withId:hardDelete:completion:));


/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
