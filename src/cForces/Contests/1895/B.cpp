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
    vi a (2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

//     vll length;
//     vi x(n);
//     int xk=0;
//     vi y(n);
//     int yk=0;
//
//     for(int i=0;i<2*n;i++) {
//         xk=0;
//         x[xk++]=i;
//         for(int j=0;j<2*n;j++) {
//             if(i!=j){
//                 for(int k=0;k<2*n;k++) {
//
//                 }
//             }
//         }
//     }
    sort (all (a) );
    // int l=0;
    // int r=n-1;
    vi x;
    vi y;
    ll length = 0;

    for (int i = 0; i < n; i++) {
        x.pb (a[i]);
        y.pb (a[2 * n - 1 - i]);
    }

    for (int i = 0; i < n - 1; i++) {
        length += (abs (x[i] - x[i + 1]) + abs (y[i] - y[i + 1]) );
    }

    cout << length << "\n";

    for (int i = 0; i < n; i++) {
        cout << x[i] << " " << y[i] << "\n";
    }

    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        // cout << "\n";
    }
}
