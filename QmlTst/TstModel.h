#ifndef TSTMODEL_H
#define TSTMODEL_H

#include <QObject>
#include <QList>

class TstModel : public QObject
{
    Q_OBJECT
public:
    explicit TstModel(QObject *parent = 0);
    Q_INVOKABLE QList<qreal> getTorList();
    Q_INVOKABLE QList<qreal> getTimeSpan();
    Q_INVOKABLE int getListNum();
signals:

public slots:
};

#endif // TSTMODEL_H
