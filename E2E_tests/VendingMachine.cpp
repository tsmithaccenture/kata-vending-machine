#include <VendingMachine.h>
#include <Product.h>
#include <vector>
#include "gtest/gtest.h"

double quarterDiameter = 24.26;

TEST(AcceptanceTestSuite, whenNoCoinsAreInserted_thenInsertCoinIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();
    EXPECT_EQ("INSERT COIN", vendingMachine.GetMessage());
}

TEST(AcceptanceTestSuite, whenFourQuartersAreInserted_thenOneDollarIsDisplayed){
    VendingMachine vendingMachine = VendingMachine();

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

TEST(AcceptanceTestSuite, DISABLED_whenColaIsSelected_andOneDollarHasBeenInserted_thenColaIsDispensed){
    int colaId = 1;

    Product cola;
    cola.Id = colaId;
    cola.Description = "Cola";
    cola.PriceInCents = 100;
    cola.Quantity = 2;

    vector<Product> products;
    products.push_back(cola);

    VendingMachine vendingMachine = VendingMachine(products);

    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);
    vendingMachine.InsertCoin(quarterDiameter);

    vendingMachine.SelectProduct(colaId);

    EXPECT_EQ(1, vendingMachine.GetProductQuantity(colaId));
}


//There are three products: cola for $1.00, chips for $0.50, and candy for $0.65.

// When the respective button is pressed and enough money has been inserted,
// the product is dispensed and the machine displays THANK YOU.

// If the display is checked again, it will display INSERT COIN and the current amount will be set to $0.00.

// If there is not enough money inserted then the machine displays PRICE
// and the price of the item and subsequent checks of the display will display either INSERT COIN
// or the current amount as appropriate.