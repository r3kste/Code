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
    int n, c = 0;
    cin >> n;
    vi a (n);
    to (i, 0, n, 1) {
        cin >> a[i];

        if (i > 1) {
            if (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i]) {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}