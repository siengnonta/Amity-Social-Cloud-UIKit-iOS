//
//  AmityEnums.h
//  AmityChat
//
//  Created by David Zhang on 3/2/18.
//  Copyright © 2018 Amity. All rights reserved.
//

#ifndef AmityEnums_h
#define AmityEnums_h
#import <Foundation/Foundation.h>

#pragma mark - Backend mapping

// AmityDataType
static NSString * const kAmityDataTypeText = @"text";

// AmityReferenceType
static NSString * const kAmityReferenceTypePost = @"post";
static NSString * const kAmityReferenceTypeComment = @"comment";
static NSString * const kAmityReferenceTypeMessage = @"message";
static NSString * const kAmityReferenceTypeContent = @"content";

typedef NS_ENUM(NSInteger, AmityConnectionStatus) {
    // The client/manager has never been connected. Or the client has been reset.
    AmityConnectionStatusNotConnected = 0,
    // The client/manager was once connected, but not anymore.
    AmityConnectionStatusDisconnected = 1,
    // The client/manager is in the process of connecting.
    AmityConnectionStatusConnecting = 2,
    // The client/manager is currently connected.
    AmityConnectionStatusConnected = 3,
};

typedef NS_ENUM(NSInteger, AmityChannelQueryFilter) {
    // query for all channels, regardless of whether the user has joined or not
    AmityChannelQueryFilterAll = 0,
    // query for all channels where the user is member
    AmityChannelQueryFilterUserIsMember = 1,
    // query for all channels where the user is not a member
    AmityChannelQueryFilterUserIsNotMember = 2,
};

typedef NS_ENUM(NSInteger, AmityLoadingStatus) {
    // the data locally is already fresh, no need to load
    AmityLoadingStatusNotLoading = 0,
    // the client is currently loading this data from the server
    AmityLoadingStatusLoading = 1,
    // the client has loaded fresh data from the server and is up to date
    AmityLoadingStatusLoaded = 2,
    // the client has encoutered an error loading this data, please check if Ids and parameters are correct
    AmityLoadingStatusError = 3,
};

/**
   Reflection of the data state.

   Use this property to verify that the data is actually:
   - fresh (verified from the server)
   - from the local storage only
   - and more.

   - AmityDataStatusNotExist: The data does not exist locally.
   - AmityDataStatusLocal: The data is fetched from local database.
   - AmityDataStatusFresh: The data is fresh.
   - AmityDataStatusError: The data is invalid, this is set in conjunction with LoadingStatusError.
 */
typedef NS_ENUM(NSInteger, AmityDataStatus) {
    AmityDataStatusNotExist = 0,
    AmityDataStatusLocal = 1,
    AmityDataStatusFresh = 2,
    AmityDataStatusError = 3
};

/**
   Errors that can happen within the SDK.

   - AmityErrorCodeUnauthorized: The action is not allowed with the current
     logged-in user.
   - AmityErrorCodeUserIsMuted: The action cannot be completed because the user is
     muted in the channel.
   - AmityErrorCodeChannelIsMuted: The action cannot be completed because the
     entire channel is muted.
   - AmityErrorCodeUserIsBanned: The action cannot be completed because the user
     is banned.
   - MaxRepetitionExceed: The action cannot be completed because it has been
     done too frequently.
   - AmityErrorCodeBanWordFound: The action cannot be completed because a
     blacklist word has been detected.
   - AmityErrorCodeGlobalBanError: The logged-in user is banned globally from
     using the SDK.
   - AmityErrorCodeInvalidParameter: The action cannot be completed because a
     parameter is invalid.
   - AmityErrorCodeQueryInProgress: There's a query already in progress.
 */
typedef NS_ENUM(NSInteger, AmityErrorCode) {
    // Server codes
    AmityErrorCodeBusiness = 500000,
    AmityErrorCodeBadRequest = 400000,
    AmityErrorCodeUnauthorized = 400100,
    AmityErrorCodeItemNotFound = 400400,
    AmityErrorCodeForbiddenError = 400300,
    AmityErrorCodePermissionDenied = 400301,
    AmityErrorCodeUserIsMuted = 400302,
    AmityErrorCodeChannelIsMuted = 400303,
    AmityErrorCodeUserIsBanned = 400304,
    AmityErrorCodeNumberOfMemberExceed = 400305,
    AmityErrorCodeExemptFromBan = 400306,
    AmityErrorCodeMaxRepetitionExceed = 400307,
    AmityErrorCodeBanWordFound = 400308,
    AmityErrorCodeLinkNotAllowed = 400309,
    AmityErrorCodeTooManyMember = 400310,
    AmityErrorCodeRateLimit = 400311,
    AmityErrorCodeGlobalBan = 400312,
    AmityErrorCodeConflict = 400900,
    AmityErrorCodeReactionNotFound = 400400,
    AmityErrorCodeModeratorUnableToLeaveCommunity = 400317,
    AmityErrorCodeMemberUnableToLeaveCommunity = 400318,
    AmityErrorCodeNotificationDisabled = 400319,

    // Client codes
    AmityErrorCodeUnknown = 800000,
    AmityErrorCodeInvalidParameter = 800110,
    AmityErrorCodeMalformedData = 800130,
    AmityErrorCodeQueryInProgress = 800170,
    AmityErrorCodeConnectionError = 800210,
    AmityErrorCodeUploadFailed = 800310
};

/**
   Channel Membership types.

   Each member can be only on one state at any given time.

   - AmityChannelMembershipNone: Not a member of this channel.
   - AmityChannelMembershipMember: Standard member.
   - AmityChannelMembershipBanned: Banned member.
   - AmityChannelMembershipMember: Member.
 */
typedef NS_ENUM(NSUInteger, AmityChannelMembershipType) {
    AmityChannelMembershipTypeNone,
    AmityChannelMembershipTypeMember,
    AmityChannelMembershipTypeBanned
};

/**
   Community Membership types.

   Each member can be only on one state at any given time.

   - AmityCommunityMembershipTypeNone: Not a member of this channel.
   - AmityCommunityMembershipTypeMember: Standard member.
   - AmityCommunityMembershipTypeBanned: Banned member.
 */
typedef NS_ENUM(NSUInteger, AmityCommunityMembershipType) {
    AmityCommunityMembershipTypeNone,
    AmityCommunityMembershipTypeMember,
    AmityCommunityMembershipTypeBanned
};

/**
 Reference type of an object we are referencing to.

 - AmityReferenceTypeMessage: A text message.
 - AmityReferenceTypePost: A post of user.
 - AmityReferenceTypeComment: A comment.
 */
typedef NS_ENUM(NSInteger, AmityReferenceType) {
    AmityReferenceTypeMessage,
    AmityReferenceTypePost,
    AmityReferenceTypeComment
};

/**
 Data type of the data we intend to sent.

 - AmityDataTypeText: A text.
 */
typedef NS_ENUM(NSInteger, AmityDataType) {
    AmityDataTypeText
};

/**
 * Sort type option for sorting the user
 */
typedef NS_ENUM(NSUInteger, AmityUserSortOption) {
    AmityUserSortOptionDisplayName,
    AmityUserSortOptionFirstCreated,
    AmityUserSortOptionLastCreated
};

/**
 * Sort type option for sorting the user feed
 */
typedef NS_ENUM(NSUInteger, AmityPostQuerySortOption) {
    AmityPostQuerySortOptionLastCreated,
    AmityPostQuerySortOptionFirstCreated
};

/**
 Sync State
 */
typedef NS_ENUM(NSInteger, AmitySyncState) {
    AmitySyncStateDefault = 0,
    AmitySyncStateSynced = 1,
    AmitySyncStateSyncing = 2,
    AmitySyncStateError = 3,
};

/**
 * Filter type option for query the community
 */
typedef NS_ENUM(NSInteger, AmityCommunityQueryFilter) {
    // query for all community, regardless of whether the user has joined or not
    AmityCommunityQueryFilterAll = 0,
    // query for all community where the user is member
    AmityCommunityQueryFilterUserIsMember = 1,
    // query for all community where the user is not a member
    AmityCommunityQueryFilterUserIsNotMember = 2,
};

/**
 * Options for sorting communities
 */
typedef NS_ENUM(NSUInteger, AmityCommunitySortOption) {
    AmityCommunitySortOptionLastCreated,
    AmityCommunitySortOptionFirstCreated,
    AmityCommunitySortOptionDisplayName
};

/**
 * Options for sorting community memberships
 */
typedef NS_ENUM(NSUInteger, AmityCommunityMembershipSortOption) {
    AmityCommunityMembershipSortOptionLastCreated,
    AmityCommunityMembershipSortOptionFirstCreated,
};

/**
 * Community membership filter options
 */
typedef NS_ENUM(NSUInteger, AmityCommunityMembershipFilter) {
    AmityCommunityMembershipFilterAll,
    AmityCommunityMembershipFilterBan,
    AmityCommunityMembershipFilterMember
};

/*
 * Sort type option for sorting the community categories
 */
typedef NS_ENUM(NSUInteger, AmityCommunityCategoriesSortOption) {
    AmityCommunityCategoriesSortOptionLastCreated,
    AmityCommunityCategoriesSortOptionFirstCreated,
    AmityCommunityCategoriesSortOptionDisplayName
};


/**
 Reference Type for comment
 */
typedef NS_ENUM(NSUInteger, AmityCommentReferenceType) {
    AmityCommentReferenceTypePost,
    AmityCommentReferenceTypeContent
};

/**
 Target Type for post
 */
typedef NS_ENUM(NSUInteger, AmityPostTargetType) {
    AmityPostTargetTypeUser,
    AmityPostTargetTypeCommunity
};

/**
 Request Query options.
 */
typedef NS_ENUM(NSInteger, AmityQueryOption) {
    /**
     Query only deleted results
     */
    AmityQueryOptionDeleted,
    /**
     Query only non deleted results
     */
    AmityQueryOptionNotDeleted,
    /**
     Query both deleted & non deleted results
     */
    AmityQueryOptionAll
};

/**
 Default Sort Option
 */
typedef NS_ENUM(NSInteger, AmitySortBy) {
    AmitySortByFirstCreated,
    AmitySortByLastCreated
};

/**
 Default Ordering Option
 */
typedef NS_ENUM(NSInteger, AmityOrderBy) {
    AmityOrderByAscending,
    AmityOrderByDescending
};

typedef NS_ENUM(NSInteger, AmityCommunityType) {
    // Default community
    AmityCommunityTypeNormal = 0,
    // Trending community
    AmityCommunityTypeTrending = 1,
    // Recommended community
    AmityCommunityTypeRecommended = 2,
};

/**
 List of available permissions for user.
 */
typedef NS_ENUM(NSInteger, AmityPermission) {
    AmityPermissionMuteChannel,
    AmityPermissionCloseChannel,
    AmityPermissionEditChannel,
    AmityPermissionEditChannelRateLimit,
    // Message
    AmityPermissionEditMessage,
    AmityPermissionDeleteMessage,
    // Channel user
    AmityPermissionBanChannelUser,
    AmityPermissionMuteChannelUser,
    AmityPermissionAddChannelUser,
    AmityPermissionRemoveChannelUser,
    AmityPermissionEditChannelUser,
    // User
    AmityPermissionBanUser,
    AmityPermissionEditUser,
    AmityPermissionAssignUserRole,
    // Feed
    AmityPermissionEditUserFeedPost,
    AmityPermissionDeleteUserFeedPost,
    AmityPermissionEditUserFeedComment,
    AmityPermissionDeleteUserFeedComment,
    // Community User
    AmityPermissionAddCommunityUser,
    AmityPermissionRemoveCommunityUser,
    AmityPermissionEditCommunityUser,
    AmityPermissionBanCommunityUser,
    AmityPermissionMuteCommunityUser,
    // Community
    AmityPermissionEditCommunity,
    AmityPermissionDeleteCommunity,
    AmityPermissionEditCommunityPost,
    AmityPermissionDeleteCommunityPost,
    AmityPermissionPinCommunityPost,
    AmityPermissionEditCommunityComment,
    AmityPermissionDeleteCommunityComment,
    AmityPermissionReviewCommunityPost
};

typedef NS_ENUM(NSUInteger, AmityChannelMembershipFilter) {
    AmityChannelMembershipFilterAll,
    AmityChannelMembershipFilterMute,
    AmityChannelMembershipFilterBan
};

/**
 Channel search member filter
 */
typedef NS_ENUM(NSUInteger, AmityChannelMembershipSearchFilter) {
    /// Standard member.
    AmityChannelMembershipSearchFilterMember,
    
    /// Muted member.
    AmityChannelMembershipSearchFilterMute,
    
    /// Banned member.
    AmityChannelMembershipSearchFilterBan
};

typedef NS_ENUM(NSUInteger, AmityFeedType) {
    AmityFeedTypePublished,
    AmityFeedTypeReviewing,
    AmityFeedTypeDeclined
};

/**
 Message Mention Type

 - AmityMessageMentionTypeUser: mention users in  message.
 - AmityMessageMentionTypeChannel: mention all users in message.
 */
typedef NS_ENUM(NSInteger, AmityMessageMentionType) {
    AmityMessageMentionTypeUser,
    AmityMessageMentionTypeChannel
};

typedef NS_ENUM(NSInteger, AmityCommunityEvent) {
    AmityCommunityEventCommunity,
    AmityCommunityEventPosts,
    AmityCommunityEventComments,
    AmityCommunityEventPostsAndComments
};

typedef NS_ENUM(NSInteger, AmityPostEvent) {
    AmityPostEventPost,
    AmityPostEventComments
};

typedef NS_ENUM(NSInteger, AmityUserEvent) {
    AmityUserEventUser,
    AmityUserEventPosts,
    AmityUserEventComments,
    AmityUserEventPostsAndComments
};

typedef NS_ENUM(NSInteger, AmityCommentEvent) {
    AmityCommentEventComment
};

/**
 * Community membership filter options
 */
typedef NS_OPTIONS(NSInteger, AmityCommunityMembershipFilterOption) {
    AmityCommunityMembershipFilterOptionNone = 0,
    AmityCommunityMembershipFilterOptionBan = 1 << 0,
    AmityCommunityMembershipFilterOptionMember = 1 << 1,
};

#endif /* AmityEnums_h */
