#include "TorMonitorUi.h"

TorMonitorUi::TorMonitorUi(QObject *parent) : QObject(parent)
{
    _torMonitorCore = new  TorMonitorCore;
}

bool TorMonitorUi::getConnStatus()
{
    return _torMonitorCore->getTorConnStatus();
}

void TorMonitorUi::setCommType(int i)
{
    _torMonitorCore->setCommType(i);
}

int TorMonitorUi::getCommType()
{
    LowerCfgDs cfg = _torMonitorCore->getLowerCfgDs();
    return (int)(cfg.mCommType);
}

void TorMonitorUi::setCtlMode(int i)
{
    _torMonitorCore->setCtlMode(i);
}

int TorMonitorUi::getCtlMode()
{
    LowerCfgDs cfg = _torMonitorCore->getLowerCfgDs();
    return (int)(cfg.mCtlMode);
}

void TorMonitorUi::reqLowerCurArgs()
{
    _torMonitorCore->sndCfgReq2Lower();
}

QString TorMonitorUi::getDeleComp()
{
    return _torMonitorCore->getLowerCfgDs().mDelegComp;
}

QString TorMonitorUi::getExeComp()
{
    return _torMonitorCore->getLowerCfgDs().mExeComp;
}

QString TorMonitorUi::getCollComp()
{
    return _torMonitorCore->getLowerCfgDs().mCollabComp;
}

QString TorMonitorUi::getMachineNo()
{
    return _torMonitorCore->getLowerCfgDs().mMachinNo;
}

QString TorMonitorUi::getHydClamp()
{
    return _torMonitorCore->getLowerCfgDs().mHydClamp;
}

QString TorMonitorUi::getAreaNo()
{
    return _torMonitorCore->getLowerCfgDs().mAreaNo;
}

QString TorMonitorUi::getWellNo()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mWellNo);
}

QString TorMonitorUi::getOwnerSuper()
{
    return _torMonitorCore->getLowerCfgDs().mOwnerSuper;
}

QString TorMonitorUi::getTechDir()
{
    return _torMonitorCore->getLowerCfgDs().mTechDir;
}

QString TorMonitorUi::getRemark()
{
    return _torMonitorCore->getLowerCfgDs().mRemark;
}

QString TorMonitorUi::getPipeName()
{
    return _torMonitorCore->getLowerCfgDs().mPipeName;
}

QString TorMonitorUi::getPipType()
{
    return _torMonitorCore->getLowerCfgDs().mPipeType;
}

QString TorMonitorUi::getPipeDiameter()
{
    return _torMonitorCore->getLowerCfgDs().mPipeDiameter;
}

QString TorMonitorUi::getPipeClass()
{
    return _torMonitorCore->getLowerCfgDs().mPipeClass;
}

QString TorMonitorUi::getPipeThinkness()
{
    return _torMonitorCore->getLowerCfgDs().mPipeThickness;
}

QString TorMonitorUi::getTongArmLen()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mTongArmLen);
}

QString TorMonitorUi::getCorrFactor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mCorrFactor);
}

QString TorMonitorUi::getDelayTime()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mDelayTime);
}

QString TorMonitorUi::getMinStep()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMinStep);
}

QString TorMonitorUi::getMaxStep()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMaxStep);
}

QString TorMonitorUi::getMaxTor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMaxTor);
}

QString TorMonitorUi::getMinTor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMinTor);
}

QString TorMonitorUi::getBestTor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mCtlTor);
}

QString TorMonitorUi::getCtlTor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mCtlTor);
}

QString TorMonitorUi::getDrawTor()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mDrawTor);
}

QString TorMonitorUi::getMaxTime()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMaxTime);
}

QString TorMonitorUi::getMaxCycle()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mMaxCycle);
}

QString TorMonitorUi::getDateTime()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mLowerTime);
}

QString TorMonitorUi::getPipeNo()
{
    return QString("%1").arg(_torMonitorCore->getLowerCfgDs().mPipeNo);
}
