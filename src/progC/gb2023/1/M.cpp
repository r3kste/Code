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
    int n, T;
    cin >> n >> T;
    vi a (n);
    int yan_count = 0;
    int nathan_count = 0;
    ll yan_time = 0;
    ll nathan_time = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        yan_time += a[i];
        nathan_time += a[n - 1 - i];

        if (yan_time <= T) {
            yan_count++;
        }

        if (nathan_time <= T) {
            nathan_count++;
        }
    }

    if (yan_count > nathan_count) {
        cout << "Yan";
    } else if (yan_count == nathan_count) {
        cout << "Empate";
    } else {
        cout << "Nathan";
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