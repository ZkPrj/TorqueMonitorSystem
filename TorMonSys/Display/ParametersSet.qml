import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item {
    property int windowWidth:800;
    property int windowHeight:504;
    property int paraNumber:1;/*显示哪个页面，1表示管理参数，2表示套管参数，3表示图形参数，4表示技术参数，5表示预览界面*/
    property bool managesetStatus:true;/*设置的管理参数是否合理*/
    property bool casingsetStatus:true;/*设置的套管参数是否合理*/
    property bool imagesetStatus:true;/*设置的图形参数是否合理*/
    property bool techsetStatus:true;/*设置的技术参数是否合理*/
    property bool paraSubmit:false;/*用户是否提交参数设置，true为提交，false为不提交*/

    property string entrustUnit_user:entrustunitInput.inputContent;/*管理参数设置，委托单位*/
    property string operationArea_user:operationareaInput.inputContent;/*管理参数设置，作业区域*/
    property string operationUnit_user:operationunitInput.inputContent;/*管理参数设置，作业单位*/
    property string operationWellID_user:operationwellIDInput.inputContent;/*管理参数设置，作业井号*/
    property string cooperationUnit_user:cooperationunitInput.inputContent;/*管理参数设置，协作单位*/
    property string partyAsupervisor_user:partyAsupervisorInput.inputContent;/*管理参数设置，甲方监督*/
    property string instrmentID_user:instrmentIDInput.inputContent;/*管理参数设置，仪器编号*/
    property string technicalDirector_user:technicaldirectorInput.inputContent;/*管理参数设置，技术负责人*/
    property string hydraulicClamp_user:hydraulicclampInput.inputContent;/*管理参数设置，液压钳*/

    property string casingName_user;/*套管参数设置，套管名称*/
    property string casingType_user;/*套管参数设置，套管型号*/
    property string casingSize_user;/*套管参数设置，套管尺寸*/
    property string casingSteelgrade_user;/*套管参数设置，套管钢级*/
    property string casingThick_user;/*套管参数设置，套管重/厚*/
    property int buckleType_user;/*套管参数设置，套管扣型选择*/
    property int measureChannel_user;/*套管参数设置，套管测量通道*/

    property int torqueRange_user;/*图形参数设置，扭矩量程，用户设置*/
    property int maxTorque_user;/*图形参数设置，最大扭矩，用户设置*/
    property real roundRange_user;/*图形参数设置，圈数量程，用户设置*/
    property int minTorque_user;/*图形参数设置，最小扭矩，用户设置*/
    property int timeRange_user;/*图形参数设置，时间量程，用户设置*/
    property int optimalTorque_user;/*图形参数设置，最佳量程，用户设置*/
    property int rpmRange_user;/*图形参数设置，转速量程，用户设置*/
    property int controlTorque_user;/*图形参数设置，控制扭矩，用户设置*/
    property int rateRange_user;/*图形参数设置，变化率量程，用户设置*/
    property int referenceTorque_user;/*图形参数设置，参考扭矩，用户设置*/

    property real clampArmlength_user;/*技术参数设置，钳臂长，用户设置*/
    property real reviseCoefficient_user;/*技术参数设置，修正系数，用户设置*/
    property int pulseNumber_user;/*技术参数设置，脉冲数，用户设置*/
    property string threadLubricantOil_user;/*技术参数设置，丝扣油，用户设置*/
    property real sensorForce_user;/*技术参数设置，传感器力，用户设置*/
    property int delayTime_user;/*技术参数设置，延迟时间，用户设置*/
    property int shiftgearTorque_user;/*技术参数设置，换挡扭矩，用户设置*/
    property real dampingCoefficient_user;/*技术参数设置，阻尼系数，用户设置*/
    property int maxStair_user;/*技术参数设置，最大台阶，用户设置*/
    property int minStair_user;/*技术参数设置，最小台阶，用户设置*/

    property string entrustUnit:"中海油股份有限公司";/*管理参数设置，委托单位*/
    property string operationArea:"BH26";/*管理参数设置，作业区域*/
    property string operationUnit:"中海油服";/*管理参数设置，作业单位*/
    property string operationWellID:"BH26-6CASING";/*管理参数设置，作业井号*/
    property string cooperationUnit:"中海油服B16";/*管理参数设置，协作单位*/
    property string partyAsupervisor:"shunli";/*管理参数设置，甲方监督*/
    property string instrmentID:"SL-TMC116";/*管理参数设置，仪器编号*/
    property string technicalDirector:"pingan";/*管理参数设置，技术负责人*/
    property string hydraulicClamp:"如石TQ340";/*管理参数设置，液压钳*/

    property string casingName:"Fox";/*套管参数设置，套管名称*/
    property string casingType:"Fox";/*套管参数设置，套管型号*/
    property string casingSize:"9 5/8";/*套管参数设置，套管尺寸*/
    property string casingSteelgrade:"L/N-80";/*套管参数设置，套管钢级*/
    property string casingThick:"11.66mm";/*套管参数设置，套管重/厚*/
    property int buckleType:2;/*套管参数设置，套管扣型选择*/
    property int measureChannel:1;/*套管参数设置，套管测量通道*/

    property int torqueRange:17000;/*图形参数设置，扭矩量程*/
    property int maxTorque:16000;/*图形参数设置，最大扭矩*/
    property real roundRange:5.00;/*图形参数设置，圈数量程*/
    property int minTorque:12000;/*图形参数设置，最小扭矩*/
    property int timeRange:15;/*图形参数设置，时间量程*/
    property int optimalTorque:14000;/*图形参数设置，最佳量程*/
    property int rpmRange:30;/*图形参数设置，转速量程*/
    property int controlTorque:13800;/*图形参数设置，控制扭矩*/
    property int rateRange:1200;/*图形参数设置，变化率量程*/
    property int referenceTorque:1600;/*图形参数设置，参考扭矩*/

    property real clampArmlength:1.07;/*技术参数设置，钳臂长*/
    property real reviseCoefficient:1.0001;/*技术参数设置，修正系数*/
    property int pulseNumber:600;/*技术参数设置，脉冲数*/
    property string threadLubricantOil:"APIMOD";/*技术参数设置，丝扣油*/
    property real sensorForce:40.0;/*技术参数设置，传感器力*/
    property int delayTime:2;/*技术参数设置，延迟时间*/
    property int shiftgearTorque:0;/*技术参数设置，换挡扭矩*/
    property real dampingCoefficient:1;/*技术参数设置，阻尼系数*/
    property int maxStair:2300;/*技术参数设置，最大台阶*/
    property int minStair:5600;/*技术参数设置，最小台阶*/

    width:windowWidth;
    height:windowHeight;

    onParaNumberChanged: {
        entrustUnit = entrustunitInput.inputContent;
    }

    Rectangle{
        id:parameterSet;
        height:parent.height;
        width:parent.width*0.2;
        color:"gray";
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
            textContent:entrustUnit;
        }
        ParameterTextInput{
            id:operationareaInput;
            x:parent.width*0.53;
            y:parent.height*0.1;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"作业区块";
            textContent:entrustUnit;
        }
        ParameterTextInput{
            id:operationunitInput;
            x:parent.width*0.03;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"操作单位";
            textContent:operationUnit;
        }
        ParameterTextInput{
            id:operationwellIDInput;
            x:parent.width*0.53;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"作业井号";
            textContent:operationWellID;
        }
        ParameterTextInput{
            id:cooperationunitInput;
            x:parent.width*0.03;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"协作单位";
            textContent:cooperationUnit;
        }
        ParameterTextInput{
            id:partyAsupervisorInput;
            x:parent.width*0.53;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"甲方监督";
            textContent:partyAsupervisor;
        }
        ParameterTextInput{
            id:instrmentIDInput;
            x:parent.width*0.03;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"仪器编号";
            textContent:instrmentID;
        }
        ParameterTextInput{
            id:technicaldirectorInput;
            x:parent.width*0.53;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"技术负责";
            textContent:technicalDirector;
        }
        ParameterTextInput{
            id:hydraulicclampInput;
            x:parent.width*0.03;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"液 压 钳";
            textContent:hydraulicClamp;
        }
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
            textTitle:"名     称";
            textContent:casingName;
        }
        ParameterTextInput{
            id:casingTypeInput;
            x:parent.width*0.03;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"型     号";
            textContent:casingType;
        }
        ParameterTextInput{
            id:casingSizeInput;
            x:parent.width*0.03;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"尺     寸";
            textContent:casingSize;
        }
        ParameterTextInput{
            id:casingSteelgradeInput;
            x:parent.width*0.03;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"钢     级";
            textContent:casingSteelgrade;
        }
        ParameterTextInput{
            id:casingThickInput;
            x:parent.width*0.03;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"重  /  厚";
            textContent:casingThick;
        }
        ParameterChooseBox{
            id:buckleTypeChoose;
            x:parent.width*0.53;
            y:parent.height*0.1;
            itemWidth: parent.width*0.4;
            itemHeight:parent.height*0.2;
            boxTitle:"扣型选择";
            choose1:"园扣";
            choose2:"特殊扣";
            chooseStatus:buckleType;
        }
        ParameterChooseBox{
            id:measureChannelChoose;
            x:parent.width*0.53;
            y:parent.height*0.5;
            itemWidth: parent.width*0.4;
            itemHeight:parent.height*0.2;
            boxTitle:"测量通道选择";
            choose1:"0通道";
            choose2:"1通道";
            chooseStatus:measureChannel;
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
            unit:"N.m";
            textContent:torqueRange;
        }
        ParameterTextInputUnit{
            id:maxtorqueInput;
            x:parent.width*0.53;
            y:parent.height*0.1;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"最大扭矩";
            unit:"N.m";
            textContent:maxTorque;
        }
        ParameterTextInputUnit{
            id:roundrangeInput;
            x:parent.width*0.03;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"圈数量程";
            unit:"圈";
            textContent:minTorque;
        }
        ParameterTextInputUnit{
            id:mintorqueInput;
            x:parent.width*0.53;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"最小扭矩";
            unit:"N.m";
            textContent:minTorque;
        }
        ParameterTextInputUnit{
            id:timerangeInput;
            x:parent.width*0.03;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"时间量程";
            unit:"S";
            textContent:timeRange;
        }
        ParameterTextInputUnit{
            id:optimaltorqueInput;
            x:parent.width*0.53;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"最佳扭矩";
            unit:"N.m";
            textContent:optimalTorque;
        }
        ParameterTextInputUnit{
            id:rpmrangeInput;
            x:parent.width*0.03;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"转速量程";
            unit:"RPM";
            textContent:rpmRange;
        }
        ParameterTextInputUnit{
            id:controltorqueInput;
            x:parent.width*0.53;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"控制扭矩";
            unit:"N.m";
            textContent:controlTorque;
        }
        ParameterTextInputUnit{
            id:ratetangeInput;
            x:parent.width*0.03;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"变化率量程";
            unit:"N.m";
            textContent:rateRange;
        }
        ParameterTextInputUnit{
            id:referencetorqueInput;
            x:parent.width*0.53;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"参考扭矩";
            unit:"N.m";
            textContent:referenceTorque;
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
            unit:"m";
            textContent:clampArmlength;
        }
        ParameterTextInputUnit{
            id:reviseCoefficientInput;
            x:parent.width*0.53;
            y:parent.height*0.1;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"修正系数";
            textContent:reviseCoefficient;
        }
        ParameterTextInputUnit{
            id:pulseNumberInput;
            x:parent.width*0.03;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"脉 冲 数";
            unit:"冲";
            textContent:pulseNumber;
        }
        ParameterTextInputUnit{
            id:threadLubricantOilInput;
            x:parent.width*0.53;
            y:parent.height*0.27;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"丝 扣 油";
            unit:"（字符串）";
            textContent:threadLubricantOil;
        }
        ParameterTextInputUnit{
            id:sensorForceInput;
            x:parent.width*0.03;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"传 感 器";
            unit:"kN";
            textContent:sensorForce;
        }
        ParameterTextInputUnit{
            id:delayTimeInput;
            x:parent.width*0.53;
            y:parent.height*0.44;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"延迟时间";
            unit:"S";
            textContent:delayTime;
        }
        ParameterTextInputUnit{
            id:shiftgearTorqueInput;
            x:parent.width*0.03;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"换挡扭矩";
            unit:"N.m";
            textContent:shiftgearTorque;
        }
        ParameterTextInputUnit{
            id:dampingCoefficientInput;
            x:parent.width*0.53;
            y:parent.height*0.61;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"阻尼系数";
            unit:"X10";
            textContent:dampingCoefficient;
        }
        ParameterTextInputUnit{
            id:maxStairInput;
            x:parent.width*0.03;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"最大台阶";
            unit:"N.m";
            textContent:maxStair;
        }
        ParameterTextInputUnit{
            id:minStairInput;
            x:parent.width*0.53;
            y:parent.height*0.78;
            itemWidth:parent.width*0.4;
            itemHeight:parent.height*0.05;
            textTitle:"最小台阶";
            unit:"N.m";
            textContent:minStair;
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
                if(paraNumber<4){
                    paraNumber = paraNumber + 1;
                }else if(paraNumber===4){
                    paraSubmit = true;
                    paraSubmit = false;
                }
            }
        }
    }
}
