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
vector<vi> dp;
vector<vector<char>> a;
ll f (int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        if (dp[i][j] != 0) {
            return dp[i][j] % MOD;
        } else {
            ll aa = f (i - 1, j);
            aa %= MOD;
            ll b = f (i, j - 1);
            b %= MOD;

            if (a[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = aa + b;
                dp[i][j] %= MOD;
            }

            return dp[i][j];
        }
    } else {
        return 0;
    }

    return 0;
}
int solve() {
    fastio;
    cin >> n;
    a = vector<vector<char>> (n, vector<char> (n, '.'));
    dp = vector<vi> (n, vi (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[0][i] == '*') {
            break;
        }

        dp[0][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] == '*') {
            break;
        }

        dp[i][0] = 1;
    }

    dp[0][0] = 0;

    //f(i,j) = no of paths from from (0,0) to (i,j)
    //ans = f(0,0)
    //f(i,j) = f(i-i,j) + f(i,j-1)

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                ll aa = dp[i - 1][j] % MOD;
                ll b = dp[i][j - 1] % MOD;
                dp[i][j] = aa + b;
                dp[i][j] %= MOD;
            }
        }
    }

    if (n == 1 && a[0][0] == '.') {
        cout << 1;
    } else if (a[0][0] == '*') {
        cout << 0;
    } else {
        cout << dp[n - 1][n - 1];
    }

    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}