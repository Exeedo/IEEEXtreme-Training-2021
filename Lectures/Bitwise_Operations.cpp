#include <iostream>
using namespace std;

int main()
{
    int a = 90;
    int b = 54;

    // Bitwise AND operation
    cout << (a & b) << endl;		//  18 = 0001 0011

    // Bitwise OR operation
    cout << (a | b) << endl;		// 126 = 0111 1110

    // Bitwise XOR operation
    cout << (a ^ b) << endl;		// 108 = 0110 1100

    // Bitwise NOT operation
    cout << (~a) << endl;			// -91 = 1010 0101

    // Bitwise Shift Left operation
    cout << (b << 2) << endl;		// 216 = 1101 1000

    // Bitwise Shift Right operation
    cout << (a >> 2) << endl;		//  22 = 0001 0110
}
