#ifndef BIGNUMBERSARITHEMATIC_HPP
#define BIGNUMBERSARITHEMATIC_HPP
#include <iostream>
#include <algorithm>
using namespace std;
class BigNumbersArithematic{
    public:
        string string_divisor(string, string);
        string string_remainder(string, string);
        string string_plus(string, string);
        string string_minus(string, string);
        string string_multiplication(string, string);
        string string_power(string, string);
        string string_max(string, string);
        string string_trimmer(string);
};
#endif