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
    int n, k;
    cin >> n >> k;

    if (k % 3 == 1) {
        cout << "Yes\n" << k;
    } else if (k % 3 == 2) {
        cout << "No\n" << k;
    } else {
        if (n % 2 == 0) {
            if (k % 6 == 0) {
                cout << "Yes\n" << n + k / 3;
            } else {
                cout << "No\n" << n + k / 3;
            }
        } else {
            if (k % 6 == 0) {
                cout << "No\n" << n + k / 3 + 1;
            } else {
                cout << "Yes\n" << n + k / 3 + 1;
            }
        }
    }

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