#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QPointer>
#include <QQmlApplicationEngine>
#include <QString>

class Platform : public QObject
{
    Q_OBJECT

public slots:

        // get application list from java and convert to QVariantList format that can be used directly in QML
        QVariantList applicationList();

        // launch application by package name
        void launchApplication(const QString &packageName);

        // open wallpaper picker menu
        void pickWallpaper();

        // return if system clock is in 24 hour format
        bool is24HourFormat();

public:

    // singleton, so we can propagate notifications from java
    static Platform &instance()
    {
        static Platform platform;
        return platform;
    }

signals:
    // signal when packages have changed (installed/uninstalled)
    void packagesChanged();

private:
    const QString desktopFilesPath = "/usr/share/applications";
};

#endif // PLATFORM_H
