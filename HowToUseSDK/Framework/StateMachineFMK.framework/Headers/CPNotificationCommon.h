//
//  CPNotificationCommon.h
//  中汇支付
//
//  Created by cqh on 15/6/25.
//  Copyright (c) 2015年 Chepay. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * const CPStateMachineStateDeviceTypeChange;
FOUNDATION_EXPORT NSString * const CPStateMachineStateChange;
FOUNDATION_EXPORT NSString * const CPStateMachineReadIC;
FOUNDATION_EXPORT NSString * const CPStateMachineReadMag;
FOUNDATION_EXTERN NSString * const CPStateMachineRequestPin;
FOUNDATION_EXTERN NSString * const CPStateMachineResponsePin;
FOUNDATION_EXPORT NSString * const CPStateMachineOnline;
FOUNDATION_EXPORT NSString * const CPStateMachineStopPBOC;
FOUNDATION_EXPORT NSString * const CPStateMachineOnlineFailure;
FOUNDATION_EXPORT NSString * const CPStateMachineReadMagPin;
FOUNDATION_EXPORT NSString * const CPStateMachineReadIcEMVResult;
FOUNDATION_EXPORT NSString * const CPStateMachineReadPinFinish;
FOUNDATION_EXPORT NSString * const CPStateMachineDealFailure;
FOUNDATION_EXPORT NSString * const CPStateMachineKeepReadingCard;
FOUNDATION_EXPORT NSString * const CPStateMachineVolumReadIcData;
FOUNDATION_EXPORT NSString * const CPStateMachineReadMac;
FOUNDATION_EXPORT NSString * const CPStateMachineReadMacFailure;
FOUNDATION_EXPORT NSString * const CPStateMachineDealParamSuccess;
FOUNDATION_EXPORT NSString * const CPStateMachineScreenDisplaySuccess;
FOUNDATION_EXPORT NSString * const CPStateMachineReadCardType;
FOUNDATION_EXPORT NSString * const CPStateMachineSearchDevices;
FOUNDATION_EXPORT NSString * const CPStateMachineSearchAudioDevice;
FOUNDATION_EXPORT NSString * const CPStateMachineHeadPhonePlugged;
FOUNDATION_EXPORT NSString * const CPStateMachineSearchDevicesTimeOut;
FOUNDATION_EXPORT NSString * const CPStateMachineSearchDevicesInterrupt;
FOUNDATION_EXPORT NSString * const CPStateMachineStandBy;
FOUNDATION_EXPORT NSString * const CPStateMachineStandByFailure;
FOUNDATION_EXPORT NSString * const CPStateMachineWriteICDataSuccess;
FOUNDATION_EXPORT NSString * const CPStateMachineNewValue;
FOUNDATION_EXPORT NSString * const CPStateMachineOldValue;
FOUNDATION_EXPORT NSString * const CPStateMachineUnexpectedLose;
FOUNDATION_EXPORT NSString * const CPStateMachineScreenDisconnectSuccess;
