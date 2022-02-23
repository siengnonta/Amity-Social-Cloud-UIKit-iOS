//
//  AmityMessageRepository.h
//  AmitySDK
//
//  Created by amity on 1/25/18.
//  Copyright © 2018 amity. All rights reserved.
//

@import Foundation;

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityMessage.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUser.h>
#import <AmitySDK/AmityReaction.h>
#import <AmitySDK/AmityMention.h>

@class AmityMentioneesBuilder;

typedef void (^AmityMessageCreateCompletion)(AmityMessage * _Nullable message, NSError * _Nullable error);

/**
 Repository provides access messages and collections.
 */
@interface AmityMessageRepository : NSObject

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
 Creates and returns a collection of all messages filtered by the given
 `channelId`, tags, and `parentId`.
 
 @discussion
 When observing changes on the collection, the only time AmityCollectionChange
 gives back a deletion update (on messages) is when the user has been banned
 or has left the channel:
 to confirm this, you can also observe changes in the AmityChannel object
 (if this also gets deleted, you have either left the channel or you've been
 banned).
 
 @remarks
 Let's say that a channel has the messages (in chronological order):
 ABC...XYZ
 
 When `reverse` is set to:
 
 - `false`, we will fetch the first (oldest)
 messages in chronological order: ABC first, then the next page etc.
 
 - `true`, we will fetch the last (newest) messages
 in reverse-chronological order: ZYX first, then the previous page etc.
 
 It's up to the developer to call the right `loadNext`/`loadPrevious` page in
 the returned collection based on the `reverse` value:
 
 - `loadNext` loads newer messages in comparison with the last loaded page
 
 - `loadPrevious` loads older messages in comparison with the last loaded page
 
 @note when asking for more messages, based on the reverse preference,
 you'll need to ask for the next page (if the reverse is `false`) or the
 previous page (if the reverse is `true`). A message is matched when it contains ANY tag listed in includingTags, and contains NONE of the tags listed in excludingTags.
 
 @param channelId The channel identifier of the channel we're interested in
 @param includingTags The list of required message tags, pass an empty array to
 ignore this requirement.
 @param excludingTags The list of tags required not to be set in the messages,
 pass an empty array to ignore this requirement.
 @param filterByParentId Whether we're initerested in filtering by parentId or
 not.
 @param parentId The `messageId` of the parent whose child we're interested in.
 @param reverse Whether we'd like the collection in chronological order or not.
 @return The `AmityMessage` live collection.
 */
- (nonnull AmityCollection<AmityMessage *> *)getMessagesWithChannelId:(nonnull NSString *)channelId
                                                        includingTags:(nonnull NSArray<NSString *> *)includingTags
                                                        excludingTags:(nonnull NSArray<NSString *> *)excludingTags
                                                     filterByParentId:(BOOL)filterByParentId
                                                             parentId:(nullable NSString *)parentId
                                                              reverse:(BOOL)reverse NS_SWIFT_NAME(getMessages(channelId:includingTags:excludingTags:filterByParentId:parentId:reverse:));

/**
 Get all of the reactions on the specific message.
 @param messageId The related message id to be observed.
 @return The `AmityReaction` live collection.
 */
- (nonnull AmityCollection<AmityReaction *> *)getReactions:(nonnull NSString *)messageId;

/**
 Gets an existing message by message Id
 */
- (AmityObject<AmityMessage *> * _Nullable)getMessage:(nonnull NSString *)messageId;

/**
 Deletes message with provided message id
 */
- (void)deleteMessageWithId:(nonnull NSString *)messageId completion:(nullable AmityRequestCompletion)completion;

/**
 Removes all failed messages.
 */
- (void)deleteFailedMessages:(AmityRequestCompletion _Nullable)completion;

/**
 Removes particular failed message
 */
- (void)deleteFailedMessage:(nonnull NSString *)messageId completion:(nullable AmityRequestCompletion)completion;

/**
 Creates a new custom message.
 
 @param channelId The channel we want to create a message in.
 @param data Message (custom) data.
 @param tags An array of tags (you can store here whatever you want)
 @param parentId The new message parent (note: this cannot be changed later).
 @return The AmityMessage live object.
 
 @note Behind the scenes this methods calls `NSJSONSerialization`, which states
 that an object that may be converted to JSON must have the following
 properties:
 
 - Top level object is an NSArray or NSDictionary.
 
 - All objects are NSString, NSNumber, NSArray, NSDictionary, or NSNull.
 
 - All dictionary keys are NSStrings.
 
 - NSNumbers are not NaN or infinity.
 
 Failing to do so will result in an exception.
 */
- (nonnull NSString *)createCustomMessageWithChannelId:(nonnull NSString *)channelId
                                                  data:(nonnull NSDictionary<NSString *, id> *)data
                                                  tags:(nullable NSArray<NSString *> *)tags
                                              parentId:(nullable NSString *)parentId
                                            completion:(nullable AmityMessageCreateCompletion)completion;

/**
 Creates a new text message.
 
 @param channelId The channel we want to create a message in.
 @param text The text message to be sent.
 @param tags An array of tags (you can store here whatever you want).
 @param parentId The new message parent (note: this cannot be changed later).
 @return The AmityMessage live object.
 */
- (nonnull NSString *)createTextMessageWithChannelId:(nonnull NSString *)channelId
                                                text:(nonnull NSString *)text
                                                tags:(nullable NSArray<NSString *> *)tags
                                            parentId:(nullable NSString *)parentId
                                          completion:(nullable AmityMessageCreateCompletion)completion;

/**
 Creates a new text message.
 
 @param channelId The channel we want to create a message in.
 @param text The text message to be sent.
 @param tags An array of tags (you can store here whatever you want).
 @param parentId The new message parent (note: this cannot be changed later).
 @param metadata The metadata for the message, it can contain information about mentions
 @param mentionees The mentiones in the message
 @return The AmityMessage live object.
 */
- (nonnull NSString *)createTextMessageWithChannelId:(nonnull NSString *)channelId
                                                text:(nonnull NSString *)text
                                                tags:(nullable NSArray<NSString *> *)tags
                                            parentId:(nullable NSString *)parentId
                                            metadata:(nullable NSDictionary<NSString *, id> *)metadata
                                          mentionees:(nonnull AmityMentioneesBuilder *)mentionees
                                          completion:(nullable AmityMessageCreateCompletion)completion
NS_SWIFT_NAME(createTextMessage(channelId:text:tags:parentId:metadata:mentionees:completion:));


/**
 Creates audio message.
 
 @param channelId: Channel Identifier for this message
 @param audioFile: URL for the audio file in local file system.
 @param fileName: Name for this audio file. If a file name is provided that would be used else sdk would try to determine the file name based on url last path component.
 @param parentId: Id of the parent message. If this message is a "reply-to" for some other message, you can provide id of that message.
 @param tags: Array of tags for this message.
 */
- (nonnull NSString *)createAudioMessageWithChannelId:(nonnull NSString *)channelId
                                            audioFile:(nonnull NSURL *)audioFileURL
                                             fileName:(nullable NSString *)fileName
                                             parentId:(nullable NSString *)parentId
                                                 tags:(nullable NSArray<NSString *> *)tags
                                           completion:(nullable AmityMessageCreateCompletion)completion;

/**
 Creates a new image message.
  
 @param channelId A channel Identifier.
 @param imageFile URL for the image file in local file system
 @param fullImage whether or not the image should be sent at full resolution.
 @param tags An array of tags (you can store here whatever you want).
 @param parentId  The new message parent (note: this cannot be changed later).
 */
- (nonnull NSString *)createImageMessageWithChannelId:(nonnull NSString *)channelId
                                            imageFile:(nonnull NSURL *)imageURL
                                              caption:(nullable NSString *)caption
                                            fullImage:(BOOL)fullImage
                                                 tags:(nullable NSArray<NSString *> *)tags
                                             parentId:(nullable NSString *)parentId
                                           completion:(nullable AmityMessageCreateCompletion)completion;

/**
 Creates a new file message.
 
 @param channelId A channel Identifier.
 @param file URL for the file from local file system.
 @param filename File name to be sent (will be sent as NSString).
 @param tags An array of tags (you can store here whatever you want).
 @param parentId  The new message parent (note: this cannot be changed later).
 */
- (nonnull NSString *)createFileMessageWithChannelId:(nonnull NSString *)channelId
                                                file:(nonnull NSURL *)fileURL
                                            filename:(nullable NSString *)filename
                                             caption:(nullable NSString *)caption
                                                tags:(nullable NSArray<NSString *> *)tags
                                            parentId:(nullable NSString *)parentId
                                          completion:(nullable AmityMessageCreateCompletion)completion;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
