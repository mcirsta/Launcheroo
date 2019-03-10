#include "iconprovider.h"

#include <QDebug>

ImageProvider::ImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
}
QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);

    return getApplicationIcon(id);
}

QImage ImageProvider::getApplicationIcon(const QString &packageName)
{
    QImage image;

    Q_UNUSED(packageName);
    image = QImage("://icon/application.png");

    return image;
}
