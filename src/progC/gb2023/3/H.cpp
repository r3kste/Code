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
    // fastio;
    cout << "? 1\n";
    cout.flush();
    ll a;
    cin >> a;
    a *= 2;
    cout << "? " << a << "\n";
    cout.flush();
    ll b;
    cin >> b;

    if (b == a) {
        cout << "! " << a << "\n";
        cout.flush();
    } else {
        cout << "! " << a - 1 << "\n";
        cout.flush();
    }

    return 0;
}

int main() {
    // fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}