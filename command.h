#ifndef COMMAND_H
#define COMMAND_H

#include <QTextCodec>
#include <QByteArray>
#include "QDebug"
#include <qfile.h>
#include "serialThread.h"
#include <unistd.h>
#include <signal.h>
#include <QProcess>
#include <string.h>
#include <qthread.h>
#include "qobject.h"
#include "log.h"
#include "sql.h"
#include "VariableDefinition.h"

class command:public QObject
{
    Q_OBJECT
public:
    explicit command();                               //构造函数
    SerialThread *myserial;
    void SerialOpen(void);                            //打开串口
    int SerialWriteData(unsigned int boardnumber,unsigned int SensorType_send,unsigned int CommandType,unsigned int BlockAddress, int Send_Data);//命令发送
    void ReceiveHandle(QByteArray str);            //接受帧处理
    void ReadNodeData(unsigned char boardnum);      //读取节点信息
protected:
    void receive(unsigned char b[]);                     //对参数进行处理
    unsigned char DataHandle(unsigned char a[]);      //数据处理函数
    unsigned char DataHandleCoorAddr(unsigned char a[]);  //处理协调器中节点短地址
    void DataHandleNodeInfor(unsigned char a[]); //处理协调器中节点信息
    float DataConversionHandle();                     //数据转换处理函数
    QByteArray    SendData(unsigned int boardnumber,unsigned int SensorType_send,unsigned int CommandType,unsigned int BlockAddress,unsigned int Send_Data);  //发送函数处
    void SendRunningState();  //看门狗溢出发送
    void ReadShoraddress();
    void ReadNodeInfor(unsigned char boardnum,unsigned char commandnum);
    unsigned char AutoUploadDataHandle(unsigned char a[]);
    unsigned char ReturnErrorHandle(unsigned char a[]);
    unsigned char GetState();
    void DataStorage();
    Log log;
    SQL sql;
private slots:
    void DataForwar(QByteArray str);                  //数据转发
signals:
    void serialFinish(QByteArray str);
    void bodyInfrared(unsigned int boardNum,unsigned int Command);
    void modeSignal(unsigned int boardNum,unsigned int Command);
    void s_humidity(unsigned int boardNum,unsigned int Command);
    void s_illumination(unsigned int boardNum,unsigned int Command);
    void s_temperature(unsigned int boardNum,unsigned int Command);
    void s_Co2(unsigned int boardNum,unsigned int Command);
    void s_waterLevel(unsigned int boardNum,unsigned int Command);
    void s_O2(unsigned int boardNum,unsigned int Command);
    void backState();
    //void s_lampIllumination(unsigned int boardNum, unsigned int Command);
};
#endif // COMMAND_H
