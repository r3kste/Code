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
    // map<string, bool> a;
    // vector<char> a;
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    int c = 0;

    for (int i = 0; i < n - 1; i++) {
        // string perm = "";
        //
        // if (i != 0)
        // {
        //     perm = s.substr (0, i);
        // }
        //
        // string temp = s.substr (i + 2, n - i - 2);
        // perm = perm + "" + temp;
        //
        // if (a[perm])
        // {
        //     continue;
        // }
        // else
        // {
        //     a[perm] = true;
        //     c++;
        // }
        if (s[i] == s[i + 2]) {
            c++;
        }
    }

    cout << n - 1 - c;
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
