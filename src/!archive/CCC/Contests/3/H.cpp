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
    to (i, 0, n, i + 1) {
        cin >> a[i];
    }
    vi cik;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cik.push_back (a[i] + a[j]);
        }
    }

    ll s = 0;
    sort (cik.begin(), cik.end());

    for (int i = 0; i < n; i++) {
        s += (cik[i]);
    }

    cout << s;
    return 0;
}