#include <VendingMachine.h>
#include "gtest/gtest.h"

const double quarterDiameter = 24.26;
const double dimeDiameter = 17.91;
const double nickelDiameter = 21.21;
const int dimeValueInCents = 10;
const int quarterValueInCents = 25;
const int nickelValueInCents = 5;
const double pennyDiameter = 19.05;

TEST(VendingMachineSuite, whenAQaurterDiameterIsInserted_thenUpdateTotalAmountToTwentyFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(quarterValueInCents, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenADimeDiameterIsInserted_thenUpdateTotalAmountToTen){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(dimeDiameter);

    EXPECT_EQ(dimeValueInCents, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenANickelDiameterIsInserted_thenUpdateTotalAmountToFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(nickelDiameter);

    EXPECT_EQ(nickelValueInCents, vendingMachine.GetTotalValueInCents());
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

    vendingMachine.InsertCoin(pennyDiameter);

    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenAPennyAndAQuarterAreInserted_thenUpdateTotalAmountToTwentyFive){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(pennyDiameter);
    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(25, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenADimeAndAQuarterAreInserted_thenUpdateTotalAmountTo35){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(dimeDiameter);
    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(35, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenAQuarterAndNickelandDimeAreInserted_thenUpdateTotalAmountTo40){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(dimeDiameter);
    vendingMachine.InsertCoin(nickelDiameter);

    EXPECT_EQ(40, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenOnePennyIsInserted_thenInvalidCoinCountIsOne){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(pennyDiameter);

    EXPECT_EQ(1, vendingMachine.GetInvalidCoinCount());
}

TEST(VendingMachineSuite, whenOneQuarterIsInserted_thenInvalidCoinCountIsZero){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.InsertCoin(quarterDiameter);

    EXPECT_EQ(0, vendingMachine.GetInvalidCoinCount());
}