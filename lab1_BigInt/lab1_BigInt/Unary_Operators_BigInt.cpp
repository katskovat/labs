#include "Class_BigInt.h"


BigInt& BigInt::operator++()
{
	BigInt tmp = 1;
	return (*this) = (*this) + tmp;
}

const BigInt BigInt::operator++(int)
{
	BigInt prev = (*this);
	BigInt tmp = 1;
	(*this) += tmp;
	return prev;
};

BigInt& BigInt::operator--()
{
	BigInt tmp = 1;
	return (*this) = (*this) - tmp;
}

const BigInt BigInt::operator--(int)
{
	BigInt prev = (*this);
	BigInt tmp = 1;
	(*this) -= tmp;
	return prev;
};
