//
//  CorresponseUtil.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/26.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "UnPageData.h"
#import "PageProtocol.h"
#import "CommunicateDelegate.h"

typedef NS_ENUM(NSInteger, timeout_type) {
    //以下是枚举成员
    SHORT =0,
    LONG, CUSTOM
};
@interface CorresponseUtil : NSObject

@property (atomic, assign)   NSObject<CommunicateDelegate> *communicateDelegate;



-(UnPageData*)translate:(char*) cmd params:(char*) params paramsLen:
(int) paramsLen timeout_type: (timeout_type) tmo_type timeout:(int) timeout;

@end
