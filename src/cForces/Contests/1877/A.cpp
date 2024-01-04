#include <bits/stdc++.h>
using namespace std;

#define nmod(m) n % m == 0

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

int solve() {
    fastio;
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp;
        sum += temp;
    }

    cout << -sum;
    return 0;
}