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
    ll n, h;
    cin >> n >> h;
    vll a (n);
    vll diff (n - 1);
    to (i, 0, n, 1) {
        cin >> a[i];

        if (i == 0) {
            continue;
        }

        diff[i - 1] = a[i] - a[i - 1];
    }
    ll k = 0;
    ll f = 1, e = h;

    while (f <= e) {
        ll m = (f + e) / 2;
        ll dam = 0;
        to (i, 0, n - 1, 1) {
            dam += min (m, diff[i]);
        }
        dam += m;

        if (dam >= h) {
            k = m;
            e = m - 1;
        } else {
            f = m + 1;
        }
    }

    cout << k;
    // vi diff(n - 1);
    // vector<ll> apag;
    // int cont = (h / n);
    // int c = 0;
    // to(i, 0, n, 1)
    // {
    //     cin >> a[i];
    //     if (i == 0)
    //         continue;
    //     if (a[i] - a[i - 1] <= cont)
    //     {
    //         sum += (a[i] - a[i - 1]);
    //     }
    //     else
    //     {
    //         c++;
    //     }
    // }
    // if (cont == 0)
    // {
    //     cout << 1;
    // }
    // else
    // {
    //     cout << (h - sum + 1) / (c + 1);
    // }
    // to(i, 0, n, 1)
    // {
    //     cin >> a[i];
    //     if (i == 0)
    //         continue;
    //     diff[i - 1] = a[i] - a[i - 1];
    //     if (diff[i - 1] <= cont)
    //     {
    //         sum += diff[i - 1];
    //     }
    //     else
    //     {
    //         apag.push_back(diff[i - 1]);
    //     }
    // }
    // h = h - sum - 1;
    // sort(apag.begin(), apag.end());
    // vi sums;
    // to(i, 0, apag.size(), 1)
    // {
    //     ll dam = min(ll(h / (apag.size() + 1)), apag[i]);
    //     h -= dam;
    //     sums.push_back(dam);
    // }
    return 0;
}