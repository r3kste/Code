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
    int n, m;
    cin >> n >> m;
    int minindex = (n < m) ? 0 : 1;
    int ans = MOD;

    for (int i = 1; i < (n + m); i++) {
        int a = n + m - i;
        int b = i;

        if (a % b == 0) {
            int cnt = 0;

            if (minindex == 0) {
                cnt = abs (a - n);
            } else {
                cnt = abs (b - m);
            }

            if (cnt < ans) {
                ans = cnt;
            }
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