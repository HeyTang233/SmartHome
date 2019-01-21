#ifndef TCPCLIENTTHREAD_H
#define TCPCLIENTTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include "jsoncommand.h"
#include "log.h"
#include "sql.h"

class TcpClientThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpClientThread(QObject *parent = 0);
     QTcpSocket *tcpSocket;
     JsonCommand JsonCommandHandle;
     QTimer *timer;
     void run();
     QByteArray inBlock;        //读取缓存
     Log log;
     SQL sql;
     QString ServerIP;
signals:
    
public slots:
    void SendData();
    void breakoff(QAbstractSocket::SocketError);
    void ConnectToSever();
    //void Receive();
    //void quit();

};

#endif // TCPCLIENTTHREAD_H
