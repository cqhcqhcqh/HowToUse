//
//  UnPageData.h
//  SSMposSDK
//
//  Created by cuixj on 15/4/23.
//  Copyright (c) 2015年 soccis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseVariables.h"
@interface UnPageData : BaseVariables

@property (nonatomic) int execute_id;
@property (nonatomic,strong)   NSData* params;

@end
