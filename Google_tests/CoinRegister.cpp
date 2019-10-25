#include "gtest/gtest.h"
#include <Quarter.cpp>
#include <Dime.cpp>
#include <Nickel.cpp>
#include <CoinRegister.cpp>

TEST(CoinRegisterTests, shouldReturnRunningTotal_whenGivenTwoQuarters){
    CoinRegister coinRegister;
    Quarter quarter;

    coinRegister.Add(quarter.value);
    coinRegister.Add(quarter.value);

    EXPECT_EQ(.50, coinRegister.GetTotalAmount());
}

TEST(CoinRegisterTests, shouldReturnRunningTotal_whenGivenThreeQuarters){
    CoinRegister coinRegister;
    Quarter quarter;

    coinRegister.Add(quarter.value);
    coinRegister.Add(quarter.value);
    coinRegister.Add(quarter.value);

    EXPECT_EQ(.75, coinRegister.GetTotalAmount());
}

TEST(CoinRegisterTests, shouldReturnRunningTotal_whenGivenOneDimeOneQuarterOneNickel){
    CoinRegister coinRegister;
    Quarter quarter;
    Dime dime;
    Nickel nickel;

    coinRegister.Add(quarter.value);
    coinRegister.Add(dime.value);
    coinRegister.Add(nickel.value);

    EXPECT_EQ(.4, coinRegister.GetTotalAmount());
}
