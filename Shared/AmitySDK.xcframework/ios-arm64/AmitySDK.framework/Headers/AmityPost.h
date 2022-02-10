//
//  AmityPost.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 4/13/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityCommunity.h>

@class AmityPost;
@class AmityUser;
@class AmityImageData;
@class AmityFileData;
@class AmityComment;
@class AmityVideoData;
@class AmityStream;
@class AmityPoll;
typedef NS_ENUM(NSInteger, AmityVideoDataQuality);

/**
 * Post
 */
__attribute__((objc_subclassing_restricted))
@interface AmityPost : NSObject

/**
 * The unique identifier for the post
 */
@property (nonnull, strong, readonly, nonatomic) NSString *postId;

/**
 * The unique identifier for the post user id
 */
@property (nonnull, strong, readonly, nonatomic) NSString *postedUserId;

/**
 * The unique identifier for the shared user id
 */
@property (nonnull, strong, readonly, nonatomic) NSString *sharedUserId;

/**
 * The data type of the post
 */
@property (nonnull, strong, readonly, nonatomic) NSString *dataType;

/**
 The post author.
 */
@property (nullable, strong, readonly, nonatomic) AmityUser *postedUser;

/**
 The shared author.
 */
@property (nullable, strong, readonly, nonatomic) AmityUser *sharedUser;

/**
   Number of share on this post
 */
@property (assign, readonly, nonatomic) NSUInteger sharedCount;

/**
 * Post data
 */
@property (nullable, strong, readonly, nonatomic) NSDictionary<NSString *, id> *data;

/**
 * Post meta data
 */
@property (nullable, strong, readonly, nonatomic) NSDictionary<NSString *, id> *metadata;

/**
 * The creation date of the post
 */
@property (nonnull, strong, nonatomic) NSDate *createdAt;

/**
   @abstract The post last edited time
   @discussion The updated time is updated for updated data on the post
 */
@property (nonnull, strong, nonatomic) NSDate *updatedAt;

/**
 Timestamp when this post was last edited by user. For newly created post, `createdAt` & `editedAt` would be the same
 */
@property (nonnull, strong, nonatomic) NSDate *editedAt;

/**
  Number of reaction on this post
*/
@property (assign, nonatomic, readonly) NSUInteger reactionsCount;

/**
  The list of my reactions to this post.
*/
@property (nonnull, assign, readonly, nonatomic) NSArray <NSString *> *myReactions;

/**
 The reaction data.
 */
@property (nullable, strong, readonly, nonatomic) NSDictionary *reactions;

/**
  Number of people that have flagged this post
*/
@property (assign, readonly, nonatomic) NSUInteger flagCount;

/**
 The sync state of the comment.
 */
@property (readonly, nonatomic) AmitySyncState syncState;

/**
 Determines if this post has been edited.
 */
@property (readonly, nonatomic) BOOL isEdited;

/**
 Whether the post has been deleted.
 */
@property (assign, readonly, nonatomic) BOOL isDeleted;

/**
 Id of the parent post
 */
@property (nullable, nonatomic) NSString *parentPostId;

/**
 Total number of comments in this post.
 */
@property (readonly, nonatomic) NSUInteger commentsCount;

/**
 Returns array of children posts.
 */
@property (nullable, nonatomic) NSArray<AmityPost *> *childrenPosts;

/**
 Id of the target this post belongs to.
 */
@property (nonnull, nonatomic) NSString *targetId;

/**
 Id of the target this post belongs to.
 */
@property (nonnull, nonatomic) NSString *targetType;

/**
 The community to which this post belongs to.
 */
@property (nullable, nonatomic) AmityCommunity *targetCommunity;

/**
 Array of latest 5 comments
 */
@property (nonnull, nonatomic) NSArray<AmityComment *> *latestComments;

/**
 Gets the file data associated with this post.
 
 @return: Returns AmityFileData if present. Else returns nil.
 */
- (nullable AmityFileData *)getFileInfo;

/**
 Gets the image data associated with this post.
 
 @return: Returns AmityImageData if present. Else returns nil.
 */
- (nullable AmityImageData *)getImageInfo;

/**
 Gets the video data associated with this post.
 
 @return: Returns AmityVideoData if present. Else returns nil.
 */
- (nullable AmityVideoData *)getVideoInfoForQuality:(AmityVideoDataQuality)quality;

/// Gets the video data associated with this post, for all available quality.
/// The key of returning dictionary is `AmityVideoDataQuality`.
- (nonnull NSDictionary<NSNumber *, AmityVideoData *> *)getVideosInfo;

- (nullable AmityImageData *)getVideoThumbnailInfo;

/**
 Gets the live stream data associated with this post.
 
 @return: Returns AmityStream if present. Else returns nil.
 */
- (nullable AmityStream *)getLiveStreamInfo;

/**
 Gets the feed type with this post
 @return: Returns AmityFeedType if present. Else return published
 */
- (AmityFeedType)getFeedType;

/**
 Gets the poll data associated with this post
 @return: Returns AmityPoll if present. Else returns nil.
 */
- (nullable AmityPoll *)getPollInfo;

@end
