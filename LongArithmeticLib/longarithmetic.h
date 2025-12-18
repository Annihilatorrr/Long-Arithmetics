#pragma once
#include <string>
#include "export.h"
class LIBRARY_API LongArithmetic
{
    void reverse(char *result) const;
    void addReversedAndAssign(char *v1, const char *v2) const;
    std::string addUnsigned(const std::string &v1, const std::string &v2, bool negativeResult = false) const;
    std::string subUnsigned(const std::string &v1, const std::string &v2) const;
    std::string mulUnsigned(const std::string &v1, const std::string &v2) const;

public:
    std::string add(const std::string &v1, const std::string &v2) const;
    std::string sub(const std::string &v1, const std::string &v2) const;
    std::string mul(const std::string &v1, const std::string &v2) const;
    std::string pow(const std::string &v1, int n) const;
    int compare(const std::string &v1, const std::string &v2) const;
    std::string factorial(const std::string &value) const;
};
