#include "Worker.h"

Worker::Worker()
{
    formatlog = new QFile(Settings::logs);
    if (!formatlog->open(QIODevice::ReadOnly)) {
        Utils::print(QString("Cold not read file %1").arg(Settings::logs));
        exit(EXIT_FAILURE);
    }

    mysql = new MySQL();
    mysql->connect();

    gamedbd = new Gamedbd();
    gamedbd->connect();

    LoadQuests();
    Init();
}

void Worker::Init()
{
    for(;;) {
        QString line = formatlog->readLine().trimmed();
        if (line == nullptr || line == "") {
            QThread::sleep(1);
            continue;
        }

        QRegExp regex("(\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2})(.*)formatlog:task:roleid=(\\d+):taskid=(\\d+):type=(\\d+):msg=DeliverByAwardData: success = 1");
        if(line.indexOf(regex) > -1) {
            regex.indexIn(line, 0);

            QString date = regex.cap(1);
            int roleid = regex.cap(3).toInt();
            int questid = regex.cap(4).toInt();

            int questindex = ValidQuest(questid);

            if(questindex != -1) {
                GRoleBase rolebase = gamedbd->getRoleBase(roleid);
                mysql->useCash(rolebase.userid, 1, 0, 1, 0, quests[questindex].cash * 100, 1);

                Utils::print(QString("Date: %1 Roleid:%2 Userid: %5 Cash:%3 Quest:%4").arg(date).arg(roleid).arg(quests[questindex].cash).arg(quests[questindex].name).arg(rolebase.userid));
            }
        }
    }
}

void Worker::LoadQuests()
{
    questlist = new QFile(Settings::path + "/quests.list");
    if(!questlist->open(QIODevice::ReadOnly)) {
        Utils::print(QString("Cold not read file %1").arg("quests.list"));
        exit(EXIT_FAILURE);
    }

    while(!questlist->atEnd()) {
        QString line = questlist->readLine().trimmed();
        QRegExp regex("(\\d+),(\\d+),(.*)");
        if(line.indexOf(regex) > -1) {
            regex.indexIn(line, 0);

            Quest quest;
            quest.id = regex.cap(1).toInt();
            quest.cash = regex.cap(2).toInt();
            quest.name = regex.cap(3);

            quests.push_back(quest);
        }
    }

    Utils::print(QString("%1 quests loaded...").arg(quests.length()));
}

int Worker::ValidQuest(int questid)
{
    for(int i = 0; i < quests.length(); i++) {
        if(quests[i].id == questid) return i;
    }

    return -1;
}
