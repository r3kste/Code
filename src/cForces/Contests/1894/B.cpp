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
    map<int, int> mp;
    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if (mp.size() == 1) {
        cout << -1;
        return 0;
    } else {
        int c = 0;

        for (auto i : mp) {
            if (i.second > 1) {
                c++;
            }
        }

        if (c == 1 || c == 0) {
            cout << "-1";
            return 0;
        } else {
            map<int, bool> mp1;
            bool i2flag = false;
            bool pflag = false;

            for (int i = 0; i < n; i++) {
                if (mp[a[i]] == 1) {
                    cout << "1 ";
                    continue;
                }

                if (mp1[a[i]]) {
                    cout << "1 ";
                    pflag = true;
                } else {
                    pflag = true;

                    if (i2flag) {
                        cout << "3 ";
                        mp1[a[i]] = true;
                    } else {
                        cout << "2 ";
                        mp1[a[i]] = true;
                        i2flag = true;
                    }
                }
            }

            if (!pflag) {
                cout << "-1";
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
