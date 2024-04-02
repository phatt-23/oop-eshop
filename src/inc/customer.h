#ifndef __customer_h__
#define __customer_h__

#include "precompiled.h"
#include "cart.h"
#include "user.h"
#include "order.h"

class Customer : public User {
    Cart* m_cart;
    std::vector<Product*>* m_catalog_ptr;
    std::vector<Order*> m_orders;

public:
    Customer(uint64_t i, const std::string& n, const std::string& e, std::vector<Product*>* c);
    ~Customer();

    void add_to_cart(Product* p, uint32_t q);
    void add_to_cart(uint64_t i, uint32_t q);
    void remove_from_cart(Product* p, uint32_t q);
    void checkout();
    void orders_print(uint32_t x) const;
    void print();
};

#endif//__customer_h__
