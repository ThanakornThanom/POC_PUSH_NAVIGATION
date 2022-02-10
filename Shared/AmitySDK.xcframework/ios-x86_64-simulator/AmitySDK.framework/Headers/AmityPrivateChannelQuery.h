//
//  AmityPrivateChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/3/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityChannelQuery.h>
#import <AmitySDK/AmityPrivateChannelQueryBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityPrivateChannelQuery : AmityChannelQuery

+ (instancetype)makeWithBuilder:(AmityPrivateChannelQueryBuilder *)builder
                         client:(AmityClient *)client;

@end

NS_ASSUME_NONNULL_END
