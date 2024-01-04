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
    int n, m;
    cin >> n >> m;
    int a[n][m];
    set<int> x;
    set<int> y;
    to (i, 0, n, i + 1) {
        to (j, 0, m, j + 1) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                x.insert (i);
                y.insert (j);
            }
        }
    }
    n = n - x.size();
    m = m - y.size();
    int limit = min (n, m);

    if (limit % 2 == 0) {
        cout << "Vivek";
    } else {
        cout << "Ashish";
    }

    return 0;
}