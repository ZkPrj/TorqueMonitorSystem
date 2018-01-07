#ifndef TORMONITORUI_H
#define TORMONITORUI_H

#include <QObject>
#include "Mission/TorMonitorCore.h"


class TorMonitorUi : public QObject
{
    Q_OBJECT
public:
    explicit TorMonitorUi(QObject *parent = 0);
    Q_INVOKABLE bool getConnStatus();   /*获取通信状态*/
    Q_INVOKABLE void setCommType(int i);    /*设置通信类型，0-无线，1-有线*/
    Q_INVOKABLE int getCommType();  /*获取通信类型,0-无线，1-有线*/
    Q_INVOKABLE void setCtlMode(int i); /*设置控制模式,0-*/
    Q_INVOKABLE int getCtlMode();  /*获取控制模式*/
    Q_INVOKABLE void reqLowerCurArgs(); /*请求下位机当前的参数*/

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

    Q_INVOKABLE QString getTongArmLen();
    Q_INVOKABLE QString getCorrFactor();
    Q_INVOKABLE QString getDelayTime();
    Q_INVOKABLE QString getMinStep();
    Q_INVOKABLE QString getMaxStep();

    Q_INVOKABLE QString getMaxTor();
    Q_INVOKABLE QString getMinTor();
    Q_INVOKABLE QString getBestTor();
    Q_INVOKABLE QString getCtlTor();
    Q_INVOKABLE QString getDrawTor();
    Q_INVOKABLE QString getMaxTime();
    Q_INVOKABLE QString getMaxCycle();
    Q_INVOKABLE QString getDateTime();
    Q_INVOKABLE QString getPipeNo();


signals:

public slots:

private:
    TorMonitorCore* _torMonitorCore;
};

#endif // TORMONITORUI_H
