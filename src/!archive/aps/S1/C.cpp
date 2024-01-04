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

    if (true) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

int solve() {
    fastio;
    int x, y, n;
    cin >> x >> y >> n;
    // for (int i = n; i > n - x; i--) // there will be atleast one k in this range and it will be the maximum
    // {
    //     if (i % x == y)
    //     {
    //         cout << i;
    //         return 0;
    //     }
    // }
    // TLE... rip
    cout << int (floor ((n - y) / x)) * x + y; // lol ok just find the m such that it satisfies k=mx+y and maximum would be when k is nearest to n.
    return 0;
}