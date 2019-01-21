#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include "tcpthread.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    QTcpServer server;
signals:
    void bytesArrived(QString,unsigned int,unsigned int);
    void bytesArrived(QString,QString,QString,QString,QString,QString,QString);
    void bytesSend(QByteArray);
public slots:
    void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVER_H
