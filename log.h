#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

class Log : public QObject
{
    Q_OBJECT
public:
    explicit Log(QObject *parent = 0);
    //QFile file;
    void WriteLog(QString str);
signals:
    
public slots:
    
};

#endif // LOG_H
