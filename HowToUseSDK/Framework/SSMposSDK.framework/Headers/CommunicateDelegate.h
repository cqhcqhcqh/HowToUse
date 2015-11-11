//
//  CommunicateDelegate.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/27.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CommunicateDelegate <NSObject>

@required

- (NSData *)didReciveData:(int) tmo;
- (void)didSendData:(NSData *)data;
-(BOOL) isReset;
-(void) updateResetStatus:(BOOL) status;
@end




