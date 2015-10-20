//
//  CPInterfaceDeviceCommon.h
//  StateMechine
//
//  Created by cqh on 15/2/3.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPDevInfo.h"

typedef NS_ENUM(NSUInteger, CPInterruptResultCode) {
    
    CPInterruptResultCodeStopAid = 400,
    CPInterruptResultCodeStopRid,
    CPInterruptResultCodeStopTrade,
    CPInterruptResultCodeStopWaitingCard,
    CPInterruptResultCodeStopBeginICDeal,
    CPInterruptResultCodeStopBeginMagDeal,
    CPInterruptResultCodeStopContinueICDeal,
    CPInterruptResultCodeStopContinueMagDeal,
    CPInterruptResultCodeStopUpdateWorkKey,
    CPInterruptResultCodeStopGetDeviceInfo,
    CPInterruptResultCodeStopOnlineData,
    CPInterruptResultCodeStopCalculateMac,
    CPInterruptResultCodeStopDisplayScreen,
    CPInterruptResultCodeTimeout,
    CPInterruptResultCodeStopEndPBOC,
    CPInterruptResultCodeUnexpected,
    CPInterruptResultCodeKSNUNPAIRED,
};

typedef NS_ENUM(NSUInteger, CPSearchResultCode) {
    CPSearchResultCodeTimeout = 200,
    CPSearchResultCodeBluetoothPowerOff,
    CPSearchResultCodeBluetoothStateUnknow,
    CPSearchResultCodeBluetoothUnauthorized,
    CPSearchResultCodeBluetoothUnsupport,
    CPSearchResultCodeBluetoothResetting,
    CPSearchResultCodeBluetoothPerformConncet,
    CPSearchResultCodeDisscan,
    CPSearchResultCodeHeadPhoneUnplugged,
};

typedef NS_ENUM(NSUInteger, CPConnectResultCode) {
    CPConnectResultCodeSuccess = 300,
    CPConnectResultCodeFailure,
    CPConnectResultCodeUnexpected,
};

typedef enum {
    CPErrorCodeTimeOut = 502,
    CPErrorCodeUnexpected,
}CPErrorCode;

/**
 *	@brief	icdata数据类型
 *	@param 	CPICDataAID
 *	@param 	CPICDataRID   ic公钥
 */
typedef enum  {
    CPICDataTypeAID               = 0,
    CPICDataTypeRID ,
}CPICDataType;

FOUNDATION_EXPORT NSString* const CPICDataTypeMapping [];
/**
 *	@brief	密钥类型
 *	@param 	CPKeyTypeTRACK   磁道密钥
 *	@param 	CPKeyTypePIN     PIN密钥
 *	@param 	CPKeyTypeMAC     MAC密钥
 */
typedef enum  {
    CPKeyTypeTRACK               = 1,
    CPKeyTypePIN ,
    CPKeyTypeMAC ,
}CPKeyType;

/**
 *	@brief	支持的卡种
 *	@param 	SUPPORTCARDTYPE_MAG         支持磁条卡
 *	@param 	SUPPORTCARDTYPE_IC          支持IC卡
 *	@param 	SUPPORTCARDTYPE_RF          非接卡
 */
typedef enum {
    CPSupportCardType_MAG        = 0x01,
    CPSupportCardType_IC         = 0x02,
    CPSupportCardType_RF         = 0x04,
}CPSupportCardType;

/**
 *	@brief	刷卡、插卡返回的卡片类型
 *	@param 	CARDTYPE_MAGNETIC   磁条卡
 *	@param 	CARDTYPE_ICC        IC卡
 *	@param 	CARDTYPE_PENDING    冲正
 */
typedef enum {
    CPCardType_MAGNETIC          = 1,
    CPCardType_ICC               ,
    CPCardType_RF                ,
    CPCardType_PENDING           ,
}CPCardType;

/**
 *	@brief	交易类型
 *	@param 	TRADETYPE_PURCHASE    消费
 *	@param 	TRADETYPE_REVOKE      消费撤销
 *	@param 	TRADETYPE_QUERY       查余额
 *	@param 	TRADETYPE_TRANSFER    转账
 */
typedef enum{
    CPTradeTypePURCHASE          = 0x00,
    CPTradeTypeREVOKE            = 0x20,
    CPTradeTypeQUERY             = 0x30,
    CPTradeTypeTRANSFER          = 0x40,
} CPTradeType;


@class CPDevInfo,CPICCardInfo,CPEMVResult,CPMagCardDataInfo,CPFetchDevInfo;

typedef void (^SearchDevicesBlock)(NSMutableArray *deviceArray,int responCode);
typedef void (^SearchFinishBlock)(CPSearchResultCode resCode,NSString *resDesc,int responCode);
typedef void (^ConnectResultBlock)(CPConnectResultCode resCode,NSString *resDesc,int responCode);

typedef void (^CloseDeviceBlock)();
typedef void (^FailureBlock)(NSUInteger errCode,NSString* errInfo,int responCode);

typedef void (^InterruptFailureBlock)(CPInterruptResultCode errCode,NSString* errInfo,int responCode);

typedef void (^FinishVoidBlock)();
typedef void (^SuccessVoidBlock)(int responCode);

typedef void (^SuccessGetDeviceInfoBlock)(CPFetchDevInfo* deviceInfo,int responCode);
typedef void (^SuccessGetCardTypeBlock)(CPCardType cardType,int responCode);
typedef void (^SuccessGetICInfoBlock)(CPICCardInfo *icInfo,NSString *desc,int responCode);
typedef void (^SuccessEmvResultBlock) (CPEMVResult *emvResult ,int responCode);
typedef void (^SuccessGetMagCardInfoBlock)(CPMagCardDataInfo* trackData,NSString *desc,int responCode);
typedef void (^SuccessGetPanBlock)(NSString* pan,int responCode);
typedef void (^SuccessGetPinBlock)(NSString *pin,int responCode);
typedef void (^SuccessGetMacBlock)(NSString *mac,int responCode);

@interface CPWorkKey : NSObject
@property (nonatomic, assign) CPKeyType workKeyType;
@property (nonatomic, copy  ) NSString  * workKeyData;
@end

@interface CPWaitingCardBaseInfo : NSObject
@property (nonatomic ,assign) int               timeOut;
@property (nonatomic, copy  ) NSString          * moneyNum;
@property (nonatomic ,copy  ) NSString          *desc;
@property (nonatomic ,assign) CPSupportCardType supportCardType;
/*
 *V1刷卡交易需要的参数
 */
@property (nonatomic ,copy) NSString *ksnNo;
@property (copy, nonatomic) NSString *reqNo;
@end

/**
 *	@brief	IC交易信息
 *	@param 	flag        强制联机标识
 *	@param 	type        交易类型
 *	@param 	moneyNum    授权金额
 *	@param 	date        交易日期
 *	@param 	time        交易时间
 */
@interface CPICTradeInfo : NSObject
@property (nonatomic) CPTradeType tradeType;
@property (nonatomic,copy) NSString  * moneyNum;
@property (nonatomic, assign) Byte  getPinTimeout;
@end

@interface CPMacResourceData : NSObject
@property (copy, nonatomic) NSString *macData;
@property (copy, nonatomic) NSString *v1DeviceMac;
@end

/**
 *	@brief	IC交易处理返回数据
 *	@param 	track2data  二磁道等价数据
 *	@param 	cardExpired 卡片有效期
 *	@param 	panSerialNO IC卡序列号
 *	@param 	pan        IC卡卡号
 *  @param 	icPAN     16位的PAN
 */
@interface CPICCardInfo : NSObject
@property (nonatomic,copy) NSString *icTrack2data;
@property (nonatomic,copy) NSString *icCardExpired;
@property (nonatomic,copy) NSString *icPanSerialNO;
@property (nonatomic,copy) NSString *icPan;
@property (nonatomic ,copy) NSString *icPAN;
@property (copy, nonatomic) NSString *v1DeviceMac;
@end


/**
 *	@brief	磁道数据
 *	@param 	isCipher   是否加密
 *	@param 	track1     磁道数据
 *	@param 	track2     磁道数据
 *	@param 	track3     磁道数据
 *  @param 	magPan     明文卡号
 *  @param 	magPAN     16位的PAN
 */
@interface CPMagCardDataInfo :NSObject
@property (nonatomic ,getter = isEncrypt) BOOL encrpt;
@property (nonatomic, copy) NSString * magTrack1;
@property (nonatomic, copy) NSString * magTrack2;
@property (nonatomic, copy) NSString * magTrack3;
@property (nonatomic ,copy) NSString * magPan;
@property (nonatomic ,copy) NSString * magPAN;
@property (copy, nonatomic) NSString *v1DeviceMac;
@end



/**
 *	@brief	读取PIN密文输入数据
 *	@param 	cardPan    卡号
 *	@param 	amount      交易金额（6字节）
 *	@param 	timeout     PIN输入超时时间（单位：秒）
 */
@interface CPGetPin : NSObject
@property (nonatomic, copy  ) NSString * icPan;
@property (nonatomic, copy  ) NSString * moneyNum;
@property (nonatomic, assign) Byte     timeout;
@end


/**
 *  @param password 卡密码密文
 *  @param icData   IC卡55域IC数据
 */
@interface CPEMVResult : NSObject
@property (nonatomic,copy)  NSString* password;
@property (nonatomic,copy)  NSString* icData;
@end

/**
 *	@param 	responseCode  授权响应码, 联机完成时此域必须存在，即39域数据
 *	@param 	scipt    联机请求返回数据，即55域数据
 */
@interface CPEMVOnlineData : NSObject
@property (nonatomic,copy) NSString *responseCode;
@property (nonatomic,copy) NSString *scipt;
@end

/**
 *  交易参数
 *  @parma transactionDate 交易日期
 *  @parma transactionTime 交易时间
 *  @parma transactionType 交易类型
 *  @parma transactionCurrencyCode 交易货币种类
 *  @parma transactionNum 交易金额
 */
@interface CPTransactioninfo : NSObject
@property(nonatomic,retain)NSString *transactionDate;
@property(nonatomic,retain)NSString *transactionTime;
@property(nonatomic,retain)NSString *transactionType;
@property(nonatomic,retain)NSString *transactionCurrencyCode;
@property(nonatomic,retain)NSString *transactionNum;
@end


