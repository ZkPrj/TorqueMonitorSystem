#include "SerialComm.h"
#include <QSerialPortInfo>

SerialComm::SerialComm():CommIO()
{
    _status = CommStatusDisconn;
    _serialArg.mBaudRate = QSerialPort::Baud115200;
    _serialArg.mSerialName = "COM1";
    _serialArg.mParity = QSerialPort::NoParity;
    _serialArg.mDataBits = QSerialPort::Data8;
    _serialArg.mStopBits = QSerialPort::OneStop;
    _serialArg.mFlowControl = QSerialPort::NoFlowControl;
}

SerialComm::~SerialComm()
{
    disConn();
}

QStringList SerialComm::getAllSerials()
{
    QList<QSerialPortInfo> serialsInfo = QSerialPortInfo::availablePorts();
    QStringList serials;
    foreach(QSerialPortInfo info, serialsInfo)
    {
        serials.append(info.portName());
    }
    return serials;
}

CommIO::CommStatus SerialComm::conn2Edp(void* argv)
{
    setSerialProp(argv);
    if (_serial.isOpen())
    {
        disConn();
    }
    return connAndInitSerial();
}

CommIO::CommStatus SerialComm::reConn()
{
    if (_serial.isOpen())
    {
        disConn();
    }
    return connAndInitSerial();
}

CommIO::CommStatus SerialComm::disConn()
{
    if (_serial.isOpen())
    {
        _serial.close();
    }
    _status = CommStatusDisconn;
    return _status;
}

qint32 SerialComm::wrtData(QByteArray data)
{
    if (_serial.isOpen())
    {
        return (qint32)_serial.write(data);
    }
    _status = CommStatusDisconn;
    if (_autoReConn) reConn();
    return 0;
}

QByteArray SerialComm::rcvData()
{
    if (_serial.isOpen())
    {
        qint64 bytesNum = _serial.bytesAvailable();
        if (bytesNum > 0)
        {
            return _serial.readAll();
        }
    }
    else
    {
        _status = CommStatusDisconn;
        if (_autoReConn) reConn();
    }


    return QByteArray();
}

void SerialComm::setSerialProp(void* argv)
{
    SerialProp arg;
    if (1)
    {
        arg = *((SerialProp*)argv);
        _serialArg.mSerialName = arg.mSerialName;
        _serialArg.mBaudRate = (QSerialPort::BaudRate)arg.mBaudRate;
        /*Parity*/
        if (arg.mParity == 0) _serialArg.mParity = QSerialPort::NoParity;
        else if (arg.mParity == 1) _serialArg.mParity = QSerialPort::EvenParity;
        else if (arg.mParity == 2) _serialArg.mParity = QSerialPort::OddParity;
        else if (arg.mParity == 3) _serialArg.mParity = QSerialPort::SpaceParity;
        else if (arg.mParity == 4) _serialArg.mParity = QSerialPort::MarkParity;
        else _serialArg.mParity = QSerialPort::UnknownParity;
        /*Data Bits*/
        _serialArg.mDataBits = (QSerialPort::DataBits)arg.mDataBits;
        if (arg.mDataBits >8 ||
                arg.mDataBits < 5)
            _serialArg.mDataBits = QSerialPort::UnknownDataBits;
        /*Stop Bits*/
        if (arg.mStopBits == 1) _serialArg.mStopBits = QSerialPort::OneStop;
        else if (arg.mStopBits == 2) _serialArg.mStopBits = QSerialPort::TwoStop;
        else if (arg.mStopBits == 3) _serialArg.mStopBits = QSerialPort::OneAndHalfStop;
        else _serialArg.mStopBits = QSerialPort::UnknownStopBits;
        /*Flow Control*/
        if (arg.mFlowControl == 0) _serialArg.mFlowControl = QSerialPort::NoFlowControl;
        else if (arg.mFlowControl == 1) _serialArg.mFlowControl = QSerialPort::HardwareControl;
        else if (arg.mFlowControl == 2) _serialArg.mFlowControl = QSerialPort::SoftwareControl;
        else if (arg.mFlowControl == 3) _serialArg.mFlowControl = QSerialPort::UnknownFlowControl;
    }
}

CommIO::CommStatus SerialComm::connAndInitSerial()
{
    /*get all available serials, check weather the serial name is in the serial list,
    if not, set the status to disconn; or next step*/
    QStringList serials = getAllSerials();
    if (!serials.contains(_serialArg.mSerialName, Qt::CaseInsensitive))
        return _status;
    /*打开串口
    * 1.set serial Port
    * 2.open serial with rw access
    * 3.set baud rate/data bits/parity/stop bits/flow control
    */
    _serial.setPortName(_serialArg.mSerialName);
    if (_serial.open(QIODevice::ReadWrite))
    {
        _status = CommStatusConned;
    }
    _serial.setBaudRate(_serialArg.mBaudRate);
    _serial.setDataBits(_serialArg.mDataBits);
    _serial.setParity(_serialArg.mParity);
    _serial.setStopBits(_serialArg.mStopBits);
    _serial.setFlowControl(_serialArg.mFlowControl);
    _serial.setDataTerminalReady(true);
    return _status;
}
