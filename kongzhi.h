#ifndef KONGZHI_H
#define KONGZHI_H
#include "command.h"
#include "configure.h"
#include "sql.h"
#include "log.h"
#include "tcpclientthread.h"
#include "tcpserver.h"
#include <QTimer>
#include <QTcpSocket>
#include <QDialog>
#include <QPainter>
namespace Ui {
class Kongzhi;
}
extern QString ServerIP  ;
extern QString Illumination_Value  ;               //光照度
extern QString Temp_Value  ;                       //温度值
extern QString Humidity_Value  ;                   //湿度值
extern QString CO2_Value  ;                        //CO2
extern QString AirPressure_Value ;                 //气压
extern QString Smoke_Value ;                       //烟雾
extern QString Gas_Value ;                         //燃气
extern QString PM25_Value  ;                       //PM2.5

extern volatile unsigned int StateHumanInfrared;//人体红外,1:有人。0:无人
extern volatile unsigned int configboardnumbertemp;
extern volatile unsigned int configboardnumberIllumination;
extern volatile unsigned int configboardnumberHumidity;
extern volatile unsigned int configboardnumberAir;
extern volatile unsigned int configboardnumberCo2;
extern volatile unsigned int configboardnumberGasSensor;
extern volatile unsigned int configboardnumberPM25;
extern volatile unsigned int configboardnumberSmoke;
extern volatile unsigned int configboardnumberHumanInfrared;
extern volatile unsigned int configboardnumberFan;
extern volatile unsigned int configboardnumberInfrared;
extern volatile unsigned int configboardnumberLamp;
extern volatile unsigned int configboardnumberWarningLight;
extern volatile unsigned int configboardnumberCurtain;
//extern volatile unsigned int configboardnumber
//extern volatile unsigned int configboardnumber
class Kongzhi : public QDialog
{
    Q_OBJECT
    
public:
    explicit Kongzhi(QWidget *parent = 0);
    ~Kongzhi();
    void paintEvent(QPaintEvent *);
    int jiange;
    int arge;
    QTimer *timer;
    int temp,temp2,temp3;
    TcpClientThread *MyTcpClient;
    TcpServer Server;
    QTimer *timer1;
    QTimer *timer2;
    int readflag;
    int ReadDataNum;
    void DataUpDate();
private:
    Ui::Kongzhi *ui;
    command DataHandle;
    SQL sql;
    Log log;
    Configure confg;
private slots:
    void ReadNodeData();
    void getstr(QByteArray str);
    void canshu();
    void configboard();
    void config(QString UserName,QString Passwd,QString IP,QString Mask,QString Gateway,QString Mac,QString ServerIP);
    void update(QString SensorType,uint Command,uint BlockAddress);
    void on_pushButton_2_clicked();
    void on_server_clicked();
    void on_pushButton_3_clicked();
    void on_fashe_clicked();
    void on_fengshan_clicked();
    void on_shedeng_clicked();
    void on_bjd_clicked();
    void update();
    void on_tubiao_clicked();
};

#endif // KONGZHI_H
