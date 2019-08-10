#ifndef GROLEBASE_H
#define GROLEBASE_H

#include <QVector>
#include <Network/Octets.h>
#include <Models/GRoleForbid.h>

struct GRoleBase
{
    char version;
    int id;
    Octets name;
    int race;
    int cls;
    char gender;
    Octets custom_data;
    Octets config_data;
    int custom_stamp;
    char status;
    int delete_time;
    int create_time;
    int lastlogin_time;
    QVector<GRoleForbid> forbid;
    Octets help_states;
    int spouse;
    int userid;
};

#endif // GROLEBASE_H
