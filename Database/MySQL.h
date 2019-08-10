#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include <iostream>

#include <Settings.h>
#include <Utils.h>

class MySQL : public QObject
{
    Q_OBJECT
public:
    explicit MySQL(QObject *parent = nullptr)  : QObject(parent) {}
    ~MySQL() { mysql.close(); }
    void connect();

    int useCash(const int &userid, const int &zoneid, const int &sn, const int &aid, const int &point, const int &cash, const int &status);
    static MySQL *Instance()
    {
        if (!self)
            self = new MySQL();
        return self;
    }
    static MySQL *self;

private:
    QSqlDatabase mysql;
};

#endif // DATABASE_H
