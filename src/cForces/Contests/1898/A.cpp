#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define endl "\n"
#define yesno(a) cout << ((a) ? "Yes" : "No");

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long int ll;
typedef unsigned long long int LL;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long int> vll;

int solve() {
    fastio;
    int n, k;
    cin >> n >> k;
    vi a;
    vi b;
    vector<char> inp;

    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        inp.pb (temp);

        if (temp == 'A') {
            a.pb (i);
        } else {
            b.pb (i);
        }
    }

    // int na = a.size();
    int nb = b.size();
    // reverse (all (inp));
    // int c = 0;
    // int li = -1;
    //
    // for (int i = 0; i < n; i++)
    // {
    //     if (inp[i] == 'B')
    //     {
    //         c++;
    //
    //         if (c <= k)
    //         {
    //             li = i;
    //         }
    //     }
    // }
    //
    // if (c == k)
    // {
    //     cout << 0;
    // }
    // else if (c > k)
    // {
    //     cout << "1\n" << li + 1 << " A";
    // }
    // else
    // {
    //     cout << "1\n" << li - 1 << " B";
    // }

    if (nb == k) {
        cout << 0;
    } else if (nb > k) {
        cout << "1\n"
             << b[nb - k - 1] + 1 << " A";
    } else {
        cout << "1\n"
             << a[k - nb - 1] + 1 << " B";
    }

    return 0;
}
int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
