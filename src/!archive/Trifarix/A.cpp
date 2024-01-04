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
    ll n;
    cin >> n;
    vll a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort (all (a));
    int k;
    cin >> k;
    ll min = MOD * MOD;

    for (ll i = 0; i < n - k + 1; i++) {
        ll len = a[i + k - 1] - a[i] + 1;

        if (len < min) {
            min = len;
        }
    }

    cout << min;
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}
