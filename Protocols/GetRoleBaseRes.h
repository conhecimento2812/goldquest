#ifndef GETROLEBASERES_H
#define GETROLEBASERES_H

#include <Network/OctetsStream.h>
#include <Models/GRoleBase.h>

class GetRoleBaseRes : public OctetsStream
{
public:
    GetRoleBaseRes() : OctetsStream() {}
    virtual ~GetRoleBaseRes() { Reset(); }

    int always;
    int retcode;
    GRoleBase body;

    // OctetsStream interface
public:
    void Unmarshal() override;
    void Marshal() override;
};

#endif // GETROLEBASERES_H
