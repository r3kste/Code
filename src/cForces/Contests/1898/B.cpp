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
    // vi a(n+2);
    // a[0]=0;
    // for (int i = 1; i < n+2; i++) {
    //     cin >> a[i];
    // }
    // a[n+1]=0;
    // int c=0;
    // while (!is_sorted(all(a))) {
    //     for(int i=1;i<n+2;i++) {
    //         if(a[i]>=a[i-1] && a[i]<=a[i+1]) {
    //             c++;
    //         }
    //     }
    // }
    vi a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll c = 0;

    for (int i = n - 2; i > -1; i--) {
        if (a[i] > a[i + 1]) {
            ll nn = int (ceil  ((a[i] * 1.0) / (a[i + 1] * 1.0)));
            c += nn - 1; // idk why the -1 came, just yet...
            a[i] /= nn;
        }
    }

    cout << c;
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
