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

bool check (int a, int b, int n, int m) {
    return (a * a + b == n && b * b + a == m);
}

void solve() {
    fastio;
    int n, m;
    cin >> n >> m;
    int c = 0;
    to (i, 0, m + 1, 1) {
        to (j, 0, m + 1, 1) {
            if (check (i, j, n, m)) {
                c++;
            }
        }
    }
    cout << c;
}