#include "Class_BigInt.h"

vector <int> BigInt::from_string_to_vector(const string& str)
{
	vector <int> result;

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
	for (long long i = 0; i < number.digits.size() - 1; i = i + 1) {
		if (number.digits[i] != 0) {
			border = i;
			break;
		}
	}
	number.digits.erase(number.digits.begin(), number.digits.begin() + border);
	return number;
}

BigInt BigInt::max(BigInt first_number, BigInt second_number)
{
	if (first_number > second_number)
		return first_number;
	return second_number;
}
BigInt BigInt::min(BigInt first_number, BigInt second_number)
{
	if (first_number < second_number)
		return first_number;
	return second_number;
}

long long BigInt::size(BigInt number)
{
	return (number.digits.size() - 1) * base_length + to_string(number.digits.front()).size();
}

BigInt BigInt::abs(BigInt number)
{
	number.sign = true;
	return number;
}

bool BigInt::even(BigInt number)
{
	if (number.digits.back() % 2 == 0)
		return true;
	return false;
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

string BigInt::to_bin_positive(BigInt number)
{
	long long i = 0;
	BigInt power = 2;
	BigInt border = 0;
	vector <BigInt> powers_of_two;
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
	string binary;

	for (long long i = 0; i < powers_of_two.size(); i++)
	{
		if ((number - powers_of_two[i]) >= border)
		{
			binary += '1';
			number -= powers_of_two[i];
		}
		else
			binary += '0';
	}
	//while (binary.size() != powers_of_two.size())
		//binary += '0';
	powers_of_two.clear();
	return binary;
}

string BigInt::to_bin_negative(BigInt number)
{
	number.sign = true;
	long long i = 0;
	BigInt power = 2;
	BigInt border = 0;
	vector <BigInt> powers_of_two;
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
	string binary;

	for (long long i = 0; i < powers_of_two.size(); i++)
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

	//while (binary.front() == '0')
		//binary.erase(0, 1);

	powers_of_two.clear();
	return binary;
}
BigInt BigInt::to_dec_positive(string bin_number)
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
BigInt BigInt::to_dec_negative(string bin_number)
{
	bin_number = reverse(bin_number);
	BigInt dec_number = 0;
	BigInt tmp = 1;

	for (long long i = 0; i < bin_number.size(); i++)
	{
		if (bin_number[i] == '1')
		{
			bin_number[i] = '0';
			break;
		}
		else
			bin_number[i] = '1';
	}

	for (long long i = 0; i < bin_number.size(); i++)
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
string reverse(string str)
{
	string reversed_str;
	for (long long i = str.size() - 1; i >= 0; i--)
		reversed_str += str[i];
	return reversed_str;
}
