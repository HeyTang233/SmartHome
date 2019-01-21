#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H
#include <posix_qextserialport.h>
#include <QThread>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread();
    Posix_QextSerialPort *myCom;
signals:
    void serialFinished(QByteArray str);
public slots:
private:
    void run();
};

#endif // SERIALTHREAD_H
