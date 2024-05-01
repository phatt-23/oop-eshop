#include "inc/eshop.h"
#include "inc/product.h"

int main() {
    // creating the eshop with some specified name
    Eshop e("xXxEshopxXx");

    // create some of the products beforehand
    std::vector<Product*> products =  {
        new Product(2000, "triko", 7, 40),
        new Product(2001, "fidget spinner", 30, 100),
        new Product(2002, "poppy horror toy", 0, 200),
        new Product(2003, "yeezy boty", 7000, 10),
    };

    // add products into the eshop - overloaded method add_product
    for(auto p : products)
        e.add_product(p);

    e.add_product(2003, "yeezy boty",               7000, 10);
    e.add_product(2004, "maga hat",                 300,  200);
    e.add_product(2005, "nail polish",              200,  400);
    e.add_product(2006, "kinder hippo",             17,   300);
    e.add_product(2007, "papiry na hledani boha",   500,  3000);
    e.add_product(2008, "kradene kabelky",          200,  100);
    e.add_product(2009, "prezencka na predmet STD", 10,   INF);

    // create customers beforehand - overloaded method add_customer
    std::vector<Customer*> customers = {
        new Customer(1000, "phatt-23", "phatt-23@gmail.com", e.get_catalog()),
        new Customer(1001, "Jan Novak", "jan.novak@seznam.cz", e.get_catalog()),
    };

    // add customers into the shop
    for(auto c : customers)
        e.add_customer(c);

    e.add_customer(1004, "Gabriel Clarkson", "gab.clark@post.cz");
    e.add_customer(1006, "Emilio Reynolds",  "emi.rey@belamiboys.com");
    
    // add some items into some cusotmers cart 
    e.get_customer(1004)->add_to_cart(e.get_product(2005), 200000);
    e.get_customer(1004)->add_to_cart(e.get_product(2001), 30);
    e.get_customer(1004)->add_to_cart(2002, 10);
    e.get_customer(1004)->add_to_cart(2009, 100);
    

    // print out the customer after adding items
    e.get_customer(1004)->print();
    
    // print out current state of the eshop
    e.print();

    // checkout the customer
    e.get_customer(1004)->checkout();
    
    // print out how the state of the customer looks like after checkout
    e.get_customer(1004)->print();

    // print out state of the eshop after the customer's checkout
    e.print();

    // increase the prices by 10% -> 110%
    e.price_increase(1.10);

    // print out the current state of the eshop
    e.print();

    // print out the customer - his history stays unchanged
    e.get_customer(1004)->print();

    // ship and deliver customers order
    e.get_customer(1004)->get_orders().front()->update_status();
    e.get_customer(1004)->print();

    e.get_customer(1004)->get_orders().front()->update_status();
    e.get_customer(1004)->print();
    
    // add premium customer
    e.add_premium_customer(1007, "Jmeno Prijmeni", "jmeno.prijmeni@gmail.com", 300);
    e.get_customer(1007)->add_to_cart(e.get_product(2002), 12);
    e.get_customer(1007)->add_to_cart(e.get_product(2004), 43);
    e.get_customer(1007)->add_to_cart(2006, 56);
    e.get_customer(1007)->add_to_cart(2003, 43);

    // this will call the overrided method print
    e.get_customer(1007)->print();

    // checkout with a discount
    e.get_customer(1007)->checkout(200);

    // print out the premium customer
    e.get_customer(1007)->print();


    return 0;
}
