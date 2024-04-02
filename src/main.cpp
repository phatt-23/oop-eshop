#include "inc/eshop.h"
#include "inc/product.h"

int main() {
    Eshop e("xXxEshopxXx");
    e.add_product(2000, "triko", 7, 40);
    e.add_product(2001, "fidget spinner", 30, 100);
    e.add_product(2002, "poppy horror toy", 20, 200);
    e.add_product(2003, "yeezy boty", 7000, 10);
    e.add_product(2004, "maga hat", 300, 200);
    e.add_product(2005, "nail polish", 200, 400);
    e.add_product(2006, "kinder hippo", 17, 300);
    e.add_product(2007, "papiry na hledani boha", 500, 3000);
    e.add_product(2008, "kradene kabelky", 200, 100);
    e.add_product(2009, "prezencka na predmet STD", 10, INF);

    e.add_customer(1000, "phatt-23", "phatt-23@gmail.com");
    e.add_customer(1001, "Jan Novak", "jan.novak@seznam.cz");
    e.add_customer(1002, "Radoslav Fasuga", "rado.faso@seznam.cz");
    e.add_customer(1003, "Marek Menšík", "marek.mensik@gmail.com");
    e.add_customer(1004, "Gabriel Clarkson", "gab.clark@post.cz");
    e.add_customer(1005, "yzomandias", "yzo.bracho@rapper.cz");
    e.add_customer(1006, "Emilio Reynolds", "emi.rey@belamiboys.com");

    e.get_customer(1004)->add_to_cart(e.get_product(2005), 200000);
    e.get_customer(1004)->add_to_cart(e.get_product(2001), 30);
    e.get_customer(1004)->add_to_cart(2002, 10);
    e.get_customer(1004)->add_to_cart(2009, 12);
    e.get_customer(1004)->print();
    
    e.print();

    e.get_customer(1004)->checkout();
    e.get_customer(1004)->print();

    e.print();

    e.price_increase(1.10);
    e.print();

    e.get_customer(1004)->print();

    
    return 0;
}
