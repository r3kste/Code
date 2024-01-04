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
    ll n;
    cin >> n;
    vii a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i + 1;
    }

    sort (all (a));
    int top = a.back().F;
    int stop = a[n - 2].F;

    if (top - stop <= 1) {
        while (true) {
            // ll lb = lower_bound (all (a), a[n - 1]) - a.begin();
            auto lb = distance (a.begin(), lower_bound (a.begin(), a.end(), make_pair (a[n - 1].F, numeric_limits<int>::min())) );
            vi ans;
            ans.pb (a[lb].S);
            a[lb].F--;
            sort (all (a));

            for (auto wow : ans) {
                cout << wow << " ";
            }

            if (a[n - 1].F == 0) {
                return 0;
            }
        }
    }

    cout << -1 << " ";
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