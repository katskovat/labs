#include "Class_BigInt.h"

using namespace BigNum;
int main()
{
    BigInt first_number = BigInt("100000000000000000000");
    BigInt second_number = BigInt("5943524289824899824");

    std::cout << first_number / second_number << "\n";
    return 0;
}
