//
//  CPHttpTool.h
//  中汇支付
//
//  Created by cqh on 14/10/8.
//  Copyright (c) 2014年 Chepay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StateMachineFMK/CPLoggerManager.h>

@interface CPHttpTool : NSObject
typedef void(^SuccessBlock)(id resp);
typedef void(^Failure)(NSError* respError);

@property (nonatomic ,copy)SuccessBlock success;
@property (nonatomic ,copy)Failure failure;

+ (void)getMethodWithUrl:(NSString *)urlString params:(NSDictionary *)params success:(SuccessBlock )success failure:(Failure)failure;

+ (void)postMethodWithUrl:(NSString *)urlString params:(NSDictionary *)params success:(SuccessBlock )success failure:(Failure)failure;

+ (void)postMethodWithFile:(NSArray *)formDataArr Url:(NSString *)urlString params:(NSDictionary *)params success:(SuccessBlock )success failure:(Failure)failure;

+ (void)cofigureUrlString:(NSString *)urlString;
+ (NSString *)mainUrlString;
@end


/**
 *  用来封装文件数据的模型
 */
@interface CPFormData : NSObject
/**
 *  文件数据
 */
@property (nonatomic, strong) NSData *data;

/**
 *  参数名
 */
@property (nonatomic, copy) NSString *name;

/**
 *  文件名
 */
@property (nonatomic, copy) NSString *filename;

/**
 *  文件类型
 */
@property (nonatomic, copy) NSString *mimeType;

@end;
