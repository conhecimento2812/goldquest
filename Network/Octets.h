#ifndef OCTETS_H
#define OCTETS_H

#include <QObject>

struct Octets
{
    Octets() {}
    Octets(QByteArray data) : text(data) { lenght = static_cast<uint>(text.length()); }
    uint lenght = 0;
    QByteArray text;
};

#endif // OCTETS_H
