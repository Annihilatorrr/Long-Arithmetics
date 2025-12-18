#include <gtest/gtest.h>
#include "longarithmetic.h"

#include <tuple>

class LongArithmeticFactorialTest
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>>
{
};

TEST_P(LongArithmeticFactorialTest, ComputesFactorial)
{
    LongArithmetic la;
    auto [input, expected] = GetParam();
    EXPECT_EQ(la.factorial(input), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FactorialCases,
    LongArithmeticFactorialTest,
    ::testing::Values(
        std::make_tuple("0", "1"),
        std::make_tuple("1", "1"),
        std::make_tuple("2", "2"),
        std::make_tuple("3", "6"),
        std::make_tuple("5", "120"),
        std::make_tuple("10", "3628800"),
        std::make_tuple("20", "2432902008176640000"),
        std::make_tuple("0005", "120"),
        std::make_tuple("-0", "1")));

TEST(LongArithmeticFactorialInvalidInputTest, RejectsNegative)
{
    LongArithmetic la;
    EXPECT_THROW(la.factorial("-1"), std::invalid_argument);
    EXPECT_THROW(la.factorial("-123"), std::invalid_argument);
}

TEST(LongArithmeticFactorialInvalidInputTest, RejectsNonDigits)
{
    LongArithmetic la;
    EXPECT_THROW(la.factorial(""), std::invalid_argument);
    EXPECT_THROW(la.factorial("12a"), std::invalid_argument);
    EXPECT_THROW(la.factorial("+3"), std::invalid_argument);
}
