#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MissionProcLayer/MissionCore.h"
#include "UiLayer/TorSysUiLayer.h"
#include <QThread>
#include <QDebug>
#include <QtQml>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

//    MissionCore mission;
//    bool ret = false;
//    ret = mission.getLowerConnStatus();


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("UiLayer", new TorSysUiLayer);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
