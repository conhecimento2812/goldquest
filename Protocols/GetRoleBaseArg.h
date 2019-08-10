#ifndef GETROLEBASEARG_H
#define GETROLEBASEARG_H

#include <Network/OctetsStream.h>
#include <Utils.h>

class GetRoleBaseArg : public OctetsStream
{
public:
    GetRoleBaseArg(int roleid) : OctetsStream() {
        this->roleid = roleid;
    }
    virtual ~GetRoleBaseArg();

    static const uint opcode = 0xBC5;
    int roleid;

    // OctetsStream interface
public:
    void Unmarshal() override;
    void Marshal() override;

};

#endif // GETROLEBASEARG_H
