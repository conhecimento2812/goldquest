#include "MySQL.h"

MySQL* MySQL::self = nullptr;

void MySQL::connect()
{
    mysql = QSqlDatabase::addDatabase("QMYSQL", "mysql");
    mysql.setHostName(Settings::mysql_host);
    mysql.setPort(Settings::mysql_port);
    mysql.setUserName(Settings::mysql_user);
    mysql.setPassword(Settings::mysql_pass);
    mysql.setDatabaseName(Settings::mysql_db);
    mysql.setConnectOptions("MYSQL_OPT_RECONNECT=1;MYSQL_OPT_CONNECT_TIMEOUT=300");
    if (!mysql.open()) {
        Utils::print(QString("Error occurred opening the mysql"));
        Utils::print(mysql.lastError().text());
        exit(EXIT_FAILURE);
    }

    Utils::print("Successfully connected to database");
}

int MySQL::useCash(const int &userid, const int &zoneid, const int &sn, const int &aid, const int &point, const int &cash, const int &status)
{
    QSqlQuery sql(mysql);
    sql.prepare("CALL usecash(?, ?, ?, ?, ?, ?, ?, @out1)");
    sql.addBindValue(userid);
    sql.addBindValue(zoneid);
    sql.addBindValue(sn);
    sql.addBindValue(aid);
    sql.addBindValue(point);
    sql.addBindValue(cash);
    sql.addBindValue(status);
    sql.exec();
    sql.exec("SELECT @out1");
    sql.next();

    return sql.value(0).toInt();
}
