#include <gtest/gtest.h>
#include "longarithmetic.h"

class LongArithmeticMultiplicationTest
    : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {
protected:
    LongArithmetic la;
};

TEST_P(LongArithmeticMultiplicationTest, Multiply) {
    auto [a, b, expected] = GetParam();
    EXPECT_EQ(la.mul(a, b), expected);
}

std::string MulTestName(
    const ::testing::TestParamInfo<LongArithmeticMultiplicationTest::ParamType>& info) {
    auto [a, b, expected] = info.param;
    std::string name = "Mul_" + a + "_x_" + b + "_eq_" + expected;
    for (char& c : name) if (!isalnum(static_cast<unsigned char>(c))) c = '_';
    return name;
}

INSTANTIATE_TEST_SUITE_P(
    MultiplicationCases,
    LongArithmeticMultiplicationTest,
    ::testing::Values(

        std::make_tuple("0", "0", "0"),
        std::make_tuple("0", "5", "0"),
        std::make_tuple("0", "-5", "0"),
        std::make_tuple("5", "0", "0"),
        std::make_tuple("-5", "0", "0"),
        std::make_tuple("-0", "5", "0"),
        std::make_tuple("-0", "-5", "0"),
        std::make_tuple("5", "-0", "0"),
        std::make_tuple("-5", "-0", "0"),

        std::make_tuple("2", "123", "246"),
        std::make_tuple("-2", "123", "-246"),
        std::make_tuple("2", "-123", "-246"),
        std::make_tuple("-2", "-123", "246"),

        std::make_tuple("45", "7", "315"),
        std::make_tuple("-45", "7", "-315"),
        std::make_tuple("45", "-7", "-315"),
        std::make_tuple("-45", "-7", "315"),

        std::make_tuple("9", "8765", "78885"),
        std::make_tuple("-9", "8765", "-78885"),
        std::make_tuple("9", "-8765", "-78885"),
        std::make_tuple("-9", "-8765", "78885"),

        std::make_tuple("12", "34", "408"),
        std::make_tuple("-12", "34", "-408"),
        std::make_tuple("12", "-34", "-408"),
        std::make_tuple("-12", "-34", "408"),

        std::make_tuple("99", "99", "9801"),
        std::make_tuple("-99", "99", "-9801"),
        std::make_tuple("99", "-99", "-9801"),
        std::make_tuple("-99", "-99", "9801"),

        std::make_tuple("1234", "5678", "7006652"),
        std::make_tuple("-1234", "5678", "-7006652"),
        std::make_tuple("1234", "-5678", "-7006652"),
        std::make_tuple("-1234", "-5678", "7006652"),

        std::make_tuple("123456", "654321", "80779853376"),
        std::make_tuple("-123456", "654321", "-80779853376"),
        std::make_tuple("123456", "-654321", "-80779853376"),
        std::make_tuple("-123456", "-654321", "80779853376"),

        std::make_tuple("123456789", "987654321", "121932631112635269"),
        std::make_tuple("-123456789", "987654321", "-121932631112635269"),
        std::make_tuple("123456789", "-987654321", "-121932631112635269"),
        std::make_tuple("-123456789", "-987654321", "121932631112635269")
    ),
    MulTestName
);
