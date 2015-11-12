//
//  MposController.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/29.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommandImpl.h"
#import "DeviceInfo.h"
#import "SwipeCardData.h"
#import "PINData.h"
#import "MACData.h"
#import "TwiceAuthorData.h"
#import "CTStringUtil.h"
#import "TlvFmt.h"
#import "MposBlock.h"

typedef NS_ENUM(NSInteger, WorkType) {
    //以下是枚举成员
    PIN =0,
    MAC, TRACK
};
@interface MposController : NSObject


@property (nonatomic,strong) CommandImpl* mCommandImpl;


+(MposController*) shareInstance;
/**
 * 初始化
 * @param peripheralDelegate  外设代理
 */
-(instancetype)initWithPeripheralDelegate:(NSObject *)peripheralDelegate;

/**
 * 获取设备信息
 *
 */
-(DeviceInfo*) getDeviceInfo;

/**
 * 获取终端时间
 * @return 格式：YYYYMMDDHHMMSS
 */
-(NSString*) acquireTime;
/**
 *设置终端时间
 * @param time 格式：YYYYMMDDHHMMSS
 */
-(BOOL) updateTime:(NSString*) time;


/**
 * 要求mPOS执行刷卡或插卡
 *
 * @param tmo
 *            刷卡超时时间
 * @param amt
 *            金额，请格式化成'000000000000'
 * @param display
 *            显示信息
 * @return
 */
-(SwipeCardData*) swipeCard:(int) tmo amt:(NSString*) amt display:(NSString*) display;
                                                              
                                                              
/**
 * 要求mPOS执行输入密码
 * @param tmo
 *            超时时间
 * @param pan
 *            刷卡返回的PAN
 * @param display
 *            显示信息
*/
-(PINData*) inputPinWithPan:(int) tmo  PAN:( NSString*) pan display:(NSString*) display;
                                                              
/**
 * 计算MAC 银联算法
 *
 * @param data用于计算的数据
 * @return
 */
-(MACData*) calMac:(NSString*) data;
                                                              
/**
 * 更新工作密钥
 * @param keyType
 * @param key
 */
-(BOOL) loadWorkKey:(WorkType)keyType key:(NSString*)key kcv:(NSString*) kcv;
                                                              
/**
 * 复位
 * @return
 */
-(BOOL)reset;
                                                              
/**
 * 执行二次授权(实现发行卡认证、发卡行脚本处理、联机不成功的后续处理，完成第二次Generate AC)
 * @param respCode (39域返回结果 格式为3030);
 * @param tlv (55域返回结果)
 */
-(TwiceAuthorData*) twiceAuthorization :(NSString*) respCode TLV:(NSString*) tlv;




/**
 *结束PBOC标准流程
 */
-(BOOL) endPBOC;
/*
 * 更新公钥信息
 * int type
 * 0x01  清除全部公钥
 * 0x02  增加一个公钥
 * 0x03  删除一个公钥
 */
-(BOOL) updateRID:(int) type pubKey:(NSString*) pubKey;

/*
 * 更新AID信息
 * int type
 * 0x01  清除全部AID
 * 0x02  增加一个AID
 * 0x03  删除一个AID
 */
-(BOOL) updateAID:(int) type AID:(NSString*) AID;


-(BOOL) displayString:(int) tmo withX: (int) x withY:(int) y withPlay:(NSString*) display;


- (void)updateFirmware:(NSString *)firmwarePath withUpdateBlock:(UpdateBlock)updateBlock withErrBlock:(ErrorBlock)errBlock;


-(BOOL) useBuzzer:(short) number withHz:(short) Hz withTime:(short) time withIntervalTimer:(short) intervalTimer ;

#pragma mark - bluetooth
/**
 *  设置外设代理
 */
-(void) setPeripheralDelegate:(NSObject *) peripheralDelegate;
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
 *  连接蓝牙
 *
 *  @param cbPeripheral 指定的蓝牙外设
 */
- (void)connectWithCBPeripheral:(CBPeripheral *)cbPeripheral;
/**
 *  连接蓝牙
 *
 *
 */
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

-(BOOL) isHaveConnected;

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
