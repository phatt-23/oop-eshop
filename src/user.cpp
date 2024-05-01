#include "inc/user.h"

User::User(uint64_t i, const std::string& n, const std::string& e) 
    : m_id(i), m_name(n), m_email(e), m_points(0)
{
    
}

User::~User() = default;


uint64_t User::get_id() const {
    return m_id;
}

const std::string& User::get_name() const {
    return m_name;
}

const std::string& User::get_email() const {
    return m_email;
}

double User::get_points() const {
    return m_points;
}

void User::set_points(double points) {
    m_points = points;
}
