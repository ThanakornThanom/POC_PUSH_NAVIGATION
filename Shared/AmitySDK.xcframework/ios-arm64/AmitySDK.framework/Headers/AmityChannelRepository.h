//
//  AmityChannelRepository.h
//  AmitySDK
//
//  Created by amity on 1/25/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityChannel.h>
#import <AmitySDK/AmityChannelNotificationsManager.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityChannelQueryBuilder.h>
#import <AmitySDK/AmityChannelBuilder.h>
#import <AmitySDK/AmityChannelUpdateBuilder.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access channel and collections of channels
 */
@interface AmityChannelRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;
@property (readonly, nonatomic) NSUInteger totalUnreadCount;

/**
 * Designated intializer
 * @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a new channel. **Standard & Private** channel types has been depreciated. Please refer to our documentation for more info.
 */
- (nonnull AmityChannelBuilder *)createChannel;

/**
 Updates an existing channel.
 */
- (nonnull AmityChannelUpdateBuilder *)updateChannel:(NSString *)channelId;

/**
 * Joins a channel by channel Id, if you are already in this channel, it will fetch the existing channel. **Note:** Starting from SDK version 3.0, this method doesnot creates a new channel, if the channel doesnot exists.
 * @param channelId A valid Channel Id
 * @return A Proxy Object for the channel
 */
- (AmityObject<AmityChannel *> *)joinChannel:(nonnull NSString *)channelId;

/**
 Leaves the channel for the current user
 @param completion A block executed when the request has completed
 */
- (void)leaveChannel:(NSString *)channelId withCompletion:(AmityRequestCompletion _Nullable)completion;

/**
 * Gets an existing channel by channel Id
 */
- (AmityObject<AmityChannel *> *)getChannel:(nonnull NSString *)channelId;

/**
 Create a new channel query builder in order to get specific channel types
 @note Hence client must specify the channel types with declarative ways in order get the correct  designated builder
 @return AmityChannelQueryBuilder instance
 */
- (nonnull AmityChannelQueryBuilder *)getChannels;

/**
 @abstract Channel Level Push Notifications Management object.
 */
- (nonnull AmityChannelNotificationsManager *)notificationManagerForChannelWithId:(nonnull NSString *)channelId;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
