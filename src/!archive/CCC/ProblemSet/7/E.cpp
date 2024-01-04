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
    int n;
    ll o = 0;
    cin >> n;
    vi a (n);
    to (i, 0, n, 1) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] - 1;
        return 0;
    }

    sort (begin (a), end (a));
    int k = 1;
    o += (a[0] - 1);
    a[0] = 1;
    to (i, 1, n, 1) {
        if (a[i] != a[i - 1]) {
            k++;
            o += (a[i] - k);
            a[i] = k;
        }
    }
    cout << o;
    return 0;
}