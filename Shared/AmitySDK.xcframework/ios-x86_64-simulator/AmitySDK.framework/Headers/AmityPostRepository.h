//
//  AmityPostRepository.h
//  AmitySDK
//
//  Created by Nutchaphon Rewik on 21/7/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityReaction.h>
#import <AmitySDK/AmityPost.h>

@class AmityPostQueryOptions;

typedef void (^AmityPostRequestCompletion)(AmityPost * _Nullable post, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface AmityPostRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated intializer
 @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Create the which need a text represented by string value
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post.
 @param targetId: Target id for the feed. Set nil if you are creating a post on your own feed.
 @param targetType: Target type for the feed. Either community or user.
 
 */
- (void)createPost:(id<AmityPostBuilder>)builder
          targetId:(nullable NSString *)targetId
        targetType:(AmityPostTargetType)targetType
        completion:(nullable AmityPostRequestCompletion)completion;

/**
 Update specific post with the updated data
 @param postId: A post id represent the post object
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post. **Note** Builder should be of same type that you used to create the original post.
 */
- (void)updatePostWithPostId:(NSString *)postId
                     builder:(id<AmityPostBuilder>)builder
                  completion:(nullable AmityPostRequestCompletion)completion;

/**
 Delete the specific post with provided id
 @param postId: A post id represent the post object
 @param parentId: Id of the parent post. If a post has parent, then provide its id.
 */
- (void)deletePostWithPostId:(NSString *)postId
                    parentId:(nullable NSString *)parentId
                  completion:(nullable AmityRequestCompletion)completion;

/**
 Approve the specific post with provided id
 @param postId: A post id represent the post object
 */
- (void)approvePostWithPostId:(NSString *)postId
                   completion:(nullable AmityRequestCompletion)completion;

/**
 Decline the specific post with provided id
 @param postId: A post id represent the post object
 */
- (void)declinePostWithPostId:(NSString *)postId
                   completion:(nullable AmityRequestCompletion)completion;

/**
 Get the collection of community feed.
 
 @param options The post query options.
 @return The AmityCollection of AmityPost. Observe the changes for getting the result.
 */
- (AmityCollection<AmityPost *> *)getPosts:(AmityPostQueryOptions *)options;

/**
 Retrieves post for particular post id
 
 @param postId The id for the post
 */
- (AmityObject<AmityPost *> *)getPostForPostId:(NSString *)postId;

/**
 Get the collection of reactions for particular post for provided reaction name.
 
 @param postId: Id of the post
 @param reactionName: Name of the reaction
 @return AmityCollection of AmityReaction object. Observe the changes to get results.
 
 */
- (AmityCollection<AmityReaction *> *)getReactions:(NSString *)postId
                                      reactionName:(nullable NSString *)reactionName;

@end

NS_ASSUME_NONNULL_END
