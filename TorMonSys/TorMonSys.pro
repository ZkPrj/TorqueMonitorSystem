QT += qml quick serialport sql

CONFIG += c++11

SOURCES += main.cpp \
    CommLayer/SerialComm.cpp \
    DataWrapLayer/DataWraper.cpp \
    MissionProcLayer/MissionCore.cpp \
    MissionProcLayer/GlobalData.cpp \
    MissionProcLayer/DbOper.cpp \
    UiLayer/TorSysUiLayer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    CommLayer/CommIO.h \
    CommLayer/SerialComm.h \
    DataWrapLayer/DataWraper.h \
    DataWrapLayer/DataSet.h \
    MissionProcLayer/MissionCore.h \
    MissionProcLayer/GlobalData.h \
    MissionProcLayer/DbOper.h \
    UiLayer/TorSysUiLayer.h
