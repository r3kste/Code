#include <bits/stdc++.h>
using namespace std;

#define for(i, a, b, c) for (int(i) = ((c > 0) ? (a) : (b - 1)); ((c > 0) ? (i < b) : (i > a - 1)); (i) += c)
#define z(i, n) for (i, 0, n, 1)
#define zc(i, n, c) for (i, 0, n, c)
#define zr(i, a, b) for (i, a, b, 1)
#define zrc(i, a, b, c) for (i, a, b, c)

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testitr(itr)  \
    fastio;           \
    int t = 1;        \
    if (itr)          \
        cin >> t;     \
    z(i, t)           \
    {                 \
        solve();      \
        cout << "\n"; \
    }

#define pb push_back

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve();

int main() {
    testitr (false);
}

int solve() {
    fastio;
    int n;
    cin >> n;

    if (n > 26 || n == 1) {
        string s;
        cin >> s;
        cout << "Yes";
        return 0;
    }

    bool a[26];
    fill (begin (a), end (a), false);
    z (i, n) {
        char temp;
        cin >> temp;
        int t = int (temp);
        t = t - 97;

        if (a[t]) {
            cout << "Yes";
            return 0;
        } else {
            a[t] = true;
        }
    }
    cout << "No";
    return 0;
}