#ifndef __product_h__
#define __product_h__

#include "precompiled.h"

class Product {
    uint64_t m_id;
    std::string m_name;
    double m_price;
    int32_t m_quantity;

public:
    Product(uint64_t i, const std::string& n, double p, int32_t q);
    ~Product();

    uint64_t get_id();
    const std::string& get_name() const;
    double get_price() const;
    int32_t get_quantity() const;

    void set_name(const std::string& n);
    void set_price(double p);
    void set_quantity(uint32_t);
};

#endif//__product_h__
