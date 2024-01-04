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
vector<vector<int>> adj;
string color;
vector<bool> visited;
vii dp;
vector<bool> dpd;
int count (int node, int parent) {
    int c = 0;

    for (auto surr : dp) {
        if (surr.F == surr.S) {
            c++;
        }
    }

    cout << c;
    return 0;
}
ii f (int node, int parent) {
    if (dpd[node]) {
        return dp[node];
    } else {
        ii sub = mp (0, 0);
        //           B  W

        if (color[node] == 'W') {
            sub.S++;
        } else {
            sub.F++;
        }

        for (auto surr : adj[node]) {
            if (surr == parent) {
                continue;
            }

            ii t = f (surr, node);
            sub.F += t.F;
            sub.S += t.S;
        }

        return dp[node] = sub;
    }
}
int solve() {
    fastio;
    int n;
    cin >> n;
    adj = vector<vi> (n);
    visited = vector<bool> (n, false);
    dp = vii (n);
    dpd = vector<bool> (n);

    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        t--;
        adj[i].pb (t);
        adj[t].pb (i);
    }

    cin >> color;
    f (0, -1);
    count (0, -1);
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