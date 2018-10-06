//
// Created by illya on 06/10/18.
//

#include "gtest/gtest.h"
#include "Number.h"
#include "Numbers.h"

using cows_and_bulls::Number;
using cows_and_bulls::Numbers;
using cows_and_bulls::NumsTemplate;

class NumberTest : public ::testing::TestWithParam<Number> {};

TEST_P(NumberTest, TestOk) {
  auto num = GetParam();
  Number new_num(num);
  EXPECT_EQ(new_num, num);
}

INSTANTIATE_TEST_CASE_P(GetAsSingleNumTest, NumberTest, ::testing::ValuesIn(Numbers::nums));