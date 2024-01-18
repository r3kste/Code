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
#define vout(__) for (auto _ : __) { o (_) } br
#define vvout(___)  for (auto __ : ___) { vout (__); }

#define oyes out("YES","\n")
#define ono out("NO", "\n")

int n;
vvi dp;
int f (int from, int to) {
    if (from == to) {
        return 0;
    }
}
int solve() {
    fastio;
    in (n);
    vi a (n);
    vin (a);
    vi dp (n - 1);

    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            dp[i] = 1;
        } else {
            if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
                dp[i] = 1;
            } else {
                dp[i] = a[i + 1] - a[i];
            }
        }
    }

    vi dp2 (n - 1);

    for (int i = n - 2; i >= 0; i--) {
        if (i == n - 2) {
            dp2[i] = 1;
        } else {
            if (a[i + 2] - a[i + 1] > a[i + 1] - a[i]) {
                dp2[i] = 1;
            } else {
                dp2[i] = a[i + 1] - a[i];
            }
        }
    }

    vi ps;
    ps.pb (0);

    for (auto e : dp) {
        ps.pb (ps.back() + e);
    }

    vi ps2 (n, 0);

    for (int i = n - 2; i >= 0; i--) {
        ps2[i] = (ps2[i + 1] + dp2[i]);
    }

    int m;
    in (m);

    while (m--) {
        int f, t;
        in2 (f, t);
        f--;
        t--;

        if (t > f) {
            o (ps[t] - ps[f]);
        } else {
            o (ps2[t] - ps2[f]);
        }

        br
    }

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
