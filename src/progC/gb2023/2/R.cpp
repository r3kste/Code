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
vector<vi> dp;
vector<vector<bool>> dpd;
ll f (int i, int j) {
    if (i > j) {
        return 0;
    } else if (dpd[i][j]) {
        return dp[i][j];
    } else {
        dpd[i][j] = true;
        return dp[i][j] = max (a[i] + min (f (i + 2, j), f (i + 1, j - 1)), a[j] + min (f (i, j - 2), f (i + 1, j - 1)));
    }
}
int solve() {
    fastio;
    cin >> n;
    a = vi (n, 0);
    dp = vector<vi> (n, vi (n));
    dpd = vector<vector<bool>> (n, vector<bool> (n, false));
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // f (i, j) = maximum score of ibraheen considering from index i to index j
    // ans = sum - 2*f (0, n - 1)
    //f (i, j) = max (a[i] + min (f (i + 2, j), f (i + 1, j - 1)), a[j] + min (f (i, j - 2), f (i + 1, j - 1)))
    cout << 2 * f (0, n - 1) - sum;
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