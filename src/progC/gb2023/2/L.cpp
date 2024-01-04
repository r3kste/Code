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
    int r, c, q;
    cin >> r >> c >> q;
    char grid[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            grid[i][j] = '.';
        }
    }

    vector<tuple<int, int, int, int, char>> inp;

    while (q--) {
        char color;
        int r1, c1, r2, c2;
        //  topleft botright
        cin >> r1 >> c1 >> r2 >> c2;
        cin >> color;
        r1--;
        c1--;
        r2--;
        c2--;
        inp.pb ({r1, c1, r2, c2, color});
    }

    q = inp.size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int r1, c1, r2, c2;
            bool flag = false;

            for (int k = q - 1; k >= 0; k--) {
                r1 = get<0> (inp[k]);
                c1 = get<1> (inp[k]);
                r2 = get<2> (inp[k]);
                c2 = get<3> (inp[k]);

                if (i >= r1 && i <= r2 && j >= c1 && j <= c2) {
                    cout << get<4> (inp[k]);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                cout << ".";
            }
        }

        cout << "\n";
    }

    return 0;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        // cout << "\n";
    }
}