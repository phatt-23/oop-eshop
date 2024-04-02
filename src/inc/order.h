#ifndef __order_h__
#define __order_h__

#include "precompiled.h"
#include "user.h"
#include "product.h"

enum OrderStatus {
    Processing,
    Shipped,
    Delivered,
};

class Order {
    uint64_t m_id;
    User* m_user;
    OrderStatus m_status;
    std::unordered_map<Product*, uint32_t> m_items;
    double m_total;

public:
    Order(uint64_t i, User* u, std::unordered_map<Product*, uint32_t>* ix, double t);
    ~Order();
    void update_status(OrderStatus s);
    void update_status();
    OrderStatus get_status() const;
    void print(uint32_t x) const;
};

#endif//__order_h__
