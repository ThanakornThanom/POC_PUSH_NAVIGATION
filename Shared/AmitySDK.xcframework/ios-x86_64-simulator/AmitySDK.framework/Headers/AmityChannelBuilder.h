//
//  AmityChannelBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 9/28/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityChannel.h>
#import <AmitySDK/AmityConversationChannelBuilder.h>
#import <AmitySDK/AmityLiveChannelBuilder.h>
#import <AmitySDK/AmityCommunityChannelBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityChannelBuilder : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Default Initializer. Do not initialize this class yourself.
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a conversation channel.
 */
- (nonnull AmityObject<AmityChannel *> *)conversationWithBuilder:(AmityConversationChannelBuilder *)builder;

/**
 Creates a live channel.
 */
- (nonnull AmityObject<AmityChannel *> *)liveWithBuilder:(AmityLiveChannelBuilder *)builder;

/**
 Creates a community channel,
 */
- (nonnull AmityObject<AmityChannel *> *)communityWithBuilder:(AmityCommunityChannelBuilder *)builder;

// Disable default initializer
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
