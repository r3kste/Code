#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;

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
    int n, q;
    cin >> n >> q;
    vi a (n);
    vector<ll> ps (n + 1);
    to (i, 0, n, 1) {
        if (i == 0) {
            cin >> a[0];
            ps[1] = a[0];
            continue;
        }

        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
        a[i] = max (a[i], a[i - 1]);
    }
    to (i, 0, q, 1) {
        ll temp;
        cin >> temp;
        cout << ps[upper_bound (a.begin(), a.end(), temp) - a.begin()] << " ";
    }
    return 0;
}