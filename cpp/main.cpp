#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "platform.h"
#include "xdgiconloader_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // expose C++ classes to QML
    engine.addImageProvider(QLatin1String("icon"), new ImageProvider());
    engine.rootContext()->setContextProperty("__platform", &Platform::instance());

    // load main file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
