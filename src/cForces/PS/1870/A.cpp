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
    int n, k, x;
    cin >> n >> k >> x;

    if (k - x > 1) {
        cout << -1;
    } else if (k - x == 1 && n - x < 1) {
        cout << -1;
    } else {
        if (k == x) {
            x--;
        }

        int kk = 0;
        int c = 1;
        ll sum = 0;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (k - 1 == kk) {
                flag = true;
            }

            if (k == kk) {
                flag = true;
                kk = x;
                c = 0;
            }

            sum += (kk);
            kk += c;
        }

        if (flag) {
            cout << sum;
        } else {
            cout << -1;
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
