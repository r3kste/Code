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
vector<set<int>> adj;
vector<bool> visited;
void dfs (int node, int parent) {
    visited[node] = true;
    cout << node + 1 << " ";

    for (auto surr : adj[node]) {
        if (surr == parent) {
            continue;
        }

        if (visited[surr]) {
            continue;
        }

        dfs (surr, node);
    }
}
int solve() {
    fastio;
    cin >> n;
    int e;
    cin >> e;
    adj = vector<set<int>> (n);
    visited = vector<bool> (n, false);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert (v);
        adj[v].insert (u);
    }

    dfs (0, -1);
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