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
vector<vii> adj;
vector<bool> visited;

ll f (int node) {
    visited[node] = true;
    ll maxx = 0;

    for (auto surr : adj[node]) {
        if (visited[surr.F]) {
            continue;
        }

        maxx = max (maxx, surr.S + f (surr.F));
    }

    return maxx;
}

int solve() {
    fastio;
    cin >> n;
    adj = vector<vii> (n);
    visited.assign (n, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb (mp (v, w));
        adj[v].pb (mp (u, w));
    }

    // f(i) = maximum cost starting from node 'i'
    // ans = f(0)
    // f(i) = maximum among surrounding except visited value of w+f(surr)
    cout << f (0);
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