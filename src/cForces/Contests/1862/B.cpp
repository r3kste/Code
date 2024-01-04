#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define to(i, a, b, c) for (int(i) = (a); (i) < (b); (i) = (c))
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) = (c))

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

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
    cin >> n;
    vi a (n), b;
    to (i, 0, n, i + 1) {
        cin >> a[i];
    }
    b.push_back (a[0]);
    to (i, 1, n, i + 1) {
        b.push_back (a[i]);

        if (! (a[i] >= a[i - 1])) {
            b.push_back (a[i]);
        }
    }
    cout << b.size() << "\n";
    to (i, 0, b.size(), i + 1) {
        cout << b[i] << " ";
    }
    return 0;
}