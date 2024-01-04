#include <iostream>
#include <unordered_set>

// Function to calculate the number of distinct prime factors of a number
int countDistinctPrimeFactors (int n) {
    std::unordered_set<int> factors;

    // Divide n by 2 until it is divisible by 2
    while (n % 2 == 0) {
        factors.insert (2);
        n /= 2;
    }

    // Start checking for prime factors from 3 onwards
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.insert (i);
            n /= i;
        }
    }

    // If n is still greater than 1, it must be a prime factor itself
    if (n > 1) {
        factors.insert (n);
    }

    return factors.size();
}

int main() {
    int a, b, c;
    // Input three numbers
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;
    // Calculate the number of distinct prime factors for each number
    int A = countDistinctPrimeFactors (a);
    int B = countDistinctPrimeFactors (b);
    int C = countDistinctPrimeFactors (c);
    // Output the sum of the counts
    std::cout << "A + B + C = " << A + B + C << std::endl;
    return 0;
}
