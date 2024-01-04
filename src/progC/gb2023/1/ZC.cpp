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
    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort (all (a));
    int l = 0;
    int r = n - 1;
    int teams = 0;

    while (l <= r) {
        if (a[r] >= k) {
            teams++;
            r--;
        } else {
            if (a[l] + a[r] >= k && l != r) {
                teams++;
                l++;
                r--;
            } else {
                l++;
            }
        }
    }

    cout << teams;
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