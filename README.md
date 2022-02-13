# SmartSwitch
> 物联网DIY —— 用ESP8266和小爱同学语音实现智能开关

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

   ![image-20220213184531749](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213184531749.png)

2. 添加`独立设备`

   ![image-20220213185055804](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213185055804.png)

3. 通过**WIFI接入**，并选择**阿里云**.生成`key`，并复制到剪贴板以备用

   ![image-20220213185847867](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213185847867.png)

   
   
   

### 烧录

1. 安装 `Arduino IDE`

2. 打开`light.ino`

3. 点击开发者管理器搜索8266选择安装 (不建议选最新版本)
	<img src="https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213230854217.png" alt="image-20220213230854217" style="zoom:50%;" />
	
4. 安装后退出，烧入器插入电脑，选择端口

  ![image-20220213231132459](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213231132459.png)

  5. 配置并烧录

     以下内容需个人配置

     ```
     char auth[] = "之前获取的Key"; 
     char ssid[] = "WIF名字"
     char pswd[] = "WIFI密码";
     ```

     **注:需填2.4GHz的WIFI，不要填5GHz的WIFI**

  ### 移动端

  1. 烧入成功后，打开电灯科技APP，设备在线

     ![image-20220213232242035](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213232242035.png)

  2. 点击右上角的`+`配置按钮

     ![image-20220213232423201](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213232423201.png)

  3.  电灯与继电器接线

     ![image-20220213232725102](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213232725102.png)

     通过以上方式，就可以在APP上进行基本的控制开关了

### 语音控制

> 通过接入小爱同学实现语音控制 (小米手机)

1. 下载`米家APP`

2. 进入`其他平台设备`,找到`点灯科技`,进行绑定账号同步设备

   ![image-20220213233646273](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213233646273.png)

3. 打开`小爱APP`训练计划

   ![image-20220213233726070](https://raw.githubusercontent.com/SeasonTong/ImageHosting/main/img/image-20220213233726070.png)

   ​		以上，便实现了全部的软件控制与语音控制