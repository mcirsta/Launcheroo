#ifndef ICONPROVIDER_HPP
#define ICONPROVIDER_HPP

#include <QString>
#include <private/xdgiconloader/xdgiconloader_p.h>

class IconProvider
{
public:
    static QString getIcon(const QString& iconName);
private:
    static QString getBestSizeFormat(const QThemeIconEntries& icons);
    static int iconRez(const QString& iconPath);
};

#endif // ICONPROVIDER_HPP
