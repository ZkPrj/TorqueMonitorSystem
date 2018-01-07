import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item {
    property int windowWidth:800;
    property int windowHeight:504;
    width:windowWidth;
    height:windowHeight;
    property int realtimeProcess:1;/*实时监控页面，1.网络设置页面，2：参数设置页面，3:参数预览页面，4：实时显示页面*/
    property int paraNumber:1;/*显示哪个页面，1.表示管理参数，2表示套管参数，3表示图形参数，4表示技术参数*/
    property int wireConnected:0;/*有线或无线网络是否已经连接上*/
    property bool wireconnectionRequest:false;/*是否提交网络连接请求*/
    property int wiremodelRequest:1;/*提交的有线无线模式，1为有线，2为无线*/
    property bool paramtersetStatus:true;/*设置的参数是否合理*/
    property bool managesetStatus:true;/*管理参数设置是否合理*/
    property bool casingsetStatus:true;/*套管参数设置是否合理*/
    property bool imagesetStatus:true;/*图形参数设置是否合理*/
    property bool techsetStatus:true;/*技术参数设置是否合理*/
    property bool paraSubmit:false;/*用户是否提交参数设置，true为提交，false为不提交*/
    property bool manageparameterSubmit:false;/*是否提交管理参数*/
    property bool casingparameterSubmit:false;/*是否提交套管参数*/
    property bool imageparameterSubmit:false;/*是否提交图形参数*/
    property bool techparameterSubmit:false;/*是否提交技术参数*/

    property string entrustUnit_input;/*管理参数外部输入，委托单位*/
    property string operationArea_input;/*管理参数外部输入，作业区域*/
    property string operationUnit_input;/*管理参数外部输入，作业单位*/
    property string operationWellID_input;/*管理参数外部输入，作业井号*/
    property string cooperationUnit_input;/*管理参数外部输入，协作单位*/
    property string partyAsupervisor_input;/*管理参数外部输入，甲方监督*/
    property string instrmentID_input;/*管理参数外部输入，仪器编号*/
    property string technicalDirector_input;/*管理参数外部输入，技术负责人*/
    property string hydraulicClamp_input;/*管理参数外部输入，液压钳*/

    property string casingName_input;/*套管参数外部输入，套管名称*/
    property string casingType_input;/*套管参数外部输入，套管型号*/
    property string casingSize_input;/*套管参数外部输入，套管尺寸*/
    property string casingSteelgrade_input;/*套管参数外部输入，套管钢级*/
    property string casingThick_input;/*套管参数外部输入，套管重/厚*/
    property int buckleType_input;/*套管参数外部输入，套管扣型选择*/
    property int measureChannel_input;/*套管参数外部输入，套管测量通道*/

    property string torqueRange_input;/*图形参数外部输入，扭矩量程*/
    property string maxTorque_input;/*图形参数外部输入，最大扭矩*/
    property string roundRange_input;/*图形参数外部输入，圈数量程*/
    property string minTorque_input;/*图形参数外部输入，最小扭矩*/
    property string timeRange_input;/*图形参数外部输入，时间量程*/
    property string optimalTorque_input;/*图形参数外部输入，最佳量程*/
    property string rpmRange_input;/*图形参数外部输入，转速量程*/
    property string controlTorque_input;/*图形参数外部输入，控制扭矩*/
    property string rateRange_input;/*图形参数外部输入，变化率量程*/
    property string referenceTorque_input;/*图形参数外部输入，参考扭矩*/

    property string clampArmlength_input;/*技术参数外部输入，钳臂长*/
    property string reviseCoefficient_input;/*技术参数外部输入，修正系数*/
    property string pulseNumber_input;/*技术参数外部输入，脉冲数*/
    property string threadLubricantOil_input;/*技术参数外部输入，丝扣油*/
    property string sensorForce_input;/*技术参数外部输入，传感器力*/
    property string delayTime_input;/*技术参数外部输入，延迟时间*/
    property string shiftgearTorque_input;/*技术参数外部输入，换挡扭矩*/
    property string dampingCoefficient_input;/*技术参数外部输入，阻尼系数*/
    property string maxStair_input;/*技术参数外部输入，最大台阶*/
    property string minStair_input;/*技术参数外部输入，最小台阶*/

    property string entrustUnit_user;/*管理参数设置，委托单位*/
    property string operationArea_user;/*管理参数设置，作业区域*/
    property string operationUnit_user;/*管理参数设置，作业单位*/
    property string operationWellID_user;/*管理参数设置，作业井号*/
    property string cooperationUnit_user;/*管理参数设置，协作单位*/
    property string partyAsupervisor_user;/*管理参数设置，甲方监督*/
    property string instrmentID_user;/*管理参数设置，仪器编号*/
    property string technicalDirector_user;/*管理参数设置，技术负责人*/
    property string hydraulicClamp_user;/*管理参数设置，液压钳*/

    property string casingName_user;/*套管参数设置，套管名称*/
    property string casingType_user;/*套管参数设置，套管型号*/
    property string casingSize_user;/*套管参数设置，套管尺寸*/
    property string casingSteelgrade_user;/*套管参数设置，套管钢级*/
    property string casingThick_user;/*套管参数设置，套管重/厚*/
    property int buckleType_user;/*套管参数设置，套管扣型选择*/
    property int measureChannel_user;/*套管参数设置，套管测量通道*/

    property string torqueRange_user;/*图形参数设置，扭矩量程*/
    property string maxTorque_user;/*图形参数设置，最大扭矩*/
    property string roundRange_user;/*图形参数设置，圈数量程*/
    property string minTorque_user;/*图形参数设置，最小扭矩*/
    property string timeRange_user;/*图形参数设置，时间量程*/
    property string optimalTorque_user;/*图形参数设置，最佳量程*/
    property string rpmRange_user;/*图形参数设置，转速量程*/
    property string controlTorque_user;/*图形参数设置，控制扭矩*/
    property string rateRange_user;/*图形参数设置，变化率量程*/
    property string referenceTorque_user;/*图形参数设置，参考扭矩*/

    property string clampArmlength_user;/*技术参数设置，钳臂长*/
    property string reviseCoefficient_user;/*技术参数设置，修正系数*/
    property string pulseNumber_user;/*技术参数设置，脉冲数*/
    property string threadLubricantOil_user;/*技术参数设置，丝扣油*/
    property string sensorForce_user;/*技术参数设置，传感器力*/
    property string delayTime_user;/*技术参数设置，延迟时间*/
    property string shiftgearTorque_user;/*技术参数设置，换挡扭矩*/
    property string dampingCoefficient_user;/*技术参数设置，阻尼系数*/
    property string maxStair_user;/*技术参数设置，最大台阶*/
    property string minStair_user;/*技术参数设置，最小台阶*/
    //用于检查参数设置是否正确
    onWireConnectedChanged: {
        if(wireConnected!=0){
            realtimeProcess = 2;
        }
    }

    onParaNumberChanged: {
        if(paraNumber===2){
            manageparameterSubmit = true;
            entrustUnit_user = entrustunitInput.inputContent;
            operationArea_user = operationareaInput.inputContent;
            operationUnit_user = operationunitInput.inputContent;
            operationWellID_user = operationwellIDInput.inputContent;
            cooperationUnit_user = cooperationunitInput.inputContent;
            partyAsupervisor_user = partyAsupervisorInput.inputContent;
            instrmentID_user = instrmentIDInput.inputContent;
            technicalDirector_user = technicaldirectorInput.inputContent;
            hydraulicClamp_user = hydraulicclampInput.inputContent;
            manageparameterSubmit = false;
            /*if(entrustUnit_user===entrustUnit_input&&operationArea_user===operationArea_input&&operationUnit_user==operationUnit_input&&
                    operationWellID_user===operationWellID_input&&cooperationUnit_user===cooperationUnit_input&&cooperationUnit_user===cooperationUnit_input&&
                    partyAsupervisor_user===partyAsupervisor_input&&instrmentID_user===instrmentID_input&&instrmentID_user===instrmentID_input&&
                    hydraulicClamp_user===hydraulicClamp_input){
                managesetStatus = true;
            }else{
                 managesetStatus = false;
            }*/
            //manageparameterCheck();
        }
        if(paraNumber===3){
            casingparameterSubmit = true;
            casingName_user = casingNameInput.inputContent;
            casingType_user = casingTypeInput.inputContent;
            casingSize_user = casingSizeInput.inputContent;
            casingSteelgrade_user = casingSteelgradeInput.inputContent;
            casingThick_user = casingThickInput.inputContent;
            buckleType_user = buckleTypeChoose.chooseStatus_input;
            measureChannel_user = measureChannelChoose.chooseStatus_input;
            casingparameterSubmit = false;
            /*if(casingName_user===casingName_input&&casingType_user===casingType_input&&casingSize_user===casingSize_input&&casingSteelgrade_user===casingSteelgrade_input&&
                    casingThick_user===casingThick_input&&buckleType_user===buckleType_input&&measureChannel_user===measureChannel_input){
                casingsetStatus = true;
            }else{
                casingsetStatus = false;
            }*/
            //casingparameterCheck();
        }
        if(paraNumber===4){
            imageparameterSubmit = true;
            torqueRange_user = torquerangeInput.inputContent;
            maxTorque_user = maxtorqueInput.inputContent;
            roundRange_user = roundrangeInput.inputContent;
            minTorque_user = mintorqueInput.inputContent;
            timeRange_user = timerangeInput.inputContent;
            optimalTorque_user = optimaltorqueInput.inputContent;
            rpmRange_user = rpmrangeInput.inputContent;
            controlTorque_user = controltorqueInput.inputContent;
            rateRange_user = raterangeInput.inputContent;
            referenceTorque_user = referencetorqueInput.inputContent;
            imageparameterSubmit = false;
            /*if(torqueRange_user===torqueRange_input&&maxTorque_user===maxTorque_input&&roundRange_user===roundRange_input&&minTorque_user===minTorque_input&&
                    timeRange_user===timeRange_input&&optimalTorque_user===optimalTorque_input&&rpmRange_user===rpmRange_input&&
                    controlTorque_user===controlTorque_input&&rateRange_user===rateRange_input&&referenceTorque_user===referenceTorque_input){
                imagesetStatus = true;
            }else{
                imagesetStatus = false;
            }*/
            //imageparameterCheck();
        }
        if(realtimeProcess===3){
            techparameterSubmit = true;
            clampArmlength_user = clampArmlengthInput.inputContent;
            reviseCoefficient_user = reviseCoefficientInput.inputContent;
            pulseNumber_user = pulseNumberInput.inputContent;
            threadLubricantOil_user = threadLubricantOilInput.inputContent;
            sensorForce_user = sensorForceInput.inputContent;
            delayTime_user = delayTimeInput.inputContent;
            shiftgearTorque_user = shiftgearTorqueInput.inputContent;
            dampingCoefficient_user = dampingCoefficientInput.inputContent;
            maxStair_user = maxStairInput.inputContent;
            minStair_user = minStairInput.inputContent;
            techparameterSubmit = false;
            /*if(clampArmlength_user===clampArmlength_input&&reviseCoefficient_user===reviseCoefficient_input&&pulseNumber_user===pulseNumber_input&&
                    threadLubricantOil_user===threadLubricantOil_input&&sensorForce_user===sensorForce_input&&delayTime_user===delayTime_input&&
                    shiftgearTorque_user===shiftgearTorque_input&&dampingCoefficient_user===dampingCoefficient_input&&maxStair_user===maxStair_input&&
                    minStair_user===minStair_input){
                techsetStatus = true;
            }else{
                techsetStatus = false;
            }*/
            //techparameterCheck();
        }
    }
    function check(){
        if(entrustUnit_user===entrustUnit_input&&operationArea_user===operationArea_input&&operationUnit_user==operationUnit_input&&
                operationWellID_user===operationWellID_input&&cooperationUnit_user===cooperationUnit_input&&cooperationUnit_user===cooperationUnit_input&&
                partyAsupervisor_user===partyAsupervisor_input&&instrmentID_user===instrmentID_input&&instrmentID_user===instrmentID_input&&
                hydraulicClamp_user===hydraulicClamp_input){
            managesetStatus = true;
        }else{
             managesetStatus = false;
        }
        if(casingName_user===casingName_input&&casingType_user===casingType_input&&casingSize_user===casingSize_input&&casingSteelgrade_user===casingSteelgrade_input&&
                casingThick_user===casingThick_input&&buckleType_user===buckleType_input&&measureChannel_user===measureChannel_input){
            casingsetStatus = true;
        }else{
            casingsetStatus = false;
        }
        if(torqueRange_user===torqueRange_input&&maxTorque_user===maxTorque_input&&roundRange_user===roundRange_input&&minTorque_user===minTorque_input&&
                timeRange_user===timeRange_input&&optimalTorque_user===optimalTorque_input&&rpmRange_user===rpmRange_input&&
                controlTorque_user===controlTorque_input&&rateRange_user===rateRange_input&&referenceTorque_user===referenceTorque_input){
            imagesetStatus = true;
        }else{
            imagesetStatus = false;
        }
        if(clampArmlength_user===clampArmlength_input&&reviseCoefficient_user===reviseCoefficient_input&&pulseNumber_user===pulseNumber_input&&
                threadLubricantOil_user===threadLubricantOil_input&&sensorForce_user===sensorForce_input&&delayTime_user===delayTime_input&&
                shiftgearTorque_user===shiftgearTorque_input&&dampingCoefficient_user===dampingCoefficient_input&&maxStair_user===maxStair_input&&
                minStair_user===minStair_input){
            techsetStatus = true;
        }else{
            techsetStatus = false;
        }
        if(entrustUnit_user===entrustUnit_input){
            entrustunitInput_preview.contentConsistent = true;
        }else if(entrustUnit_user!=entrustUnit_input){
            entrustunitInput_preview.contentConsistent = false;
        }

        if(operationArea_user===operationArea_input){
            operationareaInput_preview.contentConsistent = true;
        }else if(operationArea_user!=operationArea_input){
            operationareaInput_preview.contentConsistent = false;
        }

        if(operationUnit_user===operationUnit_input){
            operationunitInput_preview.contentConsistent = true;
        }else if(operationUnit_user!=operationUnit_input){
            operationunitInput_preview.contentConsistent = false;
        }

        if(operationWellID_user===operationWellID_input){
            operationwellIDInput_preview.contentConsistent = true;
        }else if(operationWellID_user!=operationWellID_input){
            operationwellIDInput_preview.contentConsistent = false;
        }

        if(cooperationUnit_user===cooperationUnit_input){
            cooperationunitInput_preview.contentConsistent = true;
        }else if(cooperationUnit_user!=cooperationUnit_input){
            cooperationunitInput_preview.contentConsistent = false;
        }

        if(partyAsupervisor_user===partyAsupervisor_input){
            partyAsupervisorInput_preview.contentConsistent = true;
        }else if(partyAsupervisor_user!=partyAsupervisor_input){
            partyAsupervisorInput_preview.contentConsistent = false;
        }

        if(instrmentID_user===instrmentID_input){
            instrmentIDInput_preview.contentConsistent = true;
        }else if(instrmentID_user!=instrmentID_input){
            instrmentIDInput_preview.contentConsistent = false;
        }

        if(technicalDirector_user===technicalDirector_input){
            technicaldirectorInput_preview.contentConsistent = true;
        }else if(technicalDirector_user!=technicalDirector_input){
            technicaldirectorInput_preview.contentConsistent = false;
        }

        if(hydraulicClamp_user===hydraulicClamp_input){
            hydraulicclampInput_preview.contentConsistent = true;
        }else if(hydraulicClamp_user!=hydraulicClamp_input){
            hydraulicclampInput_preview.contentConsistent = false;
        }
        if(casingName_user===casingName_input){
            casingNameInput_preview.contentConsistent = true;
        }else if(casingName_user!=casingName_input){
            casingNameInput_preview.contentConsistent = false;
        }

        if(casingType_user===casingType_input){
            casingTypeInput_preview.contentConsistent = true;
        }else if(casingType_user!=casingType_input){
            casingTypeInput_preview.contentConsistent = false;
        }

        if(casingSize_user===casingSize_input){
            casingSizeInput_preview.contentConsistent = true;
        }else if(casingSize_user!=casingSize_input){
            casingSizeInput_preview.contentConsistent = false;
        }

        if(casingSteelgrade_user===casingSteelgrade_input){
            casingSteelgradeInput_preview.contentConsistent = true;
        }else if(casingSteelgrade_user!=casingSteelgrade_input){
            casingSteelgradeInput_preview.contentConsistent = false;
        }

        if(casingThick_user===casingThick_input){
            casingThickInput_preview.contentConsistent = true;
        }else if(casingThick_user!=casingThick_input){
            casingThickInput_preview.contentConsistent = false;
        }

        if(buckleType_user===buckleType_input){
            buckleTypeChoose_preview.contentConsistent = true;
        }else if(buckleType_user!=buckleType_input){
            buckleTypeChoose_preview.contentConsistent = false;
        }

        if(measureChannel_user===measureChannel_input){
            measureChannelChoose_preview.contentConsistent = true;
        }else if(measureChannel_user!=measureChannel_input){
            measureChannelChoose_preview.contentConsistent = false;
        }
        if(torqueRange_user===torqueRange_input){
            torquerangeInput_preview.contentConsist = true;
        }else if(torqueRange_user!=torqueRange_input){
            torquerangeInput_preview.contentConsist = false;
        }

        if(maxTorque_user===maxTorque_input){
            maxtorqueInput_preview.contentConsist = true;
        }else if(maxTorque_user!=maxTorque_input){
            maxtorqueInput_preview.contentConsist = false;
        }

        if(roundRange_user===roundRange_input){
            roundrangeInput_preview.contentConsist = true;
        }else if(roundRange_user!=roundRange_input){
            roundrangeInput_preview.contentConsist = false;
        }

        if(minTorque_user===minTorque_input){
            mintorqueInput_preview.contentConsist = true;
        }else if(minTorque_user!=minTorque_input){
            mintorqueInput_preview.contentConsist = false;
        }

        if(timeRange_user===timeRange_input){
            timerangeInput_preview.contentConsist = true;
        }else if(timeRange_user!=timeRange_input){
            timerangeInput_preview.contentConsist = false;
        }

        if(optimalTorque_user===optimalTorque_input){
            optimaltorqueInput_preview.contentConsist = true;
        }else if(optimalTorque_user!=optimalTorque_input){
            optimaltorqueInput_preview.contentConsist = false;
        }

        if(rpmRange_user===rpmRange_input){
            rpmrangeInput_preview.contentConsist = true;
        }else if(rpmRange_user!=rpmRange_input){
            rpmrangeInput_preview.contentConsist = false;
        }

        if(controlTorque_user===controlTorque_input){
            controltorqueInput_preview.contentConsist = true;
        }else if(controlTorque_user!=controlTorque_input){
            controltorqueInput_preview.contentConsist = false;
        }

        if(rateRange_user===rateRange_input){
            raterangeInput_preview.contentConsist = true;
        }else if(rateRange_user!=rateRange_input){
            raterangeInput_preview.contentConsist = false;
        }

        if(referenceTorque_user===referenceTorque_input){
            referencetorqueInput_preview.contentConsist = true;
        }else if(referenceTorque_user!=referenceTorque_input){
            referencetorqueInput_preview.contentConsist = false;
        }
        if(clampArmlength_user===clampArmlength_input){
            clampArmlengthInput_preview.contentConsist = true;
        }else if(clampArmlength_user!=clampArmlength_input){
            clampArmlengthInput_preview.contentConsist = false;
        }

        if(reviseCoefficient_user===reviseCoefficient_input){
            reviseCoefficientInput_preview.contentConsist = true;
        }else if(reviseCoefficient_user!=clampArmlength_input){
            reviseCoefficientInput_preview.contentConsist = false;
        }

        if(pulseNumber_user===pulseNumber_input){
            pulseNumberInput_preview.contentConsist = true;
        }else if(pulseNumber_user!=pulseNumber_input){
            pulseNumberInput_preview.contentConsist = false;
        }

        if(threadLubricantOil_user===threadLubricantOil_input){
            threadLubricantOilInput_preview.contentConsist = true;
        }else if(threadLubricantOil_user!=threadLubricantOil_input){
            threadLubricantOilInput_preview.contentConsist = false;
        }

        if(sensorForce_user===sensorForce_input){
            sensorForceInput_preview.contentConsist = true;
        }else if(sensorForce_user!=sensorForce_input){
            sensorForceInput_preview.contentConsist = false;
        }

        if(delayTime_user===delayTime_input){
            delayTimeInput_preview.contentConsist = true;
        }else if(delayTime_user!=delayTime_input){
            delayTimeInput_preview.contentConsist = false;
        }

        if(shiftgearTorque_user===shiftgearTorque_input){
            shiftgearTorqueInput_preview.contentConsist = true;
        }else if(shiftgearTorque_user!=shiftgearTorque_input){
            shiftgearTorqueInput_preview.contentConsist = false;
        }

        if(dampingCoefficient_user===dampingCoefficient_input){
            dampingCoefficientInput_preview.contentConsist = true;
        }else if(dampingCoefficient_user!=dampingCoefficient_input){
            dampingCoefficientInput_preview.contentConsist = false;
        }

        if(maxStair_user===maxStair_input){
            maxStairInput_preview.contentConsist = true;
        }else if(maxStair_user!=maxStair_input){
            maxStairInput_preview.contentConsist = false;
        }

        if(minStair_user===minStair_input){
            minStairInput_preview.contentConsist = true;
        }else if(minStair_user!=minStair_input){
            minStairInput_preview.contentConsist = false;
        }
        if(managesetStatus===true&&casingsetStatus===true&&imagesetStatus===true&&techsetStatus===true){
            paramtersetStatus=true;
        }else paramtersetStatus = false;
    }

    function manageparameterCheck(){
        if(entrustUnit_user===entrustUnit_input){
            entrustunitInput_preview.contentConsistent = true;
        }else if(entrustUnit_user!=entrustUnit_input){
            entrustunitInput_preview.contentConsistent = false;
        }

        if(operationArea_user===operationArea_input){
            operationareaInput_preview.contentConsistent = true;
        }else if(operationArea_user!=operationArea_input){
            operationareaInput_preview.contentConsistent = false;
        }

        if(operationUnit_user===operationUnit_input){
            operationunitInput_preview.contentConsistent = true;
        }else if(operationUnit_user!=operationUnit_input){
            operationunitInput_preview.contentConsistent = false;
        }

        if(operationWellID_user===operationWellID_input){
            operationwellIDInput_preview.contentConsistent = true;
        }else if(operationWellID_user!=operationWellID_input){
            operationwellIDInput_preview.contentConsistent = false;
        }

        if(cooperationUnit_user===cooperationUnit_input){
            cooperationunitInput_preview.contentConsistent = true;
        }else if(cooperationUnit_user!=cooperationUnit_input){
            cooperationunitInput_preview.contentConsistent = false;
        }

        if(partyAsupervisor_user===partyAsupervisor_input){
            partyAsupervisorInput_preview.contentConsistent = true;
        }else if(partyAsupervisor_user!=partyAsupervisor_input){
            partyAsupervisorInput_preview.contentConsistent = false;
        }

        if(instrmentID_user===instrmentID_input){
            instrmentIDInput_preview.contentConsistent = true;
        }else if(instrmentID_user!=instrmentID_input){
            instrmentIDInput_preview.contentConsistent = false;
        }

        if(technicalDirector_user===technicalDirector_input){
            technicaldirectorInput_preview.contentConsistent = true;
        }else if(technicalDirector_user!=technicalDirector_input){
            technicaldirectorInput_preview.contentConsistent = false;
        }

        if(hydraulicClamp_user===hydraulicClamp_input){
            hydraulicclampInput_preview.contentConsistent = true;
        }else if(hydraulicClamp_user!=hydraulicClamp_input){
            hydraulicclampInput_preview.contentConsistent = false;
        }
    }
    function casingparameterCheck(){
        if(casingName_user===casingName_input){
            casingNameInput_preview.contentConsistent = true;
        }else if(casingName_user!=casingName_input){
            casingNameInput_preview.contentConsistent = false;
        }

        if(casingType_user===casingType_input){
            casingTypeInput_preview.contentConsistent = true;
        }else if(casingType_user!=casingType_input){
            casingTypeInput_preview.contentConsistent = false;
        }

        if(casingSize_user===casingSize_input){
            casingSizeInput_preview.contentConsistent = true;
        }else if(casingSize_user!=casingSize_input){
            casingSizeInput_preview.contentConsistent = false;
        }

        if(casingSteelgrade_user===casingSteelgrade_input){
            casingSteelgradeInput_preview.contentConsistent = true;
        }else if(casingSteelgrade_user!=casingSteelgrade_input){
            casingSteelgradeInput_preview.contentConsistent = false;
        }

        if(casingThick_user===casingThick_input){
            casingThickInput_preview.contentConsistent = true;
        }else if(casingThick_user!=casingThick_input){
            casingThickInput_preview.contentConsistent = false;
        }

        if(buckleType_user===buckleType_input){
            buckleTypeChoose_preview.contentConsistent = true;
        }else if(buckleType_user!=buckleType_input){
            buckleTypeChoose_preview.contentConsistent = false;
        }

        if(measureChannel_user===measureChannel_input){
            measureChannelChoose_preview.contentConsistent = true;
        }else if(measureChannel_user!=measureChannel_input){
            measureChannelChoose_preview.contentConsistent = false;
        }
    }
    function imageparameterCheck(){
        if(torqueRange_user===torqueRange_input){
            torquerangeInput_preview.contentConsist = true;
        }else if(torqueRange_user!=torqueRange_input){
            torquerangeInput_preview.contentConsist = false;
        }

        if(maxTorque_user===maxTorque_input){
            maxtorqueInput_preview.contentConsist = true;
        }else if(maxTorque_user!=maxTorque_input){
            maxtorqueInput_preview.contentConsist = false;
        }

        if(roundRange_user===roundRange_input){
            roundrangeInput_preview.contentConsist = true;
        }else if(roundRange_user!=roundRange_input){
            roundrangeInput_preview.contentConsist = false;
        }

        if(minTorque_user===minTorque_input){
            mintorqueInput_preview.contentConsist = true;
        }else if(minTorque_user!=minTorque_input){
            mintorqueInput_preview.contentConsist = false;
        }

        if(timeRange_user===timeRange_input){
            timerangeInput_preview.contentConsist = true;
        }else if(timeRange_user!=timeRange_input){
            timerangeInput_preview.contentConsist = false;
        }

        if(optimalTorque_user===optimalTorque_input){
            optimaltorqueInput_preview.contentConsist = true;
        }else if(optimalTorque_user!=optimalTorque_input){
            optimaltorqueInput_preview.contentConsist = false;
        }

        if(rpmRange_user===rpmRange_input){
            rpmrangeInput_preview.contentConsist = true;
        }else if(rpmRange_user!=rpmRange_input){
            rpmrangeInput_preview.contentConsist = false;
        }

        if(controlTorque_user===controlTorque_input){
            controltorqueInput_preview.contentConsist = true;
        }else if(controlTorque_user!=controlTorque_input){
            controltorqueInput_preview.contentConsist = false;
        }

        if(rateRange_user===rateRange_input){
            raterangeInput_preview.contentConsist = true;
        }else if(rateRange_user!=rateRange_input){
            raterangeInput_preview.contentConsist = false;
        }

        if(referenceTorque_user===referenceTorque_input){
            referencetorqueInput_preview.contentConsist = true;
        }else if(referenceTorque_user!=referenceTorque_input){
            referencetorqueInput_preview.contentConsist = false;
        }

    }
    function techparameterCheck(){
        if(clampArmlength_user===clampArmlength_input){
            clampArmlengthInput_preview.contentConsist = true;
        }else if(clampArmlength_user!=clampArmlength_input){
            clampArmlengthInput_preview.contentConsist = false;
        }

        if(reviseCoefficient_user===reviseCoefficient_input){
            reviseCoefficientInput_preview.contentConsist = true;
        }else if(reviseCoefficient_user!=clampArmlength_input){
            reviseCoefficientInput_preview.contentConsist = false;
        }

        if(pulseNumber_user===pulseNumber_input){
            pulseNumberInput_preview.contentConsist = true;
        }else if(pulseNumber_user!=pulseNumber_input){
            pulseNumberInput_preview.contentConsist = false;
        }

        if(threadLubricantOil_user===threadLubricantOil_input){
            threadLubricantOilInput_preview.contentConsist = true;
        }else if(threadLubricantOil_user!=threadLubricantOil_input){
            threadLubricantOilInput_preview.contentConsist = false;
        }

        if(sensorForce_user===sensorForce_input){
            sensorForceInput_preview.contentConsist = true;
        }else if(sensorForce_user!=sensorForce_input){
            sensorForceInput_preview.contentConsist = false;
        }

        if(delayTime_user===delayTime_input){
            delayTimeInput_preview.contentConsist = true;
        }else if(delayTime_user!=delayTime_input){
            delayTimeInput_preview.contentConsist = false;
        }

        if(shiftgearTorque_user===shiftgearTorque_input){
            shiftgearTorqueInput_preview.contentConsist = true;
        }else if(shiftgearTorque_user!=shiftgearTorque_input){
            shiftgearTorqueInput_preview.contentConsist = false;
        }

        if(dampingCoefficient_user===dampingCoefficient_input){
            dampingCoefficientInput_preview.contentConsist = true;
        }else if(dampingCoefficient_user!=dampingCoefficient_input){
            dampingCoefficientInput_preview.contentConsist = false;
        }

        if(maxStair_user===maxStair_input){
            maxStairInput_preview.contentConsist = true;
        }else if(maxStair_user!=maxStair_input){
            maxStairInput_preview.contentConsist = false;
        }

        if(minStair_user===minStair_input){
            minStairInput_preview.contentConsist = true;
        }else if(minStair_user!=minStair_input){
            minStairInput_preview.contentConsist = false;
        }
        if(managesetStatus===true&&casingsetStatus===true&&imagesetStatus===true&&techsetStatus===true){
            paramtersetStatus=true;
        }else paramtersetStatus = false;
    }
    Item{
        //进行网络的有线和无线设置
        id:wirechoosePage;
        anchors.fill:parent;
        visible:realtimeProcess===1?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"green";
        }

        Rectangle{
            width:100;
            height:50;
            color:"blue";
            //color:wirestatusRequest===1?"yellow":"green";
            x:150;
            y:parent.height-70;
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                font.pixelSize: 24;
                text:"有线连接";
                color:"white";
            }
            MouseArea{
                anchors.fill:parent;
                onPressed: {
                    parent.width=90;
                    parent.height=45;
                }
                onReleased: {
                    parent.width=100;
                    parent.height=50;
                    wiremodelRequest = 1;
                }
            }
        }
        Rectangle{
            width:100;
            height:50;
            color:"blue";
            //color:wirestatusRequest===2?"yellow":"green";
            x:350;
            y:parent.height-70;
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                font.pixelSize: 24;
                text:"无线连接";
                color:"white";
            }
            MouseArea{
                anchors.fill:parent;
                onPressed: {
                    parent.width=90;
                    parent.height=45;
                }
                onReleased: {
                    parent.width=100;
                    parent.height=50;
                    wiremodelRequest = 2;
                }
            }
        }
        Rectangle{
            width:100;
            height:50;
            color:"blue";
            x:550;
            y:parent.height-70;
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                font.pixelSize: 24;
                text:"确认";
                color:"white";
            }
            MouseArea{
                anchors.fill:parent;
                onPressed: {
                    parent.width=90;
                    parent.height=45;
                }
                onReleased: {
                    parent.width=100;
                    parent.height=50;
                    wireconnectionRequest = true;
                    wireconnectionRequest = false;
                }
            }
        }
    }

    Item{
        //实时监控的参数设置页面
        id:parametersetPage;
        anchors.fill:parent;
        visible:realtimeProcess===2?true:false;


        Rectangle{
            id:parameterSet;
            height:parent.height;
            width:parent.width*0.2;
            color:"gray";
            //未进行管理参数设置页面
            Item{
                id:managesetDisplay1;
                x:parent.width*0.1;
                y:parent.height*0.12;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber<1?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "#00000000";
                    textContent: "管理参数";
                }
            }
            //正在进行管理参数设置页面
            Item{
                id:managesetDisplay2;
                x:parent.width*0.1;
                y:parent.height*0.12;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber===1?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "yellow";
                    textContent: "管理参数";
                }
            }
            //已设置完毕，且设置正常管理参数页面
            Item{
                id:managesetDisplay3;
                x:parent.width*0.1;
                y:parent.height*0.12;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>1&&managesetStatus===true?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "green";
                    displayBordercolor: "#00000000";
                    textContent: "管理参数";
                }
            }
            //已设置完毕，且设置不正常管理参数页面
            Item{
                id:managesetDisplay4;
                x:parent.width*0.1;
                y:parent.height*0.12;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>1&&managesetStatus===false?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "red";
                    displayBordercolor: "#00000000";
                    textContent: "管理参数";
                }
            }
            //未进行套管参数设置页面
            Item{
                id:casingsetDisplay1;
                x:parent.width*0.1;
                y:parent.height*0.34;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber<2?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "#00000000";
                    textContent: "套管参数";
                }
            }
            //正在进行套管参数设置页面
            Item{
                id:casingsetDisplay2;
                x:parent.width*0.1;
                y:parent.height*0.34;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber===2?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "yellow";
                    textContent: "套管参数";
                }
            }
            //已设置完毕，且设置正常套管参数页面
            Item{
                id:casingsetDisplay3;
                x:parent.width*0.1;
                y:parent.height*0.34;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>2&&casingsetStatus===true?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "green";
                    displayBordercolor: "#00000000";
                    textContent: "套管参数";
                }
            }
            //已设置完毕，且设置不正常套管参数页面
            Item{
                id:casingsetDisplay4;
                x:parent.width*0.1;
                y:parent.height*0.34;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>2&&casingsetStatus===false?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "red";
                    displayBordercolor: "#00000000";
                    textContent: "套管参数";
                }
            }
            //未进行图形参数设置页面
            Item{
                id:imagesetDisplay1;
                x:parent.width*0.1;
                y:parent.height*0.56;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber<3?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "#00000000";
                    textContent: "图形参数";
                }
            }
            //正在进行图形参数设置页面
            Item{
                id:imagesetDisplay2;
                x:parent.width*0.1;
                y:parent.height*0.56;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber===3?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "yellow";
                    textContent: "图形参数";
                }
            }
            //已设置完毕，且设置正常图形参数页面
            Item{
                id:imagesetDisplay3;
                x:parent.width*0.1;
                y:parent.height*0.56;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>3&&imagesetStatus===true?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "green";
                    displayBordercolor: "#00000000";
                    textContent: "图形参数";
                }
            }
            //已设置完毕，且设置不正常图形参数页面
            Item{
                id:imagesetDisplay4;
                x:parent.width*0.1;
                y:parent.height*0.56;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>3&&imagesetStatus===false?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "red";
                    displayBordercolor: "#00000000";
                    textContent: "图形参数";
                }
            }
            //未进行技术参数设置页面
            Item{
                id:techsetDisplay1;
                x:parent.width*0.1;
                y:parent.height*0.78;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber<4?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "#00000000";
                    textContent: "技术参数";
                }
            }
            //正在进行技术参数设置页面
            Item{
                id:techsetDisplay2;
                x:parent.width*0.1;
                y:parent.height*0.78;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber===4?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "white";
                    displayBordercolor: "yellow";
                    textContent: "技术参数";
                }
            }
            //已设置完毕，且设置正常技术参数页面
            Item{
                id:techsetDisplay3;
                x:parent.width*0.1;
                y:parent.height*0.78;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>4&&techsetStatus===true?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "green";
                    displayBordercolor: "#00000000";
                    textContent: "技术参数";
                }
            }
            //已设置完毕，且设置不正常技术参数页面
            Item{
                id:techsetDisplay4;
                x:parent.width*0.1;
                y:parent.height*0.78;
                width:parent.width*0.8;
                height:parent.height*0.1;
                visible:paraNumber>4&&techsetStatus===false?true:false;
                ParameterSetButton{
                    anchors.fill:parent;
                    displayFillcolor: "red";
                    displayBordercolor: "#00000000";
                    textContent:"技术参数";
                }
            }
        }
        Rectangle{
            id:managePage;
            height:parent.height;
            width:parent.width*0.8;
            x:parent.width*0.2;
            color:"green";
            visible:paraNumber===1?true:false;
            ParameterTextInput{
                id:entrustunitInput;
                x:parent.width*0.03;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"委托单位";
                textContent:entrustUnit_user;
            }
            ParameterTextInput{
                id:operationareaInput;
                x:parent.width*0.53;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"作业区块";
                textContent:operationArea_user;
            }
            ParameterTextInput{
                id:operationunitInput;
                x:parent.width*0.03;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"操作单位";
                textContent:operationUnit_user;
            }
            ParameterTextInput{
                id:operationwellIDInput;
                x:parent.width*0.53;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"作业井号";
                textContent:operationWellID_user;
            }
            ParameterTextInput{
                id:cooperationunitInput;
                x:parent.width*0.03;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"协作单位";
                textContent:cooperationUnit_user;
            }
            ParameterTextInput{
                id:partyAsupervisorInput;
                x:parent.width*0.53;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"甲方监督";
                textContent:partyAsupervisor_user;
            }
            ParameterTextInput{
                id:instrmentIDInput;
                x:parent.width*0.03;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"仪器编号";
                textContent:instrmentID_user;
            }
            ParameterTextInput{
                id:technicaldirectorInput;
                x:parent.width*0.53;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"技术负责";
                textContent:technicalDirector_user;
            }
            ParameterTextInput{
                id:hydraulicclampInput;
                x:parent.width*0.03;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"液 压 钳";
                textContent:hydraulicClamp_user;
            }
            //可以使用画面由模糊变清晰的过渡效果
        }
        Rectangle{
            height:parent.height;
            width:parent.width*0.8;
            x:parent.width*0.2;
            color:"green";
            visible:paraNumber===2?true:false;
            ParameterTextInput{
                id:casingNameInput;
                x:parent.width*0.03;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"名   称";
                textContent:casingName_user;
            }
            ParameterTextInput{
                id:casingTypeInput;
                x:parent.width*0.03;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"型   号";
                textContent:casingType_user;
            }
            ParameterTextInput{
                id:casingSizeInput;
                x:parent.width*0.03;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"尺   寸";
                textContent:casingSize_user;
            }
            ParameterTextInput{
                id:casingSteelgradeInput;
                x:parent.width*0.03;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"钢   级";
                textContent:casingSteelgrade_user;
            }
            ParameterTextInput{
                id:casingThickInput;
                x:parent.width*0.03;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"重 / 厚";
                textContent:casingThick_user;
            }
            ParameterChooseBox{
                id:buckleTypeChoose;
                x:parent.width*0.53;
                y:parent.height*0.1;
                itemWidth: parent.width*0.4;
                itemHeight:parent.height*0.15;
                boxTitle:"扣型选择";
                choose1:"园扣";
                choose2:"特殊扣";
                chooseStatus:buckleType_user;
            }
            ParameterChooseBox{
                id:measureChannelChoose;
                x:parent.width*0.53;
                y:parent.height*0.5;
                itemWidth: parent.width*0.4;
                itemHeight:parent.height*0.15;
                boxTitle:"测量通道选择";
                choose1:"0通道";
                choose2:"1通道";
                chooseStatus:measureChannel_user;
            }
        }

        Rectangle{
            height:parent.height;
            width:parent.width*0.8;
            x:parent.width*0.2;
            color:"green";
            visible:paraNumber===3?true:false;
            ParameterTextInputUnit{
                id:torquerangeInput;
                x:parent.width*0.03;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"扭矩量程";
                unitContent:"N.m";
                textContent:torqueRange_user;
            }
            ParameterTextInputUnit{
                id:maxtorqueInput;
                x:parent.width*0.53;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"最大扭矩";
                unitContent:"N.m";
                textContent:maxTorque_user;
            }
            ParameterTextInputUnit{
                id:roundrangeInput;
                x:parent.width*0.03;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"圈数量程";
                unitContent:"圈";
                textContent:roundRange_user;
            }
            ParameterTextInputUnit{
                id:mintorqueInput;
                x:parent.width*0.53;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"最小扭矩";
                unitContent:"N.m";
                textContent:minTorque_user;
            }
            ParameterTextInputUnit{
                id:timerangeInput;
                x:parent.width*0.03;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"时间量程";
                unitContent:"S";
                textContent:timeRange_user;
            }
            ParameterTextInputUnit{
                id:optimaltorqueInput;
                x:parent.width*0.53;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"最佳扭矩";
                unitContent:"N.m";
                textContent:optimalTorque_user;
            }
            ParameterTextInputUnit{
                id:rpmrangeInput;
                x:parent.width*0.03;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"转速量程";
                unitContent:"RPM";
                textContent:rpmRange_user;
            }
            ParameterTextInputUnit{
                id:controltorqueInput;
                x:parent.width*0.53;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"控制扭矩";
                unitContent:"N.m";
                textContent:controlTorque_user;
            }
            ParameterTextInputUnit{
                id:raterangeInput;
                x:parent.width*0.03;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"变化率量程";
                unitContent:"N.m";
                textContent:rateRange_user;
            }
            ParameterTextInputUnit{
                id:referencetorqueInput;
                x:parent.width*0.53;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"参考扭矩";
                unitContent:"N.m";
                textContent:referenceTorque_user;
            }
        }

        Rectangle{
            height:parent.height;
            width:parent.width*0.8;
            x:parent.width*0.2;
            color:"green";
            visible:paraNumber===4?true:false;
            ParameterTextInputUnit{
                id:clampArmlengthInput;
                x:parent.width*0.03;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"钳 臂 长";
                unitContent:"m";
                textContent:clampArmlength_user;
            }
            ParameterTextInputUnit{
                id:reviseCoefficientInput;
                x:parent.width*0.53;
                y:parent.height*0.1;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"修正系数";
                textContent:reviseCoefficient_user;
            }
            ParameterTextInputUnit{
                id:pulseNumberInput;
                x:parent.width*0.03;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"脉 冲 数";
                unitContent:"冲";
                textContent:pulseNumber_user;
            }
            ParameterTextInputUnit{
                id:threadLubricantOilInput;
                x:parent.width*0.53;
                y:parent.height*0.27;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"丝 扣 油";
                unitContent:"（字符串）";
                textContent:threadLubricantOil_user;
            }
            ParameterTextInputUnit{
                id:sensorForceInput;
                x:parent.width*0.03;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"传 感 器";
                unitContent:"kN";
                textContent:sensorForce_user;
            }
            ParameterTextInputUnit{
                id:delayTimeInput;
                x:parent.width*0.53;
                y:parent.height*0.44;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"延迟时间";
                unitContent:"S";
                textContent:delayTime_user;
            }
            ParameterTextInputUnit{
                id:shiftgearTorqueInput;
                x:parent.width*0.03;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"换挡扭矩";
                unitContent:"N.m";
                textContent:shiftgearTorque_user;
            }
            ParameterTextInputUnit{
                id:dampingCoefficientInput;
                x:parent.width*0.53;
                y:parent.height*0.61;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"阻尼系数";
                unitContent:"X10";
                textContent:dampingCoefficient_user;
            }
            ParameterTextInputUnit{
                id:maxStairInput;
                x:parent.width*0.03;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"最大台阶";
                unitContent:"N.m";
                textContent:maxStair_user;
            }
            ParameterTextInputUnit{
                id:minStairInput;
                x:parent.width*0.53;
                y:parent.height*0.78;
                itemWidth:parent.width*0.4;
                itemHeight:parent.height*0.05;
                textTitle:"最小台阶";
                unitContent:"N.m";
                textContent:minStair_user;
            }
        }
        Image{
            source:"image/prePage.png";
            width:parent.height*0.05;
            height:parent.height*0.08;
            x:parent.width*0.4;
            y:parent.height*0.9;
            visible:paraNumber!=1?true:false;
            MouseArea{
                anchors.fill:parent;
                onPressed: {
                    paraNumber = paraNumber - 1;
                }
            }
        }
        Image{
            source:"image/nextPage.png";
            width:parent.height*0.05;
            height:parent.height*0.08;
            x:parent.width*0.85;
            y:parent.height*0.9;
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    if(paraNumber===1){
                        paraNumber = 2;
                        manageSubmit = true;
                        manageSubmit = false;
                    }else if(paraNumber===2){
                        paraNumber = 3;
                        casingSubmit = true;
                        casingSubmit = false;
                    }else if(paraNumber===3){
                        paraNumber = 4;
                        imageSubmit = true;
                        imageSubmit = false;
                    }else if(paraNumber===4){
                        realtimeProcess = 3;
                        paraNumber = 1;
                        techSubmit = true;
                        techSubmit = false;
                        check();
                    }
                }
            }
        }
    }
    Item{
        //实时监控中的参数设置预览页面
        id:parameterpreviewPage;
        anchors.fill:parent;
        visible:realtimeProcess===3?true:false;
        Rectangle{
            //预览的管理参数设置部分
            id:managePart;
            x:0;
            y:0;
            width:parent.width*0.5;
            height:parent.height*0.45;
            color:"green";
            border.color:"white";
            ParameterTextInput{
                id:entrustunitInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.65;
                readonlyStatus:true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"委托单位";
                textContent:entrustUnit_user;
            }
            ParameterTextInput{
                id:operationareaInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"作业区块";
                textContent:operationArea_user;
            }
            ParameterTextInput{
                id:operationunitInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"操作单位";
                textContent:operationUnit_user;
            }
            ParameterTextInput{
                id:operationwellIDInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"作业井号";
                textContent:operationWellID_user;
            }
            ParameterTextInput{
                id:cooperationunitInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"协作单位";
                textContent:cooperationUnit_user;
            }
            ParameterTextInput{
                id:partyAsupervisorInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"甲方监督";
                textContent:partyAsupervisor_user;
            }
            ParameterTextInput{
                id:instrmentIDInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"仪器编号";
                textContent:instrmentID_user;
            }
            ParameterTextInput{
                id:technicaldirectorInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"技术负责";
                textContent:technicalDirector_user;
            }
            ParameterTextInput{
                id:hydraulicclampInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"液 压 钳";
                textContent:hydraulicClamp_user;
            }
            Text{
                text:"管理参数";
                y:parent.height*0.05;
                anchors.horizontalCenter: parent.horizontalCenter;
                font.pixelSize: parent.height*0.1;
            }
        }
        Rectangle{
            //预览的套管参数设置部分
            id:casingPart;
            x:parent.width*0.5;
            y:0;
            width:parent.width*0.5;
            height:parent.height*0.45;
            color:"green";
            border.color: "white";
            ParameterTextInput{
                id:casingNameInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"名   称";
                textContent:casingName_user;
            }
            ParameterTextInput{
                id:casingTypeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"型   号";
                textContent:casingType_user;
            }
            ParameterTextInput{
                id:casingSizeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"尺   寸";
                textContent:casingSize_user;
            }
            ParameterTextInput{
                id:casingSteelgradeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"钢   级";
                textContent:casingSteelgrade_user;
            }
            ParameterTextInput{
                id:casingThickInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.65;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"重 / 厚";
                textContent:casingThick_user;
            }
            ParameterChooseBox{
                id:buckleTypeChoose_preview;
                x:parent.width*0.53;
                y:parent.height*0.3;
                itemWidth: parent.width*0.4;
                itemHeight:parent.height*0.2;
                radiobuttonEnable: false;
                boxTitle:"扣型选择";
                choose1:"园扣";
                choose2:"特殊扣";
                chooseStatus:buckleType_user;
            }
            ParameterChooseBox{
                id:measureChannelChoose_preview;
                x:parent.width*0.53;
                y:parent.height*0.6;
                itemWidth: parent.width*0.4;
                itemHeight:parent.height*0.2;
                radiobuttonEnable: false;
                boxTitle:"测量通道选择";
                choose1:"0通道";
                choose2:"1通道";
                chooseStatus:measureChannel_user;
            }
            Text{
                text:"套管参数";
                y:parent.height*0.05;
                anchors.horizontalCenter: parent.horizontalCenter;
                font.pixelSize: parent.height*0.1;
            }
        }
        Rectangle{
            //预览的图形参数设置部分
            id:imagePart;
            x:0;
            y:parent.height*0.45;
            width:parent.width*0.5;
            height:parent.height*0.45;
            color:"green";
            border.color:"white";
            ParameterTextInputUnit{
                id:torquerangeInput_preview;
                x:parent.width*0.03;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"扭矩量程";
                textContent:torqueRange_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:maxtorqueInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"最大扭矩";
                textContent:maxTorque_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:roundrangeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"圈数量程";
                textContent:roundRange_user;
                unitContent: "圈";
            }
            ParameterTextInputUnit{
                id:mintorqueInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"最小扭矩";
                textContent:minTorque_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:timerangeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"时间量程";
                textContent:timeRange_user;
                unitContent: "S";
            }
            ParameterTextInputUnit{
                id:optimaltorqueInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"最佳扭矩";
                textContent:optimalTorque_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:rpmrangeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"转速量程";
                textContent:rpmRange_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:controltorqueInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"控制扭矩";
                textContent:controlTorque_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:raterangeInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"变化率量程";
                textContent:rateRange_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:referencetorqueInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"参考扭矩";
                textContent:referenceTorque_user;
                unitContent: "N.m";
            }
            Text{
                text:"图形参数";
                y:parent.height*0.05;
                anchors.horizontalCenter: parent.horizontalCenter;
                font.pixelSize: parent.height*0.1;
            }
        }
        Rectangle{
            //预览的技术参数设置部分
            id:techPart;
            x:parent.width*0.5;
            y:parent.height*0.45;
            width:parent.width*0.5;
            height:parent.height*0.45;
            color:"green";
            border.color:"white";
            ParameterTextInputUnit{
                id:clampArmlengthInput_preview;
                x:parent.width*0.03;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"钳 臂 长";
                textContent:clampArmlength_user;
                unitContent: "m";
            }
            ParameterTextInputUnit{
                id:reviseCoefficientInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.2;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"修正系数";
                textContent:reviseCoefficient_user;
                unitContent: "";
            }
            ParameterTextInputUnit{
                id:pulseNumberInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"脉 冲 数";
                textContent:pulseNumber_user;
                unitContent: "冲";
            }
            ParameterTextInputUnit{
                id:threadLubricantOilInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.35;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"丝 油 扣";
                textContent:threadLubricantOil_user;
                unitContent: "";
            }
            ParameterTextInputUnit{
                id:sensorForceInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"传 感 器";
                textContent:sensorForce_user;
                unitContent: "kN";
            }
            ParameterTextInputUnit{
                id:delayTimeInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.5;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"延迟时间";
                textContent:delayTime_user;
                unitContent: "S";
            }
            ParameterTextInputUnit{
                id:shiftgearTorqueInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"换挡扭矩";
                textContent:shiftgearTorque_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:dampingCoefficientInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.65;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"阻尼系数";
                textContent:dampingCoefficient_user;
                unitContent: "X10";
            }
            ParameterTextInputUnit{
                id:maxStairInput_preview;
                x:parent.width*0.02;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"最大台阶";
                textContent:maxStair_user;
                unitContent: "N.m";
            }
            ParameterTextInputUnit{
                id:minStairInput_preview;
                x:parent.width*0.52;
                y:parent.height*0.8;
                part1:0.35;
                part2:0.46;
                part3:0.25;
                readonlyStatus: true;
                itemWidth:parent.width*0.47;
                itemHeight:parent.height*0.1;
                textTitle:"最小台阶";
                textContent:minStair_user;
                unitContent: "N.m";
            }
            Text{
                text:"技术参数";
                y:parent.height*0.05;
                anchors.horizontalCenter: parent.horizontalCenter;
                font.pixelSize: parent.height*0.1;
            }
        }
        Rectangle{
            id:preButton;
            width:parent.width*0.1;
            height:parent.height*0.05;
            x:parent.width*0.2;
            y:parent.height*0.925;
            color:"blue";
            Text{
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
                text:"返回修改";
                font.pixelSize: parent.height*0.6;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    realtimeProcess = 2;
                }
            }
        }
        Rectangle{
            id:nextButton_unclick;
            width:parent.width*0.1;
            height:parent.height*0.05;
            x:parent.width*0.7;
            y:parent.height*0.925;
            visible:!(paramtersetStatus);
            color:"grey";
            Text{
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
                text:"进入监控";
                font.pixelSize: parent.height*0.6;
            }
        }
        Rectangle{
            id:nextButton_click;
            width:parent.width*0.1;
            height:parent.height*0.05;
            x:parent.width*0.7;
            y:parent.height*0.925;
            property bool managesetStatus:true;/*管理参数设置是否合理*/
            property bool casingsetStatus:true;/*套管参数设置是否合理*/
            property bool imagesetStatus:true;/*图形参数设置是否合理*/
            property bool techsetStatus:true;/*技术参数设置是否合理*/
            visible:paramtersetStatus;
            //visible:false;
            color:"blue";
            Text{
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
                text:"进入监控";
                font.pixelSize: parent.height*0.6;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    realtimeProcess = 4;
                    paraSubmit = true;
                    paraSubmit = false;
                }
            }
        }            
    }
    Item{
        //实时监控中的实时显示页面
        id:realtimedisplayPage;
        anchors.fill:parent;
        visible:realtimeProcess===4?true:false;
        Text{
            text:"实时显示页面";
            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
        }
    }
}
