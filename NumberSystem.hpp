#ifndef NUMBERSYSTEM_HPP
#define NUMBERSYSTEM_HPP
#include "BigNumbersArithematic.hpp"
class Number_System : public BigNumbersArithematic{
    public:
        string number, numbercopy,result;
        void dtob();
        void dtoh();
        void dtoo();
        void btod();
        void otod();
        void htod();
        void btoo();
        void btoh();
        void otob();
        void otoh();
        void htob();
        void htoo();
        bool is_decimal();
        bool is_binary();
        bool is_octal();
        bool is_hexadecimal();
};
#endif