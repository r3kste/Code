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
    vi a (n);
    ll max = -MOD;
    vi ps (n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];

        if (a[i] > max) {
            max = a[i];
        }
    }

    ll ans = max;
    int l = 0;
    // int r = n - 1;
    int ptr = 1;
    ll sum = 0;

    while (l < n - 1 && ptr < n) {
        ll temp = a[ptr] + a[ptr - 1];

        if (a[l] < 0) {
            l++;
            ptr = l + 1;
        } else {
            if (temp % 2 != 0) {
                ptr++;
            } else {
                l++;
                ptr = l + 1;
            }
        }

        sum = ps[ptr] - ps[l];

        if (sum > ans) {
            ans = sum;
        }

        if (sum <= 0) {
            l++;
            ptr = l + 1;
        }
    }

    cout << ans;
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
