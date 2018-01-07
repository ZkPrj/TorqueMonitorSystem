import QtQuick 2.5
import QtQuick.Window 2.2
Window {
    id:windowpage;
    visible: true;
    width:800;
    height:600;
    title: qsTr("Niujuyi");
    /************QML输入参数************/
    property bool netStatus:false;/*实时状态参数，true:实时状态可用，false：实时状态不可用*/
    property int filedownloadProportion:0;/*文件下载比例,默认是0，下载完成为0*/
    property int fileprocessProportion:0;/*文件下载后，处理的比例，默认是0，下载完成为0*/
    property int wireStatus:0;/*有线、无线请求成功后，获取的有线、无线状态，默认是0，有线连接为1，无线连接为2*/

    property string entrustUnit;/*管理参数设置，委托单位*/
    property string operationArea;/*管理参数设置，作业区域*/
    property string operationUnit;/*管理参数设置，作业单位*/
    property string operationWellID;/*管理参数设置，作业井号*/
    property string cooperationUnit;/*管理参数设置，协作单位*/
    property string partyAsupervisor;/*管理参数设置，甲方监督*/
    property string instrmentID;/*管理参数设置，仪器编号*/
    property string technicalDirector;/*管理参数设置，技术负责人*/
    property string hydraulicClamp;/*管理参数设置，液压钳*/

    property string casingName;/*套管参数设置，套管名称*/
    property string casingType;/*套管参数设置，套管型号*/
    property string casingSize;/*套管参数设置，套管尺寸*/
    property string casingSteelgrade;/*套管参数设置，套管钢级*/
    property string casingThick;/*套管参数设置，套管重/厚*/
    property int buckleType;/*套管参数设置，套管扣型选择*/
    property int measureChannel;/*套管参数设置，套管测量通道*/

    property string torqueRange;/*图形参数设置，扭矩量程*/
    property string maxTorque;/*图形参数设置，最大扭矩*/
    property string roundRange;/*图形参数设置，圈数量程*/
    property string minTorque;/*图形参数设置，最小扭矩*/
    property string timeRange;/*图形参数设置，时间量程*/
    property string optimalTorque;/*图形参数设置，最佳量程*/
    property string rpmRange;/*图形参数设置，转速量程*/
    property string controlTorque;/*图形参数设置，控制扭矩*/
    property string rateRange;/*图形参数设置，变化率量程*/
    property string referenceTorque;/*图形参数设置，参考扭矩*/

    property string clampArmlength;/*技术参数设置，钳臂长，需要大于0.01*/
    property string reviseCoefficient;/*技术参数设置，修正系数*/
    property string  pulseNumber;/*技术参数设置，脉冲数*/
    property string threadLubricantOil;/*技术参数设置，丝扣油*/
    property string sensorForce;/*技术参数设置，传感器力*/
    property string delayTime;/*技术参数设置，延迟时间*/
    property string shiftgearTorque;/*技术参数设置，换挡扭矩*/
    property string dampingCoefficient;/*技术参数设置，阻尼系数*/
    property string maxStair;/*技术参数设置，最大台阶*/
    property string minStair;/*技术参数设置，最小台阶*/

    /************QML输出参数************/
    //property int wirestatusRequest:wirechoosePage.wirestatusRequest;/*有线、无线请求参数，0:默认状态，1：请求有线连接，2：请求无线连接*/
    //property int historydataKey:historydatachoosePage.historydataKey/*请求查看历史数据的关键词，1：关键词1，2：关键词2，3：关键词3，4：关键词4*/
    //property int historydataID:historydatachoosePage.historydataID;/*请求显示的历史数据ID*/
    //property bool historydataPrint:printdataPage.printdataComfirm;/*请求显示的历史数据ID*/

    property string entrustUnit_user:realtimemonitorPage.entrustUnit_user;/*用户管理参数设置，委托单位*/
    property string operationArea_user:realtimemonitorPage.operationArea_user;/*用户管理参数设置，作业区域*/
    property string operationUnit_user:realtimemonitorPage.operationUnit_user;/*用户管理参数设置，作业单位*/
    property string operationWellID_user:realtimemonitorPage.operationWellID_user;/*用户管理参数设置，作业井号*/
    property string cooperationUnit_user:realtimemonitorPage.cooperationUnit_user;/*用户管理参数设置，协作单位*/
    property string partyAsupervisor_user:realtimemonitorPage.partyAsupervisor_user;/*用户管理参数设置，甲方监督*/
    property string instrmentID_user:realtimemonitorPage.instrmentID_user;/*用户管理参数设置，仪器编号*/
    property string technicalDirector_user:realtimemonitorPage.technicalDirector_user;/*用户管理参数设置，技术负责人*/
    property string hydraulicClamp_user:realtimemonitorPage.hydraulicClamp_user;/*用户管理参数设置，液压钳*/

    property string casingName_user:realtimemonitorPage.casingName_user;/*用户套管参数设置，套管名称*/
    property string casingType_user:realtimemonitorPage.casingType_user;/*用户套管参数设置，套管型号*/
    property string casingSize_user:realtimemonitorPage.casingSize_user;/*用户套管参数设置，套管尺寸*/
    property string casingSteelgrade_user:realtimemonitorPage.casingSteelgrade_user;/*用户套管参数设置，套管钢级*/
    property string casingThick_user:realtimemonitorPage.casingThick_user;/*用户套管参数设置，套管重/厚*/
    property int buckleType_user:realtimemonitorPage.buckleType_user;/*用户套管参数设置，套管扣型选择*/
    property int measureChannel_user:realtimemonitorPage.measureChannel_user;/*用户套管参数设置，套管测量通道*/

    property string torqueRange_user:realtimemonitorPage.torqueRange_user;/*用户图形参数设置，扭矩量程*/
    property string maxTorque_user:realtimemonitorPage.maxTorque_user;/*用户图形参数设置，最大扭矩*/
    property string roundRange_user:realtimemonitorPage.roundRange_user;/*用户图形参数设置，圈数量程*/
    property string minTorque_user:realtimemonitorPage.minTorque_user;/*用户图形参数设置，最小扭矩*/
    property string timeRange_user:realtimemonitorPage.timeRange_user;/*用户图形参数设置，时间量程*/
    property string optimalTorque_user:realtimemonitorPage.optimalTorque_user;/*用户图形参数设置，最佳量程*/
    property string rpmRange_user:realtimemonitorPage.rpmRange_user;/*用户图形参数设置，转速量程*/
    property string controlTorque_user:realtimemonitorPage.controlTorque_user;/*用户图形参数设置，控制扭矩*/
    property string rateRange_user:realtimemonitorPage.rateRange_user;/*用户图形参数设置，变化率量程*/
    property string referenceTorque_user:realtimemonitorPage.referenceTorque_user;/*用户图形参数设置，参考扭矩*/

    property string clampArmlength_user:realtimemonitorPage.clampArmlength_user;/*用户技术参数设置，钳臂长*/
    property string reviseCoefficient_user:realtimemonitorPage.reviseCoefficient_user;/*用户技术参数设置，修正系数*/
    property string pulseNumber_user:realtimemonitorPage.pulseNumber_user;/*用户技术参数设置，脉冲数*/
    property string threadLubricantOil_user:realtimemonitorPage.threadLubricantOil_user;/*用户技术参数设置，丝扣油*/
    property string sensorForce_user:realtimemonitorPage.sensorForce_user;/*用户技术参数设置，传感器力*/
    property string delayTime_user:realtimemonitorPage.delayTime_user;/*用户技术参数设置，延迟时间*/
    property string shiftgearTorque_user:realtimemonitorPage.shiftgearTorque_user;/*用户技术参数设置，换挡扭矩*/
    property string dampingCoefficient_user:realtimemonitorPage.dampingCoefficient_user;/*用户技术参数设置，阻尼系数*/
    property string maxStair_user:realtimemonitorPage.maxStair_user;/*用户技术参数设置，最大台阶*/
    property string minStair_user:realtimemonitorPage.minStair_user;/*用户技术参数设置，最小台阶*/

    /************QML内部参数************/
    property int pageNumber:titleButtons.clickedNumber;/*页面显示，默认为0,实时监控的页面1，下载按钮的页面2，数据查看3，校准测试4*/
    property int titleClickNumber:titleButtons.clickedNumber;/*titleButtons哪一个点击，1：实时监控按钮，2：下载文件按钮，3：数据查看，4：校准测试*/
    property bool parameterSubmit:realtimemonitorPage.paraSubmit;/*用于判断用户是否提交了参数设置*/
    property bool manageSubmit:realtimemonitorPage.manageparameterSubmit;/*是否提交管理参数*/
    property bool casingSubmit:realtimemonitorPage.casingparameterSubmit;/*是否提交套管参数*/
    property bool imageSubmit:realtimemonitorPage.imageparameterSubmit;/*是否提交图形参数*/
    property bool techSubmit:realtimemonitorPage.techparameterSubmit;/*是否提交技术参数*/
    property bool parameterReceived:false;/*QML是否收到外部的参数数据*/
    property bool connectionRequest:realtimemonitorPage.wireconnectionRequest;
    //flags: Qt.FramelessWindowHint;
    color:"green";
    onConnectionRequestChanged: {
        if(connectionRequest===true){
            if (realtimemonitorPage.wiremodelRequest === 1){
                UiLayer.setCommType(1)
            }
            else if (realtimemonitorPage.wiremodelRequest === 2){
                UiLayer.setCommType(0)
            }
        }
    }
    onWireStatusChanged: {
        waitReceiveParameter.running = true;
    }
    onManageSubmitChanged: {
        UiLayer.setDeleComp(entrustUnit_user.trim())
        UiLayer.setExeComp(operationUnit_user.trim())
        UiLayer.setCollComp(cooperationUnit_user.trim())
        UiLayer.setMachineNo(instrmentID_user.trim())
        UiLayer.setHydClamp(hydraulicClamp_user.trim())
        UiLayer.setAreaNo(operationArea_user.trim())
        UiLayer.setWellNo(Number(operationWellID_user.trim()))
        UiLayer.setOwnerSuper(partyAsupervisor_user.trim())
        UiLayer.setTechDir(technicalDirector_user.trim());
        UiLayer.setRemark("remarkTxtF.text.trim()");
    }
    onCasingSubmitChanged: {
        if(casingSubmit===true){
            UiLayer.setPipeName(casingName_user.trim())
            UiLayer.setPipeType(casingType_user.trim())
            UiLayer.setPipeDiameter(casingSize_user.trim())
            UiLayer.setPipeClass(casingSteelgrade_user.trim())
            UiLayer.setPipeThinkness(casingThick_user.trim())
        }
    }
    onImageSubmitChanged: {
        if(imageSubmit===true){
            UiLayer.setMaxTor(Number(maxTorque_user.trim()))
            UiLayer.setMinTor(Number(minTorque_user.trim()))
            UiLayer.setBestTor(Number(optimalTorque_user.trim()))
            UiLayer.setCtlTor(Number(controlTorque_user.trim()))
            UiLayer.setDrawTor(Number(referenceTorque_user.trim()))
            UiLayer.setMaxTime(Number(timeRange_user.trim()))
            UiLayer.setMaxCycle(Number(roundRange_user.trim()))
            //UiLayer.setDateTime(Date.fromLocaleString(Qt.locale(), dateTimeTxtF.text.trim(), "yyyy-MM-dd hh:mm:ss"))
            UiLayer.setPipeNo(100);
        }
    }
    onTechSubmitChanged: {
        if(techSubmit===true){
            UiLayer.setTongArmLen(Number(clampArmlength_user.trim()))
            UiLayer.setCorrFactor(Number(reviseCoefficient_user.trim()))
            UiLayer.setDelayTime(Number(delayTime_user.trim()))
            UiLayer.setMinStep(Number(minStair_user.trim()))
            UiLayer.setMaxStep(Number(maxStair_user.trim()))
            UiLayer.updateTorSysArg();
        }
    }

    TitleButtons{
        id:titleButtons;
        titleButtons_netStatus: netStatus;
        windowWidth: parent.width;
        windowHeight: parent.height*0.16;
    }

    /*InitialPage{
        visible:pageNumber===0?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    Justify_Test{
        id:justifytestPage;
        visible:pageNumber===40?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    Historydata_Display{
        id:historydatadisplayPage;
        visible:pageNumber===31?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    Modifydata_Display{
        id:modifydatadisplayPage;
        visible:pageNumber===32?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    ParameterPreview{
        id:parameterpreviewPage;
        visible:pageNumber
    }

    Printdata_Display{
        id:printdataPage;
        visible:pageNumber===33?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    Historydata_Choose{
        id:historydatachoosePage;
        visible:pageNumber===30?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }
    ParametersSet{
        id:parametersetPage;
        visible:pageNumber===10?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }*/
    RealtimeMonitor{
        id:realtimemonitorPage;
        visible:pageNumber===1?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
        wireConnected:wireStatus;
    }
    /*WireChoose{
        id:wirechoosePage;
        visible:pageNumber===1?true:false;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
    }*/
    /*File_Download{
        visible:pageNumber===20?true:false;
        id:filedownloadPage;
        windowWidth: parent.width;
        windowHeight: parent.height*0.84;
        y:parent.height*0.16;
        filedownPortation: filedownloadProportion;
        fileprocessPortation: fileprocessProportion;
    }*/
    /*Text{
        font.pointSize: 50;
        text:entrustUnit;
    }

    Text{
        font.pointSize: 50;
        y:100;
        color:"red";
        text:entrustUnit_user;
    }*/

    Timer{
        id:waitReceiveParameter;
        interval:2000;
        running:false;
        repeat: false;
        onTriggered: {
            //需要张凯填写
            entrustUnit = UiLayer.getDeleComp();
            operationArea = UiLayer.getAreaNo();
            operationUnit = UiLayer.getExeComp();
            operationWellID = UiLayer.getWellNo();
            cooperationUnit = UiLayer.getCollComp();
            partyAsupervisor = UiLayer.getOwnerSuper();
            instrmentID = UiLayer.getMachineNo();
            technicalDirector = UiLayer.getTechDir();
            hydraulicClamp = UiLayer.getHydClamp();

            casingName = UiLayer.getPipeName();
            casingType = UiLayer.getPipType();
            casingSize = UiLayer.getPipeDiameter();
            casingSteelgrade = UiLayer.getPipeClass();
            casingThick = UiLayer.getPipeThinkness()
            buckleType = 2;
            measureChannel = 1;

            torqueRange = (UiLayer.getMaxTor()+1000).toString();
            maxTorque = UiLayer.getMaxTor().toString();
            roundRange = UiLayer.getMaxCycle().toString();
            minTorque = UiLayer.getMinTor().toString();
            timeRange = UiLayer.getMaxTime().toString();
            optimalTorque = UiLayer.getBestTor().toString();
            rpmRange = "30";
            controlTorque = UiLayer.getCtlTor().toString();
            rateRange = "1200";
            referenceTorque = UiLayer.getMinTor().toString();

            clampArmlength = UiLayer.getTongArmLen().toString();
            reviseCoefficient = UiLayer.getCorrFactor().toString();
            pulseNumber = "600";
            threadLubricantOil = "APIMOD";
            sensorForce = "40.0";
            delayTime = UiLayer.getDelayTime().toString();
            shiftgearTorque = "0";
            dampingCoefficient = "1";
            maxStair = UiLayer.getMaxStep().toString();
            minStair = UiLayer.getMinStep().toString();

            realtimemonitorPage.entrustUnit_user = entrustUnit;
            realtimemonitorPage.operationArea_user = operationArea;
            realtimemonitorPage.operationUnit_user = operationUnit;
            realtimemonitorPage.operationWellID_user = operationWellID;
            realtimemonitorPage.cooperationUnit_user = cooperationUnit;
            realtimemonitorPage.partyAsupervisor_user = partyAsupervisor;
            realtimemonitorPage.instrmentID_user = instrmentID;
            realtimemonitorPage.technicalDirector_user = technicalDirector;
            realtimemonitorPage.hydraulicClamp_user = hydraulicClamp;

            realtimemonitorPage.casingName_user = casingName;
            realtimemonitorPage.casingType_user = casingType;
            realtimemonitorPage.casingSize_user = casingSize;
            realtimemonitorPage.casingSteelgrade_user = casingSteelgrade;
            realtimemonitorPage.casingThick_user = casingThick;
            realtimemonitorPage.buckleType_user = buckleType;
            realtimemonitorPage.measureChannel_user = measureChannel;

            realtimemonitorPage.torqueRange_user = torqueRange;
            realtimemonitorPage.maxTorque_user = maxTorque;
            realtimemonitorPage.roundRange_user = roundRange;
            realtimemonitorPage.minTorque_user = minTorque;
            realtimemonitorPage.timeRange_user = timeRange;
            realtimemonitorPage.optimalTorque_user = optimalTorque;
            realtimemonitorPage.rpmRange_user = rpmRange;
            realtimemonitorPage.controlTorque_user = controlTorque;
            realtimemonitorPage.rateRange_user = rateRange;
            realtimemonitorPage.referenceTorque_user = referenceTorque;

            realtimemonitorPage.clampArmlength_user = clampArmlength;
            realtimemonitorPage.reviseCoefficient_user = reviseCoefficient;
            realtimemonitorPage.pulseNumber_user = pulseNumber;
            realtimemonitorPage.threadLubricantOil_user = threadLubricantOil;
            realtimemonitorPage.sensorForce_user = sensorForce;
            realtimemonitorPage.delayTime_user = delayTime;
            realtimemonitorPage.shiftgearTorque_user = shiftgearTorque;
            realtimemonitorPage.dampingCoefficient_user = dampingCoefficient;
            realtimemonitorPage.maxStair_user = maxStair;
            realtimemonitorPage.minStair_user = minStair;

            receiveParameter.running = true;
        }
    }
    Timer {
        id:receiveParameter;
        interval:50; running:false; repeat:true;
        onTriggered:{
            //需要张凯填写
            entrustUnit = UiLayer.getDeleComp();
            operationArea = UiLayer.getAreaNo();
            operationUnit = UiLayer.getExeComp();
            operationWellID = UiLayer.getWellNo();
            cooperationUnit = UiLayer.getCollComp();
            partyAsupervisor = UiLayer.getOwnerSuper();
            instrmentID = UiLayer.getMachineNo();
            technicalDirector = UiLayer.getTechDir();
            hydraulicClamp = UiLayer.getHydClamp();

            casingName = UiLayer.getPipeName();
            casingType = UiLayer.getPipType();
            casingSize = UiLayer.getPipeDiameter();
            casingSteelgrade = UiLayer.getPipeClass();
            casingThick = UiLayer.getPipeThinkness()
            buckleType = 2;
            measureChannel = 1;

            torqueRange = (UiLayer.getMaxTor()+1000).toString();
            maxTorque = UiLayer.getMaxTor().toString();
            console.log(maxTorque)
            roundRange = UiLayer.getMaxCycle().toString();
            minTorque = UiLayer.getMinTor().toString();
            timeRange = UiLayer.getMaxTime().toString();
            optimalTorque = UiLayer.getBestTor().toString();
            rpmRange = "30";
            controlTorque = UiLayer.getCtlTor().toString();
            rateRange = "1200";
            referenceTorque = UiLayer.getMinTor().toString();

            clampArmlength = UiLayer.getTongArmLen().toString();
            reviseCoefficient = UiLayer.getCorrFactor().toString();
            pulseNumber = "600";
            threadLubricantOil = "APIMOD";
            sensorForce = "40.0";
            delayTime = UiLayer.getDelayTime().toString();
            shiftgearTorque = "0";
            dampingCoefficient = "1";
            maxStair = UiLayer.getMaxStep().toString();
            minStair = UiLayer.getMinStep().toString();
            //将每隔50ms的值赋给RealtimeMonitor的input数据进行比较
            realtimemonitorPage.entrustUnit_input = entrustUnit;
            realtimemonitorPage.operationArea_input = operationArea;
            realtimemonitorPage.operationUnit_input = operationUnit;
            realtimemonitorPage.operationWellID_input = operationWellID;
            realtimemonitorPage.cooperationUnit_input = cooperationUnit;
            realtimemonitorPage.partyAsupervisor_input = partyAsupervisor;
            realtimemonitorPage.instrmentID_input = instrmentID;
            realtimemonitorPage.technicalDirector_input = technicalDirector;
            realtimemonitorPage.hydraulicClamp_input = hydraulicClamp;

            realtimemonitorPage.casingName_input = casingName;
            realtimemonitorPage.casingType_input = casingType;
            realtimemonitorPage.casingSize_input = casingSize;
            realtimemonitorPage.casingSteelgrade_input = casingSteelgrade;
            realtimemonitorPage.casingThick_input = casingThick;
            realtimemonitorPage.buckleType_input = buckleType;
            realtimemonitorPage.measureChannel_input = measureChannel;

            realtimemonitorPage.torqueRange_input = torqueRange;
            realtimemonitorPage.maxTorque_input = maxTorque;
            realtimemonitorPage.roundRange_input = roundRange;
            realtimemonitorPage.minTorque_input = minTorque;
            realtimemonitorPage.timeRange_input = timeRange;
            realtimemonitorPage.optimalTorque_input = optimalTorque;
            realtimemonitorPage.rpmRange_input = rpmRange;
            realtimemonitorPage.controlTorque_input = controlTorque;
            realtimemonitorPage.rateRange_input = rateRange;
            realtimemonitorPage.referenceTorque_input = referenceTorque;

            realtimemonitorPage.clampArmlength_input = clampArmlength;
            realtimemonitorPage.reviseCoefficient_input = reviseCoefficient;
            realtimemonitorPage.pulseNumber_input = pulseNumber;
            realtimemonitorPage.threadLubricantOil_input = threadLubricantOil;
            realtimemonitorPage.sensorForce_input = sensorForce;
            realtimemonitorPage.delayTime_input = delayTime;
            realtimemonitorPage.shiftgearTorque_input = shiftgearTorque;
            realtimemonitorPage.dampingCoefficient_input = dampingCoefficient;
            realtimemonitorPage.maxStair_input = maxStair;
            realtimemonitorPage.minStair_input = minStair;
        }
    }
    Timer{
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            if (UiLayer.getUpConnStatus())
            {
                netStatus = true;
                if (UiLayer.getCommType() === 0){
                    wireStatus = 2
                    UiLayer.reqUperDefaultArgs()
                }
                else if (UiLayer.getCommType() === 1){
                    wireStatus = 1;
                    UiLayer.reqUperDefaultArgs()
                }

            }
        }
    }

//    Timer {
//        id:netStatusTimer;
//        interval:3000; running:true; repeat:false;
//        onTriggered:{
//            netStatus = true;
//        }
//    }
//    Timer {
//        id:wireStatusTimer;
//        interval:5000; running:false; repeat:false;
//        onTriggered:{
//            wireStatus = 2;
//        }
//   }
}
