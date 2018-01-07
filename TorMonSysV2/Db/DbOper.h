#ifndef DBOPER_H
#define DBOPER_H

#include <QtSql/QSqlDriver>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDateTime>
#include <QList>

struct TorAddtionalDataStruct
{
    QString mDelegateComp;  /*委托单位*/
    QString mExeComp;   /*作业单位*/
    QString mCollabComp;    /*协作单位*/
    QString mMachinNo;  /*仪器编号*/
    QString mHydClamp;  /*液压钳*/
    QString mAreaNo;    /*作业区块*/
    QString mWellNo;    /*井号*/
    QString mOwnerSuper;    /*甲方监督*/
    QString mTechDir;   /*技术负责人*/
    QString mRemark;    /*备注*/

    QString mPipeName;  /*套管名字*/
    QString mPipeType;  /*套管型号*/
    QString mPipeDiameter;  /*套管直径*/
    QString mPipeClass; /*套管钢级*/
    QString mPipeThickness; /*套管厚度*/

    qreal mTongArmLen;  /*钳臂长*/
    qreal mCorrFactor;  /*修正系数*/
    qreal mDelayTime;   /*延迟时长*/
    qreal mMinStep; /*最小台阶*/
    qreal mMaxStep; /*最大台阶*/

    qreal mMaxTor;  /*最大扭矩*/
    qreal mMinTor;  /*最小扭矩*/
    qreal mBestTor; /*最佳扭矩*/
    qreal mCtlTor;  /*控制扭矩*/
    qreal mDrawTor; /*画线扭矩*/
    qreal mMaxTime; /*最大时间*/
    qreal mMaxCycle; /*最大周期*/

};

struct TorRtDataStruct
{
    quint32 mWellNo;    /*井号*/
    quint32 mPipeNo;    /*套管编号*/
    quint32 mRtTor;     /*实时扭矩*/
    qreal mRtCycle;     /*实时圈数*/
    quint32 mTimeSpan;  /*时间戳*/
    quint32 mStartTime; /*起始时间*/
    quint32 mAddId;     /*附加ID*/
};

class DbOper
{
public:
    static DbOper* getDbOper();
    TorAddtionalDataStruct searchAddtionalData(quint32 id);
    bool insertId(
                  quint32 id,
                  quint32 manId,
                  quint32 techId,
                  quint32 pipeId,
                  quint32 dispId
                  );
    bool insertManageData(
            quint32 id,
            QString deleComp,/*委托单位*/
            QString exeComp,    /*作业单位*/
            QString collabComp, /*协作单位*/
            QString machineNo,  /*仪器编号*/
            QString hydClamp,   /*液压钳*/
            QString areaNo, /*作业区块*/
            QString wellNo, /*作业井号*/
            QString ownerSuper, /*甲方监督*/
            QString TechDir, /*技术负责人*/
            QString remark  /*备注*/
            );
    bool insertPipeData(
            quint32 id,
            QString pipeName,
            QString pipeType,
            QString pipeDiameter,
            QString pipeClass,
            QString pipeThickness
            );
    bool insertTechData(
            quint32 id,
            qreal tongArmLen,
            qreal corrFactor,
            qreal delayTime,
            qreal minStep,
            qreal maxStep
            );
    bool insertDspData(
            quint32 id,
            qreal maxTor,
            qreal minTor,
            qreal bestTor,
            qreal ctlTor,
            qreal drawTor,
            int maxTime,
            int maxCycle
            );
    bool insertTorPipCycleList(QList<TorRtDataStruct> data);

    bool deleteRtTorPipeData(quint32 wellNo, quint32 pipeNo);

    QList<TorRtDataStruct> searchTorData(quint32 wellNo, quint32 pipeNo);

    quint32 getMaxIdIndexId();
    quint32 getMaxManageId();
    quint32 getMaxPipeId();
    quint32 getMaxTechId();
    quint32 getMaxDspId();
    bool getIdByAddId(quint32 addId, quint32& mangeId, quint32& dspId, quint32& pipId, quint32& techId);
private:
    DbOper();
    bool createConn();/*创建连接*/


private:
    QSqlDatabase _db;
    static DbOper* _self;
};

#endif // DBOPER_H
