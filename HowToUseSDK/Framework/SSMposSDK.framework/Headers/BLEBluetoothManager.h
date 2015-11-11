//
//  CTBluetoothManager.h
//  MposSDKDemo
//
//  Created by centerm on 14-3-28.
//  Copyright (c) 2014年 Centerm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLESwiperProfile.h"

#import "BluetoothPeripheral.h"
#import "BluetoothManagerDelegate.h"

typedef NS_ENUM(NSInteger, BTManagerErrorID) {
    BTManagerErrorIDBUSY = 821301,
        BTManagerErrorIDNoOpen = 821302,
            BTManagerErrorIDNoDevice = 821303,
                BTManagerErrorIDDisconnect = 821304,
       BTManagerErrorIDCloseBT = 821305,
    
};


typedef NS_ENUM(NSInteger, CTBLEDeviceType)
{
    CTBLEDeviceType_MPOS,
    CTBLEDeviceType_PRINTER,
};

#define ERROR_MSG_BUSY              @"正在进行其它操作"


/**
 *  设备连接中断的通知
 */
static NSString * const kLostConnectionNotifi = @"LostConnection";



/**
 *  蓝牙外设管理器
 */
@interface BLEBluetoothManager : NSObject<CBCentralManagerDelegate,CBPeripheralDelegate>{
    
    bleCentralDelegateState                 _currentCentralManagerState;
    
    CBUUID                                  *_customTransServiceUUID;
    CBUUID                                  *_customTransTxUUID;
    CBUUID                                  *_customTransRxUUID;
    
}

@property (assign)           BOOL                                   havePerioheralConnected;


@property (atomic, assign)   NSObject                               *peripheralDataSource;

@property (atomic, assign)   NSObject <BluetoothManagerDelegate>    *peripheralDelegate;


/**
 *  单例返回蓝牙管理器
 *
 *  @return 蓝牙管理器
 */
+ (BLEBluetoothManager *)sharedInstance;

///**
// *  实例化
// *
// *  @return 返回蓝牙管理对象
// */
//- (CTBluetoothManager *)initBTManager;

/**
 *  打开上位机蓝牙模块
 */
- (void)openBluetooth;

/**
 *  搜索蓝牙
 */
- (void)searchDevices:(int) tmo;

/**
 *  停止搜索外部蓝牙设备
 */
- (void)stopSearchDevices;


/**
 *  连接指定蓝牙
 *
 *  @param btPeripheral 指定的蓝牙外设
 */
- (void)connect:(BluetoothPeripheral *)btPeripheral;


/**
 *  连接指定蓝牙
 *
 *  @param cbPeripheral 指定的蓝牙外设
 */
- (void)connectWithCBPeripheral:(CBPeripheral *)cbPeripheral;

- (void)connectWithIdentifier:(NSString *)identifier;
/**
 *  断开与制定蓝牙的连接
 *
 *  @param btPeripheral 指定的蓝牙外设
 */
- (void)disconnect:(BluetoothPeripheral *)btPeripheral;

/**
 *  通过蓝牙给已连接的设备发送数据
 *
 *  @param outData     下发的数据
 *  @param aPeripheral 指定的蓝牙外设
 */
- (void)send:(NSData *)outData toPeripheral:(BluetoothPeripheral *) aPeripheral;

/**
 *  获取连接状态
 *
 *  @return 0，无操作；1，监听连接；2，正在连接；3，已连接
 */
- (int)getState;

/**
 *  自定义传输的服务及读写特征值
 *
 *  @param serviceUUID 传输服务的UUID
 *  @param txUUID      写服务特征值UUID
 *  @param rxUUID      读服务特征值UUID
 */
- (void)configureTransparentServiceUUID: (NSString *)serviceUUID txUUID:(NSString *)txUUID rxUUID:(NSString *)rxUUID withPeripheralType:(int)perType;

/**
 *  设置当前蓝牙设备的类型
 *
 *  @param type 蓝牙设备类型
 */
- (void)setBLEDeviceType:(CTBLEDeviceType)type;

@end

