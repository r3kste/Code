#include <bits/stdc++.h>
using namespace std;

#define for(i, a, b, c) for (int(i) = ((c > 0) ? (a) : (b - 1)); ((c > 0) ? (i < b) : (i > a - 1)); (i) += c)
#define z(i, n) for (i, 0, n, 1)
#define zc(i, n, c) for (i, 0, n, c)
#define zr(i, a, b) for (i, a, b, 1)
#define zrc(i, a, b, c) for (i, a, b, c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testitr(itr)  \
    fastio;           \
    int t = 1;        \
    if (itr)          \
        cin >> t;     \
    z(i, t)           \
    {                 \
        solve();      \
    }

#define pb push_back

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve();

int main() {
    testitr (false);
}

void solve() {
    fastio;
    ll n, q;
    cin >> n >> q;
    vi a (n);
    z (i, n) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    ll ps[n + 1];
    ps[0] = 0;
    zr (i, 1, n + 1) {
        ps[i] = a[i - 1] + ps[i - 1];
    }
    z (i, q) {
        ll x, y;
        cin >> x >> y;
        cout << ps[n - x + y] - ps[n - x] << "\n";
    }
}