import QtQuick 2.0

Item {
    property int windowWidth:800;
    property int windowHeight:504;
    width:windowWidth;
    height:windowHeight;
    Rectangle{
        anchors.fill:parent;
        color:"green";
        Item{
            id:managePart;
            x:0;
            y:0;
            width:parent.width/2;
            height:parent.height/2;
            Text{
                text:"管理参数部分";
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
        Item{
            id:casingPart;
            x:parent.width/2;
            y:0;
            width:parent.width/2;
            height:parent.height/2;
            Text{
                text:"套管参数部分";
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
        Item{
            id:imagePart;
            x:0;
            y:parent.height/2;
            width:parent.width/2;
            height:parent.height/2;
            Text{
                text:"图形参数部分";
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
        Item{
            id:techPart;
            x:parent.width/2;
            y:parent.height/2;
            width:parent.width/2;
            height:parent.height/2;
            Text{
                text:"技术参数部分";
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
    }
}
