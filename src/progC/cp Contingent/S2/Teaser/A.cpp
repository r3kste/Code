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

vi dp (26, -1);

int calc (int n) {
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        dp[0] = 1;
        return 1;
    } else {
        if (dp[n] != -1) {
            return dp[n];
        } else {
            dp[n] = calc (n - 1) + calc (n - 2) + calc (n - 3) + calc (n - 4) + calc (n - 5) + calc (n - 6);
            dp[n] = dp[n] % MOD;
            return dp[n];
        }
    }
}
int solve() {
    fastio;
    int n;
    cin >> n;
    cout << calc (n);
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
