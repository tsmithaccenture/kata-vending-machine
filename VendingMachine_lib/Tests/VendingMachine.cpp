#include <VendingMachine.h>
#include "gtest/gtest.h"

TEST(VendingMachineSuite, whenAQaurterDiameterIsInserted_thenUpdateTotalAmountToTwentyFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(24.26);

    EXPECT_EQ(25, vendingMachine.GetTotalAmount());
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

