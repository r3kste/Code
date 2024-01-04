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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[26];
    fill (begin (a), end (a), 0);
    to (i, 0, n, 1) {
        a[s[i] - 97]++;
    }
    int mx = 0;
    to (i, 0, 26, 1) {
        if (a[i] > a[mx]) {
            mx = i;
        }
    }
    cout << (char) (mx + 97);
    return 0;
}