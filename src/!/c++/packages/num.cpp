#include <bits/stdc++.h>
using namespace std;

bool isPrime (long long int n) {
    if (n < 2) {
        return false;
    } else if (n == 2 || n == 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (long long int i = 5; i < sqrt (n) + 1; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
}

long long int power (long long int x, int y, long long int mod) {
    long long int o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) {
            o = (o * x) % mod;
        }

        y >>= 1;
        x = (x * x) % mod;
    }

    return o;
}
long long int inv (long long int n, long long int mod) {
    return power (n, mod - 2, mod);
}
long long int mul (long long int x, long long int y, long long int mod) {
    return (x * y) % mod;
}
long long int div (long long int x, long long int y, long long int mod) {
    return mul (x, inv (y, mod), mod);
}
long long int ncr (long long int n, long long int r, long long int mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) { // Make sure r is the least one possible
        return ncr (n, n - r, mod);
    }

    long long int o = 1;

    for (int i = r; i > 0; i--) {
        o = div (mul (o, n - i + 1, mod), i, mod);
    }

    return o;
}

int main() {
}
