import QtQuick 2.0

Item {
    id:titleButtons;
    property int windowWidth:800;
    property int windowHeight:100;
    property int clickedNumber:0;
    property bool titleButtons_netStatus;
    width:windowWidth;
    height:windowHeight;
    Item{
        id:realtime_monitor_wireless;
        width:windowWidth*0.15;
        height:parent.height;
        visible:titleButtons_netStatus===false?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"grey";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"实时监控";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:realtime_monitor_choosed;
        width:windowWidth*0.15;
        height:parent.height;
        visible:(titleButtons_netStatus===true&&clickedNumber===1)?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"blue";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"实时监控";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:realtime_monitor_unchoosed;
        width:windowWidth*0.15;
        height:parent.height;
        visible:(titleButtons_netStatus===true&&clickedNumber!=1)?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"yellow";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"实时监控";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                clickedNumber = 1;
            }
        }
    }
    Item{
        id:download_file_wireless;
        width:windowWidth*0.15;
        height:parent.height;
        x:windowWidth*0.15;
        visible:titleButtons_netStatus===false?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"grey";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"下载文件";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:download_file_choosed;
        width:windowWidth*0.15;
        height:parent.height;
        x:windowWidth*0.15;
        visible:(titleButtons_netStatus===true&&clickedNumber===2)?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"blue";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"下载文件";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:download_file_unchoosed;
        width:windowWidth*0.15;
        height:parent.height;
        x:windowWidth*0.15;
        visible:(titleButtons_netStatus===true&&clickedNumber!=2)?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"yellow";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"下载文件";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                clickedNumber = 2;
            }
        }
    }
    Item{
        id:data_view_choosed;
        width:windowWidth*0.15;
        x:windowWidth*0.3;
        height:parent.height;
        visible:clickedNumber===3?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"blue";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"数据查看";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:data_view_unchoosed;
        width:windowWidth*0.15;
        x:windowWidth*0.3;
        height:parent.height;
        visible:clickedNumber!=3?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"yellow";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"数据查看";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
        MouseArea{
            anchors.fill:parent;
            onClicked: {
                clickedNumber = 3;
            }
        }
    }
    Item{
        id:justify_test_choosed;
        width:windowWidth*0.15;
        height:parent.height;
        x:windowWidth*0.45;
        visible:clickedNumber===4?true:false;
        Rectangle{
            anchors.fill:parent;
            color:"blue";
            border.color: "white";
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"校准测试";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
    }
    Item{
        id:justify_test_unchoosed;
        width:windowWidth*0.15;
        height:parent.height;
        x:windowWidth*0.45;
        visible:clickedNumber!=4?true:false;
        Rectangle{
            id:justify_test_background;
            anchors.fill:parent;
            color:"yellow";
            border.color: "white";
        }
        Text{
            id:justify_test_text;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text:"校准测试";
            font.pixelSize: windowHeight*0.3;
            color:"black";
        }
        MouseArea{
            id:justify_test_mousearea;
            anchors.fill:parent;
            onClicked: {
                clickedNumber = 4;
            }
        }
    }
}
