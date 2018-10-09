//
// Created by illya on 06/10/18.
//

#include "gtest/gtest.h"
#include "Number.h"
#include "Numbers.h"

using cows_and_bulls::Number;
using cows_and_bulls::Numbers;
using cows_and_bulls::NumsTemplate;
using cows_and_bulls::Result;

class NumberTest : public ::testing::TestWithParam<Number> {};

TEST_P(NumberTest, self_convertion_test) {
  auto num = GetParam();
  Number new_num(num);
  EXPECT_EQ(new_num, num);
}

TEST_P(NumberTest, get_result_for_self) {
  auto num = GetParam();
  cows_and_bulls::Result result{4,0};
  EXPECT_EQ(result, num.GetResultFor(num));
}

INSTANTIATE_TEST_CASE_P(NumbersConstructionTest, NumberTest, ::testing::ValuesIn(Numbers::nums));

class NumberResultTest : public ::testing::TestWithParam<std::tuple<Number, Number, Result>> {};

TEST_P(NumberResultTest, number_result_test) {
 auto [base, target, result] = GetParam();
 EXPECT_EQ(result, base.GetResultFor(target));
 EXPECT_EQ(result, target.GetResultFor(base));
}

INSTANTIATE_TEST_CASE_P(TestResult, NumberResultTest, ::testing::Values(
    //              base          target        expectation
    std::make_tuple(Number{1023}, Number{4567}, Result{0, 0}),
    std::make_tuple(Number{1023}, Number{1456}, Result{1, 0}),
    std::make_tuple(Number{1023}, Number{1045}, Result{2, 0}),
    std::make_tuple(Number{1023}, Number{1025}, Result{3, 0}),
    std::make_tuple(Number{1023}, Number{2310}, Result{0, 4}),
    std::make_tuple(Number{1023}, Number{1032}, Result{2, 2}),
    std::make_tuple(Number{1023}, Number{2031}, Result{1, 3})
));
