import QtQuick 2.0
import QtQuick.Controls 1.4
Item {
    property int windowWidth:800;
    property int windowHeight:504;
    width:windowWidth;
    height:windowHeight;
    property int historydataKey:1;
    property int historydataID;
    property bool historydatadisplayActive:false;
    Rectangle{
        height:parent.height;
        width:parent.width*0.3;
        color:"gray";
        Rectangle{
            x:parent.width*0.1;
            y:parent.height*0.09;
            width:parent.width*0.8;
            height:parent.height*0.09;
            color:historydataKey===1?"green":"blue";
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                text:"关键词1";
                font.pixelSize: parent.height*0.7;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    historydataKey = 1;
                }
            }
        }
        Rectangle{
            x:parent.width*0.1;
            y:parent.height*0.27;
            width:parent.width*0.8;
            height:parent.height*0.09;
            color:historydataKey===2?"green":"blue";
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                text:"关键词2";
                font.pixelSize: parent.height*0.7;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    historydataKey = 2;
                }
            }
        }
        Rectangle{
            x:parent.width*0.1;
            y:parent.height*0.45;
            width:parent.width*0.8;
            height:parent.height*0.09;
            color:historydataKey===3?"green":"blue";
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                text:"关键词3";
                font.pixelSize: parent.height*0.7;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    historydataKey = 3;
                }
            }
        }
        Rectangle{
            x:parent.width*0.1;
            y:parent.height*0.63;
            width:parent.width*0.8;
            height:parent.height*0.09;
            color:historydataKey===4?"green":"blue";
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                text:"关键词4";
                font.pixelSize: parent.height*0.7;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    historydataKey = 4;
                }
            }
        }
        Rectangle{
            x:parent.width*0.1;
            y:parent.height*0.81;
            width:parent.width*0.8;
            height:parent.height*0.09;
            color:"cyan";
            Text{
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                text:"查看";
                font.pixelSize: parent.height*0.7;
            }
            MouseArea{
                anchors.fill:parent;
                onClicked: {
                    historydatadisplayActive = true;
                    historydatadisplayActive = false;
                }
            }
        }
    }
    Rectangle{
        height:parent.height;
        width:parent.width*0.7;
        x:parent.width*0.3;
        color:"red";
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            font.pixelSize: parent.height*0.1;
            text:"历史数据查看界面";
            color:"white";
        }
        Image{
            source:"image/prePage.png";
            width:parent.height*0.05;
            height:parent.height*0.08;
            x:parent.width*0.2;
            y:parent.height*0.9;
        }
        Image{
            source:"image/nextPage.png";
            width:parent.height*0.05;
            height:parent.height*0.08;
            x:parent.width*0.75;
            y:parent.height*0.9;
        }
    }
}
