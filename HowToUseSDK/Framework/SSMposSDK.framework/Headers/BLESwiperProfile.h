//
//  BLESwiperProfile.h
//  BLESwiper
//
//  Created by centerm on 14-3-7.
//  Copyright (c) 2014年 Centerm. All rights reserved.
//

#ifndef BLESwiper_BLESwiperProfile_h
#define BLESwiper_BLESwiperProfile_h


typedef NS_ENUM(NSInteger, bleCentralDelegateState) {
	bleCentralDelegateStateCentralManagerPoweredOff = 0,            //上位机蓝牙未开启
	bleCentralDelegateStateCentralManagerUnauthorized,
	bleCentralDelegateStateCentralManagerUnknown,
	bleCentralDelegateStateCentralManagerUnsupported,               //上位机不支持蓝牙4.0
	bleCentralDelegateStateCentralManagerPoweredOn,
	bleCentralDelegateStateCentralManagerResetting,
    bleCentralDelegateStateRetrieveConnectedPeripherals,
    bleCentralDelegateStateDiscoverPeripheral,
    bleCentralDelegateStateConnectPeripheral,
    bleCentralDelegateStateDidConnectPeripheral,
    bleCentralDelegateStateFailToConnectPeripheral,
};


#define SECONDS_SEND_DATA                   0.001
#define max_time_searchDevice               30.0f

#define SECONDS_WAIT_RESPONSE               30.0f //秒
#define MAX_RESEND_TIMES                    3
#define MAX_TIME_PAIRDEVICE                 20





#define ERROR_CODE_CSwiperController_SENDDATA_TIMEOUT                901
#define ERROR_MESSAGE_CSwiperController_SENDDATA_TIMEOUT            @"发送数据超时"


#endif
