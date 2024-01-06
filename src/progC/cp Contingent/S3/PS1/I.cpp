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
#define vin(n) rep (_, n) { in (a[_]) }
#define vvin(r, c) rep(__,r) { rep(_,c) { in (matrix[__][_]) } }
#define br cout << "\n";
#define out(_,__) cout << _ << __;
#define o(_) out(_, " ")
#define vout(__) for (int _ : __) { o (_) } br
#define vvout(___)  for (vi __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

int n;
int m;
vector<vector<int>> adj;
vector<bool> visited;
vi distances;
int dfs (int node, int target, int dist) {
    visited[node] = true;

    if (node == target) {
        distances.pb (dist);
    }

    for (auto surr : adj[node]) {
        if (visited[surr]) {
            continue;
        }

        dfs (surr, target, dist + 1);
    }

    return 0;
}
int d (int start, int end) {
    int min = MOD;
    visited = vb (n, false);
    distances.clear();
    dfs (start, end, 0);

    for (auto distance : distances) {
        if (distance < min) {
            min = distance;
        }
    }

    return min;
}
int solve() {
    fastio;
    int s, t;
    in2 (n, m) in2 (s, t);
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        in2 (u, v);
        u--;
        v--;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    o (d (0, 3));
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
