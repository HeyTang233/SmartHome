#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T20:32:12
#
#-------------------------------------------------

QT       += core gui sql network script

TARGET = Demo
TEMPLATE = app

LIBS     +=./lib-SmartHomeGateway-X86.so
#LIBS    +=lib-SmartHomeGateway-ARM.so

SOURCES += main.cpp\
        login.cpp \
    serialThread.cpp \
    kongzhi.cpp

HEADERS  += login.h \
    command.h \
    configure.h \
    jsoncommand.h \
    log.h \
    posix_qextserialport.h \
    qextserialbase.h \
    qextserialport.h \
    sql.h \
    tcpclientthread.h \
    tcpserver.h \
    tcpthread.h \
    VariableDefinition.h \
    serialThread.h \
    kongzhi.h

FORMS    += login.ui \
    kongzhi.ui

RESOURCES += \
    set.qrc
