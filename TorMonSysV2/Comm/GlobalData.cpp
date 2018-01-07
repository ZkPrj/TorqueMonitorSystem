#include "GlobalData.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>


QString GlobalData::_cfgFilePath = "..\\Cfg.dat";
QString GlobalData::_logFilePath = "..\\log.dat";
GlobalData* GlobalData::_self = NULL;

GlobalData *GlobalData::getInstance()
{
    if (!_self)
    {
        _self = new GlobalData;
    }
    return _self;
}

ConfigContext GlobalData::getConfigData()
{
    return _cfgCxt;
}

void GlobalData::writeLog(QString log)
{
    QByteArray data;
    data.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") +" "+log + "\n");
    _logFile->write(data);
    _logFile->flush();
}

GlobalData::~GlobalData()
{
    _logFile->close();
    _logFile->deleteLater();
}

GlobalData::GlobalData()
{
    initLogFile();
    loadAndParseCfgData();
}

void GlobalData::loadAndParseCfgData()
{
    writeLog("\n==========================================\n");
    writeLog("启动程序，并开始解析配置文件......");
    QFile cfg(_cfgFilePath);
    cfg.open(QIODevice::ReadOnly);
    QByteArray cfgData = cfg.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(cfgData);
    QJsonObject jsonDoc = doc.object();

    _cfgCxt.mUpTransPort = jsonDoc["UperPort"].toInt();
    _cfgCxt.mLowerTransPort = jsonDoc["LowerPort"].toInt();
    _cfgCxt.mUperMaxConnTimeOut = jsonDoc["UperTimeOut"].toInt();
    _cfgCxt.mLowerMaxConnTimeOut = jsonDoc["LowerTimeOut"].toInt();
    _cfgCxt.mUpTransParity = jsonDoc["UperParity"].toInt();
    _cfgCxt.mUpTransDataBits = jsonDoc["UperDataBit"].toInt();
    _cfgCxt.mUpTransStopBits = jsonDoc["UperStopBit"].toInt();
    _cfgCxt.mUpTransFlowCtl = jsonDoc["UperFlowCtl"].toInt();
    _cfgCxt.mLowerTransParity = jsonDoc["LowerParity"].toInt();
    _cfgCxt.mLowerTransDataBits = jsonDoc["LowerDataBit"].toInt();
    _cfgCxt.mLowerTransStopBits = jsonDoc["LowerStopBit"].toInt();
    _cfgCxt.mLowerTransFlowCtl = jsonDoc["LowerFlowCtl"].toInt();
    writeLog("解析配置文件成功");

}

void GlobalData::initLogFile()
{
    _logFile = new QFile(_logFilePath);
    _logFile->open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
}
