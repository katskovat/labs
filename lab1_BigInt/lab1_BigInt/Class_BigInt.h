#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

namespace BigNum {
    class BigInt {
    public:
        std::vector <int> digits;
        bool sign;
        static const int base = 1000000000;
        static const int base_length = 9;
        static const int max_len_for_default_multiply = 256;

        BigInt();
        BigInt(int);
        BigInt(std::string);
        BigInt(const BigInt&);
        ~BigInt();

        static std::vector <int> from_string_to_vector(const std::string& string);
        static BigInt remove_leading_zeroes(BigInt);
        static BigInt r_add_cells(BigInt, int);
        static BigInt l_add_cells(BigInt, int);
        static BigInt multiply(BigInt, BigInt);
        static BigInt division(BigInt, BigInt, bool);
        static std::string to_bin_positive(BigInt);
        static std::string to_bin_negative(BigInt);
        static BigInt to_dec_positive(std::string);
        static BigInt to_dec_negative(std::string);

        BigInt& operator=(const BigInt& number)
        {
            (*this).digits = number.digits;
            (*this).sign = number.sign;
            return (*this);
        };

        BigInt operator~() const
        {};

        BigInt& operator++();
        const BigInt operator++(int);
        BigInt& operator--();
        const BigInt operator--(int);

        BigInt& operator+=(const BigInt&);
        BigInt& operator*=(const BigInt&);
        BigInt& operator-=(const BigInt&);
        BigInt& operator/=(const BigInt&);
        BigInt& operator^=(const BigInt&);
        BigInt& operator%=(const BigInt&);
        BigInt& operator&=(const BigInt&);
        BigInt& operator|=(const BigInt&);

        BigInt operator+() const
        {
            return *this;
        };
        BigInt operator-() const
        {
            BigInt tmp = *this;
            tmp.sign = (false == (*this).sign);
            return tmp;
        };

        bool operator==(const BigInt& number) const;
        bool operator!=(const BigInt& number) const;
        bool operator>(const BigInt& number) const;
        bool operator<(const BigInt& number) const;
        bool operator<=(const BigInt& number) const;
        bool operator>=(const BigInt& number) const;

        operator int() const;

        operator std::string() const;

        int size() const
        {
            return sizeof(digits);
        };
    };

    BigInt operator+(const BigInt& number1, const BigInt& number2);
    BigInt operator-(const BigInt&, const BigInt&);
    BigInt operator*(const BigInt&, const BigInt&);
    BigInt operator/(const BigInt&, const BigInt&);
    BigInt operator^(const BigInt&, const BigInt&);
    BigInt operator%(const BigInt&, const BigInt&);
    BigInt operator&(const BigInt&, const BigInt&);
    BigInt operator|(const BigInt&, const BigInt&);

    std::ostream& operator <<(std::ostream& o, const BigInt& i);

   
}
