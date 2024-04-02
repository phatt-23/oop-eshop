#include "inc/order.h"

Order::Order(uint64_t i, User* u, std::unordered_map<Product*, uint32_t>* ix, double t) 
    : m_id(i), m_user(u), m_items(std::move(*ix)), m_total(t)
{
    
}

Order::~Order() {
    
}

void Order::update_status() {
    switch(m_status) {
        case OrderStatus::Processing: 
            m_status = OrderStatus::Shipped;
            break;
        case OrderStatus::Shipped:
            m_status = OrderStatus::Delivered;
            break;
        default:
            printf("The order (id: %ld) is already delivered!\n", m_id);
            break;
    }
}

void Order::update_status(OrderStatus s) {
    m_status = s;
}

OrderStatus Order::get_status() const {
    return m_status;
}

void Order::print(uint32_t x) const {
    for(int i=0; i<x; ++i) printf(" ");
    printf(
        "(order | id: %ld) = { // user-id: %ld, total: %.2lf, status: ", 
        m_id, m_user->get_id(), m_total
    );
    switch(m_status) {
        case OrderStatus::Processing:
            printf("processing");
            break;
        case OrderStatus::Shipped:
            printf("shipped");
            break;
        case OrderStatus::Delivered:
            printf("delivered");
            break;
        default: break;
    }
    printf(" //\n");

    for(auto i : m_items) {
        for(int i=0; i<x + 4; ++i) printf(" ");
        std::cout
            << "(" 
            << "id: " << i.first->get_id()
            << ", name: " << i.first->get_name()
            << ", price: " << i.first->get_price()
            << ", quantity: " << i.second
            << "),"
            << std::endl; 
    }
    for(int i=0; i<x; ++i) printf(" ");
    printf("},\n");
}


