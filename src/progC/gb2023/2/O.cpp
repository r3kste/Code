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
    int n, one, two;
    cin >> n >> one >> two;
    int first = 1;
    int second = 1;
    int time = 0;
    vi a (100000);
    vi b (100000);

    while (true) {
        time++;
        first = time * one % n;

        if (b[first] == 1) {
            break;
        }

        a[first] = 1;
        second = time * two % n;

        if (a[second] == 1) {
            break;
        }

        b[second] = 1;
    }

    cout << time;
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