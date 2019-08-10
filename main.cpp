#include <QCoreApplication>

#include <Settings.h>
#include <Utils.h>

#include <Threads/Thread.h>
#include <Server.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Utils::print("QuestReward - Discord: Conhecimento#2812 | v0.1.0");
    Utils::print(QString("Build date: %1 at %2").arg(__DATE__).arg(__TIME__));

    Settings::Init(a.applicationDirPath());

    Server server;

    Thread t;
    t.start();


    return a.exec();
}
