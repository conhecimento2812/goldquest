#ifndef SETTINGS_H
#define SETTINGS_H

#include <QVariant>
#include <QFileInfo>
#include <QSettings>

class Settings
{
public:
    static void Init(const QString &file);

    static QString path;
    static QString Z_pF22bgVxJ;
    static QString logs;

    static QString mysql_host;
    static int mysql_port;
    static QString mysql_user;
    static QString mysql_pass;
    static QString mysql_db;

    static QString gamedbd_host;
    static quint16 gamedbd_port;
};

#endif // SETTINGS_H
