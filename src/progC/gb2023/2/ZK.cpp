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
    int n;
    cin >> n;

    switch (n) {
    case 1:
        cout << "Alas! Farha is bitten by snake. She is now at 75.";
        break;

    case 2:
        cout << "Nothing happened to her.";
        break;

    case 3:
        cout << "Nothing happened to her.";
        break;

    case 4:
        cout << "Alas! Farha is bitten by snake. She is now at 79.";
        break;

    case 5:
        cout << "Farha is on ladder.";
        break;

    case 6:
        cout << "Yay! Farha has won the game. She is now at 100.";
        break;

    default:
        break;
    }

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