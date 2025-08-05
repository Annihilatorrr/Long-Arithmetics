#include <gtest/gtest.h>
#include "longarithmetic.h"

struct CompareTestCase {
    std::string lhs;
    std::string rhs;
    int expected; // -1, 0, 1
};

inline void PrintTo(const CompareTestCase& param, std::ostream* os) {
    *os << "(\"" << param.lhs << "\", \"" << param.rhs << "\", expected=" << param.expected << ")";
}

class LongArithmeticComparisonTest
    : public ::testing::TestWithParam<CompareTestCase> {};

TEST_P(LongArithmeticComparisonTest, CompareValues) {
    LongArithmetic la;
    auto param = GetParam();
    int result = la.compare(param.lhs.c_str(), param.rhs.c_str());
    EXPECT_EQ(result, param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllCases,
    LongArithmeticComparisonTest,
    ::testing::Values(
        // Positive vs Positive
        CompareTestCase{"123", "456", -1},
        CompareTestCase{"123", "123", 0},
        CompareTestCase{"456", "123", 1},
        CompareTestCase{"12", "123", -1},
        CompareTestCase{"2", "123", -1},
        CompareTestCase{"123", "12", 1},
        CompareTestCase{"123", "2", 1},

        // Negative vs Negative
        CompareTestCase{"-123", "-456", 1},
        CompareTestCase{"-123", "-123", 0},
        CompareTestCase{"-456", "-123", -1},
        CompareTestCase{"-12", "-123", 1},
        CompareTestCase{"-2", "-123", 1},
        CompareTestCase{"-123", "-12", -1},
        CompareTestCase{"-123", "-2", -1},

        // Negative vs Positive
        CompareTestCase{"-123", "12", -1},
        CompareTestCase{"-123", "123", -1},

        // Positive vs Negative
        CompareTestCase{"123", "-2", 1}
    )
);
