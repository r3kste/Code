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
    vll a (n);
    ll max = -MOD;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > max) {
            max = a[i];
        }
    }

    reverse (all (a));
    vll ans;

    for (ll k = max + 1; k < 100000; k++) {
        LL num = 0;

        for (int i = 0; i < a.size(); i++) {
            num += (a[i] * ll (pow (k, i)));
        }

        if (num % (k - 1) == 0) {
            ans.pb (k);
        }
    }

    cout << ans.size() << endl;

    for (auto i : ans) {
        cout << i << " ";
    }

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