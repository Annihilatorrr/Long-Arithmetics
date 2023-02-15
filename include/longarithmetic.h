#pragma once
#include <string>
#include "export.h" 
class LIBRARY_API LongArithmetic
{
    void reverse(char* result) const;
    void addReversedAndAssign(char* v1, const char* v2) const;
    void addUnsigned(const char* v1, const char* v2, char* result) const;
    void subUnsigned(const char* v1, const char* v2, char* result) const;
    void mulUnsigned(const char* v1, const char* v2, char* result) const;

public:
    void add(const char* v1, const char* v2, char* result) const;
    void sub(const char* v1, const char* v2, char* result) const;
    void mul(const char* v1, const char* v2, char* result) const;
    void pow(const char* v1, int n, char* result) const;
    int compare(const char* v1, const char* v2) const;
    void factorial(const char* v, char** result) const;

};

