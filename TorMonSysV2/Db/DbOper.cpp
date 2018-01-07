#include "DbOper.h"
#include <QVariant>

DbOper* DbOper::_self = 0;

DbOper *DbOper::getDbOper()
{
    if (!_self)
    {
        _self = new DbOper();
    }
    return _self;
}

TorAddtionalDataStruct DbOper::searchAddtionalData(quint32 id)
{
    TorAddtionalDataStruct data = {0};
    if (_db.isOpen())
    {
        QString cmd = QString("select a.DelegateCompany, a.ExeCompany, a.CollabCompany,"
                              "a.MachineNo, a.HydClamp, a.AreaNo, a.WellNo, a.OwnerSuper,"
                              "a.TechDir, a.Remark,"
                              "b.PipeName, b.PipeType, b.PipeDiameter, b.PipeClass,"
                              "b.PipeThickness,"
                              "c.TongArmLen, c.CorrFactor, c.DelayTime, c.MinStep,"
                              "c.MaxStep, "
                              "d.MaxTorque, d.MinTorque, d.BestTorque, d.CtlTorque,"
                              "d.DrawTorque, d.MaxTime, d.MaxCycle "
                              "from IdIndexTable, ManageProperty as a, PipeProperty as b,"
                              "TechProperty as c, DisplayConstraint as d "
                              "where IdIndexTable.ManageId = a.UniNo and "
                              "IdIndexTable.PipePropId = b.UniNo and "
                              "IdIndexTable.TechPropId = c.UniNo and "
                              "IdIndexTable.DispConstId = d.UniNo and "
                              "IdIndexTable.UniNo = %1");
        cmd = cmd.arg(id);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret) /*查询成功*/
        {
            if (qery.next())/*只取第一组数据，理论上也只会有一组数据*/
            {
                data.mDelegateComp = qery.value("DelegateCompany").toString();
                data.mExeComp = qery.value("ExeCompany").toString();
                data.mCollabComp = qery.value("CollabCompany").toString();
                data.mMachinNo = qery.value("MachineNo").toString();
                data.mHydClamp = qery.value("HydClamp").toString();
                data.mAreaNo = qery.value("AreaNo").toString();
                data.mWellNo = qery.value("WellNo").toString();
                data.mOwnerSuper = qery.value("OwnerSuper").toString();
                data.mTechDir = qery.value("TechDir").toString();
                data.mRemark = qery.value("Remark").toString();
                data.mPipeName = qery.value("PipeName").toString();
                data.mPipeType = qery.value("PipeType").toString();
                data.mPipeDiameter = qery.value("PipeDiameter").toString();
                data.mPipeClass = qery.value("PipeClass").toString();
                data.mPipeThickness = qery.value("PipeThickness").toString();
                data.mTongArmLen = qery.value("TongArmLen").toFloat();
                data.mCorrFactor = qery.value("CorrFactor").toFloat();
                data.mDelayTime = qery.value("DelayTime").toFloat();
                data.mMinStep = qery.value("MinStep").toFloat();
                data.mMaxStep = qery.value("MaxStep").toFloat();
                data.mMaxTor = qery.value("MaxTorque").toFloat();
                data.mMinTor = qery.value("MinTorque").toFloat();
                data.mBestTor = qery.value("BestTorque").toFloat();
                data.mCtlTor = qery.value("CtlTorque").toFloat();
                data.mDrawTor = qery.value("DrawTorque").toFloat();
                data.mMaxTime = qery.value("MaxTime").toFloat();
                data.mMaxCycle = qery.value("MaxCycle").toFloat();
            }
        }
    }
    else
    {
        createConn();
    }
    return data;
}

bool DbOper::insertId(quint32 id, quint32 manId, quint32 techId, quint32 pipeId, quint32 dispId)
{
    if (_db.isOpen())
    {
        QString cmd = QString("insert into IdIndexTable values(%1,%2,%3,%4,%5)");
        cmd = cmd.arg(id).arg(manId).arg(dispId).arg(pipeId).arg(techId);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
        else
        {
            cmd = QString("update IdIndexTable set ManageId = %2,"
                          "DispConstId = %3,"
                          "PipePropId = %4,"
                          "TechPropId = %5 where UniNo = %1");
            cmd = cmd.arg(id).arg(manId).arg(dispId).arg(pipeId).arg(techId);
            qery.exec(cmd);
            if (ret) return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

bool DbOper::insertManageData(quint32 id, QString deleComp, QString exeComp, QString collabComp, QString machineNo, QString hydClamp, QString areaNo, QString wellNo, QString ownerSuper, QString techDir, QString remark)
{
    if (_db.isOpen())
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

        QString cmd = QString("insert into ManageProperty values (\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\',\'%8\',\'%9\',\'%10\',\'%11\')");
        cmd = cmd.arg(deleComp).arg(exeComp).arg(collabComp).arg(machineNo).arg(hydClamp).arg(areaNo).arg(wellNo).arg(id).arg(ownerSuper).arg(techDir).arg(remark);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

bool DbOper::insertPipeData(quint32 id, QString pipeName, QString pipeType, QString pipeDiameter, QString pipeClass, QString pipeThickness)
{
    if (_db.isOpen())
    {
        pipeName = pipeName.replace("'", "''");
        pipeType = pipeType.replace("'", "''");
        pipeDiameter = pipeDiameter.replace("'", "''");
        pipeClass = pipeClass.replace("'", "''");
        pipeThickness = pipeThickness.replace("'", "''");

        QString cmd = QString("insert into PipeProperty values (\'%1\',\'%2\',\'%3\',\'%4\',\'%5\',\'%6\')");
        cmd = cmd.arg(pipeName).arg(pipeType).arg(pipeDiameter).arg(pipeClass).arg(pipeThickness).arg(id);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

bool DbOper::insertTechData(quint32 id, qreal tongArmLen, qreal corrFactor, qreal delayTime, qreal minStep, qreal maxStep)
{
    if (_db.isOpen())
    {

        QString cmd = QString("insert into TechProperty values (%1,%2,%3,%4,%5,%6)");
        cmd = cmd.arg(tongArmLen).arg(corrFactor).arg(delayTime).arg(minStep).arg(maxStep).arg(id);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

bool DbOper::insertDspData(quint32 id, qreal maxTor, qreal minTor, qreal bestTor, qreal ctlTor, qreal drawTor, int maxTime, int maxCycle)
{
    if (_db.isOpen())
    {

        QString cmd = QString("insert into DisplayConstraint values (%1,%2,%3,%4,%5,%6,%7,%8)");
        cmd = cmd.arg(maxTor).arg(minTor).arg(bestTor).arg(ctlTor).arg(drawTor).arg(maxTime).arg(maxCycle).arg(id);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

bool DbOper::insertTorPipCycleList(QList<TorRtDataStruct> data)
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
            if (!_db.commit())
            {
                _db.rollback();
                return false;
            }
            return true;
        }
    }
    return false;
}

bool DbOper::deleteRtTorPipeData(quint32 wellNo, quint32 pipeNo)
{
    if (_db.isOpen())
    {
        QString cmd = QString("delete from TorqueRecord where WellNo=%1 and PipeNo = %2");
        cmd = cmd.arg(wellNo).arg(pipeNo);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            return true;
        }
    }
    else
    {
        createConn();
    }
    return false;
}

QList<TorRtDataStruct> DbOper::searchTorData(quint32 wellNo, quint32 pipeNo)
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
        createConn();
    }
    return list;
}

quint32 DbOper::getMaxIdIndexId()
{
    if (_db.isOpen())
    {
        QString cmd = QString("select Max(UniNo) from IdIndexTable");
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                return qery.value(0).toUInt();
            }
        }
    }
    else
    {
        createConn();
    }
    return 0;
}

quint32 DbOper::getMaxManageId()
{
    if (_db.isOpen())
    {
        QString cmd = QString("select Max(UniNo) from ManageProperty");
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                return qery.value(0).toUInt();
            }
        }
    }
    else
    {
        createConn();
    }
    return 0;
}

quint32 DbOper::getMaxPipeId()
{
    if (_db.isOpen())
    {
        QString cmd = QString("select Max(UniNo) from PipeProperty");
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                return qery.value(0).toUInt();
            }
        }
    }
    else
    {
        createConn();
    }
    return 0;
}

quint32 DbOper::getMaxDspId()
{
    if (_db.isOpen())
    {
        QString cmd = QString("select Max(UniNo) from DisplayConstraint");
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                return qery.value(0).toUInt();
            }
        }
    }
    else
    {
        createConn();
    }
    return 0;
}

bool DbOper::getIdByAddId(quint32 addId, quint32 &mangeId, quint32 &dspId, quint32 &pipId, quint32 &techId)
{
    if (_db.isOpen())
    {
        QString cmd = QString("select * from IdIndexTable where UniNo=%1");
        cmd = cmd.arg(addId);
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                mangeId = qery.value("ManageId").toUInt();
                dspId = qery.value("DispConstId").toUInt();
                pipId = qery.value("PipePropId").toUInt();
                techId = qery.value("TechPropId").toUInt();
                return true;
            }
        }

    }
    else
    {
        createConn();
    }
    return false;
}

quint32 DbOper::getMaxTechId()
{
    if (_db.isOpen())
    {
        QString cmd = QString("select Max(UniNo) from TechProperty");
        QSqlQuery qery(_db);
        bool ret = qery.exec(cmd);
        if (ret)
        {
            if (qery.next())
            {
                return qery.value(0).toUInt();
            }
        }
    }
    else
    {
        createConn();
    }
    return 0;
}

DbOper::DbOper()
{
    createConn();
}

bool DbOper::createConn()
{
    _db = QSqlDatabase::addDatabase("QSQLITE", "torSql");
    _db.setDatabaseName("..\\TorqueSystem.db");
    if (!_db.open())
    {
        /*无法连接数据库*/
        return false;
    }
    return true;
}
