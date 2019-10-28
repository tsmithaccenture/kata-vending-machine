#include <VendingMachine.h>
#include "gtest/gtest.h"

class vendingMachineFixture: public ::testing::Test {
public:
    VendingMachine vendingMachine;

    void SetUp( ) {
        vendingMachine = VendingMachine();
    }
};

TEST_F(vendingMachineFixture, whenAQuarterIsInserted_ThenReturnTwentyFiveCentsValue){
    double value = vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    EXPECT_EQ(quarterValueInCents, value);
}

TEST_F(vendingMachineFixture, whenAQuarterWithAnInvalidDiameterIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(0.1, quarterWeightInGrams);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenAQuarterWithAnInvalidWeightIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(quarterDiameterInMillimeters, 0.1);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenADimeIsInserted_ThenReturnTenCentsValue){
    double value = vendingMachine.InsertCoin(dimeDiameterInMillimeters, dimeWeightInGrams);

    EXPECT_EQ(dimeValueInCents, value);
}

TEST_F(vendingMachineFixture, whenADimeWithAnInvalidDiameterIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(0.1, dimeWeightInGrams);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenADimeWithAnInvalidWeightIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(dimeDiameterInMillimeters, 0.1);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenANickelIsInserted_ThenReturnFiveCentsValue){
    double value = vendingMachine.InsertCoin(nickelDiameterInMillimeters, nickelWeightInGrams);

    EXPECT_EQ(nickelValueInCents, value);
}

TEST_F(vendingMachineFixture, whenANickelWithAnInvalidDiameterIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(0.1, nickelWeightInGrams);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenANickelWithAnInvalidWeightIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(nickelDiameterInMillimeters, 0.1);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenTwentyFiveCentsValueIsAddedToTotalValue_ThenReturnTwentyFiveCentsValue){
    double totalValue = vendingMachine.AddInsertedValue(0.25);

    EXPECT_EQ(0.25, totalValue);
}

TEST_F(vendingMachineFixture, whenTwentyFiveCentsValueIsAddedToTotalValueTwice_ThenReturnFiftyCentsValue){
    double totalValue = vendingMachine.AddInsertedValue(0.25);

    EXPECT_EQ(0.25, totalValue);

    totalValue = vendingMachine.AddInsertedValue(0.25);

    EXPECT_EQ(0.50, totalValue);
}

TEST_F(vendingMachineFixture, whenTwoQuartersAreInserted_ThenReturnFiftyCentsValue){
    double value = vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    EXPECT_EQ(0.25, value);

    value = vendingMachine.InsertCoin(quarterDiameterInMillimeters, quarterWeightInGrams);

    EXPECT_EQ(0.50, value);
}

TEST_F(vendingMachineFixture, whenTwentyFiveCentsValueIsSentToUpdateMessage_ThenReturnFormattedValue){
    std::string formattedValue = vendingMachine.UpdateMessage(0.25);

    EXPECT_EQ("$0.25", formattedValue);
}

TEST_F(vendingMachineFixture, whenFiveCentsValueIsSentToUpdateMessage_ThenReturnFormattedValue){
    std::string formattedValue = vendingMachine.UpdateMessage(0.05);

    EXPECT_EQ("$0.05", formattedValue);
}

TEST_F(vendingMachineFixture, whenTenCentsValueIsSentToUpdateMessage_ThenReturnFormattedValue){
    std::string formattedValue = vendingMachine.UpdateMessage(0.10);

    EXPECT_EQ("$0.10", formattedValue);
}

TEST_F(vendingMachineFixture, whenUpdateMessageIsSentTenCentsValue_ThenGetMessageReturnsFormattedValue){
    vendingMachine.UpdateMessage(0.10);

    EXPECT_EQ("$0.10", vendingMachine.GetMessage());
}

TEST_F(vendingMachineFixture, whenTwentyFiveCentsValueIsAddedToTotalValue_ThenGetMessageReturnsFormattedValue){
    vendingMachine.AddInsertedValue(0.25);

    EXPECT_EQ("$0.25", vendingMachine.GetMessage());
}

TEST_F(vendingMachineFixture, whenAPennyIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(pennyDiameterInMillimeters, pennyWeightInGrams);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenAPennyWithAnInvalidDiameterIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(0.1, pennyWeightInGrams);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenAPennyWithAnInvalidWeightIsInserted_ThenReturnZeroCentsValue){
    double value = vendingMachine.InsertCoin(pennyDiameterInMillimeters, 0.1);

    EXPECT_EQ(0.00, value);
}

TEST_F(vendingMachineFixture, whenAddReturnedCoinIsSentOneCentValue_ThenReturnReturnedCoinsCountOfOne){
    int returnedCoinsCount = vendingMachine.AddReturnedCoins(0.01);

    EXPECT_EQ(1, returnedCoinsCount);
}

TEST_F(vendingMachineFixture, whenAddReturnedCoinIsSentOneCentValueTwice_ThenReturnReturnedCoinsCountOfTwo){
    int returnedCoinsCount = vendingMachine.AddReturnedCoins(0.01);

    EXPECT_EQ(1, returnedCoinsCount);

    returnedCoinsCount = vendingMachine.AddReturnedCoins(0.01);

    EXPECT_EQ(2, returnedCoinsCount);
}

TEST_F(vendingMachineFixture, whenAddReturnedCoinIsSentOneCentValueTwice_ThenGetReturnedCoinsReturnsReturnedCoins){
    vendingMachine.AddReturnedCoins(0.01);
    vendingMachine.AddReturnedCoins(0.01);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_EQ(2, returnedCoins.size());
}

TEST_F(vendingMachineFixture, whenAPennyIsInserted_ThenGetReturnedCoinsReturnsOneCoin){
    vendingMachine.InsertCoin(pennyDiameterInMillimeters, pennyWeightInGrams);

    std::vector<double> returnedCoins = vendingMachine.GetReturnedCoins();

    EXPECT_EQ(1, returnedCoins.size());
}

TEST_F(vendingMachineFixture, whenGetProductPriceIsSentProductOne_ThenPriceOfOneDollarIsReturned){
    double price = vendingMachine.GetProductPrice(1);

    EXPECT_EQ(1.00, price);
}

TEST_F(vendingMachineFixture, whenGetProductPriceIsSentProductTwo_ThenPriceOfFiftyCentsIsReturned){
    double price = vendingMachine.GetProductPrice(2);

    EXPECT_EQ(0.50, price);
}

TEST_F(vendingMachineFixture, whenGetProductPriceIsSentProductThree_ThenPriceOfSixtyFiveCentsIsReturned){
    double price = vendingMachine.GetProductPrice(3);

    EXPECT_EQ(0.65, price);
}

TEST_F(vendingMachineFixture, whenIsInsertedGreaterThanOrEqualToPriceIsSentProductOne_AndTotalValueIsOneDollar_ThenReturnsTrue){
    vendingMachine.AddInsertedValue(1.00);

    EXPECT_TRUE(vendingMachine.IsInsertedGreaterThanOrEqualToPrice(1));
}

TEST_F(vendingMachineFixture, whenIsInsertedGreaterThanOrEqualToPriceIsSentProductOne_AndTotalValueIsNinetyCents_ThenReturnsFalse){
    vendingMachine.AddInsertedValue(0.90);

    EXPECT_FALSE(vendingMachine.IsInsertedGreaterThanOrEqualToPrice(1));
}