//
// Created by illya on 10/10/18.
//

#include <Result.h>
#include <gtest/gtest.h>

using cows_and_bulls::Result;

class ResultTest : public ::testing::TestWithParam<std::tuple<Result, bool>> {};

TEST_P(ResultTest, result_validation) {
  auto [result, valid] = GetParam();
  EXPECT_EQ(valid, result.IsValid());
}

INSTANTIATE_TEST_CASE_P(ResultValidationTest, ResultTest, ::testing::Values(
    //              target        is valid
    std::make_tuple(Result{0, 0}, true),
    std::make_tuple(Result{0, 1}, true),
    std::make_tuple(Result{0, 2}, true),
    std::make_tuple(Result{0, 3}, true),
    std::make_tuple(Result{0, 4}, true),
    std::make_tuple(Result{0, 5}, false),

    std::make_tuple(Result{1, 0}, true),
    std::make_tuple(Result{1, 1}, true),
    std::make_tuple(Result{1, 2}, true),
    std::make_tuple(Result{1, 3}, true),
    std::make_tuple(Result{1, 4}, false),
    std::make_tuple(Result{1, 5}, false),

    std::make_tuple(Result{2, 0}, true),
    std::make_tuple(Result{2, 1}, true),
    std::make_tuple(Result{2, 2}, true),
    std::make_tuple(Result{2, 3}, false),
    std::make_tuple(Result{2, 4}, false),
    std::make_tuple(Result{2, 5}, false),

    std::make_tuple(Result{3, 0}, true),
    std::make_tuple(Result{3, 1}, false),
    std::make_tuple(Result{3, 2}, false),
    std::make_tuple(Result{3, 3}, false),
    std::make_tuple(Result{3, 4}, false),
    std::make_tuple(Result{3, 5}, false),

    std::make_tuple(Result{4, 0}, true),
    std::make_tuple(Result{4, 1}, false),
    std::make_tuple(Result{4, 2}, false),
    std::make_tuple(Result{4, 3}, false),
    std::make_tuple(Result{4, 4}, false),
    std::make_tuple(Result{4, 5}, false),

    std::make_tuple(Result{5, 0}, false),
    std::make_tuple(Result{5, 1}, false),
    std::make_tuple(Result{5, 2}, false),
    std::make_tuple(Result{5, 3}, false),
    std::make_tuple(Result{5, 4}, false),
    std::make_tuple(Result{5, 5}, false)
));