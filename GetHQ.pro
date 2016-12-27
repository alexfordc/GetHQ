#-------------------------------------------------
#
# Project created by QtCreator 2016-12-17T12:46:56
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = GetHQ
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mycthostftdcmdspi.cpp \
    test.cpp \
    hello.cpp

HEADERS += \
    mycthostftdcmdspi.h \
    test.h \
    hello.h \
    ThostFtdcMdApi.h \
    ThostFtdcTraderApi.h \
    ThostFtdcUserApiDataType.h \
    ThostFtdcUserApiStruct.h



win32: LIBS += -L$$PWD/ -lthostmduserapi

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
