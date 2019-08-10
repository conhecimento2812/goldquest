#ifndef WORKER_H
#define WORKER_H

#include <QIODevice>
#include <QObject>
#include <QThread>
#include <QRegExp>
#include <QFile>
#include <QList>

#include <Settings.h>
#include <Utils.h>

#include <Models/GRoleBase.h>
#include <Models/Quest.h>

#include <Network/Gamedbd.h>
#include <Database/MySQL.h>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();

private:
    void Init();
    void LoadQuests();
    int ValidQuest(int questid);

    QFile *formatlog;
    QFile *questlist;
    QList<Quest> quests;
    Gamedbd *gamedbd;
    MySQL *mysql;
};

#endif // WORKER_H
