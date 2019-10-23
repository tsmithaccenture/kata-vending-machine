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



// handle valid quarter
// handle valid dime
// handle valid nickel
// handle updating totalamount
// handle updating message

//accept dime
//accept Nickel

// The vending machine will accept valid coins (nickels, dimes, and quarters).
// When a valid coin is inserted the amount of the coin will be added to the current amount and the display will be updated.

