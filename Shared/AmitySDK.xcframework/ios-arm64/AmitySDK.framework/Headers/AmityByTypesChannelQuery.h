//
//  AmityByTypesChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/5/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityChannelQuery.h>
#import <AmitySDK/AmityByTypesChannelQueryBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityByTypesChannelQuery : AmityChannelQuery

+ (instancetype)makeWithBuilder:(AmityByTypesChannelQueryBuilder *)builder
                         client:(AmityClient *)client;

@end

NS_ASSUME_NONNULL_END
