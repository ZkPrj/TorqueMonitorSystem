import QtQuick 2.5
import QtQuick.Window 2.2
Window {
    id:windowpage;
    property real windowWidth;
    visible: true;
    width:800;
    height:600;
    title: qsTr("Hello World");
    //flags: Qt.FramelessWindowHint;
    color:"green";
    Text{
        //text:mouseX_position.toString();
    }
    Rectangle{
        color:"blue";
        width:5;
        height:parent.height;
        x:parent.width-5;

        MouseArea{
            anchors.fill:parent;
            property point clickPos:"0,0";
            onPressed: {
                clickPos = Qt.point(mouse.x,mouse.y);
                windowWidth = clickPos.x;
            }
            onPositionChanged: {
                var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y);
                windowpage.setWidth(windowWidth+delta.x);
                //windowpage.setX(windowpage.x+delta.x);
                //windowpage.setY(windowpage.y+delta.y);
            }
        }
    }

    /*Rectangle{
        color:"blue";
        width:windowpage.width-10;
        height:5;
        x:5;
        y:windowpage.height-5;
        MouseArea{
            anchors.fill:parent;
            property point clickPos:"0,0";
            //property int areaHeight;

            onPressed: {
                clickPos =Qt.point(mouse.x,mouse.y);
                //areaHeight = windowpage.height;
            }
            //还是有问题，控制不够精确，可能是某个参数设置有问题，需要进一步调节
            onPositionChanged: {
                var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y);
                windowpage.setHeight(windowpage.y+delta.y);
                console.log(delta.y);
            }
        }
    }*/
    /*Image{
        //x:200;
        id:closeButton;
        //anchors.horizontalCenter: parent.horizontalCenter;
        x:windowpage.width-closeButton.width;
        width:30;
        height:30;
        //anchors.fill:parent;
        source:"image/close.png";
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                Qt.quit();
            }
        }
    }*/
}
