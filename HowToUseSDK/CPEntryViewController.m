//
//  CPEntryViewController.m
//  SDKDemo
//
//  Created by Cnepay on 15/10/19.
//  Copyright (c) 2015年 Cnepay. All rights reserved.
//

#import "CPEntryViewController.h"
#import <cnepay_developkit_bt_FMK/cnepay_developkit_bt_FMK.h>


@interface CPEntryViewController ()
@property (weak, nonatomic) IBOutlet UITextField *orderTokenTF;
@property (weak, nonatomic) IBOutlet UITextField *orderTextField;
@property (weak, nonatomic) IBOutlet UITextField *mechantTF;
@property (weak, nonatomic) IBOutlet UITextField *ksnTF;

@property (strong, nonatomic) CPDealBaseInfo *baseInfo;
@end

@implementation CPEntryViewController

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self.view endEditing:YES];
}

- (IBAction)fetchOrderAction {
    
    __block CPDealBaseInfo *dealBaseInfo = [[CPDealBaseInfo alloc] init];
    __weak typeof(self) weakself = self;
    self.baseInfo = dealBaseInfo;
    [CPOrderProductTool configureOrderUrlString:@"http://zftapi.21er.net:15080"];
     [CPOrderProductTool orderMakeWithMerchantCode:self.mechantTF.text Success:^(NSString *order, NSString *orderToken) {
         weakself.orderTextField.text = order;
         weakself.orderTokenTF.text = orderToken;
     } failure:^(NSError *respError) {
         
     }];
}


- (IBAction)goinSDK {

    self.baseInfo.ksnNo = self.ksnTF.text;
    self.baseInfo.orderNo = self.orderTextField.text;
    self.baseInfo.orderToken = self.orderTokenTF.text;
     [[CPContainerViewController alloc] initWithDealBaseInfo:self.baseInfo aPresentingViewController:self];
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [CPHttpTool cofigureUrlString:@"http://zftpay.21er.net:15080"];
}


@end
