//
//  CPRSAEncrpTool.h
//  中汇支付
//
//  Created by cqh on 14/12/24.
//  Copyright (c) 2014年 Chepay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPRSAEncrpTool : NSObject

+ (instancetype) rsaEncrpTool;

- (NSString *) rsaEncryptWithPublicKey:(NSString *)publicKey withKeyWords:(NSString *)keyWords;
@end
