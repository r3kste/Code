#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
/*
Unweighted Graph
*/
struct Graph {
    vector<vector<int>> adj;
    int n;
    vector<bool> visited;
    vector<int> roots;

    Graph (int no_of_nodes) {
        adj.resize (no_of_nodes);
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
    void dfs (int node) {
        visited[node] = true;

        for (auto to : adj[node]) {
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

/*
Unweighted GRAPH
*/
struct GRAPH {
    vector<vector<int>> adj;
    int n;
    vector<bool> visited;

    vector<int> height, eulerian, first, segtree, subtree_size;
    vector<int> roots;
    int timer;
    int depth;
    vector<int> tin, tout;

    GRAPH (int no_of_nodes) {
        adj.resize (no_of_nodes);
        n = no_of_nodes;
    }

    /*
    Repopulates:
        1. visited
        2. height
        3. first
        4. eulerian
        5. tin
        6. tout
        7. subtree_size
        8. timer
        9. depth
        10. segtree (dependent on Population)
    */
    void init (bool fill = true) {
        visited.assign (n, false);
        height.resize (n);
        first.resize (n);
        eulerian.reserve (n * 2);
        tin.resize (n);
        tout.resize (n);
        subtree_size.resize (n);
        timer = 0;
        depth = -1;

        if (fill) {
            DFS ();
            //
            int m = eulerian.size();
            segtree.resize (m * 4);
            build (1, 0, m - 1);
        }
    }

    /*
    Depopulates:
        1. visited
        2. height
        3. first
        4. eulerian
        5. tin
        6. tout
        7. subtree_size
        8. timer
        9. depth
        10. segtree (dependent on Population)
    */
    void clear() {
        visited.clear();
        height.clear();
        first.clear();
        eulerian.clear();
        tin.clear();
        tout.clear();
        subtree_size.clear();
        timer = 0;
        depth = -1;
        segtree.clear();
    }

    /*
    Populates: adj (with stdin)
    */
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
    /*
    Repopulates (via depth-first traversal):
        1. visited
        2. tin
        3. height
        4. first
        5. eulerian
        6. depth
        7. subtree_size
        8. tout
    */
    void DFS (int h = 0) {
        for (int root : roots) {
            dfs (root, h);
        }
    }
    void dfs (int node, int h = 0) {
        visited[node] = true;
        tin[node] = ++timer;
        height[node] = h;
        first[node] = eulerian.size();
        eulerian.push_back (node);
        depth = max (depth, h);

        for (int to : adj[node]) {
            if (!visited[to]) {
                dfs (to, h + 1);
                eulerian.push_back (node);
                subtree_size[node] += subtree_size[to];
            }
        }

        subtree_size[node]++;
        tout[node] = ++timer;
    }

    void bfs (int root, int h = 0) {
        queue<int> q;
        vector<bool> visited (n);
        vector<int> parents (n);
        q.push (root);
        visited[root] = true;
        parents[root] = -1;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            for (int u : adj[vertex]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push (u);
                    height[u] = height[vertex] + 1;
                    parents[u] = vertex;
                }
            }
        }
    }

    /*
    Repopulates: roots
    */
    void find_components () {
        fill (visited.begin(), visited.end(), false);
        roots.clear();

        for (int vertex = 0; vertex < n; ++vertex) {
            if (!visited[vertex]) {
                roots.push_back (vertex);
                dfs (vertex);
            }
        }
    }

    /*
    Checks whether parents is an ancestor (direct or indirect) of child
    */
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
};

/*
Weighted Graph
*/
struct Graph_EV {
    using pii = pair<int, int>;
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
    void dijkstra_pqu (int start, vector<long long int> &distances, vector<int> &parents) {
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
};

int solve() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    int n, m;
    cin >> n >> m;
    GRAPH graph (n);
    return 0;
}

int main() {
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
