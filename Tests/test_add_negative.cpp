#include <gtest/gtest.h>
#include "longarithmetic.h"

TEST(LongArithmeticTests, AdditionOf2NegativeValues_0) {
    LongArithmetic la;
    std::string result = la.add("-123", "-456");
    EXPECT_STREQ(result.c_str(), "-579");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_1) {
    LongArithmetic la;
    std::string result = la.add("-12345", "-11");
    EXPECT_STREQ(result.c_str(), "-12356");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_2) {
    LongArithmetic la;
    std::string result = la.add("-12345", "-99");
    EXPECT_STREQ(result.c_str(), "-12444");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_3) {
    LongArithmetic la;
    std::string result = la.add("-12345", "-9");
    EXPECT_STREQ(result.c_str(), "-12354");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_4) {
    LongArithmetic la;
    std::string result = la.add("-11", "-12345");
    EXPECT_STREQ(result.c_str(), "-12356");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_5) {
    LongArithmetic la;
    std::string result = la.add("-9", "-12345");
    EXPECT_STREQ(result.c_str(), "-12354");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_6) {
    LongArithmetic la;
    std::string result = la.add("-9", "-9");
    EXPECT_STREQ(result.c_str(), "-18");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_7) {
    LongArithmetic la;
    std::string result = la.add("-9", "-0");
    EXPECT_STREQ(result.c_str(), "-9");
}


TEST(LongArithmeticTests, AdditionOf2NegativeValues_8) {
    LongArithmetic la;
    std::string result = la.add("-0", "-9");
    EXPECT_STREQ(result.c_str(), "-9");
}


TEST(LongArithmeticTests, AdditionOf2NegativeValues_9) {
    LongArithmetic la;
    std::string result = la.add("-99", "-0");
    EXPECT_STREQ(result.c_str(), "-99");
}


TEST(LongArithmeticTests, AdditionOf2NegativeValues_10) {
    LongArithmetic la;
    std::string result = la.add("-0", "-99");
    EXPECT_STREQ(result.c_str(), "-99");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_11) {
    LongArithmetic la;
    std::string result = la.add("-0", "-0");
    EXPECT_STREQ(result.c_str(), "0");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_12) {
    LongArithmetic la;
    std::string result = la.add("-5", "-4");
    EXPECT_STREQ(result.c_str(), "-9");
}

TEST(LongArithmeticTests, AdditionOf2NegativeValues_13) {
    LongArithmetic la;
    std::string result = la.add("-5", "-5");
    EXPECT_STREQ(result.c_str(), "-10");
}
