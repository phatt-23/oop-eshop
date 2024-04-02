#ifndef __cart_h__
#define __cart_h__

#include "precompiled.h"
#include "product.h"
#include "user.h"

class Cart {
    User* m_owner;
    std::unordered_map<Product*, uint32_t> m_content;
    double m_total;

public:
    Cart(User* u);
    ~Cart();

    void view(uint8_t x);
    void add(Product* p, uint32_t q);
    void remove(Product* p, uint32_t q);
    double update_total();
    User* get_owner();
    double get_total();
    std::unordered_map<Product*, uint32_t>* get_content();
    void checkout();
};

#endif//__cart_h__
