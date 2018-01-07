import QtQuick 2.5
//import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
//import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0

ApplicationWindow{
    id:root;
    visible: true;
    width:800;
    height:800;
    property int count: 0
    //连接状态
    Rectangle {
        id: connStatusRect
        x: 44
        y: 39
        width: 167
        height: 46
        color: "#ffffff"
        border.width: 2
        border.color: "red"
        Text{
            id: connTxt
            anchors.centerIn: parent
            text:"False"
        }
    }
    //通信类型
    Rectangle{
        id: commSelectRect
        visible: false
        border.color: "red"
        border.width: 2
        width: 250
        height: 110
        anchors.top:  connStatusRect.bottom
        anchors.topMargin: 20
        anchors.left: connStatusRect.left
        RowLayout{
            id: commRowLayOut
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            RadioButton{
                id: wirelessBtn
                text: qsTr("无线通信")
                checked: true
            }
            RadioButton{
                id: wireBtn
                text: qsTr("有线通信")
            }
        }
        Button{
            id: commBtn
            anchors.top: commRowLayOut.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            text: "设置"
            onClicked: {
                if (wirelessBtn.checked){
                    UiLayer.setCommType(0)
                }
                else{
                    UiLayer.setCommType(1)
                }
            }
        }
    }
    /*设置参数*/
    Rectangle{
        id: argSetRect
        visible: false
        anchors.top: commSelectRect.bottom
        anchors.topMargin: 10
        anchors.left:  commSelectRect.left
        width: 100
        height: 50
        Button{
            id: timeBtn
            text: "设置参数"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            onClicked: {
                UiLayer.reqUperDefaultArgs()
                count = 0;
                argPopup.open()
            }
        }
    }

    Popup{
        id: argPopup
        x: (root.width - width)/2
        y: (root.height - height)/2
        width: 700
        height: 730
        modal: true
        focus: true

        //contentHeight: argView.height
        //contentWidth: argView.width
//        contentItem: Rectangle{
//            focus: true
//            Button{
//                anchors.centerIn: parent
//                text:"Push Me"
//            }
//        }

        contentItem: ArgView{
            id: argView
            //width: 680
            //height: 700
            anchors.centerIn: argPopup
        }
    }

    Popup{
        id: torDisp
        x: (root.width - width)/2
        y: (root.height - height)/2
        width: 700
        height: 730
        modal: true
        focus: true
        contentItem: Tst{
            id: torView
            anchors.fill: parent
        }
    }

    Timer{
        running: true
        interval: 500
        repeat: true

        onTriggered: {
            if (UiLayer.getUpConnStatus())
            {
                connTxt.text = "OK!"
                connStatusRect.border.color = "blue"
                commSelectRect.visible = true;
            }
            else
            {
                connTxt.text = "Disconnect!"
                connStatusRect.border.color = "red"
                commSelectRect.visible = false;
            }
            //设置通信类型的选择
            if (commSelectRect.visible === true)
            {
                if (UiLayer.getCommType() === 0&&
                        wirelessBtn.checked === true) /*无线*/
                {
                    commSelectRect.border.color = "blue"
                    wirelessBtn.enabled = false
                    wireBtn.enabled = false
                    commBtn.enabled = false
                    argSetRect.visible = true
                }
                else if (UiLayer.getCommType() === 1&&
                         wireBtn.checked === true)/*有线*/
                {
                    commSelectRect.border.color = "blue"
                    wirelessBtn.enabled = false
                    wireBtn.enabled = false
                    commBtn.enabled = false
                    argSetRect.visible = true
                }
                else
                {
                    commSelectRect.border.color = "red"
                    wirelessBtn.enabled = true
                    wireBtn.enabled = true
                    commBtn.enabled = true
                }
            }
            //参数显示
            if (argPopup.visible === true)
            {
                count = (count + 1);
                if (count >= 20)
                    return ;
                argView.getAndInitUsrData()
            }
        }
    }

    Connections{
        target: argPopup
        onClosed:{
            console.log("argpopup closed")
            UiLayer.startTorMonitor()
            torView.initTorArg()
            torDisp.open()
        }
    }
}
