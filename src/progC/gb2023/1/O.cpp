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
    int n = s.size();
    int c = 1;
    string ans;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cout << s[i] << c;
            c = 0;
        }

        c++;
    }

    if (c != 0) {
        cout << s.back() << c;
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