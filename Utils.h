#ifndef UTILS_H
#define UTILS_H

#include <QTextCodec>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include <Network/Octets.h>
#include <iostream>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <winsock2.h>
#else
    #include <arpa/inet.h>
#endif

class Utils
{
public:
    static QString toUtf8(Octets octets);
    static QString toASCII(Octets octets);
    static QByteArray toUtf16LE(QByteArray text);
    static Octets fromUtf8(QByteArray text);
    static void print(QString text);
    static QString getIp(int ip);
    static Octets emptyOctets();
    static Octets base64Octets(QString text);
};

#endif // UTILS_H
