// LongArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <cassert>
#include <cstring>
#include "Logger.h"
#include "longarithmetic.h"

int main()
{
    logger::setGlobalLogLevel(logger::LogLevel::Info);
    LOG_INFO(0, "Long-Arithmetics app: demo for big-integer operations (LongArithmeticLib).");
    LOG_INFO(0, "Build/run this app to try addition/subtraction/multiplication/power/factorial APIs.");

    const LongArithmetic arithmetic;
    const auto zeroSum = arithmetic.add("0", "0");
    LOG_INFO(0, "0 + 0 = %s", zeroSum.c_str());

    const char* v1 = "-5";
    const char* v2 = "-5";
    const auto sum = arithmetic.add(v1, v2);
    LOG_INFO(0, "%s + %s = %s", v1, v2, sum.c_str());
}
