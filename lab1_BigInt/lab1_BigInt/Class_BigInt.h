#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class BigInt {
public:
    vector <int> digits;
    bool sign;
    static const int base = 1000000000;
    static const int base_length = 9;
    static const int max_len_for_default_multiply = 256;

    BigInt();
    BigInt(int);
    BigInt(std::string); // бросать исключение std::invalid_argument при ошибке
    BigInt(const BigInt&);
    ~BigInt();

    static vector <int> from_string_to_vector(const string& string);
    static BigInt remove_leading_zeroes(BigInt);
    static BigInt r_add_cells(BigInt, int);
    static BigInt l_add_cells(BigInt, int);
    static BigInt max(BigInt, BigInt);
    static BigInt min(BigInt, BigInt);
    static long long size(BigInt);
    static BigInt abs(BigInt);
    static bool even(BigInt);
    static BigInt multiply(BigInt, BigInt);
    static BigInt division(BigInt, BigInt, bool);
    static string to_bin_positive(BigInt);
    static string to_bin_negative(BigInt);
    static BigInt to_dec_positive(string);
    static BigInt to_dec_negative(string);

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

    bool operator==(const BigInt& number) const
    {
        if ((*this).sign != number.sign)
            return false;

        if ((*this).digits.size() != number.digits.size())
            return false;

        for (int i = 0; i < number.digits.size(); i++)
            if ((*this).digits[i] != number.digits[i])
                return false;

        return true;
    };
    bool operator!=(const BigInt& number) const
    {
        return !((*this) == number);
    };
    bool operator>(const BigInt& number) const
    {
        if ((*this)  == number)
            return false;

        if ((*this).sign == false && number.sign == true)
            return false;
        if ((*this).sign == true && number.sign == false)
            return true;

        if ((*this).sign == true)
        {
            if ((*this).digits.size() < number.digits.size())
                return false;
            if ((*this).digits.size() > number.digits.size())
                return true;
            for (long long i = 0; i < (*this).digits.size(); i++)
            {
                if ((*this).digits[i] > number.digits[i])
                    return true;
                if ((*this).digits[i] < number.digits[i])
                    return false;
            }
            return true;
        }

        if ((*this).sign == false)
        {
            if ((*this).digits.size() < number.digits.size())
                return true;
            if ((*this).digits.size() > number.digits.size())
                return false;
            for (long long i = 0; i < (*this).digits.size(); i++)
                if ((*this).digits[i] > number.digits.size())
                    return false;
            return true;
        }
    };
    bool operator<(const BigInt& number) const
    {
        if ((*this) != number && !((*this) > number))
            return true;
        return false;
    };
    bool operator<=(const BigInt& number) const
    {
        if ((*this) < number || (*this) == number)
            return true;
        return false;
    };
    bool operator>=(const BigInt& number) const
    {
        if ((*this) > number || (*this) == number)
            return true;
        return false;
    };

    operator int() const
    {
        if ((*this).digits.size() > 2)
            throw invalid_argument("Too big number. Cannot be converted to int.");
        if ((*this).digits.size() == 2)
            if ((*this).digits[0] > 2)
                throw invalid_argument("Too big number. Cannot be converted to int.");
            else
                if (((*this).digits[1] > 147483647 && (*this).sign == true) || ((*this).digits[1] > 147483648 && (*this).sign == false))
                    throw invalid_argument("Too big number. Cannot be converted to int.");
        int iteration = 0;
        int number = 0;
        for (int i = (*this).digits.size() - 1; i >= 0; i--)
        {
            if (iteration == 0)
            {
                number += (*this).digits[i];
                iteration++;
            }
            else
                number += (*this).digits[i] * base;
        }
        if ((*this).sign == true)
            return number;
        else
            return -number;
    };

    operator std::string() const
    {
        string str;
        if ((*this).sign == false && (*this).digits.front() != 0)
            str += '-';
        str += to_string((*this).digits[0]);
        for (int j = 1; j < (*this).digits.size(); j++)
        {
            int len = 0;
            int num = (*this).digits[j];
            while (num > 0)
            {
                num /= 10;
                len++;
            }
            while (len != 9)
            {
                str += '0';
                len++;
            }
            str += to_string((*this).digits[j]);
        }
        return str;
    };
    
    size_t size() const
    {
        return sizeof(digits);
    };
};

BigInt operator+(const BigInt&, const BigInt&); //
BigInt operator-(const BigInt&, const BigInt&); //
BigInt operator*(const BigInt&, const BigInt&); //
BigInt operator/(const BigInt&, const BigInt&); //exeption 
BigInt operator^(const BigInt&, const BigInt&); //
BigInt operator%(const BigInt&, const BigInt&); //
BigInt operator&(const BigInt&, const BigInt&); //
BigInt operator|(const BigInt&, const BigInt&); //

ostream& operator <<(ostream& o, const BigInt& i);

string reverse(string);