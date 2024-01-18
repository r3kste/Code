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
#define vout(__) for (auto _ : __) { o (_) } br
#define vvout(___)  for (auto __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

/*
Weighted Graph
*/
#define INF LONG_MAX
// #define INF 100000000000000000
struct Graph_EV {
    using pii = pair<int, int>;
    vector<vector<pii>> adj;
    vector<vector<ll>> mat;
    int n;
    vector<bool> visited;
    vector<int> roots;
    vector<vector<ll>> distances;

    Graph_EV (int no_of_nodes, bool fill = true) {
        adj.resize (no_of_nodes);
        n = no_of_nodes;
        visited.assign (no_of_nodes, false);
        distances = vector<vector<ll>> (no_of_nodes, vector<ll> (no_of_nodes, INF));
        mat = vector<vector<ll>> (no_of_nodes, vector<ll> (no_of_nodes, 0));

        if (fill) {
            DFS ();
        }
    }

    void clear() {
        visited.clear();
        roots.clear();
        distances.clear();
    }

    void input (int no_of_edges) {
        for (int i = 0; i < no_of_edges; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back (make_pair (v, w));
            adj[v].push_back (make_pair (u, w));
        }
    }
    void input() {
        for (int i = 0; i < n; i++) {
            int u, w;
            cin >> u >> w;
            u--;

            if (u == -2) {
                roots.push_back (i);
            } else {
                adj[u].push_back (make_pair (i, w));
                adj[i].push_back (make_pair (u, w));
            }
        }
    }
    void input_matrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll weight;
                cin >> weight;
                mat[i][j] = weight;
            }
        }
    }

    void DFS () {
        visited.assign (n, false);

        if (roots.size() == 0) {
            roots.push_back (0);
        }

        for (int root : roots) {
            dfs (root);
        }
    }
    void dfs (int node) {
        visited[node] = true;

        for (auto [to, weight] : adj[node]) {
            if (!visited[to]) {
                dfs (to);
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

            for (auto [next, weight] : adj[vertex]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push (next);
                }
            }
        }
    }

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

    void dijkstra (int start, vector<long long int> &distances, vector<int> &parents) {
        distances.assign (n, INF);
        parents.assign (n, -1);
        distances[start] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push ({0, start});

        while (!q.empty()) {
            int node = q.top().second;
            int dist = q.top().first;
            q.pop();

            if (dist != distances[node]) {
                continue;
            }

            for (auto [to, len] : adj[node]) {
                if (distances[node] + len < distances[to]) {
                    distances[to] = distances[node] + len;
                    parents[to] = node;
                    q.push ({distances[to], to});
                }
            }
        }
    }
    vector<int> path (int start, int target, vector<int> const & parents, int offset) {
        vector<int> path;

        for (int v = target; v != start; v = parents[v]) {
            if (v == -1) {
                return vector<int> (1, -1);
            }

            path.push_back (v + offset);
        }

        path.push_back (start + offset);
        reverse (path.begin(), path.end());
        return path;
    }

    void populate_distances (vector<int> & nodes_to_be_removed) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                distances[i][j] = mat[i][j];
            }
        }

        reverse (all (nodes_to_be_removed));
        vb done (n);
        vll ans;

        for (auto kk : nodes_to_be_removed) {
            int k = kk - 1;
            ll sum = 0;
            done[k] = 1;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distances[i][j] = min (distances[i][j], distances[i][k] + distances[k][j]);

                    if (done[i] && done[j]) {
                        sum += distances[i][j];
                    }
                }
            }

            ans.pb (sum);
        }

        reverse (all (ans));
        vout (ans);
    }
};

int solve() {
    fastio;
    int n;
    in (n);
    Graph_EV g (n, false);
    g.input_matrix();
    vi nodes_to_be_removed (n);
    vin (nodes_to_be_removed);
    g.populate_distances (nodes_to_be_removed);
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
