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

int solve() {
    fastio;
    int n, x;
    cin >> n >> x;
    vi c (n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> dp (n + 1, vector<int> (x + 1, 0));

    //dp[a][b] = number of ways to get a sum of b using a distinct (ordered?) coins
    for (int i = 0; i <= x; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= x; j++)
    //     {
    //         if (j - c[i] >= 0)
    //         {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - c[i]];
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - c[j - 1] >= 0) {
                dp[j][i] = (dp[j - 1][i] % MOD) + (dp[j][i - c[j - 1]] % MOD) % MOD;
            } else {
                dp[j][i] = dp[j - 1][i] % MOD;
            }
        }
    }

    cout << dp[n][x] % MOD;
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