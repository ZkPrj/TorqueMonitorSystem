#include "model.h"
#include "TstModel.h"

#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QTimer>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

AnimalModel model;

void addItem()
{
   model.addAnimal(Animal(1, 111));
   model.addAnimal(Animal(2, 222));
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    model.addAnimal(Animal(2, 2123));
    model.addAnimal(Animal(3, 34554));
    model.addAnimal(Animal(4, 12354));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myModel", &model);
    engine.rootContext()->setContextProperty("TstModel", new TstModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QTimer::singleShot(10000,addItem);
    return app.exec();
}
