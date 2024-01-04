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

int op (vi a) {
    sort (begin (a), end (a));
    to (i, 0, a.size(), 1) {
        a[i] += (a.size() - i);
    }
    return 0;
}

int solve() {
    fastio;
    int n;
    cin >> n;
    vi a (n);
    to (i, 0, n, i + 1) {
        cin >> a[i];
    }
    sort (begin (a), end (a));
    int q;
    cin >> q;
    to (i, 0, q, i + 1) {
        int j, x;
        a[j - 1] = x;
    }
    return 0;
}