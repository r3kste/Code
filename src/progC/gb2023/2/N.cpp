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
    string a, b;
    cin >> a >> b;

    if (a.find (b) != string::npos) {
        cout << "good";
        return 0;
    } else {
        for (int i = 0; i < 4; i++) {
            string tb = "";

            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    tb += b[j];
                }
            }

            if (a.find (tb) != string::npos) {
                cout << "almost good";
                return 0;
            }
        }
    }

    cout << "none";
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