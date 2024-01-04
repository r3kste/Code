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
    ll n;
    cin >> n;

    for (int k = 2; k < 1000; k++) {
        ll kk = 1;
        ll sum = 0;
        int c = 0;
        // float a = (1.0 * log (n * (k - 1) + 1)) / (1.0 * log (k));
        // int aa = int (a);

        // sum+=kk;
        // kk*=k;
        while (sum < n) {
            sum += kk;
            kk *= k;
            c++;
        }

        if (sum == n && c >= 3) {
            cout << "YES";
            return 0;
        }

        // if((pow(k,aa)-1)/()==n)
        // if (a - aa == 0.0)
        // {
        //     if (a >= 3)
        //     {
        //         cout << "YES";
        //         return 0;
        //     }
        // }
    }

    cout << "NO";
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
