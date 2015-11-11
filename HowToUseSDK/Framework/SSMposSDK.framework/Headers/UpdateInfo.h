//
//  UpdateInfo.h
//  SSMposSDK
//
//  Created by cuixj on 15/6/5.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UpdateInfo : NSObject

@property (nonatomic, assign)NSInteger requestStatus;   // 请求状态
@property (nonatomic, assign)NSInteger offset;          // 偏移量
@property (nonatomic, assign)NSInteger dataLen;         // 数据长度
@property (nonatomic, strong)NSData *data;        // 固件数据

@property (nonatomic, assign) NSInteger         currentPercent;

@end
