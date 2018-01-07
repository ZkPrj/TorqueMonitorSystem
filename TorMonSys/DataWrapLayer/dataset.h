#ifndef DATASET_H
#define DATASET_H

#include <QString>



struct UperArgsStruct
{
    quint32 mMangArgUid;    /*管理参数的唯一标识*/
    quint32 mPipeArgUid;    /*套管参数的唯一标识*/

    quint32 mMaxTor;        /*最大扭矩*/
    quint32 mMinTor;        /*最小扭矩*/
    quint32 mCtlTor;        /*控制扭矩*/
    quint32 mDrawTor;       /*划线扭矩*/
};

struct TorInfoStruct
{
    quint32 mCurTor;    /*当前扭矩*/
    quint32 mCurCycles; /*当前圈数*/
    quint32 mPipeNo;    /*套管编号*/
};

/*输出： 与下位机收发器通信的DataSet*/
struct OutLowerTransceiverDataSet
{
    bool mReqFilesList; /*请求文件列表*/
    quint8 mReqFilesListUnUpdateNum;
    bool mReqFilesListValid;

    QByteArray mFileName; /*请求下载的文件名*/
    quint8 mFileNameUnUpdateNum;
    bool mFileNameValid;

    QByteArray mDelFileName; /*请求删除的文件名*/
    quint8 mDelFileNameUnUpdateNum;
    bool mDelFileNameValid;
};

struct FileInfo
{
    quint32 mFileNum;
    quint32 mCurFileNo;
    QByteArray mFileName;
};

/*输入： 与下位机收发器通信的DataSet*/
/*
 * 注意：下位收发器中定义的数据有效性与上位机收发器中定义的数据有效性含义不一致
 * 下位机数据有效性：该缓冲区中存在数据，则数据有效;否则，数据无效
 * 上位机数据有效性：该缓冲区内在几个周期内有数据更新，则数据有效；否则，数据无效
*/
struct InLowerTransceiverDataSet
{
    QList<FileInfo> mFileList; /*文件列表*/
    bool mFileListValid;

    QByteArray mFileContent;   /*文件内容*/
    bool mFileContenValid;

    quint8 mFileCrc[4]; /*CRC校验码*/
    bool mFileCrcValid;

    bool mDelFlag;  /*是否删除文件成功*/
    bool mDelFlagValid; /*删除文件成功标志位*/
};

/*输出： 与上位机收发器通信的Dataset*/
struct OutUperTransceiverDataSet
{
    quint32 mCommType; /*通信类型*/
    quint8 mCommTypeUnpdateNum;
    bool mCommTypeValid;

    quint32 mCtlTor; /*控制扭矩*/
    quint8 mCtlTorUnUpdateNum;
    bool mCtlTorValid;
    quint32 mDrawTor; /*画线扭矩*/
    quint8 mDrawTorUnUpdateNum;
    bool mDrawTorValid;
    quint32 mCycleMax; /*最大圈数*/
    quint8 mCycleMaxUnUpdateNum;
    bool mCycleMaxValid;
    quint32 mDateTime; /*时间日期，距离1970-1-1的时间*/
    quint8 mDateTimeUnUpdateNum;
    bool mDateTimeValid;
    quint32 mPipeNo; /*杆号*/
    quint8 mPipeNoUnUpdateNum;
    bool mPipeNoValid;
    quint32 mCorrFactor; /*修正系数*/
    quint8 mCorrFactorUnUpdateNum;
    bool mCorrFactorValid;
    quint32 mDelayTime; /*延迟时间*/
    quint8 mDelayTimeUnUpdateNum;
    bool mDelayTimeValid;
    quint32 mWellNo; /*井号*/
    quint8 mWellNoUnUpdateNum;
    bool mWellNoValid;
    quint32 mAddID;  /*附加的ID*/
    quint8 mAddIDUnUpdateNum;
    bool mAddIDValid;

    quint32 mEchoCtlTor;/*响应的控制扭矩*/
    quint8 mEchoCtlTorUnUpdateNum;
    bool mEchoCtlTorValid;
    quint32 mEchoDrawTor;/*响应的画线扭矩*/
    quint8 mEchoDrawTorUnUpdateNum;
    bool mEchoDrawTorValid;
    quint32 mEchoCycleMax;/*响应的圈数最大值*/
    quint8 mEchoCycleMaxUnUpdateNum;
    bool mEchoCycleMaxValid;
    quint32 mEchoDateTime;/*响应的日期时间*/
    quint8 mEchoDateTimeUnUpdateNum;
    bool mEchoDateTimeValid;
    quint32 mEchoPipeNo;/*响应的套管编号*/
    quint8 mEchoPipeNoUnUpdateNum;
    bool mEchoPipeNoValid;
    quint32 mEchoCorrFactor;/*响应的修正系数*/
    quint8 mEchoCorrFactorUnUpdateNum;
    bool mEchoCorrFactorValid;
    quint32 mEchoDelayTime;/*响应的延迟时间*/
    quint8 mEchoDelaytTimeUnUpdateNum;
    bool mEchoDelayTimeValid;
    quint32 mEchoWellNo; /*响应的井号*/
    quint8 mEchoWellUnUpdateNum;
    bool mEchoWellNoValid;
    quint32 mEchoAddID;  /*附加的ID*/
    quint8 mEchoAddIDUnUpdateNum;
    bool mEchoAddIDValid;
};

/*输入： 与上位机收发器通信的Dataset*/
struct InUperTransceiverDataSet
{
    char mConnCmd;  /*连接响应*/
    quint8 mConnCmdUnUpdateNum; /*数据未更新次数*/
    bool mConnCmdValid;
    quint32 mCommType; /*通信类型*/
    quint8 mCommTypeUnpdateNum;
    bool mCommTypeValid;
    quint32 mCurTor;/*当前扭矩*/
    quint8 mCurTorUnUpdateNum;
    bool mCurTorValid;
    quint32 curPipe; /*当前杆号*/
    quint8 mCurPipeUnUpdateNum;
    bool mCurPipeValid;
    quint8 mCycleNum;   /*当前圈数*/
    quint8 mCycleUnUpdateNum;
    bool mCycleNumValid;
    quint32 mReleaseStatus; /*协议状态*/
    quint8 mReleaseStatusUnUpdateNum;
    bool mReleaseStatusValid;
    quint32 mCtlTor; /*控制扭矩*/
    quint8 mCtlTorUnUpdateNum;
    bool mCtlTorValid;
    quint32 mDrawTor; /*画线扭矩*/
    quint8 mDrawTorUnUpdateNum;
    bool mDrawTorValid;
    quint32 mCycleMax; /*最大圈数*/
    quint8 mCycleMaxUnUpdateNum;
    bool mCycleMaxValid;
    quint32 mDateTime; /*时间日期，距离1970-1-1的时间*/
    quint8 mDateTimeUnUpdateNum;
    bool mDateTimeValid;
    quint32 mPipeNo; /*杆号*/
    quint8 mPipeNoUnUpdateNum;
    bool mPipeNoValid;
    quint32 mCorrFactor; /*修正系数*/
    quint8 mCorrFactorUnUpdateNum;
    bool mCorrFactorValid;
    quint32 mDelayTime; /*延迟时间*/
    quint8 mDelayTimeUnUpdateNum;
    bool mDelayTimeValid;
    quint32 mWellNo;
    quint8 mWellNoUnUpdateNum;
    bool mWellNoValid;
    quint32 mAddNo; /*附加的ID*/
    quint8 mAddNoUnUpdateNum;
    bool mAddNoValid;


    quint32 mEchoCtlTor;/*响应的控制扭矩*/
    quint8 mEchoCtlTorUnUpdateNum;
    bool mEchoCtlTorValid;
    quint32 mEchoDrawTor;/*响应的画线扭矩*/
    quint8 mEchoDrawTorUnUpdateNum;
    bool mEchoDrawTorValid;
    quint32 mEchoCycleMax;/*响应的圈数最大值*/
    quint8 mEchoCycleMaxUnUpdateNum;
    bool mEchoCycleMaxValid;
    quint32 mEchoDateTime;/*响应的日期时间*/
    quint8 mEchoDateTimeUnUpdateNum;
    bool mEchoDateTimeValid;
    quint32 mEchoPipeNo;/*响应的套管编号*/
    quint8 mEchoPipeNoUnUpdateNum;
    bool mEchoPipeNoValid;
    quint32 mEchoCorrFactor;/*响应的修正系数*/
    quint8 mEchoCorrFactorUnUpdateNum;
    bool mEchoCorrFactorValid;
    quint32 mEchoDelayTime;/*响应的延迟时间*/
    quint8 mEchoDelaytTimeUnUpdateNum;
    bool mEchoDelayTimeValid;
    quint32 mEchoWellNo; /*响应的井号*/
    quint8 mEchoWellUnUpdateNum;
    bool mEchoWellNoValid;
    quint32 mEchoAddID;  /*附加的ID*/
    quint8 mEchoAddIDUnUpdateNum;
    bool mEchoAddIDValid;
};


#endif // DATASET_H
