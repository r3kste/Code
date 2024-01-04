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
    int n;
    cin >> n;
    ll s = 0;
    // vi a(n);
    to (i, 0, n, 1) {
        int temp;
        cin >> temp;
        s += temp;
    }
    cout << ((s % n == 0) ? 0 : 1);
    // sort(a.begin(), a.end());
    // int u;
    // if (a[n - 1] == a[0])
    // {
    //     cout << 0;
    //     return 0;
    // }
    // to(i, 0, 1, -1)
    // {
    //     vi o(n);
    //     to(j, 0, n, 1)
    //     {
    //         o[j] = a[j];
    //     }
    //     a[n - 1]--;
    //     a[0]++;
    //     sort(a.begin(), a.end());
    //     if (a[n - 1] == a[0])
    //     {
    //         cout << 0;
    //         return 0;
    //     }
    //     if (equal(a.begin(), a.end(), o.begin()))
    //     {
    //         cout << a[n - 1] - a[0];
    //         return 0;
    //     }
    // }
    return 0;
}