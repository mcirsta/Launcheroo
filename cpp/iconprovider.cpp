#include "iconprovider.hpp"
#include <QFile>
#include <iostream>
#include <QRegularExpression>

QString IconProvider::getIcon(const QString& iconName)
{
    QString iconFullPath;
    QFile iconFile(iconName);
    if(iconFile.exists()) {
        iconFullPath = iconName;
        std::cout<< iconName.toStdString() <<std::endl;
    }
    else {
        const auto info = XdgIconLoader::instance()->loadIcon(iconName);
        if(info.entries.size() > 0) {
            iconFullPath = getBestSizeFormat(info.entries);
        }
        else {
            //TODO error
            std::cout << "Icon not found for :" << iconName.toStdString() << std::endl;
        }
    }
    return iconFullPath;
}

int IconProvider::iconRez(const QString &iconPath)
{
    int rez = -1;
    QRegularExpression iconResExp("\\d+x\\d.");
    int startPos = iconPath.indexOf(iconResExp, 0);
    if(startPos > 0) {
        int endPos = iconPath.indexOf('x', startPos);
        QString resStr = iconPath.mid(startPos, endPos - startPos);
        rez = resStr.toInt();
    }
    return rez;
}

QString IconProvider::getBestSizeFormat(const QThemeIconEntries& icons)
{
    QString bestIcon;
    QRegularExpression svgExt("\\.svg$");
    if(icons.size() > 1) {
        for (const auto &i : icons) {
            if(i->filename.contains(svgExt)) {
                bestIcon = i->filename;
                break;
            }
            else {
                if(iconRez(i->filename) >= iconRez(bestIcon))
                {
                    bestIcon = i->filename;
                }
            }
        }
    }
    else {
        bestIcon = icons[0]->filename;
    }
    std::cout<<"Best icon: "<<bestIcon.toStdString() << std::endl;
    return bestIcon;
}
