#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QObject>

#include <QtSql/QSqlDriver>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include "SerialComm.h"

struct TorRtDataStruct
{
    quint32 mWellNo;
    quint32 mPipeNo;
    quint32 mRtTor;
    quint32 mRtCycle;
    quint32 mTimeSpan;
    quint32 mStartTime;
    quint32 mAddId;
};

QList<TorRtDataStruct> searchTorData(QSqlDatabase _db, quint32 wellNo, quint32 pipeNo)
{
    QList<TorRtDataStruct> list;
    if (_db.isOpen())
    {
        QString cmd = QString("select * from TorqueRecord where WellNo=%1 and PipeNo = %2");
        cmd = cmd.arg(wellNo).arg(pipeNo);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            while(qery.next())
            {
                TorRtDataStruct element;
                element.mRtCycle = qery.value("CycleNum").toUInt();
                element.mRtTor = qery.value("Torque").toUInt();
                element.mWellNo = qery.value("WellNo").toUInt();
                element.mPipeNo = qery.value("PipeNo").toUInt();
                element.mTimeSpan = qery.value("TimeSpan").toUInt();
                element.mStartTime = qery.value("StartTime").toUInt();
                element.mAddId = qery.value("AddPropId").toUInt();
                list.append(element);
            }
        }
    }
    else
    {
        //createConn();
    }
    return list;
}

QString deleteRtTorPipeData(quint32 wellNo, quint32 pipeNo)
{
    QString cmd;
    if (1)
    {
        cmd = QString("delete from TorqueRecord where WellNo=%1 and PipeNo = %2");
        cmd = cmd.arg(wellNo).arg(pipeNo);
    }
    return cmd;
}

bool insertTorPipCycleList(QSqlDatabase _db, QList<TorRtDataStruct> data)
{
    if (_db.isOpen())
    {
        if (_db.transaction())
        {
            QSqlQuery qery(_db);

            for(TorRtDataStruct rtData:data)
            {
                QString cmd = QString("insert into TorqueRecord values (%1,%2,%3,%4,%5,%6,%7)");
                cmd = cmd.arg(rtData.mRtCycle).arg(rtData.mRtTor).arg(rtData.mWellNo).arg(rtData.mPipeNo).arg(rtData.mTimeSpan).arg(rtData.mStartTime).arg(rtData.mAddId);
                qery.exec(cmd);
            }
            return _db.commit();
        }
    }
    return false;
}

QString insertManageData(quint32 id, QString deleComp, QString exeComp, QString collabComp, QString machineNo, QString hydClamp, QString areaNo, QString wellNo, QString ownerSuper, QString techDir, QString remark)
{
    QString cmd;
    if (1)
    {
        deleComp = deleComp.replace("'", "''");
        exeComp = exeComp.replace("'", "''");
        collabComp = collabComp.replace("'", "''");
        machineNo = machineNo.replace("'", "''");
        hydClamp = hydClamp.replace("'", "''");
        areaNo = areaNo.replace("'", "''");
        wellNo = wellNo.replace("'", "''");
        ownerSuper = ownerSuper.replace("'", "''");
        techDir = techDir.replace("'", "''");
        remark = remark.replace("'", "''");

        cmd = QString("insert into ManageProperty values (\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\',\'%8\',\'%9\',\'%10\',\'%11\')");
        cmd = cmd.arg(deleComp).arg(exeComp).arg(collabComp).arg(machineNo).arg(hydClamp).arg(areaNo).arg(wellNo).arg(id).arg(ownerSuper).arg(techDir).arg(remark);
    }
    return cmd;
}

QString insertPipeData(quint32 id, QString pipeName, QString pipeType, QString pipeDiameter, QString pipeClass, QString pipeThickness)
{
    QString cmd;
    if (1)
    {
        pipeName = pipeName.replace("'", "''");
        pipeType = pipeType.replace("'", "''");
        pipeDiameter = pipeDiameter.replace("'", "''");
        pipeClass = pipeClass.replace("'", "''");
        pipeThickness = pipeThickness.replace("'", "''");

        cmd = QString("insert into PipeProperty values (\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\')");
        cmd = cmd.arg(pipeName).arg(pipeType).arg(pipeDiameter).arg(pipeClass).arg(pipeThickness).arg(id);
    }
    return cmd;
}

QString insertTechData(quint32 id, qreal tongArmLen, qreal corrFactor, qreal delayTime, qreal minStep, qreal maxStep)
{
    QString cmd;
    if (1)
    {

        cmd = QString("insert into TechProperty values (%1,%2,%3,%4,%5,%6)");
        cmd = cmd.arg(tongArmLen).arg(corrFactor).arg(delayTime).arg(minStep).arg(maxStep).arg(id);

    }
    return cmd;
}

QString insertDspData(quint32 id, qreal maxTor, qreal minTor, qreal bestTor, qreal ctlTor, qreal drawTor, int maxTime, int maxCycle)
{
    QString cmd;
    if (1)
    {
        cmd = QString("insert into DisplayConstraint values (%1,%2,%3,%4,%5,%6,%7,%8)");
        cmd = cmd.arg(maxTor).arg(minTor).arg(bestTor).arg(ctlTor).arg(drawTor).arg(maxTime).arg(maxCycle).arg(id);
    }
    return cmd;
}

typedef union
{
    quint8 data[16];
    struct
    {
        quint8 mHead;
        quint8 mType;
        quint8 mData[13];
        quint8 mCkcSum;
    }normalData;
}LowerOutRawDataStruct;

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   qreal real = 3.9;
   int b = 3;
   real = b;
   b = real;
   qDebug()<<real<<" "<<b;
   return a.exec();
}

#if 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SerialComm* serialComm = new SerialComm;
    SerialProp serialProp;
    serialProp.mSerialName = "COM16";
    if (argc == 2)
    {
        serialProp.mSerialName = argv[1];
    }

    serialProp.mBaudRate = 115200;
    serialProp.mDataBits = 8;
    serialProp.mFlowControl = 0;
    serialProp.mParity = 0;
    serialProp.mStopBits = 1;
    CommIO::CommStatus status = serialComm->conn2Edp(&serialProp);

    /*往串口发送两个字节*/
    LowerOutRawDataStruct data;
    memset(&data, 0, sizeof(data));
    data.normalData.mHead = 0x55;
    data.normalData.mType = 0;
    data.normalData.mCkcSum = 0x55;
    serialComm->wrtData(QByteArray((char*)&data, sizeof(data)));
    while(1)
    {
        QByteArray datas = serialComm->rcvData();
        if (datas.length() > 0)
        {
            qDebug()<<"Rcv: "<<datas;
        }
    }
    return a.exec();
}
#endif


#if 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile loadFile("c:/cfg.dat");
    loadFile.open(QIODevice::ReadOnly);
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDc = QJsonDocument::fromJson(saveData);
    QJsonObject obj = loadDc.object();
    QString name = obj["FirstName"].toString();
    int age = obj["Age"].toInt();
    int year = obj["Year"].toInt();
    qDebug()<<name<<" "<<age;

    QString str = QString("'abc'").replace("'", "''");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "torSql");
    db.setDatabaseName("..\\TorqueSystem.db");
    if (!db.open())
    {
        qDebug()<<"Failed to conn to db";
    }
    QSqlQuery qery(db);
    QString cmd = QString("update IdIndexTable set ManageId = %2,"
                  "DispConstId = %3,"
                  "PipePropId = %4,"
                  "TechPropId = %5 where UniNo = %1");
    cmd = cmd.arg(1).arg(2).arg(1).arg(1).arg(1);
    //qery.prepare(cmd);
    cmd = insertManageData(7,
                           "交大",
                           "\'\'技启",
                           "jiaoDa",
                           "1234",
                           "液压大钳",
                           "#003",
                           "A001",
                           "张凯",
                           "张凯",
                           "备注-空");
    //cmd = insertPipeData(8, "P1\'", "PT1\'\'", "P'D1", "P''C1", "PT1");
    cmd = insertTechData(5, 10.3, 2.3, 4, 11.00, 24.32);
    cmd = insertDspData(5, 100000, 30000, 80000, 70000, 50000, 16, 50);

    QList<TorRtDataStruct> list;
    TorRtDataStruct d1 = {1,1,1000,12,25,23666,1};
    list.append(d1);
    TorRtDataStruct d2 = {1,2,1200,13,28,23666,1};
    list.append(d2);
    TorRtDataStruct d3 = {1,3,1230,14,28,23666,1};
    list.append(d3);
    bool exe = insertTorPipCycleList(db, list);
    list = searchTorData(db, 1, 2);
    //cmd = deleteRtTorPipeData(1, 1);
    //bool exe = qery.exec(cmd);
    if (!exe)
    {
        qDebug()<<qery.lastError().type()<<"\n"<<qery.lastError().text();
    }
    while(qery.next())
    {
        qDebug()<<"MaxTor: "<<qery.value("MaxTorque").toInt();
        qDebug()<<"MinTor: "<<qery.value("MinTorque").toInt();
        qDebug()<<"DelegateCompany: "<<qery.value("DelegateCompany").toString();
        qDebug()<<"ExeCompany: "<<qery.value("ExeCompany").toString();
    }
    return a.exec();
}



typedef union
{
    quint8 data[259];
    struct
    {
        quint8 mHead;
        quint8 mType;
        quint8 mReverse[256];
        quint8 mCkcSum;
    }connData;
}LowerInRawDataStruct;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LowerInRawDataStruct data;
    memcpy(data.data, "abcdefg", 8);
    qDebug()<<data.connData.mHead;
    qDebug()<<data.connData.mType;
    qDebug()<<sizeof(LowerInRawDataStruct);
    return a.exec();
}
#endif
