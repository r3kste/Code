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

vll dp (1000001, 0);

ll calc (int n) {
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ll sum = 0;

        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = dp[i] + dp[i - j] % MOD;
            }
        }
    }

    return dp[n];
}
int solve() {
    fastio;
    int n;
    cin >> n;
    cout << calc (n) % MOD;
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
