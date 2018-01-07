#ifndef UPERICDRELOVER_H
#define UPERICDRELOVER_H

#include <QReadWriteLock>
#include "IcdRelover.h"
#include "MiddleDataSet.h"
#include "IO/SerialComm.h"

enum UperCmdType
{
    UperCmdTypeConn = 1,    /*连接响应*/
    UperCmdTypeCommType = 2,   /*通信通道选择*/
    UperCmdTypeCurTorPipe = 3, /*当前扭矩和杆号*/
    UperCmdTypeCurStatus = 4, /*当前泄压状态*/
    UperCmdTypeGetCtlTor = 250, /*下位机的控制扭矩*/
    UperCmdTypeGetDrawTor = 249, /*下位机画线扭矩*/
    UperCmdTypeGetCycleMax = 248, /*下位机圈数最大值*/
    UperCmdTypeGetDateTime = 247, /*下位机时间*/
    UperCmdTypeGetPipeNo = 246, /*下位机杆号*/
    UperCmdTypeGetCorrFactor = 245, /*下位机修正系数*/
    UperCmdTypeGetDelayTime = 244, /*下位机延迟时间*/
    UperCmdTypeGetWellNo = 243, /*井号*/
    UperCmdTypeGetAddNo = 242, /*附加的ID*/
    UperCmdTypeGetTongArmLen = 241, /*获取钳臂长*/
    UperCmdTypeSetCtlTor = 5, /*下位机的控制扭矩*/
    UperCmdTypeSetDrawTor = 6, /*下位机画线扭矩*/
    UperCmdTypeSetCycleMax = 7, /*下位机圈数最大值*/
    UperCmdTypeSetDateTime = 8, /*下位机时间*/
    UperCmdTypeSetPipeNo = 9, /*下位机杆号*/
    UperCmdTypeSetCorrFactor = 10, /*下位机修正系数*/
    UperCmdTypeSetDelayTime = 11, /*下位机延迟时间*/
    UperCmdTypeSetWellNo = 12, /*井号*/
    UperCmdTypeSetAddNo = 13, /*附加的ID*/
    UperCmdTypeSetTongArmLen = 14, /*设置钳臂长*/
    UperCmdTypeSetCtlMode = 15, /*设置控制模式*/
};

struct SetArgDataSet
{
    UperCmdType mType;
    quint32 mPayLoad;
};

class UperIcdRelover : public IcdRelover
{
    Q_OBJECT
public:
    UperIcdRelover();

    virtual  void conn2Edp();
    virtual ConnStatusType getConnStatus();
    virtual void setData(void* data);
    QByteArray getData();

public slots:
    void timerEvent(QTimerEvent *event);

protected:
    void updateInputData();
    virtual void getRawData();
    virtual QList<QByteArray> fetchFrames();
    virtual void unWrapFrames(QList<QByteArray> frames);
    virtual void stepSndData();
    void cycleHandleOtherMission();
    void handleConn();

    void initDataSet(); /*参数初始化*/
    QByteArray wrapFrame(UperCmdType cmd, qint32 payLoad);
private:
    OutUperTransceiverDataSet _outData; /*待输出数据（中间层）*/
    InUperTransceiverDataSet _inData;   /*待输入数据（中间层）*/

    QByteArray _rawBuf;     /*原始输入数据*/
    QReadWriteLock _inLock;
    QReadWriteLock _outLock;
    CommIO* _io;

    ConnStatusType _connStatus;   /*与底层的连接状态*/
    /*候选连接器*/
    QList<SerialComm*> _candiList;
    int _connCount;
    int _cyleTimeMs;/*周期时间*/
};

#endif // UPERICDRELOVER_H
