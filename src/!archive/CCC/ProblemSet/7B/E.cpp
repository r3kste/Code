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

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    int n;
    cin >> n;
    vi a (n);
    to (i, 0, n, 1) {
        cin >> a[i];
    }
    int o = 360;
    to (i, 0, n, 1) {
        int s = 0;
        to (j, 0, n, 1) {
            s += a[ (i + j) % n];
            o = min (o, abs (360 - s * 2));
        }

        if (o == 0) {
            cout << 0;
            return 0;
        }
    }
    cout << o;
    return 0;
}