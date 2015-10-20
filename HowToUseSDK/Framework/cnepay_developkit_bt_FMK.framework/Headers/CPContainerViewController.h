//
//  CPContainerViewController.h
//  ContainerViewController
//
//  Created by cqh on 15/3/27.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import "CPMainNavController.h"

FOUNDATION_EXTERN NSString *const kCollectionSuccess;
FOUNDATION_EXTERN NSString *const kCollectionFailure;
@class CPDealBaseInfo;
@interface CPContainerViewController : CPMainNavController
- (void)initWithDealBaseInfo:(CPDealBaseInfo *)dealInfo aPresentingViewController:(UIViewController *)aController;
- (void) exitSDK;
@end
