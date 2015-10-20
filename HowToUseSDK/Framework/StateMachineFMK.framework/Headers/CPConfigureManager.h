//
//  CPConfigureManager.h
//  StateMechine
//
//  Created by cqh on 15/3/2.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPInterfaceDeviceCommon.h"
#import "CPDevConfigure.h"

@interface CPConfigureManager : NSObject
+ (CPDevConfigure *)getDevConfigureWithType:(CPDeviceType)type;
@end


@interface CPInitialDevParam : NSObject
@property (nonatomic ,strong) NSArray *aids;
@property (nonatomic ,strong) NSArray *rids;
@property (nonatomic ,copy) NSString *workKey;
@property (nonatomic ,copy) NSString *ksn;
@property (nonatomic ,getter = isVolumDevice) BOOL volumDevice;
/**
 *  判断是否需要做更新所有的参数..
 */
@property (nonatomic ,getter = isNeedUpdateAllParam) BOOL needUpdateAllParam;
@end
