#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

#include <Workers/Worker.h>

class Thread : public QThread
{
    Q_OBJECT
public:
    void run();
};

#endif // THREAD_H
