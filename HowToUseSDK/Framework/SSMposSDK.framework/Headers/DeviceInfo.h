//
//  DeviceInfo.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/28.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseVariables.h"
@interface DeviceInfo : BaseVariables
//设备硬件编号（SN码）   12  SN码, 新大陆企标的设备序列号
@property  (nonatomic ,strong) NSString* termSN;
// 设备个人化状态 1   0xFF：默认初始状态   //0x00：个人化完成
@property  (nonatomic ,strong) NSString* privatize;
//应用版本    16   ASCII
@property (nonatomic ,strong) NSString* appVersion;
//保留  10  生产规则，默认为全0x00

// 设备状态    1   见MPOS设备硬件能力
@property  (nonatomic ,strong) NSString* deviceStatus;
// 固件版本    16  ASCII
@property (nonatomic ,strong)NSString*  firmwareVersion;
//客户序列号（CSN）  LL..24  由客户定义的设备序列号，一般为根据接入环境要求而定义的设备硬件编号，也可以称为设备ID
@property (nonatomic ,strong)NSString*  CSN;
//密钥序列号（KSN）  LL..40  由客户定义的密钥序列号
@property (nonatomic ,strong)NSString*  KSN;
//产品ID    2   0x00 0x30   ME30
// 0x00 0x31   ME31   //新大陆
// Ox00 0x35   M35
// 0x00 0x36   M36    //联迪
// 0x01 0x80   D180
//0x02 0x10   D210   //百富
//0x02 0x18   Vi218  //信雅达
// 0x00 0x20   M20    //海信
@property (nonatomic ,strong)NSString*  productID;
//厂商ID    2   VID:
//新大陆：0x00 0x01
// 联迪：0x00 0x02
//百富：0x00 0x03
// 信雅达：0x00 0x06
// 海信：0x00 0
@property (nonatomic ,strong)NSString*  manufacturerID;
//生产SN号   LL..40  根据生产要求而自定义的SN号
@property (nonatomic ,strong)NSString*  produceSN;
//Boot版本  LL..40  ASCII
@property (nonatomic ,strong)NSString*  bootVersion;
//蓝牙名称
@property (nonatomic ,strong)NSString*  bluetoothName;
//蓝牙MAC地址
@property (nonatomic ,strong)NSString*  bluetoothMac;
@end
