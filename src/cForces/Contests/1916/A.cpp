#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int) (a).size())

typedef long long int ll;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vll;

int solve() {
    fastio;
    int n, k;
    cin >> n >> k;
    vi a (n);
    bool flag = true;
    ll p = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p *= a[i];

        if (2023 % a[i] != 0 || p > 2023 || 2023 % p != 0) {
            flag = false;
        }
    }

    if (!flag) {
        cout << "NO";
    } else {
        cout << "YES\n" << 2023 / p << " ";

        for (int i = 1; i < k; i++) {
            cout << 1 << " ";
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