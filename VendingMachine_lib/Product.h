#include<string>
using namespace std;

#ifndef TESTING_TEST_PRODUCT_H
#define TESTING_TEST_PRODUCT_H

class Product {
public:
    int Id;
    int PriceInCents;
    int Quantity;
    void Dispense();
    Product();
};

#endif
