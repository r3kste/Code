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
#define vout(__) for (int _ : __) { out (_,"\n") } br
#define vvout(___)  for (vi __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

/*
Unweighted Graph
*/
struct Graph {
    vector<vector<int>> adj;
    int n;
    vector<bool> visited;
    vector<int> roots;
    vector<int> init;
    vector<int> goal;
    int steps;
    vi ans;
    /*
    vector<int> root_of;
    vector<int> parent_of;
    map<int, int> cluster_size;
    vector<int> height, eulerian, first, segtree, subtree_size;
    int timer;
    vector<int> tin, tout;
    int depth;
    */

    Graph (int no_of_nodes) {
        adj.resize (no_of_nodes);
        init.resize (no_of_nodes);
        goal.resize (no_of_nodes);
        steps = 0;
        n = no_of_nodes;
    }

    void insit (bool fill = true) {
        visited.assign (n, false);
        /*
        height.resize (n);
        first.resize (n);
        timer = 0;
        tin.resize (n);
        tout.resize (n);
        subtree_size.resize (n);
        depth = -1;
        */

        if (fill) {
            DFS ();
            /*
            int m = eulerian.size();
            segtree.resize (m * 4);
            build (1, 0, m - 1);
            */
        }
    }

    void clear() {
        visited.clear();
        /*
        height.clear();
        first.clear();
        eulerian.clear();
        tin.clear();
        tout.clear();
        subtree_size.clear();
        timer = 0;
        depth = -1;
        segtree.clear();
        */
    }

    void input (int m) {
        for (int i = 0; i < m; i++) {
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

    void DFS () {
        visited.assign (n, false);
        dfs (0, 0, -1, 0, 0, 0);
    }
    void dfs (int node, int h, int parent, int root, int even_count, int odd_count) {
        visited[node] = true;

        if (h % 2 == 0) {
            init[node] ^= even_count % 2;
        } else {
            init[node] ^= odd_count % 2;
        }

        if (goal[node] != init[node]) {
            steps++;
            ans.pb (node + 1);

            if (h % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        /*
        root_of[node] = root;
        parent_of[node] = parent;
        cluster_size[root]++;
        tin[node] = ++timer;
        height[node] = h;
        first[node] = eulerian.size();
        eulerian.push_back (node);
        depth = max (depth, h);
        */
        for (int to : adj[node]) {
            if (!visited[to]) {
                if (h % 2 == 0) {
                    dfs (to, h + 1, node, root, even_count, odd_count);
                } else {
                    dfs (to, h + 1, node, root, even_count, odd_count);
                }

                /*
                eulerian.push_back (node);
                subtree_size[node] += subtree_size[to];
                */
            }
        }

        /*
        subtree_size[node]++;
        tout[node] = ++timer;
        */
    }

    void bfs (int root, int h = 0) {
        queue<int> q;
        vector<bool> visited (n);
        q.push (root);
        visited[root] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            for (int u : adj[vertex]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push (u);
                }
            }
        }
    }

    // void clusters () {
    //     fill (visited.begin(), visited.end(), false);
    //     roots.clear();

    //     for (int vertex = 0; vertex < n; ++vertex) {
    //         if (!visited[vertex]) {
    //             roots.push_back (vertex);
    //             dfs (vertex, 0, -1, vertex);
    //         }
    //     }
    // }
    /*
    bool is_ancestor (int parents, int child) {
        return tin[parents] <= tin[child] && tout[parents] >= tout[child];
    }

    void build (int node, int begin, int end) {
        if (begin == end) {
            segtree[node] = eulerian[begin];
        } else {
            int mid = (begin + end) / 2;
            build (node << 1, begin, mid);
            build (node << 1 | 1, mid + 1, end);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }
    int query (int node, int begin, int end, int L, int R) {
        if (begin > R || end < L) {
            return -1;
        }

        if (begin >= L && end <= R) {
            return segtree[node];
        }

        int mid = (begin + end) >> 1;
        int left = query (node << 1, begin, mid, L, R);
        int right = query (node << 1 | 1, mid + 1, end, L, R);

        if (left == -1) {
            return right;
        }

        if (right == -1) {
            return left;
        }

        return height[left] < height[right] ? left : right;
    }
    int lca (int u, int v) {
        int left = first[u], right = first[v];

        if (left > right) {
            swap (left, right);
        }

        return query (1, 0, eulerian.size() - 1, left, right);
    }
    */
};

int solve() {
    fastio;
    int n;
    in (n);
    Graph g (n);
    g.input (n - 1);
    vin (g.init);
    vin (g.goal);
    g.DFS ();
    o (g.steps) br
    vout (g.ans);
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
