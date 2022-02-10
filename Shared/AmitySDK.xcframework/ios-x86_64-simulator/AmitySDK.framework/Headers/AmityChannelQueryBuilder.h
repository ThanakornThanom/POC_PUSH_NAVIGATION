//
//  AmityChannelQueryBuilder.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/3/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityChannelQuery.h>
#import <AmitySDK/AmityStandardChannelQuery.h>
#import <AmitySDK/AmityPrivateChannelQuery.h>
#import <AmitySDK/AmityByTypesChannelQuery.h>
#import <AmitySDK/AmityBroadcastChannelQuery.h>
#import <AmitySDK/AmityConversationChannelQuery.h>
#import <AmitySDK/AmityPrivateChannelQueryBuilder.h>
#import <AmitySDK/AmityStandardChannelQueryBuilder.h>
#import <AmitySDK/AmityByTypesChannelQueryBuilder.h>
#import <AmitySDK/AmityBroadcastChannelQueryBuilder.h>
#import <AmitySDK/AmityClient.h>

@class AmityLiveChannelQuery;
@class AmityLiveChannelQueryBuilder;
@class AmityCommunityChannelQuery;
@class AmityCommunityChannelQueryBuilder;

NS_ASSUME_NONNULL_BEGIN

@interface AmityChannelQueryBuilder : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;
- (nonnull AmityPrivateChannelQuery *)privateTypeWithBuilder:(AmityPrivateChannelQueryBuilder *)builder;
- (nonnull AmityStandardChannelQuery *)standardTypeWithBuilder:(AmityStandardChannelQueryBuilder *)builder;
- (nonnull AmityByTypesChannelQuery *)byTypesWithBuilder:(AmityByTypesChannelQueryBuilder *)builder;
- (nonnull AmityBroadcastChannelQuery *)broadcastWithBuilder:(AmityBroadcastChannelQueryBuilder *)builder;
- (nonnull AmityConversationChannelQuery *)conversationWithBuilder:(AmityConversationChannelQueryBuilder *)builder;
- (nonnull AmityLiveChannelQuery *)liveTypeWithBuilder:(AmityLiveChannelQueryBuilder *)builder;
- (nonnull AmityCommunityChannelQuery *)communityTypeWithBuilder:(AmityCommunityChannelQueryBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
