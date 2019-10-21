#include "gtest/gtest.h"
#include <Coin.cpp>


TEST(CoinTests, shouldReturnValueOfCoin_whenSentQuarter){
    Quarter quarter;
    Coin coin = Coin(24.26); //weight: 5.67

    EXPECT_EQ(quarter.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentDime){
    Dime dime;
    Coin coin = Coin(dime.diameter); //weight: 2.268

    EXPECT_EQ(dime.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentNickel){
    Nickel nickel;
    Coin coin = Coin(nickel.diameter);

    EXPECT_EQ(nickel.value, coin.getValue());
}