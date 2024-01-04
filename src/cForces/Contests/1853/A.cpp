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
    int n;
    cin >> n;
    vi a (n);
    ll mm = MOD;
    to (i, 0, n, i + 1) {
        cin >> a[i];

        if (i == 0) {
            continue;
        }

        ll temp = a[i] - a[i - 1];

        if (temp < mm) {
            mm = temp;
        }
    }
    bool s = is_sorted (begin (a), end (a));

    if (!s) {
        cout << 0;
    } else {
        cout << (mm + 2) / 2;
    }

    a.clear();
    return 0;
}