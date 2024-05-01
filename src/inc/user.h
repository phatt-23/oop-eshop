#ifndef __user_h__
#define __user_h__

#include "precompiled.h"

#define _basic_points_factor 0.01

// pure virtual class
class User 
{
protected:
    uint64_t m_id;
    std::string m_name;
    std::string m_email;
    double m_points = 0;

public:
    User(uint64_t i, const std::string& n, const std::string& e);
    ~User();    

    uint64_t get_id() const;
    const std::string& get_name() const;
    const std::string& get_email() const;
    virtual void print() = 0;
    double get_points() const;
    void set_points(double points);
};

#endif//__user_h__
