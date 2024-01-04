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
    int n;
    cin >> n;
    int c = 0;
    int m = 0;
    int o = 0;
    vector<char> comp;
    vector<char> ou;
    vector<char> in;
    // to(i, 0, n, i + 1)
    // {
    //     if (s[i] == 'u')
    //     {
    //         c++;
    //         if (c % 2 == 0)
    //         {
    //             o += (i - m);
    //         }
    //         else
    //         {
    //             m = i;
    //         }
    //     }
    // }
    // if (s[0] == 'u' && s[n - 1] == 'u' && c % 2 == 0)
    // {
    //     cout << o;
    // }
    // else
    // {
    //     cout << -1;
    // }
    to (i, 0, n, i + 1) {
        char temp;
        cin >> temp;
        in.push_back (temp);
    }
    to (i, 0, n - 1, i + 1) {
        comp.push_back ('d');
        int t = n - i - 1;

        if (in[t] == 'u') {
            in[t] = 'd';
            c++;

            if (in[t - 1] == 'd') {
                in[t - 1] = 'u';
            } else {
                in[t - 1] = 'd';
            }
        }
    }
    to (i, 0, n, i + 1) {
        if (in[i] == 'u') {
            cout << -1;
            return 0;
        }
    }
    cout << c;
    return 0;
}