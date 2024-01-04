
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
vector<vll> grid;
vll dp;
vector<bool> dpd;
ll f (int i) {
    if (i > n - 2 || i < 0) {
        return 0;
    }

    if (dpd[i]) {
        return dp[i];
    } else {
        ll sum = grid[0][i] + grid[1][i] + grid[0][i + 1] + grid[1][i + 1];
        ll a = sum - grid[0][i];
        ll b = sum - grid[1][i];
        ll c = sum - grid[0][i + 1];
        ll d = sum - grid[1][i + 1];
        ll mx = max (a, max (b, max (c, d)));
        dpd[i] = true;
        return dp[i] = max (mx + f (i + 2), f (i + 1));
    }
}
int solve() {
    fastio;
    cin >> n;
    grid = vector<vll> (2, vll (n));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp = vll (n, 0);
    dpd = vector<bool> (n, false);
    // f(i) = maximum sum starting from i'th index
    // ans = f(0)
    // f (i) = max (max (L, 7, J, F) + f (i + 2), f (i + 1))
    cout << f (0);
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