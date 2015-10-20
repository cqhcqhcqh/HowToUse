//
//  CPOrderProductTool.h
//  cnepay_developkit_bt
//
//  Created by cqh on 15/5/5.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPOrderProductTool : NSObject

+ (void) orderMakeWithMerchantCode:(NSString *)merchantcode Success:(void(^)(NSString* order ,NSString *orderToken))order failure:(void(^)(NSError* respError))failure;

+ (void) configureOrderUrlString:(NSString *)urlString;

+ (NSString *)getOrderUrl;

@end
