//
//  SwipeCardResponse.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/28.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseVariables.h"
@interface SwipeCardData : BaseVariables



@property (nonatomic ,strong) NSString* pan;//卡PAN
@property (nonatomic ,strong) NSString* panHash;
@property (nonatomic ,strong) NSString* oneTrack;//加密一磁
@property  (nonatomic ,strong)NSString* twoTrack;//加密二磁
@property (nonatomic ,strong) NSString* threeTrack;//加密三磁
@property  (nonatomic ,strong)NSString* expiryDate;//卡有效期
@property (nonatomic ,strong) NSString* KSN;
@property  (nonatomic ,strong)NSString* extras;
@property  (nonatomic ,strong)NSString* icParams;//55域IC数据
@property (nonatomic ,strong) NSString* carSeq;//卡序列号
@property (nonatomic) int cardType;//1磁条卡 2 ic卡
@property (nonatomic ,strong) NSString* executeResult;
@property (nonatomic ,strong) NSString* unEncTrack2Data;//未加密二磁数据

@end
