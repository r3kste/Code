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
long long int power (long long int x, ll y, long long int mod) {
    long long int o = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1) {
            o = (o * x) % mod;
        }

        y >>= 1;
        x = (x * x) % mod;
    }

    return o;
}
long long int inv (long long int n, long long int mod) {
    return power (n, mod - 2, mod);
}
long long int mul (long long int x, long long int y, long long int mod) {
    return (x * y) % mod;
}
long long int div (long long int x, long long int y, long long int mod) {
    return mul (x, inv (y, mod), mod);
}
long long int ncr (long long int n, long long int r, long long int mod) {
    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    if (n - r < r) { // Make sure r is the least one possible
        return ncr (n, n - r, mod);
    }

    long long int o = 1;

    for (ll i = r; i > 0; i--) {
        o = div (mul (o, n - i + 1, mod), i, mod);
    }

    return o;
}

int solve() {
    fastio;
    int n;
    in (n);
    vll a (n);
    vin (a);

    for (int i = 0; i < n; i++) {
        a[i] = a[i] - i;
    }

    map<ll, ll> p;
    ll op = 0;

    for (int i = 0; i < n; i++) {
        ll x = a[i];
        op += p[x];
        p[x]++;
    }

    out (op, "\n");
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
