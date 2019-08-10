#include "Gamedbd.h"

Gamedbd *Gamedbd::self = nullptr;

Gamedbd *Gamedbd::Instance()
{
    if(!self)
        self = new Gamedbd();
    return self;
}

void Gamedbd::connect()
{
    socket = new QTcpSocket();
    socket->connectToHost(host, port);
    if (!socket->waitForConnected(3000)) {
        Utils::print(QString("Failed connect gamedbd: %1:%2").arg(host).arg(port));
        exit(EXIT_FAILURE);
    }
}

QByteArray Gamedbd::response()
{
    socket->waitForBytesWritten(1000);
    socket->waitForReadyRead(3000);

    return socket->readAll();
}

GRoleBase Gamedbd::getRoleBase(int roleid)
{
    GetRoleBaseArg rolebase(roleid);
    rolebase.socket = socket;
    rolebase.Marshal();
    rolebase.Send(rolebase.opcode);

    GetRoleBaseRes res;
    res.setData(response());
    res.Unmarshal();

    return res.body;
}
