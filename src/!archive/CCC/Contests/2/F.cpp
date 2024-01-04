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
    int n, x;
    cin >> n >> x;
    vi r (n);
    vi s (n);
    vi a (n);
    ll R = 0, S = 0, A = 0;
    to (i, 0, n, i + 1) {
        cin >> a[i];
    }
    to (i, 0, n, i + 1) {
        cin >> s[i];
    }
    to (i, 0, n, i + 1) {
        cin >> r[i];
    }
    to (i, 0, n, i + 1) {
        R = (R | r[i]);
        to (j, 0, n, j + 1) {
            S += s[j];
            to (k, 0, n, k + 1) {
                A += a[k];

                if (A == R && S + A == x) {
                    cout << "yes";
                    return 0;
                }
            }
        }
    }
    cout << "no";
    return 0;
}