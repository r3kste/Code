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
    int n, k, q;
    cin >> n >> k >> q;
    vi a (n);
    ll c = 0;
    ll o = 0;
    vll temps;
    to (i, 0, n, 1) {
        cin >> a[i];

        if (a[i] <= q) {
            c++;
        } else {
            // if (i != n - 1)
            // {
            //     temps.push_back(c);
            c = 0;
            // }
        }

        if (c >= k) {
            o += (c - k + 1);
        }
    }
    // temps.push_back(c);
    // c = 0;
    // to(i, 0, temps.size(), 1)
    // {
    //     int w = max(temps[i] - k + 1, (ll)0);
    //     c += ((w + 1) * w) / 2;
    // }
    cout << o;
    return 0;
}