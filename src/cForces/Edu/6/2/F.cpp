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
#define vin(a) rep (_, sz (a)) { in (a[_]) }
#define vvin(r, c) rep(__,r) { rep(_,c) { in (matrix[__][_]) } }
#define br cout << "\n";
#define out(_,__) cout << _ << __;
#define o(_) out(_, " ")
#define vout(__) for (int _ : __) { o (_) } br
#define vvout(___)  for (vi __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

bool find (vc s, string p, int n) {
    map<char, deque<int>> l;
    rep (__, n) {
        if (s[__] == '.')
            continue;

        l[s[__]].pb (__);
    }
    int starti = l[p[0]].front();
    l[p[0]].pop_front();

    for (int i = 1; i < sz (p); i++) {
        if (sz (l[p[i]]) == 0)
            return false;

        int nexti = upper_bound (all (l[p[i]]), starti) - l[p[i]].begin();

        if (nexti >= sz (l[p[i]]))
            return false;

        starti = l[p[i]][nexti];

        for (int j = 0; j <= nexti; j++)
            l[p[i]].pop_front();
    }

    return true;
}

bool valid (vc s, string p, vi a, int x, int n) {
    rep (__, x) {
        s[a[__] - 1] = '.';
    }
    return find (s, p, n);
}
int solve() {
    fastio;
    string t, p;
    in2 (t, p);
    int n = sz (t);
    vc s(n);
    rep (__, n) s[__] = t[__];
    vi a (n);
    vin (a);
    int l = 0;
    int r = n;
    int n_iter = 100;

    while (n_iter--) {
        int m = l + (r - l) / 2;

        if (valid (s, p, a, m, n))
            l = m;
        else
            r = m;
    }

    o (l);
    br;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // in (t);

    while (t--)
        solve();
}
