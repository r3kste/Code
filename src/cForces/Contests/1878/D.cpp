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

int solve() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<char> s;
    vi l;
    vi r;

    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        s.push_back (temp);
    }

    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        l.push_back (t);
    }

    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        r.push_back (t);
    }

    int q;
    cin >> q;
    vi x;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        x.push_back (t);
    }

    vi ta (n);
    vi tb (n);

    for (int c = 0; c < q; c++) {
        if (ta[x[c] - 1] == 0 && tb[x[c] - 1] == 0) {
            int j = 0, a, b;
            j = lower_bound (r.begin(), r.end(), x[c]) - r.begin();
            // for (int i = 0; i < k; i++)
            // {
            //     if (r[i] < x[c])
            //     {
            //         continue;
            //     }
            //     else
            //     {
            //         j = i;
            //         break;
            //     }
            // }
            int sum = l[j] + r[j];
            a = min (x[c], sum - x[c]) - 1;
            b = max (x[c], sum - x[c]) - 1;
            ta[x[c] - 1] = a;
            tb[x[c] - 1] = b;
        }

        if (ta[x[c] - 1] != tb[x[c] - 1]) {
            reverse (s.begin() + ta[x[c] - 1], s.end() - n + tb[x[c] - 1] + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i];
    }

    return 0;
}