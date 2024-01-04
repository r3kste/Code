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
    vi floor (n);
    vi foot (n);
    vi chain (n);

    for (int i = 0; i < n; i++) {
        cin >> floor[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> foot[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> chain[i];
    }

    ll dff = 0;
    ll dfc = 0;

    for (int i = 0; i < n; i++) {
        ll ff = floor[i] - foot[i];
        dff += (ff * ff);
        ll fc = floor[i] - chain[i];
        dfc += (fc * fc);
    }

    if (! (dff > dfc)) {
        cout << "Yan";
    } else {
        cout << "MaratonIME";
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