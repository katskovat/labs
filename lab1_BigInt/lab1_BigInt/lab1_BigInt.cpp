#include "Class_BigInt.h"

int main()
{
    BigInt first_number = BigInt("5943524289824899824");
    BigInt second_number = BigInt("403909023903");

    BigInt number = BigInt("5943524289824899823");
    BigInt number2 = BigInt("354398423989423");
    BigInt answer = BigInt("5943310646069231168");
    number ^= number2;

    std::cout << (answer) << "\n";
    std::cout << (number) << "\n";
    return 0;
}
