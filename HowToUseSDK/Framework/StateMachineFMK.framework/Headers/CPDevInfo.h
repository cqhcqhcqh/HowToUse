//
//  CPDevInfo.h
//  StateMachine
//
//  Created by cqh on 15/5/24.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSUInteger, CPDeviceType) {
    CPDeviceType_Itroni21 = 1,
    CPDeviceType_M35,
    CPDeviceType_Itron159,
    CPDeviceType_HZm20,
    CPDeviceTypeAll,
    CPDeviceTypeUnKnown,
};

typedef NS_ENUM(NSUInteger, CPDeviceConnectState) {
    CPDeviceConnectStateDisConnect = 1,
    CPDeviceConnectStateConnecting,
    CPDeviceConnectStateConnected,
};

typedef NS_ENUM(NSUInteger, CPCommunitaionType)  {
    CPCommunitaionTypeAudio,
    CPCommunitaionTypeBluetooth,
};

FOUNDATION_EXPORT NSString* const DeviceTypeMapping [];
FOUNDATION_EXPORT NSString* const Itron159Model;
FOUNDATION_EXPORT NSString* const Hzm20Model;
FOUNDATION_EXPORT NSString* const Landim35Model;
FOUNDATION_EXPORT NSString* const Itroni21Model;
FOUNDATION_EXPORT CPDeviceType DeviceModelMapping(NSString *model);

@class CPFetchDevInfo;

@interface CPDevInfo : NSObject
/**
 *  设备的公开信息
 *  @parma 设备的唯一识别
 *  @param devName 外设蓝牙名
 *  @param devChannel 设备通信类型
 */
//@property (nonatomic,copy) NSString           * devIndentifier;
//@property (nonatomic,copy) NSString           * devName;
@property (nonatomic ,strong) CBPeripheral *peripheral;
@property (nonatomic        ) CPCommunitaionType devChannel;

@property (nonatomic, assign) CPDeviceType type;
@property (nonatomic, copy) NSString *devType;
@property (nonatomic, copy) NSString *devModel;
@property (nonatomic, copy) NSString *devKsn;
@property (nonatomic, copy) NSString *devBTmac;
@property (nonatomic, copy) NSString *devHardNo;
/**
 *  设备连接之后可以获取到得信息
 */
@property (nonatomic ,assign) CPDeviceConnectState devConnectState;
- (void) setFetchDevInfo:(CPFetchDevInfo *)fetchDevInfo;
@end

@interface CPFetchDevInfo : NSObject
@property (nonatomic, copy) NSString *fetchDevType;
@property (nonatomic, copy) NSString *fetchDevModel;
@property (nonatomic, copy) NSString *fetchDevKsn;
@property (nonatomic, copy) NSString *fetchDevBTmac;
@property (nonatomic ,copy) NSString *fetchDevHardNo;
@end
