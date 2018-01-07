#ifndef FILELOADICDRELOVER_H
#define FILELOADICDRELOVER_H

#include <QObject>
#include "IcdRelover.h"
#include "IO/SerialComm.h"



class FileLoadIcdRelover : public IcdRelover
{
    Q_OBJECT
public:
    enum CmdType{
        CmdTypeConn = 0,
        CmdTypeFileList = 1,
        CmdTypeLoadFile = 2,
        CmdTypeFileCrc = 3,
        CmdTypeDelFile = 4,
        CmdTypeOpenErr = 0xaa,
        CmdTypeInvalid = 0xff,
    };
    union ResponeDs
    {
         char mRawData[257];
         struct ConnDs
         {
             char mType;
         }mConnDs;
         struct FileListDs
         {
             char mType;
             quint16 mFileNo;
             quint32 mFileLen;
             quint16 mFileNum;
             char mFileName[12];
         }mFileListDs;
         struct FileLoadDs
         {
             char mType;
             char mFileContent[256];
         }mFileLoadDs;
         struct FileDelDs
         {
             char mType;
             bool mOk;
         }mFileDelDs;
         struct FileCrcDs
         {
             char mType;
             char mCrc[4];
         }mFileCrcDs;
    };
    FileLoadIcdRelover();
    void openIO(QString serial);
    void reqConn();
    void reqFileList();
    void reqLoadFile(QByteArray fileName);
    void reqDelFile(QByteArray fileName);
    ResponeDs getRespInfo(QByteArray rawFrame);
private:

private:
    CommIO* _io;
};

#endif // FILELOADICDRELOVER_H
