import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item{
    property string textTitle;/*输入框前的title*/
    property string textContent;/*输入框的内容*/
    property string inputContent:textinput.text;/*用户存储input中的数据*/
    property string unitContent;
    property int itemWidth:250;
    property int itemHeight:30;
    width:itemWidth;
    height:itemHeight;
    property real part1:0.28;
    property real part2:0.48;
    property real part3:0.3;
    property bool readonlyStatus:false;
    property bool contentConsist:true;
    Text{
        id:title
        width:parent.width*part1;
        anchors.verticalCenter: parent.verticalCenter;
        text:textTitle;
        color:"white";
        font.pixelSize:textTitle.length>4?parent.height*0.6:parent.height*0.7;
    }
    Item{
        id:normalcondition;
        anchors.fill:parent;
        visible:contentConsist;
        TextField {
            id:textinput;
            x:parent.width*0.02+title.width;
            width:parent.width*part2;
            height:parent.height;
            readOnly: readonlyStatus;
            font.pixelSize:parent.height*0.7;
            anchors.verticalCenter: parent.verticalCenter;
            text:textContent;
            style:TextFieldStyle{
                textColor:"black";
                background:Rectangle{
                    radius:2;
                    implicitWidth:parent.width;
                    implicitHeight:parent.height;
                    border.color:"#333";
                    border.width:1;
                }
            }
        }
    }
    Item{
        id:unnormalcondition;
        anchors.fill:parent;
        visible:!(contentConsist);
        TextField {
            id:textinput2;
            x:parent.width*0.02+title.width;
            width:parent.width*part2;
            height:parent.height;
            readOnly: readonlyStatus;
            font.pixelSize:parent.height*0.7;
            anchors.verticalCenter: parent.verticalCenter;
            text:textContent;
            style:TextFieldStyle{
                textColor:"red";
                background:Rectangle{
                    radius:2;
                    implicitWidth:parent.width;
                    implicitHeight:parent.height;
                    border.color:"#333";
                    border.width:1;
                }
            }
        }
    }
    Text{
        id:unit;
        x:parent.width*0.04+title.width+textinput.width;
        width:parent.width*part2;
        anchors.verticalCenter: parent.verticalCenter;
        text:unitContent;
        color:"white";
        font.pixelSize:parent.height*0.7;
    }
}
