#include "DataWraper.h"
#include <QtEndian>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include "MissionProcLayer/GlobalData.h"
#include <QtGlobal>

#pragma pack(1)
typedef union
{
    quint8 data[259];
    struct
    {
        quint8 mHead;
        quint8 mType;
        quint8 mReverse[256];
        quint8 mCkcSum;
    }connData;
    struct
    {
        quint8 mHead;
        quint8 mType;
        quint16 mCurFileNo;
        quint32 mCurFileLen;
        quint16 mFileNum;
        quint8 mFileName[12];
        quint8 mReverse[236];
        quint8 mCkcSum;
    }fileList;
}LowerInRawDataStruct;

typedef union
{
    quint8 data[16];
    struct
    {
        quint8 mHead;
        quint8 mType;
        quint8 mData[13];
        quint8 mCkcSum;
    }normalData;
}LowerOutRawDataStruct;

#pragma pack()

DataWraper::DataWraper(QObject *parent):QObject(parent)
{
    _uperStatus = ConnStatusUnKnown;
    _lowerStatus = ConnStatusUnKnown;
    _uperTransceInData = {0};
    _uperTransceOutData = {0};
    _lowerTransceInData.mFileListValid = false;
    _lowerTransceInData.mFileContenValid = false;
    _lowerTransceInData.mFileCrcValid = false;
    _lowerTransceInData.mDelFlagValid = false;
    _lowerTransceOutData.mReqFilesListValid = false;
    _lowerTransceOutData.mFileNameValid = false;
    _lowerTransceOutData.mDelFileNameValid = false;
    _uperBuf.clear();;
    _uperCandiList.clear();;
    _uperConnCount = 0;
    _uperIo = 0;
    _lowerIo = 0;
    _lowerConnCount = 0;
    _updateCycle = 10;  /*10ms 更新一次*/
    startTimer(_updateCycle);/*设置基准定时器，每10ms运行一次*/
}


InUperTransceiverDataSet DataWraper::getUperData()
{
    InUperTransceiverDataSet data;
    _uperInRwLock.lockForRead();
    data = _uperTransceInData;
    memset(&_uperTransceInData, 0, sizeof(_uperTransceInData));
    _uperInRwLock.unlock();
    return data;
}

void DataWraper::conn2UperTranser()
{
    /*如果当前处于连接中或者已经连接上，则不做任何处理*/
    if (_uperStatus == ConnStatusConnecting||
            _uperStatus == ConnStatusConnOk)
        return ;
    _uperCandiList.clear();
    /*1.首先获取所有串口*/
    QStringList serialNames = SerialComm::getAllSerials();
    /*2.依次打开每个串口，并判断在1s内是否能收到CONN命令*/
    for (QString serial: serialNames)
    {
        SerialComm* serialComm = new SerialComm;
        /*设置串口属性*/
        SerialProp serialProp;
        serialProp.mSerialName = serial;
        serialProp.mBaudRate = GlobalData::cfgCtx.mUpTransPort;
        serialProp.mDataBits = GlobalData::cfgCtx.mUpTransDataBits;
        serialProp.mFlowControl = GlobalData::cfgCtx.mUpTransFlowCtl;
        serialProp.mParity = GlobalData::cfgCtx.mUpTransParity;
        serialProp.mStopBits = GlobalData::cfgCtx.mUpTransStopBits;
        CommIO::CommStatus status = serialComm->conn2Edp(&serialProp);
        /*3.a 如果打开串口失败,则删除该serialComm*/
        if(status != CommIO::CommStatusConned)
        {
            serialComm->disConn();
            delete serialComm;
            serialComm= 0;
            continue;
        }
        _uperCandiList.append(serialComm);
    }
    if (_uperCandiList.length()>0)
    {
        /*如果候选列表>0,则设置连接计数为100，开始连接计数*/
        _uperConnCount = 100;
        _uperStatus = ConnStatusConnecting;
    }
}

void DataWraper::conn2LowerTranser()
{
    /*如果当前处于连接中或者已经连接上，则不做任何处理*/
    if (_lowerStatus == ConnStatusConnecting||
            _uperStatus == ConnStatusConnOk)
        return ;
    _lowerCandiList.clear();
    /*1.首先获取所有串口*/
    QStringList serialNames = SerialComm::getAllSerials();
    /*2.依次打开每个串口,并判断在1s内是否收到CONN命令*/
    for (QString serial: serialNames)
    {
        SerialComm* serialComm = new SerialComm;
        /*设置串口属性*/
        SerialProp serialProp;
        serialProp.mSerialName = serial;
        serialProp.mBaudRate = GlobalData::cfgCtx.mLowerTransPort;
        serialProp.mDataBits = GlobalData::cfgCtx.mLowerTransDataBits;
        serialProp.mFlowControl = GlobalData::cfgCtx.mLowerTransFlowCtl;
        serialProp.mParity = GlobalData::cfgCtx.mLowerTransParity;
        serialProp.mStopBits = GlobalData::cfgCtx.mLowerTransStopBits;
        CommIO::CommStatus status = serialComm->conn2Edp(&serialProp);
        /*3.如果打开串口失败，则删除该serialComm*/
        if (status != CommIO::CommStatusConned)
        {
            serialComm->disConn();
            delete serialComm;
            serialComm = 0;
            continue;
        }
        /*往串口发送两个字节*/
        LowerOutRawDataStruct data;
        memset(&data, 0, sizeof(data));
        data.normalData.mHead = 0x55;
        data.normalData.mType = 0;
        data.normalData.mCkcSum = 0x55;

        serialComm->wrtData(QByteArray((char*)&data, sizeof(data)));
        _lowerCandiList.append(serialComm);
    }
    if (_lowerCandiList.length() > 0)
    {
        /*如果候选列表>0,则设置连接计数为100，开始连接计数*/
        _lowerConnCount = 100;
        _lowerStatus = ConnStatusConnecting;
    }
}

ConnStatusType DataWraper::getUperStatus()
{
    return _uperStatus;
}

ConnStatusType DataWraper::getLowerStatus()
{
    return _lowerStatus;
}

void DataWraper::setUperData(UperCmdType type, int payLoad)
{
    _uperOutRwLock.lockForWrite();
    switch(type)
    {
    case UperCmdTypeCommType:
        _uperTransceOutData.mCommType = payLoad;
        _uperTransceOutData.mCommTypeUnpdateNum = 0;
        _uperTransceOutData.mCommTypeValid = true;
        break;
    case UperCmdTypeCurTorPipe:
        break;
    case UperCmdTypeCurStatus:
        break;
    case UperCmdTypeGetCtlTor:
        _uperTransceOutData.mCtlTor = payLoad;
        _uperTransceOutData.mCtlTorUnUpdateNum = 0;
        _uperTransceOutData.mCtlTorValid = true;
        break;
    case UperCmdTypeGetDrawTor:
        _uperTransceOutData.mDrawTor = payLoad;
        _uperTransceOutData.mDrawTorUnUpdateNum = 0;
        _uperTransceOutData.mDrawTorValid = true;
        break;
    case UperCmdTypeGetCycleMax:
        _uperTransceOutData.mCycleMax = payLoad;
        _uperTransceOutData.mCycleMaxUnUpdateNum = 0;
        _uperTransceOutData.mCycleMaxValid = true;
        break;
    case UperCmdTypeGetDateTime:
        _uperTransceOutData.mDateTime = payLoad;
        _uperTransceOutData.mDateTimeUnUpdateNum = 0;
        _uperTransceOutData.mDateTimeValid = true;
        break;
    case UperCmdTypeGetPipeNo:
        _uperTransceOutData.mPipeNo = payLoad;
        _uperTransceOutData.mPipeNoUnUpdateNum = 0;
        _uperTransceOutData.mPipeNoValid = true;
        break;
    case UperCmdTypeGetCorrFactor:
        _uperTransceOutData.mCorrFactor = payLoad;
        _uperTransceOutData.mCorrFactorUnUpdateNum = 0;
        _uperTransceOutData.mCorrFactorValid = true;
        break;
    case UperCmdTypeGetDelayTime:
        _uperTransceOutData.mDelayTime = payLoad;
        _uperTransceOutData.mDelayTimeUnUpdateNum = 0;
        _uperTransceOutData.mDelayTimeValid = true;
        break;
    case UperCmdTypeGetWellNo:
        _uperTransceOutData.mWellNo = payLoad;
        _uperTransceOutData.mWellNoUnUpdateNum = 0;
        _uperTransceOutData.mWellNoValid = true;
        break;
    case UperCmdTypeGetAddNo:
        _uperTransceOutData.mAddID = payLoad;
        _uperTransceOutData.mAddIDUnUpdateNum = 0;
        _uperTransceOutData.mAddIDValid = true;
        break;
    case UperCmdTypeSetCtlTor:
        _uperTransceOutData.mEchoCtlTor = payLoad;
        _uperTransceOutData.mEchoCtlTorUnUpdateNum = 0;
        _uperTransceOutData.mEchoCtlTorValid = true;
        break;
    case UperCmdTypeSetDrawTor:
        _uperTransceOutData.mEchoDrawTor = payLoad;
        _uperTransceOutData.mEchoDrawTorUnUpdateNum = 0;
        _uperTransceOutData.mEchoDrawTorValid = true;
        break;
    case UperCmdTypeSetCycleMax:
        _uperTransceOutData.mEchoCycleMax = payLoad;
        _uperTransceOutData.mEchoCycleMaxUnUpdateNum = 0;
        _uperTransceOutData.mEchoCycleMaxValid = true;
        break;
    case UperCmdTypeSetDateTime:
        _uperTransceOutData.mEchoDateTime = payLoad;
        _uperTransceOutData.mEchoDateTimeUnUpdateNum = 0;
        _uperTransceOutData.mEchoDateTimeValid = true;
        break;
    case UperCmdTypeSetPipeNo:
        _uperTransceOutData.mEchoPipeNo = payLoad;
        _uperTransceOutData.mEchoPipeNoUnUpdateNum = 0;
        _uperTransceOutData.mEchoPipeNoValid = true;
        break;
    case UperCmdTypeSetCorrFactor:
        _uperTransceOutData.mEchoCorrFactor = payLoad;
        _uperTransceOutData.mEchoCorrFactorUnUpdateNum = 0;
        _uperTransceOutData.mEchoCorrFactorValid = true;
        break;
    case UperCmdTypeSetDelayTime:
        _uperTransceOutData.mEchoDelayTime = payLoad;
        _uperTransceOutData.mEchoDelaytTimeUnUpdateNum = 0;
        _uperTransceOutData.mEchoDelayTimeValid = true;
        break;
    case UperCmdTypeSetWellNo:
        _uperTransceOutData.mEchoWellNo = payLoad;
        _uperTransceOutData.mEchoWellUnUpdateNum = 0;
        _uperTransceOutData.mEchoWellNoValid = true;
        break;
    case UperCmdTypeSetAddNo:
        _uperTransceOutData.mEchoAddID = payLoad;
        _uperTransceOutData.mEchoAddIDUnUpdateNum = 0;
        _uperTransceOutData.mEchoAddIDValid = true;
        break;
    }

    _uperOutRwLock.unlock();
}

void DataWraper::setLowerData(LowerCmdType type, QByteArray payLoad)
{
    _lowerOutRwLock.lockForWrite();
    switch(type)
    {
    case LowerCmdTypeFileList:
        _lowerTransceOutData.mReqFilesListValid = true;
        _lowerTransceOutData.mReqFilesList = true;
        _lowerTransceOutData.mReqFilesListUnUpdateNum = 0;
        break;
    case LowerCmdTypeFileContent:
        _lowerTransceOutData.mFileNameValid = true;
        _lowerTransceOutData.mFileName = payLoad;
        _lowerTransceOutData.mFileNameUnUpdateNum = 0;
        break;
    case LowerCmdTypeDelFlag:
        _lowerTransceOutData.mDelFileNameValid = true;
        _lowerTransceOutData.mDelFileName = payLoad;
        _lowerTransceOutData.mFileNameUnUpdateNum = 0;
        break;
    default:
        break;
    }

    _lowerOutRwLock.unlock();
}

void DataWraper::timerEvent(QTimerEvent *event)
{
    /*该事件频率为100HZ - 10ms*/
    /*底层原始数据收发频率为 50HZ - 20ms*/
    /*中间层数据解析频率为20HZ - 50ms*/
    static int i = 0;
    i = (i + 1)%10;
    if (i%2 == 0)/*原始数据收发*/
    {
        //qDebug()<<"Begin getRawData";
        getRawData();
        //qDebug()<<"Begin wrapAndSndData";
        wrapAndSndData();
    }
    if (i % 5 == 0)/*中间层数据解析*/
    {
        //qDebug()<<"Begin updataInputData";
        updataInputData();
        //fetchLowerFrames();
    }
    /*更新通信状态*/
    //qDebug()<<"Begin monitorConnStatus";
    monitorConnStatus();
    /*处理连接事务*/
    //qDebug()<<"Begin handleUperConn";
    handleUperConn();
    //qDebug()<<"Begin handleLowerConn";
    handleLowerConn();
}

void DataWraper::getRawData()
{
    /*接收上位机收发器的数据*/
    if (_uperIo != 0&&
            _uperIo->getCurStatus() == CommIO::CommStatusConned)
    {
        QByteArray rcvData = _uperIo->rcvData();
        if (rcvData.length() > 0)
        {
            _uperRawDataLock.lockForWrite();
            _uperBuf.append(rcvData);
            _uperRawDataLock.unlock();
        }
    }
    /*接收下位机收发器的数据*/
    if (_lowerIo != 0&&
            _lowerIo->getCurStatus() == CommIO::CommStatusConned)
    {
        QByteArray rcvData = _lowerIo->rcvData();
        if (rcvData.length() > 0)
        {
            _lowerRawDataLock.lockForWrite();
            _lowerBuf.append(rcvData);
            _lowerRawDataLock.unlock();
        }
    }
}

void DataWraper::updateLowerInputData()
{
    QList<QByteArray> lowerFrames = fetchLowerFrames();  /*获取当前下位机所有的数据帧*/
    for(QByteArray frame: lowerFrames)
    {
        unWrapLowerData(frame);
    }
}

void DataWraper::updateUperInputData()
{
    QList<QByteArray> uperFrmes = fetchUperFrames();   /*获取当前上位机所有的数据帧*/
    /*首先增加所有数据的次数*/
    _uperInRwLock.lockForWrite();
    _uperTransceInData.mConnCmdUnUpdateNum += 1;
    _uperTransceInData.mCommTypeUnpdateNum += 1;
    _uperTransceInData.mCurTorUnUpdateNum +=1;
    _uperTransceInData.mCurPipeUnUpdateNum += 1;
    _uperTransceInData.mCycleUnUpdateNum += 1;
    _uperTransceInData.mCtlTorUnUpdateNum += 1;
    _uperTransceInData.mDrawTorUnUpdateNum += 1;
    _uperTransceInData.mCycleMaxUnUpdateNum += 1;
    _uperTransceInData.mDateTimeUnUpdateNum += 1;
    _uperTransceInData.mPipeNoUnUpdateNum += 1;
    _uperTransceInData.mCorrFactorUnUpdateNum += 1;
    _uperTransceInData.mDelayTimeUnUpdateNum += 1;
    _uperTransceInData.mAddNoUnUpdateNum += 1;
    _uperTransceInData.mEchoCtlTorUnUpdateNum += 1;
    _uperTransceInData.mEchoDrawTorUnUpdateNum += 1;
    _uperTransceInData.mEchoCycleMaxUnUpdateNum += 1;
    _uperTransceInData.mEchoDateTimeUnUpdateNum += 1;
    _uperTransceInData.mEchoPipeNoUnUpdateNum += 1;
    _uperTransceInData.mEchoCorrFactorUnUpdateNum += 1;
    _uperTransceInData.mEchoDelaytTimeUnUpdateNum += 1;
    _uperInRwLock.unlock();
    for(QByteArray frame: uperFrmes)
    {
        unWrapUperData(frame);  /*对每帧数据进行解包处理*/
    }
    /*设置数据的有效性*/
    /*这里认为，如果连续10个周期没有收到有效数据，则认为数据无效*/
    _uperInRwLock.lockForWrite();
    if (_uperTransceInData.mConnCmdUnUpdateNum >= 10) _uperTransceInData.mConnCmdValid = false;
    if (_uperTransceInData.mCommTypeUnpdateNum >= 10) _uperTransceInData.mCommTypeValid = false;
    if (_uperTransceInData.mCurTorUnUpdateNum >= 10) _uperTransceInData.mCurTorValid = false;
    if (_uperTransceInData.mCurPipeUnUpdateNum >= 10) _uperTransceInData.mCurPipeValid = false;
    if (_uperTransceInData.mCycleUnUpdateNum >= 10) _uperTransceInData.mCycleNumValid = false;
    if (_uperTransceInData.mCtlTorUnUpdateNum >= 10) _uperTransceInData.mCtlTorValid = false;
    if (_uperTransceInData.mDrawTorUnUpdateNum >= 10) _uperTransceInData.mDrawTorValid = false;
    if (_uperTransceInData.mCycleMaxUnUpdateNum >= 10) _uperTransceInData.mCycleMaxValid = false;
    if (_uperTransceInData.mDateTimeUnUpdateNum >= 10) _uperTransceInData.mDateTimeValid = false;
    if (_uperTransceInData.mPipeNoUnUpdateNum >= 10) _uperTransceInData.mPipeNoValid = false;
    if (_uperTransceInData.mCorrFactorUnUpdateNum >= 10) _uperTransceInData.mCorrFactorValid = false;
    if (_uperTransceInData.mDelayTimeUnUpdateNum >= 10) _uperTransceInData.mDelayTimeValid = false;
    if (_uperTransceInData.mAddNoUnUpdateNum >= 10) _uperTransceInData.mAddNoValid = false;
    if (_uperTransceInData.mEchoCtlTorUnUpdateNum >= 10) _uperTransceInData.mEchoCtlTorValid = false;
    if (_uperTransceInData.mEchoDrawTorUnUpdateNum >= 10) _uperTransceInData.mEchoDrawTorValid = false;
    if (_uperTransceInData.mEchoCycleMaxUnUpdateNum >= 10) _uperTransceInData.mEchoCycleMaxValid = false;
    if (_uperTransceInData.mEchoDateTimeUnUpdateNum >= 10) _uperTransceInData.mEchoDateTimeValid = false;
    if (_uperTransceInData.mEchoPipeNoUnUpdateNum >= 10) _uperTransceInData.mEchoPipeNoValid = false;
    if (_uperTransceInData.mEchoCorrFactorUnUpdateNum >= 10) _uperTransceInData.mEchoCorrFactorValid = false;
    if (_uperTransceInData.mEchoDelaytTimeUnUpdateNum >= 10) _uperTransceInData.mEchoDelayTimeValid = false;
    _uperInRwLock.unlock();
}

void DataWraper::updataInputData()
{
    updateUperInputData();
    updateLowerInputData();
}

void DataWraper::stepSndData()
{
    /*发送数据*/
    wrapAndSndData();
}

QList<QByteArray> DataWraper::fetchUperFrames()
{
    QList<QByteArray> frameList;
    _uperRawDataLock.lockForWrite();
    int index = 0;/*此处应添加判断缓冲区的大小，大于某个过大的值，则删除该内容的一半*/
    for (int i = 0; i < _uperBuf.length() - 7; ++i)
    {
        /*首先判断头是否为： 0XAA*/
        if (((unsigned char)(_uperBuf.at(i)) == 0xaa))
        {
            unsigned char chcSum = 0;
            for (int j = 0; j < 7; ++ j)
            {
                chcSum += (unsigned char)_uperBuf.at(i + j);
            }
            /*其次判断CheckSum是否正确*/
            if (chcSum == (unsigned char)_uperBuf.at(i + 7))
            {
                /*校验正确，则把该帧数据填充到帧队列中*/
                frameList.append(_uperBuf.mid(i, 8));
                i += 7;
                index = i;
            }
        }
    }
    _uperBuf.remove(0, index - 0);
    _uperRawDataLock.unlock();
    return frameList;
}

QList<QByteArray> DataWraper::fetchLowerFrames()
{
    QList<QByteArray> frameList;
    _lowerRawDataLock.lockForWrite();
    int index = 0;
    for (int i=0; i < _lowerBuf.length() - (int)sizeof(LowerInRawDataStruct) + 1; ++i)
    {
        /*首先判断头是否为： 0x55*/
        if (((unsigned char)(_lowerBuf.at(i)) == 0x55))
        {
            unsigned char chcSum = 0;
            for (int j = 0; j < (int)sizeof(LowerInRawDataStruct) - 1; ++j)
            {
                chcSum += (unsigned char)_lowerBuf.at(i + j);
            }
            /*其次判断CkcSum是否正确*/
            if (chcSum == (unsigned char)_lowerBuf.at(i + sizeof(LowerInRawDataStruct) - 1))
            {
                frameList.append(_lowerBuf.mid(i, sizeof(LowerInRawDataStruct)));
                i += sizeof(LowerInRawDataStruct) - 1;
                index = i;
            }
        }
    }
    _lowerBuf.remove(0, index);
    _lowerRawDataLock.unlock();
    return frameList;
}

void DataWraper::unWrapUperData(QByteArray frameData)
{
    QByteArray data = frameData.mid(2, 4);
    quint32 payLoad = *((quint32*)(data.data()));
    quint8 cycle = (quint8)frameData.at(6);
    UperCmdType cmd = (UperCmdType)((unsigned char)frameData.at(1));
    _uperInRwLock.lockForWrite();;
    switch(cmd)
    {
    case UperCmdTypeConn:
        /*不做处理*/
        break;
    case UperCmdTypeCommType:
        _uperTransceInData.mCommType = payLoad;
        _uperTransceInData.mCommTypeUnpdateNum = 0;
        _uperTransceInData.mCommTypeValid = true;
        break;
    case UperCmdTypeCurTorPipe:
        _uperTransceInData.mCurTor = payLoad/65536;
        _uperTransceInData.mCurTorUnUpdateNum = 0;
        _uperTransceInData.mCurTorValid = true;
        _uperTransceInData.curPipe = payLoad%65536;
        _uperTransceInData.mCurPipeUnUpdateNum = 0;
        _uperTransceInData.mCurPipeValid = true;
        _uperTransceInData.mCycleNum = cycle;
        _uperTransceInData.mCycleUnUpdateNum = 0;
        _uperTransceInData.mCycleNumValid = true;
        break;
    case UperCmdTypeCurStatus:
        _uperTransceInData.mReleaseStatus = payLoad;
        _uperTransceInData.mReleaseStatusUnUpdateNum = 0;
        _uperTransceInData.mReleaseStatusValid = true;
        break;        
    case UperCmdTypeGetCtlTor:
        _uperTransceInData.mCtlTor = payLoad;
        _uperTransceInData.mCtlTorUnUpdateNum = 0;
        _uperTransceInData.mCtlTorValid = true;
        break;
    case UperCmdTypeGetDrawTor:
        _uperTransceInData.mDrawTor = payLoad;
        _uperTransceInData.mDrawTorUnUpdateNum = 0;
        _uperTransceInData.mDrawTorValid = true;
        break;
    case UperCmdTypeGetCycleMax:
        _uperTransceInData.mCycleMax = payLoad;
        _uperTransceInData.mCycleMaxUnUpdateNum = 0;
        _uperTransceInData.mCycleMaxValid = true;
        break;
    case UperCmdTypeGetDateTime:
        _uperTransceInData.mDateTime = payLoad;
        _uperTransceInData.mDateTimeUnUpdateNum = 0;
        _uperTransceInData.mDateTimeValid = true;
        break;
    case UperCmdTypeGetPipeNo:
        _uperTransceInData.mPipeNo = payLoad;
        _uperTransceInData.mPipeNoUnUpdateNum = 0;
        _uperTransceInData.mPipeNoValid = true;
        break;
    case UperCmdTypeGetCorrFactor:
        _uperTransceInData.mCorrFactor = payLoad;
        _uperTransceInData.mCorrFactorUnUpdateNum = 0;
        _uperTransceInData.mCorrFactorValid = true;
        break;
    case UperCmdTypeGetDelayTime:
        _uperTransceInData.mDelayTime = payLoad;
        _uperTransceInData.mDelayTimeUnUpdateNum = 0;
        _uperTransceInData.mDelayTimeValid = true;
        break;
    case UperCmdTypeGetWellNo:
        _uperTransceInData.mWellNo = payLoad;
        _uperTransceInData.mWellNoUnUpdateNum = 0;
        _uperTransceInData.mWellNoValid = true;
        break;
    case UperCmdTypeGetAddNo:
        _uperTransceInData.mAddNo = payLoad;
        _uperTransceInData.mAddNoUnUpdateNum = 0;
        _uperTransceInData.mAddNoValid = true;
        break;
    case UperCmdTypeSetCtlTor:
        _uperTransceInData.mEchoCtlTor = payLoad;
        _uperTransceInData.mEchoCtlTorUnUpdateNum = 0;
        _uperTransceInData.mEchoCtlTorValid = true;
        break;
    case UperCmdTypeSetDrawTor:
        _uperTransceInData.mEchoDrawTor = payLoad;
        _uperTransceInData.mEchoDrawTorUnUpdateNum = 0;
        _uperTransceInData.mEchoDrawTorValid = true;
        break;
    case UperCmdTypeSetCycleMax:
        _uperTransceInData.mEchoCycleMax = payLoad;
        _uperTransceInData.mEchoCycleMaxUnUpdateNum = 0;
        _uperTransceInData.mEchoCycleMaxValid = true;
        break;
    case UperCmdTypeSetDateTime:
        _uperTransceInData.mEchoDateTime = payLoad;
        _uperTransceInData.mEchoDateTimeUnUpdateNum = 0;
        _uperTransceInData.mEchoDateTimeValid = true;
        break;
    case UperCmdTypeSetPipeNo:
        _uperTransceInData.mEchoPipeNo = payLoad;
        _uperTransceInData.mEchoPipeNoUnUpdateNum = 0;
        _uperTransceInData.mEchoPipeNoValid = true;
        break;
    case UperCmdTypeSetCorrFactor:
        _uperTransceInData.mEchoCorrFactor = payLoad;
        _uperTransceInData.mEchoCorrFactorUnUpdateNum = 0;
        _uperTransceInData.mEchoCorrFactorValid = true;
        break;
    case UperCmdTypeSetDelayTime:
        _uperTransceInData.mEchoDelayTime = payLoad;
        _uperTransceInData.mEchoDelaytTimeUnUpdateNum = 0;
        _uperTransceInData.mEchoDelayTimeValid = true;
        break;
    case UperCmdTypeSetWellNo:
        _uperTransceInData.mEchoWellNo = payLoad;
        _uperTransceInData.mEchoWellUnUpdateNum = 0;
        _uperTransceInData.mEchoWellNoValid = true;
        break;
    case UperCmdTypeSetAddNo:
        _uperTransceInData.mEchoAddID = payLoad;
        _uperTransceInData.mEchoAddIDUnUpdateNum = 0;
        _uperTransceInData.mEchoAddIDValid = true;
        break;
    }
    _uperInRwLock.unlock();
}

void DataWraper::unWrapLowerData(QByteArray frameData)
{
    LowerInRawDataStruct data;
    FileInfo fileInfo;
    memcpy(&data, (void*)frameData.data(), qMin((unsigned int)frameData.size(), sizeof(data)));
    _lowerInRwLock.lockForWrite();
    switch(data.connData.mType)
    {
    case LowerCmdTypeFileList:
        fileInfo.mCurFileNo = (quint32)data.fileList.mCurFileNo;
        fileInfo.mFileNum = (quint32)data.fileList.mFileNum;
        fileInfo.mFileName.append((char*)data.fileList.mFileName, sizeof(data.fileList.mFileName));
        _lowerTransceInData.mFileList.append(fileInfo);
        _lowerTransceInData.mFileListValid = true;
        break;
    case LowerCmdTypeFileContent:
        break;
    case LowerCmdTypeFileCrc:
        break;
    case LowerCmdTypeDelFlag:
        break;
    default:
        break;
    }
    _lowerInRwLock.unlock();
}

void DataWraper::wrapAndSndData()
{
    wrapAndSndUperData();
    wrapAndSndLowerData();
}

void DataWraper::wrapAndSndUperData()
{
    if (_uperStatus != ConnStatusConnOk)
        return ;
    _uperOutRwLock.lockForWrite();
    QByteArray data;
    /*通信类型*/
    if (_uperTransceOutData.mCommTypeValid)
    {
        data = wrapUpTransData(UperCmdTypeCommType, _uperTransceOutData.mCommType);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mCommTypeValid = false;
        }
    }
    /*控制扭矩*/
    if (_uperTransceOutData.mCtlTorValid)
    {
        data = wrapUpTransData(UperCmdTypeGetCtlTor, _uperTransceOutData.mCtlTor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mCtlTorValid = false;
        }
    }
    /*画线扭矩*/
    if (_uperTransceOutData.mDrawTorValid)
    {
        data = wrapUpTransData(UperCmdTypeGetDrawTor, _uperTransceOutData.mDrawTor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mDrawTorValid = false;
        }
    }
    /*最大圈数*/
    if (_uperTransceOutData.mCycleMaxValid)
    {
        data = wrapUpTransData(UperCmdTypeGetCycleMax, _uperTransceOutData.mCycleMax);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mCycleMaxValid = false;
        }
    }
    /*时间日期*/
    if (_uperTransceOutData.mDateTimeValid)
    {
        data = wrapUpTransData(UperCmdTypeGetDateTime, _uperTransceOutData.mDateTime);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mDateTimeValid = false;
        }
    }
    /*杆号*/
    if (_uperTransceOutData.mPipeNoValid)
    {
        data = wrapUpTransData(UperCmdTypeGetPipeNo, _uperTransceOutData.mPipeNo);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mPipeNoValid = false;
        }
    }
    /*修正系数*/
    if (_uperTransceOutData.mCorrFactorValid)
    {
        data = wrapUpTransData(UperCmdTypeGetCorrFactor, _uperTransceOutData.mCorrFactor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mCorrFactorValid = false;
        }
    }
    /*延迟时间*/
    if (_uperTransceOutData.mDelayTimeValid)
    {
        data = wrapUpTransData(UperCmdTypeGetDelayTime, _uperTransceOutData.mDelayTime);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mDelayTimeValid = false;
        }
    }
    /*井号*/
    if (_uperTransceOutData.mWellNoValid)
    {
        data = wrapUpTransData(UperCmdTypeGetWellNo, _uperTransceOutData.mWellNo);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mWellNoValid = false;
        }
    }
    /*附加的ID*/
    if (_uperTransceOutData.mAddIDValid)
    {
        data = wrapUpTransData(UperCmdTypeGetAddNo, _uperTransceOutData.mAddID);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mAddIDValid = false;
        }
    }
    /*响应的控制扭矩*/
    if (_uperTransceOutData.mEchoCtlTorValid)
    {
        data = wrapUpTransData(UperCmdTypeSetCtlTor, _uperTransceOutData.mEchoCtlTor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoCtlTorValid = false;
        }
    }
    /*响应的画线扭矩*/
    if (_uperTransceOutData.mEchoDrawTorValid)
    {
        data = wrapUpTransData(UperCmdTypeSetDrawTor, _uperTransceOutData.mEchoDrawTor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoDrawTorValid = false;
        }
    }
    /*响应的圈数最大值*/
    if (_uperTransceOutData.mEchoCycleMaxValid)
    {
        data = wrapUpTransData(UperCmdTypeSetCycleMax, _uperTransceOutData.mEchoCycleMax);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoCycleMaxValid = false;
        }
    }
    /*响应的日期时间*/
    if (_uperTransceOutData.mEchoDateTimeValid)
    {
        data = wrapUpTransData(UperCmdTypeSetDateTime, _uperTransceOutData.mEchoDateTime);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoDateTimeValid = false;
        }
    }
    /*响应的套管编号*/
    if (_uperTransceOutData.mEchoPipeNoValid)
    {
        data = wrapUpTransData(UperCmdTypeSetPipeNo, _uperTransceOutData.mEchoPipeNo);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoPipeNoValid = false;
        }
    }
    /*响应的修正系数*/
    if (_uperTransceOutData.mEchoCorrFactorValid)
    {
        data = wrapUpTransData(UperCmdTypeSetCorrFactor, _uperTransceOutData.mEchoCorrFactor);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoCorrFactorValid = false;
        }
    }
    /*响应的延迟时间*/
    if (_uperTransceOutData.mEchoDelayTimeValid)
    {
        data = wrapUpTransData(UperCmdTypeSetDelayTime, _uperTransceOutData.mEchoDelayTime);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoDelayTimeValid = false;
        }
    }
    /*响应的井号*/
    if (_uperTransceOutData.mEchoWellNoValid)
    {
        data = wrapUpTransData(UperCmdTypeSetWellNo, _uperTransceOutData.mEchoWellNo);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoWellNoValid = false;
        }
    }
    /*附加的ID*/
    if (_uperTransceOutData.mEchoAddIDValid)
    {
        data = wrapUpTransData(UperCmdTypeSetAddNo, _uperTransceOutData.mEchoAddID);
        if (data.size() == _uperIo->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _uperTransceOutData.mEchoAddIDValid = false;
        }
    }
    /*首先增加所有数据的次数*/
    _uperTransceOutData.mCommTypeUnpdateNum += 1;
    _uperTransceOutData.mCtlTorUnUpdateNum += 1;
    _uperTransceOutData.mDrawTorUnUpdateNum += 1;
    _uperTransceOutData.mCycleMaxUnUpdateNum += 1;
    _uperTransceOutData.mDateTimeUnUpdateNum += 1;
    _uperTransceOutData.mPipeNoUnUpdateNum += 1;
    _uperTransceOutData.mCorrFactorUnUpdateNum += 1;
    _uperTransceOutData.mDelayTimeUnUpdateNum += 1;
    _uperTransceOutData.mWellNoUnUpdateNum += 1;
    _uperTransceOutData.mAddIDUnUpdateNum += 1;

    _uperTransceOutData.mEchoCtlTorUnUpdateNum += 1;
    _uperTransceOutData.mEchoDrawTorUnUpdateNum += 1;
    _uperTransceOutData.mEchoCycleMaxUnUpdateNum += 1;
    _uperTransceOutData.mEchoDateTimeUnUpdateNum += 1;
    _uperTransceOutData.mEchoPipeNoUnUpdateNum += 1;
    _uperTransceOutData.mEchoCorrFactorUnUpdateNum += 1;
    _uperTransceOutData.mEchoDelaytTimeUnUpdateNum += 1;
    _uperTransceOutData.mEchoWellUnUpdateNum += 1;
    _uperTransceOutData.mEchoAddIDUnUpdateNum += 1;

    if (_uperTransceOutData.mCommTypeUnpdateNum >= 10) _uperTransceOutData.mCommTypeValid = false;
    if (_uperTransceOutData.mCtlTorUnUpdateNum >= 10) _uperTransceOutData.mCtlTorValid = false;
    if (_uperTransceOutData.mDrawTorUnUpdateNum >= 10) _uperTransceOutData.mDrawTorValid = false;
    if (_uperTransceOutData.mCycleMaxUnUpdateNum >= 10) _uperTransceOutData.mCycleMaxValid = false;
    if (_uperTransceOutData.mDateTimeUnUpdateNum >= 10) _uperTransceOutData.mDateTimeValid = false;
    if (_uperTransceOutData.mPipeNoUnUpdateNum >= 10) _uperTransceOutData.mPipeNoValid = false;
    if (_uperTransceOutData.mCorrFactorUnUpdateNum >= 10) _uperTransceOutData.mCorrFactorValid = false;
    if (_uperTransceOutData.mDelayTimeUnUpdateNum >= 10) _uperTransceOutData.mDelayTimeValid = false;
    if (_uperTransceOutData.mWellNoUnUpdateNum >= 10) _uperTransceOutData.mWellNoValid = false;
    if (_uperTransceOutData.mAddIDUnUpdateNum >= 10) _uperTransceOutData.mAddIDValid = false;

    if (_uperTransceOutData.mEchoCtlTorUnUpdateNum >= 10) _uperTransceOutData.mEchoCtlTorValid = false;
    if (_uperTransceOutData.mEchoDrawTorUnUpdateNum >= 10) _uperTransceOutData.mEchoDrawTorValid = false;
    if (_uperTransceOutData.mEchoCycleMaxUnUpdateNum >= 10) _uperTransceOutData.mEchoCycleMaxValid = false;
    if (_uperTransceOutData.mEchoDateTimeUnUpdateNum >= 10) _uperTransceOutData.mEchoDateTimeValid = false;
    if (_uperTransceOutData.mEchoPipeNoUnUpdateNum >= 10) _uperTransceOutData.mEchoPipeNoValid = false;
    if (_uperTransceOutData.mEchoCorrFactorUnUpdateNum >= 10) _uperTransceOutData.mEchoCorrFactorValid = false;
    if (_uperTransceOutData.mEchoDelaytTimeUnUpdateNum >= 10) _uperTransceOutData.mEchoDelayTimeValid = false;
    if (_uperTransceOutData.mEchoWellUnUpdateNum >= 10) _uperTransceOutData.mEchoWellNoValid = false;
    if (_uperTransceOutData.mEchoCycleMaxUnUpdateNum >= 10) _uperTransceOutData.mEchoCycleMaxValid = false;
    if (_uperTransceOutData.mEchoAddIDUnUpdateNum >= 10) _uperTransceOutData.mEchoAddIDValid = false;

    /*设置数据的有效性*/
    _uperOutRwLock.unlock();
}

void DataWraper::wrapAndSndLowerData()
{
    QByteArray data;
    if (_lowerStatus != ConnStatusConnOk)
        return ;
    _lowerOutRwLock.lockForWrite();
    if (_lowerTransceOutData.mReqFilesListValid) /*请求文件列表*/
    {
        data = wrapLowerTransData(LowerCmdTypeFileList, QByteArray());
        if (data.size() == _lowerIo->wrtData(data))
        {
            _lowerTransceOutData.mReqFilesListValid = false;
        }
    }
    if (_lowerTransceOutData.mFileNameValid)
    {
        data = wrapLowerTransData(LowerCmdTypeFileContent, _lowerTransceOutData.mFileName);
        if (data.size() == _lowerIo->wrtData(data))
        {
            _lowerTransceOutData.mFileNameValid = false;
        }
    }
    if (_lowerTransceOutData.mDelFileNameValid)
    {
        data = wrapLowerTransData(LowerCmdTypeDelFlag, _lowerTransceOutData.mDelFileName);
        if (data.size() == _lowerIo->wrtData(data))
        {
            _lowerTransceOutData.mDelFileNameValid = false;
        }
    }
    /*首先增加所有数据的次数*/
    _lowerTransceOutData.mReqFilesListUnUpdateNum +=1;
    _lowerTransceOutData.mFileNameUnUpdateNum += 1;
    _lowerTransceOutData.mDelFileNameUnUpdateNum += 1;
    if (_lowerTransceOutData.mReqFilesListUnUpdateNum >= 10) _lowerTransceOutData.mReqFilesListValid = false;
    if (_lowerTransceOutData.mFileNameUnUpdateNum >= 10) _lowerTransceOutData.mFileNameValid = false;
    if (_lowerTransceOutData.mDelFileNameUnUpdateNum >= 10) _lowerTransceOutData.mDelFileNameValid = false;
    _lowerOutRwLock.unlock();
}

QByteArray DataWraper::wrapUpTransData(UperCmdType cmd, qint32 payLoad)
{
    /*封装待发送的数据*/
    /*
     * 第一个字节 0xAA, 第二个字节 0x55, 第三个字节 CmdType， 后面四个字节 Payload 最后一个字节 CheckSum
     *
    */
    QByteArray data;
    data.append((char)0xaa);
    data.append((char)cmd);
    payLoad = qToLittleEndian(payLoad);
    data.append((char*)(&payLoad), sizeof(qint32));
    data.append((char)0);
    unsigned char chcSum  = 0;
    for(int i = 0; i < data.length(); ++i)
    {
        chcSum += (unsigned char)data.at(i);
    }
    data.append(chcSum);
    return data;
}

QByteArray DataWraper::wrapLowerTransData(LowerCmdType cmd, QByteArray payLoad)
{
    /*Head：0X55*/
    LowerOutRawDataStruct data;
    data.normalData.mHead = 0x55;
    data.normalData.mType = (quint8)cmd;
    memset((void*)data.normalData.mData, 0, sizeof(data.normalData.mData));
    memcpy((void*)data.normalData.mData, payLoad.data(), qMin(sizeof(data.normalData.mData), (unsigned int)payLoad.size()));
    unsigned char chcSum  = 0;
    QByteArray retData((char*)&data, sizeof(data));
    for(int i = 0; i < retData.length()-1; ++i)
    {
        chcSum += (unsigned char)retData.at(i);
    }
    retData[retData.length()- 1] = chcSum;
    return retData;
}

void DataWraper::handleUperConn()
{
    if (_uperConnCount > 0)
    {
        _uperConnCount -= 1;
        /*依次判断每个候选连接，是否收到数据*/
        for (SerialComm* serial: _uperCandiList)
        {
            QByteArray datas = serial->rcvData();
            if (datas.length() >= 8&&
                    (unsigned char)(datas.at(0)) == 0xaa)
            {
                /*建立起了正常连接*/
                if (_uperIo != 0)
                {
                    _uperIo->disConn();
                    delete _uperIo;
                }
                _uperIo = serial;
                _uperCandiList.removeOne(serial); /*从候选列表中移除该连接*/
                _uperStatus = ConnStatusConnOk; /*连接成功*/

                qDebug()<<"Connect Success and the rcv data is: "<<datas;
                /*Debug*/
//                setUperData(UperCmdTypeCommType, 0);
//                setUperData(UperCmdTypeSetCtlTor, 10);
//                setUperData(UperCmdTypeSetDrawTor, 100);
//                setUperData(UperCmdTypeSetCycleMax, 50);
//                setUperData(UperCmdTypeSetDateTime, QDateTime::currentDateTime().toTime_t());
  //              setUperData(UperCmdTypeSetPipeNo, 120);
//                setUperData(UperCmdTypeSetCorrFactor, 12);
//                setUperData(UperCmdTypeSetDelayTime, 8);
//                setUperData(UperCmdTypeSetWellNo, 9999);
//                setUperData(UperCmdTypeSetAddNo, 9999);

//                setUperData(UperCmdTypeGetCtlTor, 0);
//                setUperData(UperCmdTypeGetDrawTor, 0);
//                setUperData(UperCmdTypeGetCycleMax, 0);
//                setUperData(UperCmdTypeGetDateTime, QDateTime::currentDateTime().toTime_t());
//                setUperData(UperCmdTypeGetPipeNo, 655);
//                setUperData(UperCmdTypeGetCorrFactor, 2);
//                setUperData(UperCmdTypeGetDelayTime, 3);
//                setUperData(UperCmdTypeGetWellNo, 23);
//                setUperData(UperCmdTypeGetAddNo, 123);
                //setUperData(UperCmdTypeSetCtlTor, 100);

                //setUperData(UperCmdTypeSetWellNo, 9999);
                /*Debug*/
                break;
            }
        }
        /*如果已经成功建立连接，或者连接计数为0，则删除候选项*/
        if (_uperStatus == ConnStatusConnOk||
                _uperConnCount == 0)
        {
            /*连接成功，则删除候选连接,并清空连接计数*/
            for (SerialComm* serial: _uperCandiList)
            {
                if (serial != 0)
                {
                    serial->disConn();
                    delete serial;
                    qDebug()<<"Remove the serial";
                }
            }
            _uperConnCount = 0;
            if (_uperStatus != ConnStatusConnOk) /*如果此时还未连接成功，则设置连接失败*/
            {
                _uperStatus = ConnStatusUnConn;
                qDebug()<<"Failed to conn";
            }
        }
    }
}

void DataWraper::handleLowerConn()
{
    if (_lowerConnCount > 0)
    {
        _lowerConnCount -= 1;
        for (SerialComm* serial: _lowerCandiList)
        {
            QByteArray datas = serial->rcvData();
            if (datas.length() > 0)
            {
                qDebug()<<"Rcv: "<<datas;
            }
            if (datas.length() >= (int)sizeof(LowerInRawDataStruct))
            {
                LowerInRawDataStruct rawData;
                memcpy(&rawData, datas.data(), (int)sizeof(LowerInRawDataStruct));
                if (rawData.connData.mHead == 0x55&&
                        rawData.connData.mType == 0x00)
                {
                    /*建立起正常连接*/
                    if (_lowerIo != 0)
                    {
                        _lowerIo->disConn();
                        delete _lowerIo;
                    }
                    _lowerIo = serial;
                    _lowerCandiList.removeOne(serial);
                    _lowerStatus = ConnStatusConnOk; /*连接成功*/
                    qDebug()<<"Connect Lower Successed！\nThe data is:"<<datas;
                    //setLowerData(LowerCmdTypeFileList, QByteArray());
                }
            }
        }
        if (_lowerStatus == ConnStatusConnOk||
                _lowerConnCount == 0)
        {
            for (SerialComm* serial: _lowerCandiList)
            {
                if (serial != 0)
                {
                    serial->disConn();
                    delete serial;
                    qDebug()<<"Remove the serial";
                }
            }
            _lowerConnCount = 0;
            if (_lowerStatus != ConnStatusConnOk) /*如果此时还未成功，则设置连接失败*/
            {
                _lowerStatus = ConnStatusUnConn;
                qDebug()<<"Failed to conn Lower Transceiver";
            }
        }
    }
}

void DataWraper::monitorConnStatus()
{
    if (_uperIo != 0&&
            _uperStatus != ConnStatusConnecting)
    {
        if (_uperIo->getCurStatus() == CommIO::CommStatusDisconn)
            _uperStatus = ConnStatusUnConn;
    }
}
