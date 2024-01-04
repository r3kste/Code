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
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = max (0LL, ll (ceil (0.7 * n) - k));

    if (ans > n - m) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    double num = (n - m + k) * 1.0;
    double den = 1.0 * n;
    ans = 100.0 * ((num / den * 1.0));
    cout << ll (floor (ans)) ;
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}