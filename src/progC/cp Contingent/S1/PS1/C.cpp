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

typedef vector<vector<double>> matrix;
ll order;
matrix m_mul (matrix a, matrix b) {
    matrix res (order, vector<double> (order, 0) );

    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            for (int k = 0; k < order; k++) {
                res[i][j] += a[i][k] * b[k][j];
                // res[i][j] %= m;
            }
        }
    }

    return res;
}

matrix m_pow (matrix a, ll n) {
    matrix res (order, vector<double> (order, 0) );

    for (ll i = 0; i < order; i++) {
        res[i][i] = 1;
    }

    while (n) {
        if (n & 1) {
            res = m_mul (res, a);
        }

        n >>= 1;
        a = m_mul (a, a );
    }

    return res;
}

int solve() {
    fastio;
    int n;
    cin >> n;
    double p;
    cin >> p;
    order = 2;
    matrix a (order, vector<double> (order, p) );
    // matrix ini  (order, vector<double> (order, p) );
    // ini[0][0] = ini[1][1] = 0;
    // ini[0][1] = ini[1][0] = 1;
    a[0][1] = 1 - p;
    a[1][0] = 1 - p;
    double ans = m_pow (a, n) [0][1];
    // cout << m_mul (m_pow (a, n), m_pow (ini, n) ) [0][0] ;

    if (n % 2) {
        cout << ans;
    } else {
        cout << 1 - ans;
    }

// vi a(n);
// for (int i = 0; i < n; i++) {
//     cin >> a[i];
// }
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
