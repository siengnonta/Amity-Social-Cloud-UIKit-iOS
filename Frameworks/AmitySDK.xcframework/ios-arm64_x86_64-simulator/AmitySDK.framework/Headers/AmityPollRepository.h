//
//  AmityPollRepository.h
//  AmitySDK
//
//  Created by Sarawoot Khunsri on 3/8/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityBuilder.h>

typedef void (^AmityPollRequestCompletion)(NSString * _Nullable pollId, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access to feed and collections of feeds
 */
@interface AmityPollRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Designated intializer
 @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 @param builder: A type of AmityPollBuilder object.
 */
- (void)createPoll:(nonnull id<AmityPollBuilder>)builder
        completion:(AmityPollRequestCompletion _Nullable)completion;

/**
 Close the specific poll with poll id
 @param pollId: A poll id represent the poll object
 */
- (void)closePollWithId:(nonnull NSString *)pollId
                 completion:(AmityRequestCompletion _Nullable)completion;

/**
 Vote the specific poll with poll id
 @param pollId: A poll id represent the poll object
 @param answerIds: Array of answerIds
 */
- (void)votePollWithId:(nonnull NSString *)pollId
             answerIds:(nonnull NSArray<NSString *> *)answerIds
            completion:(AmityRequestCompletion _Nullable)completion;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
