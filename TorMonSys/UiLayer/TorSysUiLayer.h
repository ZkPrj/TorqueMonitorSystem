#ifndef TORSYSUILAYER_H
#define TORSYSUILAYER_H

#include <QObject>
#include "MissionProcLayer/MissionCore.h"

class TorSysUiLayer : public QObject
{
    Q_OBJECT
public:
    explicit TorSysUiLayer(QObject *parent = 0);


public:
    Q_INVOKABLE bool getUpConnStatus();
    Q_INVOKABLE void setCommType(int i);
    Q_INVOKABLE int getCommType();
    Q_INVOKABLE void reqUperDefaultArgs();
    Q_INVOKABLE QString getDeleComp();
    Q_INVOKABLE QString getExeComp();
    Q_INVOKABLE QString getCollComp();
    Q_INVOKABLE QString getMachineNo();
    Q_INVOKABLE QString getHydClamp();
    Q_INVOKABLE QString getAreaNo();
    Q_INVOKABLE QString getWellNo();
    Q_INVOKABLE QString getOwnerSuper();
    Q_INVOKABLE QString getTechDir();
    Q_INVOKABLE QString getRemark();
    Q_INVOKABLE QString getPipeName();
    Q_INVOKABLE QString getPipType();
    Q_INVOKABLE QString getPipeDiameter();
    Q_INVOKABLE QString getPipeClass();
    Q_INVOKABLE QString getPipeThinkness();
    Q_INVOKABLE qreal getTongArmLen();
    Q_INVOKABLE qreal getCorrFactor();
    Q_INVOKABLE qreal getDelayTime();
    Q_INVOKABLE qreal getMinStep();
    Q_INVOKABLE qreal getMaxStep();
    Q_INVOKABLE qreal getMaxTor();
    Q_INVOKABLE qreal getMinTor();
    Q_INVOKABLE qreal getBestTor();
    Q_INVOKABLE qreal getCtlTor();
    Q_INVOKABLE qreal getDrawTor();
    Q_INVOKABLE qreal getMaxTime();
    Q_INVOKABLE qreal getMaxCycle();
    Q_INVOKABLE QDateTime getDateTime();
    Q_INVOKABLE quint32 getPipeNo();

    Q_INVOKABLE void setDeleComp(QString str);
    Q_INVOKABLE void setExeComp(QString str);
    Q_INVOKABLE void setCollComp(QString str);
    Q_INVOKABLE void setMachineNo(QString str);
    Q_INVOKABLE void setHydClamp(QString str);
    Q_INVOKABLE void setAreaNo(QString str);
    Q_INVOKABLE void setWellNo(QString str);
    Q_INVOKABLE void setOwnerSuper(QString str);
    Q_INVOKABLE void setTechDir(QString str);
    Q_INVOKABLE void setRemark(QString str);
    Q_INVOKABLE void setPipeName(QString str);
    Q_INVOKABLE void setPipeType(QString str);
    Q_INVOKABLE void setPipeDiameter(QString str);
    Q_INVOKABLE void setPipeClass(QString str);
    Q_INVOKABLE void setPipeThinkness(QString str);
    Q_INVOKABLE void setTongArmLen(qreal data);
    Q_INVOKABLE void setCorrFactor(qreal data);
    Q_INVOKABLE void setDelayTime(qreal data);
    Q_INVOKABLE void setMinStep(qreal data);
    Q_INVOKABLE void setMaxStep(qreal data);
    Q_INVOKABLE void setMaxTor(qreal data);
    Q_INVOKABLE void setMinTor(qreal data);
    Q_INVOKABLE void setBestTor(qreal data);
    Q_INVOKABLE void setCtlTor(qreal data);
    Q_INVOKABLE void setDrawTor(qreal data);
    Q_INVOKABLE void setMaxTime(qreal data);
    Q_INVOKABLE void setMaxCycle(qreal data);
    Q_INVOKABLE void setDateTime(QDateTime data);
    Q_INVOKABLE void setPipeNo(quint32 data);
    Q_INVOKABLE void updateTorSysArg();

    Q_INVOKABLE void reqLastTorList();
    Q_INVOKABLE void reqNextTorList();
    Q_INVOKABLE void reqCurTorList();
    Q_INVOKABLE void startTorMonitor();
    Q_INVOKABLE QList<qreal> getCurTorList();
    Q_INVOKABLE QList<qreal> getCurCycleList();
    Q_INVOKABLE QList<qreal> getTimeSpanList();
signals:

public slots:

private:
    MissionCore* _core;
    QList<TorRtDataStruct> _curTorList;
};

#endif // TORSYSUILAYER_H
