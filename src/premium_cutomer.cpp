#include "inc/premium_customer.h"

#define _monthly_fee 300
#define __dbg_premium_customer__ true

#define _premium_points_factor 0.1

PremiumCustomer::PremiumCustomer(uint64_t i, const std::string& n, const std::string& e, const std::vector<Product*>* c, double p)
: Customer(i, n, e, c), m_monthly_fee(_monthly_fee)
{
    m_points = p;
    if(__dbg_premium_customer__) printf(
        "%s Allocated a premium customer (%ld, %s, %s)\n", 
        NOTE, i, n.c_str(), e.c_str()
    );
}

PremiumCustomer::PremiumCustomer(Customer* bc, double points)
: Customer(bc->get_id(), bc->get_name(), bc->get_email(), bc->get_catalog())
{
    m_points = points;
}
        
PremiumCustomer::~PremiumCustomer()
{
    if(__dbg_premium_customer__) printf(
        "%s Deallocated a premium customer (%ld, %s, %s)\n", 
        NOTE, m_id, m_name.c_str(), m_email.c_str()
    );
}

void PremiumCustomer::set_montly_fee(double mf)
{
    m_monthly_fee = mf;
}

double PremiumCustomer::get_montly_fee() const
{
    return m_monthly_fee;
}

void PremiumCustomer::print()
{
    printf("-----premium customer print-----\n");
    std::cout
        << "- id: " << m_id << std::endl
        << "- username: " << m_name << std::endl
        << "- email: " << m_email << std::endl
        << "- points: " << m_points << std::endl
        << "- monthly fee: " << m_monthly_fee << std::endl
        << "- cart = {" << std::endl;
    m_cart->view(4);
    std::cout 
        << "}" << std::endl
        << std::fixed << std::setprecision(2)
        << "- cart total: " << m_cart->get_total() << std::endl
        << "- orders = {" << std::endl;
    this->orders_print(4);
    std::cout << "}" << std::endl
        << std::endl;
    printf("------------------------\n");
}

void PremiumCustomer::add_points() {
    this->set_points(this->get_points() + _premium_points_factor * m_cart->get_total());
}
