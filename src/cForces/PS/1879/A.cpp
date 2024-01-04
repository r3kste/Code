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
    vii a (n);
    vii b (n);
    cin >> a[0].F;
    cin >> a[0].S;
    int s1 = a[0].F;
    int e1 = a[0].S;
    bool flag = false;

    for (int i = 1; i < n; i++) {
        cin >> a[i].F;
        cin >> a[i].S;

        if (a[i].S >= e1 && !flag) {
            // b[i-1].pb(mp(a[i].F,a[i].S));
            if (a[i].F >= s1) {
                cout << -1;
                flag = true;
            }
        }
    }

    if (flag) {
        return 0;
    }

    cout << s1;
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
