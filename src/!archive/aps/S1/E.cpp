#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define to(i, a, b, c) for (int(i) = (a); (i) < (b); (i) = (c))
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) = (c))

#define MOD (LL)(998244353)
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

int solve() {
    fastio;
    int w, h;
    cin >> w >> h;
    cout << power (2, w + h, MOD); // kinda surprised it works, kinda guessed tho...
    return 0;
}