#include <VendingMachine.h>
#include "gtest/gtest.h"

TEST(AcceptanceTestSuite, whenNoCoinsAreInserted_thenInsertCoinIsDisplayed){
    VendingMachine vendingMachine;
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST(AcceptanceTestSuite, whenFourQuartersAreInserted_thenOneDollarIsDisplayed){
    VendingMachine vendingMachine;

    double quarterDiameter = 24.26;

    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    
    EXPECT_EQ("1.00", vendingMachine.GetMessage());
}
