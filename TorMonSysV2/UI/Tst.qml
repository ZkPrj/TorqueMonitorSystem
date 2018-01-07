import QtQuick 2.0

Rectangle{
    id: root
    width: 800
    height: 800
    property int gridSize: 4
    color: "white"
    Canvas{
        id: canvas
        anchors.centerIn: root
        width: 600
        height: 500
        property int pixelSkip: 1
        property int numPoints: 1
        property int tickMargin: 34

        property string drawTorColor: "orange"
        property string bestTorColor: "blue"
        property string maxTorColor: "red"
        property string curTorColor: "green"
        property string curCycleColor: "purple"

        property real drawTor: 1000
        property real maxTor: 9000
        property real bestTor: 7000

        property int torScale: 1000
        property int timeScale: 1
        property int cycleScale: 2
        property real xGridSize: 10+2
        property real yGridSize: 10+2
        property real xLeftOffset: 50
        property real yTopOffset: 50
        property real xRightOffset: 100
        property real yBottomOffset: 50
        property real xGridStep: (canvas.width-xLeftOffset-xRightOffset)/xGridSize
        property real yGridStep: (canvas.height-yTopOffset-yBottomOffset)/yGridSize

        function drawTorLine(ctx){
            /*请求数据*/
            ctx.save()
            UiLayer.reqCurTorList()
            var torList = UiLayer.getCurTorList()
            var cycleList = UiLayer.getCurCycleList()
            var timeSpanList = UiLayer.getTimeSpanList()
            //画线
            ctx.strokeStyle = curTorColor
            ctx.beginPath()
            for (var i = 0; i< torList.length; ++i){
                var x = timeSpanList[i]%1000.0;
                var y = torList[i];
                x = canvas.xLeftOffset + canvas.xGridStep*(1 + x*timeScale)
                y = canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+y/torScale)
                if (i === 0){
                    ctx.moveTo(x,y)
                }else{
                    ctx.lineTo(x,y)
                }
            }
            ctx.stroke();
            ctx.strokeStyle = curCycleColor
            ctx.beginPath()
            for (i = 0; i< torList.length; ++i){
                var x = cycleList[i];
                var y = torList[i];
                x = canvas.xLeftOffset + canvas.xGridStep*(1 + x*cycleScale)
                y = canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+y/torScale)
                if (i === 0){
                    ctx.moveTo(x,y)
                }else{
                    ctx.lineTo(x,y)
                }
            }
            ctx.stroke();
            ctx.restore()
        }

        function drawBackground(ctx){
            ctx.save()
            ctx.fillStyle = "#eeeeee";
            ctx.fillRect(0, 0, canvas.width, canvas.height);
            ctx.strokeStyle = "#d7d7d7";

            ctx.beginPath();
            // 画一个20*20的网格
            for (var i = 0; i < canvas.yGridSize + 1; i++) {
                ctx.moveTo(xLeftOffset, canvas.yTopOffset + i * canvas.yGridStep);
                ctx.lineTo(canvas.width-xRightOffset, canvas.yTopOffset + i * canvas.yGridStep);
            }

            // Vertical grid lines
            for (i = 0; i < canvas.xGridSize+1; i++) {
                ctx.moveTo(canvas.xLeftOffset + i * canvas.xGridStep, yTopOffset);
                ctx.lineTo(canvas.xLeftOffset + i * canvas.xGridStep, canvas.height-yBottomOffset);
            }
            ctx.stroke();
            //坐标轴画粗线
            /*左、上、下加粗*/
            ctx.strokeStyle = "#666666";
            ctx.beginPath();
            ctx.moveTo(canvas.xLeftOffset+canvas.xGridStep, canvas.yTopOffset + canvas.yGridStep)
            ctx.lineTo(canvas.xLeftOffset+canvas.xGridStep, canvas.height-canvas.yBottomOffset-canvas.yGridStep)
            ctx.moveTo(canvas.width-canvas.xRightOffset-canvas.xGridStep, canvas.yTopOffset+canvas.yGridStep)
            ctx.lineTo(canvas.width-canvas.xRightOffset-canvas.xGridStep, canvas.height-canvas.yBottomOffset-canvas.yGridStep)
            ctx.moveTo(canvas.xLeftOffset+canvas.xGridStep, canvas.yTopOffset + canvas.yGridStep)
            ctx.lineTo(canvas.width - canvas.xRightOffset-canvas.xGridStep, canvas.yTopOffset + canvas.yGridStep)
            ctx.moveTo(canvas.xLeftOffset+canvas.xGridStep, canvas.height-canvas.yBottomOffset-canvas.yGridStep)
            ctx.lineTo(canvas.width - canvas.xRightOffset-canvas.xGridStep, canvas.height-canvas.yBottomOffset-canvas.yGridStep)
            ctx.stroke()
            //画横坐标、纵坐标标线
            ctx.beginPath();
            for (i =0; i < canvas.xGridSize-1; ++i){
                ctx.moveTo(canvas.xLeftOffset+(i+1) * canvas.xGridStep, canvas.yTopOffset + 0.5*canvas.yGridStep)
                ctx.lineTo(canvas.xLeftOffset+(i+1) * canvas.xGridStep, canvas.yTopOffset+canvas.yGridStep)
                ctx.moveTo(canvas.xLeftOffset+(i+1) * canvas.xGridStep, canvas.height - canvas.yBottomOffset- 0.5*canvas.yGridStep)
                ctx.lineTo(canvas.xLeftOffset+(i+1) * canvas.xGridStep, canvas.height - canvas.yBottomOffset-canvas.yGridStep)
            }
            for (i = 0; i < canvas.yGridSize-1; ++i){
                ctx.moveTo(canvas.xLeftOffset +0.5*canvas.xGridStep, canvas.yTopOffset+(i+1)*canvas.yGridStep)
                ctx.lineTo(canvas.xLeftOffset +canvas.xGridStep, canvas.yTopOffset+(i+1)*canvas.yGridStep)

            }
            ctx.stroke()
            ctx.beginPath();
            ctx.fillStyle = "black"
            ctx.font = "13px Arial"
            ctx.textAlign = "left"
            for(i=0; i<canvas.yGridSize-1; ++i){
                //标记扭矩的纵坐标
                var metrice = ctx.measureText((i*torScale).toString())
                ctx.fillText((i*torScale).toString(), canvas.xLeftOffset-metrice.width+2, canvas.height - canvas.yBottomOffset-(i+1)*canvas.yGridStep+2)
                if (i === canvas.yGridSize-2){
                    metrice = ctx.measureText("扭矩(kN.m)")
                    ctx.fillText("扭矩(kN.m)", canvas.xLeftOffset-metrice.width/2, canvas.yTopOffset - 10)
                }
            }
            for (i=0; i<canvas.xGridSize-1; ++i){
                //标记扭矩的横坐标

                if (i%timeScale===0){
                    var metrice = ctx.measureText((i/timeScale).toString())
                    ctx.fillText((i/timeScale).toString(), canvas.xLeftOffset + (i+1)*canvas.xGridStep - metrice.width/2, canvas.height-canvas.yBottomOffset+5);
                }

                if (i%cycleScale===0){
                    var metrice = ctx.measureText((i/cycleScale).toString())
                    ctx.fillText((i/cycleScale).toString(), canvas.xLeftOffset + (i+1)*canvas.xGridStep - metrice.width/2, canvas.yTopOffset);
                }
                if (i === canvas.xGridSize - 2){
                    ctx.fillText("圈数(r)", canvas.width - canvas.xRightOffset -5, canvas.yTopOffset - 10)
                    ctx.fillText("时间(s)", canvas.width - canvas.xRightOffset -5, canvas.height-canvas.yBottomOffset)
                }
            }

            ctx.stroke()
            //画标注线
            ctx.beginPath()
            ctx.strokeStyle = canvas.maxTorColor
            ctx.moveTo(canvas.width -canvas.xRightOffset+5, canvas.yTopOffset + 50)
            ctx.lineTo(canvas.width -canvas.xRightOffset + 25, canvas.yTopOffset + 50)
            ctx.fillText("最大扭矩", canvas.width -canvas.xRightOffset + 30, canvas.yTopOffset + 50+5)
            ctx.stroke()
            ctx.beginPath()
            ctx.strokeStyle = canvas.bestTorColor
            ctx.moveTo(canvas.width -canvas.xRightOffset+5, canvas.yTopOffset + 100)
            ctx.lineTo(canvas.width -canvas.xRightOffset + 25, canvas.yTopOffset + 100)
            ctx.fillText("最佳扭矩", canvas.width -canvas.xRightOffset + 30, canvas.yTopOffset + 100+5)
            ctx.stroke()
            ctx.beginPath()
            ctx.strokeStyle = canvas.curTorColor
            ctx.moveTo(canvas.width -canvas.xRightOffset+5, canvas.yTopOffset + 150)
            ctx.lineTo(canvas.width -canvas.xRightOffset + 25, canvas.yTopOffset + 150)
            ctx.fillText("当前扭矩", canvas.width -canvas.xRightOffset + 30, canvas.yTopOffset + 150+5)
            ctx.stroke()
            ctx.beginPath()
            ctx.strokeStyle = canvas.drawTorColor
            ctx.moveTo(canvas.width -canvas.xRightOffset+5, canvas.yTopOffset + 200)
            ctx.lineTo(canvas.width -canvas.xRightOffset + 25, canvas.yTopOffset + 200)
            ctx.fillText("画线扭矩", canvas.width -canvas.xRightOffset + 30, canvas.yTopOffset + 200+5)
            ctx.stroke()
            ctx.beginPath()
            ctx.strokeStyle = canvas.curCycleColor
            ctx.moveTo(canvas.width -canvas.xRightOffset+5, canvas.yTopOffset + 250)
            ctx.lineTo(canvas.width -canvas.xRightOffset + 25, canvas.yTopOffset + 250)
            ctx.fillText("当前圈数", canvas.width -canvas.xRightOffset + 30, canvas.yTopOffset + 250+5)
            ctx.stroke()
            //最大扭矩
            ctx.beginPath()
            ctx.strokeStyle = canvas.maxTorColor
            ctx.moveTo(canvas.xLeftOffset + canvas.xGridStep, canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.maxTor/canvas.torScale))
            ctx.lineTo(canvas.width - canvas.xRightOffset - canvas.xGridStep,canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.maxTor/canvas.torScale))
            ctx.stroke()
            //画线扭矩
            ctx.beginPath()
            ctx.strokeStyle = canvas.drawTorColor
            ctx.moveTo(canvas.xLeftOffset + canvas.xGridStep, canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.drawTor/canvas.torScale))
            ctx.lineTo(canvas.width - canvas.xRightOffset - canvas.xGridStep,canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.drawTor/canvas.torScale))
            ctx.stroke()
            //最佳扭矩
            ctx.beginPath()
            ctx.strokeStyle = canvas.bestTorColor
            ctx.moveTo(canvas.xLeftOffset + canvas.xGridStep, canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.bestTor/canvas.torScale))
            ctx.lineTo(canvas.width - canvas.xRightOffset - canvas.xGridStep,canvas.height - canvas.yBottomOffset - canvas.yGridStep*(1+canvas.bestTor/canvas.torScale))
            ctx.stroke()
            ctx.restore();
        }

        onPaint: {
            var ctx = canvas.getContext("2d")
            drawBackground(ctx)
            drawTorLine(ctx)
        }
    }

    function initTorArg(){
        canvas.drawTor = UiLayer.getDrawTor()
        canvas.maxTor = UiLayer.getMaxTor()
        canvas.bestTor = UiLayer.getCtlTor()
        canvas.xGridSize = Math.max(UiLayer.getMaxTime(),UiLayer.getMaxCycle())+2
        canvas.torScale = Math.ceil(1.0*(UiLayer.getMaxTor()+500) / (canvas.yGridSize-2) )
        canvas.timeScale = Math.floor((canvas.xGridSize-2)/UiLayer.getMaxTime())
        canvas.cycleScale = Math.floor((canvas.xGridSize-2)/UiLayer.getMaxCycle())
    }
    Timer{
        repeat: true
        running: true
        interval: 100
        onTriggered: {
            canvas.requestPaint()
        }
    }
}
