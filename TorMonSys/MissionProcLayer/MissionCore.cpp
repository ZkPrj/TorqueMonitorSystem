#include "MissionCore.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTimer>
#include <QtMath>
#include "GlobalData.h"

MissionCore::MissionCore(QObject *parent) : QObject(parent)
{
    readAndParseCfgFile();
    _db = DbOper::getDbOper();

    _startTorMonitor = false;
    _dataWraper = new DataWraper;
    _commType = -1;
    _loopT = 50;    /*50ms循环一次定时器*/
    initUperData();
    startTimer(_loopT);
}

bool MissionCore::getUpConnStatus()
{
    /*True - 正常连接，False - 未建立连接*/
    ConnStatusType status = _dataWraper->getUperStatus();
    if (status == ConnStatusConnOk)
        return true;
    else
    {
        if (status != ConnStatusConnecting) _dataWraper->conn2UperTranser();
        return false;
    }
}

bool MissionCore::getLowerConnStatus()
{
    ConnStatusType status = _dataWraper->getLowerStatus();
    if (status == ConnStatusConnOk)
        return true;
    else
    {
        if (status != ConnStatusConnecting) _dataWraper->conn2LowerTranser();
        return false;
    }
}


void MissionCore::reqUperDefaultArgs()
{
    if (_dataWraper)
    {
        /*请求附加的ID*/
        _dataWraper->setUperData(UperCmdTypeGetAddNo, 0);
        /*请求下位机控制扭矩*/
        _dataWraper->setUperData(UperCmdTypeGetCtlTor, 0);
        /*请求画线扭矩*/
        _dataWraper->setUperData(UperCmdTypeGetDrawTor, 0);
        /*请求下位机圈数最大值*/
        _dataWraper->setUperData(UperCmdTypeGetCycleMax, 0);
        /*请求下位机时间*/
        _dataWraper->setUperData(UperCmdTypeGetDateTime, 0);
        /*请求下位机杆号*/
        _dataWraper->setUperData(UperCmdTypeGetPipeNo, 0);
        /*请求下位机修正系数*/
        _dataWraper->setUperData(UperCmdTypeGetCorrFactor, 0);
        /*请求下位机延迟时间*/
        _dataWraper->setUperData(UperCmdTypeGetDelayTime, 0);
        /*请求下位机井号*/
        _dataWraper->setUperData(UperCmdTypeGetWellNo, 0);
    }
}

QString MissionCore::getDeleComp()
{
    return _manageData[0].mDelegateComp;
}

QString MissionCore::getExeComp()
{
    return _manageData[0].mExeComp;
}

QString MissionCore::getCollComp()
{
    return _manageData[0].mCollabComp;
}

QString MissionCore::getMachineNo()
{
    return _manageData[0].mMachinNo;
}

QString MissionCore::getHydClamp()
{
    return _manageData[0].mHydClamp;
}

QString MissionCore::getAreaNo()
{
    return _manageData[0].mAreaNo;
}

QString MissionCore::getWellNo()
{
    return _manageData[0].mWellNo;
}

QString MissionCore::getOwnerSuper()
{
    return _manageData[0].mOwnerSuper;
}

QString MissionCore::getTechDir()
{
    return _manageData[0].mTechDir;
}

QString MissionCore::getRemark()
{
    return _manageData[0].mRemark;
}

QString MissionCore::getPipeName()
{
    return _manageData[0].mPipeName;
}

QString MissionCore::getPipType()
{
    return _manageData[0].mPipeType;
}

QString MissionCore::getPipeDiameter()
{
    return _manageData[0].mPipeDiameter;
}

QString MissionCore::getPipeClass()
{
    return _manageData[0].mPipeClass;
}

QString MissionCore::getPipeThinkness()
{
    return _manageData[0].mPipeThickness;
}

qreal MissionCore::getTongArmLen()
{
    return _manageData[0].mTongArmLen;
}

qreal MissionCore::getCorrFactor()
{
    return _manageData[0].mCorrFactor;
}

qreal MissionCore::getDelayTime()
{
    return _manageData[0].mDelayTime;
}

qreal MissionCore::getMinStep()
{
    return _manageData[0].mMinStep;
}

qreal MissionCore::getMaxStep()
{
    return _manageData[0].mMaxStep;
}

qreal MissionCore::getMaxTor()
{
    return _manageData[0].mMaxTor;
}

qreal MissionCore::getMinTor()
{
    return _manageData[0].mMinTor;
}

qreal MissionCore::getBestTor()
{
    return _manageData[0].mBestTor;
}

qreal MissionCore::getCtlTor()
{
    return _ctlTor[0] * _manageData[0].mTongArmLen;/*实际的扭矩为：力*套管长度，接收到的数据为力*/
}

qreal MissionCore::getDrawTor()
{
    return _drawTor[0] * _manageData[0].mTongArmLen;/*实际的扭矩为：力*套管长度，接收到的数据为力*/
}

qreal MissionCore::getMaxTime()
{
    return _manageData[0].mMaxTime;
}

qreal MissionCore::getMaxCycle()
{
    return _manageData[0].mMaxCycle;
}

QDateTime MissionCore::getDateTime()
{
    return QDateTime::currentDateTime().addSecs(-1*_dateTime[0]);
}

quint32 MissionCore::getPipeNo()
{
    return _pipeNo[0];
}

void MissionCore::setDeleComp(QString str)
{
    _manageData[1].mDelegateComp = str;
}

void MissionCore::setExeComp(QString str)
{
    _manageData[1].mExeComp = str;
}

void MissionCore::setCollComp(QString str)
{
    _manageData[1].mCollabComp = str;
}

void MissionCore::setMachineNo(QString str)
{
    _manageData[1].mMachinNo = str;
}

void MissionCore::setHydClamp(QString str)
{
    _manageData[1].mHydClamp = str;
}

void MissionCore::setAreaNo(QString str)
{
    _manageData[1].mAreaNo = str;
}

void MissionCore::setWellNo(QString str)
{
    _manageData[1].mWellNo = str;
    _wellNo[1] = str.toInt();
}

void MissionCore::setOwnerSuper(QString str)
{
    _manageData[1].mOwnerSuper = str;
}

void MissionCore::setTechDir(QString str)
{
    _manageData[1].mTechDir = str;
}

void MissionCore::setRemark(QString str)
{
    _manageData[1].mRemark = str;
}

void MissionCore::setPipeName(QString str)
{
    _manageData[1].mPipeName = str;
}

void MissionCore::setPipeType(QString str)
{
    _manageData[1].mPipeType = str;
}

void MissionCore::setPipeDiameter(QString str)
{
    _manageData[1].mPipeDiameter = str;
}

void MissionCore::setPipeClass(QString str)
{
    _manageData[1].mPipeClass = str;
}

void MissionCore::setPipeThinkness(QString str)
{
    _manageData[1].mPipeThickness = str;
}

void MissionCore::setTongArmLen(qreal data)
{
    _manageData[1].mTongArmLen = data;
}

void MissionCore::setCorrFactor(qreal data)
{
    _manageData[1].mCorrFactor = data;
    _corrFactor[1] = data;
}

void MissionCore::setDelayTime(qreal data)
{
    _manageData[1].mDelayTime = data;
    _delayTime[1] = data;
}

void MissionCore::setMinStep(qreal data)
{
    _manageData[1].mMinStep = data;
}

void MissionCore::setMaxStep(qreal data)
{
    _manageData[1].mMaxStep = data;
}

void MissionCore::setMaxTor(qreal data)
{
    _manageData[1].mMaxTor = data;

}

void MissionCore::setMinTor(qreal data)
{
    _manageData[1].mMinTor = data;
}

void MissionCore::setBestTor(qreal data)
{
    _manageData[1].mBestTor = data;
}

void MissionCore::setCtlTor(qreal data)
{
    _manageData[1].mCtlTor = data;
    _ctlTor[1] = data;
}

void MissionCore::setDrawTor(qreal data)
{
    _manageData[1].mDrawTor = data;
    _drawTor[1] = data;
}

void MissionCore::setMaxTime(qreal data)
{
    _manageData[1].mMaxTime = data;
}

void MissionCore::setMaxCycle(qreal data)
{
    _manageData[1].mMaxCycle =data;
    _cycleMax[1] = data;
}

void MissionCore::setDateTime(QDateTime data)
{
    _dateTime[1] = data.secsTo(QDateTime::currentDateTime());
}

void MissionCore::setPipeNo(quint32 data)
{
    _pipeNo[1] = data;
}

void MissionCore::updateTorSysArg()
{
    quint32 manageId = 0, pipId = 0, techId = 0, dispId = 0, idIndexId = _addId[0];
    quint32 oldManageId = 0, oldDspId = 0, oldPipId = 0, oldTechId = 0;
    _db->getIdByAddId(idIndexId, oldManageId, oldDspId, oldPipId, oldTechId);
    manageId = oldManageId;
    pipId = oldPipId;
    techId = oldTechId;
    dispId = oldDspId;
    /*这里需要单独赋值，因为有两个地方可以查询到*/
    _manageData[0].mDrawTor = _drawTor[0];
    _manageData[0].mCtlTor = _ctlTor[0];
    /*任意一个参数进行了修改，则需要更新ADDid，并更新数据库,以及发送给上位机收发器*/
    /*管理参数*/
    if (QString::compare(_manageData[0].mCollabComp, _manageData[1].mCollabComp)||
            QString::compare(_manageData[0].mDelegateComp, _manageData[1].mDelegateComp)||
            QString::compare(_manageData[0].mExeComp, _manageData[1].mExeComp)||
            QString::compare(_manageData[0].mMachinNo, _manageData[1].mMachinNo)||
            QString::compare(_manageData[0].mHydClamp, _manageData[1].mHydClamp)||
            QString::compare(_manageData[0].mAreaNo, _manageData[1].mAreaNo)||
            QString::compare(_manageData[0].mWellNo, _manageData[1].mWellNo)||
            QString::compare(_manageData[0].mOwnerSuper, _manageData[1].mOwnerSuper)||
            QString::compare(_manageData[0].mTechDir, _manageData[1].mTechDir)||
            QString::compare(_manageData[0].mRemark, _manageData[1].mRemark))
     {
         manageId = _db->getMaxManageId();
         manageId = (manageId + 1)%4294967296;  /*其中4294967295为UInt3的最大值*/
         _db->insertManageData(manageId, _manageData[1].mDelegateComp,
                 _manageData[1].mExeComp, _manageData[1].mCollabComp,
                 _manageData[1].mMachinNo, _manageData[1].mHydClamp,
                 _manageData[1].mAreaNo, _manageData[1].mWellNo,
                 _manageData[1].mOwnerSuper, _manageData[1].mTechDir,
                 _manageData[1].mRemark);
    }
    /*套管参数*/
    if (QString::compare(_manageData[0].mPipeName, _manageData[1].mPipeName)||
            QString::compare(_manageData[0].mPipeType, _manageData[1].mPipeType)||
            QString::compare(_manageData[0].mPipeDiameter, _manageData[1].mPipeDiameter)||
            QString::compare(_manageData[0].mPipeClass, _manageData[1].mPipeClass)||
            QString::compare(_manageData[0].mPipeThickness, _manageData[1].mPipeThickness))
    {
        pipId = _db->getMaxPipeId();
        pipId = (pipId + 1)%4294967296;
        _db->insertPipeData(pipId, _manageData[1].mPipeName,
                _manageData[1].mPipeType, _manageData[1].mPipeDiameter,
                _manageData[1].mPipeClass, _manageData[1].mPipeThickness);
    }
    /*技术参数*/
    if (qFabs(_manageData[0].mTongArmLen - _manageData[1].mTongArmLen) > 0.05||
            qFabs(_manageData[0].mCorrFactor - _manageData[1].mCorrFactor) > 0.05||
            qFabs(_manageData[0].mDelayTime - _manageData[1].mDelayTime) > 0.05||
            qFabs(_manageData[0].mMinStep - _manageData[1].mMinStep) > 0.05||
            qFabs(_manageData[0].mMaxStep - _manageData[1].mMaxStep) > 0.05)
    {
        techId = _db->getMaxTechId();
        techId = (techId + 1)%4294967296;
        _db->insertTechData(techId, _manageData[1].mTongArmLen,
                _manageData[1].mCorrFactor, _manageData[1].mDelayTime,
                _manageData[1].mMinStep, _manageData[1].mMaxStep);
    }
    /*显示参数*/
    if (qFabs(_manageData[0].mMaxTor - _manageData[1].mMaxTor) > 0.05||
            qFabs(_manageData[0].mMinTor - _manageData[1].mMinTor) > 0.05||
            qFabs(_manageData[0].mBestTor - _manageData[1].mBestTor) > 0.05||
            qFabs(_manageData[0].mCtlTor*_manageData[0].mTongArmLen - _manageData[1].mCtlTor) > 0.05||
            qFabs(_manageData[0].mDrawTor*_manageData[0].mTongArmLen - _manageData[1].mDrawTor) > 0.05||
            qFabs(_manageData[0].mMaxTime - _manageData[1].mMaxTime) > 0.05||
            qFabs(_manageData[0].mMaxCycle - _manageData[1].mMaxCycle) > 0.05)
    {
        dispId = _db->getMaxDspId();
        dispId = (dispId + 1)%4294967296;
        _db->insertDspData(dispId, _manageData[1].mMaxTor,
                _manageData[1].mMinTor, _manageData[1].mBestTor,
                _manageData[1].mCtlTor, _manageData[1].mDrawTor,
                (qint32)_manageData[1].mMaxTime, (qint32)_manageData[1].mMaxCycle);
    }
    /*更新ID*/
    if (manageId != oldManageId||
            pipId != oldManageId||
            dispId != oldDspId||
            techId != oldTechId)/*说明有新的改动*/
    {
        idIndexId = _db->getMaxIdIndexId();
        idIndexId = (idIndexId + 1)%4294967296;
        _db->insertId(idIndexId, manageId, techId, pipId, dispId);
        /*发送参数到上位机收发器*/
        _dataWraper->setUperData(UperCmdTypeSetAddNo, idIndexId);
    }
    /*更新控制扭矩*/
    if (qFabs(_ctlTor[0] - _ctlTor[1]/_manageData[1].mTongArmLen)>=1)
    {
        if (_manageData[1].mTongArmLen >= 0.01)
            _dataWraper->setUperData(UperCmdTypeSetCtlTor, (quint32)(_ctlTor[1]/_manageData[1].mTongArmLen));/*实际发送的为力*/
    }
    /*更新画线扭矩*/
    if (qFabs(_drawTor[0] - _drawTor[1]/_manageData[1].mTongArmLen)>=1)
    {
        if (_manageData[1].mTongArmLen >= 0.01)
            _dataWraper->setUperData(UperCmdTypeSetDrawTor, (quint32)(_drawTor[1]/_manageData[1].mTongArmLen));/*实际发送的为力*/
    }
    /*更新圈数最大值*/
    if (_cycleMax[0] != _cycleMax[1])
    {
        _dataWraper->setUperData(UperCmdTypeSetCycleMax, _cycleMax[1]);
    }
    /*更新下位机时间*/
    if (qAbs(_dateTime[0] - _dateTime[1]) > 30)/*时间相差大于30s*/
    {
        _dataWraper->setUperData(UperCmdTypeSetDateTime, QDateTime::currentDateTime().addSecs(-1*_dateTime[1]).toTime_t());
    }
    /*更新下位机杆号*/
    if (_pipeNo[0] != _pipeNo[1])
    {
        _dataWraper->setUperData(UperCmdTypeSetPipeNo, _pipeNo[1]);
    }
    /*更新下位机修正系数*/
    if (qFabs(_corrFactor[0] - _corrFactor[1])>0.05)
    {
        _dataWraper->setUperData(UperCmdTypeSetCorrFactor, (quint32)(qFloor(_corrFactor[1] * 10 + 0.5)));
    }
    /*更新下位机延迟时间*/
    if (qFabs(_delayTime[0] - _delayTime[1]) > 0.05)
    {
        _dataWraper->setUperData(UperCmdTypeSetDelayTime, _delayTime[1]);
    }
    /*更新下位机井号*/
    if (_wellNo[0] != _wellNo[1])
    {
        _dataWraper->setUperData(UperCmdTypeSetWellNo, _wellNo[1]);
    }
}

void MissionCore::startTorMonitor()
{
    _startTorMonitor = true;
}

QList<TorRtDataStruct> MissionCore::getPipeTorList(quint32 wellNo, quint32 pipeNo)
{
    return _db->searchTorData(wellNo, pipeNo);
}

QList<TorRtDataStruct> MissionCore::getCurPipeTorList()
{
    return _curPipeTorList;
}

QList<TorRtDataStruct> MissionCore::getPipeTorList(quint32 pipeIndex)
{
    return getPipeTorList(_wellNo[0], pipeIndex);
}

void MissionCore::setCommType(int i)
{
    if (_dataWraper)
    {
        _dataWraper->setUperData(UperCmdTypeCommType, i);
    }
}

int MissionCore::getCommType()
{
    /*
     * 注意：设置了通信类型后，一定要在0.5s内获取通信类型，
     * 否则从上位机收发器获取到的数据会由于数据长时间未更新而设置该数据无效
    */
    return _commType;
}


void MissionCore::getArgsFromUpTrans()
{
    InUperTransceiverDataSet data;
}

void MissionCore::setArgs2UpTrans()
{

}

void MissionCore::getCurTorFromUpTrans()
{

}

void MissionCore::readAndParseCfgFile()
{
    QFile cfg("c:/cfg.dat");
    cfg.open(QIODevice::ReadOnly);
    QByteArray cfgData = cfg.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(cfgData);
    QJsonObject jsonDoc = doc.object();
    GlobalData::cfgCtx.mUpTransPort = jsonDoc["UperPort"].toInt();
    GlobalData::cfgCtx.mLowerTransPort = jsonDoc["LowerPort"].toInt();
    GlobalData::cfgCtx.mUperMaxConnTimeOut = jsonDoc["UperTimeOut"].toInt();
    GlobalData::cfgCtx.mLowerMaxConnTimeOut = jsonDoc["LowerTimeOut"].toInt();
    GlobalData::cfgCtx.mUpTransParity = jsonDoc["UperParity"].toInt();
    GlobalData::cfgCtx.mUpTransDataBits = jsonDoc["UperDataBit"].toInt();
    GlobalData::cfgCtx.mUpTransStopBits = jsonDoc["UperStopBit"].toInt();
    GlobalData::cfgCtx.mUpTransFlowCtl = jsonDoc["UperFlowCtl"].toInt();
    GlobalData::cfgCtx.mLowerTransParity = jsonDoc["LowerParity"].toInt();
    GlobalData::cfgCtx.mLowerTransDataBits = jsonDoc["LowerDataBit"].toInt();
    GlobalData::cfgCtx.mLowerTransStopBits = jsonDoc["LowerStopBit"].toInt();
    GlobalData::cfgCtx.mLowerTransFlowCtl = jsonDoc["LowerFlowCtl"].toInt();
}

void MissionCore::searchAddArg(int id)
{

}

void MissionCore::handleUperData()
{
    /*周期性的获取底层的数据*/
    InUperTransceiverDataSet uperData = _dataWraper->getUperData();
    if (uperData.mCommTypeValid)
    {
        _commType = (qint32)uperData.mCommType;
    }
    /*获取附加的ID*/
    if (uperData.mAddNoValid)
    {
        /*查询数据库，获取相应的参数*/
       _addId[0] = uperData.mAddNo;
       _manageData[0] = _db->searchAddtionalData(uperData.mAddNo);
    }
    if (uperData.mEchoAddIDValid)
    {
        _addId[0] = uperData.mEchoAddID;
        _manageData[0] = _db->searchAddtionalData(uperData.mEchoAddID);
    }
    /*控制扭矩*/
    if (uperData.mCtlTorValid)
    {
        _ctlTor[0] = uperData.mCtlTor;
        _manageData[0].mCtlTor = uperData.mCtlTor;
    }
    if (uperData.mEchoCtlTorValid)
    {
        _ctlTor[0] = uperData.mEchoCtlTor;
        _manageData[0].mCtlTor = uperData.mEchoCtlTor;
    }
    /*画线扭矩*/
    if (uperData.mDrawTorValid)
    {
        _drawTor[0] = uperData.mDrawTor;
        _manageData[0].mDrawTor = uperData.mDrawTor;
    }
    if (uperData.mEchoDrawTorValid)
    {
        _drawTor[0] = uperData.mEchoDrawTor;
        _manageData[0].mDrawTor = uperData.mEchoDrawTor;
    }
    /*圈数的最大值*/
    if (uperData.mCycleMaxValid)
    {
        _cycleMax[0] = uperData.mCycleMax;
    }
    if (uperData.mEchoCycleMaxValid)
    {
        _cycleMax[0] = uperData.mEchoCycleMax;
    }
    /*下位机时间*/
    if (uperData.mDateTimeValid)
    {
        _dateTime[0] = (qint32)QDateTime::fromTime_t(uperData.mDateTime).secsTo(QDateTime::currentDateTime());
        _startTime = QDateTime::currentDateTime().addSecs(-1*_dateTime[0]);
    }
    if (uperData.mEchoDateTimeValid)
    {
        _dateTime[0] = (qint32)QDateTime::fromTime_t(uperData.mEchoDateTime).secsTo(QDateTime::currentDateTime());
        _startTime = QDateTime::currentDateTime().addSecs(-1*_dateTime[0]);
    }
    /*下位机杆号*/
    if (uperData.mPipeNoValid)
    {
        _pipeNo[0] = uperData.mPipeNo;
    }
    if (uperData.mEchoPipeNoValid)
    {
        _pipeNo[0] = uperData.mEchoPipeNo;
    }
    /*修正系数*/
    if (uperData.mCorrFactorValid)
    {
        _corrFactor[0] = uperData.mEchoCorrFactor/10.0;;/*实际的修正系数 = 下位存的修正系数/10.0*/
    }
    if (uperData.mEchoCorrFactorValid)
    {
        _corrFactor[0] = uperData.mEchoCorrFactor/10.0;/*实际的修正系数 = 下位存的修正系数/10.0*/
    }
    /*延迟时间*/
    if (uperData.mDelayTimeValid)
    {
        _delayTime[0] = uperData.mDelayTime;
    }
    if (uperData.mEchoDelayTimeValid)
    {
        _delayTime[0] = uperData.mEchoDelayTime;
    }
    /*下位机井号*/
    if (uperData.mWellNoValid)
    {
        _wellNo[0] = uperData.mWellNo;
    }
    if (uperData.mEchoWellNoValid)
    {
        _wellNo[0] = uperData.mEchoWellNo;
    }
    if(uperData.mCurPipeValid&&uperData.mCycleNumValid&&uperData.mCurTorValid)
    {
        if (!_startTorMonitor) return ;
        if (_curTorRtData.mPipeNo != uperData.curPipe)
        {
            /*插入到数据库中*/
            if (_curPipeTorList.length() > 0)
            {
                _db->deleteRtTorPipeData(_curPipeTorList[0].mWellNo, _curPipeTorList[0].mPipeNo);
                _db->insertTorPipCycleList(_curPipeTorList);
            }
            /*清空缓冲区，并设置起始时间*/
            _startTime = QDateTime::currentDateTime().addSecs(-1*_dateTime[0]);
            _curPipeTorList.clear();
        }
        _curTorRtData.mTimeSpan = _startTime.msecsTo(QDateTime::currentDateTime().addSecs(-1*_dateTime[0]));
        _curTorRtData.mStartTime = _startTime.toTime_t();
        _curTorRtData.mPipeNo = uperData.curPipe;
        _curTorRtData.mAddId = _addId[0];
        _curTorRtData.mRtCycle = uperData.mCycleNum/10.0;/*实际的圈数应为收到的圈数的1/10*/
        _curTorRtData.mRtTor = uperData.mCurTor * _manageData[0].mTongArmLen;/*实际的扭矩应为：收到的扭矩*套管长度,修正系数呢?*/
        _curTorRtData.mWellNo = _manageData[0].mWellNo.toUInt();
        _curPipeTorList.append(_curTorRtData);
    }
}


void MissionCore::initUperData()
{
    for (int i = 0; i < 2; ++i)
    {
        _manageData[i].mDelegateComp = "";
        _manageData[i].mExeComp = "";
        _manageData[i].mCollabComp = "";
        _manageData[i].mMachinNo = "";
        _manageData[i].mHydClamp = "";
        _manageData[i].mAreaNo = "";
        _manageData[i].mWellNo = "";
        _manageData[i].mOwnerSuper = "";
        _manageData[i].mTechDir = "";
        _manageData[i].mRemark = "";
        _manageData[i].mPipeName = "";
        _manageData[i].mPipeType = "";
        _manageData[i].mPipeDiameter = "";
        _manageData[i].mPipeClass = "";
        _manageData[i].mPipeThickness = "";
        _manageData[i].mTongArmLen = 0;
        _manageData[i].mCorrFactor = 0;
        _manageData[i].mDelayTime = 0;
        _manageData[i].mMinStep = 0;
        _manageData[i].mMaxStep = 0;
        _manageData[i].mMaxTor = 0;
        _manageData[i].mMinTor = 0;
        _manageData[i].mBestTor = 0;
        _manageData[i].mCtlTor = 0;
        _manageData[i].mDrawTor = 0;
        _manageData[i].mMaxTime = 0;
        _manageData[i].mMaxCycle = 0;
        _ctlTor[i] = 0;
        _drawTor[i] = 0;
        _cycleMax[i] = 0;
        _dateTime[i] = 0;
        _pipeNo[i] = 0;
        _corrFactor[i] = 1.0;
        _delayTime[i] = 0;
        _wellNo[i] = 0;
        _addId[i] = 0;
    }

}

void MissionCore::timerEvent(QTimerEvent *event)
{
    /*
     * 1个周期处理一次上位机收发器发送过来的数据
     * 20个周期往下位机请求一次时间（已禁用）
    */
    static int i = 0;
    i = (i + 1)%20;
    handleUperData();
    /*请求时间*/
    if (i % 20 == 0)
    {
        /*请求下位机时间*//*这样会降低下位机工作效率*/
        //_dataWraper->setUperData(UperCmdTypeGetDateTime, 0);
    }
}


