#include "GetRoleBaseRes.h"

void GetRoleBaseRes::Unmarshal()
{
    this->operator>>(always);
    this->operator>>(retcode);
    this->operator>>(body.version);
    this->operator>>(body.id);
    this->operator>>(body.name);
    this->operator>>(body.race);
    this->operator>>(body.cls);
    this->operator>>(body.gender);
    this->operator>>(body.custom_data);
    this->operator>>(body.config_data);
    this->operator>>(body.custom_stamp);
    this->operator>>(body.status);
    this->operator>>(body.delete_time);
    this->operator>>(body.create_time);
    this->operator>>(body.lastlogin_time);

    uint forbid_size = this->uncompact_uint32();
    for(uint i = 0; i < forbid_size; i++) {
        GRoleForbid forbid;
        this->operator>>(forbid.type);
        this->operator>>(forbid.time);
        this->operator>>(forbid.createtime);
        this->operator>>(forbid.reason);
        body.forbid.push_back(forbid);
    }

    this->operator>>(body.help_states);
    this->operator>>(body.spouse);
    this->operator>>(body.userid);

}

void GetRoleBaseRes::Marshal()
{

}
