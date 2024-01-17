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

int solve() {
    fastio;
    int n;
    in (n);
    vi aa (n), bb (n);
    vin (aa);
    vin (bb);
    priority_queue<int, vi> a (all (aa));
    priority_queue<int, vi> b (all (bb));
    int op = 0;

    while (true) {
        if (a.top() == b.top()) {
            a.pop();
            b.pop();

            if (a.empty()) {
                break;
            }
        } else {
            op++;

            if (a.top() > b.top()) {
                int temp = a.top();
                a.pop();
                a.push (to_string (temp).size());
            } else {
                int temp = b.top();
                b.pop();
                b.push (to_string (temp).size());
            }
        }
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
