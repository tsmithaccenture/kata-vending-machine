#include <cstring>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

const double quarterDiameterInMillimeters = 24.26;
const double quarterWeightInGrams = 5.670;
const double quarterValueInCents = 0.25;
const double dimeDiameterInMillimeters = 17.91;
const double dimeWeightInGrams = 2.268;
const double dimeValueInCents = 0.10;
const double nickelDiameterInMillimeters = 21.21;
const double nickelWeightInGrams = 5.00;
const double nickelValueInCents = 0.05;
const double pennyDiameterInMillimeters = 19.05;
const double pennyWeightInGrams = 2.5;
const double pennyValueInCents = 0.01;

class VendingMachine {

private:
    double totalInsertedValue;
    std::string displayMessage;
    std::vector<double> returnedCoins;

public:
    std::string GetMessage();
    double InsertCoin(double diameter, double weight);
    double AddInsertedValue(double value);
    std::string UpdateMessage(double value);
    std::vector<double> GetReturnedCoins();
    int AddReturnedCoins(double value);
    bool SelectProduct(int productId);
    int GetDispensedProductId();
    double GetProductPrice(int productId);
    bool IsInsertedGreaterThanOrEqualToPrice(int productId);
};

#endif
