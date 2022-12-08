#include "Class_BigInt.h"

BigInt& BigInt::operator +=(const BigInt& number)
{
	return *this = *this + number;
}

BigInt& BigInt::operator *=(const BigInt& number)
{
	return *this = *this * number;
}

BigInt& BigInt::operator -=(const BigInt& number)
{
	return *this = *this - number;
}

BigInt& BigInt::operator /=(const BigInt& number)
{
	return *this = *this / number;
}

BigInt& BigInt::operator %=(const BigInt& number)
{
	return *this = *this % number;
}

BigInt& BigInt::operator ^=(const BigInt& number)
{
	return *this = *this ^ number;
}

BigInt& BigInt::operator &=(const BigInt& number)
{
	return *this = *this & number;
}

BigInt& BigInt::operator |=(const BigInt& number)
{
	return *this = *this | number;
}