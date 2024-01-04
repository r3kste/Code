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

typedef vector<vector<int>> matrix;
ll order;
int solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    matrix a (n, vector<int> (m, 0) );
    matrix score (n, vector<int> (m, 0) );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        ll min_row = (int) MOD;

        for (int j = 0; j < m; j++) {
            if (a[i][j] <= min_row) {
                min_row = a[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            if (a[i][j] == min_row) {
                score[i][j]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        ll min_col = (int) MOD;

        for (int j = 0; j < n; j++) {
            if (a[j][i] <= min_col) {
                min_col = a[j][i];
            }
        }

        for (int j = 0; j < n; j++) {
            if (a[j][i] == min_col) {
                score[j][i]++;
            }
        }
    }

    ll c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (score[i][j] == 2) {
                c++;
            }
        }
    }

    cout << c;
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
