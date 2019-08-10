#include "Settings.h"

QString Settings::path = "";
QString Settings::Z_pF22bgVxJ = "";
QString Settings::logs = "/home/logs/world2.formatlog";

QString Settings::mysql_host = "";
int Settings::mysql_port = 0;
QString Settings::mysql_user = "";
QString Settings::mysql_pass = "";
QString Settings::mysql_db = "";

QString Settings::gamedbd_host = "127.0.0.1";
quint16 Settings::gamedbd_port = 29400;

void Settings::Init(const QString &file)
{
    QSettings settings(file + "/questreward.conf", QSettings::IniFormat);

    path    = file;
    Z_pF22bgVxJ = settings.value("questreward/license").toString();
    logs    = settings.value("questreward/formatlog").toString();

    mysql_host = settings.value("mysql/host").toString();
    mysql_port = settings.value("mysql/port").toInt();
    mysql_user = settings.value("mysql/user").toString();
    mysql_pass = settings.value("mysql/pass").toString();
    mysql_db   = settings.value("mysql/db").toString();

    gamedbd_host = settings.value("Gamedbd/host").toString();
    gamedbd_port = static_cast<quint16>(settings.value("Gamedbd/port").toInt());
}
