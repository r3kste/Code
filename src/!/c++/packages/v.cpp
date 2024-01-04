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

int bsearch_l (vi a, int x) {
    int n = sz (a);
    int ptr = 0;

    for (int jump = n / 2; jump >= 1; jump /= 2) {
        while (ptr + jump < n && a[ptr + jump] <= x) {
            ptr += jump;
        }
    }

    return (ptr);
}
int bsearch_r (vi a, int x) {
    vi b = a;
    reverse (all (b));
    int n = sz (b);
    int ptr = 0;

    for (int jump = n / 2; jump >= 1; jump /= 2) {
        while (ptr + jump < n && b[ptr + jump] >= x) {
            ptr += jump;
        }
    }

    return (n - 1 - ptr);
}
int main() {
    return 0;
}
