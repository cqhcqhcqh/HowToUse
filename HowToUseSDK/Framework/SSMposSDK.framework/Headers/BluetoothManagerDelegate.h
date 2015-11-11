//
//  BluetoothManagerDelegate.h
//  MposSDKDemo
//
//  Created by centerm on 14-4-2.
//  Copyright (c) 2014年 Centerm. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BluetoothManagerDelegate <NSObject>

//  超时类型
typedef NS_ENUM(NSInteger, BLESwipCardStateTimeOut) {
    BLESwipCardStateDeviceSearchTimeOut = 0,
	BLESwipCardStatePairTimeOut,
    BLESwipCardStateSendDataTimeOut,
};


/**
 *  发现外设时触发的回调  ！默认子线程返回
 *
 *  @param blePeripheral  返回发现的设备
 */
- (void)didDiscoverDevice:(BluetoothPeripheral *)btPeripheral;

/**
 *  连接成功时触发的回调
 *
 *  @param blePeripheral 返回配对成功的设备
 */
- (void)didPairDevice:(BluetoothPeripheral *)btPeripheral;

/**
 *  连接失败时触发的回调
 *
 *  @param blePeripheral 返回尝试建立连接的设备
 *  @param error         错误信息
 */
- (void)didFailToPairDevice:(BluetoothPeripheral *)btPeripheral withError:(NSError *)error;

/**
 *  连接断开时触发的回调
 *
 *  @param error 错误信息
 */
- (void)didUNPairDevice:(NSError *)error;

/**
 *  蓝牙操作超时时触发的回调
 *
 *  @param timeOut 返回超时类型
 */
- (void)onTimeOut:(BLESwipCardStateTimeOut)timeOut;

/**
 *  上位机蓝牙状态改变时触发的回调
 *
 *  @param currentBTManagerState 改变后的状态
 */
- (void)didBTManagerStateChanged:(bleCentralDelegateState)currentBTManagerState;

@end


