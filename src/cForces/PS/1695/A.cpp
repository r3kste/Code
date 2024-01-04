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
    int mr = -1;
    int mc = -1;
    int maxa = -int (MOD);
    vector<vector<int>> aa (n, vector<int> (m) );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aa[i][j];

            if (aa[i][j] > maxa) {
                mr = i;
                mc = j;
                maxa = aa[i][j];
            }
        }
    }

    int a = mr + 1;
    int b = mc + 1;
    int c = n - a + 1;
    int d = m - b + 1;
    a = max (a, c);
    b = max (b, d);
    cout << a*b;
    // int h = max (mr + 1, n - mr);
    // int w = max (mc + 1, m - mc);
    // cout << h*w;
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
