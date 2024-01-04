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

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vii dp;
vector<bool> dpd;
vi catto;
int c;
void dfs (int node, int parent, int streak) {
    visited[node] = true;
    int newstreak = streak;

    if (catto[node]) {
        newstreak += 1;
    } else {
        newstreak = 0;
    }

    if (newstreak <= m) {
        if (adj[node].size() == 1 && node != 0) {
            c++;
        } else {
            for (auto surr : adj[node]) {
                if (surr == parent || visited[surr]) {
                    continue;
                }

                dfs (surr, node, newstreak);
            }
        }
    }
}
int solve() {
    fastio;
    cin >> n;
    cin >> m;
    adj = vector<vi> (n);
    visited = vector<bool> (n, false);
    dp = vii (n);
    dpd = vector<bool> (n);
    catto = vi (n, 0);
    c = 0;

    for (int i = 0; i < n; i++) {
        cin >> catto[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    dfs (0, -1, 0);
    cout << c;
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