#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl "\n"
#define yesno(a) cout << ((a) ? "Yes" : "No");

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;

int solve() {
    fastio;
    int n;
    cin >> n;
    ll moves = 0;
    ll x = 0;
    // ll sum = 0;
    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // sum += a[i];
    }

    // cout << (ll)(ceil(sum / 2.0) + 1);
    sort (all (a) );
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        // if (x >= a[r])
        // {
        //     x = 0;
        //     r--;
        //     moves++;
        // }
        // else
        // {
        //     int m=1;
        //     if (l != r)
        //         m = min(a[l], a[r] - x);
        //     a[l] -= m;
        //     x += m;
        //     moves += m;
        //     if (a[l] == 0)
        //     {
        //         l++;
        //     }
        // }
        if (l != r) {
            if (a[l] < a[r] - x) {
                x += a[l];
                moves += a[l];
                l++;
            } else {
                a[l] -= (a[r] - x);
                moves += a[r] - x + 1;
                r--;

                if (a[l] == 0) {
                    l++;
                }

                x = 0;
            }
        } else {
            if (a[l] == 0) {
                break;
            }

            if (a[l] == 1) {
                moves++;
                break;
            }

            moves += (ceil ( (a[l] - x) / 2.0) + 1);
            l++;
        }
    }

    cout << moves;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
