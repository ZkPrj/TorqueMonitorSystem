QT += qml quick serialport sql

CONFIG += c++11

SOURCES += main.cpp \
    Comm/GlobalData.cpp \
    IO/SerialComm.cpp \
    IoMiddleWare/IcdRelover.cpp \
    IoMiddleWare/UperIcdRelover.cpp \
    Mission/TorMonitorCore.cpp \
    DspInter/TorMonitorUi.cpp \
    Db/DbOper.cpp \
    IoMiddleWare/FileLoadIcdRelover.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Comm/GlobalData.h \
    Comm/SharedDataDef.h \
    IO/CommIO.h \
    IO/SerialComm.h \
    IoMiddleWare/MiddleDataSet.h \
    IoMiddleWare/IcdRelover.h \
    IoMiddleWare/UperIcdRelover.h \
    Mission/TorMonitorCore.h \
    DspInter/TorMonitorUi.h \
    Db/DbOper.h \
    IoMiddleWare/FileLoadIcdRelover.h

