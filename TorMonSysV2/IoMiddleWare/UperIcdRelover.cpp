#include "UperIcdRelover.h"
#include <QtEndian>
#include "Comm/GlobalData.h"
#include <QDebug>

UperIcdRelover::UperIcdRelover():IcdRelover(),
    _io(NULL)
{
    initDataSet();/*初始化参数*/
    startTimer(_cyleTimeMs); /*这里默认为20ms运行一次*/
}

void UperIcdRelover::conn2Edp()
{
    /*如果当前处理连接中或者已经连接上，则不做任何处理*/
    if (_connStatus == ConnStatusConnecting ||
            _connStatus == ConnStatusConnOk)
        return ;
    GlobalData::getInstance()->writeLog("Start to get connection with Uper......");
    _candiList.clear();
    _connCount = 0;
    ConfigContext cfg;
    cfg = GlobalData::getInstance()->getConfigData();
    /*1.获取所有可用串口*/
    QStringList serialNames = SerialComm::getAllSerials();
    /*2.依次打开每个串口，并判断在1s内能否收到CONN命令*/
    for (QString serial: serialNames)
    {
        SerialComm* serialComm = new SerialComm;
        /*设置串口属性*/
        SerialProp serialProp;

        serialProp.mSerialName = serial;
        serialProp.mBaudRate = cfg.mUpTransPort;
        serialProp.mDataBits = cfg.mUpTransDataBits;
        serialProp.mFlowControl = cfg.mUpTransFlowCtl;
        serialProp.mParity = cfg.mUpTransParity;
        serialProp.mStopBits = cfg.mUpTransStopBits;
        CommIO::CommStatus status = serialComm->conn2Edp(&serialProp);
        /*3.a 如果串口打开失败，则删除该serialComm*/
        if (status != CommIO::CommStatusConned)
        {
            serialComm->disConn();
            delete serialComm;
            serialComm = 0;
            continue;
        }
        /*3.b 否则，添加到候选列表中*/
        _candiList.append(serialComm);
    }
    /*如果候选列表>0，则设置连接计数为50(old)（即等待1s），开始连接计数*/
    if (_candiList.length() > 0)
    {
        _connCount = cfg.mUperMaxConnTimeOut/_cyleTimeMs;
        _connStatus = ConnStatusConnecting;
    }
}

ConnStatusType UperIcdRelover::getConnStatus()
{
    return _connStatus;
}

void UperIcdRelover::setData(void *data)
{
    SetArgDataSet* argData = (SetArgDataSet*)data;
    _outLock.lockForWrite();
    switch(argData->mType)
    {
    case UperCmdTypeCommType:
        _outData.mCommType = argData->mPayLoad;
        _outData.mCommTypeUnpdateNum = 0;
        _outData.mCommTypeValid = true;
        break;
    case UperCmdTypeCurTorPipe:
        break;
    case UperCmdTypeCurStatus:
        break;
    case UperCmdTypeGetCtlTor:
        _outData.mCtlTor = argData->mPayLoad;
        _outData.mCtlTorUnUpdateNum = 0;
        _outData.mCtlTorValid = true;
        break;
    case UperCmdTypeGetDrawTor:
        _outData.mDrawTor = argData->mPayLoad;
        _outData.mDrawTorUnUpdateNum = 0;
        _outData.mDrawTorValid = true;
        break;
    case UperCmdTypeGetCycleMax:
        _outData.mCycleMax = argData->mPayLoad;
        _outData.mCycleMaxUnUpdateNum = 0;
        _outData.mCycleMaxValid = true;
        break;
    case UperCmdTypeGetDateTime:
        _outData.mDateTime = argData->mPayLoad;
        _outData.mDateTimeUnUpdateNum = 0;
        _outData.mDateTimeValid = true;
        break;
    case UperCmdTypeGetPipeNo:
        _outData.mPipeNo = argData->mPayLoad;
        _outData.mPipeNoUnUpdateNum = 0;
        _outData.mPipeNoValid = true;
        break;
    case UperCmdTypeGetCorrFactor:
        _outData.mCorrFactor = argData->mPayLoad;
        _outData.mCorrFactorUnUpdateNum = 0;
        _outData.mCorrFactorValid = true;
        break;
    case UperCmdTypeGetDelayTime:
        _outData.mDelayTime = argData->mPayLoad;
        _outData.mDelayTimeUnUpdateNum = 0;
        _outData.mDelayTimeValid = true;
        break;
    case UperCmdTypeGetWellNo:
        _outData.mWellNo = argData->mPayLoad;
        _outData.mWellNoUnUpdateNum = 0;
        _outData.mWellNoValid = true;
        break;
    case UperCmdTypeGetAddNo:
        _outData.mAddID = argData->mPayLoad;
        _outData.mAddIDUnUpdateNum = 0;
        _outData.mAddIDValid = true;
        break;
    case UperCmdTypeGetTongArmLen: /*获取套管长度， 新增 2018-1-5*/
        _outData.mTongArmLen = argData->mPayLoad;
        _outData.mTongArmLenUnUpdateNum = 0;
        _outData.mTongArmLenValid = true;
        break;
    case UperCmdTypeSetCtlTor:
        _outData.mSetCtlTor = argData->mPayLoad;
        _outData.mSetCtlTorUnUpdateNum = 0;
        _outData.mSetCtlTorValid = true;
        break;
    case UperCmdTypeSetDrawTor:
        _outData.mSetDrawTor = argData->mPayLoad;
        _outData.mSetDrawTorUnUpdateNum = 0;
        _outData.mSetDrawTorValid = true;
        break;
    case UperCmdTypeSetCycleMax:
        _outData.mSetCycleMax = argData->mPayLoad;
        _outData.mSetCycleMaxUnUpdateNum = 0;
        _outData.mSetCycleMaxValid = true;
        break;
    case UperCmdTypeSetDateTime:
        _outData.mSetDateTime = argData->mPayLoad;
        _outData.mSetDateTimeUnUpdateNum = 0;
        _outData.mSetDateTimeValid = true;
        break;
    case UperCmdTypeSetPipeNo:
        _outData.mSetPipeNo = argData->mPayLoad;
        _outData.mSetPipeNoUnUpdateNum = 0;
        _outData.mSetPipeNoValid = true;
        break;
    case UperCmdTypeSetCorrFactor:
        _outData.mSetCorrFactor = argData->mPayLoad;
        _outData.mSetCorrFactorUnUpdateNum = 0;
        _outData.mSetCorrFactorValid = true;
        break;
    case UperCmdTypeSetDelayTime:
        _outData.mSetDelayTime = argData->mPayLoad;
        _outData.mSetDelaytTimeUnUpdateNum = 0;
        _outData.mSetDelayTimeValid = true;
        break;
    case UperCmdTypeSetWellNo:
        _outData.mSetWellNo = argData->mPayLoad;
        _outData.mSetWellUnUpdateNum = 0;
        _outData.mSetWellNoValid = true;
        break;
    case UperCmdTypeSetAddNo:
        _outData.mSetAddID = argData->mPayLoad;
        _outData.mSetAddIDUnUpdateNum = 0;
        _outData.mSetAddIDValid = true;
        break;
    case UperCmdTypeSetTongArmLen: /*设置套管长度，新增 2018-1-5*/
        _outData.mSetTongArmLen = argData->mPayLoad;
        _outData.mSetTongArmLenUnUpdateNum = 0;
        _outData.mSetTongArmLenValid = true;
        break;
    case UperCmdTypeSetCtlMode: /*设置控制模式，新增 2018-1-5*/
        _outData.mSetCtlMode = argData->mPayLoad;
        _outData.mSetCtlModeUnUpdateNum = 0;
        _outData.mSetCtlModeValid = true;
        break;
    default:
        break;
    }

    _outLock.unlock();
}

QByteArray UperIcdRelover::getData()
{
    QByteArray data;
    _inLock.lockForRead();
    data.append((char*)&_inData, sizeof(InUperTransceiverDataSet));
    _inLock.unlock();
    return data;
}

void UperIcdRelover::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    static int i = 0;
    i = (i+1)%50;
    /*每个周期接收和发送一次底层数据,后续根据性能调节*/
    getRawData();   /*获取原始数据*/
    stepSndData();  /*发送数据*/
    /*每2个周期接收并处理一次数据，存放到中间层缓冲区*/
    if (i%2 == 0)
    {
        updateInputData();
    }
    /*处理额外的事务*/
    cycleHandleOtherMission();
}

void UperIcdRelover::updateInputData()
{
    /*首先增加所有数据的未更新次数*/
    _inLock.lockForWrite();
    _inData.mConnCmdUnUpdateNum += 1;
    _inData.mCommTypeUnpdateNum += 1;
    _inData.mCurTorUnUpdateNum +=1;
    _inData.mCurPipeUnUpdateNum += 1;
    _inData.mCurCycleUnUpdateNum += 1;
    _inData.mCtlTorUnUpdateNum += 1;
    _inData.mDrawTorUnUpdateNum += 1;
    _inData.mCycleMaxUnUpdateNum += 1;
    _inData.mDateTimeUnUpdateNum += 1;
    _inData.mPipeNoUnUpdateNum += 1;
    _inData.mCorrFactorUnUpdateNum += 1;
    _inData.mDelayTimeUnUpdateNum += 1;
    _inData.mAddNoUnUpdateNum += 1;
    _inData.mTongArmLenUnUpdateNum += 1; /*钳臂长未更新次数 新增 2018-1-5*/
    _inData.mSetCtlTorUnUpdateNum += 1;
    _inData.mSetDrawTorUnUpdateNum += 1;
    _inData.mSetCycleMaxUnUpdateNum += 1;
    _inData.mSetDateTimeUnUpdateNum += 1;
    _inData.mSetPipeNoUnUpdateNum += 1;
    _inData.mSetCorrFactorUnUpdateNum += 1;
    _inData.mSetDelaytTimeUnUpdateNum += 1;
    _inData.mSetCtlModeUnUpdateNum += 1;    /*控制模式未更新次数 新增 2018-1-5*/
    _inData.mSetTongArmLenUnUpdateNum += 1; /*钳臂长未更新次数 新增 2018-1-5*/
    _inLock.unlock();
    /*从原始数据中获取帧列表*/
    QList<QByteArray> frames = fetchFrames();
    /*每帧数据进行拆包处理*/
    unWrapFrames(frames);
    /*设置数据有效性，这里认为，如果连续10个周期没有收到有效数据，则认为数据无效*/
    _inLock.lockForWrite();
    if (_inData.mConnCmdUnUpdateNum >= 10) _inData.mConnCmdValid = false;
    if (_inData.mCommTypeUnpdateNum >= 10) _inData.mCommTypeValid = false;
    if (_inData.mCurTorUnUpdateNum >= 10) _inData.mCurTorValid = false;
    if (_inData.mCurPipeUnUpdateNum >= 10) _inData.mCurPipeValid = false;
    if (_inData.mCurCycleUnUpdateNum >= 10) _inData.mCurCycleValid = false;
    if (_inData.mCtlTorUnUpdateNum >= 10) _inData.mCtlTorValid = false;
    if (_inData.mDrawTorUnUpdateNum >= 10) _inData.mDrawTorValid = false;
    if (_inData.mCycleMaxUnUpdateNum >= 10) _inData.mCycleMaxValid = false;
    if (_inData.mDateTimeUnUpdateNum >= 10) _inData.mDateTimeValid = false;
    if (_inData.mPipeNoUnUpdateNum >= 10) _inData.mPipeNoValid = false;
    if (_inData.mCorrFactorUnUpdateNum >= 10) _inData.mCorrFactorValid = false;
    if (_inData.mDelayTimeUnUpdateNum >= 10) _inData.mDelayTimeValid = false;
    if (_inData.mAddNoUnUpdateNum >= 10) _inData.mAddNoValid = false;
    if (_inData.mTongArmLenUnUpdateNum >= 10) _inData.mTongArmLenValid = false;/*钳臂长数据有效性 新增 2018-1-5*/
    if (_inData.mSetCtlTorUnUpdateNum >= 10) _inData.mSetCtlTorValid = false;
    if (_inData.mSetDrawTorUnUpdateNum >= 10) _inData.mSetDrawTorValid = false;
    if (_inData.mSetCycleMaxUnUpdateNum >= 10) _inData.mSetCycleMaxValid = false;
    if (_inData.mSetDateTimeUnUpdateNum >= 10) _inData.mSetDateTimeValid = false;
    if (_inData.mSetPipeNoUnUpdateNum >= 10) _inData.mSetPipeNoValid = false;
    if (_inData.mSetCorrFactorUnUpdateNum >= 10) _inData.mSetCorrFactorValid = false;
    if (_inData.mSetDelaytTimeUnUpdateNum >= 10) _inData.mSetDelayTimeValid = false;
    if (_inData.mSetCtlModeUnUpdateNum >= 10) _inData.mSetCtlModeValid = false;/*控制模式数据有效性 新增 2018-1-5*/
    if (_inData.mSetTongArmLenUnUpdateNum >= 10) _inData.mSetTongArmLenValid = false;/*钳臂长有效性 新增 2018-1-5*/
    _inLock.unlock();
}

void UperIcdRelover::getRawData()
{
    /*如果io有效，且io处于连接状态，则正常接收数据*/
    if (_io && _connStatus != ConnStatusConnecting)
    {
        if (_io->getCurStatus() == CommIO::CommStatusDisconn)
            _connStatus = ConnStatusUnConn;
    }
    if (_io&& _connStatus == ConnStatusConnOk)
    {
        _rawBuf.append(_io->rcvData());
    }
}

QList<QByteArray> UperIcdRelover::fetchFrames()
{
    QList<QByteArray> frameList;
    int index = 0;
    for (int i=0; i < _rawBuf.length() - 7; ++i)
    {
        /*首先判断头是否为： 0xAA*/
        if (((unsigned char)(_rawBuf.at(i)) == 0xaa))
        {
            unsigned char chcSum = 0;
            for (int j = 0; j < 7; ++ j)
            {
                chcSum += (unsigned char)_rawBuf.at(i + j);
            }
            /*其次判断CheckSum是否正确*/
            if (chcSum == (unsigned char)_rawBuf.at(i + 7))
            {
                /*校验正确，则把该帧数据填充到帧队列中*/
                frameList.append(_rawBuf.mid(i, 8));
                i += 7;
                index = i;
            }
        }
    }
    if (index == 0&&_rawBuf.length()>8000)/*这里认为如果缓冲区里面数据足够多时，还未收到有效的数据，则应当适当的删掉部分数据，以免影响内存使用*/
    {
        index = _rawBuf.length()/2;
    }
    _rawBuf.remove(0, index);
    return frameList;
}

void UperIcdRelover::unWrapFrames(QList<QByteArray> frames)
{
    _inLock.lockForWrite();
    for (QByteArray frame: frames)
    {
        QByteArray data = frame.mid(2, 4);
        quint32 payLoad = *((quint32*)(data.data()));
        quint8 cycle = (quint8)frame.at(6);
        UperCmdType cmd = (UperCmdType)((unsigned char)frame.at(1));
        switch(cmd)
        {
        case UperCmdTypeConn:
            /*不做处理*/
            break;
        case UperCmdTypeCommType:
            _inData.mCommType = payLoad;
            _inData.mCommTypeUnpdateNum = 0;
            _inData.mCommTypeValid = true;
            break;
        case UperCmdTypeCurTorPipe:
            _inData.mCurTor = payLoad/65536;
            _inData.mCurTorUnUpdateNum = 0;
            _inData.mCurTorValid = true;
            _inData.mCurPipe = payLoad%65536;
            _inData.mCurPipeUnUpdateNum = 0;
            _inData.mCurPipeValid = true;
            _inData.mCurCycle = cycle;
            _inData.mCurCycleUnUpdateNum = 0;
            _inData.mCurCycleValid = true;
            break;
        case UperCmdTypeCurStatus:
            _inData.mReleaseStatus = payLoad;
            _inData.mReleaseStatusUnUpdateNum = 0;
            _inData.mReleaseStatusValid = true;
            break;
        case UperCmdTypeGetCtlTor:
            _inData.mCtlTor = payLoad;
            _inData.mCtlTorUnUpdateNum = 0;
            _inData.mCtlTorValid = true;
            break;
        case UperCmdTypeGetDrawTor:
            _inData.mDrawTor = payLoad;
            _inData.mDrawTorUnUpdateNum = 0;
            _inData.mDrawTorValid = true;
            break;
        case UperCmdTypeGetCycleMax:
            _inData.mCycleMax = payLoad;
            _inData.mCycleMaxUnUpdateNum = 0;
            _inData.mCycleMaxValid = true;
            break;
        case UperCmdTypeGetDateTime:
            _inData.mDateTime = payLoad;
            _inData.mDateTimeUnUpdateNum = 0;
            _inData.mDateTimeValid = true;
            break;
        case UperCmdTypeGetPipeNo:
            _inData.mPipeNo = payLoad;
            _inData.mPipeNoUnUpdateNum = 0;
            _inData.mPipeNoValid = true;
            break;
        case UperCmdTypeGetCorrFactor:
            _inData.mCorrFactor = payLoad;
            _inData.mCorrFactorUnUpdateNum = 0;
            _inData.mCorrFactorValid = true;
            break;
        case UperCmdTypeGetDelayTime:
            _inData.mDelayTime = payLoad;
            _inData.mDelayTimeUnUpdateNum = 0;
            _inData.mDelayTimeValid = true;
            break;
        case UperCmdTypeGetWellNo:
            _inData.mWellNo = payLoad;
            _inData.mWellNoUnUpdateNum = 0;
            _inData.mWellNoValid = true;
            break;
        case UperCmdTypeGetAddNo:
            _inData.mAddNo = payLoad;
            _inData.mAddNoUnUpdateNum = 0;
            _inData.mAddNoValid = true;
            break;
        case UperCmdTypeGetTongArmLen:/*钳臂长,新增 2018-1-5*/
            _inData.mTongArmLen = payLoad;
            _inData.mTongArmLenUnUpdateNum = 0;
            _inData.mTongArmLenValid = true;
            break;
        case UperCmdTypeSetCtlTor:
            _inData.mSetCtlTor = payLoad;
            _inData.mSetCtlTorUnUpdateNum = 0;
            _inData.mSetCtlTorValid = true;
            break;
        case UperCmdTypeSetDrawTor:
            _inData.mSetDrawTor = payLoad;
            _inData.mSetDrawTorUnUpdateNum = 0;
            _inData.mSetDrawTorValid = true;
            break;
        case UperCmdTypeSetCycleMax:
            _inData.mSetCycleMax = payLoad;
            _inData.mSetCycleMaxUnUpdateNum = 0;
            _inData.mSetCycleMaxValid = true;
            break;
        case UperCmdTypeSetDateTime:
            _inData.mSetDateTime = payLoad;
            _inData.mSetDateTimeUnUpdateNum = 0;
            _inData.mSetDateTimeValid = true;
            break;
        case UperCmdTypeSetPipeNo:
            _inData.mSetPipeNo = payLoad;
            _inData.mSetPipeNoUnUpdateNum = 0;
            _inData.mSetPipeNoValid = true;
            break;
        case UperCmdTypeSetCorrFactor:
            _inData.mSetCorrFactor = payLoad;
            _inData.mSetCorrFactorUnUpdateNum = 0;
            _inData.mSetCorrFactorValid = true;
            break;
        case UperCmdTypeSetDelayTime:
            _inData.mSetDelayTime = payLoad;
            _inData.mSetDelaytTimeUnUpdateNum = 0;
            _inData.mSetDelayTimeValid = true;
            break;
        case UperCmdTypeSetWellNo:
            _inData.mSetWellNo = payLoad;
            _inData.mSetWellUnUpdateNum = 0;
            _inData.mSetWellNoValid = true;
            break;
        case UperCmdTypeSetAddNo:
            _inData.mSetAddID = payLoad;
            _inData.mSetAddIDUnUpdateNum = 0;
            _inData.mSetAddIDValid = true;
            break;
        case UperCmdTypeSetTongArmLen:/*设置钳臂长,新增 2018-1-5*/
            _inData.mSetTongArmLen = payLoad;
            _inData.mSetTongArmLenUnUpdateNum = 0;
            _inData.mSetTongArmLenValid = true;
            break;
        case UperCmdTypeSetCtlMode:/*设置控制模式,新增 2018-1-5*/
            _inData.mSetCtlMode = payLoad;
            _inData.mSetCtlModeUnUpdateNum = 0;
            _inData.mSetCtlModeValid = true;
            break;
        default:
            break;
        }
    }
    _inLock.unlock();
}

void UperIcdRelover::stepSndData()
{
    /*通信状态或者io不正常，直接返回*/
    if (!_io|| (_connStatus != ConnStatusConnOk))
    {
        return ;
    }
    QByteArray data;
    _outLock.lockForRead();
    /*通信类型*/
    if (_outData.mCommTypeValid)
    {
        data = wrapFrame(UperCmdTypeCommType, _outData.mCommType);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mCommTypeValid = false;
        }
    }
    /*控制扭矩*/
    if (_outData.mCtlTorValid)
    {
        data = wrapFrame(UperCmdTypeGetCtlTor, _outData.mCtlTor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mCtlTorValid = false;
        }
    }
    /*画线扭矩*/
    if (_outData.mDrawTorValid)
    {
        data = wrapFrame(UperCmdTypeGetDrawTor, _outData.mDrawTor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mDrawTorValid = false;
        }
    }
    /*最大圈数*/
    if (_outData.mCycleMaxValid)
    {
        data = wrapFrame(UperCmdTypeGetCycleMax, _outData.mCycleMax);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mCycleMaxValid = false;
        }
    }
    /*时间日期*/
    if (_outData.mDateTimeValid)
    {
        data = wrapFrame(UperCmdTypeGetDateTime, _outData.mDateTime);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mDateTimeValid = false;
        }
    }
    /*杆号*/
    if (_outData.mPipeNoValid)
    {
        data = wrapFrame(UperCmdTypeGetPipeNo, _outData.mPipeNo);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mPipeNoValid = false;
        }
    }
    /*修正系数*/
    if (_outData.mCorrFactorValid)
    {
        data = wrapFrame(UperCmdTypeGetCorrFactor, _outData.mCorrFactor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mCorrFactorValid = false;
        }
    }
    /*延迟时间*/
    if (_outData.mDelayTimeValid)
    {
        data = wrapFrame(UperCmdTypeGetDelayTime, _outData.mDelayTime);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mDelayTimeValid = false;
        }
    }
    /*井号*/
    if (_outData.mWellNoValid)
    {
        data = wrapFrame(UperCmdTypeGetWellNo, _outData.mWellNo);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mWellNoValid = false;
        }
    }
    /*附加的ID*/
    if (_outData.mAddIDValid)
    {
        data = wrapFrame(UperCmdTypeGetAddNo, _outData.mAddID);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mAddIDValid = false;
        }
    }
    /*获取钳臂长，新增 2018-1-5*/
    if (_outData.mTongArmLenValid)
    {
        data = wrapFrame(UperCmdTypeGetTongArmLen, _outData.mTongArmLen);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mTongArmLenValid = false;
        }
    }
    /*响应的控制扭矩*/
    if (_outData.mSetCtlTorValid)
    {
        data = wrapFrame(UperCmdTypeSetCtlTor, _outData.mSetCtlTor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetCtlTorValid = false;
        }
    }
    /*响应的画线扭矩*/
    if (_outData.mSetDrawTorValid)
    {
        data = wrapFrame(UperCmdTypeSetDrawTor, _outData.mSetDrawTor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetDrawTorValid = false;
        }
    }
    /*响应的圈数最大值*/
    if (_outData.mSetCycleMaxValid)
    {
        data = wrapFrame(UperCmdTypeSetCycleMax, _outData.mSetCycleMax);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetCycleMaxValid = false;
        }
    }
    /*响应的日期时间*/
    if (_outData.mSetDateTimeValid)
    {
        data = wrapFrame(UperCmdTypeSetDateTime, _outData.mSetDateTime);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetDateTimeValid = false;
        }
    }
    /*响应的套管编号*/
    if (_outData.mSetPipeNoValid)
    {
        data = wrapFrame(UperCmdTypeSetPipeNo, _outData.mSetPipeNo);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetPipeNoValid = false;
        }
    }
    /*响应的修正系数*/
    if (_outData.mSetCorrFactorValid)
    {
        data = wrapFrame(UperCmdTypeSetCorrFactor, _outData.mSetCorrFactor);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetCorrFactorValid = false;
        }
    }
    /*响应的延迟时间*/
    if (_outData.mSetDelayTimeValid)
    {
        data = wrapFrame(UperCmdTypeSetDelayTime, _outData.mSetDelayTime);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetDelayTimeValid = false;
        }
    }
    /*响应的井号*/
    if (_outData.mSetWellNoValid)
    {
        data = wrapFrame(UperCmdTypeSetWellNo, _outData.mSetWellNo);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetWellNoValid = false;
        }
    }
    /*附加的ID*/
    if (_outData.mSetAddIDValid)
    {
        data = wrapFrame(UperCmdTypeSetAddNo, _outData.mSetAddID);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetAddIDValid = false;
        }
    }
    /*设置的钳臂长,新增 2018-1-5*/
    if (_outData.mSetTongArmLenValid)
    {
        data = wrapFrame(UperCmdTypeSetTongArmLen, _outData.mSetTongArmLen);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetTongArmLenValid = false;
        }
    }
    /*设置的控制模式，新增 2018-1-5*/
    if (_outData.mSetCtlModeValid)
    {
        data = wrapFrame(UperCmdTypeSetCtlMode, _outData.mSetCtlMode);
        if (data.size() == _io->wrtData(data))
        {
            /*如果写数据成功，则置该数据无效（代表后续不用继续发送）*/
            _outData.mSetCtlModeValid = false;
        }
    }
    /*增加所有待发数据的次数，如果连续10帧都未发送成功，则停止继续发送*/
    _outData.mCommTypeUnpdateNum += 1;
    _outData.mCtlTorUnUpdateNum += 1;
    _outData.mDrawTorUnUpdateNum += 1;
    _outData.mCycleMaxUnUpdateNum += 1;
    _outData.mDateTimeUnUpdateNum += 1;
    _outData.mPipeNoUnUpdateNum += 1;
    _outData.mCorrFactorUnUpdateNum += 1;
    _outData.mDelayTimeUnUpdateNum += 1;
    _outData.mWellNoUnUpdateNum += 1;
    _outData.mAddIDUnUpdateNum += 1;
    _outData.mTongArmLenUnUpdateNum += 1;/*获取钳臂长 未更新次数，新增 2018-1-5*/

    _outData.mSetCtlTorUnUpdateNum += 1;
    _outData.mSetDrawTorUnUpdateNum += 1;
    _outData.mSetCycleMaxUnUpdateNum += 1;
    _outData.mSetDateTimeUnUpdateNum += 1;
    _outData.mSetPipeNoUnUpdateNum += 1;
    _outData.mSetCorrFactorUnUpdateNum += 1;
    _outData.mSetDelaytTimeUnUpdateNum += 1;
    _outData.mSetWellUnUpdateNum += 1;
    _outData.mSetAddIDUnUpdateNum += 1;
    _outData.mSetTongArmLenUnUpdateNum += 1; /*设置钳臂长 未更新次数，新增 2018-1-5*/
    _outData.mSetCtlModeUnUpdateNum += 1;/*设置的控制模式 未更新次数，新增 2018-1-5*/

    if (_outData.mCommTypeUnpdateNum >= 10) _outData.mCommTypeValid = false;
    if (_outData.mCtlTorUnUpdateNum >= 10) _outData.mCtlTorValid = false;
    if (_outData.mDrawTorUnUpdateNum >= 10) _outData.mDrawTorValid = false;
    if (_outData.mCycleMaxUnUpdateNum >= 10) _outData.mCycleMaxValid = false;
    if (_outData.mDateTimeUnUpdateNum >= 10) _outData.mDateTimeValid = false;
    if (_outData.mPipeNoUnUpdateNum >= 10) _outData.mPipeNoValid = false;
    if (_outData.mCorrFactorUnUpdateNum >= 10) _outData.mCorrFactorValid = false;
    if (_outData.mDelayTimeUnUpdateNum >= 10) _outData.mDelayTimeValid = false;
    if (_outData.mWellNoUnUpdateNum >= 10) _outData.mWellNoValid = false;
    if (_outData.mAddIDUnUpdateNum >= 10) _outData.mAddIDValid = false;
    if (_outData.mTongArmLenUnUpdateNum >= 10) _outData.mTongArmLenValid = false;/*获取钳臂长 有效性，新增 2018-1-5*/

    if (_outData.mSetCtlTorUnUpdateNum >= 10) _outData.mSetCtlTorValid = false;
    if (_outData.mSetDrawTorUnUpdateNum >= 10) _outData.mSetDrawTorValid = false;
    if (_outData.mSetCycleMaxUnUpdateNum >= 10) _outData.mSetCycleMaxValid = false;
    if (_outData.mSetDateTimeUnUpdateNum >= 10) _outData.mSetDateTimeValid = false;
    if (_outData.mSetPipeNoUnUpdateNum >= 10) _outData.mSetPipeNoValid = false;
    if (_outData.mSetCorrFactorUnUpdateNum >= 10) _outData.mSetCorrFactorValid = false;
    if (_outData.mSetDelaytTimeUnUpdateNum >= 10) _outData.mSetDelayTimeValid = false;
    if (_outData.mSetWellUnUpdateNum >= 10) _outData.mSetWellNoValid = false;
    if (_outData.mSetCycleMaxUnUpdateNum >= 10) _outData.mSetCycleMaxValid = false;
    if (_outData.mSetAddIDUnUpdateNum >= 10) _outData.mSetAddIDValid = false;
    if (_outData.mSetTongArmLenUnUpdateNum >= 10) _outData.mSetTongArmLenValid = false;/*设置钳臂长 有效性，新增 2018-1-5*/
    if (_outData.mSetCtlModeUnUpdateNum >= 10) _outData.mSetCtlModeValid = false;/*设置的控制模式 有效性，新增 2018-1-5*/
    _outLock.unlock();
}

void UperIcdRelover::cycleHandleOtherMission()
{
    handleConn();
}

void UperIcdRelover::handleConn()
{
    GlobalData* global = GlobalData::getInstance();
    if (_connCount > 0)
    {
        _connCount -= 1;
        /*依次判断每个候选连接，判断是否收到数据*/
        for (SerialComm* serial: _candiList)
        {
            QByteArray datas = serial->rcvData();
            if (datas.length() >= 8&&
                    (unsigned char)(datas.at(0)) == 0xaa)
            {
                /*建立起了正常连接*/
                if (_io != 0)
                {
                    _io->disConn();
                    delete _io;
                }
                _io = serial;
                _candiList.removeOne(serial);   /*从候选列表中移除该连接*/
                _connStatus = ConnStatusConnOk; /*连接成功*/
                qDebug()<<"Connect Success and the rcv data is: "<<datas;
                global->writeLog("Connect Success and the rcv data is:" + datas.toHex());
                break;
            }
        }
        /*如果已经成功建立连接，或者连接计数为0，则删除候选项*/
        if (_connStatus == ConnStatusConnOk||
                _connCount == 0)
        {
            /*连接成功，则删除候选连接,并清空连接计数*/
            for (SerialComm* serial: _candiList)
            {
                if (serial != 0)
                {
                    serial->disConn();
                    delete serial;
                    qDebug()<<"Remove the serial";
                }
            }
            _connCount = 0;
            if (_connStatus != ConnStatusConnOk) /*如果此时还未连接成功，则设置连接失败*/
            {
                _connStatus = ConnStatusUnConn;
                qDebug()<<"Failed to conn";
                global->writeLog("Failed to conn");
            }
        }
    }
}

void UperIcdRelover::initDataSet()
{
    _rawBuf.clear();
    memset(&_inData, 0, sizeof(_inData));
    memset(&_outData, 0, sizeof(_outData));
    _cyleTimeMs = 20;/*设置每个循环周期为20ms*/
    _connStatus = ConnStatusUnKnown;
}

QByteArray UperIcdRelover::wrapFrame(UperCmdType cmd, qint32 payLoad)
{
    /*封装待发送的数据*/
    /*
     * 第一个字节 0xAA,第二个字节 type,第三~七个字节 payLoad 第八个字节 ckcSum
    */
    QByteArray data;
    data.append((char)0xaa);
    data.append((char)cmd);
    payLoad = qToLittleEndian(payLoad);
    data.append((char*)&payLoad, sizeof(qint32));
    data.append((char)0);
    unsigned char chcSum  = 0;
    for(int i = 0; i < data.length(); ++i)
    {
        chcSum += (unsigned char)data.at(i);
    }
    data.append(chcSum);
    return data;
}
