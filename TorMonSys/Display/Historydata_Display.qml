import QtQuick 2.0
import QtQuick.Controls 1.4
Item {
    property int windowWidth;
    property int windowHeight;
    property bool historydatadisplayModify:false;
    property bool historydatadisplayPrint:false;
    property bool historydatadisplayBack:false;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Text{
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        text:"历史数据显示界面";
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
                historydatadisplayModify = true;
                historydatadisplayModify = false;
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
            text:"打印数据";
            font.pixelSize: parent.height*0.6;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                historydatadisplayPrint = true;
                historydatadisplayPrint = false;
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
                historydatadisplayBack = true;
                historydatadisplayBack = false;
            }
        }
    }
}
