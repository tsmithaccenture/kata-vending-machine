#include<string>
using namespace std;

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

class VendingMachine {

private:
    int totalAmount;
    const double dimeDiameter = 17.91;
    const int dimeValue = 10;
    const int quarterValue = 25;
    const double nickelDiameter = 21.21;
    const int nickelValue = 5;

public:
    string GetMessage();
    void InsertCoin(double diameter); 
    int GetTotalAmount();
};

#endif
