import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property int windowWidth:800;
    property int windowHeight:504;
    property int filedownPortation;
    property int fileprocessPortation;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"red";
    }
    Text{
        text:filedownPortation<100?"文件下载":"文件处理";
        font.pixelSize: 30;
        color:"white";
        x:parent.width/2;
        y:parent.height/2-50;
    }

    ProgressBar{
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        value:filedownPortation<100?filedownPortation*0.01:fileprocessPortation*0.01;
    }
}
