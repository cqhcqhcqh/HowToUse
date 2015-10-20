# 中汇移动支付，iOS接入设备SDK使用注意
> **Beta:**
> 该API仍处于 Beta 阶段

```
1. 该接口适用对象：中汇合作APP
2. 该接口实现功能：进行刷卡收款
```

## API 接口地址

### 1、接入设备SDK的接口设定
参考使用:
[CPHttpTool cofigureUrlString:@"http://zftpay.21er.net:15080"];

### 2、订单号的生成使用文档链接 [点我](https://github.com/tangye1234/sdk-doc/blob/master/User%20API.md)

```
https://payment.vcpos.cn # 生产环境
http://zftpay.21er.net:15080 # 测试环境
```
## 配置项目,使用注意

```
1. 需要下载必要的Resources 下载地址:[SDKResource.zip](https://codeload.github.com/cqhcqhcqh/SDKResources/zip/master)
2. 导入动态库(将cnepay_developkit_bt_FMK.framework和StateMachineFMK.framework导入至Embedded Binaries)
3. 在项目的主info-plist文件中配上NSLocationWhenInUseUsageDescription对应的key<SDK中涉及到定位,需兼容iOS8.0>

```

