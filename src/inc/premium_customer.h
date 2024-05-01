#ifndef __PREMIUM_CUTOMER_H
#define __PREMIUM_CUTOMER_H

#include "customer.h"

class PremiumCustomer : public Customer 
{
    private:
        double m_monthly_fee;        

    public:
        // an ordinary customer upgrades to Premium with some starting points
        PremiumCustomer(uint64_t i, const std::string& n, const std::string& e, const std::vector<Product*>* c, double points);

        // constuct a completelly new PremiumCustomer with some starting amount of points 
        PremiumCustomer(Customer* basic_customer, double points);

        // deconstructor
        ~PremiumCustomer() override;
        
        // getter setter for montly fee
        void set_montly_fee(double mf);

        double get_montly_fee() const;

        // Get a discount from the total price of the cart. Decreases the amount of points used for the discount.
        void print() override;

        void add_points() override;
};

#endif//__PREMIUM_CUTOMER_H