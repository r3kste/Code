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
        // cout << "\n";
    }
}

int solve() {
    fastio;
    int n, q;
    cin >> n >> q;
    vi a (n);
    to (i, 0, n, 1) {
        cin >> a[i];
    }
    sort (begin (a), end (a));
    to (i, 0, q, 1) {
        int type, no;
        cin >> type >> no;

        switch (type) {
        case 1:
            cout << lower_bound (a.begin(), a.end(), no) - a.begin() << "\n";
            break;

        case 2:
            cout << lower_bound (a.begin(), a.end(), no + 1) - a.begin() << "\n";
            break;

        case 3:
            cout << upper_bound (a.begin(), a.end(), no) - lower_bound (a.begin(), a.end(), no) << "\n";

        default:
            break;
        }
    }
    return 0;
}