//
//  Commod.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/27.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommunicateDelegate.h"
#import "CorresponseUtil.h"
#import "BluetoothManagerDataSource.h"
#import "BluetoothPeripheral.h"
#import "BLEBluetoothManager.h"
#import "HexUtil.h"
#import "DeviceInfo.h"
#import "MposBlock.h"
#import "UpdateInfo.h"


@interface CommandImpl : NSObject<CommunicateDelegate,BluetoothManagerDataSource>

@property   (nonatomic ,strong)CorresponseUtil *corresponseUtil;
@property   (nonatomic ,strong) BLEBluetoothManager *bluetoothManager;
@property   (nonatomic ,strong) BluetoothPeripheral *curPeripheral;
@property   (nonatomic) BOOL isConnected;
@property   (nonatomic ,strong)NSMutableArray *reviceDatas;
@property   (nonatomic ,strong)NSTimer *timer;
@property   (nonatomic )BOOL isTimeout;
@property   (nonatomic ,strong) NSMutableData *mutableRespData;
@property   (nonatomic) int  respDataLen;
@property   (nonatomic)int  timeout;
@property   (nonatomic)BOOL isReset;
@property   (nonatomic) BOOL   isExist;
@property   (nonatomic)  int localPro;




-(DeviceInfo*) getDeviceInfo;
-(UnPageData*) openCardReader:(int) type timeout: (int) tmo display: (char*) display displayLen:(int) displayLen;
-(UnPageData*) readTrackDataWithEncrypted:(int) PKeyIndex type:
(int) type panShieldMask:(char*) panShieldMask panShieldMaskLen:(int)panShieldMaskLen encryptArithmeticMark: (int) encryptArithmeticMark keyIndex
                                         :(int) keyIndex key:(char*) key keyLen:(int) keyLen random: (char*) random randomLen:(int)randomLen tranceNo:(char*) tranceNo tranceNoLen :(int)tranceLen arithmeticType:(int)arithmeticType extras:(char*)extras extrasLen:(int)extrasLen withTimeout:(int) tmo;


-(UnPageData*) readTrackDataWithUnencrypted:(int) type;

-(UnPageData*)inputPin:(int) index keyType: (int) keyType panMark: (int) panMark panOrPanSHA:
(char*)panOrPanSHA panOrPanSHALen:(int) panOrPanSHALen key:(char*) key keyLen:(int) keyLen maxLen: (int) maxLen extras: (char*) extras extrasLen:(int)extrasLen isUseEnterKey:
(int) isUseEnterKey tmo:(int) tmo displayData: (char*) displayData displayDataLen:(int)displayDataLen;

-(UnPageData*) calMAC:(int) keyIndex keyType: (int) keyType MACType: (int) MACType
            blockMark:(int) blockMark data:(char*)data dataLen:(int)dataLen wKey:(char*)wKey
              wKeyLen:(int) wKeyLen;

-(UnPageData*) loadWorkKey:(int) KeyType  mKeyIndex:(int) mKeyIndex wKeyIndex: (int) wKeyIndex
               wKey: (char*) wKey wKeyLen:(int) wKeyLen;

-(UnPageData*) executeStandardProcess:(char*) tlv tlvLen:(int) tlvLen withTimeout:(int)tmo ;

-(UnPageData*) twiceAuthorization:(char*) tlv tlvLen:(int) tlvLen;

-(BOOL) endPBOC;

-(BOOL) updaTime:(char*) time timeLen:(int)timeLen;

-(UnPageData*) acquireTime;

-(BOOL) reset ;

-(BOOL) updateRID:(int) type pubKey: (char*) pubKey pubKeyLen:(int) pubKeyLen;


-(BOOL) updateAID:(int) type AID:(char*) AID AIDLen :(int) AIDLen;

-(BOOL) displayString:(int) tmo withDisplay:(NSData*) display;

-(BOOL) clearScreen;

-(BOOL) setCursorPositionWithX:(int) x Y:(int) y;

-(BOOL) useBuzzer:(NSData*) number withHz:(NSData*) Hz withTime:(NSData*) time withIntervalTimer:(NSData*) intervalTimer withTimeout:(int) tmo;

- (void)updateFirmware:(NSString *)firmwarePath withUpdateBlock:(UpdateBlock)updateBlock withErrBlock:(ErrorBlock)errBlock;


@end
