#include "GetRoleBaseArg.h"

GetRoleBaseArg::~GetRoleBaseArg()
{
    Reset();
}

void GetRoleBaseArg::Unmarshal()
{

}

void GetRoleBaseArg::Marshal()
{
    Reset();
    this->operator<<(-1);
    this->operator<<(roleid);
}
