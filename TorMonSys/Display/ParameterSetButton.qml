import QtQuick 2.0

Item {
    property int itemWidth;
    property int itemHeight;
    property string textContent;
    property string displayFillcolor;
    property string displayBordercolor;
    Rectangle{
        anchors.fill:parent;
        color:displayFillcolor;
        border.color: displayBordercolor;
        Text{
            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
            text:textContent;
            font.pixelSize: parent.height*0.6;
        }
    }
}
