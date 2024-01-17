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
ll pow2 (ll n) {
    ll ans = 0;

    while (n % 2 == 0) {
        ans++;
        n /= 2;
    }

    return ans;
}
bool comp (int a, int b) {
    return pow2 (b) > pow2 (a);
}
int solve() {
    fastio;
    int n;
    in (n);
    vi a (n);
    vin (a);
    ll already_pow2 = 0;

    for (int e : a) {
        already_pow2 += pow2 (e);
    }

    if (n - already_pow2 <= 0) {
        o (0);
    } else {
        int req = n - already_pow2;
        int ans = 0;
        vi nos (n);
        iota (all (nos), 1);
        sort (all (nos), comp);

        while (req > 0) {
            if (nos.empty()) {
                break;
            }

            ans++;
            req -= pow2 (nos.back());
            nos.pop_back();
        }

        if (req > 0) {
            o (-1);
        } else {
            o (ans);
        }
    }

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
