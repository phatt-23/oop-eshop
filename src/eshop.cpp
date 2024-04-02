#include "inc/eshop.h"
#include "inc/customer.h"

#define DBG_ESHOP 1

Eshop::Eshop(const std::string& n) 
    : m_name(n), m_product_count(0)
{
    if(DBG_ESHOP) printf("%s Created an E-shop called %s!\n", NOTE, n.c_str());
}

Eshop::~Eshop() {
    if(DBG_ESHOP) printf("%s Deallocating E-shop %s!\n", NOTE, m_name.c_str()); 
} 

void Eshop::add_customer(Customer* c) {
    m_customers.push_back(c);
}

void Eshop::add_customer(uint64_t i, const std::string& n, const std::string& e) {
    m_customers.push_back(new Customer(i, n, e, &m_catalog));
}

void Eshop::add_product(uint32_t i, const std::string& n, double p, int32_t q) {
    m_catalog.push_back(new Product(i, n, p, q));
    m_product_count++;
}

void Eshop::add_product(Product* p) {
    m_catalog.push_back(p);
}

Customer* Eshop::get_customer(uint32_t i) {
    for(Customer* c : m_customers) {
        if(c->get_id() == i) {
            return c;
        }
    }
    return nullptr;
}

Product* Eshop::get_product(uint32_t i) {
    for(Product* p : m_catalog) {
        if(p->get_id() == i) {
            return p;
        }
    }
    return nullptr;
}


void Eshop::price_increase(double i) {
    for(Product* p : m_catalog) {
        p->set_price(p->get_price() * i);
    }
}

void Eshop::print() {
    printf("---------Eshop---------\n");
    printf("[product] = {\n");
    for(Product* p : m_catalog)  {
        std::cout 
            << "    "
            << "(id: " << p->get_id()
            << ", name: " << p->get_name()
            << ", price: " << p->get_price()
            << ", quantity: " << p->get_quantity()
            << ")," << std::endl;
    }
    printf("}\n");

    printf("[user] = {\n");
    for(Customer* c : m_customers)  {
        std::cout 
            << "    "
            << "(id: " << c->get_id()
            << ", name: " << c->get_name()
            << ", email: " << c->get_email()
            << ")," << std::endl;
    }
    printf("}\n");


    printf("-----------------------\n");
}
