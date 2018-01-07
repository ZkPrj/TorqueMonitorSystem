import QtQuick 2.0

Item {
    property int windowWidth;
    property int windowHeight;
    property bool justifytestback:false;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Text{
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        text:"校准测试界面";
        font.pixelSize:parent.height*0.1;
    }
    Rectangle{
        width:100;
        height:50;
        color:"green";
        anchors.horizontalCenter: parent.horizontalCenter;
        y:parent.height-70;
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            font.pixelSize: 24;
            text:"返回";
            color:"white";
        }
        MouseArea{
            id:justifyTest_back;
            anchors.fill:parent;
            onPressed: {
                justifytestback = true;
            }
            onReleased: {
                justifytestback = false;
            }
        }
    }
}
