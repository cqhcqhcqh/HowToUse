//
//  CPSendMessageOperation.h
//  GCD的其他用法
//
//  Created by cqh on 15/1/27.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CPMessage,CPSendMessageOperation;

@protocol CPSendMessageOperationDelegate <NSObject>
@optional
- (void) sendMessageOperation:(CPSendMessageOperation *) operation didFinishSendMessage:(CPMessage *)message;
@end

@interface CPSendMessageOperation : NSOperation
@property (nonatomic ,weak) id <CPSendMessageOperationDelegate> delegate;
@property (nonatomic ,strong) CPMessage *message;

- (instancetype) initWithTask:(CPMessage *)message;
+ (instancetype) sendMessageOperationWithTask:(CPMessage *)message;
@end

@interface CPMessage : NSObject

+(instancetype)cpMessage;
@property (nonatomic ,assign) int type;
@property (nonatomic ,assign) int subType;
@property (nonatomic ,assign) int code;
@property (nonatomic ,strong) id obj;
@end
