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
    vll a (n);
    vll ps (n + 1);
    ps[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    ll cur = 0;

    for (int j = 1; j < ps.size(); j++) {
        ll i = ps[j];
        cout << (i / m) - cur << " ";
        cur = (i / m);
    }

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