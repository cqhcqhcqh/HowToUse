# 中汇移动支付，iOS接入设备SDK使用注意
> **Beta:**
> 该API仍处于 Beta 阶段

```
1. 该接口适用对象：SDK或中汇自有APP
2. 该接口实现功能：进行刷卡收款
3. 该接口调用规范：采用HTTPS请求与中汇的前置POSP进行通信
```


## API 接口地址
```
https://payment.vcpos.cn # 生产环境
http://zftpay.21er.net:15080 # 测试环境
```
## 使用注意
#### 1\. 需要下载必要的Resources 下载地址:[SDKResource.zip](https://codeload.github.com/cqhcqhcqh/SDKResources/zip/master)
#### 2\. 导入动态库(将cnepay_developkit_bt_FMK.framework和StateMachineFMK.framework导入至Embedded Binaries)
#### 3\. 在项目的主info-plist文件中配上NSLocationWhenInUseUsageDescription对应的key<SDK中涉及到定位,需兼容iOS8.0>


