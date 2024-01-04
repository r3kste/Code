#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define to(i, a, b, c) for (int(i) = (a); (i) < (b); (i) = (c))
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) = (c))

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve();

int main() {
    fastio;
    int t = 1;

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}
LL power (LL x, LL y, LL mod) {
    LL o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) { // checks whether the LSB of y is 1.
            o = (o * x) % mod;
        }

        y = y >> 1;        // y = y/2
        x = (x * x) % mod; // x = x*x
    }

    return o;
}
LL inv_m (LL n, LL mod) {
    return power (n, mod - 2, mod); // n^(mod-2) % mod
}
LL ncr_m (LL n, LL r, LL mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) {
        return ncr_m (n, n - r, mod);    // make sure r is the lower r
    }

    LL o = 1;

    // for (int i = n; i > 0; i--)
    // {
    //     o = (o * i) % mod; // calculates n!
    // }
    // for (int i = r; i > 0; i--)
    // {
    //     o = (o * inv_m(i, mod)) % mod; // divides by r!
    // }
    // for (int i = n - r; i > 0; i--)
    // {
    //     o = (o * inv_m(i, mod)) % mod; // divides by (n-r)!
    // }

    for (int i = r; i > 0; i--) {
        o = (o * (n - i + 1)) % mod;   // calculates n!/(n-r)! together
        o = (o * inv_m (i, mod)) % mod; // divides the above by r!
    }

    return o;
}

int solve() {
    fastio;
    LL a, b;
    cin >> a >> b;
    cout << ncr_m (a, b, MOD);
    return 0;
}