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
    vi s;
    vi e;
    vii inp;
    int minend = n;
    int maxstart = 0;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        minend = min (minend, r);
        maxstart = max (maxstart, l);
        inp.pb (mp (l, r));
    }

    if (maxstart > minend) {
        cout << "0\n";
    } else {
        cout << minend - maxstart + 1 << "\n";
    }

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