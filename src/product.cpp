#include "inc/product.h"
#include <pthread.h>

#define PRODUCT_DBG 1

Product::Product(uint64_t i, const std::string& n, double p, int32_t q) 
    : m_id(i), m_name(n), m_price(p), m_quantity(q)
{
    if(PRODUCT_DBG) printf(
        "%s Created a product: name = %s, price = %.2lf, quantity = %d\n", 
        NOTE, m_name.c_str(), m_price, m_quantity
    );
}

Product::~Product() {
    if(PRODUCT_DBG) printf(
        "%s Deallocated a product: name = %s, price = %.2lf, quantity = %d\n", 
        NOTE, m_name.c_str(), m_price, m_quantity
    );
}

uint64_t Product::get_id() {
    return m_id;
}

const std::string& Product::get_name() const {
    return m_name;
}

double Product::get_price() const {
    return m_price;
}

int32_t Product::get_quantity() const {
    return m_quantity;
}

void Product::set_name(const std::string& n) {
    m_name = n;
}

void Product::set_price(double p) {
    m_price = p;
}

void Product::set_quantity(uint32_t q) {
    m_quantity = q;
}

