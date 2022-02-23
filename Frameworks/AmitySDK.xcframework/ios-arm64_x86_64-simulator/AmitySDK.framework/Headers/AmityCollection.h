//
//  AmityCollection.h
//  AmitySDK
//
//  Created by amity on 1/28/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityEnums.h>
#import <Foundation/Foundation.h>

@class AmityCollection;
@class AmityNotificationToken;
@class AmityCollectionChange;

NS_ASSUME_NONNULL_BEGIN

/**
   A collection is a container type returned from queries. Clients can request to load more and observe insertions and changes to the objects in the collection. Initially the count will be zero. Observers will be notified of changes.
 */
@interface AmityCollection<__covariant ObjectType> : NSObject

// if the current data is considered stale or if it's fresh data from the server
@property (readonly, nonatomic) AmityDataStatus dataStatus;

// stores the current local data status
@property (readonly, nonatomic) AmityLoadingStatus loadingStatus;

// stores if there is a previous page to query
@property (readonly, nonatomic) BOOL hasPrevious;

// stores if there is a next page to query
@property (readonly, nonatomic) BOOL hasNext;

/**
 * The number objects
 *
 * @return NSUInteger
 */
- (NSUInteger)count;

/**
 * Returns an instance at a given index
 *
 * @param idx An index in the collection
 * @return an object
 */
- (nullable ObjectType)objectAtIndex:(NSUInteger)idx;

/**
 * Returns all objects of this live collection.
 *
 * @note This is equavalent to @code
 * var allObjects: [ObjectType] = []
 * for i in 0..<collection.count() {
 *     if let object = collection.object(at: i) {
 *         allObjects.add(object)
 *     }
 * }
 * return allObjects;
 * @endcode
 */
- (NSArray<ObjectType> *)allObjects;

/**
   Reset the current records being displayed to the default last page
 */
- (void)resetPage;

/**
   Requests more objects to load if any are available
 */
- (void)previousPage;

/**
   Requests more objects to load if any are available
 */
- (void)nextPage;

/**
   Adds a block to observe changes in the collection
   @param block called when the collection or any of the underlying objects have changed
   @return AmityNotificationToken object that should be retained to continue to observe.
 */
- (nonnull AmityNotificationToken *)observeWithBlock:(void (^)(AmityCollection<ObjectType> * _Nonnull collection, AmityCollectionChange * _Nullable changes, NSError * _Nullable error))block;
/**
   Adds a block to observe changes in the collection exactly once
   @param block called exactly once when the collection or any of the underlying objects have changed
   @return AmityNotificationToken object that should be retained to continue to observe.
 */
- (nonnull AmityNotificationToken *)observeOnceWithBlock:(void (^)(AmityCollection<ObjectType> * _Nonnull collection, AmityCollectionChange * _Nullable changes, NSError * _Nullable error))block;
/**
   Block call of `init` and `new` because AmityObject cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

/**
 *  Represents changes in a AmityCollection
 */
@interface AmityCollectionChange : NSObject

/**
 * The indexes of objects inserted
 */
@property (nullable, strong, readonly, nonatomic) NSArray <NSNumber *> *insertions;

/**
 * The indexes of objects deleted
 */
@property (nullable, strong, readonly, nonatomic) NSArray <NSNumber *> *deletions;

/**
 * The indexes of objects modified
 */
@property (nullable, strong, readonly, nonatomic) NSArray <NSNumber *> *modifications;

@end

NS_ASSUME_NONNULL_END
