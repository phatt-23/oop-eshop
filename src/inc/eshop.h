#ifndef __ESHOP_H
#define __ESHOP_H

#include "precompiled.h"
#include "product.h"
#include "customer.h"


class Eshop {
private:
    std::string m_name;
    std::vector<Product*> m_catalog;
    std::vector<Customer*> m_customers;
    uint32_t m_product_count;

public:
    Eshop(const std::string& n);
    ~Eshop();
    void add_customer(Customer* c);
    void add_customer(uint64_t i, const std::string& n, const std::string& e);
    void add_product(Product* p);
    void add_product(uint32_t i, const std::string& n, double p, int32_t q);

    Customer* get_customer(uint32_t i);
    Product* get_product(uint32_t i);

    void price_increase(double i);
    void print();
};

#endif//__ESHOP_H
