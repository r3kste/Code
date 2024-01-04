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
    ll a, b;
    cin >> a >> b;
    ll diff = abs (b - a);
    ll score = diff + 1;
    ll l = a - score;
    ll r = a + score;

    if (l < 0) {
        cout << r << "\n";
        // if (r <= 1000000000)
        // {
        //     cout << r << "\n";
        // }
        // else
        // {
        //     cout << -1 << "\n";
        // }
    } else {
        cout << 0 << "\n";
    }

    return 0;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}