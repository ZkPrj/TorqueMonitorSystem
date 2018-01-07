import QtQuick 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: win
    visible: true
    property string string1:"aaa";
    property string string2;

    width: 600;
    height:400;
    ParameterChooseBox{
        id:test1;
        chooseStatus: 1
    }
    ParameterChooseBox{
        id:test2;
        y:100
        chooseStatus: 2
    }
    Text{
        text:test1.chooseStatus_input;
    }
}
