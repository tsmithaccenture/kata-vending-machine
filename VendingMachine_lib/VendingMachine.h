#include<string>
using namespace std;

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

class VendingMachine {

private:
    int totalAmount;
    int invalidCoinCount;
    const double dimeDiameter = 17.91;
    const int dimeValue = 10;
    const int quarterValue = 25;
    const double nickelDiameter = 21.21;
    const int nickelValue = 5;
    const double quarterDiameter = 24.26;

public:
    VendingMachine();
    string GetMessage();
    void InsertCoin(double diameter); 
    int GetTotalAmount();
    int GetInvalidCoinCount();
};

#endif
