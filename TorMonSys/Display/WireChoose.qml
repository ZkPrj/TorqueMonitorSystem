import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property int windowWidth:800;
    property int windowHeight:504;
    property int wirestatusRequest:0;
    property bool wirechooseBack:false;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Rectangle{
        width:100;
        height:50;
        color:wirestatusRequest===1?"yellow":"green";
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
            onClicked: {
                wirestatusRequest = 1;
            }
        }
    }
    Rectangle{
        width:100;
        height:50;
        color:wirestatusRequest===2?"yellow":"green";
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
            onClicked: {
                wirestatusRequest = 2;
            }
        }
    }
    Rectangle{
        width:100;
        height:50;
        color:"green";
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
            onClicked:{
                wirechooseBack = true;
                wirechooseBack = false;
            }
        }
    }
}
