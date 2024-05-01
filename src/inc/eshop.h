#ifndef __ESHOP_H
#define __ESHOP_H

#include "precompiled.h"
#include "product.h"
#include "customer.h"
#include "premium_customer.h"


class Eshop {
private:
    std::string m_name;
    std::vector<Product*> m_catalog;
    std::vector<Customer*> m_customers;
    uint32_t m_product_count;

public:
    // Initialise the e-shop. Pass in the name of your e-shop.
    Eshop(const std::string& name);

    // Deconstructor.
    ~Eshop();

    // Add a product by passing in the Customer.
    void add_customer(Customer* customer);
    
    // Add a product by constructing the Customer.
    void add_customer(uint64_t id, const std::string& name, const std::string& email);
    
    // Add a premium customer.
    void add_premium_customer(uint64_t i, const std::string& n, const std::string& e, double points);

    void add_premium_customer(Customer* basic_customer, double points);

    // Add a product by passing in the Product.
    void add_product(Product& product);
    
    // Add a product by passing in the Product.
    void add_product(Product* product);

    // Add a product by constructing the Product.
    void add_product(uint32_t id, const std::string& name, double price, int32_t quantity);

    // Get a customer by searching by its ID.
    Customer* get_customer(uint32_t id);

    // Get a product by searching by its ID.
    Product* get_product(uint32_t id);

    // Get the pointer to the catalog
    std::vector<Product*>* get_catalog();

    // Increase the prices by a percentage where 0 = 0% and 1 = 100%.
    void price_increase(double increase_by);

    // Prints out the current state of the e-shop.
    void print();
};

#endif//__ESHOP_H
