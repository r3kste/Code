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
vector<vector<int>> distances;
int d (int start, int target) {
    if (distances[start][target] != MOD) {
        return distances[start][target];
    } else {
        queue<ii> todo;
        visited = vb (n, false);
        todo.push (mp (start, 0));

        while (!todo.empty()) {
            int node = todo.front().F;
            int dist = todo.front().S;
            todo.pop();

            if (node == target) {
                distances[start][target] = dist;
                distances[target][start] = dist;
                return dist;
            }

            if (visited[node]) {
                continue;
            }

            visited[node] = true;

            for (auto surr : adj[node]) {
                todo.push (mp (surr, dist + 1));
            }
        }
    }

    return MOD;
}

int solve() {
    fastio;
    int s, t;
    in2 (n, m) in2 (s, t);
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, false);
    distances = vector<vector<int>> (n, vector<int> (n, MOD));

    for (int i = 0; i < m; i++) {
        int u, v;
        in2 (u, v);
        u--;
        v--;
        adj[u].pb (v);
        adj[v].pb (u);
    }

    s--;
    t--;
    int cur_dist = d (s, t);
    ll ans = 0;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b || find (adj[a].begin(), adj[a].end(), b) != adj[a].end()) { //if b is already directly connected to a
                continue;
            }

            int dist1 = d (s, a) + d (b, t) + 1; // s->a->b->t
            int dist2 = d (s, b) + d (a, t) + 1; // s->b->a->t

            if (min (dist1, dist2) >= cur_dist) {
                ans ++;
            }
        }
    }

    o (ans / 2);
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
