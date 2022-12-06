#include "pch.h"
#include "../lab1_BigInt/Class_BigInt.h"

string first_number = "5943524289824899824";
string second_number = "403909023903";

BigInt firstBigInt = first_number;
BigInt secondBigInt = second_number;

TEST(TestCaseName, TestName) {
	string answ = "5943524693733923727";
	BigInt answer = answ;
	BigInt tmp = firstBigInt + secondBigInt;
	ASSERT_EQ(answer, tmp);
}