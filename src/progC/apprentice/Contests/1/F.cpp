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
    vector<double> a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<double> b (m);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    ll c = 0;
    double max = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            double r = b[j] / a[i];

            if (r - ll (r) == 0) {
                if (r > max) {
                    max = r;
                    c = 1;
                } else if (r == max) {
                    c++;
                }
            }
        }
    }

    cout << c;
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}