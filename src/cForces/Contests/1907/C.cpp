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
    string s;
    cin >> s;
    vector<pair<char, int>> k;
    int c = 1;

    for (int i = 0; i < s.size() - 1;) {
        c = 1;

        for (int j = i; j < s.size() - 1; j++) {
            if (s[j] == s[j + 1]) {
                c++;
            }
        }

        k.pb (mp (s[i], c));
        i += (c);
    }

    k.pb (mp (s[s.size() - 1], c));
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