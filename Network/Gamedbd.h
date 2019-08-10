#ifndef GAMEDBD_H
#define GAMEDBD_H

#include <QObject>
#include <QTcpSocket>
#include <Utils.h>
#include <Settings.h>

#include <Network/OctetsStream.h>

#include <Models/GRoleBase.h>
#include <Protocols/GetRoleBaseArg.h>
#include <Protocols/GetRoleBaseRes.h>

class Gamedbd : public QObject
{
    Q_OBJECT
public:
    explicit Gamedbd(QObject *parent = nullptr) : QObject(parent) {
        host = Settings::gamedbd_host;
        port = Settings::gamedbd_port;
    }
    ~Gamedbd() { socket->close(); }
    static Gamedbd *Instance();

    void connect();
    QByteArray response();
    GRoleBase getRoleBase(int roleid);

private:
    static Gamedbd *self;
    QTcpSocket *socket;
    QString host;
    quint16 port;
};

#endif // GAMEDBD_H
