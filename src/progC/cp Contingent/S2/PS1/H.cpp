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
    int n, x;
    cin >> n >> x;
    vii inp (n);

    for (int i = 0; i < n; i++) {
        cin >> inp[i].F;
    }

    for (int i = 0; i < n; i++) {
        cin >> inp[i].S;
    }

    //f(i,x) = maximum number of pages until i'th book with x coins
    //ans = f(n,x)
    //4 8  5 3
    //5 12 8 1
    vector<vi> dp (n + 1, vi (x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (i == 0 || j == 0) {
                break;
            }

            if (j - inp[i - 1].F >= 0) {
                dp[i][j] = max (inp[i - 1].S + dp[i - 1][j - inp[i - 1].F], dp[i - 1][j]);
                //              bought the previous book                    didn't
            } else {
                dp[i][j] = dp[i - 1][j];
                //          couldn't
            }
        }
    }

    cout << dp[n][x];
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