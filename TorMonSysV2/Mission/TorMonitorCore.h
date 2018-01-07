#ifndef TORMONITORCORE_H
#define TORMONITORCORE_H

#include <QObject>
#include <QList>
#include "IoMiddleWare/UperIcdRelover.h"
#include "Db/DbOper.h"

struct LowerCfgDs
{
    int mCommType;  /*通信类型，-1-无效，0-无线，1-有线*/
    int mWellNo;    /*井号*/
    int mPipeNo;    /*套管编号*/
    int mCtlTor;    /*控制扭矩*/    /*收到的控制扭矩*钳臂长=实际的控制扭矩*/
    int mDrawTor;   /*画线扭矩*/    /*收到的画线扭矩*钳臂长=实际的画线扭矩*/
    qreal mCycleMax; /*圈数最大值*/
    qreal mCorrFactor;  /*修正系数*/ /*收到的修正系数与实际的修正系数相差10倍*/
    int mDelayTime; /*延迟时间*/

    QString mDelegComp; /*委托单位*/
    QString mExeComp;   /*作业单位*/
    QString mCollabComp;    /*协作单位*/
    QString mMachinNo;  /*仪器编号*/
    QString mHydClamp;  /*液压钳*/
    QString mAreaNo;    /*作业区块*/
    QString mOwnerSuper;    /*甲方监督*/
    QString mTechDir;   /*技术负责人*/
    QString mRemark;    /*备注*/

    QString mPipeName;  /*套管名字*/
    QString mPipeType;  /*套管型号*/
    QString mPipeDiameter;  /*套管直径*/
    QString mPipeClass; /*套管钢级*/
    QString mPipeThickness; /*套管厚度*/

    qreal mTongArmLen;  /*钳臂长*/ /*收到的钳臂长=实际的钳臂长*1000*/
    qreal mMinStep; /*最小台阶*/
    qreal mMaxStep; /*最大台阶*/

    qreal mMaxTor;  /*最大扭矩*/
    qreal mMinTor;  /*最小扭矩*/
    qreal mMaxTime; /*最大时间*/
    qreal mMaxCycle; /*最大周期*/

    quint32 mLowerTime; /*下位机时间*/
    quint32 mAddId; /*附加的编号*/

    quint32 mCtlMode;   /*控制模式, 0-圈数，扭矩   1-扭矩*/
};


class TorMonitorCore : public QObject
{
    Q_OBJECT
public:
    explicit TorMonitorCore(QObject *parent = 0);
    bool getTorConnStatus();/*获取扭矩仪连接器的通信状态*/
    void setCommType(int i);    /*设置通信类型，0-无线，1-有线*/
    void setCtlMode(int i); /*设置控制模式， 0-圈数，扭矩 1-扭矩*/
    void setLowerCfgDs(LowerCfgDs cfg);
    QList<TorRtDataStruct> getCurPipeTorList(); /*获取当前套管的扭矩列表*/
    QList<TorRtDataStruct> getSpePipeTorList(quint32 pipe); /*获取指定套管的扭矩列表*/

    LowerCfgDs getLowerCfgDs();
    void sndCfgReq2Lower();
    void startMonitor(bool start = true);   /*设置是否开启扭矩实时监控*/
private:
    void initDataSet();
    void handleCfgData(InUperTransceiverDataSet& inData);
    void handleRtData(InUperTransceiverDataSet& inData);
    void stepLoop();
signals:

public slots:
    void timerEvent(QTimerEvent *event);

private:
    bool _monitorStatus;
    IcdRelover* _icd;
    LowerCfgDs _lowerCfgData;
    TorRtDataStruct _lowerRtData;
    QList<TorRtDataStruct> _lowerRtList;
    DbOper* _db;
};

#endif // TORMONITORCORE_H
