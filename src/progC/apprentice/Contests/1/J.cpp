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
ll tonum (vll a) {
    ll ans = 0;
    vll b = a;
    reverse (all (b));
    ll m = 1;

    for (auto i : b) {
        if (i != -1) {
            ans += (m * i);
            m *= 10;
        }
    }

    return ans;
}
int solve() {
    fastio;
    ll n, d;
    cin >> n >> d;
    vll a (n);
    vector<pair<ll, ll>> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // if (a[i] == 0)
        // {
        //     flag = true;
        // }
        b.pb (mp (a[i], i));
    }

    ll mmm = tonum (a);
    // if (flag)
    // {
    //     for (auto i : a)
    //     {
    //         cout << i;
    //     }
    // }
    // else
    // {}
    sort (all (b));
    reverse (all (b));
    ll i = 0;

    while (i < b.size()) {
        a[b[i].S] = -1;
        a.pb (d);
        i++;
        ll wow = tonum (a);

        if (wow < mmm) {
            mmm = wow;
        }
    }

    cout << mmm;
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