#include "TorSysUiLayer.h"

TorSysUiLayer::TorSysUiLayer(QObject *parent) : QObject(parent)
{
    _core = new MissionCore;
}

bool TorSysUiLayer::getUpConnStatus()
{
    return _core->getUpConnStatus();
}

void TorSysUiLayer::setCommType(int i)
{
    return _core->setCommType(i);
}

int TorSysUiLayer::getCommType()
{
    return _core->getCommType();
}

void TorSysUiLayer::reqUperDefaultArgs()
{
    return _core->reqUperDefaultArgs();
}

QString TorSysUiLayer::getDeleComp()
{
    return _core->getDeleComp();
}

QString TorSysUiLayer::getExeComp()
{
    return _core->getExeComp();
}

QString TorSysUiLayer::getCollComp()
{
    return _core->getCollComp();
}

QString TorSysUiLayer::getMachineNo()
{
    return _core->getMachineNo();
}

QString TorSysUiLayer::getHydClamp()
{
    return _core->getHydClamp();
}

QString TorSysUiLayer::getAreaNo()
{
    return _core->getAreaNo();
}

QString TorSysUiLayer::getWellNo()
{
    return _core->getWellNo();
}

QString TorSysUiLayer::getOwnerSuper()
{
    return _core->getOwnerSuper();
}

QString TorSysUiLayer::getTechDir()
{
    return _core->getTechDir();
}

QString TorSysUiLayer::getRemark()
{
    return _core->getRemark();
}

QString TorSysUiLayer::getPipeName()
{
    return _core->getPipeName();
}

QString TorSysUiLayer::getPipType()
{
    return _core->getPipType();
}

QString TorSysUiLayer::getPipeDiameter()
{
    return _core->getPipeDiameter();
}

QString TorSysUiLayer::getPipeClass()
{
    return _core->getPipeClass();
}

QString TorSysUiLayer::getPipeThinkness()
{
    return _core->getPipeThinkness();
}

qreal TorSysUiLayer::getTongArmLen()
{
    return _core->getTongArmLen();
}

qreal TorSysUiLayer::getCorrFactor()
{
    return _core->getCorrFactor();
}

qreal TorSysUiLayer::getDelayTime()
{
    return _core->getDelayTime();
}

qreal TorSysUiLayer::getMinStep()
{
    return _core->getMinStep();
}

qreal TorSysUiLayer::getMaxStep()
{
    return _core->getMaxStep();
}

qreal TorSysUiLayer::getMaxTor()
{
    return _core->getMaxTor();
}

qreal TorSysUiLayer::getMinTor()
{
    return _core->getMinTor();
}

qreal TorSysUiLayer::getBestTor()
{
    return _core->getBestTor();
}

qreal TorSysUiLayer::getCtlTor()
{
    return _core->getCtlTor();
}

qreal TorSysUiLayer::getDrawTor()
{
    return _core->getDrawTor();
}

qreal TorSysUiLayer::getMaxTime()
{
    return _core->getMaxTime();
}

qreal TorSysUiLayer::getMaxCycle()
{
    return _core->getMaxCycle();
}

QDateTime TorSysUiLayer::getDateTime()
{
    return _core->getDateTime();
}

quint32 TorSysUiLayer::getPipeNo()
{
    return _core->getPipeNo();
}

void TorSysUiLayer::setDeleComp(QString str)
{
    return _core->setDeleComp(str);
}

void TorSysUiLayer::setExeComp(QString str)
{
    return _core->setExeComp(str);
}

void TorSysUiLayer::setCollComp(QString str)
{
    return _core->setCollComp(str);
}

void TorSysUiLayer::setMachineNo(QString str)
{
    return _core->setMachineNo(str);
}

void TorSysUiLayer::setHydClamp(QString str)
{
    return _core->setHydClamp(str);
}

void TorSysUiLayer::setAreaNo(QString str)
{
    return _core->setAreaNo(str);
}

void TorSysUiLayer::setWellNo(QString str)
{
    return _core->setWellNo(str);
}

void TorSysUiLayer::setOwnerSuper(QString str)
{
    return _core->setOwnerSuper(str);
}

void TorSysUiLayer::setTechDir(QString str)
{
    return _core->setTechDir(str);
}

void TorSysUiLayer::setRemark(QString str)
{
    return _core->setRemark(str);
}

void TorSysUiLayer::setPipeName(QString str)
{
    return _core->setPipeName(str);
}

void TorSysUiLayer::setPipeType(QString str)
{
    return _core->setPipeType(str);
}

void TorSysUiLayer::setPipeDiameter(QString str)
{
    return _core->setPipeDiameter(str);
}

void TorSysUiLayer::setPipeClass(QString str)
{
    return _core->setPipeClass(str);
}

void TorSysUiLayer::setPipeThinkness(QString str)
{
    return _core->setPipeThinkness(str);
}

void TorSysUiLayer::setTongArmLen(qreal data)
{
    return _core->setTongArmLen(data);
}

void TorSysUiLayer::setCorrFactor(qreal data)
{
    return _core->setCorrFactor(data);
}

void TorSysUiLayer::setDelayTime(qreal data)
{
    return _core->setDelayTime(data);
}

void TorSysUiLayer::setMinStep(qreal data)
{
    return _core->setMinStep(data);
}

void TorSysUiLayer::setMaxStep(qreal data)
{
    return _core->setMaxStep(data);
}

void TorSysUiLayer::setMaxTor(qreal data)
{
    return _core->setMaxTor(data);
}

void TorSysUiLayer::setMinTor(qreal data)
{
    return _core->setMinTor(data);
}

void TorSysUiLayer::setBestTor(qreal data)
{
    return _core->setBestTor(data);
}

void TorSysUiLayer::setCtlTor(qreal data)
{
    return _core->setCtlTor(data);
}

void TorSysUiLayer::setDrawTor(qreal data)
{
    return _core->setDrawTor(data);
}

void TorSysUiLayer::setMaxTime(qreal data)
{
    return _core->setMaxTime(data);
}

void TorSysUiLayer::setMaxCycle(qreal data)
{
    return _core->setMaxCycle(data);
}

void TorSysUiLayer::setDateTime(QDateTime data)
{
    return _core->setDateTime(data);
}

void TorSysUiLayer::setPipeNo(quint32 data)
{
    return _core->setPipeNo(data);
}

void TorSysUiLayer::updateTorSysArg()
{
    return _core->updateTorSysArg();
}

void TorSysUiLayer::reqLastTorList()
{

}

void TorSysUiLayer::reqNextTorList()
{

}

void TorSysUiLayer::reqCurTorList()
{
    _curTorList = _core->getCurPipeTorList();
}

void TorSysUiLayer::startTorMonitor()
{
    _core->startTorMonitor();
}

QList<qreal> TorSysUiLayer::getCurTorList()
{
    QList<qreal> list;
    for (TorRtDataStruct rtData: _curTorList)
    {
        list.append(rtData.mRtTor);
    }
//    list.clear();
//    list.append(2000);
//    list.append(3100);
//    list.append(4200);
//    list.append(5300);
//    list.append(6400);
//    list.append(7500);
//    list.append(8600);
//    list.append(8700);
//    list.append(7800);
//    list.append(3900);
//    list.append(3500);
    return list;
}

QList<qreal> TorSysUiLayer::getCurCycleList()
{
    QList<qreal> list;
    for (TorRtDataStruct rtData: _curTorList)
    {
        list.append(rtData.mRtCycle);
    }
//    list.clear();
//    list.append(1);
//    list.append(1.4);
//    list.append(2.0);
//    list.append(3.2);
//    list.append(3.5);
//    list.append(4.0);
//    list.append(4.1);
//    list.append(4.3);
//    list.append(4.5);
//    list.append(4.7);
//    list.append(5.0);
    return list;
}

QList<qreal> TorSysUiLayer::getTimeSpanList()
{
    QList<qreal> list;
    for (TorRtDataStruct rtData: _curTorList)
    {
        list.append(rtData.mTimeSpan);
    }
//    list.clear();
//    list.append(1);
//    list.append(2);
//    list.append(3);
//    list.append(4);
//    list.append(5);
//    list.append(6);
//    list.append(7);
//    list.append(8);
//    list.append(9);
//    list.append(10);
//    list.append(11);
    return list;
}


