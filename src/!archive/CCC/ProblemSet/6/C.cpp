#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for (int(i) = ((c > 0) ? (a) : (b - 1)); ((c > 0) ? (i < b) : (i > a - 1)); (i) += c)
#define z(i, n) FOR(i, 0, n, 1)
#define zc(i, n, c) FOR(i, 0, n, c)
#define zr(i, a, b) FOR(i, a, b, 1)
#define zrc(i, a, b, c) FOR(i, a, b, c)

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
        cout << "\n"; \
    }

#define pb push_back

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve();

int main() {
    testitr (true);
}

bool check (int l, int r, int x, int y) {
    int g = __gcd (x, y);
    ll lc = x * y / g;
    return (lc <= r);
}

int solve() {
    fastio;
    int l, r;
    cin >> l >> r;
    // int x = l, y = l + 1;

    if (l * 2 <= r) {
        cout << l << " " << l * 2;
    } else {
        cout << -1 << " " << -1;
    }

    return 0;
}