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
#define vin(a) {rep (_, sz (a)) { in (a[_]) }}
#define vvin(r, c) rep(__,r) { rep(_,c) { in (matrix[__][_]) } }
#define br cout << "\n";
#define out(_,__) cout << _ << __;
#define o(_) out(_, " ")
#define vout(__) for (int _ : __) { o (_) } br
#define vvout(___)  for (vi __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

int n;
vector<vector<ii>> adj;
vector<bool> visited;

ll bfs (int root) {
    queue<int> todo;
    todo.push (root);
    bool flag = false;

    while (!todo.empty()) {
        int node = todo.front();
        todo.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        for (auto surr : adj[node]) {
            if (surr.S != -1) {
                flag = true;
            }

            todo.push (surr.F);
        }
    }

    return flag ? 1 : 2;
}

int solve() {
    fastio;
    in (n);
    adj = vector<vector<ii>> (n);
    visited = vector<bool> (n, false);
    vi a (n), b (n), c (n);
    vin (a);
    vin (b);
    vin (c);

    for (int i = 0; i < n; i++) {
        int A, B, C;
        A = a[i] - 1;
        B = b[i] - 1;
        C = c[i] - 1;

        if (B != A) {
            adj[A].pb (mp (B, C));
            adj[B].pb (mp (A, C));
        }
    }

    ll count = 1;

    for (int root = 0; root < n; root++) {
        if (visited[root]) {
            continue;
        }

        if (sz (adj[root]) == 0) {
            continue;
        }

        count *= bfs (root);
        count %= MOD;
    }

    o (count);
    br;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    in (t);

    while (t--) {
        solve();
    }
}
