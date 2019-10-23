#include<string>
using namespace std;

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

class VendingMachine {

private:
    int totalAmount;

public:
    string GetMessage();
    void InsertCoin(double diameter); 
    int GetTotalAmount();
};

#endif
