#ifndef __customer_h__
#define __customer_h__

#include "precompiled.h"
#include "cart.h"
#include "user.h"
#include "order.h"

class Customer : public User {
protected:
    Cart* m_cart;
    const std::vector<Product*>* m_catalog_ptr;
    std::vector<Order*> m_orders;

public:
    Customer(uint64_t id, const std::string& name, const std::string& email, const std::vector<Product*>* cart);
    virtual ~Customer();

    void add_to_cart(Product* product, uint32_t quantity);
    void add_to_cart(uint64_t product_id, uint32_t quantity);
    void remove_from_cart(Product* product, uint32_t quantity);
    void checkout();
    void checkout(double discount);
    void orders_print(uint32_t x) const;
    void print() override;
    const std::vector<Product*>* get_catalog() const;
    std::vector<Order*> get_orders(); 
    virtual void add_points();
};

#endif//__customer_h__
