#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define int long long int
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

bool valid (vector<tuple<int, int, int, int>> p, int m, int T) {
    int n = sz (p);
    ll no_balloons = 0;
    rep (_, n) {
        int t = get<0> (p[_]);
        int z = get<1> (p[_]);
        int y = get<2> (p[_]);
        int cT = T;
        int cycle = z * t + y;
        no_balloons += z * floor (cT / cycle);
        cT %= cycle;
        no_balloons += min (z, (ll)floor (cT / t));
    }
    return no_balloons >= m;
}
int solve() {
    fastio;
    int req, n;
    in2 (req, n);
    vector<tuple<int, int, int, int>> p (n);
    rep (__, n) {
        int t, z, y;
        in3 (t, z, y);
        p[__] = {t, z, y, __};
    }
    int l = 0;
    int r = 10e9;

    while (!valid (p, req, r)) {
        r *= 2;
    }

    int n_iter = 100;

    while (n_iter--) {
        int m = l + (r - l) / 2;

        if (valid (p, req, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    o (r);
    br;
    sort (all (p));
    int tno_balloons = 0;
    int T = r;
    vi ans (n, 0);
    rep (_, n) {
        int no_balloons = 0;
        int t = get<0> (p[_]);
        int z = get<1> (p[_]);
        int y = get<2> (p[_]);
        int index = get<3> (p[_]);
        int cT = T;
        int cycle = z * t + y;
        no_balloons += z * floor (cT / cycle);
        cT %= cycle;
        no_balloons += min (z, (ll)floor (cT / t));
        ans[index] = no_balloons;
        tno_balloons += no_balloons;

        if (tno_balloons >= req) {
            ans[index] -= (tno_balloons - req);
            break;
        }
    }
    vout (ans);
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
