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

void solve();

int main() {
    fastio;
    int t = 1;

    if (false) {
        cin >> t;
    }

    while (t--) {
        solve();
        cout << "\n";
    }
}

void solve() {
    fastio;
    int n, c = 0;
    cin >> n;
    vi h (n);
    vi a (n);
    map<int, int> k;
    to (i, 0, n, 1) {
        cin >> h[i];
        cin >> a[i];
        k[a[i]]++;
    }
    to (i, 0, n, 1) {
        c += k[h[i]];
    }
    cout << c;
}