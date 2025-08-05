#include "longarithmetic.h"

#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

static std::string stripLeadingZeros(const std::string& str) {
    size_t i = 0;
    while (i < str.length() && str[i] == '0') {
        ++i;
    }

    // Если остались цифры после нулей — вернём хвост
    if (i < str.length()) {
        return str.substr(i);
    }

    // Если были только нули — вернуть "0"
    return "0";
}


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

LIBRARY_API int LongArithmetic::compare(const std::string& v1, const std::string& v2) const
{
    // Обрабатываем знаки
    bool neg1 = (!v1.empty() && v1[0] == '-');
    bool neg2 = (!v2.empty() && v2[0] == '-');

    std::string num1 = neg1 ? v1.substr(1) : v1;
    std::string num2 = neg2 ? v2.substr(1) : v2;

    num1 = stripLeadingZeros(num1);
    num2 = stripLeadingZeros(num2);

    size_t len1 = num1.length();
    size_t len2 = num2.length();

    // Разные знаки: отрицательное всегда меньше положительного
    if (neg1 && !neg2) return -1;
    if (!neg1 && neg2) return 1;

    // Оба положительные или оба отрицательные
    int sign = neg1 ? -1 : 1;

    if (len1 > len2) return 1 * sign;
    if (len2 > len1) return -1 * sign;

    for (size_t i = 0; i < len1; ++i) {
        if (num1[i] > num2[i]) return 1 * sign;
        if (num1[i] < num2[i]) return -1 * sign;
    }

    return 0; // Равны
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

LIBRARY_API std::string LongArithmetic::add(const std::string& v1, const std::string& v2) const
{
    auto isNegative = [](const std::string& val) {
        return !val.empty() && val[0] == '-';
    };

    auto stripSign = [=](const std::string& val) {
        return isNegative(val) ? val.substr(1) : val;
    };

    auto normalizeZero = [](const std::string& result) {
        size_t start = (result[0] == '-') ? 1 : 0;
        for (size_t i = start; i < result.size(); ++i) {
            if (result[i] != '0')
                return result;
        }
        return std::string("0");
    };

    const bool neg1 = isNegative(v1);
    const bool neg2 = isNegative(v2);

    const std::string abs1 = stripSign(v1);
    const std::string abs2 = stripSign(v2);

    std::string result;

    // оба положительные
    if (!neg1 && !neg2) {
        result = addUnsigned(abs1, abs2);
    }
    // оба отрицательные
    else if (neg1 && neg2) {
        result = "-" + addUnsigned(abs1, abs2);
    }
    // v1 положительное, v2 отрицательное
    else if (!neg1 && neg2) {
        int cmp = compare(abs1, abs2);
        if (cmp >= 0)
            result = sub(abs1, abs2);
        else
            result = "-" + sub(abs2, abs1);
    }
    // v1 отрицательное, v2 положительное
    else {
        int cmp = compare(abs1, abs2);
        if (cmp > 0)
            result = "-" + sub(abs1, abs2);
        else
            result = sub(abs2, abs1);
    }

    return normalizeZero(result);
}



LIBRARY_API std::string LongArithmetic::sub(const std::string& v1, const std::string& v2) const 
{
    std::string result;

    // оба положительные
    if (v1[0] != '-' && v2[0] != '-') {
        int cmp = compare(v1, v2);
        if (cmp == 0) {
            result = "0";
        }
        else if (cmp < 0) {
            result = "-" + subUnsigned(v2, v1);
        }
        else {
            result = subUnsigned(v1, v2);
        }
    }
    // оба отрицательные
    else if (v1[0] == '-' && v2[0] == '-') {
        if (compare(v1.substr(1), v2.substr(1)) != 1) {
            result = subUnsigned(v2.substr(1), v1.substr(1));
        } else {
            result = "-" + subUnsigned(v1.substr(1), v2.substr(1));
        }
    }
    // v1 отрицательное, v2 положительное
    else if (v1[0] == '-' && v2[0] != '-') {
        result = "-" + addUnsigned(v1.substr(1), v2);
    }
    // v1 положительное, v2 отрицательное
    else if (v1[0] != '-' && v2[0] == '-') {
        result = addUnsigned(v1, v2.substr(1));
    }

    return result;
}


std::string LongArithmetic::mul(const std::string& v1, const std::string& v2) const {
    if (v1 == "0" || v2 == "0") return "0";

    bool neg1 = !v1.empty() && v1[0] == '-';
    bool neg2 = !v2.empty() && v2[0] == '-';
    bool isNegative = (neg1 != neg2);

    std::string abs1 = neg1 ? v1.substr(1) : v1;
    std::string abs2 = neg2 ? v2.substr(1) : v2;

    std::string result = mulUnsigned(abs1, abs2);

    if (isNegative && result != "0")
        result.insert(result.begin(), '-');

    return result;
}
// std::string LongArithmetic::factorial(const std::string& value) const
// {
//     std::string input = stripLeadingZeros(value);

//     if (input == "0" || input == "1") {
//         return "1";
//     }

//     std::string current = input;
//     std::string tempResult = input;
//     std::string next;
//     std::string result;

//     while (current != "1") {
//         subUnsigned(current, "1", next);              // next = current - 1
//         mulUnsigned(tempResult., next, result);        // result = tempResult * next
//         current = next;
//         tempResult = result;
//     }

//     return result;
// }

#include <string>
#include <memory>

LIBRARY_API std::string LongArithmetic::pow(const std::string& v1, int n) const
{
    if (n < 0)
        throw std::invalid_argument("Negative exponent not supported");

    if (n == 0)
        return "1";

    if (n == 1)
        return v1;

    std::string base = v1;
    bool isNegative = false;
    if (!base.empty() && base[0] == '-')
    {
        base.erase(0, 1);
        isNegative = true;
    }

    std::string result = "1";
    std::string current_base = base;
    int exponent = n;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = mul(result, current_base);

        current_base = mul(current_base, current_base);
        exponent /= 2;
    }

    if (isNegative && (n % 2 == 1))
        result = "-" + result;

    return result;
}




LIBRARY_API std::string LongArithmetic::subUnsigned(const std::string& v1, const std::string& v2) const
{
    std::string result;
    int carry = 0;

    int i = static_cast<int>(v1.length()) - 1;
    int j = static_cast<int>(v2.length()) - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = i >= 0 ? v1[i] - '0' : 0;
        int digit2 = j >= 0 ? v2[j] - '0' : 0;

        int res = digit1 - digit2 - carry;

        if (res < 0) {
            res += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(res + '0');
        --i;
        --j;
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return result;
}


std::string LongArithmetic::mulUnsigned(const std::string& v1, const std::string& v2) const {
    int n1 = v1.size();
    int n2 = v2.size();
    std::vector<int> res(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; --i) {
        int d1 = v1[i] - '0';
        int carry = 0;
        for (int j = n2 - 1; j >= 0; --j) {
            int d2 = v2[j] - '0';
            int sum = d1 * d2 + res[i + j + 1] + carry;
            carry = sum / 10;
            res[i + j + 1] = sum % 10;
        }
        res[i] += carry;
    }

    std::string result;
    bool leadingZero = true;
    for (int d : res) {
        if (d == 0 && leadingZero) continue;
        leadingZero = false;
        result.push_back('0' + d);
    }

    return result.empty() ? "0" : result;
}