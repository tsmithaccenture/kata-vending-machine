#include <string>
#include <Product.h>

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

class VendingMachine {

private:
    int totalValueInCents;
    int invalidCoinCount;
    const double dimeDiameter = 17.91;
    const int dimeValueInCents = 10;
    const int quarterValueInCents = 25;
    const double nickelDiameter = 21.21;
    const int nickelValueInCents = 5;
    const double quarterDiameter = 24.26;

public:
    VendingMachine();
    string GetMessage();
    void InsertCoin(double diameter); 
    int GetTotalValueInCents();
    int GetInvalidCoinCount();
    void SelectProduct(int productId);
    int GetProductQuantity(int productId);

    VendingMachine(vector<Product> products);
};

#endif
