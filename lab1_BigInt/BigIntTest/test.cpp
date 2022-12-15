#include "pch.h"
#include "../lab1_BigInt/Class_BigInt.h"

BigInt first_number = BigInt("5943524289824899824");
BigInt second_number = BigInt("403909023903");
BigInt third_number = BigInt("645");
BigInt fourth_number = BigInt("100000000000000000000");
BigInt fifth_number = BigInt("3");

BigInt first_negative_number = BigInt("-5943524289824899824");
BigInt second_negative_number = BigInt("-403909023903");
BigInt third_negative_number = BigInt("-645");
BigInt fourth_negavite_number = BigInt("-100000000000000000000");
BigInt fifth_negative_number = BigInt("3");

BigInt zero_number = BigInt("0");
BigInt one_number = BigInt("1");

// +
TEST(SumBigInt1, TestName) { //5943524289824899824 + 403909023903
	BigInt answer = BigInt("5943524693733923727");
	BigInt tmp = first_number + second_number;
	ASSERT_EQ(answer, tmp);
}

TEST(SumBigInt2, TestName) { //100000000000000000000 + 645
	BigInt answer = BigInt("100000000000000000645");
	BigInt tmp = fourth_number + third_number;
	ASSERT_EQ(answer, tmp);
}

TEST(SumBigInt3, TestName) { //5943524289824899824 + -403909023903
	BigInt answer = BigInt("5943523885915875921");
	BigInt tmp = first_number + second_negative_number;
	ASSERT_EQ(answer, tmp);
}

// -

TEST(DiffBigInt1, TestName) { //5943524289824899824 - 5943524289824899824
	BigInt answer = BigInt("0");
	BigInt tmp = first_number - first_number;
	ASSERT_EQ(answer, tmp);
}

TEST(DiffBigInt2, TestName) { //5943524289824899824 - 403909023903
	BigInt answer = BigInt("5943523885915875921");
	BigInt tmp = first_number - second_number;
	ASSERT_EQ(answer, tmp);
}

TEST(DiffBigInt3, TestName) { //100000000000000000000 - -645
	BigInt answer = BigInt("100000000000000000645");
	BigInt tmp = fourth_number - third_negative_number;
	ASSERT_EQ(answer, tmp);
}

// *

TEST(MulBigInt1, TestName) { //5943524289824899824 * 403909023903
	BigInt answer = BigInt("2400643094446946562696596493072");
	BigInt tmp = first_number * second_number;
	ASSERT_EQ(answer, tmp);
}

TEST(MulBigInt2, TestName) { //5943524289824899824 * -403909023903
	BigInt answer = BigInt("-2400643094446946562696596493072");
	BigInt tmp = first_number * second_negative_number;
	ASSERT_EQ(answer, tmp);
}

TEST(MulBigInt3, TestName) { //-5943524289824899824 * -100000000000000000000
	BigInt answer = BigInt("594352428982489982400000000000000000000");
	BigInt tmp = first_negative_number * fourth_negavite_number;
	ASSERT_EQ(answer, tmp);
}

// /
TEST(Div1, TestName) { //-5943524289824899824 * -100000000000000000000
	BigInt number1 = BigInt("5943524289824899824");
	BigInt number2 = BigInt("403909023903345");
	BigInt tmp = number1 / number2;
	BigInt answer = BigInt("14715");
	ASSERT_EQ(answer, tmp);
}

TEST(Div2, TestName) { //-5943524289824899824 * -100000000000000000000
	BigInt number1 = BigInt("5943524289824899824");
	BigInt number2 = BigInt("-403909023903345");
	BigInt tmp = number1 / number2;
	BigInt answer = BigInt("-14715");
	ASSERT_EQ(answer, tmp);
}

TEST(Div3, TestName) { //-5943524289824899824 * -100000000000000000000
	BigInt answer = BigInt("16");
	BigInt tmp = fourth_number / first_number;
	ASSERT_EQ(answer, tmp);
}

// ^

TEST(XOR1, TestName) { //5943524289824899824 ^ 403909023903
	BigInt answer = BigInt("5943523937524767343");
	BigInt tmp = first_number ^ second_number;
	ASSERT_EQ(answer, tmp);
}

// |

TEST(OR1, TestName) { //5943524289824899824 | 403909023903
	BigInt answer = BigInt("5943524315629345535");
	BigInt tmp = first_number | second_number;
	ASSERT_EQ(answer, tmp);
}

// &
TEST(AND, TestName) { //5943524289824899824 & 403909023903
	BigInt answer = BigInt("378104578192");
	BigInt tmp = first_number & second_number;
	ASSERT_EQ(answer, tmp);
}

// =
TEST(Assign1, TestName) { 
	BigInt answer = first_number;
	ASSERT_EQ(answer, first_number);
}

TEST(Assign2, TestName) {
	BigInt answer = first_negative_number;
	ASSERT_EQ(answer, first_negative_number);
}

// ++(int)

TEST(Unary1PlusPlus, TestName) { 
	BigInt answer = BigInt("5943524289824899825");
	BigInt number = BigInt("5943524289824899824");
	number++;
	ASSERT_EQ(answer, number);
}

TEST(Unary2PlusPlus, TestName) {
	BigInt answer = BigInt("-5943524289824899823");
	BigInt number = BigInt("-5943524289824899824");
	number++;
	ASSERT_EQ(answer, number);
}

// ++

TEST(UnaryPlusPlus1, TestName) {
	BigInt answer = BigInt("5943524289824899825");
	BigInt number = BigInt("5943524289824899824");
	++number;
	ASSERT_EQ(answer, number);
}

TEST(UnaryPlusPlus2, TestName) {
	BigInt answer = BigInt("-5943524289824899823");
	BigInt number = BigInt("-5943524289824899824");
	++number;
	ASSERT_EQ(answer, number);
}

// --(int)

TEST(Unary1MinusMinus, TestName) {
	BigInt answer = BigInt("5943524289824899823");
	BigInt number = BigInt("5943524289824899824");
	number--;
	ASSERT_EQ(answer, number);
}

TEST(Unary2MinusMinus, TestName) {
	BigInt answer = BigInt("-5943524289824899825");
	BigInt number = BigInt("-5943524289824899824");
	number--;
	ASSERT_EQ(answer, number);
}

// --

TEST(UnaryMinusMinus1, TestName) {
	BigInt answer = BigInt("5943524289824899823");
	BigInt number = BigInt("5943524289824899824");
	--number;
	ASSERT_EQ(answer, number);
}

TEST(UnaryMinusMinus2, TestName) {
	BigInt answer = BigInt("-5943524289824899825");
	BigInt number = BigInt("-5943524289824899824");
	--number;
	ASSERT_EQ(answer, number);
}

// +=
TEST(AssignSum, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt answer = BigInt("5943524693733923726");
	number += second_number;
	ASSERT_EQ(answer, number);
}

// -=
TEST(AssignDiff, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt answer = BigInt("5943523885915875920");
	number -= second_number;
	ASSERT_EQ(answer, number);
}

// *=
TEST(AssignMul, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt answer = BigInt("2400643094446946562292687469169");
	number *= second_number;
	ASSERT_EQ(answer, number);
}

// /=
TEST(AssignDiv, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt number2 = BigInt("354398423989423");
	BigInt answer = BigInt("16770");
	number /= number2;
	ASSERT_EQ(answer, number);
}

// %=
TEST(AssignMod, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt number2 = BigInt("354398423989423");
	BigInt answer = BigInt("262719522276113");
	number %= number2;
	ASSERT_EQ(answer, number);
}

// ^=
TEST(AssignXOR, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt number2 = BigInt("354398423989423");
	BigInt answer = BigInt("5943310646069231168");
	number ^= number2;
	ASSERT_EQ(answer, number);
}

// &=
TEST(AssignAND, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt number2 = BigInt("354398423989423");
	BigInt answer = BigInt("284021089829039");
	number &= number2;
	ASSERT_EQ(answer, number);
}

// |=
TEST(AssignOR, TestName) {
	BigInt number = BigInt("5943524289824899823");
	BigInt number2 = BigInt("354398423989423");
	BigInt answer = BigInt("5943594667159060207");
	number |= number2;
	ASSERT_EQ(answer, number);
}

// unary +
TEST(UnaryPlus, TestName) {
	BigInt answer = BigInt("5943524289824899824");
	BigInt tmp = +first_number;
	ASSERT_EQ(answer, tmp);
}

//unary -

TEST(UnaryMinus, TestName) {
	BigInt answer = BigInt("-5943524289824899824");
	BigInt tmp = -first_number;
	ASSERT_EQ(answer, tmp);
}

// ==

TEST(Equal1, TestName) {
	bool answer = 0;
	bool tmp = (first_number == second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(Equal2, TestName) {
	bool answer = 1;
	bool tmp = (first_number == first_number);
	ASSERT_EQ(answer, tmp);
}

// != 

TEST(NotEqual1, TestName) {
	bool answer = 1;
	bool tmp = (first_number != second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(NotEqual2, TestName) {
	bool answer = 0;
	bool tmp = (first_number != first_number);
	ASSERT_EQ(answer, tmp);
}

// >

TEST(More1, TestName) {
	bool answer = 1;
	bool tmp = (first_number > second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(More2, TestName) {
	bool answer = 0;
	bool tmp = (first_number > first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(More3, TestName) {
	bool answer = 0;
	bool tmp = (second_number > first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(More4, TestName) {
	bool answer = 0;
	bool tmp = (first_negative_number > first_number);
	ASSERT_EQ(answer, tmp);
}

// <

TEST(Less1, TestName) {
	bool answer = 0;
	bool tmp = (first_number < second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(Less2, TestName) {
	bool answer = 0;
	bool tmp = (first_number < first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(Less3, TestName) {
	bool answer = 1;
	bool tmp = (second_number < first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(Less4, TestName) {
	bool answer = 1;
	bool tmp = (first_negative_number < first_number);
	ASSERT_EQ(answer, tmp);
}

// >=

TEST(EqualMore1, TestName) {
	bool answer = 1;
	bool tmp = (first_number >= second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualMore2, TestName) {
	bool answer = 1;
	bool tmp = (first_number >= first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualMore3, TestName) {
	bool answer = 0;
	bool tmp = (second_number >= first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualMore4, TestName) {
	bool answer = 0;
	bool tmp = (first_negative_number >= first_number);
	ASSERT_EQ(answer, tmp);
}

// <=

TEST(EqualLess1, TestName) {
	bool answer = 0;
	bool tmp = (first_number < second_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualLess2, TestName) {
	bool answer = 1;
	bool tmp = (first_number <= first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualLess3, TestName) {
	bool answer = 1;
	bool tmp = (second_number < first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(EqualLess4, TestName) {
	bool answer = 1;
	bool tmp = (first_negative_number < first_number);
	ASSERT_EQ(answer, tmp);
}


// string()
TEST(String1, TestName) {
	std::string answer = "5943524289824899824";
	std::string tmp = std::string(first_number);
	ASSERT_EQ(answer, tmp);
}

TEST(String2, TestName) {
	std::string answer = "-5943524289824899824";
	std::string tmp = std::string(first_negative_number);
	ASSERT_EQ(answer, tmp);
}

TEST(String3, TestName) {
	std::string answer = "10000000000000000000000";
	std::string tmp = std::string(fourth_number);
	ASSERT_EQ(answer, tmp);
}

// int()
TEST(Int1, TestName)
{
	int answer = 645;
	int tmp = int(third_number);
	ASSERT_EQ(answer, tmp);
}