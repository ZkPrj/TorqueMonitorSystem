import QtQuick 2.0

Item {
    property int windowWidth;
    property int windowHeight;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Text{
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        text:"初始界面";
        font.pixelSize:parent.height*0.1;
    }
}
