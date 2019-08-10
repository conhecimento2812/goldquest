#ifndef GROLEFORBID_H
#define GROLEFORBID_H

#include <Network/Octets.h>

struct GRoleForbid
{
    char type;
    int time;
    int createtime;
    Octets reason;
};

#endif // GROLEFORBID_H
