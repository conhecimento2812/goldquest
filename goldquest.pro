QT += core network sql
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Database/MySQL.cpp \
        Network/Gamedbd.cpp \
        Network/OctetsStream.cpp \
        Protocols/GetRoleBaseArg.cpp \
        Protocols/GetRoleBaseRes.cpp \
        Server.cpp \
        Settings.cpp \
        Threads/Thread.cpp \
        Utils.cpp \
        Workers/Worker.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Database/MySQL.h \
    Models/GRoleBase.h \
    Models/GRoleForbid.h \
    Models/Quest.h \
    Network/Gamedbd.h \
    Network/Octets.h \
    Network/OctetsStream.h \
    Protocols/GetRoleBaseArg.h \
    Protocols/GetRoleBaseRes.h \
    Server.h \
    Settings.h \
    Threads/Thread.h \
    Utils.h \
    Workers/Worker.h
