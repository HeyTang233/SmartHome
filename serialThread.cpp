#include "serialThread.h"

SerialThread::SerialThread()
{
    struct PortSettings ttySetting;
    myCom = new Posix_QextSerialPort("/dev/ttyUSB0",QextSerialBase::Polling);
    myCom->open(QIODevice::ReadWrite);
    myCom->setBaudRate(BAUD9600);
    myCom->setDataBits(DATA_8);
    myCom->setFlowControl(FLOW_OFF);
    myCom->setParity(PAR_EVEN);
    myCom->setStopBits(STOP_1);
    myCom->setTimeout(70);
}
void SerialThread::run()
{
    while (1) {
        int a;
        a=myCom->bytesAvailable();
        msleep(40);
        if(a==myCom->bytesAvailable())
        {
            QByteArray temp = myCom->readAll();
            emit this->serialFinished(temp);
        }
    }
}
