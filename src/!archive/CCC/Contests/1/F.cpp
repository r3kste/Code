#include <bits/stdc++.h>
using namespace std;

#define to(i, a, b, c) for (int(i) = (a); (i) < b; (i) += c)
#define fro(i, a, b, c) for (int(i) = (b)-1; (i) >= (a); (i) -= c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    // y = 8 - y + 1;
    // ll a = x - 1;
    // ll b = y - 1;
    // ll c = n - x;
    // ll d = n - y;
    // ll lx = a + c;
    // ll ly = b + d;
    cout << "YES";
    return 0;
}