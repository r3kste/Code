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
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    int n;
    cin >> n;
    vi a (3);
    a[0] = 1;
    a[1] = 3;
    int k = 2;
    int p, b;
    int c = 0;

    for (int i = 3; i < 1e6; i++) {
        if (c >= n) {
            return 0;
        }

        if (k == 0) {
            p = 1;
            b = 2;
        } else if (k == 1) {
            p = 2;
            b = 0;
        } else {
            p = 0;
            b = 1;
        }

        if (((3 * i) % (a[p] + a[b])) != 0) {
            a[k % 3] = i;
            k++;
            cout << i << " ";
            c++;
        }
    }

    return 0;
}