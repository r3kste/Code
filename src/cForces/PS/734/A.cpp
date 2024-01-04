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
    vector<char> a (n);
    int ca = 0, cd = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        switch (a[i]) {
        case 'A':
            ca++;
            break;

        case 'D':
            cd++;
            break;

        default:
            break;
        }
    }

    cout << ((ca > cd) ? "Anton" : (ca == cd) ? "Friendship" : "Danik");
    return 0;
}

int main() {
    fastio;
    int t = 1;

    while (t--) {
        solve();
        cout << "\n";
    }
}
