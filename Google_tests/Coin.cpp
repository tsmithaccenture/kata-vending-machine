#include "gtest/gtest.h"
#include <Coin.cpp>

TEST(CoinTests, shouldReturnValueOfCoin_whenSentQuarter){
    Coin coin = Coin(24.26, 5.67);

    EXPECT_EQ(0.25, coin.getValue());
}

TEST(CoinTests, shouldReturnValueOfCoin_whenSentDime){
    Coin coin = Coin(17.91, 2.268);

    EXPECT_EQ(0.1, coin.getValue());
}

