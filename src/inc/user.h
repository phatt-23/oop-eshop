#ifndef __user_h__
#define __user_h__

#include "precompiled.h"

class User {
protected:
    uint64_t m_id;
    std::string m_name;
    std::string m_email;

public:
    User(uint64_t i, const std::string& n, const std::string& e);
    ~User();    

    uint64_t get_id() const;
    const std::string& get_name() const;
    const std::string& get_email() const;
};

#endif//__user_h__
