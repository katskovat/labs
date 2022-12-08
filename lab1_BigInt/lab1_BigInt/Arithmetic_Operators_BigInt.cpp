#include "Class_BigInt.h"

BigInt operator +(const BigInt& number1, const BigInt& number2)
{
	BigInt first_number = number1;
	BigInt second_number = number2;
	if (first_number.sign == true and second_number.sign == false)
	{
		second_number.sign = true;
		return first_number - second_number;
	}

	if (first_number.sign == false and second_number.sign == true)
	{
		first_number.sign = true;
		return second_number - first_number;
	}

	if (first_number.sign == false and second_number.sign == false)
		second_number.sign = true;

	if (first_number.digits.size() < second_number.digits.size())
		first_number = BigInt::r_add_cells(first_number, second_number.digits.size() - first_number.digits.size());
	else
		second_number = BigInt::r_add_cells(second_number, first_number.digits.size() - second_number.digits.size());

	int sum = 0;
	int add_next_digit = 0;
	for (int i = first_number.digits.size() - 1; i >= 0; i--)
	{
		sum = first_number.digits[i] + second_number.digits[i] + add_next_digit;
		add_next_digit = sum / BigInt::base;
		first_number.digits[i] = sum % BigInt::base;
	}
	if (add_next_digit != 0)
		first_number.digits.insert(first_number.digits.begin(), add_next_digit);
	return first_number;
}

BigInt operator -(const BigInt& number1, const BigInt& number2)
{
	BigInt first_number = number1;
	BigInt second_number = number2;
	if (first_number.sign == true and second_number.sign == false)
	{
		second_number.sign = true;
		return first_number + second_number;
	}

	if (first_number.sign == false and second_number.sign == true)
	{
		first_number.sign = true;
		BigInt tmp_number = first_number + second_number;
		tmp_number.sign = false;
		return tmp_number;
	}

	if (first_number.sign == false and second_number.sign == false)
	{
		first_number.sign = true;
		second_number.sign = true;
		BigInt tmp = first_number;
		first_number = second_number;
		second_number = tmp;
	}

	if (first_number < second_number)
	{
		BigInt tmp = first_number;
		first_number = second_number;
		second_number = tmp;
		first_number.sign = false;
	}
	second_number = BigInt::r_add_cells(second_number, first_number.digits.size() - second_number.digits.size());
	long long difference = 0;

	for (long long i = first_number.digits.size() - 1; i >= 0; i--)
	{
		difference = (long long)first_number.digits[i] - (long long)second_number.digits[i];
		if (difference >= 0)
		{
			first_number.digits[i] = difference;
		}
		else
		{
			first_number.digits[i] = difference + BigInt::base;
			for (long long j = i - 1; true; j--)
				if (first_number.digits[j] == 0)
					first_number.digits[j] = BigInt::base - 1;
				else
				{
					first_number.digits[j] = first_number.digits[j] - 1;
					break;
				}
		}
	}
	return BigInt::remove_leading_zeroes(first_number);
}

BigInt operator *(const BigInt& number1, const BigInt& number2)
{
	BigInt first_number = number1;
	BigInt second_number = number2;

	BigInt result_number = BigInt::multiply(first_number, second_number);
	result_number.sign = (first_number.sign == second_number.sign);
	return result_number;
}

BigInt operator /(const BigInt& number1, const BigInt& number2)
{
	if (number2.digits.size() == 1 and number2.digits[0] == 0)
		throw invalid_argument("Fatal error. Disivion by zero isn't possible.");

	if (number1 == number2)
		return 1;

	if (number1.digits.size() < number2.digits.size())
		return 0;

	BigInt first_number = number1;
	BigInt second_number = number2;
	
	BigInt result = BigInt::division(first_number, second_number, 1);
	result.sign = (first_number.sign == second_number.sign);
	return result;
}

BigInt operator %(const BigInt& number1, const BigInt& number2)
{
	BigInt first_number = number1;
	BigInt second_number = number2;

	BigInt result = BigInt::division(first_number, second_number, 0);
	result.sign = (first_number.sign == second_number.sign);

	return result;
}