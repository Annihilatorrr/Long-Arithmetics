#include <gtest/gtest.h>
#include "longarithmetic.h"

#include <stdexcept>
#include <string>

TEST(LongArithmeticInvalidInputTest, RejectsMalformedOperands)
{
    const LongArithmetic arithmetic;
    const std::string invalidOperands[] = {
        "", "-", "1x", "+3", "--1", " 3", "3 ", std::string("1\0", 2), "\xFF",
    };

    for (const auto &operand : invalidOperands)
    {
        SCOPED_TRACE(::testing::PrintToString(operand));
        EXPECT_THROW(arithmetic.add(operand, "1"), std::invalid_argument);
        EXPECT_THROW(arithmetic.add("1", operand), std::invalid_argument);
        EXPECT_THROW(arithmetic.sub(operand, "1"), std::invalid_argument);
        EXPECT_THROW(arithmetic.sub("1", operand), std::invalid_argument);
        EXPECT_THROW(arithmetic.mul(operand, "0"), std::invalid_argument);
        EXPECT_THROW(arithmetic.mul("0", operand), std::invalid_argument);
        EXPECT_THROW(arithmetic.compare(operand, "1"), std::invalid_argument);
        EXPECT_THROW(arithmetic.compare("1", operand), std::invalid_argument);
        EXPECT_THROW(arithmetic.pow(operand, 0), std::invalid_argument);
        EXPECT_THROW(arithmetic.pow(operand, 1), std::invalid_argument);
        EXPECT_THROW(arithmetic.pow(operand, 2), std::invalid_argument);
        EXPECT_THROW(arithmetic.factorial(operand), std::invalid_argument);
    }
}
