#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n;
    vector<bool> visited;

    vector<int> height, euler, first, segtree, subtree_size;
    vector<int> roots;
    vector<vector<int>> distances;
    int timer;
    int depth;
    vector<int> tin, tout;

    Graph (vector<vector<int>> &adj, vector<int> roots = {0}) {
        n = adj.size();
        visited.assign (n, false);
        height.resize (n);
        first.resize (n);
        euler.reserve (n * 2);
        tin.resize (n);
        tout.resize (n);
        subtree_size.resize (n);
        timer = 0;
        depth = INT32_MIN;
        DFS (adj, roots);
        int m = euler.size();
        segtree.resize (m * 4);
        build (1, 0, m - 1);
    }
    void DFS (vector<vector<int>> &adj, vector<int> roots, int h = 0) {
        for (int root : roots) {
            dfs (adj, root);
        }
    }
    void dfs (vector<vector<int>> &adj, int node = 0, int h = 0) {
        visited[node] = true;
        tin[node] = ++timer;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back (node);
        depth = max (depth, h);

        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs (adj, to, h + 1);
                euler.push_back (node);
                subtree_size[node] += subtree_size[to];
            }
        }

        subtree_size[node]++;
        tout[node] = ++timer;
    }

    void bfs (vector<vector<int>> &adj, int root,  int h = 0) {
        queue<int> q;
        vector<bool> visited (n);
        vector<int> parent (n);
        q.push (root);
        visited[root] = true;
        parent[root] = -1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push (u);
                    height[u] = height[v] + 1;
                    parent[u] = v;
                }
            }
        }
    }

    void find_components (vector<vector<int>> &adj) {
        fill (visited.begin(), visited.end(), false);

        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                roots.push_back (v);
                dfs (adj, v);
            }
        }
    }

    bool is_ancestor (int parent, int child) {
        return tin[parent] <= tin[child] && tout[parent] >= tout[child];
    }

    void build (int node, int begin, int end) {
        if (begin == end) {
            segtree[node] = euler[begin];
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

        return query (1, 0, euler.size() - 1, left, right);
    }
};

int solve() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj (n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back (v);
        adj[v].push_back (u);
    }

    // for (int i = 0; i < n; i++) {
    //     int u;
    //     cin >> u;
    //     u--;
    //     adj[u].push_back (i);
    //     adj[i].push_back (u);
    // }
    Graph graph (adj);
    return 0;
}

int main() {
    solve();
}