#ifndef SQL_H
#define SQL_H

#include <QObject>
#include <QtSql>
#include <QDebug>
#include "log.h"

class SQL : public QObject
{
    Q_OBJECT
public:
    explicit SQL(QObject *parent = 0);
    bool SqlConnect();
    bool SqlAddRecord(QString username,QString passwd,QString ip,QString mask,QString gateway,QString mac,QString serverIp);
    int  SqlQueryCount();
    bool SqlUpdateRecord(QString username,QString passwd,QString ip,QString mask,QString gateway,QString mac,QString serverIp);
    QString SqlLastusername();
    QString SqlLastpasswd();
    QString SqlLastip();
    QString SqlFirstip();
    QString SqlLastMask();
    QString SqlLastGateway();
    QString SqlLastMac();
    QString SqlLastServerIp();
    QString SqlTimeQuery(QString key,QString tablename);
    bool SqlUpdatakey(QString tablename,QString key);
    bool SqlClearTable(QString tablename);
    QSqlTableModel* SqlOperate(QString tablename);
    float SqlQuery(QString value,QString tablename);
    int SqlCount(QString table);
    QString SqlQueryRecord(int i,QString tablename);
    Log log;
signals:
    
public slots:
    
};

#endif // SQL_H
