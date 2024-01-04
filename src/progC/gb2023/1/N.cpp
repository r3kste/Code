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
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
    }

    for (int i = 0; i < n; i++) {
        auto c1 = a[i];

        for (int j = i + 1; j < n; j++) {
            auto c2 = a[j];
            auto center1 = c1.F;
            auto center2 = c2.F;
            auto dx = center2.F - center1.F;
            auto dy = center2.S - center1.S;
            auto dc = sqrt ((dx) * (dx) + (dy) * (dy));

            if (dc - c1.S - c2.S <= 0) {
                cout << i + 1 << " " << j + 1 << " ";
            }
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