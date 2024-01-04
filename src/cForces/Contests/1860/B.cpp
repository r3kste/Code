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
int c = 0;
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

int solve() {
    fastio;
    ll m, k, a, ak;
    cin >> m >> k >> a >> ak;
    ll ck = k;

    if (m <= a) {
        cout << 0;
    } else {
        while (ak > 0) {
            m = m - k;
            ak = ak - 1;

            if (m <= a) {
                cout << 0;
            }
        }

        m = m - a;
        ll alt = MOD;

        if (a > 0) {
            alt = ceil ((m - a) / double (ck));
        }

        cout << min (alt, (ll) ((m / ck) + (m % ck)));
    }

    return 0;
}