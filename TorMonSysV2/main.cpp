#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Comm/GlobalData.h"
#include "Mission/TorMonitorCore.h"
#include "DspInter/TorMonitorUi.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("torMonitorUi", new TorMonitorUi);
    engine.load(QUrl(QLatin1String("qrc:/UI/main.qml")));

    return app.exec();
}
