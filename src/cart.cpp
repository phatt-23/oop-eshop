#include "inc/cart.h"
#include <unordered_map>

#define __dbg_cart__ 1

Cart::Cart(User* u) 
    : m_owner(u), m_total(0)
{
    if(__dbg_cart__) printf(
        "%s Created a cart for user %ld, %s, %s\n",
        NOTE, u->get_id(), u->get_name().c_str(), u->get_email().c_str() 
    );
}

Cart::~Cart() {
    if(__dbg_cart__) printf(
        "%s Deallocated a cart for user %ld, %s, %s\n",
        NOTE, m_owner->get_id(), m_owner->get_name().c_str(), m_owner->get_email().c_str() 
    );
}

void Cart::view(uint8_t x) {
    // for(int i=0; i<x; ++i) printf(" ");
    // printf("-----Cart of user (%ld, %s, %s)-----\n",
    //     m_owner->get_id(), m_owner->get_name().c_str(), m_owner->get_email().c_str()
    // );

    for(auto c : m_content) {
        for(int i=0; i<x; ++i) printf(" ");
        std::cout 
            << "(" 
            << "id: " << c.first->get_id()
            << ", name: " << c.first->get_name()
            << ", price: " << c.first->get_price()
            << ", quantity: " << c.second
            << "),"
            << std::endl;
    }
}

void Cart::add(Product* p, uint32_t q) {
    m_content[p] = q;
    this->update_total();
}

void Cart::remove(Product* p, uint32_t q) {
    auto t = m_content.find(p);
    if(t != m_content.end()) {
        if(t->second >= q) {
            t->second -= q;
        } else {
            m_content.erase(t);
        }
        if(__dbg_cart__) printf(
            "%s Removed %d of %s from cart of user (%ld, %s, %s)\n",
            NOTE, q, p->get_name().c_str(), 
            m_owner->get_id(), m_owner->get_name().c_str(), m_owner->get_email().c_str()
        );
    }
    this->update_total();
}

double Cart::update_total() {
    double sum = 0;
    for(auto c : m_content) {
        sum += c.first->get_price() * c.second;
    }
    m_total = sum;
    return sum;
}

User* Cart::get_owner() {
    return m_owner;
}

double Cart::get_total() {
    return m_total;
}

std::unordered_map<Product*, uint32_t>* Cart::get_content() {
    return &m_content;
}

void Cart::checkout() {
    m_content.clear();
    this->update_total();
}

void Cart::set_total(double total) {
    m_total = total;
}

void Cart::checkout_with_discount(double discount) {
    if(this->m_total >= discount && this->get_owner()->get_points() >= discount) {
        this->m_total -= discount;
        this->get_owner()->set_points(this->get_owner()->get_points() - discount);
    }
    m_content.clear();
    this->update_total();
}
