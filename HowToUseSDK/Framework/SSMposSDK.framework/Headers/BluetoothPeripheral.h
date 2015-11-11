//
//  BluetoothPeripheral.h
//  MposSDKDemo
//
//  Created by centerm on 14-3-28.
//  Copyright (c) 2014年 Centerm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface BluetoothPeripheral : NSObject

@property (assign)  BOOL                    isSupportPeripheral;        //表征当前蓝牙外设是否为支持的外设

@property (assign)  BOOL                    isPairedPeripheral;         //表征当前外设是否为已连接外设

@property (retain)  CBPeripheral            *cbPeripheral;
@property (copy)    NSString                *blePeripheralName;         //外设的名字
@property (retain)  NSNumber                *bleDeviceRRSI;             //外设的信号强度
@property (retain)  CBCharacteristic        *transparentDataWriteChar;  //写服务特征值
@property (retain)  CBCharacteristic        *transparentDataReadChar;   //读服务特征值


/**
 *  发送数据
 *
 *  @param data 需要发送的数据
 *  @param type 写服务特征值类型
 */
- (void)sendTransparentData:(NSData *)data type:(CBCharacteristicWriteType)type;

/**
 *  设置数据传输广播
 *
 *  @param notify YES:设置数据传输广播   NO:不设置数据传输广播
 *
 *  @return 设置是否成功
 */
- (BOOL)setTransDataNotification:(BOOL)notify;


@end
