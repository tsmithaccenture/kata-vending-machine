#include "gtest/gtest.h"
#include <Coin.cpp>
Quarter quarter;
Dime dime;
Nickel nickel;

TEST(CoinTests, shouldReturnValueOfCoin_whenSentQuarter){
    Coin coin = Coin(quarter.diameter);

    EXPECT_EQ(quarter.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentDime){
    Coin coin = Coin(dime.diameter);

    EXPECT_EQ(dime.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentNickel){
    Coin coin = Coin(nickel.diameter);

    EXPECT_EQ(nickel.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueZero_whenSentPenny){
    Coin coin = Coin(19.05);

    EXPECT_EQ(0, coin.getValue());
}