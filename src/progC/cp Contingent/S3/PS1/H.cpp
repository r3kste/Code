#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define int long long

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
vvi adj;
vb visited;
int csz = 0;
void dfs (int node, int parent) {
    visited[node] = true;
    csz++;

    for (auto surr : adj[node]) {
        if (surr == parent || visited[surr]) {
            continue;
        }

        dfs (surr, node);
    }
}
/* int bfs (int start, int end)
{
    queue<tuple<int, bool>> q;
    set<int> see;
    q.push ({start, false});

    while (!q.empty())
    {
        int node = get<0> (q.front());
        bool flag = get<1> (q.front());
        q.pop();

        if (node == end)
        {
            return flag ? 1 : 0;
        }
        else if (see.find (node) != see.end())
        {
            continue;
        }
        else
        {
            see.insert (node);

            for (auto surr : adj[node])
            {
                if (flag || surr.S == 1)
                {
                    flag = true;
                    q.push ({surr.F, flag});
                }
                else
                {
                    q.push ({surr.F, flag});
                }
            }
        }
    }

    return 0;
} */

ll power (ll x, int y, ll mod) { // Binary Exponentiation of x^y % mod
    ll o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) { // Checks if LSB of y is 1.
            o = (o * x) % mod;
        }

        y >>= 1; // y = y/2
        x = (x * x) % mod;
    }

    return o;
}

int solve() {
    fastio;
    ll n, k;
    in2 (n, k);
    adj = vvi (n);
    visited = vb (n, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        in3 (u, v, x);
        u--;
        v--;

        if (x == 0) {
            adj[u].pb (v);
            adj[v].pb (u);
        }
    }

    ll ans = power (n, k, MOD);

    for (int root = 0; root < n; root++) {
        if (visited[root]) {
            continue;
        }

        /* queue<int> todo;
        todo.push (root);
        set<int> cluster;
        cluster.insert (root)*/
        csz = 0;
        dfs (root, -1);
        /* while (!todo.empty())
        {
            int node = todo.front();
            todo.pop();

            if (visited[node])
            {
                continue;
            }

            visited[node] = true;

            for (auto surr : adj[root])
            {
                todo.push (surr);
                cluster.insert (surr);
            }
        }
        ans -= power (cluster.size(), k, MOD)*/
        ans -= power (csz, k, MOD);
        ans += MOD * 2;
        ans %= MOD;
    }

    o (ans);
    br;
    /*
    f (i, j, k) = no of good sequences from node 'i' to node 'j' with sequence length as k;
    ans = f (0, 0, k) + f (0, 1, k) + ... f (n - 1, n - 1, k)
    f (i, j, k) = sum (f (i, a, 1) + f (a, j, k - 1))
    */
    /*
    ll ans = 0;
    queue<tuple<int, int, int>> f;
    set<tuple<int, int, int>> seen;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f.push ({i, j, k});
        }
    }

    while (!f.empty())
    {
        int i, j, k;
        auto state = f.front();
        f.pop();
        i = get<0> (state);
        j = get<1> (state);
        k = get<2> (state);

        if (k < 1)
        {
            continue;
        }

        if (k == 1)
        {
            ans += bfs (i, j);
        }
        else
        {
            for (int iii = 0; iii < n; iii++)
            {
                f.push ({i, iii, 1});
                f.push ({iii, j, k - 1});
            }
        }
    }

    o (ans);
    br; */
    return 0;
}

int32_t main() {
    fastio;
    int t = 1;
    // in (t);

    while (t--) {
        solve();
    }
}
