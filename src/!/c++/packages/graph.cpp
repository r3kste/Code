#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dp;
vector<bool> dpd;
vector<int> subtree_size;

void dfs (int node) {
    visited[node] = true;

    for (auto surr : adj[node]) {
        if (visited[surr]) {
            continue;
        }

        dfs (surr);
    }
}

void bfs (int root) {
    queue<int> todo;
    todo.push (root);

    while (!todo.empty()) {
        int node = todo.front();
        todo.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        for (auto surr : adj[node]) {
            todo.push (surr);
        }
    }
}

void populate_subtree_size (int node, int parent) {
    for (auto surr : adj[node]) {
        if (surr != parent) {
            populate_subtree_size (surr, node);
            subtree_size[node] += subtree_size[surr];
        }
    }

    subtree_size[node]++;
}

int solve() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    int n, e;
    cin >> n >> e;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, false);
    dp = vector<int> (n);
    dpd = vector<bool> (n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back (v);
        adj[v].push_back (u);
    }

    return 0;
}

int main() {
}
