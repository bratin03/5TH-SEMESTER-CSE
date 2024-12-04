#include <bits/stdc++.h>

using namespace std;
#define prDouble(x) cout << fixed << setprecision(20) << x
// Function to convert a binary string to a float
float binaryStringToFloat(const string &binaryStr)
{
    // Ensure the binary string is exactly 32 characters long
    if (binaryStr.length() != 32)
    {
        cerr << "Invalid binary string length (must be 32 characters)." << endl;
        return 0.0f; // Return a default value in case of an error.
    }

    // Use a stringstream to parse the binary string as a uint32_t
    bitset<32> bitset(binaryStr);
    uint32_t ieee32 = bitset.to_ulong();

    // Extract the sign, exponent, and fraction bits from the IEEE 754 representation
    int sign = (ieee32 >> 31) & 0x1;
    int exponent = (ieee32 >> 23) & 0xFF;
    int fraction = ieee32 & 0x7FFFFF;

    // Check for special cases: infinity and NaN
    if (exponent == 0xFF)
    {
        if (fraction == 0)
        {
            if (sign == 0)
                return numeric_limits<float>::infinity(); // Positive infinity
            else
                return -numeric_limits<float>::infinity(); // Negative infinity
        }
        else
        {
            return numeric_limits<float>::quiet_NaN(); // Not-a-Number (NaN)
        }
    }

    // Calculate the fractional part of the floating-point number
    float result = 1.0f;
    for (int i = 0; i < 23; i++)
    {
        if (fraction & (1 << (22 - i)))
        {
            result += 1.0f / static_cast<float>(1 << (i + 1));
        }
    }

    // Apply the exponent and sign to calculate the final float value
    result *= powf(2.0f, static_cast<float>(exponent) - 127.0f);
    return (sign == 0) ? result : -result;
}

int main()
{
    string binaryStr = "01111111110101010101010101010101"; // Example binary representation
    float result = binaryStringToFloat(binaryStr);

    cout << "Binary representation: " << binaryStr << endl;
    cout << "Converted float: ";
    prDouble(result);
    cout << endl;

    return 0;
}
