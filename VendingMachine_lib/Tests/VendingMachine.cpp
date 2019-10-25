#include <VendingMachine.h>
#include "gtest/gtest.h"

const double quarterDiameter = 24.26;
const double dimeDiameter = 17.91;
const double nickelDiameter = 21.21;
const int dimeValueInCents = 10;
const int quarterValueInCents = 25;
const int nickelValueInCents = 5;
const double pennyDiameter = 19.05;
const int productPriceInCents = 100;

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

TEST(VendingMachineSuite, when50CentsIsInserted_andProductSelectedCostsOneDollar_thenAvailabilityToBuyIsFalse){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    EXPECT_FALSE(vendingMachine.SelectProduct(productPriceInCents));
}

TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCostsOneDollar_thenAvailabilityToBuyIsTrue){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    EXPECT_TRUE(vendingMachine.SelectProduct(productPriceInCents));
}

TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCosts50Cents_thenTotalAmountIsReduced){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SelectProduct(50);
    EXPECT_EQ(50, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCostsOneDollarCents_thenTotalAmountIsReduced){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SelectProduct(productPriceInCents);
    EXPECT_EQ(0, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenOneDollarIsInserted_andProductSelectedCostsOneDollar_thenDisplayTHANKYOU){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SelectProduct(productPriceInCents);

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenOneDollarIsInserted_andProductSelectedCostsOneDollar_thenDisplayTHANKYOUThenINSERTCOIN){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SelectProduct(productPriceInCents);

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN",vendingMachine.GetMessage());
    EXPECT_EQ(0,vendingMachine.GetTotalValueInCents());

}

TEST(VendingMachineSuite, whenOneDollarAndFivtyCentsIsInserted_andProductSelectedCostsOneDollar_thenDisplayTHANKYOUThenINSERTCOIN){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SelectProduct(productPriceInCents);

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN",vendingMachine.GetMessage());
    EXPECT_EQ(0,vendingMachine.GetTotalValueInCents());

}


//TEST(VendingMachineSuite, when50CentsIsInserted_andProductSelectedCostsOneDollar_thenDisplayIsUpdatedToShowCost){
//    VendingMachine vendingMachine = VendingMachine();
//    vendingMachine.InsertCoin(quarterDiameter);
//    vendingMachine.InsertCoin(quarterDiameter);
//    vendingMachine.SelectProduct(productPriceInCents);
//    EXPECT_EQ("PRICE 1.00",vendingMachine.GetMessage());
//}



