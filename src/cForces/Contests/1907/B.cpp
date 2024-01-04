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
    int loweri = -1;
    int upperi = -1;
    vi ignore;
    vi lower;
    vi upper;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == 'b' || ch == 'B') {
            if (ch == 'b' && lower.size() > 0) {
                lower.pop_back();
            } else if (ch == 'B' && upper.size() > 0) {
                upper.pop_back();
            }
        } else {
            if (isupper (ch)) {
                upper.pb (i);
            } else if (islower (ch)) {
                lower.pb (i);
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (binary_search (all (lower), i) || binary_search (all (upper), i)) {
            cout << s[i];
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