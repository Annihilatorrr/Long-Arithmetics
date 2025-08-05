
#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticAdditionTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {};

TEST_P(LongArithmeticAdditionTest, ParameterizedAddition) {
    LongArithmetic la;
    auto [a, b, expected] = GetParam();
    std::string result = la.add(a.c_str(), b.c_str());
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

INSTANTIATE_TEST_SUITE_P(
    Additions,
    LongArithmeticAdditionTest,
    ::testing::Values(
        std::make_tuple("123", "456", "579"),
        std::make_tuple("12345", "11", "12356"),
        std::make_tuple("12345", "99", "12444"),
        std::make_tuple("12345", "9", "12354"),
        std::make_tuple("11", "12345", "12356"),
        std::make_tuple("9", "12345", "12354"),
        std::make_tuple("9", "9", "18"),
        std::make_tuple("9", "0", "9"),
        std::make_tuple("0", "9", "9"),
        std::make_tuple("99", "0", "99"),
        std::make_tuple("0", "99", "99"),
        std::make_tuple("0", "0", "0"),
        std::make_tuple("5", "4", "9"),
        std::make_tuple("5", "5", "10"),
        std::make_tuple("-5", "-4", "-9"),
        std::make_tuple("-5", "-5", "-10"),
        std::make_tuple("-99", "-1", "-100"),
        std::make_tuple("-0", "-0", "0"),
        std::make_tuple("-123", "123", "0"),
        std::make_tuple("123", "-123", "0"),
        std::make_tuple("-123", "100", "-23"),
        std::make_tuple("100", "-123", "-23"),
        std::make_tuple("-100", "123", "23"),
        std::make_tuple("123", "-100", "23"),
        std::make_tuple("0", "-123", "-123"),
        std::make_tuple("-123", "0", "-123"),
        std::make_tuple("0", "-0", "0"),
        std::make_tuple("-0", "0", "0")
    )
);
