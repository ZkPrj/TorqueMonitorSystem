#include "TstModel.h"

TstModel::TstModel(QObject *parent) : QObject(parent)
{

}

QList<qreal> TstModel::getTorList()
{
    QList<qreal> list;
    list.append(1.1);
    list.append(2.0);
    list.append(2.1);
    list.append(2.2);
    return list;
}

QList<qreal> TstModel::getTimeSpan()
{
    QList<qreal> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    return list;
}

int TstModel::getListNum()
{
    return 4;
}
