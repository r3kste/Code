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

int solve (vll dp, vector<bool> dp_done) {
    fastio;
    int n, x;
    cin >> n >> x;
    vi c (n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    dp[0] = 0;
    dp_done[0] = true;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (!dp_done[i]) {
                if (i - c[j] >= 0) {
                    dp[i] = min (dp[i], dp[i - c[j]] + 1);
                }
            }
        }

        dp_done[i] = true;
    }

    if (dp[x] == int (MOD)) {
        cout << -1;
    } else {
        cout << dp[x];
    }

    return 0;
}

int main() {
    fastio;
    int t = 1;
    vll dp (1000001, int (MOD));
    vector<bool> dp_done (1000001, false);

    while (t--) {
        solve (dp, dp_done);
        cout << "\n";
    }
}