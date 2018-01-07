import QtQuick 2.0

Rectangle{
    width: 600
    height: 600
    color: "white"

    Canvas{
        id: canvas
        width: 500
        height: 500
        anchors.centerIn: parent
        function drawBackground(ctx){
            //ctx.save()
            ctx.fillStyle = "#eeeeeeee"
            ctx.fillRect(0, 0, 500, 500)
            //ctx.strokeRect(0,0,500,500)
            //ctx.restore();
        }
        onPaint:{
            var ctx = canvas.getContext("2d");
            ctx.lineWidth = 1
//            ctx.fillStype = "blue"
//            ctx.strokeStyle = "red"
//            ctx.fillRect(0, 0, 500, 500)
//            ctx.strokeRect(0,0,300,500)
            drawBackground(ctx)
        }
    }
}
