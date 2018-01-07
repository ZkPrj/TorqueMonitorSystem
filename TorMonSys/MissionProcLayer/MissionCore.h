#ifndef MISSIONCORE_H
#define MISSIONCORE_H

#include <QObject>
#include <QDateTime>
#include "CommLayer/SerialComm.h"
#include "DataWrapLayer/DataWraper.h"
#include "DbOper.h"




class MissionCore : public QObject
{
    Q_OBJECT
public:
    explicit MissionCore(QObject *parent = 0);

    bool getUpConnStatus();
    void setCommType(int i);
    int getCommType();
    void reqUperDefaultArgs();
    /*相关参数的获取和设置*/
    QString getDeleComp();
    QString getExeComp();
    QString getCollComp();
    QString getMachineNo();
    QString getHydClamp();
    QString getAreaNo();
    QString getWellNo();
    QString getOwnerSuper();
    QString getTechDir();
    QString getRemark();
    QString getPipeName();
    QString getPipType();
    QString getPipeDiameter();
    QString getPipeClass();
    QString getPipeThinkness();
    qreal getTongArmLen();
    qreal getCorrFactor();
    qreal getDelayTime();
    qreal getMinStep();
    qreal getMaxStep();
    qreal getMaxTor();
    qreal getMinTor();
    qreal getBestTor();
    qreal getCtlTor();
    qreal getDrawTor();
    qreal getMaxTime();
    qreal getMaxCycle();
    QDateTime getDateTime();
    quint32 getPipeNo();

    void setDeleComp(QString str);
    void setExeComp(QString str);
    void setCollComp(QString str);
    void setMachineNo(QString str);
    void setHydClamp(QString str);
    void setAreaNo(QString str);
    void setWellNo(QString str);
    void setOwnerSuper(QString str);
    void setTechDir(QString str);
    void setRemark(QString str);
    void setPipeName(QString str);
    void setPipeType(QString str);
    void setPipeDiameter(QString str);
    void setPipeClass(QString str);
    void setPipeThinkness(QString str);
    void setTongArmLen(qreal data);
    void setCorrFactor(qreal data);
    void setDelayTime(qreal data);
    void setMinStep(qreal data);
    void setMaxStep(qreal data);
    void setMaxTor(qreal data);
    void setMinTor(qreal data);
    void setBestTor(qreal data);
    void setCtlTor(qreal data);
    void setDrawTor(qreal data);
    void setMaxTime(qreal data);
    void setMaxCycle(qreal data);
    void setDateTime(QDateTime data);
    void setPipeNo(quint32 data);
    void updateTorSysArg();
    void startTorMonitor();

    QList<TorRtDataStruct> getPipeTorList(quint32 pipeIndex);   /*获取指定套管的扭矩信息列表*/
    QList<TorRtDataStruct> getPipeTorList(quint32 wellNo, quint32 pipeNo);
    QList<TorRtDataStruct> getCurPipeTorList();

    bool getLowerConnStatus();


private:
    void getArgsFromUpTrans();
    void setArgs2UpTrans();
    void getCurTorFromUpTrans();
    void readAndParseCfgFile();

    void searchAddArg(int id);

    void handleUperData();

    void initUperData();
signals:

public slots:
    void timerEvent(QTimerEvent *event);
private:
    DataWraper* _dataWraper;
    DbOper* _db;
    quint32 _loopT; /*循环的周期*/
    /*记录底层的状态*/
    int _commType;  /*-1：无效，0-无线，1-有线*/
    /*第一套数据为实际接收到的数据，第二套为人工设置的数据*/
    /*注意跟控制扭矩和画线扭矩相关的内容：第一套接收的数据为力，设置的数据第二套为扭矩，中间相差一个套管长度*/
    TorAddtionalDataStruct _manageData[2];
    quint32 _ctlTor[2];
    quint32 _drawTor[2];
    quint32 _cycleMax[2];
    qint32 _dateTime[2]; /*每秒获取下位机时间*//*改处记录的是距离当前系统时间的秒数间隔*/
    quint32 _pipeNo[2];
    qreal _corrFactor[2];
    quint32 _delayTime[2];
    quint32 _wellNo[2];
    quint32 _addId[2]; /*上位机收发器存放的附加ID*/
    /*扭矩仪实时数据*/
    QDateTime _startTime;
    TorRtDataStruct _curTorRtData;
    QList<TorRtDataStruct> _curPipeTorList;
    bool _startTorMonitor;
};

#endif // MISSIONCORE_H
