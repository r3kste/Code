#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve() {
    fastio;
    int n;
    cin >> n;
    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sort(a.begin(), a.end());
    ll c = 0;
    ll b = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         c += a[i];
    //     }
    //     else
    //     {
    //         b += a[i];
    //     }
    // }
    // cout << max(b, c) << " " << min(b, c) << "\n";
    int l = 0;
    int r = n - 1;
    int i = 0;

    while (l <= r) {
        if (i % 2 == 0) {
            c += max (a[l], a[r]);
        } else {
            b += max (a[l], a[r]);
        }

        i++;

        if (a[l] > a[r]) {
            l++;
        } else {
            r--;
        }
    }

    cout << c << " " << b;
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        // cout << "\n";
    }
}
