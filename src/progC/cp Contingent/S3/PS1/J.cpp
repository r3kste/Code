#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

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
vector<vector<ii>> adj;
vector<bool> visited;
vll position;
vb positiond;

bool bfs (ll root, ll spos) {
    queue<ii> todo;
    todo.push (mp (root, spos));

    while (!todo.empty()) {
        ll node = todo.front().F;
        ll pos = todo.front().S;
        todo.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        for (auto surr : adj[node]) {
            ll d = surr.S;//adj(some)

            if (positiond[surr.F]) {
                if (position[surr.F] != pos + d) {
                    return false;
                }
            } else {
                todo.push (mp (surr.F, pos + d));
                position[surr.F] = pos + d;
                positiond[surr.F] = true;
            }
        }
    }

    return true;
}

int solve() {
    fastio;
    ll m;
    in2 (n, m);
    adj = vector<vector<ii>> (n);
    visited = vector<bool> (n, false);
    position = vll (n);
    positiond = vb (n);

    for (int i = 0; i < m; i++) {
        ll u, v, d;
        in3 (u, v, d);
        u--;
        v--;
        adj[u].pb (mp (v, d));
        adj[v].pb (mp (u, -d));
    }

    for (ll root = 0; root < n; root++) {
        if (visited[root]) {
            continue;
        }

        if (!bfs (root, 0)) {
            ono;
            return 0;
        }
    }

    oyes;
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