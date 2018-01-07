#ifndef DATAWRAPER_H
#define DATAWRAPER_H

#include <QObject>
#include <QTimerEvent>
#include <QReadWriteLock>
#include <QByteArray>
#include <QList>
#include "DataSet.h"
#include "CommLayer/SerialComm.h"


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
    UperCmdTypeSetCtlTor = 5, /*下位机的控制扭矩*/
    UperCmdTypeSetDrawTor = 6, /*下位机画线扭矩*/
    UperCmdTypeSetCycleMax = 7, /*下位机圈数最大值*/
    UperCmdTypeSetDateTime = 8, /*下位机时间*/
    UperCmdTypeSetPipeNo = 9, /*下位机杆号*/
    UperCmdTypeSetCorrFactor = 10, /*下位机修正系数*/
    UperCmdTypeSetDelayTime = 11, /*下位机延迟时间*/
    UperCmdTypeSetWellNo = 12, /*井号*/
    UperCmdTypeSetAddNo = 13, /*附加的ID*/
};

enum LowerCmdType
{
    LowerCmdTypeConn = 0,
    LowerCmdTypeFileList = 1, /*文件列表*/
    LowerCmdTypeFileContent = 2, /*文件内容*/
    LowerCmdTypeFileCrc = 3, /*文件的CRC校验码*/
    LowerCmdTypeDelFlag = 4, /*删除文件的标志*/
};

enum ConnStatusType
{
    ConnStatusUnKnown = 0, /*未知状态*/
    ConnStatusConnecting = 1, /*正在连接过程中*/
    ConnStatusConnOk = 2, /*连接成功*/
    ConnStatusUnConn = 3, /*未连接*/
};

class DataWraper : public QObject
{
    Q_OBJECT
public:
    explicit DataWraper(QObject *parent = 0);
    InUperTransceiverDataSet getUperData();
    void conn2UperTranser();
    void conn2LowerTranser();
    ConnStatusType getUperStatus();
    ConnStatusType getLowerStatus();
    void setUperData(UperCmdType type, int payLoad);
    void setLowerData(LowerCmdType type, QByteArray payLoad);
signals:

public slots:
    void timerEvent(QTimerEvent *event);

private:
    void getRawData();
    void updateLowerInputData();
    void updateUperInputData();
    void updataInputData();
    void stepSndData();
    QList<QByteArray> fetchUperFrames();
    QList<QByteArray> fetchLowerFrames();
    void unWrapUperData(QByteArray frameData);
    void unWrapLowerData(QByteArray frameData);
    void wrapAndSndData();
    void wrapAndSndUperData();
    void wrapAndSndLowerData();
    QByteArray wrapUpTransData(UperCmdType cmd, qint32 payLoad);
    QByteArray wrapLowerTransData(LowerCmdType cmd, QByteArray payLoad);
    void handleUperConn();
    void handleLowerConn();
    void monitorConnStatus();
private:
    OutUperTransceiverDataSet _uperTransceOutData;  /*发送给上位机收发器的Data*/
    QReadWriteLock _uperOutRwLock;
    InUperTransceiverDataSet _uperTransceInData;    /*从上位机收发器接收的Data*/
    QReadWriteLock _uperInRwLock;
    InLowerTransceiverDataSet _lowerTransceInData;  /*从下位机收发器接收到的数据*/
    QReadWriteLock _lowerInRwLock;
    OutLowerTransceiverDataSet _lowerTransceOutData;    /*输出给下位机收发器的数据*/
    QReadWriteLock _lowerOutRwLock;

    CommIO* _uperIo;
    CommIO* _lowerIo;
    QByteArray _uperBuf;
    QByteArray _lowerBuf;
    QReadWriteLock _uperRawDataLock;
    QReadWriteLock _lowerRawDataLock;
    ConnStatusType _uperStatus;
    ConnStatusType _lowerStatus;

    QList<SerialComm*> _uperCandiList; /*上位机收发器的候选列表*/
    QList<SerialComm*> _lowerCandiList; /*下位机收发器的候选列表*/
    int _uperConnCount ;
    int _lowerConnCount;

    int _updateCycle ;

};

#endif // DATAWRAPER_H
