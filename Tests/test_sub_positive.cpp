#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticSubtractionTest
    : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {};

TEST_P(LongArithmeticSubtractionTest, ParameterizedSubtraction) {
    LongArithmetic la;
    auto [a, b, expected] = GetParam();
    std::string result = la.sub(a.c_str(), b.c_str());
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

std::string SubTestName(
    const ::testing::TestParamInfo<LongArithmeticSubtractionTest::ParamType>& info) {
    const auto& [a, b, expected] = info.param;
    std::string name = "Sub_" + a + "_minus_" + b + "_eq_" + expected;
    for (char& c : name) {
        if (!isalnum(static_cast<unsigned char>(c))) c = '_';
    }
    return name;
}

INSTANTIATE_TEST_SUITE_P(
    SubtractionCases,
    LongArithmeticSubtractionTest,
    ::testing::Values(
        // Положительные значения
        std::make_tuple("456", "123", "333"),
        std::make_tuple("123", "123", "0"),
        std::make_tuple("1000", "1", "999"),
        std::make_tuple("1000", "999", "1"),
        std::make_tuple("987654321", "123456789", "864197532"),

        std::make_tuple("123", "456", "-333"),
        std::make_tuple("1", "1000", "-999"),
        std::make_tuple("0", "12345", "-12345"),
        std::make_tuple("3", "9", "-6"),
        std::make_tuple("111", "222", "-111"),

        std::make_tuple("-123", "-456", "333"),    // -123 - (-456) = 333
        std::make_tuple("-789", "-456", "-333"),   // -789 - (-456) = -333
        std::make_tuple("-555", "-555", "0"),

        std::make_tuple("123", "-456", "579"),

        std::make_tuple("-123", "456", "-579")
    ),
    SubTestName
);
