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
    Order(uint64_t id, User* user, std::unordered_map<Product*, uint32_t>* items, double total);
    ~Order();

    // updates the status to a specific status
    void update_status(OrderStatus new_status);
    
    // updates the status by one step
    void update_status();

    // gets its current OrderStatus
    OrderStatus get_status() const;

    // prints out the order - items, status
    void print(uint32_t indent_size) const;
};

#endif//__order_h__
