# SmartSwitch
> 物联网DIY —— 用ESP8266和小爱同学语音控制开关灯

## 准备

### 硬件准备

1. ESP8266开发板
2. 继电器
3. 烧入设备CH340
4. 220V转5V电灯
5. 一条充电器线

### 软件准备

1. 安装`Arduino IDE` 和` ESP8266扩展包`

   Arduino IDE默认没有集成ESP8266扩展包，因此需要单独安装。扩展包可以通过Arduino IDE中开发板管理器安装，也可以使用离线安装包。安装扩展包后，即可在Arduino IDE菜单 > 工具 > 开发板中选择对应的开发板

   其中，Arduino IDE下载需要1.8.x及以上版本，ESP8266扩展需要2.5.0版本

2. 手机下载[点灯科技APP](diandeng.tech/home) 

## 开发

### 生成Key

1. 手机打开`Blinker` ，点击`+`

   <img src="https://gitee.com/seasontong/image/raw/master/img/image-20220208210844667.png" alt="image-20220208210844667" style="zoom:80%;" />

2. 添加`独立设备`

   <img src="https://gitee.com/seasontong/image/raw/master/img/image-20220208211227550.png" alt="image-20220208211227550" style="zoom: 80%;" />

3. 生成`key`，并复制到剪贴板

   <img src="https://gitee.com/seasontong/image/raw/master/img/image-20220208211400716.png" alt="image-20220208211400716" style="zoom:80%;" />![image-20220208211423814](https://gitee.com/seasontong/image/raw/master/img/image-20220208211423814.png)

   <img src="https://gitee.com/seasontong/image/raw/master/img/image-20220208211449892.png" alt="image-20220208211449892" style="zoom:80%;" />