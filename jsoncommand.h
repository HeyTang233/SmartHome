#ifndef JSONCOMMAND_H
#define JSONCOMMAND_H

#include <QObject>
#include <QtScript>
#include <QNetworkInterface>
#include <QFile>
#include "log.h"
#include "sql.h"

////样板间/////////环境采集数据全局变量///////////
extern QString Illumination_Value  ;               //光照度
extern QString Temp_Value  ;                       //温度值
extern QString Humidity_Value  ;                   //湿度值
extern QString CO2_Value  ;                        //CO2
extern QString AirPressure_Value ;                 //气压
extern QString Smoke_Value ;                       //烟雾
extern QString Gas_Value ;                         //燃气
extern QString PM25_Value  ;                       //PM2.5
extern volatile unsigned int StateHumanInfrared;//人体红外,1:有人。0:无人

extern int CurtainFlag,FanFlag,DigtalFlag,LampFlag,BuzzFlag;

class JsonCommand : public QObject
{
    Q_OBJECT
public:
    explicit JsonCommand(QObject *parent = 0);
    QByteArray outBlock;
    QByteArray SendDataHandle();
    unsigned int ReceiveDataHandle(QByteArray str);
    Log log;
    SQL sql;

signals:

public slots:
    
};

#endif // JSONCOMMAND_H
