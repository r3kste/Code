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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vll> dp (n + 1, vll (10, 0));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 10; j++) {
            dp[i][j] = 0;
        }

    for (int i = 1; i < 10; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] >= '1'  &&  s[i] <= '9') {
            dp[i][s[i] - '0'] = dp[i - 1][s[i] - '0'];
        } else {
            for (int j = 1; j < 10; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }

        for (int j = 2; j < 10; j++) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    if (n < 10) {
        cout << "";
    }

    cout << dp[n][9];
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