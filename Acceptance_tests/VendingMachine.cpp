#include <VendingMachine.h>
#include "gtest/gtest.h"

class AcceptanceTestFixture: public ::testing::Test {
public:
    VendingMachine vendingMachine;

    void SetUp( ) {
        vendingMachine = VendingMachine();
    }
};

bool contains(std::vector<double> container, double key){
    return std::find(container.begin(), container.end(), key) != container.end();
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenNoCoinsAreInserted_ThenINSERTCOINIsDisplayed){
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenAValidCoinIsInserted_ThenTheCurrentAmountIsDisplayed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    EXPECT_EQ("$0.25", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenOneCentIsInserted_ThenTheCoinReturnContainsOneCent){
    vendingMachine.InsertCoin(pennyDiameterInMillimeters, pennyWeightInGrams);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 1);
    EXPECT_TRUE(contains(returnedCoins, pennyValueInCents));
}

TEST_F(AcceptanceTestFixture, DISABLED_GivenAVendingMachine_WhenOneDollarIsInserted_AndColaIsSelected_ThenColaIsDispensed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    int colaId = 1;

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == colaId);
}

/*TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenOneDollarIsInserted_AndColaIsSelected_ThenTHANKYOUIsDisplayed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    int colaId = 1;

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == colaId);
    EXPECT_EQ("THANK YOU", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenNinetyCentsIsInserted_AndColaIsSelected_ThenPRICEOneDollarIsDisplayed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);

    int colaId = 1;

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("PRICE $1.00", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenFiftyCentsIsInserted_AndChipsIsSelected_ThenChipsIsDispensed){
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);

    int chipsId = 2;

    vendingMachine.SelectProduct(chipsId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == chipsId);
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_WhenSixtyFiveCentsIsInserted_AndCandyIsSelected_ThenCandyIsDispensed){
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);
    vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);

    int candyId = 3;

    vendingMachine.SelectProduct(candyId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == candyId);
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndMoneyIsInserted_AndASelectionIsMade_WhenTHANKYOUIsDisplayed_ThenINSERTCOINIsDisplayed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    int chipsId = 2;

    vendingMachine.SelectProduct(chipsId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == chipsId);
    EXPECT_EQ("THANK YOU", vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndNoCoinsAreInserted_WhenASelectionIsMade_ThenINSERTCOINIsDisplayed){
    int chipsId = 2;

    vendingMachine.SelectProduct(chipsId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndThirtyCentsIsInserted_AndColaIsSelected_WhenPRICEOneDollarIsDisplayed_ThenThirtyCentsIsDisplayed){
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);

    int colaId = 1;

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("PRICE $1.00", vendingMachine.GetMessage());
    EXPECT_EQ("$0.30", vendingMachine.GetMessage());
}*/

/*TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndSeventyFiveCentsIsInserted_AndChipsIsSelected_ThenTheCoinReturnContainsTwentyFiveCents){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    int chipsId = 2;

    vendingMachine.SelectProduct(chipsId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == chipsId);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 1);
    EXPECT_TRUE(contains(returnedCoins, quarterValueInCents));
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndSeventyFiveCentsIsInserted_AndCandyIsSelected_ThenTheCoinReturnContainsTenCents){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    int candyId = 3;

    vendingMachine.SelectProduct(candyId);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == candyId);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 1);
    EXPECT_TRUE(contains(returnedCoins, dimeValueInCents));
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndOneDollarAndFifteenCentsIsInserted_AndColaIsSelected_ThenTheCoinReturnContainsFifteenCents){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);
    vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);

    int colaId = 1;

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == colaId);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 2);
    EXPECT_TRUE(contains(returnedCoins, dimeValueInCents));
    EXPECT_TRUE(contains(returnedCoins, nickelValueInCents));
}*/

/*TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndFiftyCentsIsInserted_WhenTheCoinReturnButtonIsPressed_ThenTheCoinReturnContainsFiftyCents){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    vendingMachine.ReturnCoins();

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 2);
    EXPECT_TRUE(contains(returnedCoins, quarterValueInCents));
    EXPECT_TRUE(contains(returnedCoins, quarterValueInCents));
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndFiftyCentsIsInserted_AndTheCoinReturnButtonIsPressed_WhenTheCoinReturnContainsFiftyCents_ThenINSERTCOINIsDisplayed){
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    vendingMachine.ReturnCoins();

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_TRUE(returnedCoins.size() == 2);
    EXPECT_TRUE(contains(returnedCoins, quarterValueInCents));
    EXPECT_TRUE(contains(returnedCoins, quarterValueInCents));
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}*/

/*TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndColaIsSoldOut_AndOneDollarIsInserted_WhenColaIsSelected_ThenSOLDOUTIsDisplayed){
    int colaId = 1;

    EXPECT_FALSE(vendingMachine.Inventory.Contains(Product(colaId, 1.00)));

    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("SOLD OUT", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndColaIsSoldOut_AndOneDollarIsInserted_AndColaIsSelected_WhenSOLDOUTIsDisplayed_ThenOneDollarIsDisplayed){
    int colaId = 1;

    EXPECT_FALSE(vendingMachine.Inventory.Contains(Product(colaId, 1.00)));

    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);
    vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("SOLD OUT", vendingMachine.GetMessage());
    EXPECT_EQ("$1.00", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndColaIsSoldOut_AndNoMoneyIsInserted_WhenColaIsSelected_ThenSOLDOUTIsDisplayed){
    int colaId = 1;

    EXPECT_FALSE(vendingMachine.Inventory.Contains(Product(colaId, 1.00)));

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("SOLD OUT", vendingMachine.GetMessage());
}

TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndColaIsSoldOut_AndNoMoneyIsInserted_AndColaIsSelected_WhenSOLDOUTIsDisplayed_ThenINSERTCOINIsDisplayed){
    int colaId = 1;

    EXPECT_FALSE(vendingMachine.Inventory.Contains(Product(colaId, 1.00)));

    vendingMachine.SelectProduct(colaId);

    EXPECT_TRUE(vendingMachine.GetDispensedProductId() == NULL);
    EXPECT_EQ("SOLD OUT", vendingMachine.GetMessage());
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}*/

/*
TEST_F(AcceptanceTestFixture, GivenAVendingMachine_AndNoCoinsAreInserted_WhenNoChangeExistsInTheMachine_ThenEXACTCHANGEONLYIsDisplayed){
    EXPECT_TRUE(vendingMachine.Bank.Count == 0);
    EXPECT_EQ("EXACT CHANGE ONLY", vendingMachine.GetMessage());
}*/
