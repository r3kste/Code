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
    int n, q;
    cin >> n >> q;
    ll max = 0;
    vi a (n);

    // vi log2a;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > max) {
            max = a[i];
        }

        // log2a.pb((a[i] % 2 == 0) ? int(floor(log2(a[i]))) : 0);
    }

    ll qmax = ll (floor (log2 (max) ) );
    int qmin = MOD;
    // ll oper = 0;
    vi x;

    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;

        if (temp <= qmax && temp < qmin) {
            x.push_back (temp);
            qmin = temp;
            // oper += pow(2, temp);
        }

        // if (temp <= qmax)
        // {
        //     ll what = pow(2, temp);
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (a[j] % 2 == 0)
        //         {
        //             if (a[j] >= what)
        //             {
        //                 if (a[j] % what == 0)
        //                 {
        //                     a[j] += (what >>2);
        //                 }
        //             }
        //         }
        //     }
        // }
    }

    for (int i = 0; i < x.size(); i++) {
        ll what = pow (2, x[i]);

        for (int j = 0; j < n; j++) {
            if (a[j] % 2 == 0) {
                if (a[j] >= what) {
                    if (a[j] % what == 0) {
                        a[j] += (what >> 1);
                    }
                }
            }
        }

        // oper -= what;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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
