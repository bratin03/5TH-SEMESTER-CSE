#include <bits/stdc++.h>
using namespace std;

#define prDouble(x) cout << fixed << setprecision(10) << x

// Function to convert a float to its IEEE 754 single-precision binary representation
string floatToBinaryString(float value)
{
    uint32_t *ptr = reinterpret_cast<uint32_t *>(&value);
    bitset<32> binaryBits(*ptr);

    return binaryBits.to_string();
}

int main()
{
    float floatValue = 1.625 * pow(2, 32); // Example floating-point number
    string binaryRepresentation = floatToBinaryString(floatValue);

    cout << "Original float: ";
    prDouble(floatValue);
    cout << endl;
    cout << "IEEE 754 binary representation: " << binaryRepresentation << endl;

    return 0;
}
