#ifndef COMMIO_H
#define COMMIO_H

#include <QObject>
#include <QByteArray>
#include <QVariant>



class CommIO
{
public:

    enum CommStatus
    {
        CommStatusDisconn,  /*未连接*/
        CommStatusOnConning,    /*建立连接中*/
        CommStatusConned,      /*连接上了*/
        CommStatusUnknown,      /*未知的连接状态*/
    };

    CommIO(){}
    ~CommIO() {}
    CommStatus getCurStatus(){return _status;} /*获取当前连接状态*/

    void setConnProps(bool reConn){_autoReConn = reConn;}
    virtual CommStatus conn2Edp(void*) = 0;
    virtual CommStatus reConn() = 0;
    virtual CommStatus disConn() = 0;
    virtual qint32 wrtData(QByteArray)  = 0;
    virtual QByteArray rcvData() = 0;

protected:
    CommStatus _status;
    bool _autoReConn;
};



#endif // COMMIO_H
