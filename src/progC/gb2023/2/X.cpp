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
    // cout << n << " ";

    if (n == 1) {
        cout << -1;
        return 0;
    }

    ll moves = 2 * (n / 11);
    n %= 11;

    if (moves == 0) {
        if (n == 1) {
            cout << -1;
        } else if (n < 6) {
            cout << 1;
        } else if (n == 6) {
            cout << 2;
        } else if (n == 7) {
            cout << 3;
        } else if (n < 11) {
            cout << 2;
        }
    } else {
        if (n == 0) {
            cout << moves;
        } else if (n < 6) {
            cout << moves + 1;
        } else {
            cout << moves + 2;
        }
    }

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