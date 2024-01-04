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
    string a;
    string b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    if (n != m) {
        cout << "No";
        return 0;
    }

    string ta = "";

    for (auto c : a) {
        ta += tolower (c);
    }

    string tb = "";

    for (auto c : b) {
        tb += tolower (c);
    }

    a = ta;
    b = tb;

    if (a == b) {
        cout << "Yes";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if ((a[i] == 'b' || a[i] == 'p') && (b[i] == 'p' || b[i] == 'b')) {
                continue;
            } else if ((a[i] == 'i' || a[i] == 'e') && (b[i] == 'e' || b[i] == 'i')) {
                continue;
            } else {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
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