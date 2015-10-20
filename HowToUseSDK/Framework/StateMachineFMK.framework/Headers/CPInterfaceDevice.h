//
//  CPInterfaceDevice.h
//  StateMechine
//
//  Created by cqh on 15/2/3.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPInterfaceDeviceCommon.h"
#import "Promise.h"

typedef enum {
    CPUnexpectedTypePhoneBluetoothPowerOff,
    CPUnexpectedTypeDeviceBluetoothPowerOff,
    CPUnexpectedTypeDeviceUnPlugged,
}CPUnexpectedType;
@protocol CPUnexpectedListner <NSObject>
- (void)unexpectedListnerWithCode:(CPUnexpectedType)type error:(NSString *)errorDesc;

@end


@class CPDevConfigure;

@interface CPInterfaceDevice : NSObject

@property (nonatomic ,weak) id <CPUnexpectedListner> delegate;
- (CPDevConfigure *)getConfigure;

/**
 *  获取设备对象
 *
 *  @param type 设备类型
 *
 *  @return 指定的设备
 */
+ (instancetype)interfaceDeviceWithType:(CPDeviceType)type stateListner:(id<CPUnexpectedListner>)listner;

/**
 *  获取设备类型
 *
 *  @return 设备类型
 */


- (CPDeviceType)getType;


/**
 *  销毁设备
 */
- (void) destroyDevice;

/**
// *  获取设备
// *
// *  @return 设备对象
// */
//+ (instancetype) getDevice;

/**
 *  初始化设备
 *
 *  @param type 设备类型
 */
- (void) initDeviceSDKWithStateListner:(id<CPUnexpectedListner>)listner;

/**
 *  搜寻设备
 *
 *  @param timeout        超时时间
 *  @param searchDevices  搜寻到设备之后回调
    @param finish         搜索中止的回调
 */
//- (void) searchDeviceWithTimeout:(NSUInteger)timeout searchDevices:(SearchDevicesBlock)devicesBlock finish:(SearchFinishBlock)finish;
- (Promise *) searchDeviceWithTimeout:(int)timeout;

/**
 *	停止查询设备
 *
 *	@return	void
 */
//- (void) stopSearchDevice;
/*
 * 扫描中断<Interrupt Scan>
 */
- (void)searchDeviceInterruptWithReason:(NSString *)reason code:(CPSearchResultCode)code;

/**
 *  连接设备
 *
 *  @param identifier 设备识别码
 *  @param success    成功回调
 *  @param failure    失败的回调
 */
- (void) startconnectDevice:(CPDevInfo *)devInfo finish:(ConnectResultBlock)finish;

/**
 *  获取设备信息
 *
 *  @param deviceInfo 设备信息获取成功回调
 *  @param failure    设备信息获取失败回调
 */
- (void) getDeviceInfo:(SuccessGetDeviceInfoBlock) deviceInfo failure:(InterruptFailureBlock)failure;

- (Promise *)getDeviceInfo;


/**
 *  添加ic数据
 *
 *  @param icData    ic数据
 *  @param type      数据类型
 *  @param index     起始位置
 */
- (Promise *)writeICData:(NSArray *)icData type:(CPICDataType)type startIndex:(int)startIndex;

/**
 *  添加公钥
 *
 *  @param rids     公钥
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void)writeRids:(NSArray *)rids index:(int)index success:(SuccessVoidBlock)success failedBlock:(InterruptFailureBlock)failure;
- (Promise *)writeAids:(NSArray *)aids index:(int)index;

/**
 *		添加AID
 *
 *	@param 	aids 	AID信息
 *	@param 	successCB 	成功回调
 *	@param 	failedCB 	失败回调
 *
 *	@return	void
 */
- (void)writeAids:(NSArray *)aids index:(int)index success:(SuccessVoidBlock)success failedBlock:(InterruptFailureBlock)failure;
- (Promise *)writeRids:(NSArray *)rids index:(int)index;

/**
 *  更新工作密钥
 *
 *  @param workKey 密钥
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void) updateWorkKey:(CPWorkKey *)workKey success:(SuccessVoidBlock)success failure:(InterruptFailureBlock)failure;


/**
 *  启动等待刷卡
 *
 *  @param waitingCardBaseInfo 启动等待刷卡的基本信息
 *  @param success             卡类型回调
 *  @param failure             失败回调
 */
- (void)startWaitingCardWithConfigureInfo:(CPWaitingCardBaseInfo *) waitingCardBaseInfo success:(SuccessGetCardTypeBlock)success failure:(InterruptFailureBlock)failure;
- (Promise *)startWaitingCardWithConfigureInfo:(CPWaitingCardBaseInfo *)waitingCardBaseInfo;

#pragma mark ----------------------------------------- IC卡交易
/**
 *  ic卡开始交易
 *
 *  @param icTradeInfo ic卡交易信息
 *  @param success     ic卡信息回调
 *  @param onReadIcDataSuccess 读取ic卡信息成功
 *  @param failure     失败回调
 */
- (void) icCardBeginDeal:(CPICTradeInfo *)icTradeInfo onReadIcDateSucc:(SuccessVoidBlock)onReadIcDataSuccess success:(SuccessGetICInfoBlock)success failure:(InterruptFailureBlock)failure;
- (Promise *) icCardBeginDeal:(CPICTradeInfo *)icTradeInfo;
/**
 *  获取卡号密码
 *
 *  @param inputInfo 获取密码请求参数
 *  @param emvResult 获取密码联机处理结果
 *  @param failure   失败回调
 */
- (void)icCardGetPassword:(CPGetPin *)inputInfo success:(SuccessEmvResultBlock)emvResult failure:(InterruptFailureBlock)failure;


/**
 *	@brief	联机交易后请求数据
 *
 *	@param 	onLineData 	联机交易的信息
 *	@param 	success 	成功回调
 *	@param 	failure	失败回调
 *
 *	@return	void
 */
- (void)icCardOnlineDataProcess:(CPEMVOnlineData *)onLineData
              success:(SuccessEmvResultBlock)success failure:(InterruptFailureBlock)failure;

- (Promise *)icCardOnlineDataProcess:(CPEMVOnlineData *)onLineData;
/**
 *	@brief	停止IC交易
 *
 *	@param 	success 	成功回调
 *	@param 	failure	失败回调
 *
 *	@return	void
 */
- (void) icCardDealStop:(SuccessVoidBlock)success failure:(InterruptFailureBlock)failure;


#pragma mark ----------------------------------------- 磁条卡交易

/**
 *  获取磁条卡信息
 *
 *  @param success 磁条卡信息回调
 *  @param failure 失败回调
 */
- (void)magGetCardInfoSuccess:(SuccessGetMagCardInfoBlock)success failure:(InterruptFailureBlock)failure;
- (Promise *)magGetCardInfo;
/**
 *  获取磁条卡密码
 *
 *  @param inputInfo 获取密码请求参数
 *  @param success   密码数据获取成功回调
 *  @param failure   失败回调
 */
- (void) magGetPinWith:(CPGetPin *)inputInfo success:(SuccessGetPinBlock)success failure:(InterruptFailureBlock)failure;

#pragma mark ***************************************************** 艾创获取密码
- (Promise *)getPasswordWithCardType:(CPCardType)cardType;

#pragma mark ----------------------------------------- 计算mac
- (Promise *)calculateMac:(CPMacResourceData *)macData;
/**
 *  获取计算出来的mac
 *
 *  @param macData 需要计算的数据
 *  @param success 计算结果回调
 *  @param failure 失败回调
 */
- (void) calculateMac:(NSString*)macData
         success:(SuccessGetMacBlock)success failure:(InterruptFailureBlock)failure;

/**
 *  显示文本
 *  
 *  @param text    需要显示的文字
 *  @param time    显示的时间
 *  @param success 成功回调
 *  @param failure 失败回调
 */
- (void) displayText:(NSString *)text showTime:(int)time success:(SuccessVoidBlock)success failure:(InterruptFailureBlock)failure;

///**
// *  停止PBOC交易
// */
//
//- (void) stopPBOCWithSuccess:(SuccessVoidBlock)success failure:(FailureBlock)faillure;

/**
 *  关闭设备
 */
- (void) closeConnect:(CloseDeviceBlock)closed;

/**
 *  中断连接
 *
 */
- (void) stopConnecting;

/**
 *  取消写入Aids
 */
- (void) cancelWriteAids;

/**
 *  取消写入Rids
 */

- (void) cancelWriteRids;


/**
 *  取消写入交易
 */
- (void) cancelTrade;

- (void) cancelInputPin;
- (void) add;
- (int ) count;
/**
 *  sdk的调用方法
 *
 */
+ (instancetype) getDevice;


@end
