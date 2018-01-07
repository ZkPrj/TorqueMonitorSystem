#ifndef SHAREDDATADEF_H
#define SHAREDDATADEF_H
#include <QString>

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



#endif // SHAREDDATADEF_H
