import QtQuick 2.0

Item {
    //该测试文件用于测试canvas绘图。
    //界面刚打开时，每个一秒会随机产生一个数字，并根据该数字进行绘线，允许绘制20s.
    //20s后，每隔1s，最左边的一个数据消失，产生一个新数据。
    //能够存储整幅图的数据。
    width:800;
    height:600;
    property variant datas:[];
    property variant totalData:[];
    Rectangle{
        id:background;
        anchors.fill:parent;
        color:"green";
    }
    //点击按钮后，可以将整个的轨迹都保存下来。
    Rectangle{
        width:60;
        height:40;
        color:"red";
        MouseArea{
            anchors.fill:parent;
            onPressed: {
                linedraw3.visible = false;
                textString.text = totalData.length;
                imageSave.requestPaint();
                timerSet.running = false;
            }
            onReleased:{
                imageSave.save("totalDisplay.bmp");
            }
        }
    }
    Canvas{
        id:linedraw3;
        anchors.fill:parent;
        visible:true;
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0,0,1200,600);
            ctx.beginPath();
            ctx.strokeStyle = "yellow";
            ctx.lineWidth = 3;
            ctx.moveTo(0,datas[0]);
            for(var i=1;i<=19;i++){
                ctx.lineTo(50*(i+1),datas[i]);
            }
            ctx.stroke();
        }
    }
    Canvas{
        id:imageSave;
        anchors.fill:parent;
        visible:true;
        onPaint: {
            var ctx2 = getContext("2d");
            ctx2.clearRect(0,0,1200,600);
            ctx2.beginPath();
            ctx2.strokeStyle = "yellow";
            ctx2.lineWidth = 3;
            ctx2.moveTo(0,totalData[0]);
            for(var i=1;i<totalData.length;i++){
                ctx2.lineTo(1200/totalData.length*i,totalData[i]);
            }
            ctx2.stroke();
        }
    }
    Text{
        id:textString;
    }
    Text{
        id:totalvalue;
        y:40;
    }
    Timer{
        id:timerSet;
        interval: 500; running: true; repeat: true;
        onTriggered: {
            for(var j=0;j<19;j++){
                datas[j] = datas[j+1];
            }
            datas[19] = Math.random()*50+100;
            totalData.push(datas[19]);
            linedraw3.requestPaint();
            if(datas[19]>=148){
                linedraw3.save("display.png");
            }
            totalvalue.text = 1200/totalData.length;
        }
    }
}
