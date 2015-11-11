//
//  PINData.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/29.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseVariables.h"
@interface PINData : BaseVariables
@property (nonatomic,assign) int keyId;
@property (nonatomic,assign) int pinLen;
@property (nonatomic,strong) NSString* pinblock;
@property (nonatomic,strong) NSString* KSN;
@end
