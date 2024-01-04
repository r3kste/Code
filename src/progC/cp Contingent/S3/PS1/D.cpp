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
vector<vector<int>> adj;
vector<bool> visited;
int maxdepth;
void dfs (int node, int depth) {
    maxdepth = max (maxdepth, depth);
    visited[node] = true;

    for (auto surr : adj[node]) {
        if (visited[surr] || surr == -2) {
            continue;
        }

        dfs (surr, depth + 1);
    }
}
int solve() {
    fastio;
    cin >> n;
    adj = vector<vi> (n);
    visited = vector<bool> (n, false);
    vi roots;
    maxdepth = (int) - MOD;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        adj[i].pb (t);

        if (t == -2) {
            roots.pb (i);
        } else {
            adj[t].pb (i);
        }
    }

    for (auto root : roots) {
        dfs (root, 1);
    }

    cout << maxdepth;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}