#include "Class_BigInt.h"


//SECONDARY FUNCTIONS
std::vector <int> BigInt::from_string_to_vector(const std::string& str)
{
	std::vector <int> result;

	if (str.size() % base_length == 0)
		result.resize(str.size() / base_length);
	else
		result.resize(str.size() / base_length + 1);

	for (long long str_position = str.size() - 1, res_position = result.size() - 1; str_position >= 0; str_position = str_position - base_length, res_position = res_position - 1)
		if (((str_position + 1) - base_length) <= 0)
			result[res_position] = stoi(str.substr(0, str_position + 1));
		else
			result[res_position] = stoi(str.substr(str_position - base_length + 1, base_length));
	return result;
}


BigInt BigInt::l_add_cells(BigInt number, int count)
{
	if (number.digits.size() == 1 and number.digits[0] == 0)
		return number;
	number.digits.resize(number.digits.size() + count);
	return number;
}

BigInt BigInt::r_add_cells(BigInt number, int count)
{
	number.digits.reserve(count);
	for (int i = 0; i < count; i++)
		number.digits.insert(number.digits.begin(), 0);
	return number;
}

BigInt BigInt::remove_leading_zeroes(BigInt number)
{
	long long border = number.digits.size() - 1;
	for (int i = 0; i < number.digits.size() - 1; i = i + 1) {
		if (number.digits[i] != 0) {
			border = i;
			break;
		}
	}
	number.digits.erase(number.digits.begin(), number.digits.begin() + border);
	return number;
}

BigInt BigInt::multiply(BigInt first_number, BigInt second_number)
{
	BigInt result_number;
	result_number.digits.resize(first_number.digits.size() + second_number.digits.size());

	long long mod = 0;
	long long prev = 0;
	for (long long i = second_number.digits.size() - 1; i >= 0; i--)
	{
		for (long long j = first_number.digits.size() - 1; j >= 0; j--)
		{
			long long tmp = (long long)first_number.digits[j] * (long long)second_number.digits[i] + mod;

			prev = result_number.digits[i + j + 1];
			result_number.digits[i + j + 1] = (prev + tmp) % base;
			mod = (prev + tmp) / base;

			prev = result_number.digits[i + j];
			result_number.digits[i + j] = (prev + mod) % base;
			mod = (prev + mod) / base;
		}
	}
	if (mod != 0)
		result_number.digits[0] += mod;
	result_number = remove_leading_zeroes(result_number);
	return result_number;
}

BigInt BigInt::division(BigInt first_number, BigInt second_number, bool whats_return)
{
	BigInt result = 0;
	BigInt tmp = 1;
	first_number.sign = true;
	second_number.sign = true;

	while (first_number >= second_number)
	{
		result++;
		first_number = first_number - second_number;
	}
	if (whats_return == 0) //if 0 -- modulo, if 1 -- division result
		return first_number;
	else
		return result;

}

std::string BigInt::to_bin_positive(BigInt number)
{
	long long i = 0;
	BigInt power = 2;
	BigInt border = 0;
	std::vector <BigInt> powers_of_two;
	powers_of_two.push_back(1);
	while (powers_of_two[i] <= number)
	{
		powers_of_two.push_back(powers_of_two[i] * power);
		i++;
	}
	if (powers_of_two[i] > number)
	{
		powers_of_two.pop_back();
	}
	std::reverse(powers_of_two.begin(), powers_of_two.end());
	std::string binary;

	for (int i = 0; i < powers_of_two.size(); i++)
	{
		if ((number - powers_of_two[i]) >= border)
		{
			binary += '1';
			number -= powers_of_two[i];
		}
		else
			binary += '0';
	}
	powers_of_two.clear();
	return binary;
}

std::string BigInt::to_bin_negative(BigInt number)
{
	number.sign = true;
	long long i = 0;
	BigInt power = 2;
	BigInt border = 0;
	std::vector <BigInt> powers_of_two;
	powers_of_two.push_back(1);
	while (powers_of_two[i] <= number)
	{
		powers_of_two.push_back(powers_of_two[i] * power);
		i++;
	}
	if (powers_of_two[i] > number)
	{
		powers_of_two.pop_back();
	}
	std::reverse(powers_of_two.begin(), powers_of_two.end());
	std::string binary;

	for (int i = 0; i < powers_of_two.size(); i++)
	{
		if ((number - powers_of_two[i]) >= border)
		{
			binary += '0';
			number -= powers_of_two[i];
		}
		else
			binary += '1';
	}
	if (binary.back() == '0')
		binary.back() = '1';
	else
	{
		bool flag = 0;
		for (long long i = binary.size() - 1; i >= 0; i--)
		{
			if (binary[i] == '0')
			{
				binary[i] = '1';
				flag = 1;
				break;
			}
			else
				binary[i] = '0';
		}
		if (flag == 0)
			binary.insert(binary.begin(), '1');
	}

	powers_of_two.clear();
	return binary;
}
BigInt BigInt::to_dec_positive(std::string bin_number)
{
	bin_number = reverse(bin_number);
	BigInt dec_number = 0;
	BigInt tmp = 1;
	if (bin_number[0] == '1')
		dec_number += tmp;
	for (int i = 1; i < bin_number.size(); i++)
	{
		tmp *= 2;
		if (bin_number[i] == '1')
		{
			dec_number += tmp;
		}
	}

	return dec_number;
}
BigInt BigInt::to_dec_negative(std::string bin_number)
{
	bin_number = reverse(bin_number);
	BigInt dec_number = 0;
	BigInt tmp = 1;

	for (int i = 0; i < bin_number.size(); i++)
	{
		if (bin_number[i] == '1')
		{
			bin_number[i] = '0';
			break;
		}
		else
			bin_number[i] = '1';
	}

	for (int i = 0; i < bin_number.size(); i++)
	{
		if (bin_number[i] == '0')
			bin_number[i] = '1';
		else
			bin_number[i] = '0';
	}

	if (bin_number[0] == '1')
		dec_number += tmp;
	for (int i = 1; i < bin_number.size(); i++)
	{
		tmp *= 2;
		if (bin_number[i] == '1')
		{
			dec_number += tmp;
		}
	}
	dec_number.sign = false;
	return dec_number;
}
std::string reverse(std::string str)
{
	std::string reversed_str;
	for (long long i = str.size() - 1; i >= 0; i--)
		reversed_str += str[i];
	return reversed_str;
}



// CONSTRUCTORS
BigInt::BigInt()
{
	digits.resize(1);
	sign = true;
}

BigInt::BigInt(int num)
{
	std::string str = std::to_string(num);

	if (str.front() == '-')
	{
		str.erase(str.begin());
		sign = false;
	}
	else
		sign = true;

	digits = BigInt::from_string_to_vector(str);
}

BigInt::BigInt(std::string str)
{
	if (str.empty() or (str.size() == 1 and str[0] == '-'))
		throw std::invalid_argument("Invalid syntax. String doesn't contain a number.");

	if (str[0] == '-')
	{
		str.erase(str.begin());
		sign = false;
	}
	else
		sign = true;

	for (int str_position = 0; str_position < str.size(); str_position++)
		if (str[str_position] < '0' or str[str_position] > '9')
			throw std::invalid_argument("Invalid syntax. String contains unacceptable symbols.");

	while (str.size() != 1 and str[0] == '0')
		str.erase(str.begin());
	digits = BigInt::from_string_to_vector(str);
}

BigInt::BigInt(const BigInt& bnum)
{
	digits = bnum.digits;
	sign = bnum.sign;
}

BigInt::~BigInt()
{
	digits.clear();
}

std::ostream& operator <<(std::ostream& o, const BigInt& i)
{
	std::string str = std::string(i);
	for (int j = 0; j < str.size(); j++)
		o.put(str[j]);
	return o;
};

//UNARY OPERATORS

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


//BITWISE OPERATORS

BigInt operator ^(const BigInt& first_number, const BigInt& second_number)
{
	std::string first_bin_number;
	std::string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	std::string XORed;

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

	for (int i = 0; i < first_bin_number.size(); i++)
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
	std::string first_bin_number;
	std::string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	std::string ANDed;

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

	for (int i = 0; i < first_bin_number.size(); i++)
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
	std::string first_bin_number;
	std::string second_bin_number;

	if (first_number.sign == true)
		first_bin_number = BigInt::to_bin_positive(first_number);
	else
		first_bin_number = BigInt::to_bin_negative(first_number);

	if (second_number.sign == true)
		second_bin_number = BigInt::to_bin_positive(second_number);
	else
		second_bin_number = BigInt::to_bin_negative(second_number);

	std::string ORed;

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

	for (int i = 0; i < first_bin_number.size(); i++)
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

//ASSIGNMENT OPERATORS

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

//ARITHMETIC OPERATORS

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
		throw std::invalid_argument("Fatal error. Disivion by zero isn't possible.");

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
