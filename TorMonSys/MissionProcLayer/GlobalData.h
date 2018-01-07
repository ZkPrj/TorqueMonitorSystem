#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <QObject>

struct ConfigContext
{
    qint32 mUpTransPort;/*上位机收发器的波特率*/
    qint32 mUpTransParity;
    qint32 mUpTransDataBits;
    qint32 mUpTransStopBits;
    qint32 mUpTransFlowCtl;
    quint32 mLowerTransPort;/*下位机收发器的波特率*/
    qint32 mLowerTransParity;
    qint32 mLowerTransDataBits;
    qint32 mLowerTransStopBits;
    qint32 mLowerTransFlowCtl;
    qint32 mUperMaxConnTimeOut; /*上位机收发器的最大连接超时时间-单位ms*/
    qint32 mLowerMaxConnTimeOut;    /*下位机收发器的最大连接超时时间-单位ms*/
};

class GlobalData
{
public:
    GlobalData();
    static ConfigContext cfgCtx;
};



#endif // GLOBALDATA_H
