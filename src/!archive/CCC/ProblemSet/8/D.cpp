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
    int n, k;
    cin >> n >> k;
    vi x (k);
    vi nom (k);
    // ll f = 1, e = k;
    // while (f <= e)
    // {
    //     ll m = (f + e) / 2;
    // }
    to (i, 0, k, 1) {
        cin >> x[i];
        nom[i] = n - x[i];
    }
    sort (nom.begin(), nom.end());
    vll psnom (k + 1);
    to (i, 1, k + 1, 1) {
        psnom[i] = nom[i - 1] + psnom[i - 1];

        if (psnom[i] > n - 1) {
            cout << i - 1;
            return 0;
        }
    }
    cout << k;
    return 0;
}