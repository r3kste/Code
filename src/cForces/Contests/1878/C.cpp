#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

#define to(i, a, b, c) for (int(i) = (a); (i) < (b); (i) = (c))
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) = (c))

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve();

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}

ll sumtill (ll n) {
    return (n * (n + 1)) / 2;
}

int solve() {
    fastio;
    ll n, k, x;
    cin >> n >> k >> x;
    // if (k >= x || k > n)
    // {
    //     cout << "NO";
    // }
    // else
    // {
    ll max = sumtill (n) - sumtill (n - k);
    ll min = sumtill (k);

    if (x <= max && x >= min) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    // }
    return 0;
}