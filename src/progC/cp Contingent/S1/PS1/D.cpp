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

typedef vector<vector<ll>> matrix;
ll order;
matrix m_mul (matrix a, matrix b, ll m) {
    matrix res (order, vector<ll> (order, 0));

    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            for (int k = 0; k < order; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= m;
            }
        }
    }

    return res;
}

matrix m_pow (matrix a, ll n, ll m) {
    matrix res (order, vector<ll> (order, 0));

    for (ll i = 0; i < order; i++) {
        res[i][i] = 1;
    }

    while (n) {
        if (n & 1) {
            res = m_mul (res, a, m);
        }

        n >>= 1;
        a = m_mul (a, a, m);
    }

    return res;
}

int solve() {
    fastio;
    int n;
    cin >> n;
    matrix a (4, vector<ll> (4, 1));
    order = 4;

    for (int i = 0; i < 4; i++) {
        a[i][i] = 0;
    }

    a = m_pow (a, n, MOD);
    cout << a[0][0];
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
