#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticSubtractionTest
    : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>>
{
};

TEST_P(LongArithmeticSubtractionTest, ParameterizedSubtraction)
{
    LongArithmetic la;
    auto [a, b, expected] = GetParam();
    std::string result = la.sub(a.c_str(), b.c_str());
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

INSTANTIATE_TEST_SUITE_P(
    SubtractionCases,
    LongArithmeticSubtractionTest,
    ::testing::Values(
        std::make_tuple("456", "123", "333"),                   // + - + => +
        std::make_tuple("123", "123", "0"),                     // x - x => 0
        std::make_tuple("1000", "1", "999"),                    // borrow chain
        std::make_tuple("10000", "1", "9999"),                  // longer borrow chain
        std::make_tuple("1000", "999", "1"),                    // near cancellation => +1
        std::make_tuple("987654321", "123456789", "864197532"), // large numbers

        std::make_tuple("123", "456", "-333"),   // + - + => -
        std::make_tuple("1", "1000", "-999"),    // + - larger + => - (borrow)
        std::make_tuple("0", "12345", "-12345"), // 0 - (+x) => -x
        std::make_tuple("3", "9", "-6"),         // single-digit negative result
        std::make_tuple("111", "222", "-111"),   // same length negative result

        std::make_tuple("123", "-456", "579"), // + - (-x) => + (addition)
        std::make_tuple("0", "-123", "123"),   // 0 - (-x) => +x
        std::make_tuple("5", "-0", "5"),       // x - (-0) => x

        std::make_tuple("-123", "456", "-579"), // (-x) - (+y) => -(x+y)
        std::make_tuple("-0", "5", "-5"),       // (-0) - (+x) => -x

        std::make_tuple("-123", "-456", "333"),  // (-a) - (-b), |a|<|b| => +
        std::make_tuple("-789", "-456", "-333"), // (-a) - (-b), |a|>|b| => -
        std::make_tuple("-555", "-555", "0"),    // (-a) - (-a) => 0
        std::make_tuple("-1000", "-999", "-1"),  // (-1000) - (-999) => -1
        std::make_tuple("-999", "-1000", "1"),   // (-999) - (-1000) => +1

        std::make_tuple("0", "0", "0"),  // 0 - 0
        std::make_tuple("0", "-0", "0"), // 0 - (-0) normalization
        std::make_tuple("-0", "0", "0"), // (-0) - 0 normalization
        std::make_tuple("-0", "-0", "0") // (-0) - (-0) normalization
        ));
