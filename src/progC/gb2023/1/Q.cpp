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
    char grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int i = 0, j = 0;
    int dir = 1;
    int coins = 0;
    int maxcoins = 0;

    while (i < n) {
        char c = grid[i][j];

        if (c == '.') {
            coins++;
            maxcoins = max (maxcoins, coins);
        }

        if (c == 'L') {
            coins = 0;
        }

        j += dir;

        if (j == m) {
            i++;

            if (i == n) {
                break;
            }

            j = m - 1;
            dir = -1;
        }

        if (j == -1) {
            i++;

            if (i == n) {
                break;
            }

            j = 0;
            dir = 1;
        }
    }

    cout << maxcoins;
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