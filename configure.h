#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QObject>
#include <QFile>
#include "sql.h"

class Configure : public QObject
{
    Q_OBJECT
public:
    explicit Configure(QObject *parent = 0);
    bool ConfigureIP();
    void InitializeIP();
    bool ConfigureMac();
    SQL sql;
signals:
    
public slots:
    
};

#endif // CONFIGURE_H
