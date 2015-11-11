//
//  MposBlock.h
//  SSMposSDK
//
//  Created by cuixj on 15/6/5.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#ifndef SSMposSDK_MposBlock_h
#define SSMposSDK_MposBlock_h















// 更新固件/应用
typedef void(^UpdateBlock)(NSInteger, BOOL);




/*
 ** 异常错误类Block定义
 */

// 获取错误信息Block
typedef void(^ErrorBlock)(int, NSString *);

#endif
