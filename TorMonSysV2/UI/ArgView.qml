import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle{
    id: root
    width: 680
    height: 700
    border.width: 2
    border.color: "red"

    Label {
        id: label1
        x: 20
        y: 28
        text: qsTr("DeleCompany")
    }

    Label {
        id: label2
        x: 26
        y: 74
        text: qsTr("ExcCompany")
    }

    Label {
        id: label3
        x: 8
        y: 120
        text: qsTr("CollabCompany")
    }

    Label {
        id: label4
        x: 32
        y: 166
        text: qsTr("MachineNo")
    }

    Label {
        id: label5
        x: 38
        y: 212
        text: qsTr("HydClamp")
    }

    Label {
        id: label6
        x: 50
        y: 258
        text: qsTr("AreaNo")
    }

    Label {
        id: label7
        x: 50
        y: 304
        text: qsTr("WellNo")
    }

    Label {
        id: label8
        x: 26
        y: 350
        text: qsTr("OwnerSuper")
    }

    Label {
        id: label9
        x: 44
        y: 396
        text: qsTr("TechDir")
    }

    Label {
        id: label10
        x: 50
        y: 442
        text: qsTr("Remark")
    }

    Label {
        id: label11
        x: 38
        y: 488
        text: qsTr("PipeName")
    }

    Label {
        id: label12
        x: 38
        y: 534
        text: qsTr("PipeType")
    }

    Label {
        id: label13
        x: 14
        y: 580
        text: qsTr("PipeDiameter")
    }

    Label {
        id: label14
        x: 32
        y: 626
        text: qsTr("PipeClass")
    }

    Label {
        id: label15
        x: 362
        y: 28
        text: qsTr("PipeThickness")
    }

    Label {
        id: label16
        x: 380
        y: 74
        width: 60
        height: 12
        text: qsTr("TongArmLen")
    }

    Label {
        id: label17
        x: 380
        y: 120
        text: qsTr("CorrFactor")
    }

    Label {
        id: label18
        x: 386
        y: 166
        text: qsTr("DelayTime")
    }

    Label {
        id: label19
        x: 398
        y: 212
        text: qsTr("MinStep")
    }

    Label {
        id: label20
        x: 398
        y: 258
        text: qsTr("MaxStep")
    }

    Label {
        id: label21
        x: 386
        y: 304
        text: qsTr("MaxTorque")
    }

    Label {
        id: label22
        x: 386
        y: 350
        text: qsTr("MinTorque")
    }

    Label {
        id: label23
        x: 380
        y: 396
        text: qsTr("BestTorque")
    }

    Label {
        id: label24
        x: 386
        y: 442
        text: qsTr("CtlTorque")
    }

    Label {
        id: label25
        x: 380
        y: 488
        text: qsTr("DrawTorque")
    }

    Label {
        id: label26
        x: 398
        y: 534
        text: qsTr("MaxTime")
    }

    Label {
        id: label27
        x: 392
        y: 580
        text: qsTr("MaxCycle")
    }

    TextField {
        id: deleCompTxtF
        x: 103
        y: 14
    }

    TextField {
        id: exeCompTxtF
        x: 103
        y: 60
        text: qsTr("")
    }

    TextField {
        id: collCompTxtF
        x: 103
        y: 106
        text: qsTr("")
    }

    TextField {
        id: machineTxtF
        x: 103
        y: 152
        text: qsTr("")
    }

    TextField {
        id: hydClampTxtF
        x: 103
        y: 198
        text: qsTr("")
    }

    TextField {
        id: areaNoTxtF
        x: 103
        y: 244
        text: qsTr("")
    }

    TextField {
        id: wellNoTxtF
        x: 103
        y: 290
        text: qsTr("")
    }

    TextField {
        id: ownerSupTxtF
        x: 103
        y: 336
        text: qsTr("")
    }

    TextField {
        id: techDirTxtF
        x: 103
        y: 382
        text: qsTr("")
    }

    TextField {
        id: remarkTxtF
        x: 103
        y: 428
    }

    TextField {
        id: pipeNameTxtF
        x: 103
        y: 474
        text: qsTr("")
    }

    TextField {
        id: pipeTypeTxtF
        x: 103
        y: 520
        text: qsTr("")
    }

    TextField {
        id: pipeDiameterTxtF
        x: 103
        y: 566
        text: qsTr("")
    }

    TextField {
        id: pipeClassTxtF
        x: 103
        y: 612
        text: qsTr("")
    }

    TextField {
        id: pipeThicknessTxtF
        x: 456
        y: 14
        text: qsTr("")
    }

    TextField {
        id: tongArmLenTxtF
        x: 456
        y: 60
        text: qsTr("")
    }

    TextField {
        id: corrFactorTxtF
        x: 456
        y: 106
        text: qsTr("")
    }

    TextField {
        id: delayTimeTxtF
        x: 456
        y: 152
        text: qsTr("")
    }

    TextField {
        id: minStepTxtF
        x: 456
        y: 198
        text: qsTr("")
    }

    TextField {
        id: maxStepTxtF
        x: 456
        y: 244
        text: qsTr("")
    }

    TextField {
        id: maxTorTxtF
        x: 456
        y: 290
        text: qsTr("")
    }

    TextField {
        id: minTorTxtF
        x: 456
        y: 336
        text: qsTr("")
    }

    TextField {
        id: bestTorTxtF
        x: 456
        y: 382
        text: qsTr("")
    }

    TextField {
        id: ctlTorTxtF
        x: 456
        y: 428
        text: qsTr("")
    }

    TextField {
        id: drawTorTxtF
        x: 456
        y: 474
        text: qsTr("")
    }

    TextField {
        id: maxTimeTxtF
        x: 456
        y: 520
        text: qsTr("")
    }

    TextField {
        id: maxCycleTxtF
        x: 456
        y: 566
        text: qsTr("")
    }

    Button {
        id: button1
        x: 240
        y: 658
        width: 200
        height: 40
        text: qsTr("设置参数")
        onClicked: {
            UiLayer.setDeleComp(deleCompTxtF.text.trim())
            UiLayer.setExeComp(exeCompTxtF.text.trim())
            UiLayer.setCollComp(collCompTxtF.text.trim())
            UiLayer.setMachineNo(machineTxtF.text.trim())
            UiLayer.setHydClamp(hydClampTxtF.text.trim())
            UiLayer.setAreaNo(areaNoTxtF.text.trim())
            UiLayer.setWellNo(Number(wellNoTxtF.text.trim()))
            UiLayer.setOwnerSuper(ownerSupTxtF.text.trim())
            UiLayer.setTechDir(techDirTxtF.text.trim());
            UiLayer.setRemark(remarkTxtF.text.trim());
            UiLayer.setPipeName(pipeNameTxtF.text.trim())
            UiLayer.setPipeType(pipeTypeTxtF.text.trim())
            UiLayer.setPipeDiameter(pipeDiameterTxtF.text.trim())
            UiLayer.setPipeClass(pipeClassTxtF.text.trim())
            UiLayer.setPipeThinkness(pipeThicknessTxtF.text.trim())
            UiLayer.setTongArmLen(Number(tongArmLenTxtF.text.trim()))
            UiLayer.setCorrFactor(Number(corrFactorTxtF.text.trim()))
            UiLayer.setDelayTime(Number(delayTimeTxtF.text.trim()))
            UiLayer.setMinStep(Number(minStepTxtF.text.trim()))
            UiLayer.setMaxStep(Number(maxStepTxtF.text.trim()))
            UiLayer.setMaxTor(Number(maxTorTxtF.text.trim()))
            UiLayer.setMinTor(Number(minTorTxtF.text.trim()))
            UiLayer.setBestTor(Number(bestTorTxtF.text.trim()))
            UiLayer.setCtlTor(Number(ctlTorTxtF.text.trim()))
            UiLayer.setDrawTor(Number(drawTorTxtF.text.trim()))
            UiLayer.setMaxTime(Number(maxTimeTxtF.text.trim()))
            UiLayer.setMaxCycle(Number(maxCycleTxtF.text.trim()))
            UiLayer.setDateTime(Date.fromLocaleString(Qt.locale(), dateTimeTxtF.text.trim(), "yyyy-MM-dd hh:mm:ss"))
            UiLayer.setPipeNo(100);
            UiLayer.updateTorSysArg();
            timer.running = true
        }
    }

    Label {
        id: label28
        x: 386
        y: 626
        text: qsTr("dateTime")
    }

    TextField {
        id: dateTimeTxtF
        x: 456
        y: 612
        text: qsTr("")
    }

    function getAndInitUsrData()
    {
        deleCompTxtF.text = UiLayer.getDeleComp();
        exeCompTxtF.text = UiLayer.getExeComp();
        collCompTxtF.text = UiLayer.getCollComp();
        machineTxtF.text = UiLayer.getMachineNo();
        hydClampTxtF.text = UiLayer.getHydClamp();
        areaNoTxtF.text = UiLayer.getAreaNo();
        wellNoTxtF.text = UiLayer.getWellNo();
        ownerSupTxtF.text = UiLayer.getOwnerSuper();
        techDirTxtF.text = UiLayer.getTechDir();
        pipeNameTxtF.text = UiLayer.getPipeName();
        pipeTypeTxtF.text = UiLayer.getPipType();
        pipeDiameterTxtF.text = UiLayer.getPipeDiameter();
        pipeClassTxtF.text = UiLayer.getPipeClass();
        pipeThicknessTxtF.text = UiLayer.getPipeThinkness()

        tongArmLenTxtF.text = UiLayer.getTongArmLen().toString();
        corrFactorTxtF.text = UiLayer.getCorrFactor().toString();
        delayTimeTxtF.text = UiLayer.getDelayTime().toString();
        minStepTxtF.text = UiLayer.getMinStep().toString();
        maxStepTxtF.text = UiLayer.getMaxStep().toString();
        minTorTxtF.text = UiLayer.getMinTor().toString();
        maxTorTxtF.text = UiLayer.getMaxTor().toString();
        bestTorTxtF.text = UiLayer.getBestTor().toString();
        ctlTorTxtF.text = UiLayer.getCtlTor().toString();
        drawTorTxtF.text = UiLayer.getDrawTor().toString();
        maxCycleTxtF.text = UiLayer.getMaxCycle().toString();
        maxTimeTxtF.text = UiLayer.getMaxTime().toString();
        dateTimeTxtF.text = UiLayer.getDateTime().toLocaleString(Qt.locale(), "yyyy-MM-dd hh:mm:ss");

    }
    function checkArgSetting()
    {
        console.log(UiLayer.getDeleComp().trim())
        if (deleCompTxtF.text.trim() === UiLayer.getDeleComp().trim())
        {
            deleCompTxtF.color = "blue"
        }
        if (exeCompTxtF.text.trim() === UiLayer.getExeComp().trim())
        {
            exeCompTxtF.color = "blue"
        }
        if (collCompTxtF.text.trim() === UiLayer.getCollComp().trim())
        {
            collCompTxtF.color = "blue"
        }
        if (machineTxtF.text.trim() === UiLayer.getMachineNo().trim())
        {
            machineTxtF.color = "blue"
        }
        if (hydClampTxtF.text.trim() === UiLayer.getHydClamp().trim())
        {
            hydClampTxtF.color = "blue"
        }
        if (areaNoTxtF.text.trim() === UiLayer.getAreaNo().trim())
        {
            areaNoTxtF.color = "blue"
        }
        if (wellNoTxtF.text.trim() === UiLayer.getWellNo().trim())
        {
            wellNoTxtF.color = "blue"
        }
        if (ownerSupTxtF.text.trim() === UiLayer.getOwnerSuper().trim())
        {
            ownerSupTxtF.color = "blue"
        }
        if (techDirTxtF.text.trim() === UiLayer.getTechDir().trim())
        {
            techDirTxtF.color = "blue"
        }
        if (remarkTxtF.text.trim() === UiLayer.getRemark().trim())
        {
            remarkTxtF.color = "blue"
        }

        if (pipeNameTxtF.text.trim() === UiLayer.getPipeName().trim())
        {
            pipeNameTxtF.color = "blue"
        }
        if (pipeTypeTxtF.text.trim() === UiLayer.getPipType().trim())
        {
            pipeTypeTxtF.color = "blue"
        }
        if (pipeDiameterTxtF.text.trim() === UiLayer.getPipeDiameter().trim())
        {
            pipeDiameterTxtF.color = "blue"
        }
        if (pipeClassTxtF.text.trim() === UiLayer.getPipeClass().trim())
        {
            pipeClassTxtF.color = "blue"
        }
        if (pipeThicknessTxtF.text.trim() === UiLayer.getPipeThinkness().trim())
        {
            pipeThicknessTxtF.color = "blue"
        }
        if (tongArmLenTxtF.text.trim() === UiLayer.getTongArmLen().toString().trim())
        {
            tongArmLenTxtF.color = "blue"
        }
        if (corrFactorTxtF.text.trim() === UiLayer.getCorrFactor().toString().trim())
        {
            corrFactorTxtF.color = "blue"
        }
        if (delayTimeTxtF.text.trim() === UiLayer.getDelayTime().toString().trim())
        {
            delayTimeTxtF.color = "blue"
        }
        if (minStepTxtF.text.trim() === UiLayer.getMinStep().toString().trim())
        {
            minStepTxtF.color = "blue"
        }
        if (maxStepTxtF.text.trim() === UiLayer.getMaxStep().toString().trim())
        {
            maxStepTxtF.color = "blue"
        }
        if (bestTorTxtF.text.trim() === UiLayer.getBestTor().toString().trim())
        {
            bestTorTxtF.color = "blue"
        }
        if (ctlTorTxtF.text.trim() === UiLayer.getCtlTor().toString().trim())
        {
            ctlTorTxtF.color = "blue"
        }
        if (drawTorTxtF.text.trim() === UiLayer.getDrawTor().toString().trim())
        {
            drawTorTxtF.color = "blue"
        }
        if (minTorTxtF.text.trim() === UiLayer.getMinTor().toString().trim())
        {
            minTorTxtF.color = "blue"
        }
        if (maxTorTxtF.text.trim() === UiLayer.getMaxTor().toString().trim())
        {
            maxTorTxtF.color = "blue"
        }
        if (maxTimeTxtF.text.trim() === UiLayer.getMaxTime().toString().trim())
        {
            maxTimeTxtF.color = "blue"
        }
        if (maxCycleTxtF.text.trim() === UiLayer.getMaxCycle().toString().trim())
        {
            maxCycleTxtF.color = "blue"
        }
        console.log(UiLayer.getDateTime().toLocaleString(Qt.locale(), "yyyy-MM-dd hh:mm:ss"))
        if (dateTimeTxtF.text.trim() === UiLayer.getDateTime().toLocaleString(Qt.locale(), "yyyy-MM-dd hh:mm:ss"))
        {
            dateTimeTxtF.color = "blue"
        }

    }

    Timer
    {
        id: timer
        running: false
        repeat: true
        interval: 200
        onTriggered: {
            checkArgSetting();
        }

    }
}
