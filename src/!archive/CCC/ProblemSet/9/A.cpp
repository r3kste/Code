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
    int n;
    cin >> n;
    vi a;
    ll o = 0;
    int c = 0;
    to (i, 0, n, 1) {
        int temp;
        cin >> temp;

        if (temp != 0) {
            a.push_back (temp);
        }

        // if (i == 0)
        // {
        //     continue;
        // }
        // int b0 = (a[i] == 0) ? 0 : a[i] / abs(a[i]);
        // int b1 = (a[i - 1] == 0) ? 0 : a[i - 1] / abs(a[i - 1]);
        // if (b0 > 0 && b1 < 1 || b0 < 0 && b1 > -1)
        // {
        //     c++;
        // }
    }
    n = a.size();
    to (i, 0, n, 1) {
        o += abs (a[i]);
    }
    a.push_back (1);
    to (i, 0, n, 1) {
        if (a[i] < 0) {
            if (a[i + 1] < 0) {
                continue;
            } else {
                c++;
            }
        }
    }
    // int signi = (a[0] == 0) ? 0 : a[0] / abs(a[0]);
    // to(j, 1, n, 1)
    // {
    //     int signj = (a[j] == 0) ? 0 : a[j] / abs(a[j]);
    //     if (signi == -signj)
    //     {
    //         c++;
    //     }
    // }
    cout << o << " " << c;
    return 0;
}