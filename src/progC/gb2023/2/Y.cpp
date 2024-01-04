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
    int bc, kc, lc;
    bc = kc = lc = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[0] == 'b') {
            bc++;
        }

        if (s[0] == 'k') {
            kc++;
        }

        if (s[0] == 'l') {
            lc++;
        }
    }

    bc /= 2;
    cout << min (bc, min (kc, lc));
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