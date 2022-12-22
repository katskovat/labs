#include "Class_BigInt.h"

BigInt operator ^(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number;
	string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	string XORed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);
	
	if (first_bin_number.size() != second_bin_number.size())
	{
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (first_number.sign == true)
					first_bin_number += '0';
				else
					first_bin_number += '1';
			}
		else
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (second_number.sign == true)
					second_bin_number += '0';
				else
					second_bin_number += '1';
			}
	}

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

	if (first_number.sign == second_number.sign)
		return BigInt::to_dec_positive(XORed);
	else
		return BigInt::to_dec_negative(XORed);
	
}

BigInt operator &(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number;
	string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	string ANDed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);

	if (first_bin_number.size() != second_bin_number.size())
	{
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (first_number.sign == true)
					first_bin_number += '0';
				else
					first_bin_number += '1';
			}
		else
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (second_number.sign == true)
					second_bin_number += '0';
				else
					second_bin_number += '1';
			}
	}

	for (long long i = 0; i < first_bin_number.size(); i++)
	{
		if (first_bin_number[i] == '1' and second_bin_number[i] == '1')
			ANDed += '1';
		else
			ANDed += '0';
	}
	ANDed = reverse(ANDed);

	if (first_number.sign == true or second_number.sign == true)
		return BigInt::to_dec_positive(ANDed);
	else
		return BigInt::to_dec_negative(ANDed);
}

BigInt operator |(const BigInt& first_number, const BigInt& second_number)
{
	string first_bin_number;
	string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	string ORed;

	first_bin_number = reverse(first_bin_number);
	second_bin_number = reverse(second_bin_number);

	if (first_bin_number.size() != second_bin_number.size())
	{
		if (first_bin_number.size() < second_bin_number.size())
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (first_number.sign == true)
					first_bin_number += '0';
				else
					first_bin_number += '1';
			}
		else
			while (first_bin_number.size() != second_bin_number.size())
			{
				if (second_number.sign == true)
					second_bin_number += '0';
				else
					second_bin_number += '1';
			}
	}

	for (long long i = 0; i < first_bin_number.size(); i++)
	{
		if (first_bin_number[i] == '1' or second_bin_number[i] == '1')
			ORed += '1';
		else
			ORed += '0';
	}
	ORed = reverse(ORed);

	if (first_number.sign == false or second_number.sign == false)
		return BigInt::to_dec_negative(ORed);
	else
		return BigInt::to_dec_positive(ORed);

}