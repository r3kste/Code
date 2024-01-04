#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;

bool isPrime (int n) {
#define nmod(m) n % m == 0

    if (n < 2) {
        return false;
    }

    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23) {
        return true;
    }

    if (nmod (2) || nmod (3) || nmod (5) || nmod (7) || nmod (11) || nmod (13) || nmod (17) || nmod (19) || nmod (23)) {
        return false;
    }

    for (int i = 23; i < sqrt (n) + 1; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }

    return true;
}

LL power (LL x, int y, ll mod) { // Binary Exponentiation of x^y % mod
    LL o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) { // Checks if LSB of y is 1.
            o = (o * x) % mod;
        }

        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }

    return o;
}
LL m_inv (LL n, ll mod) {
    return power (n, mod - 2, mod);
}
LL m_mul (LL x, LL y, ll mod) {
    return (x * y) % mod;
}
LL m_div (LL x, LL y, ll mod) {
    return m_mul (x, m_inv (y, mod), mod);
}
LL m_ncr (LL n, int r, ll mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) { // Make sure r is the least one possible
        return m_ncr (n, n - r, mod);
    }

    LL o = 1;

    for (int i = r; i > 0; i--) {
        o = m_div (m_mul (o, n - i + 1, mod), i, mod);
    }

    return o;
}

int main() {
    cout << m_inv (20, 37);
}
