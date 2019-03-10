#include <QImage>

#include "platform.h"


// get application list from java and convert to QVariantList format that can be used directly in QML
QVariantList Platform::applicationList()
{
    QVariantList appList;

    return appList;
}

// launch application by package name
void Platform::launchApplication(const QString &packageName)
{
    Q_UNUSED(packageName);
}

// open wallpaper picker menu
void Platform::pickWallpaper()
{
}

// return if system clock is in 24 hour format
bool Platform::is24HourFormat()
{
    return true;
}
