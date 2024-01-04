#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define MOD (ll)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;

int solve();

int main() {
    fastio;
    int t = 1;

    if (true) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

LL power (LL x, int y, ll mod) {
    LL o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) {
            o = (o * x) % mod;
        }

        y = y >> 1; // y = y/2
        x = (x * x) % mod;
    }

    return o;
}
LL inv_m (LL n, ll mod) {
    return power (n, mod - 2, mod);
}
LL mul (LL x, LL y, ll mod) {
    return x * 1ull * y % mod;
}
LL divide_m (LL x, LL y, ll mod) {
    return mul (x, inv_m (y, mod), mod);
}
LL ncr_m (LL n, int r, ll mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) {
        return ncr_m (n, n - r, mod);
    }

    LL o = 1;

    for (int i = r; i >= 1; i--) {
        o = divide_m (mul (o, n - i + 1, mod), i, mod);
    }

    return o;
}

int solve() {
    fastio;
    ll n;
    cin >> n;
    vll a (n);
    vll b (n);
    to (i, 0, n, 1) {
        cin >> a[i];
    }
    to (i, 0, n, 1) {
        cin >> b[i];
    }
    sort (begin (a), end (a));
    sort (begin (b), end (b));
    ll no_fixed = 0;
    ll o = 1;

    for (int i = 0, j = 1; i < n; i = j) {
        while (j < n && a[i] == a[j]) {
            j++;
        }

        int c = j - i;
        int in = lower_bound (b.begin(), b.end(), a[i]) - b.begin();
        o = (o * ncr_m (in - no_fixed, c, MOD) % MOD);
        no_fixed += c;

        if (o == 0) {
            break;
        }
    }

    cout << o;
    // if (a[0] <= b[0] || a[n - 1] <= b[n - 1])
    // {
    //     cout << 0;
    //     return 0;
    // }
    // ll c = 0;
    // ll k = 0;
    // ll o = 1;
    // ll m = 1000000007;
    // int i = n - 1, j = n - 1;
    // while (j > -1)
    // {
    //     if (a[i] > b[j])
    //     {
    //         c++;
    //         i--;
    //     }
    //     if (a[i] <= b[j] || i == -1)
    //     {
    //         o *= (max((c - k), (ll)0));
    //         o %= m;
    //         j--;
    //         k+=k0;
    //         i = n - 1;
    //         c = 0;
    //     }
    // }
    // cout << o % m;
    return 0;
}