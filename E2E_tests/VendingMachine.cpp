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

TEST(AcceptanceTestSuite, whenOneInvalidCoinIsInserted_thenTheInvalidCoinIsReleasedToCoinReturn){
    VendingMachine vendingMachine = VendingMachine();

    EXPECT_EQ(0, vendingMachine.GetInvalidCoinCount());

    double pennyDiameter = 19.05;
    vendingMachine.InsertCoin(pennyDiameter);

    EXPECT_EQ(1, vendingMachine.GetInvalidCoinCount());
}