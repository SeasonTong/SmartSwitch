#define BLINKER_WIFI
#define BLINKER_MIOT_LIGHT//小爱同学

#include <Blinker.h>

char auth[] = "f00c2c8069d2"; //Key
char ssid[] = "H3C_3AAF1E";
char pswd[] = "trj19611120";

bool wsState;
uint8_t wsMode = BLINKER_CMD_MIOT_DAY;

BlinkerButton ButtonAll("btn-lightAll"); //定义按钮数据
BlinkerButton ButtonR("btn-lightR");     //定义按钮数据
BlinkerButton ButtonG("btn-lightG");     //定义按钮数据
BlinkerButton ButtonB("btn-lightB");     //定义按钮数据

BlinkerButton ButtonOffAll("btn-unlightAll"); 
BlinkerButton ButtonOffR("btn-unlightR"); 
BlinkerButton ButtonOffG("btn-unlightG"); 
BlinkerButton ButtonOffB("btn-unlightB"); 

BlinkerButton Button3("btn-aaa");  

bool oState = false;
int counter = 0;


void miotPowerState(const String & state)
{
    BLINKER_LOG("need set power state: ", state);

    if (state == BLINKER_CMD_ON) {     //小爱同学控制开命令
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(0, LOW);

        BlinkerMIOT.powerState("on");

        BlinkerMIOT.print();

        oState = true;
    }
    else if (state == BLINKER_CMD_OFF) {   //小爱同学控制关命令
        digitalWrite(5,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(0,HIGH);

        BlinkerMIOT.powerState("off");

        BlinkerMIOT.print();

        oState = false;
    }
}

void miotMode(uint8_t mode)
{
    BLINKER_LOG("need set mode: ", mode);

    if (mode == BLINKER_CMD_MIOT_DAY) { //红色
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(0, HIGH);
    }
    
    else if (mode == BLINKER_CMD_MIOT_NIGHT) { //绿色
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(0, HIGH);
        // Your mode function
    }
    
    else if (mode == BLINKER_CMD_MIOT_COLOR) { //蓝色
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(0, LOW);
    }
    
    else if (mode == BLINKER_CMD_MIOT_WARMTH) { //黄色
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(0, HIGH);
    }
    
    else if (mode == BLINKER_CMD_MIOT_TV) { //紫色
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(0, LOW);
    }
    
    else if (mode == BLINKER_CMD_MIOT_READING) { //青色
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(0, LOW);
    }
    
    else if (mode == BLINKER_CMD_MIOT_COMPUTER) {
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(0, LOW);
    }

    wsMode = mode;

    BlinkerMIOT.mode(mode);
    BlinkerMIOT.print();
}


void miotQuery(int32_t queryCode)      //小爱同学控制
{
    BLINKER_LOG("MIOT Query codes: ", queryCode);

    switch (queryCode)
    {
        case BLINKER_CMD_QUERY_ALL_NUMBER :
            BLINKER_LOG("MIOT Query All");
            BlinkerMIOT.powerState(oState ? "on" : "off");
            BlinkerMIOT.print();
            break;
        case BLINKER_CMD_QUERY_POWERSTATE_NUMBER :
            BLINKER_LOG("MIOT Query Power State");
            BlinkerMIOT.powerState(oState ? "on" : "off");
            BlinkerMIOT.print();
            break;
        default :
            BlinkerMIOT.powerState(oState ? "on" : "off");
            BlinkerMIOT.print();
            break;
    }
}

void dataRead(const String & data)      // 如果未绑定的组件被触发，则会执行其中内容
{
    BLINKER_LOG("Blinker readString: ", data);

    Blinker.vibrate();
    
    uint32_t BlinkerTime = millis();
    
    Blinker.print("millis", BlinkerTime);
}

void buttonAll_callback(const String & state)     //点灯app内控制按键触发
{
    
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(0,LOW);
    BLINKER_LOG("get button state:on", state);

}

void buttonR_callback(const String & state)     //点灯app内控制按键触发
{
    
    digitalWrite(5,LOW);
    BLINKER_LOG("get button state:on", state);
    
}

void buttonG_callback(const String & state)     //点灯app内控制按键触发
{
    
    digitalWrite(4,LOW);
    BLINKER_LOG("get button state:on", state);

}

void buttonB_callback(const String & state)     //点灯app内控制按键触发
{
    
    digitalWrite(0,LOW);
    BLINKER_LOG("get button state:on", state);

}

void buttonOffAll_callback(const String & state)     //点灯app内控制按键触发
{
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(0,HIGH);
    BLINKER_LOG("get button state:off", state);
}

void buttonOffR_callback(const String & state)     //点灯app内控制按键触发
{
    digitalWrite(5,HIGH);
    BLINKER_LOG("get button state:off", state);
}

void buttonOffG_callback(const String & state)     //点灯app内控制按键触发
{
    digitalWrite(4,HIGH);
    BLINKER_LOG("get button state:off", state);
}

void buttonOffB_callback(const String & state)     //点灯app内控制按键触发
{
    digitalWrite(0,HIGH);
    BLINKER_LOG("get button state:off", state);
}


void button3_callback(const String & state)     //点灯app内控制按键触发
{  
  
    BLINKER_LOG("get button state:on", state);
     Blinker.print(state);
    if(state=="on"){
    digitalWrite(5,LOW);
   // Button3.print("on");
     }else if(state =="off"){
            digitalWrite(5,HIGH);
        
    //        Button3.print("off");
    }
}

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);

    pinMode(5, OUTPUT);              //定义io口为输出
    pinMode(4, OUTPUT);              //定义io口为输出
    pinMode(0, OUTPUT);              //定义io口为输出
    
    digitalWrite(5, HIGH);           //定义io默认为高电平
    digitalWrite(4, HIGH);           //定义io默认为高电平
    digitalWrite(0, HIGH);           //定义io默认为高电平
    
    wsState = true;
    
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    
    BlinkerMIOT.attachPowerState(miotPowerState);
    BlinkerMIOT.attachMode(miotMode);
    BlinkerMIOT.attachQuery(miotQuery);
    
    ButtonAll.attach(buttonAll_callback); 
    ButtonR.attach(buttonR_callback); 
    ButtonG.attach(buttonG_callback); 
    ButtonB.attach(buttonB_callback); 
;    
    ButtonOffAll.attach(buttonOffAll_callback); 
    ButtonOffR.attach(buttonOffR_callback); 
    ButtonOffG.attach(buttonOffG_callback); 
    ButtonOffB.attach(buttonOffB_callback); 
        
    Button3.attach(button3_callback);   
}

void loop()
{
    Blinker.run();
}
