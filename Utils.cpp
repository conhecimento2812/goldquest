#include "Utils.h"

QString Utils::toUtf8(Octets octets)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    return codec->fromUnicode(octets.text).mid(0, static_cast<int>(octets.lenght));
}

QString Utils::toASCII(Octets octets)
{
    QTextCodec *codec = QTextCodec::codecForName("ISO 8859-1");
    return codec->fromUnicode(octets.text).mid(0, static_cast<int>(octets.lenght));
}

QByteArray Utils::toUtf16LE(QByteArray text)
{
    QTextCodec *codec_utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec *codec_utf16le = QTextCodec::codecForName("UTF-16LE");
    return codec_utf16le->fromUnicode(codec_utf8->toUnicode(text)).remove(0, 2);
}

Octets Utils::fromUtf8(QByteArray text)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    return Octets(codec->fromUnicode(text.data()));
}

void Utils::print(QString text)
{
    QDateTime date = QDateTime::currentDateTime();
    std::cout << QString("[QuestReward][%1] %2").arg(date.toString("hh:mm:ss")).arg(text).toStdString() << std::endl;
}

QString Utils::getIp(int ip)
{
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;

    return QString("%1.%2.%3.%4").arg(bytes[3]).arg(bytes[2]).arg(bytes[1]).arg(bytes[0]);
}

Octets Utils::emptyOctets()
{
    return Octets();
}

Octets Utils::base64Octets(QString text)
{
    return Octets(QByteArray::fromBase64(text.toStdString().c_str()));
}
