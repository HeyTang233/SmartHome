#include "kongzhi.h"
#include "ui_kongzhi.h"

Kongzhi::Kongzhi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kongzhi)
{
    ui->setupUi(this);
        setWindowFlags(Qt::FramelessWindowHint);
        if(!sql.SqlConnect())
            this->deleteLater();
        ui->wendulabel_2->hide();
        ui->shidulabel_4->hide();
        ui->yanwulabel_5->hide();
        ui->widget->hide();
        configboard();
        canshu();

        timer1 = new QTimer(this);
        connect(timer1,SIGNAL(timeout()),this,SLOT(ReadNodeData()));
        timer1->start(300);
        ServerIP="192.168.1.220";
//        MyTcpClient = new TcpClientThread;
//        MyTcpClient->start();
}

void Kongzhi::canshu()
{
    ReadDataNum = 0;
    temp=0;
    temp3=0;
    temp2=0;
}
void Kongzhi::update(){

//    temp=rand()%30;
//    temp2=rand()%30;
//    temp3=rand()%30;
    ui->wendulabel_2->setGeometry(ui->wendulabel_2->x(),211-temp*2,ui->wendulabel_2->width(),temp);
    ui->shidulabel_4->setGeometry(ui->shidulabel_4->x(),211-temp2*2,ui->shidulabel_4->width(),temp2);
    ui->yanwulabel_5->setGeometry(ui->yanwulabel_5->x(),211-temp3*2,ui->yanwulabel_5->width(),temp3);
}

void Kongzhi::paintEvent(QPaintEvent *){
    jiange=40;
    arge=20;
    QPainter painter(this);
    painter.setPen(QPen(Qt::red,2));
//    painter.drawLine(600,60,600,221);
    painter.drawText(55,181,"0");
    painter.drawText(100,200,"温度");
    painter.drawText(160,200,"湿度");
    painter.drawText(230,200,"燃气");
    for(int i=1;i<4;i++){
//        painter.drawLine(70,181-i*jiange,75,181-i*jiange);
        painter.drawText(50,186-i*jiange,QString::number(i*arge));
    }
}

void Kongzhi::configboard()
{
    configboardnumberInfrared=1;
    configboardnumberHumanInfrared=2;
    configboardnumberAir=3;
    configboardnumbertemp=4;
    configboardnumberHumidity=4;
    configboardnumberIllumination=5;
    configboardnumberSmoke=6;
    configboardnumberGasSensor=7;
    configboardnumberPM25=8;
    configboardnumberWarningLight=9;
    configboardnumberFan=12;
    configboardnumberCo2=13;

}

void Kongzhi::getstr(QByteArray str)
{
    if((str.length()>5) && (str.length()<300))
    {
        if(str[0]!=0 &&str[1]!=0);
        {
            DataHandle.ReceiveHandle(str);
            DataUpDate();
            temp=QVariant(QVariant(Temp_Value).toDouble()).toInt();
            temp3=QVariant(QVariant(Smoke_Value).toDouble()).toInt();
            temp2=QVariant(QVariant(Humidity_Value).toDouble()).toInt();
        }
    }
}

void Kongzhi::ReadNodeData()
{
    ReadDataNum++;
    if(ReadDataNum>28)
    {
        DataHandle.ReadNodeData(ReadDataNum);
    }else{
        timer1->stop();
    }
}

void Kongzhi::update(QString SensorType, uint Command, uint BlockAddress)
{
    if(SensorType=="Fan")
    {
        if(Command==0)
            DataHandle.SerialWriteData(configboardnumberFan,Relay4,CommandNormal,0,ALLOFF);
        else
            DataHandle.SerialWriteData(configboardnumberFan,Relay4,CommandNormal,0,ALLON);
    }else if(SensorType=="WarningLight")
    {

    }else if(SensorType=="InfraredEmit")
    {
        if(Command==0)
            DataHandle.SerialWriteData(configboardnumberInfrared,InfraredRemoteControl,CommandInfraredLaunch,0,Command);
    }else if(SensorType=="Curtain")
    {

    }else if(SensorType=="Lamp")
    {
        if(Command==0)
            DataHandle.SerialWriteData(configboardnumberLamp,Relay4,CommandNormal,0,ALLOFF);
        else
            DataHandle.SerialWriteData(configboardnumberLamp,Relay4,CommandNormal,0,ALLON);
    }
}

void Kongzhi::config(QString UserName, QString Passwd, QString IP, QString Mask, QString Gateway, QString Mac, QString ServerIP)
{
    if(!sql.SqlConnect()==1)
    {
        if(!sql.SqlAddRecord(UserName,Passwd,IP,Mask,Gateway,Mac,ServerIP))
            log.WriteLog("Add record faild");
    }else{
        if(!sql.SqlUpdateRecord(UserName,Passwd,IP,Mask,Gateway,Mac,ServerIP))
            log.WriteLog("Update record faild");
    }
    if(!confg.ConfigureIP())
        log.WriteLog("Config IP faild");
}

Kongzhi::~Kongzhi()
{
    delete ui;
}
void Kongzhi::DataUpDate()
{
    ui->wd->setText(Temp_Value+"℃");
    ui->sd->setText(Humidity_Value+"%");
    ui->gz->setText(Illumination_Value+"Lux");
    ui->rq->setText(Gas_Value+"PPm");
    ui->co2->setText(CO2_Value+"PPm");
    ui->pm25->setText(PM25_Value+"μg/m³");
    ui->qy->setText(AirPressure_Value+"Pa");
    ui->yw->setText(Smoke_Value+"PPm");
    if(StateHumanInfrared==1)
        ui->rthw->setText("有人");
    else
        ui->rthw->setText("没人");
}

void Kongzhi::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="打开串口")
    {
        DataHandle.SerialOpen();
        connect(&DataHandle,SIGNAL(serialFinish(QByteArray)),this,SLOT(getstr(QByteArray)));
        ui->pushButton_2->setText("关闭串口");
    }else{
        ui->pushButton_2->setText("打开串口");
//        DataHandle.thread()->wait();
    }
}

void Kongzhi::on_server_clicked()
{
    MyTcpClient = new TcpClientThread;
    MyTcpClient->start();
}

void Kongzhi::on_pushButton_3_clicked()
{
    this->close();
}

void Kongzhi::on_fashe_clicked()
{
    if(ui->hongwai->text()=="1")
        DataHandle.SerialWriteData(configboardnumberInfrared,InfraredRemoteControl,CommandInfraredLaunch,0,0x01);
    else if(ui->hongwai->text()=="2")
        DataHandle.SerialWriteData(configboardnumberInfrared,InfraredRemoteControl,CommandInfraredLaunch,0,0x02);
    else if(ui->hongwai->text()=="3")
        DataHandle.SerialWriteData(configboardnumberInfrared,InfraredRemoteControl,CommandInfraredLaunch,0,0x03);
}

void Kongzhi::on_fengshan_clicked()
{
    if(ui->fengshan->text()=="打开风扇")
    {
        DataHandle.SerialWriteData(configboardnumberFan,Relay4,CommandNormal,0,ALLOFF);
        ui->fengshan->setText("关闭风扇");
    }else{
        DataHandle.SerialWriteData(configboardnumberFan,Relay4,CommandNormal,0,ALLON);
        ui->fengshan->setText("打开风扇");
    }
}

void Kongzhi::on_shedeng_clicked()
{
    if(ui->shedeng->text()=="打开射灯")
    {
        ui->shedeng->setText("关闭射灯");
        DataHandle.SerialWriteData(configboardnumberLamp,Relay4,CommandNormal,0,ALLON);
    }else{
        DataHandle.SerialWriteData(configboardnumberLamp,Relay4,CommandNormal,0,ALLOFF);
        ui->shedeng->setText("打开射灯");
     }
}

void Kongzhi::on_bjd_clicked()
{
    if(ui->bjd->text()=="打开报警灯")
    {
        DataHandle.SerialWriteData(configboardnumberWarningLight,Relay4,CommandNormal,0,ALLON);
        ui->bjd->setText("关闭报警灯");
    }else{
        DataHandle.SerialWriteData(configboardnumberWarningLight,Relay4,CommandNormal,0,ALLOFF);
        ui->bjd->setText("打开报警灯");
    }
}

void Kongzhi::on_tubiao_clicked()
{
    if(ui->tubiao->text()=="打开图表"){
    ui->wendulabel_2->show();
    ui->shidulabel_4->show();
    ui->yanwulabel_5->show();
    ui->widget->show();
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);
    ui->tubiao->setText("关闭图表");
    }else{
        ui->tubiao->setText("打开图表");
        timer->stop();
        ui->wendulabel_2->hide();
        ui->shidulabel_4->hide();
        ui->yanwulabel_5->hide();
        ui->widget->hide();
    }

}
