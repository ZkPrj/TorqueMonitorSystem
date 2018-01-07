import QtQuick 2.0;
import QtQuick.Controls 1.4;
import QtQuick.Layouts 1.2;
import QtQuick.Controls.Styles 1.4
//import QtQuick.Controls 2.0

Item {
    id:root;
    property int itemWidth:300;
    property int itemHeight:100;
    property string boxTitle;
    property string choose1;
    property string choose2;
    property int chooseStatus;
    property int chooseStatus_input:exclusivegroup.current===button1?1:2;
    property bool radiobuttonEnable:true;
    property bool contentConsistent:true;
    width:itemWidth;
    height:itemHeight;

    ExclusiveGroup{
        id:exclusivegroup;
        current:chooseStatus===1?button1:button2;
    }
    Rectangle{
        anchors.fill:parent;
        color:"green";
    }
    GroupBox{
        id:normalcondition;
        visible:contentConsistent;
        anchors.fill:parent;
        Text{
            y:root.height*(-0.5);
            text:boxTitle;
            font.pixelSize: root.height*0.3;
            color:"white";
        }

        RowLayout{
            anchors.verticalCenter: parent.verticalCenter;
            x:parent.width*0.05;
            spacing:parent.width*0.2;
            RadioButton{              
                id:button1;
                exclusiveGroup:exclusivegroup;
                enabled:radiobuttonEnable;
                style:RadioButtonStyle{
                    label:Text{
                        text:choose1;
                        font.pixelSize: root.height*0.3;
                        color:"white";
                    }
                    indicator:Rectangle{
                        implicitWidth: root.height*0.2;
                        implicitHeight: root.height*0.2;
                        radius: root.height*0.09;
                        border.color: control.activeFocus ? "darkblue" : "gray"
                        border.width: 1
                        Rectangle{
                            anchors.fill: parent;
                            visible: control.checked;
                            color: "#555";
                            radius: root.height*0.09;
                            anchors.margins: root.height*0.05;
                        }
                    }
                }
            }
            RadioButton{
                id:button2;
                exclusiveGroup:exclusivegroup;
                enabled:radiobuttonEnable;
                style:RadioButtonStyle{
                    label:Text{
                        text:choose2;
                        font.pixelSize: root.height*0.3;
                        color:"white";
                    }
                    indicator:Rectangle{
                        implicitWidth: root.height*0.2;
                        implicitHeight: root.height*0.2;
                        radius: root.height*0.09;
                        border.color: control.activeFocus ? "darkblue" : "gray"
                        border.width: 1;
                        Rectangle{
                            anchors.fill: parent;
                            visible: control.checked;
                            color: "#555";
                            radius: root.height*0.09;
                            anchors.margins: root.height*0.05;
                        }
                    }
                }
            }
        }
    }
    GroupBox{
        id:unnormalcondition;
        visible:!(contentConsistent);
        anchors.fill:parent;
        Text{
            y:root.height*(-0.5);
            text:boxTitle;
            font.pixelSize: root.height*0.3;
            color:"white";
        }

        RowLayout{
            anchors.verticalCenter: parent.verticalCenter;
            x:parent.width*0.05;
            spacing:parent.width*0.2;
            RadioButton{
                id:button3;
                exclusiveGroup:exclusivegroup;
                enabled:radiobuttonEnable;
                style:RadioButtonStyle{
                    label:Text{
                        text:choose1;
                        font.pixelSize: root.height*0.3;
                        color:"yellow";
                    }
                    indicator:Rectangle{
                        implicitWidth: root.height*0.2;
                        implicitHeight: root.height*0.2;
                        radius: root.height*0.09;
                        border.color: control.activeFocus ? "darkblue" : "gray"
                        border.width: 1
                        Rectangle{
                            anchors.fill: parent;
                            visible: control.checked;
                            color: "#555";
                            radius: root.height*0.09;
                            anchors.margins: root.height*0.05;
                        }
                    }
                }
            }
            RadioButton{
                id:button4;
                exclusiveGroup:exclusivegroup;
                enabled:radiobuttonEnable;
                style:RadioButtonStyle{
                    label:Text{
                        text:choose2;
                        font.pixelSize: root.height*0.3;
                        color:"yellow";
                    }
                    indicator:Rectangle{
                        implicitWidth: root.height*0.2;
                        implicitHeight: root.height*0.2;
                        radius: root.height*0.09;
                        border.color: control.activeFocus ? "darkblue" : "gray"
                        border.width: 1;
                        Rectangle{
                            anchors.fill: parent;
                            visible: control.checked;
                            color: "#555";
                            radius: root.height*0.09;
                            anchors.margins: root.height*0.05;
                        }
                    }
                }
            }
        }
    }
}
