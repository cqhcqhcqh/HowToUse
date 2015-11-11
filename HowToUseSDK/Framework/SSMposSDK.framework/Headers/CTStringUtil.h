//
//  CTStringUtil.h
//  CMposSDKSource
//
//  Created by centerm on 14-7-26.
//  Copyright (c) 2014年 centerm. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef	unsigned char   U8;
typedef unsigned short  U16;
#define MapBin2Hex(bBin) (((bBin) >= 0 && (bBin) <= 9) ? ((bBin) + '0'): ((bBin) - 10 + 'A'))
#define MapHex2Bin(cHex) ((cHex) <= '?' && (cHex) >= '0') ? ((U8)(cHex) - '0') /*L*/\
: (((cHex) <= 'f' && (cHex) >= 'a') ? ((U8)(cHex) - 'a' + 10) /*L*/\
: (((cHex) <= 'F' && (cHex) >= 'A') ? ((U8)(cHex) - 'A' + 10) : 16))
#define MAKEBYTE(l, h)			((unsigned char)(((unsigned char)(l) & 0x0F) | ((((unsigned char)(h)) << 4) & 0xF0)))

@interface CTStringUtil : NSObject

+ (NSData *)stringToHexStr:(NSString *)str;
+ (NSData *)hexStrToData:(NSString *)hexStr;
+ (NSData *)hexToString:(NSData *)data;
+ (NSData *)stringToHex:(NSData *)data;
+ (NSString *)stringToAsc:(NSString *)str;

// NSString转BCD码
+ (void) convertStrToBCD:(NSString *)str toBCD:(Byte [])bcd;
// ASCII码字符串转BCD字符串
+ (unsigned short) ascToBcd:(char *)asc withAscLen:(unsigned short)usLen toBcd:(Byte [])bcd;

+ (NSString *)ConvertHex:(char*)pHex withHexLen:(NSInteger)hexLen option:(BOOL)hasBlank;

+ (NSString *)GetErrInfo:(int)errCode;

@end
