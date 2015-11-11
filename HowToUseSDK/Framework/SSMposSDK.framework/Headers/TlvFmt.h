//
//  TlvFmt.h
//  HelloWorld
//
//  Created by centerm on 14-7-14.
//  Copyright (c) 2014年 centerm. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TlvFmt : NSObject
// 格式化为tlv数据
+(NSData *)dictToTlv:(NSDictionary *)dict;
// 解析tlv数据
+(NSDictionary *)tlvToDict:(NSData *)tlv;

@end
