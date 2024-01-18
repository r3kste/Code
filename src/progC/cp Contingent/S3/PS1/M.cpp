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
vector<int> dp;
vector<bool> dpd;
vll subtree_size;
ll ans = 0;

void dfs (int node, int parent, int match) {
    if (subtree_size[node] == 1) {
        return;
    }

    match = max (0, match - 1); //what?
    int maxchild = -1;

    for (auto surr : adj[node]) {
        if (surr == parent) {
            continue;
        }

        if (maxchild == -1) {
            maxchild = surr;
        } else {
            if (subtree_size[surr] > subtree_size[maxchild]) {
                maxchild = surr;
            }
        }
    }

    int remaining = subtree_size[node] - subtree_size[maxchild] - 1;

    if (remaining + match >= subtree_size[maxchild]) {
        ans += (subtree_size[node] - 1 - match) / 2;
    } else {
        ans += remaining;
        dfs (maxchild, node, match + remaining);
    }
}

void subtrees (int node, int parent) {
    for (auto surr : adj[node]) {
        if (surr != parent) {
            subtrees (surr, node);
            subtree_size[node] += subtree_size[surr];
        }
    }

    subtree_size[node]++;
}

int solve() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    int n;
    cin >> n;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, false);
    subtree_size = vll (n, 0);
    ans = 0;

    for (int i = 1; i < n; i++) {
        int u;
        in (u);
        u--;
        adj[u].push_back (i);
        adj[i].push_back (u);
    }

    subtrees (0, -1);
    dfs (0, -1, 0);
    o (ans) br;
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
