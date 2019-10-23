#include <VendingMachine.h>
#include "gtest/gtest.h"

const double quarterDiameter = 24.26;
const double dimeDiameter = 17.91;
const double nickelDiameter = 21.21;
const int dimeValue = 10;
const int quarterValue = 25;
const int nickelValue = 5;

TEST(VendingMachineSuite, whenAQaurterDiameterIsInserted_thenUpdateTotalAmountToTwentyFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(quarterValue, vendingMachine.GetTotalAmount());
}

TEST(VendingMachineSuite, whenADimeDiameterIsInserted_thenUpdateTotalAmountToTen){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(dimeDiameter);

    EXPECT_EQ(dimeValue, vendingMachine.GetTotalAmount());
}

TEST(VendingMachineSuite, whenANickelDiameterIsInserted_thenUpdateTotalAmountToFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(nickelDiameter);

    EXPECT_EQ(nickelValue, vendingMachine.GetTotalAmount());
}

TEST(VendingMachineSuite, whenAQuarterIsInserted_thenMessageIsUpdatedTo25Cents){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(quarterDiameter);
    EXPECT_EQ("0.25", vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenADimeIsInserted_thenMessageIsUpdatedTo10Cents){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(dimeDiameter);
    EXPECT_EQ("0.10", vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenAPennyIsInserted_thenMessageSaysInsertCoin){
    VendingMachine vendingMachine = VendingMachine();

    double pennyDiameter = 19.05;
    vendingMachine.InsertCoin(pennyDiameter);

    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenAPennyAndAQuarterAreInserted_thenUpdateTotalAmountToTwentyFive){
    VendingMachine vendingMachine = VendingMachine();

    double pennyDiameter = 19.05;
    vendingMachine.InsertCoin(pennyDiameter);
    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(25, vendingMachine.GetTotalAmount());
}

TEST(VendingMachineSuite, whenADimeAndAQuarterAreInserted_thenUpdateTotalAmountTo35){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(dimeDiameter);
    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(35, vendingMachine.GetTotalAmount());
}


// handle valid quarter
// handle valid dime
// handle valid nickel
// handle updating totalamount
// handle updating message

//accept dime
//accept Nickel

// The vending machine will accept valid coins (nickels, dimes, and quarters).
// When a valid coin is inserted the amount of the coin will be added to the current amount and the display will be updated.

