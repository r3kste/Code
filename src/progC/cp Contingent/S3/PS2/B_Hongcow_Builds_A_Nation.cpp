#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define MOD (ll)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int) (a).size())

#define rep(_, n) int _; for(_ = 0; _ < n; _++)

#define in(_) cin >> _;
#define in2(_0, _1) cin >> _0 >> _1;
#define in3(_0, _1, _2) cin >> _0 >> _1 >> _2;
#define vin(a) { rep (_, sz (a)) { in (a[_]) }}
#define vvin(r, c) { rep(__,r) { rep(_,c) { in (matrix[__][_]) } } }
#define br cout << "\n";
#define out(_,__) cout << _ << __;
#define o(_) out(_, " ")
#define vout(__) for (int _ : __) { o (_) } br
#define vvout(___)  for (vi __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")
#define INF LLONG_MAX
/*
Unweighted Graph
*/
struct Graph {
    vector<vector<int>> adj;
    int n;
    vector<bool> visited;
    vector<int> roots;
    vector<int> governments;
    vi governed_by;
    int count = 0;
    map<int, int> gov_pow;

    Graph (int no_of_nodes) {
        adj.resize (no_of_nodes);
        governed_by.assign (no_of_nodes, -1);
        n = no_of_nodes;
    }

    /*
    Initializes & (by default) Populates:
        1. visited
    */
    void init (bool fill = true) {
        visited.assign (n, false);

        if (fill) {
            DFS ();
        }
    }

    /*
    Depopulates:
        1. visited
    */
    void clear() {
        visited.clear();
    }

    /*
    Populates: adj (with stdin)
    */
    void input (int no_of_edges) {
        for (int i = 0; i < no_of_edges; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
    }
    void input() {
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            u--;

            if (u == -2) {
                roots.push_back (i);
            } else {
                adj[u].push_back (i);
                adj[i].push_back (u);
            }
        }
    }

    /*
    Reopulates (via depth-first traversal):
        1. visited
    */
    void DFS () {
        visited.assign (n, false);

        for (int root : roots) {
            dfs (root);
        }
    }
    void DFS_gov () {
        visited.assign (n, false);

        for (int government : governments) {
            count = 0;
            dfs_gov (government, government);
            gov_pow[government] = count;
        }
    }
    void dfs (int node) {
        visited[node] = true;

        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs (to);
            }
        }
    }
    void dfs_gov (int node, int government) {
        count++;
        visited[node] = true;
        governed_by[node] = government;

        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs_gov (to, government);
            }
        }
    }

    void bfs (int root) {
        queue<int> q;
        q.push (root);
        visited[root] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            for (int next : adj[vertex]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push (next);
                }
            }
        }
    }

    /*
    Repopulates: roots
    */
    void find_components () {
        visited.assign (n, false);
        roots.clear();

        for (int vertex = 0; vertex < n; ++vertex) {
            if (!visited[vertex]) {
                roots.push_back (vertex);
                dfs (vertex);
            }
        }
    }
};
long long int power (long long int x, int y, long long int mod) {
    long long int o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) {
            o = (o * x) % mod;
        }

        y >>= 1;
        x = (x * x) % mod;
    }

    return o;
}
long long int inv (long long int n, long long int mod) {
    return power (n, mod - 2, mod);
}
long long int mul (long long int x, long long int y, long long int mod) {
    return (x * y) % mod;
}
long long int div (long long int x, long long int y, long long int mod) {
    return mul (x, inv (y, mod), mod);
}
long long int ncr (long long int n, long long int r, long long int mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) { // Make sure r is the least one possible
        return ncr (n, n - r, mod);
    }

    long long int o = 1;

    for (int i = r; i > 0; i--) {
        o = div (mul (o, n - i + 1, mod), i, mod);
    }

    return o;
}
int solve() {
    fastio;
    int n, m, k;
    in3 (n, m, k);
    Graph g (n);

    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        g.governments.push_back (temp - 1);
    }

    g.input (m);
    g.init (false);
    g.DFS_gov();
    int max_strength = -1;
    int neutral = 0;
    ll total = 0;

    for (auto [government, strength] : g.gov_pow) {
        neutral += strength;
        total += ncr (strength, 2, MOD);

        if (strength > max_strength) {
            max_strength = strength;
        }
    }

    neutral = n - neutral;
    total -= ncr (max_strength, 2, MOD);
    total += ncr (max_strength + neutral, 2, MOD);
    o (total - m) br
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // in (t);

    while (t--) {
        solve();
    }
}
