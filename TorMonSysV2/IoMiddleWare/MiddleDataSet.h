#ifndef MIDDLEDATASET_H
#define MIDDLEDATASET_H

#include <QString>

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
    quint32 mTongArmLen; /*钳臂长*/
    quint8 mTongArmLenUnUpdateNum;
    bool mTongArmLenValid;

    quint32 mSetCtlTor;/*响应的控制扭矩*/
    quint8 mSetCtlTorUnUpdateNum;
    bool mSetCtlTorValid;
    quint32 mSetDrawTor;/*响应的画线扭矩*/
    quint8 mSetDrawTorUnUpdateNum;
    bool mSetDrawTorValid;
    quint32 mSetCycleMax;/*响应的圈数最大值*/
    quint8 mSetCycleMaxUnUpdateNum;
    bool mSetCycleMaxValid;
    quint32 mSetDateTime;/*响应的日期时间*/
    quint8 mSetDateTimeUnUpdateNum;
    bool mSetDateTimeValid;
    quint32 mSetPipeNo;/*响应的套管编号*/
    quint8 mSetPipeNoUnUpdateNum;
    bool mSetPipeNoValid;
    quint32 mSetCorrFactor;/*响应的修正系数*/
    quint8 mSetCorrFactorUnUpdateNum;
    bool mSetCorrFactorValid;
    quint32 mSetDelayTime;/*响应的延迟时间*/
    quint8 mSetDelaytTimeUnUpdateNum;
    bool mSetDelayTimeValid;
    quint32 mSetWellNo; /*响应的井号*/
    quint8 mSetWellUnUpdateNum;
    bool mSetWellNoValid;
    quint32 mSetAddID;  /*附加的ID*/
    quint8 mSetAddIDUnUpdateNum;
    bool mSetAddIDValid;
    quint32 mSetTongArmLen; /*设置钳臂长*/
    quint8 mSetTongArmLenUnUpdateNum;
    bool mSetTongArmLenValid;
    quint32 mSetCtlMode;    /*设置控制模式*/
    quint8 mSetCtlModeUnUpdateNum;
    bool mSetCtlModeValid;
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
    quint32 mCurPipe; /*当前杆号*/
    quint8 mCurPipeUnUpdateNum;
    bool mCurPipeValid;
    quint8 mCurCycle;   /*当前圈数*/
    quint8 mCurCycleUnUpdateNum;
    bool mCurCycleValid;
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
    quint32 mTongArmLen; /*钳臂长*/
    quint8 mTongArmLenUnUpdateNum;
    bool mTongArmLenValid;


    quint32 mSetCtlTor;/*响应的控制扭矩*/
    quint8 mSetCtlTorUnUpdateNum;
    bool mSetCtlTorValid;
    quint32 mSetDrawTor;/*响应的画线扭矩*/
    quint8 mSetDrawTorUnUpdateNum;
    bool mSetDrawTorValid;
    quint32 mSetCycleMax;/*响应的圈数最大值*/
    quint8 mSetCycleMaxUnUpdateNum;
    bool mSetCycleMaxValid;
    quint32 mSetDateTime;/*响应的日期时间*/
    quint8 mSetDateTimeUnUpdateNum;
    bool mSetDateTimeValid;
    quint32 mSetPipeNo;/*响应的套管编号*/
    quint8 mSetPipeNoUnUpdateNum;
    bool mSetPipeNoValid;
    quint32 mSetCorrFactor;/*响应的修正系数*/
    quint8 mSetCorrFactorUnUpdateNum;
    bool mSetCorrFactorValid;
    quint32 mSetDelayTime;/*响应的延迟时间*/
    quint8 mSetDelaytTimeUnUpdateNum;
    bool mSetDelayTimeValid;
    quint32 mSetWellNo; /*响应的井号*/
    quint8 mSetWellUnUpdateNum;
    bool mSetWellNoValid;
    quint32 mSetAddID;  /*附加的ID*/
    quint8 mSetAddIDUnUpdateNum;
    bool mSetAddIDValid;
    quint32 mSetTongArmLen; /*设置钳臂长*/
    quint8 mSetTongArmLenUnUpdateNum;
    bool mSetTongArmLenValid;
    quint32 mSetCtlMode;    /*设置控制模式*/
    quint8 mSetCtlModeUnUpdateNum;
    bool mSetCtlModeValid;
};



#endif // MIDDLEDATASET_H
