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
int solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    vi a (n);
    to (i, 0, n, i + 1) {
        cin >> a[i];
    }
    vi b (n);
    to (i, 0, n, i + 1) {
        cin >> b[i];
    }
    vi status;
    to (i, 0, n, i + 1) {
        if (a[i] == 0 || b[i] == 0) {
            status.push_back (0);
        } else {
            status.push_back (1);
        }
    }
    status.push_back (0);
    // LL num = 0;
    // LL den = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] > 0 && a[i] < b[i])
    //     {
    //         break;
    //     }
    // }
    // if (n == 0)
    // {
    //     cout << 0;
    // }
    // else
    // {
    //     cout << num * inv_m (den, MOD) % MOD;
    // }
    return 0;
}