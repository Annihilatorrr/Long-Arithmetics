#include "longarithmetic.h"

#include <iostream>
#include <memory>
#include <cstring>
LIBRARY_API std::string LongArithmetic::addUnsigned(const std::string& v1, const std::string& v2, bool negativeResult) const
{
    std::string result;
    result.reserve(std::max(v1.size(), v2.size()) + 1 + negativeResult ? 1 : 0); // максимум + 1 на перенос

    int carry = 0;
    int i = static_cast<int>(v1.size()) - 1;
    int j = static_cast<int>(v2.size()) - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0 && std::isdigit(v1[i])) ? v1[i] - '0' : 0;
        int digit2 = (j >= 0 && std::isdigit(v2[j])) ? v2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result.push_back(static_cast<char>((sum % 10) + '0'));
        carry = sum / 10;

        --i;
        --j;
    }

    if (negativeResult && result != "0")
    {
        result.push_back('-');
    }
    std::reverse(result.begin(), result.end());
    return result;
}

LIBRARY_API int LongArithmetic::compare(const char* v1, const char* v2) const
{
    if (strlen(v1) > strlen(v2))
    {
        return 1;
    }

    if (strlen(v2) > strlen(v1))
    {
        return -1;
    }

    for (int i = 0; i < strlen(v1); ++i)
    {
        if (v1[i] > v2[i])
        {
            return 1;
        }
        if (v1[i] < v2[i])
        {
            return -1;
        }
    }
    return 0;
}

LIBRARY_API void LongArithmetic::reverse(char* result) const
{
    const auto length = strlen(result);
    for (int i = 0; i < length / 2; ++i)
    {
        char tmp = result[i];
        result[i] = result[length - 1 - i];
        result[length - 1 - i] = tmp;
    }
}

LIBRARY_API void LongArithmetic::addReversedAndAssign(char* v1, const char* v2) const
{
    char* ptr1 = v1;
    const char* ptr2 = v2;
    unsigned char mem = 0;

    while (*ptr2 != 0)
    {
        unsigned char res = 0;
        if (ptr1 >= v1 && *ptr1 != 0)

        {
            res += (*ptr1) - 0x30;
        }

        if (ptr2 >= v2 && *ptr2 != 0)
        {
            res += (*ptr2) - 0x30;
        }

        res += mem;
        const char remainder = res % 10;
        *ptr1 = remainder + 0x30;
        ++ptr1;
        mem = res / 10;
        ++ptr2;
    }
    if (mem != 0)
    {
        *ptr1 = mem + 0x30;
    }
}

LIBRARY_API std::string LongArithmetic::add(const char* v1, const char* v2) const
{
    // both are positive
    if (v1[0] != '-' && v2[0] != '-')
    {
        return addUnsigned(v1, v2);
    }

    // both are negative
    else if (v1[0] == '-' && v2[0] == '-')
    {
        return addUnsigned(v1 + 1, v2 + 1, true);
    }

    // // positive and negative
    // else if (v1[0] != '-' && v2[0] == '-')
    // {
    //     if (compare(v1, v2 + 1) != -1)
    //     {
    //         sub(v1, v2 + 1, result);    
    //     }
    //     else
    //     {
    //         sub(v2 + 1, v1, result + 1);
    //         result[0] = '-';

    //     }
    // }

    // // negative and positive 
    // else if (v1[0] == '-' && v2[0] != '-')
    // {
    //     if (compare(v1 + 1, v2) != 1)
    //     {
    //         sub(v2, v1 + 1, result);
    //     }
    //     else
    //     {
    //         sub(v1 + 1, v2, result + 1);
    //         result[0] = '-';
    //     }
    // }
}

LIBRARY_API  void LongArithmetic::sub(const char* v1, const char* v2, char* result) const
{
    // both are positive
    if (v1[0] != '-' && v2[0] != '-')
    {
        // v1 <= v2
        if (compare(v1, v2) != 1)
        {
            subUnsigned(v2, v1, result + 1);
            result[0] = '-';

        }
        // v1 > v2
        else
        {
            subUnsigned(v1, v2, result);
        }
    }
    // both are negative
    if (v1[0] == '-' && v2[0] == '-')
    {
        // v1 <= v2
        if (compare(v1 + 1, v2 + 1) != 1)
        {
            subUnsigned(v2 + 1, v1 + 1, result);
        }
        // v1 > v2
        else
        {
            subUnsigned(v1 + 1, v2 + 1, result + 1);
            result[0] = '-';
        }
    }
    if (v1[0] == '-' && v2[0] != '-')
    {
        addUnsigned(v1 + 1, v2, result + 1);
        result[0] = '-';
    }

    if (v1[0] != '-' && v2[0] == '-')
    {
        addUnsigned(v1, v2 + 1, result);
    }
}

LIBRARY_API void LongArithmetic::mul(const char* v1, const char* v2, char* result) const
{
    // both are positive
    if ((v1[0] != '-' && v2[0] != '-'))
    {
        mulUnsigned(v1, v2, result);
    }
    //  or both are negative
    if (v1[0] == '-' && v2[0] == '-')
    {
        mulUnsigned(v1+1, v2+1, result);

    }

    if (v1[0] == '-' && v2[0] != '-')
    {
        mulUnsigned(v1 + 1, v2, result + 1);
        result[0] = '-';
    }
    if (v1[0] != '-' && v2[0] == '-')
    {
        mulUnsigned(v1, v2 + 1, result + 1);
        result[0] = '-';
    }
}

LIBRARY_API void LongArithmetic::factorial(const char* v, char** result) const
{
    const uint64_t maxSize = 5000000;

    *result = new char[maxSize + 1];
    memset(*result, 0, maxSize + 1);

    if (!strcmp(v, "0") || !strcmp(v, "1"))
    {
        (*result)[0] = '1';
        (*result)[1] = 0;
        return;
    }
    auto v1 = new char[maxSize + 1];
    memset(v1, 0, maxSize + 1);
    auto v2 = new char[maxSize + 1];
    memset(v2, 0, maxSize + 1);
    auto tempResult = new char[maxSize + 1];

    memcpy(v1, v, strlen(v) + 1);
    memcpy(tempResult, v1, strlen(v1) + 1);
    int iteration = 1;
    while(strcmp(v1, "1"))
    {
        //std::cout << iteration << std::endl;
        subUnsigned(v1, "1", v2);
        mulUnsigned(tempResult, v2, *result);
        std::swap(v1, v2);
        memcpy(tempResult, *result, strlen(*result) + 1);
        //++iteration;
    }

    delete[] v1;
    delete[] v2;
    delete[] tempResult;
    //const auto v2 = std::make_shared<char[]>(maxSize + 1);

}

LIBRARY_API void LongArithmetic::pow(const char* v1, int n, char* result) const
{
    if (n == 0)
    {
        result[0] = '1';
        result[1] = 0;
        return;
    }

    if (n == 1)
    {
        strcpy(result, v1);
        return;

    }
    auto temp = std::make_unique<char[]>(strlen(v1) * n);
    // both are positive
    if ((v1[0] != '-'))
    {
        strcpy(temp.get(), v1);
        for (int i = 2; i <= n; ++i)
        {
            mulUnsigned(v1, temp.get(), result);
            strcpy(temp.get(), result);
        }
    }

    //  or both are negative
    if (v1[0] == '-' && n % 2 == 0)
    {
        strcpy(temp.get(), v1+1);

        for (int i = 2; i <= n; ++i)
        {
            mulUnsigned(v1+1, temp.get(), result);
            strcpy(temp.get(), result);
        }

    }

    if (v1[0] == '-' && n % 2)
    {
        strcpy(temp.get(), v1 + 1);
        for (int i = 2; i <= n; ++i)
        {
            mulUnsigned(v1+1, temp.get(), result+1);
            strcpy(temp.get(), result+1);
        }
        result[0] = '-';
    }
}

LIBRARY_API void LongArithmetic::subUnsigned(const char* v1, const char* v2, char* result) const
{
    const char* ptr1 = v1 + strlen(v1) - 1;
    const char* ptr2 = v2 + strlen(v2) - 1;
    char* resultPtr = result;
    char carry = 0;
    while (ptr1 >= v1 || ptr2 >= v2)
    {
        char value1 = ptr1 >= v1 ? (*ptr1) - '0' : 0;
        char value2 = ptr2 >= v2 ? (*ptr2) - '0' : 0;   
        int res = 0;
        if ((value1 - (value2 + carry)) < 0)
        {
            res = value1 + 10 - value2 - carry;
            carry = 1;
        }
        else
        {
            res = value1 - value2 - carry;
            carry = 0;
        }
        *resultPtr = res + '0';
        --ptr1;
        --ptr2;
        ++resultPtr;

    }
    char* iterator = nullptr;
    for (int i = strlen(result) - 1; i >= 0; --i)
    {
        if (result[i] != '0')
        {
            iterator = result + i;
            break;
        }
    }
    if (!iterator)
    {
        result[1] = 0;
        return;
    }

    *(iterator + 1) = 0;
    reverse(result);
}

LIBRARY_API void LongArithmetic::mulUnsigned(const char* v1, const char* v2, char* result) const
{
    const char* ptrV1 = v1 + strlen(v1) - 1;
    const char* ptrV2 = v2 + strlen(v2) - 1;
    memset(result, '0', strlen(result));
    char* tempResult = new char[strlen(v1) + strlen(v2) + sizeof('\0')];
    char* tempResultPtr = tempResult;

    int offset = 0;
    while (v2 <= ptrV2)
    {
        const int digitV2 = (*ptrV2) - 48;
        int mem = 0;
        while (v1 <= ptrV1) {
            const int digitV1 = (*ptrV1) - 48;
            int res = mem + digitV1 * digitV2;
            mem = res / 10;
            const int remainder = res % 10;
            *tempResultPtr = static_cast<char>(remainder + 48);
            --ptrV1;
            ++tempResultPtr;
        }
        if (mem != 0)
        {
            *tempResultPtr = static_cast<char>(mem + 48);
            ++tempResultPtr;
        }

        *tempResultPtr = '\0';

        addReversedAndAssign(result, tempResult);
        memset(tempResult, '0', strlen(tempResult));

        ++offset;
        tempResultPtr = tempResult + offset;
        --ptrV2;
        ptrV1 = v1 + strlen(v1) - 1;
    }
    delete[] tempResult;

    char* iterator = nullptr;
    for (int i = strlen(result) - 1; i >= 0; --i)
    {
        if (result[i] != '0')
        {
            iterator = result + i;
            break;
        }
    }
    if (!iterator)
    {
        result[1] = 0;
        return;
    }

    *(iterator + 1) = 0;
    reverse(result);
}
