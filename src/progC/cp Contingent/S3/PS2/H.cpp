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
Weighted Graph
*/
struct Graph_EV {
    using pii = pair<int, ll>;
    vector<vector<pii>> adj;
    int n;
    vector<bool> visited;
    vector<int> roots;

    Graph_EV (int no_of_nodes) {
        adj.resize (no_of_nodes);
        n = no_of_nodes;
    }

    /*
    Initializes & (by default) Populates:
        1. visited
        2. depth
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
        2. depth
    */
    void clear() {
        visited.clear();
    }

    /*
    Populates: adj (with stdin)
    */
    void input (int m) {
        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back (make_pair (v, w));
            adj[v].push_back (make_pair (u, w));
        }
    }

    /*
    Populates (via depth-first traversal):
        1. visited (resets)
        2. depth
    */
    void DFS () {
        visited.assign (n, false);

        for (int root : roots) {
            dfs (root);
        }
    }
    void dfs (int node = 0) {
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

    /*
    Populates:
        1. distances => minimum distance starting from start to every other node.
        2. parents => parents, for traversal
    */
    void dijkstra_lin (int start, vector<long long int> &distances, vector<int> &parents) {
        distances.assign (n, INF);
        parents.assign (n, -1);
        vector<bool> seen (n, false);
        distances[start] = 0;

        for (int i = 0; i < n; i++) {
            int next = -1;

            for (int others = 0; others < n; others++) {
                if (!seen[others] && (next == -1 || distances[others] < distances[next])) {
                    next = others;
                }
            }

            if (distances[next] == INF) {
                break;
            }

            seen[next] = true;

            for (auto [to, len] : adj[next]) {
                if (distances[next] + len < distances[to]) {
                    distances[to] = distances[next] + len;
                    parents[to] = next;
                }
            }
        }
    }
    void dijkstra_set (int start, vector<long long int> &distances, vector<int> &parents) {
        distances.assign (n, INF);
        parents.assign (n, -1);
        distances[start] = 0;
        using pii = pair<ll, int>;
        set<pii> q;
        //dist node
        q.insert ({0, start});

        while (!q.empty()) {
            int node = q.begin()->second;
            q.erase (q.begin());

            for (auto [to, len] : adj[node]) {
                if (distances[node] + len < distances[to]) {
                    q.erase ({distances[to], to});
                    distances[to] = distances[node] + len;
                    parents[to] = node;
                    q.insert ({distances[to], to});
                }
            }
        }
    }
    void dijkstra_pqu (int start, vector<long long int> &distances, vector<int> &parents) {
        distances.assign (n, INF);
        parents.assign (n, -1);
        distances[start] = 0;
        using pii = pair<ll, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push ({0, start});

        while (!q.empty()) {
            int node = q.top().second;
            ll dist = q.top().first;
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
                return vi (1, -1);
            }

            path.push_back (v + offset);
        }

        path.push_back (start + offset);
        reverse (path.begin(), path.end());
        return path;
    }
};

int solve() {
    fastio;
    int n, m;
    in2 (n, m);
    Graph_EV g (n);
    g.input (m);
    vll distances;
    vi parents;
    g.dijkstra_pqu (0, distances, parents);
    vout (g.path (0, n - 1, parents, 1));
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
