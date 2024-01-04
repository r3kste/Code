#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

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
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;

    if (k == 1) {
        cout << m + 1;
        return 0;
    }

    if (k > n + 1 || k > m + 1) {
        cout << 0;
        return 0;
    }

    long long ans = 0;

    for (int x = 0; x <= m; x++) {
        vi rem;
        rem.push_back (x);

        for (int i = n; i >= 1; i--) {
            int last = rem.back();
            int next = last % i;
            rem.push_back (next);
        }

        sort (rem.begin(), rem.end());
        rem.erase (unique (rem.begin(), rem.end()), rem.end());

        if (rem.size() == k) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}