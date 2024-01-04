#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    vi a (n);
    vll p (n + 1, 0);
    p[0] = 0;
    ll max = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = (p[i] + a[i]);

        if (a[i] > max) {
            max = a[i];
        }
    }

    // for (int i = max; i <= p[n]; i++)
    // {
    // int j = lower_bound (p.begin(), p.end(), i) - p.begin();
    // }
    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
