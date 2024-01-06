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

vi slicing (vector<int>& arr, int X, int Y) {
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    vi result (Y - X);
    copy (start, end, result.begin());
    return result;
}
bool f (vi a, int distance) {
    if (sz (a) == 1) {
        return a[0] == distance;
    } else {
        vi ifh, efh, ish, esh;
        int n = sz (a);
        efh = slicing (a, 0, n / 2);
        ifh = slicing (a, 0, (1 + n) / 2);
        esh = slicing (a, (1 + n) / 2, n);
        ish = slicing (a, n / 2, n);
        return ((f (efh, distance) && f (ish, distance + 1)) || (f (efh, distance + 1) && f (ish, distance))
                || (f (ifh, distance) && f (esh, distance + 1)) || (f (ifh, distance + 1) && f (esh, distance)));
    }
}
int solve() {
    fastio;
    int n;
    in (n);
    vi a (n);
    vin (a);
    //f(a,i) = is a possible or not giving i (0 or 1) to that subtree
    //ans = f(a,0)
    //f(a,i) = f(a.firsthalf, i) and f(a.secondhalf, i+1) or f(a.firsthalf,i+1) and f(secondhalf, i)
    //f(a,i) when a is one node: if node==i, true else false

    if (f (a, 0)) {
        oyes;
    } else {
        ono;
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
