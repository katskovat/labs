#include "Class_BigInt.h"

BigInt::BigInt()
{
	digits.resize(1);
	sign = true;
}

BigInt::BigInt(int num)
{
	string str = to_string(num);

	if (str.front() == '-')
	{
		str.erase(str.begin());
		sign = false;
	}
	else
		sign = true;

	digits = BigInt::from_string_to_vector(str);
}

BigInt::BigInt(string str)
{
	if (str.empty() or (str.size() == 1 and str[0] == '-')) 
		throw invalid_argument("Invalid syntax. String doesn't contain a number.");

	if (str[0] == '-')
	{
		str.erase(str.begin());
		sign = false;
	}
	else
		sign = true;

	for (int str_position = 0; str_position < str.size(); str_position++)
		if (str[str_position] < '0' or str[str_position] > '9')
			throw invalid_argument("Invalid syntax. String contains unacceptable symbols.");

	while (str.size() != 1 and str[0] == '0')
		str.erase(str.begin());
	digits = BigInt::from_string_to_vector(str);
}

BigInt::BigInt(const BigInt& bnum)
{
	//if (bnum.digits.empty())
		//throw invalid_argument("Invalid syntax. String doesn't contain a number.");
	digits = bnum.digits;
	sign = bnum.sign;
}

BigInt::~BigInt()
{
	digits.clear();
}

ostream& operator <<(ostream& o, const BigInt& i)
{
	string str = string(i);
	for (long long j = 0; j < str.size(); j++)
		o.put(str[j]);
	return o;
};