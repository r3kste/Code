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
typedef pair<ll, ll> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;

int solve() {
    fastio;
    int n;
    cin >> n;
    vector<vector<tuple<ll, ll, ll>>> data (n);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tuple<ll, ll, ll> t;
        t = {x, y, z};
        data[i].pb (t);
    }

    int q;
    cin >> q;
    vector<pair<ii, ii>> op1;

    for (int _ = 0; _ < q; _++) {
        int type = 0;
        cin >> type;
        int i, j;

        if (type == 3) {
            cin >> i >> j;
            i--;
            j--;
            ll amax = -1;

            for (auto iii : data[i]) {
                for (auto jjj : data[j]) {
                    amax = max (amax, abs (get<0> (iii) - get<0> (jjj)) + abs (get<1> (iii) - get<1> (jjj)) + abs (get<2> (iii) - get<2> (jjj)));
                }
            }

            cout << amax << "\n";
        } else if (type == 1) {
            cin >> i >> j;
            i--;
            j--;
            auto t = data[i];
            int is = data[j].size();
            int js = data[i].size();

            for (auto jjj : data[j]) {
                data[i].pb (jjj);
            }

            for (auto iii : data[i]) {
                data[j].pb (iii);
            }

            // data[i].insert (data[i].end(), all (data[j]));
            // data[j].insert (data[j].end(), all (t));
            op1.pb (mp (mp (i, is), mp (j, js)));
        } else if (type == 2) {
            auto iii = op1.back().F;
            auto jjj = op1.back().S;
            op1.pop_back();

            for (int _ = 0; _ < iii.S; _++) {
                data[iii.F].pop_back();
            }

            for (int _ = 0; _ < jjj.S; _++) {
                data[jjj.F].pop_back();
            }
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
        // cout << "\n";
    }
}