#include "FileLoadIcdRelover.h"

struct ReqCmdDs
{
    char mType;
    char mPayLoad[12];
};

QByteArray genCmd(ReqCmdDs cmd)
{
    QByteArray data;
    data.append((char)0x55);/*命令头*/
    data.append((char)(cmd.mType));/*命令类型*/
    data.append(cmd.mPayLoad, sizeof(cmd.mPayLoad));
    data.append((char)0x00);    /*结束符*/
    /*计算Ckcsum*/
    unsigned char ckcSum = 0;
    for(int i = 0; i < data.length(); ++i)
    {
        ckcSum += (unsigned char)data.at(i);
    }
    data.append(ckcSum);
    return data;
}

FileLoadIcdRelover::FileLoadIcdRelover()
{

}

void FileLoadIcdRelover::reqConn()
{
    ReqCmdDs cmd;
    memset(&cmd, 0, sizeof(cmd));
    cmd.mType = (char)CmdTypeConn;    /*生成连接命令*/
    QByteArray rawData = genCmd(cmd);
    if (_io) _io->wrtData(rawData);
}

void FileLoadIcdRelover::reqFileList()
{
    ReqCmdDs cmd;
    memset(&cmd, 0, sizeof(cmd));
    cmd.mType = (char)CmdTypeFileList;    /*生成请求文件列表命令*/
    QByteArray rawData = genCmd(cmd);
    if (_io) _io->wrtData(rawData);
}

void FileLoadIcdRelover::reqLoadFile(QByteArray fileName)
{
    ReqCmdDs cmd;
    memset(&cmd, 0, sizeof(cmd));
    cmd.mType = (char)CmdTypeLoadFile;    /*生成加载单个文件命令*/
    memcpy(cmd.mPayLoad, fileName.data(), qMin(fileName.length(), sizeof(cmd.mPayLoad)));
    QByteArray rawData = genCmd(cmd);
    if (_io) _io->wrtData(rawData);
}

void FileLoadIcdRelover::reqDelFile(QByteArray fileName)
{
    ReqCmdDs cmd;
    memset(&cmd, 0, sizeof(cmd));
    cmd.mType = (char)CmdTypeDelFile;    /*生成删除单个文件命令*/
    memcpy(cmd.mPayLoad, fileName.data(), qMin(fileName.length(), sizeof(cmd.mPayLoad)));
    QByteArray rawData = genCmd(cmd);
    if (_io) _io->wrtData(rawData);
}

FileLoadIcdRelover::ResponeDs FileLoadIcdRelover::getRespInfo(QByteArray rawFrame)
{
    ResponeDs resp;
    memset(&resp, 0, sizeof(resp));
    if (rawFrame.length()!=259&&rawFrame.at(0)!= (char)0x55)
        return resp;
    if (rawFrame.at(1) == (char)0x00)
    {
        /*连接响应*/
        resp.mConnDs.mType = (char)0x00;
    }
    else if (rawFrame.at(1) == (char)0x01)
    {
        /*文件列表*/
        resp.mFileListDs.mType = (char)0x01;
        resp.mFileListDs.mFileNo = (quint16)(rawFrame.mid(2, 2).toUShort());
        resp.mFileListDs.mFileLen = (quint32)(rawFrame.mid(4, 4).toUInt());
        resp.mFileListDs.mFileNum = (quint16)(rawFrame.mid(8, 2).toUShort());
        memcpy(resp.mFileListDs.mFileName, rawFrame.mid(10, 12).data(), sizeof(resp.mFileListDs.mFileName));
    }
    else if (rawFrame.at(1) == (char)0x02)
    {
        /*文件加载内容*/
        resp.mFileLoadDs.mType = (char)0x02;
        memcpy(resp.mFileLoadDs.mFileContent, rawFrame.mid(2, 256), sizeof(resp.mFileLoadDs.mFileContent));
    }
    else if (rawFrame.at(1) == (char)0x03)
    {
        /*文件的CRC*/
        resp.mFileCrcDs.mType = (char)0x03;
        memcpy(resp.mFileCrcDs.mCrc, rawFrame.mid(2, 4), sizeof(resp.mFileCrcDs.mCrc));
    }
    else if (rawFrame.at(1) == (char)0x04)
    {
        /*删除文件*/
        resp.mFileDelDs.mType = (char)0x04
    }
    else if (rawFrame.at(1) == (char)0xaa)
    {
        /*打开文件错误*/
    }
}
