#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

#define endl '\n'
#define yesno(a) cout << ((a) ? "Yes" : "No");
#define sp cout << " ";
#define enl cout << endl;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

bool checkk (string s) {
    int n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            return false;
        }
    }

    return true;
}

int solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;

    if (checkk (s)) {
        cout << "YES";
    } else {
        char a = t[0];
        char b = t[m - 1];

        if (a != b) {
            cout << "NO";
        } else {
            if (checkk (t)) {
                for (int i = 1; i < n; i++) {
                    if (s[i] == s[i - 1]) {
                        if (s[i] == a) {
                            cout << "NO";
                            return 0;
                        }
                    }
                }

                cout << "YES";
            } else {
                cout << "NO";
            }
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
