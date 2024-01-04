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
    vi a (n);
    bool flag = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > i + 1) {
            flag = true;
        }
    }

    if (flag) {
        cout << "NO";
    } else {
        vi ans;
        cout << "YES\n";
        int posi;

        while (!a.empty()) {
            for (int i = 0; i < int (a.size()); i++) {
                if (i + 1 == a[i]) {
                    posi = i;
                }
            }

            ans.pb (posi + 1);
            a.erase (a.begin() + posi);
        }

        reverse (all (ans));

        for (auto i : ans) {
            cout << i << " ";
        }
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