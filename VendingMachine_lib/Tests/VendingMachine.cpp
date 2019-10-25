#include <VendingMachine.h>
#include "gtest/gtest.h"

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

    EXPECT_EQ(1, vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, whenOneQuarterIsInserted_thenInvalidCoinCountIsZero){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetTotalAmount(25);

    EXPECT_EQ(0, vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, when50CentsIsInserted_andProductSelectedCostsOneDollar_thenAvailabilityToBuyIsFalse){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.BuyProduct(100);

    EXPECT_FALSE(vendingMachine.ableToBuyProduct);
}




TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCostsOneDollar_thenAvailabilityToBuyIsTrue){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.SetTotalAmount(100);
    vendingMachine.BuyProduct(100);
    EXPECT_TRUE(vendingMachine.ableToBuyProduct);
}

TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCosts50Cents_thenTotalAmountIsReduced){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.SetTotalAmount(100);
    vendingMachine.BuyProduct(50);
    EXPECT_EQ(50, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, WhenYouHaveADollarandProductSelectedCostsOneDollarCents_thenTotalAmountIsReduced){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.SetTotalAmount(100);
    vendingMachine.BuyProduct(productPriceInCents);
    EXPECT_EQ(0, vendingMachine.GetTotalValueInCents());
}

TEST(VendingMachineSuite, whenOneDollarIsInserted_andProductSelectedCostsOneDollar_thenDisplayTHANKYOU){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.SetTotalAmount(100);
    vendingMachine.BuyProduct(productPriceInCents);

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenOneDollarIsInserted_andProductSelectedCostsOneDollar_thenDisplayTHANKYOUThenINSERTCOIN){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.SetTotalAmount(100);
    vendingMachine.BuyProduct(productPriceInCents);

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN",vendingMachine.GetMessage());
    EXPECT_EQ(0,vendingMachine.GetTotalValueInCents());

}

TEST(VendingMachineSuite, whenOneDollarIsInserted_andProductSelectedCostsSixtyFiveCents_thenDisplayTHANKYOUThenINSERTCOIN){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.ImplementationOfBuyingProcess("candy");

    EXPECT_EQ("THANK YOU",vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN",vendingMachine.GetMessage());
    EXPECT_EQ(0,vendingMachine.GetTotalValueInCents());

}

TEST(VendingMachineSuite, when25CentsIsInserted_andProductSelectedCostsOneDollar_thenDisplayIsUpdatedToShowCost){
    VendingMachine vendingMachine = VendingMachine();
    vendingMachine.SetTotalAmount(25);
    vendingMachine.ImplementationOfBuyingProcess("chips");
    EXPECT_EQ("PRICE 0.50",vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenOneDollarHasBeenInserted_andChipsIsSelected_thenCoinReturnHasChange){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetTotalAmount(100);

    vendingMachine.ImplementationOfBuyingProcess("chips");
    EXPECT_EQ(50, vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, selectProductReturnsChangeAmount){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetTotalAmount(100);
    vendingMachine.ImplementationOfBuyingProcess("chips");

    EXPECT_EQ(50,vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, whenOneDollarHasBeenInserted_andColaIsSelected_thenCoinReturnHasNoChange){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetTotalAmount(100);

    vendingMachine.ImplementationOfBuyingProcess("cola");
    EXPECT_EQ(0, vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, whenOneDollar_andReturnCoinsIsPressed_thenCoinReturnHasChange){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetTotalAmount(100);
    vendingMachine.ReturnCoins();
    EXPECT_EQ(100, vendingMachine.GetReturnedCoinCount());
}

TEST(VendingMachineSuite, whenExactChangeOnly_isInEnabled_EXACTCHANGEONLYIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetVendingMachine(true);
    EXPECT_EQ("EXACT CHANGE ONLY", vendingMachine.GetMessage());
}

TEST(VendingMachineSuite, whenExactChangeOnly_isInNotEnabled_EXACTCHANGEONLYIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();

    vendingMachine.SetVendingMachine(false);
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}






