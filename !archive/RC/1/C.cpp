#include <iostream>
#include <string>

int main()
{
    std::string binaryNumber;
    int n = 0; // Counter for ones
    int m = 0; // Counter for zeros
    // Input binary number as a string
    std::cin >> binaryNumber;

    // Iterate through each character in the binary string
    for (char digit : binaryNumber)
    {
        if (digit == '1')
        {
            n++; // Increment ones count
        }
        else if (digit == '0')
        {
            m++; // Increment zeros count
        }
    }

    std::cout << (n & m);
    return 0;
}