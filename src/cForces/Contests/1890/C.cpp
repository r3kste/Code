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

bool check_alt (string s) {
    int n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            return false;
        }
    }

    return true;
}

bool check_sym (string s) {
    int n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] == s[n - i - 1]) {
            return false;
        }
    }

    return true;
}

int solve() {
    fastio;
    int n;
    cin >> n;
    int k = n;
    // vector<char> s;
    string s1 = "";
    int c1 = 0;
    int c0 = 0;

    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        // s.push_back(temp);
        s1.append (to_string (temp));

        if (temp == 1) {
            c1++;
        } else {
            c0++;
        }
    }

    if (n % 2 != 0 || c1 != c0) {
        cout << "-1";
    } else {
        if (check_sym (s1)) {
            cout << "0\n";
        } else {
            for (int i = 0; i < k; i++) {
                string a = s1.substr (0, i);
                string b = s1.substr (i, k - i);
            }
        }

        return 0;
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

    return 0;
}
