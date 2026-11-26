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

    const char* v1 = "-5";
    const char* v2 = "-5";
    const LongArithmetic la;
    std::string resultw = la.add("0", "0");
    auto result = la.add(v1, v2);
}
