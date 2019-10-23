#include <VendingMachine.h>
#include "gtest/gtest.h"

TEST(AcceptanceTestSuite, whenNoCoinsAreInserted_thenInsertCoinIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST(AcceptanceTestSuite, whenFourQuartersAreInserted_thenOneDollarIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();

    double quarterDiameter = 24.26;

    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    
    EXPECT_EQ("1.00", vendingMachine.GetMessage());
}

TEST(AcceptanceTestSuite, whenOnePennyIsInserted_thenOnePennyIsAddedToTheCoinReturn){
    VendingMachine vendingMachine = VendingMachine();

    EXPECT_EQ(0, vendingMachine.GetCoinReturnCount());

    double pennyDiameter = 19.05;
    vendingMachine.InsertCoin(pennyDiameter);

    EXPECT_EQ(1, vendingMachine.GetCoinReturnCount());
}

//The vending machine will accept valid coins (nickels, dimes, and quarters) and reject invalid ones (pennies).
// When a valid coin is inserted the amount of the coin will be added to the current amount and the display will be updated.
// When there are no coins inserted, the machine displays INSERT COIN. Rejected coins are placed in the coin return.
