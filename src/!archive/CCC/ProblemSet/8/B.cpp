#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve();

int main() {
    fastio;
    int t = 1;

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        // cout << "\n";
    }
}

void solve() {
    fastio;
    int n;
    cin >> n;
    vi a (n);
    vector<ll> ps (n + 1);
    ps[0] = 0;
    to (i, 0, n, 1) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    int m;
    cin >> m;
    to (i, 0, m, 1) {
        ll temp;
        cin >> temp;
        int in = lower_bound (ps.begin(), ps.end(), temp) - ps.begin();
        cout << in << "\n";
        // to(i, 0, n + 1, 1)
        // {
        //     if (temp <= ps[i])
        //     {
        //         cout << i << "\n";
        //         break;
        //     }
        // }
    }
}