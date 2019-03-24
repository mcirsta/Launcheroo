#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "platform.hpp"
#include <private/qiconloader_p.h>


int main(int argc, char *argv[])
{
    QIconLoader::instance()->setThemeName("breeze");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // expose C++ classes to QML
    engine.rootContext()->setContextProperty("__platform", &Platform::instance());

    // load main file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
