#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include "CommIO.h"
#include <QString>
#include <QSerialPort>
#include <QStringList>

struct SerialProp
{
    QString mSerialName;
    qint32 mBaudRate;
    qint32 mParity;/*0-NoParity, 1-EvenParity,2-OddParity,3-SpaceParity,4-MarkParity,5-unKnow*/
    qint32 mDataBits;/*数据位*/
    qint32 mStopBits;/*Stop Bits,if the stop bits is  1.5, then set it 3*/
    qint32 mFlowControl;/*0-NoFlowControl, 1-HardwareControl, 2-SoftwareControl, 3-UnknownFlowControl*/
};


class SerialComm : public CommIO
{
public:
    SerialComm();
    ~SerialComm();
    static QStringList getAllSerials();
    CommStatus conn2Edp(void* argv);
    CommStatus reConn();
    CommStatus disConn();
    qint32 wrtData(QByteArray);
    QByteArray rcvData();

private:
    void setSerialProp(void* argv);
    CommStatus connAndInitSerial();

private:
    struct SerialArg
    {
        QSerialPort::BaudRate mBaudRate;/*波特率*/
        QString mSerialName; /*串口号*/
        QSerialPort::Parity mParity;/*校验位*/
        QSerialPort::DataBits mDataBits;
        QSerialPort::StopBits mStopBits;
        QSerialPort::FlowControl mFlowControl;/*流控制*/
    };
    SerialArg _serialArg;
    QSerialPort _serial;
};

#endif // SERIALCOMM_H
