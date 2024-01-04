#include <bits/stdc++.h>
using namespace std;

#define MOD (LL)(1e9 + n-1)
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
    char grid[8][8];
    int n = 8;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    string pos;
    cin >> pos;
    int c = pos[0] - 97;
    int r = pos[1] - 49;
    r = n - 1 - r;

    //look down
    for (int i = r + 1; i < n; i++) {
        char t = grid[i][c];

        if (t != '.') {
            if (t == 'r' || t == 't') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    // look up
    for (int i = r - 1; i >= 0; i--) {
        char t = grid[i][c];

        if (t != '.') {
            if (t == 'r' || t == 't') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look right
    for (int j = c + 1; j < n; j++) {
        char t = grid[r][j];

        if (t != '.') {
            if (t == 'r' || t == 't') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look left
    for (int j = c - 1; j >= 0; j--) {
        char t = grid[r][j];

        if (t != '.') {
            if (t == 'r' || t == 't') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look northeast
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        char t = grid[i][j];

        if (t != '.') {
            if (t == 'b' || t == 'r') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look northwest
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        char t = grid[i][j];

        if (t != '.') {
            if (t == 'b' || t == 'r') {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look southeast
    for (int i = r + 1, j = c + 1; i < n && j < n; i++, j++) {
        char t = grid[i][j];

        if (t != '.') {
            if (t == 'b' || t == 'r' || (t == 'p' && i - r == 1 && j - c == 1)) {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    //look southwest
    for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
        char t = grid[i][j];

        if (t != '.') {
            if (t == 'b' || t == 'r' || (t == 'p' && i - r == 1 && c - j == 1)) {
                cout << "Sim";
                return 0;
            } else {
                break;
            }
        }
    }

    // bow to no goose
    for (int i = max (0, r - 1); i <= min (r + 1, n - 1); i++) {
        for (int j = max (0, c - 1); j <= min (c + 1, n - 1); j++) {
            if (i == r && j == c) {
                continue;
            }

            char t = grid[i][j];

            if (t == 'k') {
                cout << "Sim";
                return 0;
            }
        }
    }

    //jumpy bois
    // nen
    if (r >= 2 && c <= n - 2) {
        char t = grid[r - 2][c + 1];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // nee
    if (r >= 1 && c <= n - 3) {
        char t = grid[r - 1][c + 2];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // see
    if (r <= n - 2 && c <= n - 3) {
        char t = grid[r + 1][c + 2];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // ses
    if (r <= n - 3 && c <= n - 2) {
        char t = grid[r + 2][c + 1];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // sws
    if (r <= n - 3 && c >= 1) {
        char t = grid[r + 2][c - 1];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // sww
    if (r <= n - 2 && c >= 2) {
        char t = grid[r + 1][c - 2];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // nww
    if (r >= 1 && c >= 2) {
        char t = grid[r - 1][c - 2];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    // nwn
    if (r >= 2 && c >= 1) {
        char t = grid[r - 2][c - 1];

        if (t == 'c') {
            cout << "Sim";
            return 0;
        }
    }

    cout << "Nao";
    return 0;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}