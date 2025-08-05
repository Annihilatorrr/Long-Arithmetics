// LongArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <cassert>
#include <cstring>
#include "longarithmetic.h"



int main()
{

    const char* v1 = "-5";
    const char* v2 = "-5";
    const LongArithmetic la;
    std::string resultw = la.add("0", "0");
    auto result = la.add(v1, v2);

    /*int s = -0100;
    int s2 =01777777777777777777700;
    std::cout << "Tests started" << std::endl;
    const char* v1 = "-12";
    const char* v2 = "-98";
    const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
    auto result = std::make_shared<char[]>(maxSize + 2);
    LongArithmetic la;
    la.pow(v1, 3, result.get());
    std::cout << "Answer: " << result << std::endl;*/
    
}

