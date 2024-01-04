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

int solve();

int main() {
    fastio;
    int t = 1;

    if (true) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    ll x, n;
    cin >> x >> n;
    vector<ll> a (n);
    vector<ll> c (n);
    to (i, 0, n, 1) {
        ll temp;
        cin >> temp;
        a[i] = temp;
        c[i] = temp * (i + 1);
    }

    if (n == 1) {
        cout << -1;
        return 0;
    }

    bool flag = true;
    ll cost = LLONG_MAX;
    to (i, 0, n, 1) {
        to (j, i + 1, n, 1) {
            if ((a[i] + a[j]) >= x) {
                flag = false;
                cost = min (cost, (c[i] + c[j]));
            }
        }
    }

    if (flag) {
        cost = -1;
    }

    cout << cost;
    return 0;
}