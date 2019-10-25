#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

class VendingMachine {

private:
    int totalValueInCents;
    int totalCostInCents;
    int invalidCoinCount;
    const double dimeDiameter = 17.91;
    const int dimeValueInCents = 10;
    const int quarterValueInCents = 25;
    const double nickelDiameter = 21.21;
    const int nickelValueInCents = 5;
    const double quarterDiameter = 24.26;
    bool DisplayThankYou = false;
    bool productAvailability = false;


public:
    void InsertCoin(double diameter);
    int GetTotalValueInCents();
    int GetInvalidCoinCount();
    bool SelectProduct(int productCost);
    void ResetVendingMachine();
    std::string GetMessage();
};

#endif
