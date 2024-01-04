#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;
typedef vector<unsigned long long int> vLL;

int solve() {
    fastio;
    string temp;
    cin >> temp;
    // vi a(n);
    int l = temp.length();
    ll rb = 0;
    ll rs = 0;
    ll rc = 0;

    for (int i = 0; i < l; i++) {
        if (temp[i] == 'B') {
            rb++;
        }

        if (temp[i] == 'S') {
            rs++;
        }

        if (temp[i] == 'C') {
            rc++;
        }
    }

    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
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
