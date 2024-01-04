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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ns;

    for (auto c : s) {
        int correction = 0;

        if (c - 97 > 13) {
            correction = 122 - c + 1;
        } else {
            correction = c - 97;
        }

        if (correction > k) {
            // k is not sufficient
            ns += (char (c - k));
            k = 0;
        } else {
            // k is sufficient to convert to 'a'
            ns += (char (97));
            k -= (correction);
        }
    }

    if (k % 2) {
        char ch = ns.back();
        char newch = ch - 1;
        ns = ns.substr (0, n - 1);

        if (newch == 96) {
            newch = 'b';
        }

        ns += newch;
    }

    cout << ns;
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