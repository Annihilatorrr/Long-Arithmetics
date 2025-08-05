#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticPowTest : public ::testing::TestWithParam<std::tuple<std::string, int, std::string>> {};

TEST_P(LongArithmeticPowTest, ParameterizedPow) {
    LongArithmetic la;
    auto [base, exponent, expected] = GetParam();
    std::string result = la.pow(base, exponent);
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

INSTANTIATE_TEST_SUITE_P(
    PowTests,
    LongArithmeticPowTest,
    ::testing::Values(
        std::make_tuple("0", 0, "1"),
        std::make_tuple("12345", 0, "1"),
        std::make_tuple("-9876", 0, "1"),

        std::make_tuple("0", 1, "0"),
        std::make_tuple("12345", 1, "12345"),
        std::make_tuple("-9876", 1, "-9876"),

        std::make_tuple("2", 3, "8"),
        std::make_tuple("10", 2, "100"),
        std::make_tuple("123", 2, "15129"),

        std::make_tuple("-2", 2, "4"),
        std::make_tuple("-5", 4, "625"),

        std::make_tuple("-2", 3, "-8"),
        std::make_tuple("-3", 5, "-243"),

        std::make_tuple("1", 1000, "1"),
        std::make_tuple("-1", 1000, "1"),
        std::make_tuple("-1", 999, "-1"),

        std::make_tuple("123456789", 2, "15241578750190521"),

        std::make_tuple("123456789", 3, "1881676371789154860897069"), 
        std::make_tuple("999999999", 2, "999999998000000001"),         
        std::make_tuple("987654321", 4, "951524275264729222930554919618623681"),
        std::make_tuple("1000000000", 3, "1000000000000000000000000000"), 
        std::make_tuple("3141592653589793238462643383279", 2,
            "9869604401089358618834490999872991420714831834895839696791841")
    )
);

