#include "TorMonitorCore.h"
#include <QtMath>

TorMonitorCore::TorMonitorCore(QObject *parent) : QObject(parent)
{
    initDataSet();
    startTimer(100);
}

bool TorMonitorCore::getTorConnStatus()
{
    /*True - 正常连接， False - 未建立连接*/
    ConnStatusType status = _icd->getConnStatus();
    if (status == ConnStatusConnOk)
        return true;
    else
    {
        if (status != ConnStatusConnecting) _icd->conn2Edp();
        return false;
    }
}

void TorMonitorCore::setCommType(int i)
{
    SetArgDataSet data;
    data.mType = UperCmdTypeCommType;
    data.mPayLoad = i;
    _icd->setData(&data);
}

void TorMonitorCore::setCtlMode(int i)
{
    SetArgDataSet data;
    data.mType = UperCmdTypeSetCtlMode;
    data.mPayLoad = i;
    _icd->setData(&data);
}

void TorMonitorCore::setLowerCfgDs(LowerCfgDs cfg)
{
    quint32 manageId = 0, pipId = 0, techId = 0, dispId = 0, idIndexId = _lowerCfgData.mAddId;
    quint32 oldManageId = 0, oldDspId = 0, oldPipId = 0, oldTechId = 0;
    SetArgDataSet data;
    /*先获取之前的ID*/
    _db->getIdByAddId(idIndexId, oldManageId, oldDspId, oldPipId, oldTechId);
    manageId = oldManageId; /*设置当前ID的默认值为之前的ID*/
    pipId = oldPipId;
    techId = oldTechId;
    dispId = oldDspId;
    /*判断管理参数是否修改，如果修改了，则先更新数据库*/
    if (QString::compare(cfg.mCollabComp, _lowerCfgData.mCollabComp)||
            QString::compare(cfg.mDelegComp, _lowerCfgData.mDelegComp)||
            QString::compare(cfg.mExeComp, _lowerCfgData.mExeComp)||
            QString::compare(cfg.mMachinNo, _lowerCfgData.mMachinNo)||
            QString::compare(cfg.mHydClamp, _lowerCfgData.mHydClamp)||
            QString::compare(cfg.mAreaNo, _lowerCfgData.mAreaNo)||
            cfg.mWellNo != _lowerCfgData.mWellNo||
            QString::compare(cfg.mOwnerSuper, _lowerCfgData.mOwnerSuper)||
            QString::compare(cfg.mTechDir, _lowerCfgData.mTechDir)||
            QString::compare(cfg.mRemark, _lowerCfgData.mRemark))
    {
        manageId = _db->getMaxManageId();
        manageId = (manageId + 1)%4294967296;  /*其中4294967295为UInt3的最大值*/
        _db->insertManageData(manageId, cfg.mDelegComp,
                cfg.mExeComp, cfg.mCollabComp,
                cfg.mMachinNo, cfg.mHydClamp,
                cfg.mAreaNo, QString("%1").arg(cfg.mWellNo),
                cfg.mOwnerSuper, cfg.mTechDir,
                cfg.mRemark);
    }
    /*判断套管参数是否修改，如果修改了，则先更新数据库*/
    if (QString::compare(cfg.mPipeName, _lowerCfgData.mPipeName)||
            QString::compare(cfg.mPipeType, _lowerCfgData.mPipeType)||
            QString::compare(cfg.mPipeDiameter, _lowerCfgData.mPipeDiameter)||
            QString::compare(cfg.mPipeClass, _lowerCfgData.mPipeClass)||
            QString::compare(cfg.mPipeThickness,_lowerCfgData.mPipeThickness))
    {
        pipId = _db->getMaxPipeId();
        pipId = (pipId + 1)%4294967296;
        _db->insertPipeData(pipId, cfg.mPipeName,
                cfg.mPipeType, cfg.mPipeDiameter,
                cfg.mPipeClass, cfg.mPipeThickness);
    }
    /*判断技术参数是否修改，如果修改了，则先更新数据库*/
    /*接收到下位机的修正系数是实际的10倍*/
    /*钳臂长度*1000为发送给下位机的数据，新增 2018-1-7*/
    if (qFabs(cfg.mTongArmLen*1000 - _lowerCfgData.mTongArmLen) > 1||
            qFabs(cfg.mCorrFactor - _lowerCfgData.mCorrFactor/10.0) > 0.1||
            qFabs(cfg.mDelayTime - _lowerCfgData.mDelayTime) > 0.05||
            qFabs(cfg.mMinStep - _lowerCfgData.mMinStep) > 0.05||
            qFabs(cfg.mMaxStep - _lowerCfgData.mMaxStep) > 0.05)
    {
        techId = _db->getMaxTechId();
        techId = (techId + 1)%4294967296;
        _db->insertTechData(techId, cfg.mTongArmLen,
                cfg.mCorrFactor, cfg.mDelayTime,
                cfg.mMinStep, cfg.mMaxStep);
    }
    /*判断显示参数是否修改，如果修改了，则先更新数据库*/
    if (qFabs(cfg.mMaxTor - _lowerCfgData.mMaxTor) > 0.05||
            qFabs(cfg.mMinTor - _lowerCfgData.mMinTor) > 0.05||
            qFabs(cfg.mCtlTor - _lowerCfgData.mCtlTor*_lowerCfgData.mTongArmLen) >= 1||
            qFabs(cfg.mDrawTor - _lowerCfgData.mDrawTor*_lowerCfgData.mTongArmLen) >= 1||
            qFabs(cfg.mMaxTime - _lowerCfgData.mMaxTime) > 0.05||
            qFabs(cfg.mMaxCycle - _lowerCfgData.mMaxCycle) > 0.05)
    {
        dispId = _db->getMaxDspId();
        dispId = (dispId + 1)%4294967296;
        _db->insertDspData(dispId, cfg.mMaxTor,
                cfg.mMinTor, 0/*最佳扭矩*/,
                cfg.mCtlTor, cfg.mDrawTor,
                (qint32)cfg.mMaxTime, (qint32)cfg.mMaxCycle);
    }
    /*更新ID到数据库，并设置到下位机*/
    if (manageId != oldManageId||
            pipId != oldManageId||
            dispId != oldDspId||
            techId != oldTechId)/*说明有新的改动*/
    {
        idIndexId = _db->getMaxIdIndexId();
        idIndexId = (idIndexId + 1)%4294967296;
        _db->insertId(idIndexId, manageId, techId, pipId, dispId);
        /*发送ID到上位机收发器*/
        data.mType = UperCmdTypeSetAddNo;
        data.mPayLoad = idIndexId;
        _icd->setData(&data);
    }
    /*更新控制扭矩到下位机*/
    if (cfg.mTongArmLen >= 0.01&&
            qFabs(cfg.mCtlTor/cfg.mTongArmLen - _lowerCfgData.mCtlTor)>1)
    {
        data.mType = UperCmdTypeSetCtlTor;
        data.mPayLoad = (quint32)(cfg.mCtlTor/cfg.mTongArmLen + 0.5);    /*下位机存放的是力,需要除以臂长*/
        _icd->setData(&data);
    }
    /*更新画线扭矩到下位机*/
    if (cfg.mTongArmLen >= 0.01&&
            qFabs(cfg.mDrawTor/cfg.mTongArmLen - _lowerCfgData.mDrawTor)>1)
    {
        data.mType = UperCmdTypeSetDrawTor;
        data.mPayLoad = (quint32)(cfg.mDrawTor/cfg.mTongArmLen + 0.5);    /*下位机存放的是力,需要除以臂长*/
        _icd->setData(&data);
    }
    /*更新圈数最大值*/
    if (qFabs(cfg.mCycleMax - _lowerCfgData.mCycleMax) > 1)
    {
        data.mType = UperCmdTypeSetCycleMax;
        data.mPayLoad = (quint32)(cfg.mCycleMax + 0.5);
        _icd->setData(&data);
    }
    /*更新杆号*/
    if (cfg.mPipeNo != _lowerCfgData.mPipeNo)
    {
        data.mType = UperCmdTypeSetPipeNo;
        data.mPayLoad = (quint32)cfg.mPipeNo;
        _icd->setData(&data);
    }
    /*更新修正系数*/
    if (qFabs(cfg.mCorrFactor*10 - _lowerCfgData.mCorrFactor)>1)
    {
        data.mType = UperCmdTypeSetCorrFactor;
        data.mPayLoad = (quint32)(cfg.mCorrFactor*10 + 0.5);
        _icd->setData(&data);
    }
    /*更新下位机延迟时间*/
    if (cfg.mDelayTime != _lowerCfgData.mDelayTime)
    {
        data.mType = UperCmdTypeSetDelayTime;
        data.mPayLoad = cfg.mDelayTime;
        _icd->setData(&data);
    }
    /*更新井号*/
    if (cfg.mWellNo != _lowerCfgData.mWellNo)
    {
        data.mType = UperCmdTypeSetWellNo;
        data.mPayLoad = cfg.mWellNo;
        _icd->setData(&data);
    }
    /*更新下位机时间*/
    if (cfg.mLowerTime - _lowerCfgData.mLowerTime >= 30)/*时间最大允许相差30s*/
    {
        data.mType = UperCmdTypeSetDateTime;
        data.mPayLoad = cfg.mLowerTime;
        _icd->setData(&data);
    }
    /*更新钳臂长度,新增 2018-1-7*/
    if (qFabs(cfg.mTongArmLen*1000 - _lowerCfgData.mTongArmLen) > 1)
    {
        data.mType = UperCmdTypeSetTongArmLen;
        data.mPayLoad = (quint32)(cfg.mTongArmLen*1000 + 0.5);
        _icd->setData(&data);
    }
}

QList<TorRtDataStruct> TorMonitorCore::getCurPipeTorList()
{
    return _lowerRtList;
}

QList<TorRtDataStruct> TorMonitorCore::getSpePipeTorList(quint32 pipe)
{
    return _db->searchTorData(_lowerCfgData.mWellNo, pipe);
}

LowerCfgDs TorMonitorCore::getLowerCfgDs()
{
    return _lowerCfgData;
}

void TorMonitorCore::sndCfgReq2Lower()
{
    SetArgDataSet data;
    data.mPayLoad = 0;
    if (getTorConnStatus())//如果下位机处于正常连接状态,则发送请求
    {
        data.mType = UperCmdTypeGetAddNo;
        _icd->setData(&data);   /*获取附加ID*/
        data.mType = UperCmdTypeGetCtlTor;
        _icd->setData(&data);   /*获取控制扭矩*/
        data.mType = UperCmdTypeGetDrawTor;
        _icd->setData(&data);   /*获取画线扭矩*/
        data.mType = UperCmdTypeGetCycleMax;
        _icd->setData(&data);   /*获取圈数最大值*/
        data.mType = UperCmdTypeGetDateTime;
        _icd->setData(&data);   /*获取日期时间*/
        data.mType = UperCmdTypeGetPipeNo;
        _icd->setData(&data);   /*获取套管编号*/
        data.mType = UperCmdTypeGetCorrFactor;
        _icd->setData(&data);   /*获取修正系数*/
        data.mType = UperCmdTypeGetDelayTime;
        _icd->setData(&data);   /*获取延迟时间*/
        data.mType = UperCmdTypeGetWellNo;
        _icd->setData(&data);   /*获取井号*/
        data.mType = UperCmdTypeGetTongArmLen;
        _icd->setData(&data);/*获取套管长度,新增 2018-1-7*/
    }
}

void TorMonitorCore::startMonitor(bool start)
{
    _monitorStatus = start;
}

void TorMonitorCore::initDataSet()
{
    _icd = new UperIcdRelover;
    _monitorStatus = false;
    /*初始化下位机配置数据*/
    _lowerCfgData.mCommType = -1;
    _lowerCfgData.mWellNo = 0;
    _lowerCfgData.mPipeNo = 0;
    _lowerCfgData.mCtlTor = 0;
    _lowerCfgData.mDrawTor = 0;
    _lowerCfgData.mCycleMax = 0;
    _lowerCfgData.mCorrFactor = 0;
    _lowerCfgData.mDelayTime = 0;
    _lowerCfgData.mDelegComp = "";
    _lowerCfgData.mExeComp = "";
    _lowerCfgData.mCollabComp = "";
    _lowerCfgData.mMachinNo = "";
    _lowerCfgData.mHydClamp = "";
    _lowerCfgData.mAreaNo = "";
    _lowerCfgData.mOwnerSuper = "";
    _lowerCfgData.mTechDir = "";
    _lowerCfgData.mRemark = "";
    _lowerCfgData.mPipeName = "";
    _lowerCfgData.mPipeType = "";
    _lowerCfgData.mPipeDiameter = "";
    _lowerCfgData.mPipeClass = "";
    _lowerCfgData.mPipeThickness = "";
    _lowerCfgData.mTongArmLen = 0;
    _lowerCfgData.mMinStep = 0;
    _lowerCfgData.mMaxStep = 0;
    _lowerCfgData.mMaxTor = 0;
    _lowerCfgData.mMinTor = 0;
    _lowerCfgData.mMaxTime = 0;
    _lowerCfgData.mMaxCycle = 0;
    /*初始化实时数据*/
    _lowerRtList.clear();
    memset(&_lowerRtData, 0, sizeof(_lowerRtData));
    _db = DbOper::getDbOper();
}

void TorMonitorCore::handleCfgData(InUperTransceiverDataSet& inData)
{
    /*处理通信类型*/
    if (inData.mCommTypeValid)
    {
        _lowerCfgData.mCommType = (int)inData.mCommType;
    }
    if (inData.mAddNoValid||inData.mSetAddIDValid)/*附加ID*/
    {   /*获取附加的数据*/
        quint32 addNo = inData.mAddNoValid ? inData.mAddNo : inData.mSetAddID;
        TorAddtionalDataStruct addData = _db->searchAddtionalData(addNo);
        _lowerCfgData.mAddId = addNo; /*附加的编号*/
        _lowerCfgData.mDelegComp = addData.mDelegateComp;   /*委托单位*/
        _lowerCfgData.mExeComp = addData.mExeComp;  /*作业单位*/
        _lowerCfgData.mCollabComp = addData.mCollabComp;    /*协作单位*/
        _lowerCfgData.mMachinNo = addData.mMachinNo;    /*仪器编号*/
        _lowerCfgData.mHydClamp = addData.mHydClamp;    /*液压钳*/
        _lowerCfgData.mAreaNo = addData.mAreaNo;    /*作业区块*/
        _lowerCfgData.mOwnerSuper = addData.mOwnerSuper;    /*甲方监制*/
        _lowerCfgData.mTechDir = addData.mTechDir;  /*技术负责人*/
        _lowerCfgData.mRemark = addData.mRemark;    /*备注*/
        _lowerCfgData.mPipeName = addData.mPipeName;    /*套管名称*/
        _lowerCfgData.mPipeType = addData.mPipeType;    /*套管型号*/
        _lowerCfgData.mPipeDiameter = addData.mPipeDiameter;    /*套管直径*/
        _lowerCfgData.mPipeClass = addData.mPipeClass;  /*套管钢级*/
        _lowerCfgData.mPipeThickness = addData.mPipeThickness;  /*套管厚度*/
        //_lowerCfgData.mTongArmLen = addData.mTongArmLen;    /*钳臂长,由于可以直接从下位机获取，所以注释掉了，2018-1-7*/
        _lowerCfgData.mMinStep = addData.mMinStep;  /*最小台阶*/
        _lowerCfgData.mMaxStep = addData.mMaxStep;  /*最大台阶*/
        _lowerCfgData.mMaxTor = addData.mMaxTor;    /*最大扭矩*/
        _lowerCfgData.mMinTor = addData.mMinTor;    /*最小扭矩*/
        _lowerCfgData.mMaxTime = addData.mMaxTime;  /*最大时间*/
    }
    /*控制扭矩*/
    if (inData.mCtlTorValid||inData.mSetCtlTorValid)
    {
        _lowerCfgData.mCtlTor = inData.mCtlTorValid ? inData.mCtlTor : inData.mSetCtlTor;
    }
    /*画线扭矩*/
    if (inData.mDrawTorValid||inData.mSetDrawTorValid)
    {
        _lowerCfgData.mDrawTor = inData.mDrawTorValid ? inData.mDrawTor : inData.mSetDrawTor;
    }
    /*圈数最大值*/
    if (inData.mCycleMaxValid||inData.mSetCycleMaxValid)
    {
        _lowerCfgData.mCycleMax = inData.mCycleMaxValid ? inData.mCycleMax : inData.mSetCycleMax;
    }
    /*下位机时间*/
    if (inData.mDateTimeValid||inData.mSetDateTimeValid)
    {
        _lowerCfgData.mLowerTime = inData.mDateTimeValid ? inData.mDateTime : inData.mSetDateTime;
    }
    /*下位机杆号*/
    if (inData.mPipeNoValid||inData.mSetPipeNoValid)
    {
        _lowerCfgData.mPipeNo = inData.mPipeNoValid ? inData.mPipeNo : inData.mSetPipeNo;
    }
    /*修正系数*/
    if (inData.mCorrFactorValid||inData.mSetCorrFactorValid)
    {
        _lowerCfgData.mCorrFactor = inData.mCorrFactorValid ? inData.mCorrFactor : inData.mSetCorrFactor;
    }
    /*延迟时间*/
    if (inData.mDelayTimeValid||inData.mSetDelayTimeValid)
    {
        _lowerCfgData.mDelayTime = inData.mDelayTimeValid ? inData.mDelayTime : inData.mSetDelayTime;
    }
    /*井号*/
    if (inData.mWellNoValid||inData.mSetWellNoValid)
    {
        _lowerCfgData.mWellNo = inData.mWellNoValid ? inData.mWellNo : inData.mSetWellNo;
    }
    /*后续的待扩充*/
    /*钳臂长,新增 2018-1-7*/
    if (inData.mTongArmLenValid||inData.mSetTongArmLenValid)
    {
        _lowerCfgData.mTongArmLen = inData.mTongArmLenValid ? inData.mTongArmLen : inData.mSetTongArmLen;
    }
    /*控制模式，新增 2018-1-7*/
    if (inData.mSetCtlModeValid)
    {
        _lowerCfgData.mCtlMode = inData.mSetCtlMode;
    }
}

void TorMonitorCore::handleRtData(InUperTransceiverDataSet &inData)
{   /*如果实时数据有效*/
    static QDateTime dateTime = QDateTime();
    if (inData.mCurTorValid&&inData.mCurPipeValid&&inData.mCurCycleValid)
    {
        /*如果当前杆号与上一帧杆号不一致，则存储上一杆的数据到数据库中*/
        if (inData.mCurPipe != _lowerRtData.mPipeNo)
        {
            if (_lowerRtList.length() > 0)
            {
                _db->insertTorPipCycleList(_lowerRtList);
            }
            dateTime = QDateTime::currentDateTime();
            _lowerRtData.mStartTime = _lowerCfgData.mLowerTime;
        }
        _lowerRtData.mAddId = _lowerCfgData.mAddId; /*附加的ID*/
        _lowerRtData.mPipeNo = inData.mCurPipe;  /*套管编号*/
        _lowerRtData.mWellNo = _lowerCfgData.mWellNo;   /*井号*/
        _lowerRtData.mRtCycle = inData.mCurCycle * 0.2;   /*圈数,这里0.2是与翟牛商定的系数*/
        _lowerRtData.mRtTor = inData.mCurTor * _lowerCfgData.mTongArmLen;   /*实际的扭矩应为测得的值*套管的长度*/
        _lowerRtData.mTimeSpan = (quint32)(dateTime.msecsTo(QDateTime::currentDateTime()));
        _lowerRtList.append(_lowerRtData);  /*设置完成，插入到列表中*/
    }
}

void TorMonitorCore::stepLoop()
{
    InUperTransceiverDataSet uperData;
    memcpy(&uperData, _icd->getData().data(), sizeof(InUperTransceiverDataSet));
    /*处理扭矩仪收发器的配置数据*/
    handleCfgData(uperData);
    /*如果当前处于实时监控状态，则处理实时数据*/
    if (_monitorStatus) handleRtData(uperData);
}

void TorMonitorCore::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if (getTorConnStatus())
    {
        stepLoop();
    }
}
