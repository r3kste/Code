#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl '\n'
#define yesno(a) ((a) ? "Yes" : "No");

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

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
        cout << "Yes";
    } else if (mp.size() > 2) {
        cout << "No";
    } else {
        auto i = mp.begin();
        int a = i->second;
        i++;
        int b = i->second;
        cout << yesno ((abs (a - b)) <= 1);
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
