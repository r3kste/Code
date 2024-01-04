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
    ll n, l, r;
    cin >> n >> l >> r;
    ll c = 0;

    if (n > 2 * (r - l - 1)) {
        cout << -1;
    } else {
        l += 2;

        while (l <= r && c < n) {
            cout << l << " ";
            c++;
            l -= 2;

            if (c < n) {
                cout << l << " ";
                c++;
                l += 3;
            }

            if (c == n || l > r) {
                break;
            }
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