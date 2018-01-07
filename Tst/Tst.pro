QT += core sql serialport
QT -= gui

CONFIG += c++11

TARGET = Tst
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SerialComm.cpp

HEADERS += \
    CommIO.h \
    SerialComm.h
