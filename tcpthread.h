#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include "jsoncommand.h"
#include "log.h"
extern QString SensorType;
extern unsigned int BlockAddress;
extern unsigned int Command;
extern QString UserName;
extern QString Passwd;
extern QString IP;
extern QString Mask;
extern QString Getway;
extern QString Mac;
extern QString ServerIP;

class TcpThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpThread(int socketDescriptor, QObject *parent);
    void run();

    int socketDescriptor;
    QTcpSocket *tcpSocket;
    QByteArray inBlock;        //读取缓存
    int ReceiveDataHandle(QByteArray str);
    JsonCommand JsonCommandHandle;
    Log log;
    QTimer *timer;
signals:
    void error(QTcpSocket::SocketError socketError);
    void bytesArrived(QString,unsigned int,unsigned int);
    void bytesArrived(QString,QString,QString,QString,QString,QString,QString);
    void bytesSend(QByteArray);
public slots:
    void receiveData();
    void breakoff();
    void see();
};

#endif // TCPTHREAD_H
