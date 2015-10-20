//
//  CPAllState.h
//  Model
//
//  Created by cnepayzx on 15-3-4.
//  Copyright (c) 2015年 cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StateMachineCommon.h"
@class StateMachine,State;

@interface CPAllState: NSObject

+ (void)CPAllStatesWithSM:(StateMachine *)stateMachine;

+ (State *)CPUnconnect;
+ (State *)CPScaning;
+ (State *)CPConnecting;
+ (State *)CPConnected;
+ (State *)CPDisconnecting;
+ (State *)CPFetchDeviceInfo;
+ (State *)CPSetWorkKey;
+ (State *)CPAidRid;
+ (State *)CPStandby;
+ (State *)CPWaitCard;
+ (State *)CPReadPin;
+ (State *)CPReadMac;
+ (State *)CPOnline;
+ (State *)CPDispay;
+ (State *)CPReadIC;
+ (State *)CPReadMag;
+ (State *)CPStopPBOC;

@end
