#ifndef VARIABLEDEFINITION_H
#define VARIABLEDEFINITION_H

/******************************串口通信部分要用到的定义**************************************************/
//传感器的个数定义，在使用的时候只要将下面的相对应的与SensorType相与看等不等于本身就可以判断是什么传感器了
#define  TempDS18B20          		0X01		 //DS12B20的温度
#define  TempSHT10    		  		0X08		 //SHT10的温度
#define  HumiditySHT10        		0X09		 //SHT10的湿度
#define  OnboardLight		  		0X10         //板载光照
#define  Photoresistor        		0X18         //光敏电阻
#define  RelaySingle                0X20         //单路继电器
#define  SmokeSensor 		  		0X28         //烟雾传感器
#define  Co2Sensor                  0X29         //Co2传感器
#define  GasSensor			  		0X30	     //煤气传感器
#define  RaindropSensor       		0X38         //雨滴传感器
#define  ElectricCurtains			0X40         //电动窗帘
#define  DigitalTube		  		0X48         //数码管
#define  InfraredRemoteControl		0X50     	 //红外遥控
#define  GanHuangGuan	     	    0X58         //干黄管
#define  UltrasonicSensor			0X60         //超声波传感器
#define  Shock                      0X68         //震动
#define  Noise                      0X70	     //噪声
#define  BodyInfraredSensor		    0X78         //人体红外传感器
#define  DCMotor					0X80         //直流电机
#define  StepMotor			        0X88         //步进电机
#define  TTL_IO                     0X90         //TTL_IO
#define  Output                     0X98         //(2路节点+2路电平)输出
#define  GasPressureSensor		    0XA0         //气体压力传感器
#define  DigitalAccelerometer		0XA8         //数字加速度
#define  ElectronicCompass		    0XB0         //电子罗盘
#define  InfraredTemp               0XB8         //红外温度
#define  ElectronicScales		    0XC0         //电子称
#define  ExternTemp                 0XC8         //外部温度
#define  ExternHumidity 			0XC9         //外部湿度
#define  ExternIllumination         0XD0         //外部光照
#define  BatteryVoltage			    0XD8         //电池电压
#define  Relay4                     0XE0         //4路继电器
#define  NoExternBoard     		    0XE8         //无外接板
#define  Buzz                       0XF8         //蜂鸣器
#define  RFID_TAG_15693             0XD0
#define  RFID_DATA_15693            0XD1
#define  RFID_TAG_14433A            0XD2
#define  RFID_DATA_14433A           0XD3
#define  RFID                       0XD0
#define  PMSensor                   0XF0
#define  WeatherSensor              0XA0

//Command Type
/**正常的命令类型*/
#define  CommandNormal               0X00
/**红外学习*/
#define  CommandInfraredLearn        0X01
/**红外发射*/
#define  CommandInfraredLaunch       0X02
/*步进电机控制*/
#define  CommandStepMotor            0X03
//RFID
#define  RFID_Read_Data              0X05
#define  RFID_Read_Tag               0X04
#define  RFID_Write_Data             0x06
#define  RFID_Open_Door              0x07
//继电器控制
#define  ALLON                       0X0F
#define  ALLOFF                      0X00
#define  RelayP1                     0X01
#define  RelayP2                     0X02
#define  RelayP3                     0X04
#define  RelayP4                     0X08

//控制命令定义
#define NoBlockAddress               0
#define RelayOff                     0x00
#define LampOn                       0x0f
#define WarningLightOn               0x0f
#define FanOn                        0x0f
#define CurtainOn                    0x02
#define CurtainStop                  0x01
#define CurtainOff                   0x04
/*************************************************************************************************/

/*********************************与服务器通信部分定义********************************************/
/***************************传感器控制***************************************************/
#define FAN             "Fan"               //风扇
#define LAMP            "Lamp"              //射灯
#define WARNINGLIGHT    "WarningLight"      //报警灯
#define CURTAIN         "Curtain"           //窗帘
#define INFRAREDEMIT    "InfraredEmit"      //红外发射
#define DOORCONTROL     "DoorControl"       //门禁控制
#define RFIDOPENDOOR    "RFID_Open_Door"    //打开门禁
/****************************************************************************************/

/***************************情景模式控制定义*********************************************/
#define ILL_MODE         "Illumination_mode"    //光照模式
#define TEMP_MODE        "Temperature_mode"     //温度模式
#define SEC_MODE         "Security_mode"        //安防模式
#define HOME_MODE        "Home_mode"            //离家模式
#define SLEEP_MODE       "Sleep_mode"           //睡眠模式
#define UP_MODE          "Wake_up_mode"         //起床模式
/****************************************************************************************/
/*************************************************************************************************/
#endif // VARIABLEDEFINITION_H
