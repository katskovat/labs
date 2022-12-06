#include "Class_BigInt.h"

int main()
{
    string first_number = "8993129889321";
    string second_number = "7823312988321";
    BigInt firstBigIntNumber = first_number;
    BigInt secondBigIntNumber = second_number;
    cout << (firstBigIntNumber ^ secondBigIntNumber);
    return 0;
}
