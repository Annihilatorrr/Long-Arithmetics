
#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticAdditionTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>>
{
};

TEST_P(LongArithmeticAdditionTest, ParameterizedAddition)
{
    LongArithmetic la;
    auto [a, b, expected] = GetParam();
    std::string result = la.add(a.c_str(), b.c_str());
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

INSTANTIATE_TEST_SUITE_P(
    AdditionCases,
    LongArithmeticAdditionTest,
    ::testing::Values(
        std::make_tuple("123", "456", "579"),                                  // basic + +
        std::make_tuple("12345", "11", "12356"),                               // + +, different lengths
        std::make_tuple("12345", "99", "12444"),                               // + +, carry in tail
        std::make_tuple("12345", "9", "12354"),                                // + +, single-digit add
        std::make_tuple("11", "12345", "12356"),                               // commutativity (swap operands)
        std::make_tuple("9", "12345", "12354"),                                // commutativity (swap operands)
        std::make_tuple("9", "9", "18"),                                       // + +, carry across one digit
        std::make_tuple("999", "1", "1000"),                                   // carry chain across all digits
        std::make_tuple("9999", "1", "10000"),                                 // carry chain across all digits (longer)
        std::make_tuple("1999", "1", "2000"),                                  // carry chain with leading digit change
        std::make_tuple("99999999999999999999", "1", "100000000000000000000"), // long carry chain (stress)
        std::make_tuple("9", "0", "9"),                                        // +0 identity (right)
        std::make_tuple("0", "9", "9"),                                        // +0 identity (left)
        std::make_tuple("99", "0", "99"),                                      // +0 identity, multi-digit
        std::make_tuple("0", "99", "99"),                                      // +0 identity, multi-digit
        std::make_tuple("0", "0", "0"),                                        // zero + zero
        std::make_tuple("5", "4", "9"),                                        // + +, no carry
        std::make_tuple("5", "5", "10"),                                       // + +, carry creates new digit
        std::make_tuple("-5", "-4", "-9"),                                     // - - => -
        std::make_tuple("-5", "-5", "-10"),                                    // - - => -, carry creates new digit
        std::make_tuple("-99", "-1", "-100"),                                  // - - => -, carry chain
        std::make_tuple("-999", "-1", "-1000"),                                // - - => -, carry chain (longer)
        std::make_tuple("-0", "-0", "0"),                                      // negative zero normalization
        std::make_tuple("-123", "123", "0"),                                   // mixed signs, exact cancellation
        std::make_tuple("123", "-123", "0"),                                   // mixed signs, exact cancellation (swap)
        std::make_tuple("1", "-2", "-1"),                                      // mixed signs, |neg| > |pos|
        std::make_tuple("-1", "2", "1"),                                       // mixed signs, |pos| > |neg|
        std::make_tuple("1000", "-999", "1"),                                  // mixed signs, near cancellation => +1
        std::make_tuple("-1000", "999", "-1"),                                 // mixed signs, near cancellation => -1
        std::make_tuple("-123", "100", "-23"),                                 // mixed signs, |neg| > |pos| => -
        std::make_tuple("100", "-123", "-23"),                                 // mixed signs, |neg| > |pos| (swap)
        std::make_tuple("-100", "123", "23"),                                  // mixed signs, |pos| > |neg| => +
        std::make_tuple("123", "-100", "23"),                                  // mixed signs, |pos| > |neg| (swap)
        std::make_tuple("0", "-123", "-123"),                                  // 0 + (-x)
        std::make_tuple("-123", "0", "-123"),                                  // (-x) + 0
        std::make_tuple("0", "-0", "0"),                                       // 0 + (-0) normalization
        std::make_tuple("-0", "0", "0")                                        // (-0) + 0 normalization
        ));
