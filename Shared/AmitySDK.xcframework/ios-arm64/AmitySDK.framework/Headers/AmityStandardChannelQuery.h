//
//  AmityStandardChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/3/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityChannelQuery.h>
#import <AmitySDK/AmityStandardChannelQueryBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityStandardChannelQuery : AmityChannelQuery

+ (instancetype)makeWithBuilder:(AmityStandardChannelQueryBuilder *)builder
                         client:(AmityClient *)client;

@end

NS_ASSUME_NONNULL_END
