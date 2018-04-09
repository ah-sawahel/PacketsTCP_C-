#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T16:08:33
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cleint
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    clienttcp.cpp \
    ../src/TCPClient.cpp \
    ../src/TCPServer.cpp \
    singleton.cpp \
    qcustomplot.cpp

HEADERS  += client.h \
    clienttcp.h \
    singleton.h \
    qcustomplot.h

FORMS    += client.ui

CONFIG += c++11
CONFIG += lstdc++fs
