#include <QImage>
#include <QDir>
#include <QSettings>
#include <QDebug>
#include <iostream>
#include <QFile>
#include <QProcess>

#include "platform.h"
#include <private/xdgiconloader/xdgiconloader_p.h>



// get application list from java and convert to QVariantList format that can be used directly in QML
QVariantList Platform::applicationList()
{
    QVariantList appList;

    QDir appsDir(this->desktopFilesPath);
    QStringList appsFileFiler;
    appsFileFiler << "*.desktop";
    QStringList desktopFileList = appsDir.entryList(appsFileFiler, QDir::Filter::Files, QDir::SortFlag::Name|QDir::IgnoreCase);
    for(const auto& desktopFile : desktopFileList)
    {
        QString fullPath = this->desktopFilesPath + "/" + desktopFile;
        QSettings desktopSetting(fullPath, QSettings::IniFormat);
        desktopSetting.beginGroup("Desktop Entry");
        QString appTerminal = desktopSetting.value("Terminal", "false").toString();
        QString appNoDisplay = desktopSetting.value("NoDisplay", "false").toString();
        QVariant iconFullPath = "";
        //ignore app that don't support GUI
        auto appIcon = desktopSetting.value("Icon", "NO_ICON_FOUND");
        if(appTerminal != "true" && appNoDisplay != "true" && appIcon != "NO_ICON_FOUND") {
            auto appName = desktopSetting.value("Name");
            QString appExec = desktopSetting.value("Exec").toString();

            appExec.remove("%U");
            appExec.remove("%u");


            QFile iconFile(appIcon.toString());
            if(iconFile.exists()) {
                iconFullPath = appIcon;
                std::cout<< appIcon.toString().toStdString() <<std::endl;
            }
            else {
                const auto info = XdgIconLoader::instance()->loadIcon(appIcon.toString());
                const auto entries = info.entries;
                for (const auto &i : entries) {
                    std::cout << "\t" << qPrintable(i->filename) << "\n";
                    iconFullPath = i->filename;
                }
            }
            QVariantMap data;
            data["appName"] = appName;
            data["fullPath"] = fullPath;
            data["appExec"] = appExec;
            data["iconFullPath"] = iconFullPath;
            data["appIcon"] = appIcon;
            appList.append(data);
        }
        else {
            //std::cout<< desktopFile.toStdString() <<std::endl;
        }
    }

    return appList;
}

// launch application by package name
void Platform::launchApplication(const QString &packageName)
{
    QProcess launchApp(this);
    std::cout<< packageName.toStdString() << std::endl;
    launchApp.startDetached(packageName);
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
