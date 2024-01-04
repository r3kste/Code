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
    vi price (n);
    to (i, 0, n, 1) {
        cin >> price[i];
    }
    sort (price.begin(), price.end());
    int q;
    cin >> q;
    vi coins (q);
    to (i, 0, q, 1) {
        int temp;
        cin >> temp;
        cout << upper_bound (price.begin(), price.end(), temp) - price.begin() << "\n";
    }
    return 0;
}