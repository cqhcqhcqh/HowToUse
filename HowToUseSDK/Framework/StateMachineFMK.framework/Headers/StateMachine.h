//
//  CPState.h
//  Model
//
//  Created by cnepayzx on 15-1-21.
//  Copyright (c) 2015年 cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPNotificationManager.h"
#import "CPDevInfo.h"

@class CPInterfaceDevice,State,CPMessagesQueue,CPMessage;

@interface StateMachine : NSObject

@property(nonatomic, strong)State *destState;
@property(nonatomic, strong)NSMutableArray *deferedArray;

+ (instancetype)stateMachine;

//顺序发送事件
-(void)sendMessage:(CPMessage *)message;
//插入到队列的前面
-(void)sendMessageFront:(CPMessage *)message;
-(void)sendMessageInt:(int)type;
-(void)sendMessageFrontInt:(int)type;

//缓存
-(void)deferredMessage:(CPMessage *)message;
-(BOOL)hasDeferredMessage:(int)type;
-(void)removeDeferredMessage:(int)type;
- (BOOL) hasOnWaitingOperationsMessage:(int)type;
//转换状态
-(void)transiton;

//设置初始的状态
-(void) initialState:(State *)state;

- (void)setInterfaceDeviceWithType:(CPDeviceType)type;
- (CPInterfaceDevice *)getInterfaceDevice;
- (void)setDevInfo:(CPDevInfo *)devInfo;
- (CPDevInfo *)getDevInfo;

@end

