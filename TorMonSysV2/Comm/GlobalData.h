#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <QObject>
#include <QString>
#include <QFile>

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
    static GlobalData *getInstance();
    ConfigContext getConfigData();
    void writeLog(QString log);
    ~GlobalData();
protected:
    GlobalData();
    void loadAndParseCfgData();
    void initLogFile();

private:
    static GlobalData* _self;
    static QString _cfgFilePath;
    static QString _logFilePath;
    ConfigContext _cfgCxt;
    QFile* _logFile;
};

#endif // GLOBALDATA_H
