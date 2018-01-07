#ifndef ICDRELOVER_H
#define ICDRELOVER_H

#include <QObject>
#include <QList>

enum ConnStatusType
{
    ConnStatusUnKnown = 0, /*未知状态*/
    ConnStatusConnecting = 1, /*正在连接过程中*/
    ConnStatusConnOk = 2, /*连接成功*/
    ConnStatusUnConn = 3, /*未连接*/
};


class IcdRelover : public QObject
{
    Q_OBJECT
public:
    explicit IcdRelover(QObject *parent = 0);

    virtual  void conn2Edp() = 0;
    virtual ConnStatusType getConnStatus() = 0;
    virtual void setData(void* data) = 0;
    virtual QByteArray getData() = 0;

protected:
    virtual void getRawData() = 0;
    virtual QList<QByteArray> fetchFrames() = 0;
    virtual void unWrapFrames(QList<QByteArray> frames)= 0;
    virtual void stepSndData() = 0;

signals:

public slots:
};

#endif // ICDRELOVER_H
