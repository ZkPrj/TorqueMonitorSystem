import QtQuick 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
Item{
    property string textTitle;/*输入框前的title*/
    property string textContent;/*输入框的内容*/
    property string inputContent:textinput.text;/*用户存储input中的数据*/
    property int itemWidth:250;
    property int itemHeight:30;
    property real part1:0.3;
    property real part2:0.7;
    property bool readonlyStatus:false;
    property bool contentConsistent:true;

    width:itemWidth;
    height:itemHeight;
    Text{
        width:parent.width*part1;
        anchors.verticalCenter: parent.verticalCenter;
        text:textTitle;
        color:"white";
        font.pixelSize:parent.height*0.7;
    }
    Item{
        id:normalCondition;
        visible:contentConsistent;
        anchors.fill:parent;
        TextField {
            id:textinput;
            x:parent.width*part1;
            width:parent.width*part2;
            height:parent.height;
            font.pixelSize:parent.height*0.7;
            anchors.verticalCenter: parent.verticalCenter;
            text:textContent;
            readOnly:readonlyStatus;
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
        id:unnormalCondition;
        anchors.fill:parent;
        visible:!(contentConsistent);
        TextField {
            id:textinput2;
            x:parent.width*part1;
            width:parent.width*part2;
            height:parent.height;
            font.pixelSize:parent.height*0.7;
            anchors.verticalCenter: parent.verticalCenter;
            text:textContent;
            readOnly:readonlyStatus;
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
}
