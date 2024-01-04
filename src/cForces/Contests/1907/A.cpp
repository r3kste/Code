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
    string s;
    cin >> s;
    char ch = s[0];
    int f = s[1] - 48;

    for (int i = 1; i <= 8; i++) {
        if (i == f) {
            continue;
        } else {
            cout << ch << i << "\n";
        }
    }

    for (int i = 97; i <= 104; i++) {
        if (i == int (ch)) {
            continue;
        } else {
            cout << char (i) << f << "\n";
        }
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
