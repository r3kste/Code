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

ll m;
vector<vll> a;
map<ii, ll> dp;
ll f (int i, int j, int m) {
    if (i == 1 && j == m - 1) {
        return a[i][j];
    }

    if (dp[mp (i, j)] != -1) {
        return dp[mp (i, j)];
    } else {
        ll aa = 0;
        vector<vll> b = a;

        if (i == 0) {
            aa = f (i + 1, j, m);
        }

        if (j < m - 1) {
            aa = max (f (i, j + 1, m), aa);
        }

        return dp[mp (i, j)] = a[i][j] + aa;
    }
}
int solve() {
    fastio;
    int m;
    cin >> m;
    a = vector<vll> (2, vll (m, -1));
    dp.clear();
    ll sum = MOD * MOD;
    vi top;
    vll pstop;
    pstop.pb (0);
    vi bot;
    vll psbot;
    psbot.pb (0);
    int k = 0;

    for (int i = 0; i < 2; i++) {
        k = 0;

        for (int j = 0; j < m; j++, k++) {
            cin >> a[i][j];
            dp[mp (i, j)] = -1;
            sum += a[i][j];

            if (i == 0) {
                top.pb (a[i][j]);
                pstop.pb (pstop[k] + top[k]);
            }

            if (i == 1) {
                bot.pb (a[i][j]);
                psbot.pb (psbot[k] + bot[k]);
            }
        }
    }

    //f(i,j,m)=max sum to go from (i,j) to (2,m)
    //ans = sum-f(0,0,m)
    //f(i,j,m)=a[i][j]+max(f(adjacent,m))
    // cout << sum - f (0, 0, m);
    ll t, b;
    sum = min (pstop[m] - pstop[1], psbot[m - 1] - psbot[0]);

    for (int i = 1; i < m - 1; i++) {
        t = pstop[m] - pstop[i + 1];
        b = psbot[i] - psbot[0];
        sum = min (sum, (max (t, b)));
    }

    cout << sum;
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