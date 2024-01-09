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

int n;
vector<vector<int>> adj;
vector<bool> visited;
vll distances;
void populate_distances (int node, int depth) {
    visited[node] = true;
    distances[node] = depth;

    for (auto surr : adj[node]) {
        if (visited[surr]) {
            continue;
        }

        populate_distances (surr, depth + 1);
    }
}

int farthest_from (int root) {
    queue<int> todo;
    todo.push (root);
    int far = root;

    while (!todo.empty()) {
        int node = todo.front();
        todo.pop();

        if (!visited[node]) {
            far = node;
        }

        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        for (auto surr : adj[node]) {
            todo.push (surr);
        }
    }

    return far;
}

int solve() {
    fastio;
    int n;
    in (n);
    adj = vector<vector<int>> (n);
    distances = vll (n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    vll dist;
    visited = vector<bool> (n, false);
    populate_distances (0, 0); //populate distances with distance from 0
    dist = distances;
    visited = vector<bool> (n, false);
    int a = farthest_from (0);
    visited = vector<bool> (n, false);
    int b = farthest_from (a);
    visited = vector<bool> (n, false);
    populate_distances (b, 0);
    rep (__, n) {
        dist[__] = max (dist[__], distances[__]);
    }
    visited = vector<bool> (n, false);
    populate_distances (a, 0);
    rep (___, n) {
        dist[___] = max (dist[___], distances[___]);
    }
    sort (all (dist));

    for (int k = 1; k <= n; k++) {
        int ptr = lower_bound (all (dist), k) - begin (dist);
        out (min (n, ptr + 1), " ");
    }

    br;
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
