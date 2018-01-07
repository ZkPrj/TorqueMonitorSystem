import QtQuick 2.0
import QtQuick.Controls 1.4
Item {
    property int windowWidth;
    property int windowHeight;
    property bool printdataModify:false;
    property bool printdataComfirm:false;
    property bool printdataBack:false;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Text{
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        text:"打印数据显示界面";
        font.pixelSize:parent.height*0.1;
    }
    Rectangle{
        id:modify_data;
        width:parent.width*0.12;
        height:parent.height*0.08;
        y:parent.height*0.92;
        x:parent.width*0.64;
        border.color: "black";
        Text{
            text:"修改数据";
            font.pixelSize: parent.height*0.6;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                printdataModify = true;
                printdataModify = false;
            }
        }
    }
    Rectangle{
        id:print_data;
        width:parent.width*0.12;
        height:parent.height*0.08;
        y:parent.height*0.92;
        x:parent.width*0.76;
        border.color: "black";
        Text{
            text:"确认";
            font.pixelSize: parent.height*0.6;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                printdataComfirm = true;
                printdataComfirm = false;
            }
        }
    }
    Rectangle{
        id:returnButton;
        width:parent.width*0.12;
        height:parent.height*0.08;
        y:parent.height*0.92;
        x:parent.width*0.88;
        border.color: "black";
        Text{
            text:"返回";
            font.pixelSize: parent.height*0.6;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                printdataBack = true;
                printdataBack = false;
            }
        }
    }
}
