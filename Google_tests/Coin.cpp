#include "gtest/gtest.h"
#include <Coin.cpp>
Quarter quarter;
Dime dime;

TEST(CoinTests, shouldReturnValueOfCoin_whenSentQuarter){
    Coin coin = Coin(quarter.diameter, quarter.weight);

    EXPECT_EQ(quarter.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentDime){
    Coin coin = Coin(dime.diameter, dime.weight);

    EXPECT_EQ(dime.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentNickel){
    Nickel nickel;
    Coin coin = Coin(nickel.diameter, 0);

    EXPECT_EQ(nickel.value, coin.getValue());
}

TEST(CoinTests, shouldReturnValueZero_whenSentPenny){
    Coin coin = Coin(19.05, 0);

    EXPECT_EQ(0, coin.getValue());
}

TEST(CoinTests, shouldReturnValueZero_whenSentQuarterWithInvalidWeight){
    Coin coin = Coin(quarter.diameter, 0.1);

    EXPECT_EQ(0, coin.getValue());
}

TEST(CoinTest, ShouldReturnValueZero_whenSentDimeWithInvalidWeight){
    Coin coin = Coin(dime.diameter, 0.1);

    EXPECT_EQ(0,coin.getValue());
}