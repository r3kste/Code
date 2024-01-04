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
    vi a (n), o (n);
    to (i, 0, n, 1) {
        cin >> a[i];
    }
    to (i, 0, n, 1) {
        o[i] = i;
    }
    to (i, 0, n + 1, 1) {
        bool flag = true;
        to (j, 0, n, 1) {
            if (a[j] != o[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Yes";
            return 0;
        }

        to (j, 0, n, 1) {
            int e = (j % 2 == 0) ? 1 : -1;
            a[j] = (a[j] + e);

            if (a[j] == -1) {
                a[j] = n - 1;
            }

            if (a[j] == n) {
                a[j] = 0;
            }
        }
    }
    cout << "No";
    return 0;
}