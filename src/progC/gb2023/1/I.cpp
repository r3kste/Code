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
    ll n, m;
    cin >> n >> m;
    vi a (n);
    vi ps;
    ps.pb (0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps.pb (ps[i] + a[i]);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ll wow = ps[r] - ps[l - 1];

        if (wow % 2) {
            cout << "Nao\n";
        } else {
            cout << "Sim\n";
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
    }
}