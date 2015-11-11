//
//  BaseVariables.h
//  SSMposSDK
//
//  Created by cuixj on 15/6/4.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MSG_SUCC  @"成功"
#define MSG_RESET  @"复位"
#define MSG_COMM_ERR @"终端通信异常"
#define MSG_PAGE_DATA_ERR @"包数据异常"


#define CODE_SUCC @"00"

#define CODE_RESET @"91"
#define CODE_COMM_ERR @"92"
#define CODE_PAGE_DATA_ERR @"93"

@interface BaseVariables : NSObject

@property (nonatomic,strong) NSString* errCode;
@property (nonatomic,strong) NSString* errMsg;




- (id)init;

-(void) upateMsg:(NSString*) curCode;

@end
