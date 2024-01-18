#include <bits/stdc++.h>
using namespace std;

/*
Unweighted Graph
*/
struct Graph {
    vector<vector<int>> adj;
    int n;
    vector<bool> visited;
    vector<int> roots;
    // vector<int> root_of;
    // vector<int> parent_of;
    // map<int, int> cluster_size;
    // vector<int> height;
    // vector<int> eulerian;
    // vector<int> first;
    // vector<int> segtree;
    // vector<int> subtree_size;
    // int timer;
    // vector<int> tin, tout;
    // int depth;
    Graph (int no_of_nodes, int no_of_edges, bool fill = true) {
        adj.resize (no_of_nodes);
        n = no_of_nodes;
        visited.assign (no_of_nodes, false);

        // height.resize (no_of_nodes);
        // first.resize (no_of_nodes);
        // timer = 0;
        // tin.resize (no_of_nodes);
        // tout.resize (no_of_nodes);
        // subtree_size.resize (no_of_nodes);
        // depth = -1;

        if (fill) {
            if (no_of_edges == -1) {
                input();
            } else {
                input (no_of_edges);
            }

            DFS ();
            // int m = eulerian.size();
            // segtree.resize (m * 4);
            // build (1, 0, m - 1);
        }
    }

    void clear() {
        // visited.clear();
        // height.clear();
        // first.clear();
        // eulerian.clear();
        // tin.clear();
        // tout.clear();
        // subtree_size.clear();
        // timer = 0;
        // depth = -1;
        // segtree.clear();
    }

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

    void DFS () {
        visited.assign (n, false);

        if (roots.size() == 0) {
            roots.push_back (0);
        }

        for (int root : roots) {
            dfs (root, 0, -1, root, true);
        }
    }
    void dfs (int node, int level = 0, int parent = -1, int root = 0, bool modify = false) {
        visited[node] = true;

        if (modify) {
            // root_of[node] = root;
            // parent_of[node] = parent;
            // cluster_size[root]++;
            // tin[node] = ++timer;
            // height[node] = level;
            // first[node] = eulerian.size();
            // eulerian.push_back (node);
            // depth = max (depth, level);
        }

        for (int to : adj[node]) {
            if (!visited[to]) {
                dfs (to, level + 1, node, root, modify);

                if (modify) {
                    // eulerian.push_back (node);
                    // subtree_size[node] += subtree_size[to];
                }
            }
        }

        if (modify) {
            // subtree_size[node]++;
            // tout[node] = ++timer;
        }
    }

    void bfs (int root, int level = 0) {
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

    void clusters () {
        fill (visited.begin(), visited.end(), false);
        roots.clear();

        for (int vertex = 0; vertex < n; ++vertex) {
            if (!visited[vertex]) {
                roots.push_back (vertex);
                dfs (vertex, 0, -1, vertex);
            }
        }
    }
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

/*
Weighted Graph
*/
// #define INF LLONG_MAX
#define INF 100000000000000000
struct Graph_EV {
    using pii = pair<int, int>;
    vector<vector<pii>> adj;
    // vector<vector<int>> mat;
    int n;
    vector<bool> visited;
    vector<int> roots;
    // vector<vector<long long int>> distances;

    Graph_EV (int no_of_nodes, int no_of_edges, bool fill = true) {
        adj.resize (no_of_nodes);
        n = no_of_nodes;
        visited.assign (no_of_nodes, false);
        // distances = vector<vector<long long int>> (no_of_nodes, vector<long long int> (no_of_nodes, INF));
        // mat = vector<vector<int>> (no_of_nodes, vector<int> (no_of_nodes, 0));

        if (fill) {
            if (no_of_edges == -1) {
                input();
            } else {
                input (no_of_edges);
            }

            DFS ();
        }
    }

    void clear() {
        visited.clear();
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
    // void input_matrix() {
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < 0; j++) {
    //             int weight;
    //             cin >> weight;
    //             mat[i][j] = weight;
    //         }
    //     }
    // }

    void DFS () {
        visited.assign (n, false);

        if (roots.size() == 0) {
            roots.push_back (0);
        }

        for (int root : roots) {
            dfs (root, 0, -1, root, true);
        }
    }
    void dfs (int node, int level = 0, int parent = -1, int root = 0, bool modify = false) {
        visited[node] = true;

        for (auto [to, weight] : adj[node]) {
            if (!visited[to]) {
                dfs (to, level + 1, node, root, modify);
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
                dfs (vertex, 0, -1, vertex, false);
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

    /*
    void populate_distances() {
        // distances = mat;
        for (int node = 0; node < n; node++) {
            for (auto [to, weight] : adj[node]) {
                if (to == node) {
                    distances[node][to] = 0;
                } else if (weight == -1) {
                    distances[node][to] = INF;
                } else {
                    distances[node][to] = weight;
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (distances[i][k] < INF && distances[k][j] < INF) {
                        distances[i][j] = min (distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }
    }
    */
};

int solve() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    int n, m;
    cin >> n >> m;
    Graph g (n, m);
    return 0;
}

int main() {
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
