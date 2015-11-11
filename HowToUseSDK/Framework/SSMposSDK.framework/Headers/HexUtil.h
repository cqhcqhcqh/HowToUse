//
//  HexUtil.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/23.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HexUtil : NSObject
+(Byte) ByteToBcd:(int)n;

+(unsigned int)bcd2bin:(char*)bcd_buf len:(int) bcd_len;
/*----------------------------------------------------------------------------*
 * 功能: 把32位的长整数转换为bcd码.
 * 参数:
 *       unsigned char *bcd_buf - 转换后的bcd码.
 *       long *bin - 要转换长整数.
 *       int bcd_len - 转换后的bcd数据长度.
 * 返回:
 *       unsigned long - 转换后的结果.
 * 说明:
 *      如 bcd_len=2, 123  -> \x01 \x23
 *         bcd_len=2, 1230 -> \x12 \x30
 *----------------------------------------------------------------------------*/
+(void)zl_bin2bcd:(char*)bcd_buf bin:(long) bin bcd_len:(int) bcd_len;

/**
 * short转换为字节
 *
 * @param s
 * @return
 */
+(void) shortToByteArrayTwo:(short)s withCharArray:(char*) arr ;

@end
