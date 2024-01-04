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

void solve();

int main() {
    testitr (true);
}

ll lcm (int a, int b) {
    ll p = a * b;
    ll g = __gcd (a, b);
    return p / g;
}

bool check (int a, int b, int n) {
    return lcm (a, b) <= n / 2.0;
}

void solve() {
    fastio;
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0;

    if (n % 3 == 0) {
        a = n / 3;
        b = n / 3;
    } else if (n % 3 == 2) {
        if (n % 2 == 0) {
            if (n % 4 == 0) {
                a = n / 2;
                b = a / 2;
            } else {
                a = 2;
                b = (n - 2) / 2;
            }
        } else {
            a = 1;
            b = (n - 1) / 2;
        }
    } else if (n % 3 == 1) {
        if (n % 2 == 0) {
            if (n % 4 == 0) {
                a = n / 2;
                b = a / 2;
            } else {
                a = 2;
                b = (n - 2) / 2;
            }
        } else {
            a = 1;
            b = (n - 1) / 2;
        }
    }

    cout << a << " " << b << " " << b;
}