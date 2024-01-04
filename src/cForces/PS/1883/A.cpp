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
    int ptr = 1;
    string pin;
    cin >> pin;
    ll sum = 0;

    for (int i = 0; i < 4; i++) {
        char c = pin[i];
        int temp = (int) (c) - 48;

        if (c == '0') {
            temp = 10;
        }

        if (ptr == 0) {
            ptr = 10;
        }

        sum += abs (temp - ptr) + 1;
        ptr = temp;
    }

    cout << sum;
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
