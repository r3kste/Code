#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl "\n"
#define yesno(a) cout << ((a) ? "Yes" : "No");

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
int n;
vi a;
map<ii, int> dp;
map<ii, bool> dpd;
ll fact2 (int n) {
    int k = 0;

    while (n % 2 == 0) {
        n /= 2;
        k++;
    }

    return k;
}
ll f (int pos, int ene) {
    if (pos == n - 1) {
        if (a[pos] > ene) {
            return fact2 (a[pos]);
        } else {
            return 0;
        }
    }

    if (dpd[mp (pos, ene)]) {
        return dp[mp (pos, ene)];
    } else {
        dpd[mp (pos, ene)] = true;

        if (a[pos] > ene) {
            dp[mp (pos, ene)] = max (fact2 (a[pos]) + f (pos + 1, a[pos]), f (pos + 1, ene));
        } else {
            dp[mp (pos, ene)] = f (pos + 1, ene);
        }

        return dp[mp (pos, ene)];
    }
}
int solve()

{
    fastio;
    cin >> n;
    dp.clear();
    dpd.clear();
    a = vi (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // f (i, s) = maximum energy from i to end, with s as current maximum
    // ans = f (0, 0)
    // f (i, s) = max (f (i + 1, a[i]), f (i + 1, s))
    cout << f (0, 0);
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