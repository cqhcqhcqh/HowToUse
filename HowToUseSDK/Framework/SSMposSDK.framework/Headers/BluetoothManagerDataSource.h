//
//  BluetoothManagerDataSource.h
//  MposSDKDemo
//
//  Created by centerm on 14-4-2.
//  Copyright (c) 2014年 Centerm. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BluetoothManagerDataSource <NSObject>


@required

- (void)didReciveResponse:(NSData *)data;
- (void)didFailToSendData:(NSError *)error;


@end
