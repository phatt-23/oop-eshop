#include "inc/customer.h"
#include <iomanip>

#define __dbg_customer__ 1

Customer::Customer(uint64_t i, const std::string& n, const std::string& e, std::vector<Product*>* c) 
    : User(i, n, e), m_cart(new Cart(this)), m_catalog_ptr(c)
{
    if(__dbg_customer__) printf(
        "%s Allocated a customer (%ld, %s, %s)\n", 
        NOTE, i, n.c_str(), e.c_str()
    );
}

Customer::~Customer() {
    if(__dbg_customer__) printf(
        "%s Deallocated a customer (%ld, %s, %s)\n", 
        NOTE, m_id, m_name.c_str(), m_email.c_str()
    );
}

void Customer::add_to_cart(Product* p, uint32_t q) {
    m_cart->add(p, q);
    m_cart->update_total();
}

void Customer::add_to_cart(uint64_t i, uint32_t q) {
    for(auto p : *m_catalog_ptr) {
        if(p->get_id() == i) {
            if(p->get_quantity() >= q)
                m_cart->add(p, q);
            else {
                m_cart->add(p, p->get_quantity());
                std::cout 
                    << NOTE 
                    << "Added only " << p->get_quantity()
                    << "instead of " << q
                    << "because there is only this amount available."
                    << std::endl;
            }
        }
    }
    m_cart->update_total();
}

void Customer::remove_from_cart(Product* p, uint32_t q) {
    m_cart->remove(p, q);
}

void Customer::checkout() {
    for(size_t j=0; j < m_catalog_ptr->size(); ++j) {
        Product* t = m_catalog_ptr->at(j);
        for(auto i : *m_cart->get_content()) {
            if(t == i.first) {
                if(t->get_quantity() >= int(i.second)) 
                    t->set_quantity(t->get_quantity() - i.second);
                else if(t->get_quantity() != INF) {
                    std::cout 
                        << NOTE
                        << "Checked out only with " << t->get_quantity()
                        << " because this is all that's available."
                        << std::endl;
                    m_cart->get_content()->find(i.first)->second = t->get_quantity();
                    t->set_quantity(0);
                }
            }
        }
    }
    m_cart->update_total();
    m_orders.emplace_back(new Order(m_id*1000 + m_orders.size(), this, m_cart->get_content(),m_cart->get_total()));
    m_cart->checkout();
}

void Customer::orders_print(uint32_t x) const {
    for(Order* o : m_orders) {
        o->print(x);
    }
}

void Customer::print() {
    printf("-----customer print-----\n");
    std::cout
        << "- id: " << m_id << std::endl
        << "- username: " << m_name << std::endl
        << "- email: " << m_email << std::endl
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
