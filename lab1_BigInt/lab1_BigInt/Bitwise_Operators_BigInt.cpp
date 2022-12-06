#include "Class_BigInt.h"

BigInt operator ^(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number = BigInt::to_bin(first_number);
	string second_bin_number = BigInt::to_bin(second_number);
	string XORed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);
	
	if (first_bin_number.size() != second_bin_number.size())
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
				first_bin_number += '0';
		else
			while (first_bin_number.size() != second_bin_number.size())
				second_bin_number += '0';

	for (long long i = 0; i < first_bin_number.size(); i++)
	{
		if (first_bin_number[i] == '0' and second_bin_number[i] == '1')
			XORed += '1';
		else
			if (first_bin_number[i] == '1' and second_bin_number[i] == '0')
				XORed += '1';
			else
				XORed += '0';
	}
	XORed = reverse(XORed);
	return BigInt::to_dec(XORed);
}

BigInt operator &(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number = BigInt::to_bin(first_number);
	string second_bin_number = BigInt::to_bin(second_number);

	string ANDed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);

	if (first_bin_number.size() != second_bin_number.size())
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
				first_bin_number += '0';
		else
			while (first_bin_number.size() != second_bin_number.size())
				second_bin_number += '0';

	for (long long i = 0; i < first_bin_number.size(); i++)
	{
		if (first_bin_number[i] == '1' and second_bin_number[i] == '1')
			ANDed += '1';
		else
			ANDed += '0';
	}
	ANDed = reverse(ANDed);
	return BigInt::to_dec(ANDed);
}

BigInt operator |(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number = BigInt::to_bin(first_number);
	string second_bin_number = BigInt::to_bin(second_number);

	string ORed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);

	if (first_bin_number.size() != second_bin_number.size())
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
				first_bin_number += '0';
		else
			while (first_bin_number.size() != second_bin_number.size())
				second_bin_number += '0';

	for (long long i = 0; i < first_bin_number.size(); i++)
	{
		if (first_bin_number[i] == '1' or second_bin_number[i] == '1')
			ORed += '1';
		else
			ORed += '0';
	}
	ORed = reverse(ORed);
	return BigInt::to_dec(ORed);
}