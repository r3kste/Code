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

ll valid (ll x, int n, int k) {
    return x - (x / n);
}
int solve() {
    fastio;
    int n, k;
    in2 (n, k);
    ll l = 1;
    ll r = min ((ll)10e12, (ll)n * k);

    while (valid (r, n, k) < k) {
        r *= n;
    }

    ll ans = 0;

    while (true) {
        ll m = l + (r - l) / 2;
        ll sup = valid (m, n, k);

        if (sup == k) {
            ans = m;
            break;
        } else if (sup > k) {
            r = m;
        } else if (sup < k) {
            l = m;
        }
    }

    if (ans % n == 0) {
        ans--;
    }

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
