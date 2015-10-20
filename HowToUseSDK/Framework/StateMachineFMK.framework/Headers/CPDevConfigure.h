//
//  CPDevConfigure.h
//  StateMechine
//
//  Created by cqh on 15/3/3.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CPInitialDevParam;

@interface CPDevConfigure : NSObject
@property (nonatomic ,copy) NSString *model;

+ (instancetype)devConfigureWithUnique:(NSString *)name;
- (instancetype)initWithUnique:(NSString *)name;

- (void)saveInitialDevParam:(CPInitialDevParam *)param;
- (void)clearInitialDevParam;
- (CPInitialDevParam *)getInitialDevParam;
- (void)clearWorkKey;
- (void)clearKsn;
- (void)closeUpdate;
- (void)openUpdate;

@end
