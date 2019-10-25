#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#ifndef TESTING_TEST_VENDINGMACHINE_H
#define TESTING_TEST_VENDINGMACHINE_H

static const int COLA_COST = 100;

static const int CHIPS_COST = 50;

static const int CANDY_COST = 65;

const double dimeDiameter = 17.91;

const int dimeValueInCents = 10;

const int quarterValueInCents = 25;

const double nickelDiameter = 21.21;

const int nickelValueInCents = 5;

const double quarterDiameter = 24.26;

class VendingMachine {

private:
    int totalValueInCents;
    int purchasePriceInCents;
    int returnedCoinCount;
    bool exactChangeOnly = false;



public:
    bool ableToBuyProduct = false;
    void InsertCoin(double diameter);
    int GetTotalValueInCents();
    int GetReturnedCoinCount();
    void BuyProduct(int productCostInCents);
    void ResetVendingMachine();
    std::string GetMessage();
    std::string ImplementationOfBuyingProcess(std::string selectedProduct);
    void ReturnCoins();
    void SetVendingMachine(bool SetExactChangeOnly);
    void SetTotalAmount(int productCost);

    void SetReturnedCoins(int amount);

};

#endif
