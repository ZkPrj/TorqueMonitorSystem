import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Timer{
        repeat: true
        running: true
        interval: 1000
        onTriggered: {
            var a = TstModel.getTorList()
            var b = TstModel.getTimeSpan()
            console.log(a.length,b[2])
        }
    }
}
