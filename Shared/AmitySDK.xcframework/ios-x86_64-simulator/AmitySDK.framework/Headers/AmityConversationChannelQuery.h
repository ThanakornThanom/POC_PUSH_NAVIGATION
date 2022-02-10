//
//  AmityConversationChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 3/9/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityChannelQuery.h>
#import <AmitySDK/AmityConversationChannelQueryBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityConversationChannelQuery : AmityChannelQuery

+ (instancetype)makeWithBuilder:(AmityConversationChannelQueryBuilder *)builder
                         client:(AmityClient *)client;

@end

NS_ASSUME_NONNULL_END
