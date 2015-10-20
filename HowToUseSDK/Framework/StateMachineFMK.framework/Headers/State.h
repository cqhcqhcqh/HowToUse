//
//  State.h
//  Model1
//
//  Created by cnepayzx on 15-1-19.
//  Copyright (c) 2015年 cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateMachine.h"
#import "CPSendMessageOperation.h"

@class CPInterfaceDevice;

@interface State : NSObject

@property(nonatomic,weak) StateMachine *stateMachine;
- (instancetype)initWithStateMachine:(StateMachine *)stateMachine;
+ (instancetype)stateWithStateMachine:(StateMachine *)stateMachine;

-(void)enter;
-(void)exit;
-(void)processMessage:(CPMessage *)message;
-(NSString *)getName;
-(CPInterfaceDevice *)getInterfaceDevice;

- (void)sendMessageType:(int)type;
- (void)sendMessageType:(int)type withObj:(id)obj;
- (void)sendMessageType:(int)type withSubType:(int)subType;
- (void)sendMessageType:(int)type withSubType:(int)subType withObj:(id)obj;
- (void)deferredMessage:(CPMessage *)message;
@end


