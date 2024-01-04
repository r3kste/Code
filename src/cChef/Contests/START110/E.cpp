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

int main() {
    fastio;
    int t = 1;
    cin >> t;
    int n = 1000000;
    // gfg code https://www.geeksforgeeks.org/sieve-of-eratosthenes/
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    // bool prime[n + 1];
    // memset(prime, true, sizeof(prime));
    vector<bool> prime (n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    while (t--) {
        // solve();
        cin >> n;
        // for (int n = 1; n <= 1000000; n++)
        // vi a(n);
        // for (int i = 0; i < n; i++) {
        //     cin >> a[i];
        // }
        //
        ll ans = MOD;
        bool flag = false;
        double temp = log2 (n + 1);
        int inttemp = (int (log2 (n + 1)));

        if (prime[n]) {
            ans = 1;
            flag = true;
        } else if (inttemp - temp == 0.0) {
            ans = inttemp;
            flag = true;
        } else {
            // for (int p = n; p >= 2; p--)
            // {
            //     if (prime[p])
            //     {
            //         double temp = log2(n - p + 1);
            //         int inttemp = (int(log2(n - p + 1)));
            //         if (inttemp - temp == 0.0)
            //         {
            //             ll cnt = 1 + inttemp;
            //             // if (cnt < ans)
            //             // {
            //             //     ans = cnt;
            //             //     flag = true;
            //             // }
            //             ans = cnt;
            //             flag = true;
            //             break;
            //         }
            //     }
            // }
            // cant beleive i didnt think the other way around
            int c = 0;
            int k = 1;

            while (n > 0) {
                if (prime[n]) {
                    if (c < ans) {
                        ans = c + 1;
                        flag = true;
                    }
                }

                n -= k;
                k *= 2;
                c++;
            }
        }

        if (flag) {
            // cout << "a[" << n - 1 << "]=";
            cout << ans;
            // cout << "\n";
        } else {
            cout << -1;
        }

        cout << "\n";
    }
}