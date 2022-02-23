//
//  AmityMessageFlagger.h
//  AmitySDK
//
//  Created by Federico Zanetello on 11/28/18.
//  Copyright © 2018 amity. All rights reserved.
//

@import Foundation;

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityMessage.h>

@class AmityMessage;

/**
   A editor encapsulates methods for managing messages
 */
@interface AmityMessageFlagger : NSObject

/**
   The context used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The message Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *messageId;

/**
   Designated intializer
   @param client A valid context instance
   @param messageId A messageId
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                             messageId:(nonnull NSString *)messageId NS_DESIGNATED_INITIALIZER;

/**
   Flags the message, this is reported to the admin panel for the moderators to see
 */
- (void)flagWithCompletion:(AmityRequestCompletion _Nullable)completion;

/**
   Unflags the message
 */
- (void)unflagWithCompletion:(AmityRequestCompletion _Nullable)completion;

/**
   The callback returns whether the logged-in user has flagged this message
 */
- (void)isFlaggedByMeWithCompletion:(void(^ _Nonnull)(BOOL isFlagByMe))callback;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
