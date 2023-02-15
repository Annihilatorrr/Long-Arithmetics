// LongArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <cassert>
#include "longarithmetic.h"

void testAdd()
{
    {
        const char* v1 = "-999";
        const char* v2 = "-98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-1097"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "-999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-1097"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("1097"));
    }

    {
        const char* v1 = "1";
        const char* v2 = "999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("1000"));
    }

    {
        const char* v1 = "-999";
        const char* v2 = "98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-901"));
    }

    {
        const char* v1 = "98";
        const char* v2 = "-999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-901"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("901"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "-98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.add(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("901"));
    }
}

void testSub()
{
    {
        const char* v1 = "-999";
        const char* v2 = "-999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("0"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "-999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("901"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("901"));
    }

    {
        const char* v1 = "1";
        const char* v2 = "999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-998"));
    }

    {
        const char* v1 = "-999";
        const char* v2 = "98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-1097"));
    }

    {
        const char* v1 = "98";
        const char* v2 = "-999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("1097"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "999";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-1097"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "-98";
        const uint64_t maxSize = std::max(strlen(v1), strlen(v2));
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.sub(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("1097"));
    }
}

void testMul()
{
    {
        const char* v1 = "-999";
        const char* v2 = "-98";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("97902"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "-999";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 3);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("97902"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "98";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("97902"));
    }

    {
        const char* v1 = "1";
        const char* v2 = "999";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("999"));
    }
    {
        const char* v1 = "123456789012345678901234567890";
        const char* v2 = "123456789012345678901234567890";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("15241578753238836750495351562536198787501905199875019052100"));
    }

    {
        const char* v1 = "-999";
        const char* v2 = "98";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-97902"));
    }

    {
        const char* v1 = "98";
        const char* v2 = "-999";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-97902"));
    }

    {
        const char* v1 = "-98";
        const char* v2 = "999";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-97902"));
    }

    {
        const char* v1 = "999";
        const char* v2 = "-98";
        const uint64_t maxSize = strlen(v1) + strlen(v2) + 3;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.mul(v1, v2, result.get());
        assert(std::string(result.get()) == std::string("-97902"));
    }
}

void testPower()
{
    {
        const char* v1 = "-50";
        const int n = 0;
        const uint64_t maxSize = strlen(v1) * n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("1"));
    }

    {
        const char* v1 = "-50";
        const int n = 1;
        const uint64_t maxSize = strlen(v1)*n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("-50"));
    }

    {
        const char* v1 = "-50";
        const int n = 2;
        const uint64_t maxSize = strlen(v1) * n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("2500"));
    }

    {
        const char* v1 = "-50";
        const int n = 3;
        const uint64_t maxSize = strlen(v1) * n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("-125000"));
    }

    {
        const char* v1 = "-12";
        const int n = 4;
        const uint64_t maxSize = strlen(v1) * n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("20736"));
    }
    {
        const char* v1 = "1234567";
        const int n = 7;
        const uint64_t maxSize = strlen(v1) * n;
        const auto result = std::make_shared<char[]>(maxSize + 2);
        const LongArithmetic la;
        la.pow(v1, n, result.get());
        assert(std::string(result.get()) == std::string("4371219837658380601508594259852871941768823"));
    }
}

void testFactorial()
{
    {
        const char* v1 = "10";
        const int n = 0;
        const uint64_t maxSize = 5000000;
        char* result = nullptr;
        const LongArithmetic la;
        la.factorial(v1, &result);
        assert(std::string(result) == std::string("3628800"));
    }
    {
        const char* v1 = "100";
        const int n = 0;
        char* result = nullptr;
        const LongArithmetic la;
        la.factorial(v1, &result);
        assert(std::string(result) == std::string("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000"));
    }
    {
        const char* v1 = "1";
        const int n = 0;
        char* result = nullptr;
        const LongArithmetic la;
        la.factorial(v1, &result);
        assert(std::string(result) == std::string("1"));
    }
    {
        const char* v1 = "0";
        const int n = 0;
        char* result = nullptr;
        const LongArithmetic la;
        la.factorial(v1, &result);
        assert(std::string(result) == std::string("1"));
    }
}
int main()
{

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
    testAdd();
    testFactorial();
    testSub();
    testMul();
    testPower();
    std::cout << "Tests ended" << std::endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
