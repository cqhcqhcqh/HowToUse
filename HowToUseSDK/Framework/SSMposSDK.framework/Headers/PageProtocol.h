//
//  PageProtocol.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/23.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UnPageData.h"

@interface PageProtocol : NSObject

+(int)packPage:(char*) cmdData dataLen:(int) dataLen pageId:(int) pageId cmd:(char*) cmd params:(char*)params paramsLen:(int)paramsLen;
+(UnPageData*)unPackPage:(NSData*) data;
@end
